__int64 __fastcall policy_mgr_init_chan_avoidance(__int64 a1, __int64 a2, unsigned __int16 a3)
{
  __int64 context; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int16 v14; // w4
  __int64 v15; // x8

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    if ( a3 >= 0x66u )
      v14 = 102;
    else
      v14 = a3;
    *(_WORD *)(context + 2084) = v14;
    if ( a3 )
    {
      v15 = 0;
      while ( v15 != 102 )
      {
        *(_DWORD *)(context + 1676 + 4 * v15) = *(_DWORD *)(a2 + 4 * v15);
        if ( ++v15 >= (unsigned __int64)*(unsigned __int16 *)(context + 2084) )
          goto LABEL_9;
      }
      __break(0x5512u);
      return policy_mgr_update_with_safe_channel_list();
    }
    else
    {
LABEL_9:
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: Channel list init, received %d avoided channels",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "policy_mgr_init_chan_avoidance");
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "policy_mgr_init_chan_avoidance");
    return 16;
  }
}
