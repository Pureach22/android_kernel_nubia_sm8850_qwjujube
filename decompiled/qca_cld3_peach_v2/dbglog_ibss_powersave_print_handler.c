__int64 __fastcall dbglog_ibss_powersave_print_handler(
        __int64 a1,
        __int64 a2,
        int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int *a6)
{
  unsigned int v6; // w8
  __int64 v7; // x0
  __int64 v8; // x2
  unsigned int *v9; // x3
  const char *v10; // x4
  char **v11; // x5
  __int64 v12; // x6
  __int64 result; // x0
  unsigned int v14; // w8
  unsigned int v15; // w8
  unsigned int v16; // w8
  const char *v17; // x2
  unsigned int v18; // w8

  switch ( a3 )
  {
    case 1:
      if ( (unsigned __int16)a5 == 1 )
      {
        dbglog_printf(a4, a2, "IBSS PS: create peer ID=%u", *a6);
      }
      else if ( (unsigned __int16)a5 == 2 )
      {
        dbglog_printf(a4, a2, "IBSS PS: peer alloc failed for peer ID:%u", *a6);
      }
      return 1;
    case 2:
      if ( (unsigned __int16)a5 == 4 )
        dbglog_printf(
          a4,
          a2,
          "IBSS PS: delete peer ID=%u num_peers:%d num_sleeping_peers:%d ps_enabled_for_this_peer:%d",
          *a6,
          a6[1],
          a6[2],
          a6[3]);
      return 1;
    case 3:
      if ( (_WORD)a5 )
      {
        if ( (unsigned __int16)a5 == 1 )
          dbglog_printf(a4, a2, "IBSS PS: vdev alloc failed", *a6);
      }
      else
      {
        dbglog_printf(a4, a2, "IBSS PS: vdev created");
      }
      return 1;
    case 4:
      dbglog_printf(a4, a2, "IBSS PS: vdev deleted");
      return 1;
    case 5:
      if ( (unsigned __int16)a5 == 1 )
      {
        v14 = *a6;
        if ( *a6 == 7 )
        {
          dbglog_printf(a4, a2, "IBSS PS: vdev event for peer delete");
        }
        else if ( v14 == 5 )
        {
          dbglog_printf(a4, a2, "IBSS PS: vdev event for peer add");
        }
        else
        {
          dbglog_printf(a4, a2, "IBSS PS: vdev event %u", v14);
        }
      }
      return 1;
    case 6:
      if ( (unsigned __int16)a5 != 4 )
        return 1;
      v15 = *a6;
      result = 1;
      if ( (int)*a6 <= 63 )
      {
        if ( v15 == 4 )
        {
          v16 = a6[1];
          v17 = "IBSS PS: hw_q_empty for peer:%u peer_type:%u sm_event_mask:%0x";
        }
        else
        {
          if ( v15 != 16 )
            return result;
          v16 = a6[1];
          v17 = "IBSS PS: send_n_complete for peer:%u peer_type:%u sm_event_mask:%0x";
        }
      }
      else
      {
        switch ( v15 )
        {
          case 0x40u:
            v16 = a6[1];
            v17 = "IBSS PS: rx event for peer:%u peer_type:%u sm_event_mask:%0x";
            break;
          case 0x20000u:
            v16 = a6[1];
            v17 = "IBSS PS: send_complete for peer:%u peer_type:%u sm_event_mask:%0x";
            break;
          case 0xFFFFu:
            v16 = a6[1];
            v17 = "IBSS PS: pre_send for peer:%u peer_type:%u sm_event_mask:%0x";
            break;
          default:
            return result;
        }
      }
      dbglog_printf(a4, a2, v17, v16, a6[3], a6[2]);
      return 1;
    case 7:
      if ( (unsigned __int16)a5 == 4 )
        dbglog_printf(
          a4,
          a2,
          "IBSS PS: Deliver CAB n_mpdu:%d send_flags:%0x tid_cur:%d q_depth_for_other_tid:%d",
          *a6,
          a6[1],
          a6[2],
          a6[3]);
      return 1;
    case 8:
      if ( (unsigned __int16)a5 == 4 )
        dbglog_printf(
          a4,
          a2,
          "IBSS PS: Deliver UC data peer:%d tid:%d n_mpdu:%d send_flags:%0x",
          *a6,
          a6[1],
          a6[2],
          a6[3]);
      return 1;
    case 9:
      if ( (unsigned __int16)a5 == 4 )
        dbglog_printf(
          a4,
          a2,
          "IBSS PS: Deliver UC data error peer:%d tid:%d allowed_tidmask:%0x, pending_tidmap:%0x",
          *a6,
          a6[1],
          a6[2],
          a6[3]);
      return 1;
    case 10:
      if ( (unsigned __int16)a5 == 2 )
        dbglog_printf(a4, a2, "IBSS PS: UC timer restart peer:%d timer_val:%0x", *a6, a6[1]);
      return 1;
    case 11:
      if ( (unsigned __int16)a5 == 1 )
        dbglog_printf(a4, a2, "IBSS PS: MC timer restart timer_val:%0x", *a6);
      return 1;
    case 12:
      if ( (unsigned __int16)a5 == 3 )
        dbglog_printf(
          a4,
          a2,
          "IBSS PS: null tx completion peer:%d tx_completion_status:%d flags:%0x",
          *a6,
          a6[1],
          a6[2]);
      return 1;
    case 13:
      if ( (unsigned __int16)a5 == 4 )
        dbglog_printf(a4, a2, "IBSS PS: ATIM timer start tsf:%0x %0x tbtt:%0x %0x", *a6, a6[1], a6[2], a6[3]);
      return 1;
    case 14:
      if ( (unsigned __int16)a5 == 1 )
      {
        dbglog_printf(a4, a2, "IBSS PS: no peers to send UC ATIM", a6[1]);
      }
      else if ( (unsigned __int16)a5 == 2 )
      {
        dbglog_printf(a4, a2, "IBSS PS: Send ATIM to peer:%d", a6[1]);
      }
      return 1;
    case 15:
      if ( (unsigned __int16)a5 == 2 )
        dbglog_printf(a4, a2, "IBSS PS: MC Data, num_of_peers:%d bc_atim_sent:%d", a6[1], *a6);
      return 1;
    case 16:
      if ( (unsigned __int16)a5 == 2 )
        dbglog_printf(a4, a2, "IBSS PS: UC timeout for peer:%d send_null:%d", *a6, a6[1]);
      return 1;
    case 17:
      dbglog_printf(a4, a2, "IBSS PS: allow power collapse");
      return 1;
    case 18:
      result = 1;
      if ( (unsigned __int16)a5 <= 1u )
      {
        if ( (_WORD)a5 )
        {
          if ( (unsigned __int16)a5 != 1 )
            return result;
          dbglog_printf(a4, a2, "IBSS PS: power collapse not allowed since peer id:%d is not PS capable", *a6);
        }
        else
        {
          dbglog_printf(a4, a2, "IBSS PS: power collapse not allowed by INI");
        }
      }
      else
      {
        switch ( (unsigned __int16)a5 )
        {
          case 2u:
            dbglog_printf(a4, a2, "IBSS PS: power collapse not allowed - no peers in NW");
            return 1;
          case 3u:
            if ( *a6 == 3 )
            {
              dbglog_printf(a4, a2, "IBSS PS: power collapse not allowed by peer:%d peer_flags:%0x", a6[1], a6[2]);
            }
            else
            {
              if ( *a6 != 2 )
                return result;
              dbglog_printf(a4, a2, "IBSS PS: power collapse not allowed, non-zero qdepth %d %d", a6[1], a6[2]);
            }
            break;
          case 5u:
            dbglog_printf(
              a4,
              a2,
              "IBSS PS: power collapse not allowed by state m/c nw_cur_state:%d nw_next_state:%d ps_cur_state:%d flags:%0x",
              a6[1],
              a6[2],
              a6[3],
              a6[4]);
            break;
          default:
            return result;
        }
      }
      return 1;
    case 19:
      if ( (unsigned __int16)a5 == 2 )
        dbglog_printf(a4, a2, "IBSS PS: Set Param ID:%0x Value:%0x", *a6, a6[1]);
      return 1;
    case 20:
      if ( (unsigned __int16)a5 == 1 )
        dbglog_printf(a4, a2, "IBSS PS: Pausing host, vdev_map:%0x", *a6);
      return 1;
    case 21:
      if ( (unsigned __int16)a5 == 1 )
        dbglog_printf(a4, a2, "IBSS PS: Unpausing host, vdev_map:%0x", *a6);
      return 1;
    case 22:
      if ( (unsigned __int16)a5 == 1 )
        dbglog_printf(a4, a2, "IBSS PS: HWM, vdev_map:%0x", *a6);
      return 1;
    case 23:
      if ( (unsigned __int16)a5 == 1 )
        dbglog_printf(a4, a2, "IBSS PS: LWM, vdev_map:%0x", *a6);
      return 1;
    case 24:
      if ( (unsigned __int16)a5 == 3 )
        dbglog_printf(a4, a2, "IBSS PS: Kickout peer id:%d atim_fail_cnt:%d status:%d", *a6, a6[1], a6[2]);
      return 1;
    case 25:
      if ( (unsigned __int16)a5 == 3 )
        dbglog_printf(a4, a2, "IBSS PS: Set Peer Id:%d Param ID:%0x Value:%0x", *a6, a6[1], a6[2]);
      return 1;
    case 26:
      if ( (unsigned __int16)a5 == 4 )
      {
        if ( *a6 == 48879 )
        {
          dbglog_printf(
            a4,
            a2,
            "IBSS PS: Peer ATIM window length changed, peer id:%d, peer recorded atim window:%d new atim window:%d",
            a6[1],
            a6[2],
            a6[3]);
        }
        else if ( *a6 == 57005 )
        {
          dbglog_printf(
            a4,
            a2,
            "IBSS PS: ATIM window length mismatch, our's:%d, peer id:%d, peer's:%d",
            a6[1],
            a6[2],
            a6[3]);
        }
      }
      return 1;
    case 27:
      if ( (unsigned __int16)a5 == 2 )
      {
        v18 = *a6;
        if ( a6[1] == 1 )
          dbglog_printf(a4, a2, "IBSS PS: Voting for low power chainmask from :%d", v18);
        else
          dbglog_printf(a4, a2, "IBSS PS: Voting for high power chainmask from :%d", v18);
      }
      return 1;
    default:
      if ( a3 != 1000 )
        return 0;
      v6 = a6[1] >> 30;
      if ( v6 == 2 )
      {
        v7 = a4;
        v8 = a5;
        v9 = a6;
        v10 = "IBSS PS Peer";
        v11 = dbglog_ibss_powersave_print_handler_peer_ps_states;
        v12 = 4;
      }
      else if ( v6 == 1 )
      {
        v7 = a4;
        v8 = a5;
        v9 = a6;
        v10 = "IBSS PS Self";
        v11 = dbglog_ibss_powersave_print_handler_ps_states;
        v12 = 8;
      }
      else
      {
        if ( v6 )
          return 1;
        v7 = a4;
        v8 = a5;
        v9 = a6;
        v10 = "IBSS PS NW";
        v11 = dbglog_ibss_powersave_print_handler_nw_states;
        v12 = 6;
      }
      dbglog_sm_print(v7, a2, v8, v9, v10, v11, v12, dbglog_ibss_powersave_print_handler_events, 23);
      return 1;
  }
}
