__int64 __fastcall target_if_p2p_set_ps(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 wmi_unified_hdl; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x20
  __int64 result; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  const char *v31; // x2
  unsigned int v32; // w19

  _ReadStatusReg(SP_EL0);
  wmi_unified_hdl = lmac_get_wmi_unified_hdl(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !wmi_unified_hdl )
  {
    v31 = "%s: Invalid wmi handle";
LABEL_8:
    qdf_trace_msg(0x49u, 2u, v31, v13, v14, v15, v16, v17, v18, v19, v20, "target_if_p2p_set_ps");
    result = 4;
    goto LABEL_11;
  }
  if ( !a2 )
  {
    v31 = "%s: ps config parameters is null";
    goto LABEL_8;
  }
  v21 = wmi_unified_hdl;
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: psoc:%pK, vdev_id:%d, opp_ps:%d",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "target_if_p2p_set_ps",
    a1,
    *a2,
    a2[1]);
  if ( a2[1] )
  {
    result = wmi_unified_set_p2pgo_oppps_req(v21);
    if ( !(_DWORD)result )
      goto LABEL_11;
    goto LABEL_10;
  }
  result = wmi_unified_set_p2pgo_noa_req_cmd(v21);
  if ( (_DWORD)result )
  {
LABEL_10:
    v32 = result;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Failed to send set uapsd param, %d",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "target_if_p2p_set_ps",
      (unsigned int)result);
    result = v32;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
