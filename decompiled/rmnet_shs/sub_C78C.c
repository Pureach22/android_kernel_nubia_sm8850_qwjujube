// local variable allocation has failed, the output may be wrong!
void sub_C78C(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        ...)
{
  __int64 v16; // x19
  __int64 v17; // x23
  char *v18; // x0
  gcc_va_list v25; // [xsp+28h] [xbp+28h] OVERLAPPED BYREF
  gcc_va_list va1; // [xsp+48h] [xbp+48h] OVERLAPPED BYREF
  gcc_va_list va; // [xsp+68h] [xbp+68h] OVERLAPPED BYREF
  __int64 v39; // [xsp+88h] [xbp+88h]

  va_start(va1, a16);
  va_start(va, a16);
  va_start(v25, a16);
  v39 = 0;
  v18 = (char *)((__int64 (__fastcall *)(__int64, __int64, __int64, __va_list_tag *))rmnet_shs_header_ptr)(
                  v16,
                  40,
                  8,
                  v25);
  if ( v18 && *v18 <= -127 )
  {
    snprintf((char *)&va1[0].__gr_offs, 0x30u, "%pI6", (const void *)(v17 + 8));
    snprintf((char *)&v25[0].__gr_top, 0x30u, "%pI6", (const void *)(v17 + 24));
    JUMPOUT(0xC810);
  }
  JUMPOUT(0xC6C0);
}
