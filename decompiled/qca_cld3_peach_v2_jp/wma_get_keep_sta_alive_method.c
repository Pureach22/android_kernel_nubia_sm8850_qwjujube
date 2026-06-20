__int64 __fastcall wma_get_keep_sta_alive_method(__int64 a1, int *a2)
{
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  int v12; // w8
  __int64 v13; // x21
  int v14; // w9
  unsigned int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  result = ucfg_mlme_get_sta_keepalive_method(a1, &v15);
  if ( (_DWORD)result )
  {
    result = qdf_trace_msg(
               0x36u,
               2u,
               "%s: Failed to get ini config for keep sta alive method",
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               "wma_get_keep_sta_alive_method");
    v12 = 1;
  }
  else
  {
    v13 = jiffies;
    if ( wma_get_keep_sta_alive_method___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x36u,
                 8u,
                 "%s: ini_val: %u",
                 v4,
                 v5,
                 v6,
                 v7,
                 v8,
                 v9,
                 v10,
                 v11,
                 "wma_get_keep_sta_alive_method",
                 v15);
      wma_get_keep_sta_alive_method___last_ticks = v13;
    }
    if ( v15 == 3 )
      v14 = 2;
    else
      v14 = 1;
    if ( v15 == 2 )
      v12 = 4;
    else
      v12 = v14;
  }
  *a2 = v12;
  _ReadStatusReg(SP_EL0);
  return result;
}
