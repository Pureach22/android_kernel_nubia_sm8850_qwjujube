__int64 __fastcall ucfg_cfr_rcc_clr_dbg_counters(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x19
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x8
  void (*v22)(void); // x8
  __int64 v23; // x8
  unsigned int v24; // w20
  __int64 v25; // [xsp+8h] [xbp-18h] BYREF
  __int64 v26[2]; // [xsp+10h] [xbp-10h] BYREF

  v26[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = 0;
  v26[0] = 0;
  result = dev_sanity_check(a1, &v25, v26, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !(_DWORD)result )
  {
    v18 = v25;
    v19 = *(_QWORD *)(v25 + 80);
    if ( v19 )
    {
      v20 = *(_QWORD *)(v19 + 2808);
      if ( v20 && *(_QWORD *)v20 )
      {
        v21 = *(_QWORD *)(*(_QWORD *)v20 + 168LL);
        if ( v21 )
        {
          v22 = *(void (**)(void))(v21 + 24);
          if ( v22 )
          {
            if ( *((_DWORD *)v22 - 1) != -251540498 )
              __break(0x8228u);
            v22();
          }
        }
      }
      else
      {
        qdf_trace_msg(0x45u, 1u, "%s invalid instance", v10, v11, v12, v13, v14, v15, v16, v17, "cdp_cfr_clr_dbg_stats");
      }
      v23 = v26[0];
      v24 = 0;
      *(_QWORD *)(v26[0] + 1320) = 0;
      *(_QWORD *)(v23 + 1432) = 0;
      *(_QWORD *)(v23 + 104) = 0;
      *(_QWORD *)(v23 + 112) = 0;
      *(_QWORD *)(v23 + 120) = 0;
      *(_QWORD *)(v23 + 128) = 0;
      *(_QWORD *)(v23 + 136) = 0;
      *(_QWORD *)(v23 + 144) = 0;
      *(_QWORD *)(v23 + 1392) = 0;
      *(_QWORD *)(v23 + 1400) = 0;
      *(_QWORD *)(v23 + 1408) = 0;
      *(_QWORD *)(v23 + 1416) = 0;
    }
    else
    {
      qdf_trace_msg(
        0x6Au,
        2u,
        "%s: psoc is null!",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "ucfg_cfr_rcc_clr_dbg_counters");
      v24 = 29;
    }
    wlan_objmgr_pdev_release_ref(v18, 0x30u, (unsigned int *)v23, v10, v11, v12, v13, v14, v15, v16, v17);
    result = v24;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
