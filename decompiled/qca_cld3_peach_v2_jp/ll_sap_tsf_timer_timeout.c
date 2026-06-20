__int64 __fastcall ll_sap_tsf_timer_timeout(
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
  __int64 result; // x0
  __int64 v11; // x19
  unsigned int *v12; // x8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  if ( !a1 )
    return qdf_trace_msg(0xA1u, 2u, "%s: Invalid psoc", a2, a3, a4, a5, a6, a7, a8, a9, "ll_sap_tsf_timer_timeout");
  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x34u);
  if ( result )
  {
    result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
               a1,
               *(unsigned __int8 *)(result + 208),
               105);
    if ( result )
    {
      v11 = result;
      wlan_ll_sap_notify_chan_switch_started();
      wlan_ll_sap_send_continue_vdev_restart();
      return wlan_objmgr_vdev_release_ref(v11, 0x69u, v12, v13, v14, v15, v16, v17, v18, v19, v20);
    }
  }
  return result;
}
