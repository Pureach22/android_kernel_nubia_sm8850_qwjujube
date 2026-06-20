// local variable allocation has failed, the output may be wrong!
void sub_15108(
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
  __int64 v17; // x21
  int v18; // w8
  __int64 v19; // x8
  __int64 v20; // x8
  gcc_va_list va; // [xsp+8h] [xbp+8h] OVERLAPPED BYREF
  gcc_va_list va1; // [xsp+28h] [xbp+28h] OVERLAPPED BYREF
  gcc_va_list va2; // [xsp+48h] [xbp+48h] OVERLAPPED BYREF

  if ( (*(_BYTE *)(v16 + 81) & 2) != 0 || *(_WORD *)(v16 + 76) )
  {
    v18 = *(unsigned __int16 *)(v17 + 180);
    va_start(va2, a16);
    va_start(va, a16);
    va_start(va1, a16);
    if ( v18 == 8 )
    {
      v19 = *(_QWORD *)(v17 + 216) + *(unsigned __int16 *)(v17 + 184);
      if ( *(_BYTE *)(v19 + 9) != 17 )
        goto LABEL_10;
      snprintf((char *)&va1[0].__vr_top, 0x30u, "%pI4", (const void *)(v19 + 12));
      snprintf(
        (char *)va,
        0x30u,
        "%pI4",
        (const void *)(*(_QWORD *)(v17 + 216) + *(unsigned __int16 *)(v17 + 184) + 16LL));
      v18 = *(unsigned __int16 *)(v17 + 180);
    }
    if ( v18 == 56710 )
    {
      v20 = *(_QWORD *)(v17 + 216) + *(unsigned __int16 *)(v17 + 184);
      if ( *(_BYTE *)(v20 + 6) != 17 )
        goto LABEL_10;
      snprintf((char *)&va1[0].__vr_top, 0x30u, "%pI6", (const void *)(v20 + 8));
      snprintf(
        (char *)va,
        0x30u,
        "%pI6",
        (const void *)(*(_QWORD *)(v17 + 216) + *(unsigned __int16 *)(v17 + 184) + 24LL));
    }
    rmnet_descriptor_trace_pfn(v17);
  }
LABEL_10:
  JUMPOUT(0x14ED4);
}
