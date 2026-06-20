__int64 __fastcall ll_lt_sap_deliver_audio_transport_switch_resp_to_fw(__int64 a1, unsigned int a2, unsigned int a3)
{
  _DWORD **comp_private_obj; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  _DWORD *v15; // x8
  const char *v17; // x2

  comp_private_obj = (_DWORD **)wlan_objmgr_psoc_get_comp_private_obj(a1, 0x34u);
  if ( !comp_private_obj )
  {
    v17 = "%s: psoc_ll_sap_obj is null";
    return qdf_trace_msg(
             0xA1u,
             2u,
             v17,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             "ll_lt_sap_deliver_audio_transport_switch_resp_to_fw");
  }
  v15 = *comp_private_obj;
  if ( !*comp_private_obj )
  {
    v17 = "%s: deliver_audio_transport_switch_resp op is NULL";
    return qdf_trace_msg(
             0xA1u,
             2u,
             v17,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             "ll_lt_sap_deliver_audio_transport_switch_resp_to_fw");
  }
  if ( *(v15 - 1) != 1380159806 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v15)(a1, a2, a3);
}
