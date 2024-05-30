#include <stdlib.h>
#include <strings.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>

#define MEM_STEP 5

struct Sentence {
    wchar_t *Sent;
    int size;
    int zero_sent;
};

struct Text {
    struct Sentence **text;
    int sent_count;
    int size;
};