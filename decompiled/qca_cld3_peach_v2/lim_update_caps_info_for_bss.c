__int64 __fastcall lim_update_caps_info_for_bss(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        _WORD *a10,
        __int16 a11)
{
  char v13; // w21
  __int64 result; // x0

  v13 = a11;
  if ( (a11 & 0x100) != 0 )
  {
    if ( (a11 & 0x20) != 0 )
      goto LABEL_3;
  }
  else
  {
    *a10 &= ~0x100u;
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: Clearing spectrum management:no AP support",
               a1,
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               "lim_update_caps_info_for_bss");
    if ( (v13 & 0x20) != 0 )
    {
LABEL_3:
      if ( a11 < 0 )
        return result;
      goto LABEL_4;
    }
  }
  *a10 &= ~0x20u;
  result = qdf_trace_msg(
             0x35u,
             8u,
             "%s: Clearing short preamble:no AP support",
             a1,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             "lim_update_caps_info_for_bss");
  if ( a11 < 0 )
    return result;
LABEL_4:
  *a10 &= ~0x8000u;
  return qdf_trace_msg(
           0x35u,
           8u,
           "%s: Clearing Immed Blk Ack:no AP support",
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           "lim_update_caps_info_for_bss");
}
