__int64 __fastcall lim_stop_tx_and_switch_channel(__int64 a1, __int64 a2)
{
  unsigned __int8 v2; // w20
  __int64 session_by_session_id; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v14; // x20
  int v15; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  v2 = a2;
  session_by_session_id = pe_find_session_by_session_id(a1, a2);
  if ( !session_by_session_id )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Session: %d not active",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "lim_stop_tx_and_switch_channel",
      v2);
    return 4;
  }
  if ( *(_QWORD *)(session_by_session_id + 7432) )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Avoid Switch Channel req during pre auth",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "lim_stop_tx_and_switch_channel");
    return 4;
  }
  v14 = session_by_session_id;
  v15 = policy_mgr_check_and_set_hw_mode_for_channel_switch(
          *(_QWORD *)(a1 + 21624),
          *(_BYTE *)(session_by_session_id + 10),
          *(_DWORD *)(session_by_session_id + 7204),
          7u);
  if ( v15 )
  {
    if ( v15 == 16 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to set required HW mode for channel %d freq %d, ignore CSA",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "lim_stop_tx_and_switch_channel",
        *(unsigned __int8 *)(v14 + 7208),
        *(unsigned int *)(v14 + 7204));
      return 16;
    }
    else
    {
      return lim_process_channel_switch(a1, *(unsigned __int8 *)(v14 + 10));
    }
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      4u,
      "%s: Channel change will continue after HW mode change",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "lim_stop_tx_and_switch_channel");
    return 0;
  }
}
