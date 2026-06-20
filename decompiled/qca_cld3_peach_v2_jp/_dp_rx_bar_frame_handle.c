__int64 __fastcall dp_rx_bar_frame_handle(__int64 a1, __int64 a2, unsigned int a3, unsigned __int8 a4, unsigned int a5)
{
  __int64 (*v6)(void); // x8
  unsigned int v11; // w0
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x26
  __int64 v22; // x6
  __int64 v23; // x23
  __int64 v24; // x22
  __int64 v25; // x23

  v6 = *(__int64 (**)(void))(a1 + 1432);
  if ( *((_DWORD *)v6 - 1) != 1020823628 )
    __break(0x8228u);
  v11 = v6();
  result = dp_peer_get_ref_by_id_2(a1, v11);
  if ( result )
  {
    v21 = jiffies;
    if ( dp_rx_bar_frame_handle___last_ticks - jiffies + 125 < 0 )
    {
      v22 = *(unsigned __int16 *)(a2 + 2);
      v23 = result;
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: BAR frame:  peer_id = %d tid = %u SSN = %d error status = %d",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "_dp_rx_bar_frame_handle",
        *(unsigned __int16 *)(result + 16),
        a3,
        v22,
        a4);
      result = v23;
      dp_rx_bar_frame_handle___last_ticks = v21;
      if ( !a4 )
      {
LABEL_8:
        if ( a5 == 8 || a5 == 6 )
        {
          v24 = jiffies;
          if ( dp_rx_err_handle_bar___last_ticks - jiffies + 125 < 0 )
          {
            v25 = result;
            qdf_trace_msg(
              0x45u,
              5u,
              "%s: BAR update to H.W is skipped",
              v13,
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              "dp_rx_err_handle_bar");
            result = v25;
            dp_rx_err_handle_bar___last_ticks = v24;
          }
          if ( a1 )
          {
            ++*(_DWORD *)(a1 + 14124);
            ++*(_DWORD *)(a1 + 4LL * a5 + 13908);
          }
        }
        else if ( a1 )
        {
          ++*(_DWORD *)(a1 + 13648);
        }
      }
    }
    else if ( !a4 )
    {
      goto LABEL_8;
    }
    return dp_peer_unref_delete(result, 4u, v13, v14, v15, v16, v17, v18, v19, v20);
  }
  return result;
}
