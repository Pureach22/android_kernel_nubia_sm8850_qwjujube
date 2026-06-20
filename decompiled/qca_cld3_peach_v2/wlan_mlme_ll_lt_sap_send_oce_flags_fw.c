__int64 __fastcall wlan_mlme_ll_lt_sap_send_oce_flags_fw(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int v11; // w19
  int v12; // w20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  v1 = *(_QWORD *)(result + 216);
  if ( v1 )
  {
    v2 = result;
    result = *(_QWORD *)(v1 + 80);
    if ( result )
    {
      result = mlme_get_psoc_ext_obj_fl(result);
      if ( result )
      {
        v11 = *(unsigned __int8 *)(v2 + 168);
        v12 = *(unsigned __int8 *)(result + 3668);
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: Vdev %d Disable FILS discovery",
          v3,
          v4,
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          "wlan_mlme_ll_lt_sap_send_oce_flags_fw",
          v11);
        result = wma_cli_set_command(v11, 120, v12 & 0xFFFFFFEF, 1);
        if ( (_DWORD)result )
          return qdf_trace_msg(
                   0x1Fu,
                   2u,
                   "%s: Vdev %d failed to send OCE update",
                   v13,
                   v14,
                   v15,
                   v16,
                   v17,
                   v18,
                   v19,
                   v20,
                   "wlan_mlme_ll_lt_sap_send_oce_flags_fw",
                   v11);
      }
    }
  }
  return result;
}
