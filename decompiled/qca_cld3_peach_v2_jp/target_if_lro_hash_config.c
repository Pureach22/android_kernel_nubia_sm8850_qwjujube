__int64 __fastcall target_if_lro_hash_config(__int64 a1, unsigned __int8 a2, __int64 a3)
{
  __int64 pdev_by_id; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x20
  __int64 pdev_wmi_handle; // x0
  unsigned int *v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x22
  unsigned int v26; // w19
  unsigned int *v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 result; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  _QWORD v45[8]; // [xsp+14h] [xbp-4Ch] BYREF
  int v46; // [xsp+54h] [xbp-Ch]
  __int64 v47; // [xsp+58h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v45, 0, sizeof(v45));
  pdev_by_id = wlan_objmgr_get_pdev_by_id(a1, a2, 0x2Du);
  if ( pdev_by_id )
  {
    v14 = pdev_by_id;
    pdev_wmi_handle = lmac_get_pdev_wmi_handle(pdev_by_id, v6, v7, v8, v9, v10, v11, v12, v13);
    v25 = pdev_wmi_handle;
    if ( a3 && pdev_wmi_handle )
    {
      v46 = a2;
      qdf_mem_copy(v45, (const void *)(a3 + 8), 0x14u);
      qdf_mem_copy((char *)&v45[2] + 4, (const void *)(a3 + 28), 0x2Cu);
      v26 = wmi_unified_lro_config_cmd(v25);
      wlan_objmgr_pdev_release_ref(v14, 0x2Du, v27, v28, v29, v30, v31, v32, v33, v34, v35);
      result = v26;
    }
    else
    {
      wlan_objmgr_pdev_release_ref(v14, 0x2Du, v16, v17, v18, v19, v20, v21, v22, v23, v24);
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: wmi_handle: 0x%pK, lro_hash_cfg: 0x%pK",
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        "target_if_lro_hash_config",
        v25,
        a3);
      result = 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: pdev with id %d is NULL",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "target_if_lro_hash_config",
      a2);
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
