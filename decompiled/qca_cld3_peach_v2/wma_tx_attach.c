__int64 __fastcall wma_tx_attach(
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
  __int64 v10; // x21
  __int64 **context; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 *v20; // x8
  __int64 **v21; // x20
  void (*v22)(void); // x8
  const char *v23; // x2
  const char *v24; // x3
  __int64 v25; // x8
  __int64 (*v26)(void); // x8
  __int64 v27; // x8
  _DWORD *v28; // x8

  v10 = *(_QWORD *)(a1 + 8);
  context = (__int64 **)_cds_get_context(71, (__int64)"wma_tx_attach", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v12, v13, v14, v15, v16, v17, v18, v19, "cdp_mgmt_tx_cb_set");
    goto LABEL_11;
  }
  v20 = *context;
  v21 = context;
  if ( !*context )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v12, v13, v14, v15, v16, v17, v18, v19, "cdp_mgmt_tx_cb_set");
    v20 = *v21;
    if ( *v21 )
      goto LABEL_14;
LABEL_11:
    v23 = "%s: invalid instance";
    v24 = "cdp_cfg_get_peer_unmap_conf_support";
LABEL_12:
    qdf_trace_msg(0x89u, 8u, v23, v12, v13, v14, v15, v16, v17, v18, v19, v24);
    goto LABEL_25;
  }
  if ( *v20 )
  {
    v22 = *(void (**)(void))(*v20 + 296);
    if ( v22 )
    {
      if ( *((_DWORD *)v22 - 1) != -1593903812 )
        __break(0x8228u);
      v22();
    }
    v20 = *v21;
    if ( !*v21 )
      goto LABEL_11;
  }
LABEL_14:
  v25 = v20[13];
  if ( v25 )
  {
    v26 = *(__int64 (**)(void))(v25 + 96);
    if ( v26 )
    {
      if ( *((_DWORD *)v26 - 1) != 799902358 )
        __break(0x8228u);
      if ( (v26() & 1) != 0 )
      {
        if ( !*v21 )
        {
          v23 = "%s: Invalid Instance:";
          v24 = "cdp_peer_unmap_sync_cb_set";
          goto LABEL_12;
        }
        v27 = **v21;
        if ( v27 )
        {
          v28 = *(_DWORD **)(v27 + 184);
          if ( v28 )
          {
            if ( *(v28 - 1) != -44265081 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64 **, _QWORD, __int64 (__fastcall *)()))v28)(v21, 0, wma_peer_unmap_conf_cb);
          }
        }
      }
    }
  }
LABEL_25:
  *(_QWORD *)(a1 + 16) = *(_QWORD *)(v10 + 8);
  return 0;
}
