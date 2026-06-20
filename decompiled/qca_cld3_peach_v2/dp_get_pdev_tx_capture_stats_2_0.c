__int64 __fastcall dp_get_pdev_tx_capture_stats_2_0(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v12; // x8
  const char *v13; // x2
  unsigned int v14; // w1

  if ( a1 )
  {
    v10 = *(_QWORD *)(a1 + 96456);
    if ( v10 )
    {
      v12 = v10 + 39344;
      *(_DWORD *)(a2 + 520) = *(_DWORD *)v12;
      *(_DWORD *)(a2 + 524) = *(_DWORD *)(v12 + 8);
      *(_QWORD *)(a2 + 528) = *(_QWORD *)(v12 + 152);
      *(_QWORD *)(a2 + 536) = *(_QWORD *)(v12 + 160);
      *(_QWORD *)(a2 + 544) = *(_QWORD *)(v12 + 168);
      *(_QWORD *)(a2 + 552) = *(_QWORD *)(v12 + 176);
      *(_QWORD *)(a2 + 560) = *(_QWORD *)(v12 + 184);
      *(_QWORD *)(a2 + 568) = *(_QWORD *)(v12 + 192);
      *(_QWORD *)(a2 + 576) = *(_QWORD *)(v12 + 208);
      *(_QWORD *)(a2 + 584) = *(_QWORD *)(v12 + 224);
      *(_QWORD *)(a2 + 592) = *(_QWORD *)(v12 + 232);
      *(_QWORD *)(a2 + 600) = *(_QWORD *)(v12 + 240);
      *(_QWORD *)(a2 + 608) = *(_QWORD *)(v12 + 248);
      *(_BYTE *)(a2 + 616) = *(_BYTE *)(v12 + 256);
      *(_DWORD *)(a2 + 620) = *(_DWORD *)(v12 + 260);
      *(_QWORD *)(a2 + 624) = *(_QWORD *)(v12 + 264);
      *(_QWORD *)(a2 + 632) = *(_QWORD *)(v12 + 272);
      *(_QWORD *)(a2 + 640) = *(_QWORD *)(v12 + 280);
      *(_QWORD *)(a2 + 648) = *(_QWORD *)(v12 + 288);
      *(_DWORD *)(a2 + 660) = *(_DWORD *)(v12 + 2556);
      *(_DWORD *)(a2 + 664) = *(_DWORD *)(v12 + 2560);
      *(_DWORD *)(a2 + 668) = *(_DWORD *)(v12 + 2564);
      *(_DWORD *)(a2 + 676) = *(_DWORD *)(v12 + 2572);
      *(_DWORD *)(a2 + 672) = *(_DWORD *)(v12 + 2568);
      return 0;
    }
    v13 = "%s: Monitor Pdev is NULL";
    v14 = 8;
  }
  else
  {
    v13 = "%s: Pdev is NULL";
    v14 = 2;
  }
  qdf_trace_msg(0x92u, v14, v13, a3, a4, a5, a6, a7, a8, a9, a10, "dp_get_pdev_tx_capture_stats_2_0");
  return 16;
}
