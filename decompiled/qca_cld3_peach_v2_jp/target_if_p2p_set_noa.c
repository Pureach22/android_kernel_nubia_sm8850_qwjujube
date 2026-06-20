__int64 __fastcall target_if_p2p_set_noa(
        __int64 a1,
        unsigned int a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 wmi_unified_hdl; // x0
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

  _ReadStatusReg(SP_EL0);
  wmi_unified_hdl = lmac_get_wmi_unified_hdl(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( wmi_unified_hdl )
  {
    v23 = wmi_unified_hdl;
    qdf_trace_msg(
      0x49u,
      8u,
      "%s: psoc:%pK, vdev_id:%d disable_noa:%d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "target_if_p2p_set_noa",
      a1,
      a2,
      a3 & 1);
    result = wmi_unified_vdev_set_param_send(v23);
  }
  else
  {
    qdf_trace_msg(0x49u, 2u, "%s: Invalid wmi handle", v15, v16, v17, v18, v19, v20, v21, v22, "target_if_p2p_set_noa");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
