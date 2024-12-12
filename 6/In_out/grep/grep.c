#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUF_SIZE 1024

int str_case_cmp(const char *str1, const char *str2) {
    while (*str1 && *str2) {
        if (tolower(*str1) != tolower(*str2)) {
            return 0;
        }
        str1++;
        str2++;
    }
    return *str2 == '\0';
}

int pattern_match(const char *line, const char *pattern, int ignore_case) {
    if (ignore_case) {
        for (int i = 0; line[i] != '\0'; i++) {
            if (str_case_cmp(&line[i], pattern)) {
                return 1;
            }
        }
        return 0;
    } else {
        return strstr(line, pattern) != NULL;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s [options] pattern filename\n", argv[0]);
        fprintf(stderr, "Options:\n");
        fprintf(stderr, "  -i    Case-insensitive search\n");
        fprintf(stderr, "  -n    Display line numbers\n");
        fprintf(stderr, "  -v    Invert the match (display non-matching lines)\n");
        fprintf(stderr, "  -c    Count matching lines\n");
        return 1;
    }

    int ignore_case = 0;
    int show_line_numbers = 0;
    int invert_match = 0;
    int count_only = 0;
    char *pattern = NULL;
    char *text = NULL;

    // Parse command-line arguments
    int arg_idx = 1;
    while (arg_idx < argc) {
        if (argv[arg_idx][0] == '-') {
            if (strchr(argv[arg_idx], 'i')) ignore_case = 1;
            if (strchr(argv[arg_idx], 'n')) show_line_numbers = 1;
            if (strchr(argv[arg_idx], 'v')) invert_match = 1;
            if (strchr(argv[arg_idx], 'c')) count_only = 1;
        } else if (pattern == NULL) {
            pattern = argv[arg_idx];
        } else {
            text = argv[arg_idx];
        }
        arg_idx++;
    }

    if (pattern == NULL || text == NULL) {
        fprintf(stderr, "Error: Pattern and filename are required.\n");
        return 1;
    }

    FILE *file = fopen("text", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char line[BUF_SIZE];
    int line_number = 0;
    int match_count = 0;

    while (fgets(line, sizeof(line), file)) {
        line_number++;
        int match = pattern_match(line, pattern, ignore_case);
        if (invert_match) match = !match;

        if (match) {
            match_count++;
            if (!count_only) {
                if (show_line_numbers) {
                    printf("%d:", line_number);
                }
                printf("%s", line);
            }
        }
    }

    if (count_only) {
        printf("%d\n", match_count);
    }

    fclose(file);
    return 0;
}