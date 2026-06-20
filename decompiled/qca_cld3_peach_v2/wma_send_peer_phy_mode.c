__int64 __fastcall wma_send_peer_phy_mode(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned __int8 a10,
        int a11)
{
  __int64 result; // x0
  __int64 *v14; // x22
  unsigned int v15; // w19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  _ReadStatusReg(SP_EL0);
  result = (__int64)_cds_get_context(54, (__int64)"wma_send_peer_phy_mode", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( result )
  {
    v14 = (__int64 *)result;
    v15 = wmi_host_to_fw_phymode(a11);
    result = wmi_set_peer_param_send(*v14);
    if ( (_DWORD)result )
      result = qdf_trace_msg(
                 0x36u,
                 2u,
                 "%s: vdev_id: %d peer set failed, id %d, val %d",
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 "wma_set_peer_param",
                 a10,
                 13,
                 v15);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
