__int64 __fastcall hdd_send_coex_traffic_shaping_mode(unsigned __int8 a1, unsigned __int8 a2)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x20
  _DWORD v12[3]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v13; // [xsp+14h] [xbp-1Ch]
  __int64 v14; // [xsp+1Ch] [xbp-14h]
  int v15; // [xsp+24h] [xbp-Ch]
  __int64 v16; // [xsp+28h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12[1] = 50;
  v12[2] = a2;
  v15 = 0;
  v14 = 0;
  v13 = 0;
  v12[0] = a1;
  result = sme_send_coex_config_cmd(v12);
  if ( (_DWORD)result )
  {
    v11 = jiffies;
    if ( hdd_send_coex_traffic_shaping_mode___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to send coex traffic shaping mode",
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        "hdd_send_coex_traffic_shaping_mode");
      hdd_send_coex_traffic_shaping_mode___last_ticks = v11;
    }
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
