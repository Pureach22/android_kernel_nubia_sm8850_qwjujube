__int64 __fastcall wma_send_regdomain_info_to_fw(
        unsigned int a1,
        unsigned __int16 a2,
        unsigned __int16 a3,
        unsigned __int8 a4,
        unsigned __int8 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 *context; // x19
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 result; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7

  _ReadStatusReg(SP_EL0);
  context = _cds_get_context(54, (__int64)"wma_send_regdomain_info_to_fw", a6, a7, a8, a9, a10, a11, a12, a13);
  result = qdf_trace_msg(
             0x36u,
             8u,
             "%s: reg_dmn: %d regdmn2g: %d regdmn5g :%d ctl2g: %d ctl5g: %d",
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25,
             v26,
             "wma_send_regdomain_info_to_fw",
             a1,
             a2,
             a3,
             a4,
             a5);
  if ( context )
  {
    result = wmi_unified_send_regdomain_info_to_fw_cmd(*context);
    if ( (_DWORD)result != 2 )
    {
      result = wmi_unified_pdev_param_send(*context);
      if ( (_DWORD)result )
        result = qdf_trace_msg(
                   0x36u,
                   2u,
                   "%s: failed to set PDEV tx_chain_mask_cck %d",
                   v28,
                   v29,
                   v30,
                   v31,
                   v32,
                   v33,
                   v34,
                   v35,
                   "wma_send_regdomain_info_to_fw",
                   (unsigned int)result);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
