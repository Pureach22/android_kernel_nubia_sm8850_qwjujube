__int64 __fastcall wma_process_cfg_action_frm_tb_ppdu(__int64 *a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( (unsigned int)_wma_validate_handle(a1, "wma_process_cfg_action_frm_tb_ppdu") )
  {
    result = 16;
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: cfg: %d, frm_len: %d",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "wma_process_cfg_action_frm_tb_ppdu");
    result = wmi_unified_cfg_action_frm_tb_ppdu_cmd(*a1);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
