__int64 __fastcall lim_send_dfs_chan_sw_ie_update(__int64 a1, __int64 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  if ( (unsigned int)sch_set_fixed_beacon_fields(a1, a2) )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: Unable to set CSA IE in beacon",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "lim_send_dfs_chan_sw_ie_update");
  lim_send_beacon_ind(a1, a2, 5u, v4, v5, v6, v7, v8, v9, v10, v11);
  return qdf_trace_msg(
           0x35u,
           8u,
           "%s: Updated CSA IE, IE COUNT: %d",
           v13,
           v14,
           v15,
           v16,
           v17,
           v18,
           v19,
           v20,
           "lim_send_dfs_chan_sw_ie_update",
           (unsigned int)*(char *)(a2 + 7218));
}
