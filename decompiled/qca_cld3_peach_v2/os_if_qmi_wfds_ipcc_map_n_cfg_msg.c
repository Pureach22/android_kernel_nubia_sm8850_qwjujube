__int64 __fastcall os_if_qmi_wfds_ipcc_map_n_cfg_msg(_DWORD *a1)
{
  __int64 v2; // x0
  _BYTE *v3; // x19
  __int64 v4; // x0
  __int64 v5; // x20
  unsigned int v6; // w0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v15; // w21
  const char *v16; // x2
  unsigned int v17; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v27; // [xsp+0h] [xbp-50h] BYREF
  __int64 v28; // [xsp+8h] [xbp-48h]
  __int64 v29; // [xsp+10h] [xbp-40h]
  __int64 v30; // [xsp+18h] [xbp-38h]
  __int64 v31; // [xsp+20h] [xbp-30h]
  __int64 v32; // [xsp+28h] [xbp-28h]
  __int64 v33; // [xsp+30h] [xbp-20h]
  __int64 v34; // [xsp+38h] [xbp-18h]
  __int64 v35; // [xsp+40h] [xbp-10h]
  __int64 v36; // [xsp+48h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v27 = 0;
  v2 = _qdf_mem_malloc(1u, "os_if_qmi_wfds_ipcc_map_n_cfg_msg", 383);
  if ( v2 )
  {
    v3 = (_BYTE *)v2;
    v4 = _qdf_mem_malloc(4u, "os_if_qmi_wfds_ipcc_map_n_cfg_msg", 387);
    if ( !v4 )
    {
      v15 = 2;
LABEL_11:
      _qdf_mem_free((__int64)v3);
      goto LABEL_12;
    }
    v5 = v4;
    *v3 = *a1 != 0;
    v6 = os_if_qmi_txn_init();
    if ( v6 )
    {
      v15 = v6;
      v16 = "%s: QMI txn init failed for WFDS ipcc cfg req message %d";
    }
    else
    {
      v17 = os_if_qmi_send_request((__int64)&qmi_wfds, 0, (__int64)&v27, 3, 4u);
      if ( v17 )
      {
        v15 = v17;
        qdf_trace_msg(
          0x48u,
          4u,
          "%s: QMI WFDS IPCC cfg request send failed %d",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "os_if_qmi_wfds_ipcc_map_n_cfg_msg",
          v17,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36);
        os_if_qmi_txn_cancel();
        goto LABEL_10;
      }
      v15 = os_if_qmi_txn_wait();
      if ( !v15 )
        goto LABEL_10;
      v16 = "%s: Wait for QMI WFDS IPCC response timed out %d";
    }
    qdf_trace_msg(
      0x48u,
      4u,
      v16,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "os_if_qmi_wfds_ipcc_map_n_cfg_msg",
      v15,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36);
LABEL_10:
    _qdf_mem_free(v5);
    goto LABEL_11;
  }
  v15 = 2;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return v15;
}
