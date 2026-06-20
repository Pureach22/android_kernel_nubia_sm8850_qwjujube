__int64 __fastcall wlan_mlme_psoc_enable(__int64 a1)
{
  unsigned int v2; // w0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int v11; // w19
  unsigned int v13; // w0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w20
  __int64 v23; // x8
  void (__fastcall *v24)(_QWORD); // x8

  v2 = mlme_psoc_ext_enable_cb();
  if ( v2 )
  {
    v11 = v2;
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Failed to register enable mlme ext param handler cb",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "wlan_mlme_psoc_enable");
    return v11;
  }
  else
  {
    v13 = wlan_serialization_register_comp_info_cb(a1, 0, 0, (__int64)mlme_scan_serialization_comp_info_cb);
    if ( v13 )
    {
      v22 = v13;
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: Serialize scan cmd register failed",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "wlan_mlme_psoc_enable");
      mlme_psoc_ext_disable_cb();
      return v22;
    }
    else
    {
      if ( a1 && (v23 = *(_QWORD *)(a1 + 2128)) != 0 )
      {
        v24 = *(void (__fastcall **)(_QWORD))(v23 + 1384);
        if ( v24 )
        {
          if ( *((_DWORD *)v24 - 1) != -770124015 )
            __break(0x8228u);
          v24(a1);
        }
      }
      else
      {
        qdf_trace_msg(
          0x38u,
          2u,
          "%s: tx_ops is NULL",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "wlan_mlme_get_lmac_tx_ops");
      }
      return 0;
    }
  }
}
