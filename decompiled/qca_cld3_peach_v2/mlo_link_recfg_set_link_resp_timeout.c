__int64 __fastcall mlo_link_recfg_set_link_resp_timeout(
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
  __int64 v9; // x21
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 *v19; // x20
  __int64 v20; // x21
  _DWORD *v21; // x8
  __int64 v22; // x1
  double v23; // d0
  unsigned int *v24; // x8
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  v9 = *(_QWORD *)(a1 + 3888);
  if ( !v9 )
    return qdf_trace_msg(
             0x8Fu,
             2u,
             "%s: invalid recfg_ctx",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "mlo_link_recfg_set_link_resp_timeout");
  qdf_mutex_acquire(a1 + 1656);
  v19 = *(__int64 **)(v9 + 3200);
  if ( v19 )
  {
    *(_QWORD *)(v9 + 3200) = 0;
    v20 = *v19;
    qdf_mutex_release(a1 + 1656);
    v21 = (_DWORD *)v19[1];
    v22 = v19[3];
    if ( *(v21 - 1) != 662908326 )
      __break(0x8228u);
    v23 = ((double (__fastcall *)(__int64, __int64, _QWORD))v21)(v20, v22, 0);
    wlan_objmgr_vdev_release_ref(v20, 0x5Au, v24, v23, v25, v26, v27, v28, v29, v30, v31);
    return _qdf_mem_free((__int64)v19);
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: no pending set link for link recfg",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "mlo_link_recfg_set_link_resp_timeout");
    return qdf_mutex_release(a1 + 1656);
  }
}
