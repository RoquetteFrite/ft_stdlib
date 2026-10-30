#ifndef FT_PRINTF
#define FT_PRINTF

#include <stdarg.h>
#include <unistd.h>

// sSpDdioOuUxXcC%#0-+HhlLjz

#define F_S     (1 << 0)
#define F_S_U   (1 << 1) // not
#define F_P     (1 << 2)
#define F_D_U   (1 << 3) 
#define F_D     (1 << 4)
#define F_I     (1 << 5)
#define F_O     (1 << 6)
#define F_O_U   (1 << 7)
#define F_U     (1 << 8) 
#define F_U_U   (1 << 9)
#define F_X     (1 << 10)
#define F_X_U   (1 << 11)
#define F_C     (1 << 12)
#define F_C_U   (1 << 13) // not
#define F_PER   (1 << 14)
#define F_F     (1 << 15)
#define F_F_U   (1 << 16)
#define F_B     (1 << 17)
#define F_N     (1 << 18)

#define F_SPACE (1 << 19)
#define F_HASH  (1 << 20)
#define F_ZERO  (1 << 21)
#define F_MINUS (1 << 22)
#define F_PLUS  (1 << 23)
#define F_HH    (1 << 24)
#define F_H     (1 << 25)
#define F_L     (1 << 26)
#define F_LL    (1 << 27)
#define F_J     (1 << 28)
#define F_Z     (1 << 29)

#define F_FLAG      (F_HASH | F_ZERO | F_MINUS | F_PLUS)
#define F_STR       (F_S | F_S_U)
#define F_CHAR      (F_C | F_C_U)
#define F_INT       (F_D | F_I)
#define F_U_INT     (F_O | F_U | F_X | F_X_U | F_B)
#define F_LONG      (F_D_U)
#define F_U_LONG    (F_O_U | F_U_U)
#define F_BASE      (F_X | F_X_U | F_O | F_O_U | F_B)
#define F_FLOAT       (F_F | F_F_U)

#define BASE_TEN        "0123456789"
#define BASE_SIX_LOW    "0123456789abcdef"
#define BASE_SIX_UPP    "0123456789ABCDEF"
#define BASE_OCTAL      "01234567"
#define BASE_BINARY     "01"
#define POS_INF         "inf"
#define NEG_INF         "-inf"
#define NAN_MSG         "-nan"
#define POS_INF_U       "INF"
#define NEG_INF_U       "-INF"
#define NAN_MSG_U       "-NAN"


typedef struct s_path {
    int         i;
    int         width;
    char        *format;
    int         flag;
    va_list     args;
    char        buf[50];
    short       is_neg;
    int         size;
} t_path;

int ft_printf(const char *format, ...);

int print_flag(t_path *path, int len, char flag);

#endif
