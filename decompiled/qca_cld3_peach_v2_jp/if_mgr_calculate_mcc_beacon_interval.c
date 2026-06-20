__int64 __fastcall if_mgr_calculate_mcc_beacon_interval(
        unsigned __int16 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int16 v10; // w20
  unsigned int v11; // w19
  __int16 v12; // w8
  bool v13; // zf

  v10 = a1;
  v11 = 100;
  if ( (unsigned __int16)a2 >= 0x64u )
    v11 = a2 - 100 * ((unsigned __int16)a2 / 0x64u) + 100;
  if ( a1 )
  {
    if ( (unsigned __int16)v11 < (unsigned int)a1 )
    {
      v12 = a1 % (unsigned __int16)v11;
      goto LABEL_8;
    }
  }
  else
  {
    v10 = 100;
    qdf_trace_msg(
      0x78u,
      3u,
      "%s: sta_bi 2nd parameter is zero, initialize to %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "if_mgr_calculate_mcc_beacon_interval",
      100);
  }
  v12 = (unsigned __int8)v11 % (unsigned __int8)v10;
LABEL_8:
  if ( v12 )
    v13 = (unsigned __int8)(v10 / 0x64u) == 0;
  else
    v13 = 1;
  if ( !v13 )
    return v10 / (unsigned int)(unsigned __int8)(v10 / 0x64u);
  return v11;
}
