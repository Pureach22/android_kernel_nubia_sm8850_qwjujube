__int64 __fastcall target_if_cfr_enable_cfr_timer(__int64 a1, int a2)
{
  __int64 comp_private_obj; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  __int64 pdev_wmi_handle; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x20
  __int64 result; // x0
  __int64 v25; // x0
  __int64 v26; // x20
  __int64 v27; // [xsp+8h] [xbp-18h] BYREF
  int v28; // [xsp+10h] [xbp-10h]
  __int64 v29; // [xsp+18h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x1Eu);
  if ( !comp_private_obj )
  {
    result = 16;
    goto LABEL_11;
  }
  v13 = comp_private_obj;
  if ( a2 )
  {
    v28 = 0;
    v27 = 0;
    pdev_wmi_handle = lmac_get_pdev_wmi_handle(a1, v5, v6, v7, v8, v9, v10, v11, v12);
    if ( pdev_wmi_handle )
    {
      v23 = pdev_wmi_handle;
      qdf_mem_set(&v27, 0xCu, 0);
      v27 = 0x1000000A8LL;
      result = wmi_unified_pdev_param_send(v23);
      if ( !(_DWORD)result )
        *(_BYTE *)(v13 + 9) = 1;
      goto LABEL_11;
    }
LABEL_10:
    qdf_trace_msg(
      0x6Au,
      2u,
      "%s: pdev wmi handle NULL",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "target_if_cfr_periodic_peer_cfr_enable");
    result = 4294967274LL;
    goto LABEL_11;
  }
  v28 = 0;
  v27 = 0;
  v25 = lmac_get_pdev_wmi_handle(a1, v5, v6, v7, v8, v9, v10, v11, v12);
  if ( !v25 )
    goto LABEL_10;
  v26 = v25;
  qdf_mem_set(&v27, 0xCu, 0);
  v27 = 168;
  result = wmi_unified_pdev_param_send(v26);
  if ( !(_DWORD)result )
    *(_BYTE *)(v13 + 9) = 0;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
