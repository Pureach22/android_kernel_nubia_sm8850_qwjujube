__int64 __fastcall reg_freq_to_chan_op_class(
        __int64 a1,
        unsigned int a2,
        char a3,
        unsigned int a4,
        __int64 a5,
        __int64 a6)
{
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x20
  __int64 v30; // x20
  __int64 bw_value; // x0
  unsigned int v32; // [xsp+8h] [xbp-18h] BYREF
  __int64 v33; // [xsp+Ch] [xbp-14h]
  int v34; // [xsp+14h] [xbp-Ch]
  __int64 v35; // [xsp+18h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = 0;
  v33 = 0;
  result = reg_get_pdev_obj(a1);
  if ( result )
  {
    result = reg_get_chan_enum_for_freq(a2);
    if ( (unsigned int)result < 0x66 )
    {
      v32 = 9;
      reg_set_channel_params_for_pwrmode(a1, a2, 0, &v32, 0, 1);
      bw_value = reg_get_bw_value(v32);
      result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, __int64, __int64))reg_freq_width_to_chan_op_class)(
                 bw_value,
                 a2,
                 (unsigned int)bw_value,
                 a3 & 1,
                 a4,
                 a5,
                 a6);
    }
    else
    {
      v29 = jiffies;
      if ( reg_freq_to_chan_op_class___last_ticks_10 - jiffies + 125 < 0 )
      {
        result = qdf_trace_msg(
                   0x51u,
                   2u,
                   "%s: Invalid chan enum %d",
                   v21,
                   v22,
                   v23,
                   v24,
                   v25,
                   v26,
                   v27,
                   v28,
                   "reg_freq_to_chan_op_class",
                   (unsigned int)result);
        reg_freq_to_chan_op_class___last_ticks_10 = v29;
      }
    }
  }
  else
  {
    v30 = jiffies;
    if ( reg_freq_to_chan_op_class___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x51u,
                 2u,
                 "%s: NULL pdev reg obj",
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 "reg_freq_to_chan_op_class");
      reg_freq_to_chan_op_class___last_ticks = v30;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
