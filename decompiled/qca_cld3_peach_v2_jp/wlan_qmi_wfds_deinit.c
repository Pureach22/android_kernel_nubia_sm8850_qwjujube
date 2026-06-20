__int64 __fastcall wlan_qmi_wfds_deinit(__int64 a1)
{
  __int64 result; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 (*v10)(void); // x8

  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x31u);
  if ( !result )
    return qdf_trace_msg(0x9Du, 2u, "%s: QMI context is NULL", v2, v3, v4, v5, v6, v7, v8, v9, "wlan_qmi_wfds_deinit");
  v10 = *(__int64 (**)(void))(result + 16);
  if ( v10 )
  {
    if ( *((_DWORD *)v10 - 1) != -440107680 )
      __break(0x8228u);
    return v10();
  }
  return result;
}
