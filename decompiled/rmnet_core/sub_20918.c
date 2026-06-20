// local variable allocation has failed, the output may be wrong!
void sub_20918(
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
  __int64 v16; // x20
  __int64 v17; // x29
  int v18; // w8
  __int64 v19; // x9
  __int64 v20; // x8
  __int64 v21; // x9
  __int64 v22; // x8
  gcc_va_list sa; // [xsp+18h] [xbp+18h] OVERLAPPED BYREF
  __int64 v31; // [xsp+38h] [xbp+38h]
  __int64 v32; // [xsp+40h] [xbp+40h]

  va_start(sa, a16);
  v18 = *(unsigned __int16 *)(v16 + 180);
  *(_QWORD *)(v17 - 56) = 0;
  *(_QWORD *)(v17 - 48) = 0;
  *(_QWORD *)(v17 - 40) = 0;
  *(_QWORD *)(v17 - 32) = 0;
  *(_QWORD *)(v17 - 24) = 0;
  *(_QWORD *)(v17 - 16) = 0;
  v31 = 0;
  v32 = 0;
  if ( v18 == 56710
    || v18 == 8
    && (v19 = *(_QWORD *)(v16 + 216), v20 = v19 + *(unsigned __int16 *)(v16 + 184), *(_BYTE *)(v20 + 9) == 1)
    && (*(unsigned __int8 *)(v19 + *(unsigned __int16 *)(v16 + 182)) | 8) == 8
    && (snprintf((char *)(v17 - 56), 0x30u, "%pI4", (const void *)(v20 + 12)),
        snprintf(
          (char *)sa,
          0x30u,
          "%pI4",
          (const void *)(*(_QWORD *)(v16 + 216) + *(unsigned __int16 *)(v16 + 184) + 16LL)),
        *(unsigned __int16 *)(v16 + 180) == 56710) )
  {
    v21 = *(_QWORD *)(v16 + 216);
    v22 = v21 + *(unsigned __int16 *)(v16 + 184);
    if ( *(_BYTE *)(v22 + 6) == 58 && *(char *)(v21 + *(unsigned __int16 *)(v16 + 182)) <= -127 )
    {
      snprintf((char *)(v17 - 56), 0x30u, "%pI6", (const void *)(v22 + 8));
      snprintf(
        (char *)sa,
        0x30u,
        "%pI6",
        (const void *)(*(_QWORD *)(v16 + 216) + *(unsigned __int16 *)(v16 + 184) + 24LL));
    }
  }
  JUMPOUT(0x2087C);
}
