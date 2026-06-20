__int64 __fastcall lim_handle_heart_beat_failure(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x21
  __int64 result; // x0
  __int64 (__fastcall *v15)(__int64, __int64, __int64, __int64); // x8
  __int64 v16; // x0
  __int64 v17; // x1

  v4 = _qdf_mem_malloc(0x10u, "lim_handle_heart_beat_failure", 512);
  if ( v4 )
  {
    v13 = v4;
    host_diag_log_set_code(v4, 5275);
    host_diag_log_set_length(v13, 16);
    *(_DWORD *)(v13 + 12) = *(unsigned __int8 *)(a2 + 292);
    host_diag_log_submit(v13);
    _qdf_mem_free(v13);
  }
  if ( *(_DWORD *)(a2 + 88) != 2
    || (result = lim_is_sb_disconnect_allowed_fl(a2, (__int64)"lim_handle_heart_beat_failure", 0x207u), (result & 1) == 0) )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: received heartbeat timeout in state %X",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "lim_handle_heart_beat_failure",
      *(unsigned int *)(a2 + 72));
    result = lim_print_mlm_state(a1, 4, *(unsigned int *)(a2 + 72));
    ++*(_BYTE *)(a1 + 4011);
LABEL_10:
    v15 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 14480);
    if ( !v15 )
      return result;
    goto LABEL_11;
  }
  if ( !*(_DWORD *)(a1 + 12808) )
    goto LABEL_10;
  if ( *(_DWORD *)(a2 + 7196) == 1 )
  {
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: Ignore Heartbeat failure as Channel switch is in progress",
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               "lim_handle_heart_beat_failure");
    *(_BYTE *)(a2 + 7279) = 0;
    v15 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 14480);
    if ( !v15 )
      return result;
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: Heartbeat Failure",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "lim_handle_heart_beat_failure");
    ++*(_BYTE *)(a1 + 4009);
    lim_send_deauth_mgmt_frame(a1, 4, a2 + 24, a2, 0);
    result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64))lim_tear_down_link_with_ap)(
               a1,
               *(unsigned __int8 *)(a2 + 8),
               65533,
               6);
    v15 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 14480);
    if ( !v15 )
      return result;
  }
LABEL_11:
  v16 = *(_QWORD *)(a1 + 12832);
  v17 = *(unsigned __int8 *)(a2 + 10);
  if ( *((_DWORD *)v15 - 1) != 2083539300 )
    __break(0x8228u);
  return v15(v16, v17, 3, 1);
}
