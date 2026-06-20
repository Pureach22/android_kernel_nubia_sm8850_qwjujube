__int64 __fastcall hdd_change_peer_state(
        unsigned __int8 *a1,
        __int64 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x24
  __int64 *v14; // x21
  _QWORD *context; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x8
  unsigned int (*v26)(void); // x8
  _QWORD *v27; // x22
  bool is_roam_sync_in_progress; // w8
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 result; // x0
  const char *v38; // x2
  __int64 v39; // x8
  _DWORD *v40; // x8
  __int64 v41; // x1

  v11 = *(_QWORD *)a1;
  v14 = *(__int64 **)(*(_QWORD *)a1 + 24LL);
  context = _cds_get_context(71, (__int64)"hdd_change_peer_state", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !context || !*context || (v25 = *(_QWORD *)(*context + 72LL)) == 0 )
  {
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", v17, v18, v19, v20, v21, v22, v23, v24, "cdp_peer_state_update");
LABEL_13:
    v38 = "%s: peer state update failed";
    goto LABEL_14;
  }
  v26 = *(unsigned int (**)(void))(v25 + 40);
  if ( !v26 )
    goto LABEL_13;
  v27 = context;
  if ( *((_DWORD *)v26 - 1) != 1499005600 )
    __break(0x8228u);
  if ( v26() )
    goto LABEL_13;
  is_roam_sync_in_progress = wlan_cm_is_roam_sync_in_progress(*v14, a1[8]);
  result = 0;
  if ( a3 == 3 && !is_roam_sync_in_progress )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Reset scan reject params",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "hdd_change_peer_state");
    hdd_init_scan_reject_params(v14);
    if ( (unsigned int)sme_set_peer_authorized(a2, a1[8]) )
    {
      v38 = "%s: Failed to set the peer state to authorized";
LABEL_14:
      qdf_trace_msg(0x33u, 2u, v38, v17, v18, v19, v20, v21, v22, v23, v24, "hdd_change_peer_state");
      return 5;
    }
    if ( (*(_DWORD *)(v11 + 40) | 2) == 2 )
    {
      if ( *v27 )
      {
        v39 = *(_QWORD *)(*v27 + 120LL);
        if ( v39 )
        {
          v40 = *(_DWORD **)(v39 + 56);
          if ( v40 )
          {
            v41 = a1[8];
            if ( *(v40 - 1) != 875705606 )
              __break(0x8228u);
            ((void (__fastcall *)(_QWORD *, __int64, __int64, _QWORD))v40)(v27, v41, 2, 0);
          }
        }
      }
      else
      {
        qdf_trace_msg(0x89u, 8u, "%s: invalid instance", v17, v18, v19, v20, v21, v22, v23, v24, "cdp_fc_vdev_unpause");
      }
    }
    return 0;
  }
  return result;
}
