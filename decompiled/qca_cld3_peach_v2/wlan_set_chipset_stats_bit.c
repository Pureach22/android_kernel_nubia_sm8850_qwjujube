__int64 __fastcall wlan_set_chipset_stats_bit(
        __int64 result,
        char a2,
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
  unsigned __int64 v24; // x9
  unsigned __int64 v27; // x9

  _ReadStatusReg(SP_EL0);
  if ( (result & 1) != 0 )
  {
    if ( a2 )
    {
      result = qdf_trace_msg(
                 0x38u,
                 8u,
                 "%s: setting chipset stats event flags",
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 "wlan_set_chipset_stats_bit");
      byte_826C82 = 1;
      _X8 = &qword_826C78;
      __asm { PRFM            #0x11, [X8] }
      do
        v24 = __ldxr((unsigned __int64 *)&qword_826C78);
      while ( __stxr(v24 | 0x20, (unsigned __int64 *)&qword_826C78) );
      _X8 = &qword_826C78;
      __asm { PRFM            #0x11, [X8] }
      do
        v27 = __ldxr((unsigned __int64 *)&qword_826C78);
      while ( __stxr(v27 | 0x40, (unsigned __int64 *)&qword_826C78) );
    }
  }
  else
  {
    result = qdf_get_dump_inprogress(a3, a4, a5, a6, a7, a8, a9, a10);
    if ( (_DWORD)result )
      result = qdf_trace_msg(
                 0x38u,
                 2u,
                 "%s: Failed to get dump_inprogress from cnss",
                 v10,
                 v11,
                 v12,
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 "wlan_set_chipset_stats_bit");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
