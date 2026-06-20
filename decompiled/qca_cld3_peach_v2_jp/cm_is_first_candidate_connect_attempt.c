bool __fastcall cm_is_first_candidate_connect_attempt(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 cmpt_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19
  __int64 req_by_cm_id_fl; // x0
  _BOOL4 v21; // w20
  __int64 v22; // x20

  if ( !a1 )
  {
    v22 = jiffies;
    if ( cm_get_cm_ctx_fl___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s:%u: vdev is NULL",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "cm_is_first_candidate_connect_attempt",
        1657);
      cm_get_cm_ctx_fl___last_ticks = v22;
      return 0;
    }
    return 0;
  }
  if ( (*(_DWORD *)(a1 + 16) & 0xFFFFFFFD) != 0 )
    return 0;
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1);
  if ( cmpt_obj && (v19 = *(_QWORD *)(cmpt_obj + 496)) != 0 )
  {
    qdf_mutex_acquire(v19 + 120);
    req_by_cm_id_fl = cm_get_req_by_cm_id_fl(
                        v19,
                        *(_DWORD *)(v19 + 88),
                        (__int64)"cm_is_first_candidate_connect_attempt",
                        0x67Eu);
    v21 = req_by_cm_id_fl && !*(_BYTE *)(req_by_cm_id_fl + 872) && *(unsigned __int8 *)(req_by_cm_id_fl + 873) < 2u;
    qdf_mutex_release(v19 + 120);
    return v21;
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s:%u: vdev %d cm_ctx is NULL",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "cm_is_first_candidate_connect_attempt",
      1657,
      *(unsigned __int8 *)(a1 + 104));
    return 0;
  }
}
