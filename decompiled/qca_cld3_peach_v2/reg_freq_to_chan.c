__int64 __fastcall reg_freq_to_chan(
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
  __int64 pdev_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x20
  __int64 result; // x0
  unsigned int i; // w21
  __int64 v23; // x20

  if ( !a2 )
  {
    v23 = jiffies;
    if ( reg_freq_to_chan___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(0x51u, 8u, "%s: Invalid freq %d", a3, a4, a5, a6, a7, a8, a9, a10, "reg_freq_to_chan", 0);
      reg_freq_to_chan___last_ticks = v23;
      return 0;
    }
    return 0;
  }
  pdev_obj = reg_get_pdev_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !pdev_obj )
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: reg pdev priv obj is NULL",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "reg_freq_to_chan");
    return 0;
  }
  v20 = pdev_obj;
  result = reg_freq_to_chan_for_chlist(pdev_obj + 7344, a2, 102);
  if ( (_BYTE)result )
    return result;
  if ( *(_DWORD *)(channel_map + 504) > (unsigned int)(unsigned __int16)a2
    || *(_DWORD *)(channel_map + 1212) < (unsigned int)(unsigned __int16)a2 )
  {
    return 0;
  }
  for ( i = 1; i != 13; ++i )
  {
    result = ((__int64 (__fastcall *)(_QWORD, __int64, _QWORD))reg_get_reg_maschan_lst_frm_6g_pwr_mode)(i, v20, 0);
    if ( !result )
      break;
    result = reg_freq_to_chan_for_chlist(result, a2, 60);
    if ( (_BYTE)result )
      break;
    result = 0;
  }
  return result;
}
