__int64 wlan_dp_txrx_pdev_attach()
{
  __int64 v0; // x19
  __int64 **v1; // x0
  __int64 v2; // x2
  __int64 v3; // x3
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x8
  __int64 (__fastcall *v13)(__int64 **, __int64 *, __int64, __int64); // x8
  __int64 result; // x0
  unsigned int v15; // w0
  unsigned int v16; // w22
  __int64 v17; // x0
  __int64 v18; // x20
  __int64 **v19; // x19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x8
  _DWORD *v29; // x8
  __int64 context; // [xsp+0h] [xbp-20h] BYREF
  __int64 v31; // [xsp+8h] [xbp-18h]
  __int64 v32; // [xsp+10h] [xbp-10h]
  __int64 v33; // [xsp+18h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = gp_dp_ctx;
  v32 = 0;
  context = _cds_get_context(62, "wlan_dp_txrx_pdev_attach");
  v31 = _cds_get_context(64, "wlan_dp_txrx_pdev_attach");
  v1 = (__int64 **)_cds_get_context(71, "wlan_dp_txrx_pdev_attach");
  if ( !v1 || !*v1 )
  {
    qdf_trace_msg(
      0x89u,
      8u,
      "%s: Invalid Instance:",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "cdp_pdev_attach",
      context,
      v31,
      v32,
      v33);
LABEL_12:
    result = 16;
    goto LABEL_13;
  }
  v12 = **v1;
  if ( !v12 )
    goto LABEL_12;
  v13 = *(__int64 (__fastcall **)(__int64 **, __int64 *, __int64, __int64))(v12 + 32);
  if ( !v13 )
    goto LABEL_12;
  if ( *((_DWORD *)v13 - 1) != 1681154952 )
    __break(0x8228u);
  result = v13(v1, &context, v2, v3);
  if ( !(_DWORD)result )
  {
    v15 = dp_rx_fst_attach(v0);
    if ( v15 != 11 && v15 )
    {
      v16 = v15;
      v17 = _cds_get_context(71, "wlan_dp_txrx_pdev_attach");
      v18 = gp_dp_ctx;
      v19 = (__int64 **)v17;
      wlan_dp_stc_detach(gp_dp_ctx);
      dp_rx_fst_detach(v18);
      if ( v19 && *v19 )
      {
        v28 = **v19;
        if ( v28 )
        {
          v29 = *(_DWORD **)(v28 + 56);
          if ( v29 )
          {
            if ( *(v29 - 1) != 226555140 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64 **, _QWORD, _QWORD))v29)(v19, 0, 0);
          }
        }
      }
      else
      {
        qdf_trace_msg(
          0x89u,
          8u,
          "%s: Invalid Instance:",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "cdp_pdev_detach",
          context,
          v31,
          v32,
          v33);
      }
      result = v16;
    }
    else
    {
      wlan_dp_resource_mgr_set_req_resources(*(_QWORD *)(v0 + 3000));
      result = 0;
    }
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
