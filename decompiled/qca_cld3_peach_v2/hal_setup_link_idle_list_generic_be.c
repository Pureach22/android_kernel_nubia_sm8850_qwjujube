__int64 __fastcall hal_setup_link_idle_list_generic_be(
        __int64 a1,
        unsigned int *a2,
        __int64 a3,
        int a4,
        unsigned int a5,
        unsigned int a6,
        int a7)
{
  __int64 v12; // x8
  _DWORD *v13; // x12
  __int64 v14; // x12
  unsigned int *v15; // x13
  unsigned int v16; // w25
  unsigned int *v17; // x22

  if ( a4 )
  {
    v12 = 0;
    v13 = nullptr;
    do
    {
      if ( (int)v12 >= 1 )
      {
        v15 = &a2[2 * v12];
        *v13 = *(_QWORD *)v15;
        v13[1] = *((unsigned __int8 *)v15 + 4) | 0x500;
      }
      v14 = *(_QWORD *)(a3 + 8LL * (int)v12++);
      v13 = (_DWORD *)(v14 + a5 - 8);
    }
    while ( a4 != (_DWORD)v12 );
  }
  v16 = a5 - 8;
  hal_write32_mb_1(a1, "il. count %u", ((a5 - 8) >> 4) & 0x7FC | 2);
  hal_write32_mb_1(a1, "count %u", ((a4 * v16) << 10) & 0xFFFF0000);
  hal_write32_mb_1(a1, "ress", *a2);
  hal_write32_mb_1(a1, "", *((unsigned __int8 *)a2 + 4));
  hal_write32_mb_1(a1, "", *((unsigned __int8 *)a2 + 4) | 0x500u);
  v17 = &a2[2 * (a4 - 1)];
  hal_write32_mb_1(a1, "%d not OK for DNBS", *(_QWORD *)v17);
  hal_write32_mb_1(a1, "ot OK for DNBS", *((unsigned __int8 *)v17 + 4) | (((a6 >> 2) & 0x1FFF) << 8));
  hal_write32_mb_1(a1, "%d not OK for DNBS", *a2);
  hal_write32_mb_1(a1, "BS", *a2);
  hal_write32_mb_1(a1, "s: P2P USD OP type parse failed", *((unsigned __int8 *)a2 + 4));
  hal_write32_mb_1(a1, "SD OP type parse failed", (unsigned int)(2 * a7));
  return hal_write32_mb_1(a1, "mimo_brp6_err = %u", 1);
}
