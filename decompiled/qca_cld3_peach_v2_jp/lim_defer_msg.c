__int64 __fastcall lim_defer_msg(__int64 a1, unsigned __int16 *a2)
{
  unsigned __int8 v4; // w20
  __int64 v5; // x24
  unsigned int v6; // w22
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // w8

  v4 = ((__int64 (*)(void))lim_write_deferred_msg_q)();
  if ( v4 )
  {
    v5 = jiffies;
    if ( lim_defer_msg___last_ticks - jiffies + 125 < 0 )
    {
      v6 = *a2;
      v7 = lim_msg_str(*a2);
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Dropped lim message (0x%X) Message %s",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "lim_defer_msg",
        v6,
        v7);
      lim_defer_msg___last_ticks = v5;
    }
    v16 = 0x80000000;
  }
  else
  {
    v16 = 0x40000000;
  }
  mac_trace_msg_rx(a1, 255, v16 | *a2);
  return v4;
}
