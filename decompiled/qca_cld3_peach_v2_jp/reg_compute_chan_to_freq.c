__int64 __fastcall reg_compute_chan_to_freq(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 pdev_obj; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x20
  __int64 result; // x0
  unsigned int v26; // w11
  int v27; // w8
  unsigned int v28; // w21
  unsigned int v29; // w22
  unsigned int v30; // w23

  pdev_obj = reg_get_pdev_obj(a1, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( pdev_obj )
  {
    v24 = pdev_obj;
    result = reg_compute_chan_to_freq_for_chlist(pdev_obj + 7344, a2, a3, a4);
    if ( !(_WORD)result )
    {
      v26 = a4 - 42;
      v27 = (unsigned __int16)(a4 - 42);
      v28 = a3 - 42 >= 0x3C ? 102 : (unsigned __int16)(a3 - 42);
      result = 0;
      v29 = v26 >= 0x3C ? 102 : v27;
      if ( v28 <= 0x65 && v29 <= 0x65 )
      {
        v30 = 1;
        while ( 1 )
        {
          result = ((__int64 (__fastcall *)(_QWORD, __int64, _QWORD))reg_get_reg_maschan_lst_frm_6g_pwr_mode)(
                     v30,
                     v24,
                     0);
          if ( !result )
            break;
          result = reg_compute_chan_to_freq_for_chlist(result, a2, v28, v29);
          if ( (_WORD)result )
            break;
          if ( ++v30 == 13 )
            return 0;
        }
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: reg pdev priv obj is NULL",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "reg_compute_chan_to_freq");
    return 0;
  }
  return result;
}
