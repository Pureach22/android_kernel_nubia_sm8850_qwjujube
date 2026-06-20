__int64 __fastcall target_if_pmo_send_lphb_enable(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( a2 )
  {
    qdf_trace_msg(
      0x49u,
      4u,
      "%s: PMO_HB_SET_ENABLE enable=%d, item=%d, session=%d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_pmo_send_lphb_enable",
      *a2,
      a2[1],
      a2[2]);
    if ( (unsigned int)a2[1] - 1 >= 2 )
    {
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: LPHB configuration wrong item %d",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "target_if_pmo_send_lphb_enable");
      result = 16;
    }
    else if ( a1 && (v20 = *(_QWORD *)(a1 + 2800)) != 0 && (v21 = *(_QWORD *)(v20 + 16)) != 0 )
    {
      result = wmi_unified_lphb_config_hbenable_cmd(v21);
    }
    else
    {
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: Invalid wmi handle",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "target_if_pmo_send_lphb_enable");
      result = 4;
    }
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: LPHB Enable configuration is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_pmo_send_lphb_enable");
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
