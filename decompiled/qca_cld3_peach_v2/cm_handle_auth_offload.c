__int64 __fastcall cm_handle_auth_offload(
        unsigned __int8 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x1
  __int64 v20; // x2
  __int64 v21; // x3
  _QWORD *v22; // x21
  __int64 result; // x0
  const char *v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int updated; // w0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x20
  _DWORD *v43; // x10
  __int64 v44; // x3
  __int64 v45; // x1
  unsigned __int64 v46; // x2
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x20

  context = _cds_get_context(54, (__int64)"cm_handle_auth_offload", a2, a3, a4, a5, a6, a7, a8, a9);
  v22 = _cds_get_context(53, (__int64)"cm_handle_auth_offload", v11, v12, v13, v14, v15, v16, v17, v18);
  result = 16;
  if ( v22 && context )
  {
    cds_get_ring_log_level(0, v19, v20, v21);
    v24 = qdf_wake_lock_name((__int64)(context + 287));
    ((void (__fastcall *)(__int64, const char *, __int64, _QWORD))host_diag_log_wlock)(12, v24, 2000, 0);
    qdf_wake_lock_timeout_acquire((__int64)(context + 262), 500);
    lim_sae_auth_cleanup_retry((__int64)v22, *a1);
    wlan_cm_set_sae_auth_ta(
      v22[2704],
      *a1,
      *(unsigned int *)(a1 + 7) | ((unsigned __int64)*(unsigned __int16 *)(a1 + 11) << 32));
    wlan_cm_store_mlo_roam_peer_address(v22[2704], a1, v25, v26, v27, v28, v29, v30, v31, v32);
    updated = wlan_cm_update_offload_ssid_from_candidate(v22[2704], *a1, a1 + 1);
    if ( updated )
    {
      v42 = jiffies;
      if ( cm_handle_auth_offload___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: Set offload ssid failed %d",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "cm_handle_auth_offload",
          updated);
        cm_handle_auth_offload___last_ticks = v42;
      }
      return 16;
    }
    v43 = (_DWORD *)context[387];
    v44 = *((unsigned int *)a1 + 4);
    v45 = *a1;
    v46 = *(unsigned int *)(a1 + 1) | ((unsigned __int64)*(unsigned __int16 *)(a1 + 5) << 32);
    if ( *(v43 - 1) != 926488824 )
      __break(0x822Au);
    result = ((__int64 (__fastcall *)(_QWORD *, __int64, unsigned __int64, __int64))v43)(v22, v45, v46, v44);
    if ( (_DWORD)result )
    {
      v55 = jiffies;
      if ( cm_handle_auth_offload___last_ticks_4 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: Trigger pre-auth failed",
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          "cm_handle_auth_offload");
        cm_handle_auth_offload___last_ticks_4 = v55;
      }
      return 16;
    }
  }
  return result;
}
