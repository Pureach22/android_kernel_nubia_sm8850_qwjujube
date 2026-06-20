__int64 __fastcall tdls_find_opclass_frm_freq(
        __int64 a1,
        unsigned __int16 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x24
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( *(_QWORD *)(a1 + 216) )
  {
    if ( wlan_reg_is_6ghz_chan_freq(a2) )
    {
      v18 = jiffies;
      if ( tdls_find_opclass_frm_freq___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0,
          8u,
          "%s: allow to set op class with global_op_class",
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          "tdls_find_opclass_frm_freq");
        tdls_find_opclass_frm_freq___last_ticks = v18;
      }
    }
    wlan_reg_freq_width_to_chan_op_class();
    result = 0;
  }
  else
  {
    qdf_trace_msg(0, 2u, "%s: pdev is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "tdls_find_opclass_frm_freq");
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
