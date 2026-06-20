__int64 __fastcall hdd_cm_netif_queue_enable(
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
  __int64 **context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  unsigned int (*v20)(void); // x8
  __int64 v21; // x21
  unsigned int v22; // w20
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  int v31; // w8
  __int64 v32; // x9
  unsigned __int64 StatusReg; // x8
  __int64 v34; // x1
  unsigned int v42; // w9
  unsigned int v43; // w9

  context = (__int64 **)_cds_get_context(71, (__int64)"hdd_cm_netif_queue_enable", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context && *context )
  {
    v19 = **context;
    if ( v19 )
    {
      v20 = *(unsigned int (**)(void))(v19 + 264);
      if ( v20 )
      {
        v21 = *(_QWORD *)(a1 + 24);
        if ( *((_DWORD *)v20 - 1) != -1095293032 )
          __break(0x8228u);
        if ( v20() )
        {
          v22 = hdd_is_legacy_connection(*(_QWORD *)(a1 + 52832)) & 1;
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Legacy Connection: %d, TSO_CSUM Feature Enabled:%d",
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            "hdd_cm_netif_features_update_required",
            v22,
            *(unsigned __int8 *)(a1 + 52466));
          if ( v22 == *(unsigned __int8 *)(a1 + 52466) )
          {
            v31 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 52832) + 8LL);
            _X10 = (unsigned int *)(v21 + 6872);
            __asm { PRFM            #0x11, [X10] }
            do
            {
              v42 = __ldxr(_X10);
              v43 = v42 + 1;
            }
            while ( __stlxr(v43, _X10) );
            __dmb(0xBu);
            v32 = v21 + 16LL * (v43 & 3);
            *(_DWORD *)(v32 + 6888) = 0;
            *(_DWORD *)(v32 + 6892) = v31;
            __isb(0xFu);
            StatusReg = _ReadStatusReg(CNTVCT_EL0);
            v34 = *(_QWORD *)(v21 + 6864);
            *(_QWORD *)(v32 + 6880) = StatusReg;
            queue_work_on(32, v34, a1 + 52472);
          }
        }
      }
    }
  }
  else
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance", v11, v12, v13, v14, v15, v16, v17, v18, "cdp_cfg_get");
  }
  return wlan_hdd_netif_queue_control(a1, 3, 1);
}
