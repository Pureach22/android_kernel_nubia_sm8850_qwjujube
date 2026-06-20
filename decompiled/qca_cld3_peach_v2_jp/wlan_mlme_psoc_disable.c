__int64 __fastcall wlan_mlme_psoc_disable(
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
  __int64 v10; // x8
  void (*v11)(void); // x8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w19

  if ( a1 && (v10 = *(_QWORD *)(a1 + 2128)) != 0 )
  {
    v11 = *(void (**)(void))(v10 + 1392);
    if ( v11 )
    {
      if ( *((_DWORD *)v11 - 1) != -770124015 )
        __break(0x8228u);
      v11();
    }
  }
  else
  {
    qdf_trace_msg(0x38u, 2u, "%s: tx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_mlme_get_lmac_tx_ops");
  }
  if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))wlan_serialization_deregister_comp_info_cb)(
                       a1,
                       0,
                       0) )
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Serialize scan cmd deregister failed",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_mlme_psoc_disable");
  result = mlme_psoc_ext_disable_cb();
  if ( (_DWORD)result )
  {
    v29 = result;
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Failed to unregister enable mlme ext param hdl cb",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "wlan_mlme_psoc_disable");
    return v29;
  }
  return result;
}
