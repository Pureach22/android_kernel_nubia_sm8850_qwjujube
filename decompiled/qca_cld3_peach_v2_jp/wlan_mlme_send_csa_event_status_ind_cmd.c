__int64 __fastcall wlan_mlme_send_csa_event_status_ind_cmd(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 ext_hdl; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _DWORD *v23; // x8

  v10 = *(_QWORD *)(a1 + 152);
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 80)) == 0 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev_id %d psoc object is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_mlme_send_csa_event_status_ind_cmd",
      *(unsigned __int8 *)(a1 + 104));
    return 16;
  }
  ext_hdl = wlan_psoc_mlme_get_ext_hdl(v11);
  if ( !ext_hdl )
    return 16;
  v23 = *(_DWORD **)(ext_hdl + 7408);
  if ( !v23 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: CSA no op defined",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "wlan_mlme_send_csa_event_status_ind_cmd");
    return 16;
  }
  if ( *(v23 - 1) != -988222069 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD))v23)(a1, a2);
}
