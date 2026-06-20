__int64 ipc_log_string(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        ...)
{
  int v12; // w0
  unsigned int v13; // w8
  __int64 result; // x0
  int v15; // w20
  gcc_va_list va1; // [xsp+30h] [xbp-150h] BYREF
  gcc_va_list va; // [xsp+50h] [xbp-130h] BYREF
  _WORD s[130]; // [xsp+70h] [xbp-110h] BYREF
  unsigned int v19; // [xsp+174h] [xbp-Ch]
  __int64 v20; // [xsp+178h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    result = 4294967274LL;
    goto LABEL_8;
  }
  memset(s, 0, sizeof(s));
  s[0] = 2;
  v19 = 2;
  ((void (__fastcall *)(_WORD *))tsv_timestamp_write)(s);
  tsv_qtimer_write((__int64)s);
  va_start(va, a10);
  if ( v19 >= 0x100 )
    goto LABEL_10;
  va_copy(va1, va);
  v12 = vscnprintf((char *)&s[2] + v19, (int)(253 - v19), a2, va1);
  if ( v19 - 254 <= 0xFFFFFEFF )
  {
    v15 = v12;
    printk(&unk_82CF, "tsv_write_data");
    v13 = v19;
    v12 = v15;
    goto LABEL_6;
  }
  if ( v19 >= 0x100 )
LABEL_10:
    __break(0x5512u);
  *(_WORD *)((char *)&s[1] + v19) = ((_WORD)v12 << 8) | 4;
  v13 = v19 + 2;
LABEL_6:
  v19 = v13 + v12;
  HIBYTE(s[0]) = v13 + v12 - 2;
  s[1] = s[0];
  ipc_log_write(a1, (__int64)s);
  result = 0;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
