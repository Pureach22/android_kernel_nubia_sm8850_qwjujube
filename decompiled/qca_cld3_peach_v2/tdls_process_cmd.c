__int64 __fastcall tdls_process_cmd(
        unsigned __int16 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  const char *v10; // x4
  const char *v11; // x4
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  if ( !a1 )
  {
    v11 = (const char *)&unk_98C763;
LABEL_7:
    qdf_trace_msg(0, 2u, "%s: msg %s is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "tdls_process_cmd", v11);
    return 29;
  }
  if ( !*((_QWORD *)a1 + 1) )
  {
    v11 = "body ptr";
    goto LABEL_7;
  }
  if ( (unsigned int)*a1 - 1 > 0x19 )
    v10 = "Invalid TDLS command";
  else
    v10 = off_B2DDB0[(unsigned __int16)(*a1 - 1)];
  qdf_trace_msg(0, 8u, "%s:  %s(%d)", a2, a3, a4, a5, a6, a7, a8, a9, "tdls_process_cmd", v10);
  result = 0;
  switch ( *a1 )
  {
    case 1u:
      tdls_process_mgmt_req(*((_QWORD *)a1 + 1));
      goto LABEL_34;
    case 2u:
      tdls_process_add_peer(*((__int64 **)a1 + 1), v13, v14, v15, v16, v17, v18, v19, v20);
      goto LABEL_34;
    case 3u:
      tdls_process_update_peer(*((__int64 **)a1 + 1), v13, v14, v15, v16, v17, v18, v19, v20);
      goto LABEL_34;
    case 4u:
      tdls_process_enable_link(*((_QWORD *)a1 + 1), v13, v14, v15, v16, v17, v18, v19, v20);
      goto LABEL_34;
    case 5u:
      tdls_process_del_peer(*((_QWORD *)a1 + 1), v13, v14, v15, v16, v17, v18, v19, v20);
      goto LABEL_34;
    case 6u:
      tdls_process_setup_peer(*((_QWORD *)a1 + 1), v13, v14, v15, v16, v17, v18, v19, v20);
      goto LABEL_34;
    case 7u:
      tdls_process_remove_force_peer(*((_QWORD *)a1 + 1), v13, v14, v15, v16, v17, v18, v19, v20);
      goto LABEL_34;
    case 0xAu:
      tdls_scan_done_callback(*((_QWORD *)a1 + 1));
      goto LABEL_34;
    case 0xBu:
      tdls_set_responder(*((_QWORD *)a1 + 1), v13, v14, v15, v16, v17, v18, v19, v20);
      goto LABEL_34;
    case 0xCu:
      tdls_notify_sta_connect(*((_QWORD *)a1 + 1));
      goto LABEL_34;
    case 0xDu:
      tdls_notify_sta_disconnect(*((_QWORD *)a1 + 1));
      goto LABEL_34;
    case 0xEu:
      tdls_set_operation_mode(*((_QWORD *)a1 + 1));
      goto LABEL_34;
    case 0xFu:
      tdls_process_policy_mgr_notification(*((_QWORD *)a1 + 1));
      goto LABEL_34;
    case 0x10u:
      tdls_process_decrement_active_session(*((_QWORD *)a1 + 1));
      goto LABEL_34;
    case 0x11u:
      tdls_teardown_connections(*((__int64 **)a1 + 1));
      goto LABEL_34;
    case 0x12u:
      tdls_notify_reset_adapter(*((_QWORD *)a1 + 1));
      goto LABEL_34;
    case 0x13u:
      tdls_get_all_peers_from_list(*((_QWORD *)a1 + 1));
      goto LABEL_34;
    case 0x14u:
      tdls_process_antenna_switch(*((_QWORD *)a1 + 1), v13, v14, v15, v16, v17, v18, v19, v20);
      goto LABEL_34;
    case 0x15u:
      tdls_process_set_offchannel(*((_QWORD *)a1 + 1));
      goto LABEL_34;
    case 0x16u:
      tdls_process_set_offchan_mode(*((_QWORD **)a1 + 1), v13, v14, v15, v16, v17, v18, v19, v20);
      goto LABEL_34;
    case 0x17u:
      tdls_process_set_secoffchanneloffset(*((_QWORD *)a1 + 1));
      goto LABEL_34;
    case 0x18u:
      tdls_reset_all_peers(*((_QWORD *)a1 + 1));
      goto LABEL_34;
    case 0x19u:
      tdls_handle_start_bss(*((_QWORD *)a1 + 1));
      goto LABEL_34;
    case 0x1Au:
      tdls_handle_link_unforce(*((_QWORD *)a1 + 1));
LABEL_34:
      result = 0;
      break;
    default:
      return result;
  }
  return result;
}
