__int64 __fastcall mlo_mgr_link_switch_defer_disconnect_req(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x22
  unsigned int v15; // w23
  __int64 v16; // x23
  __int64 v17; // x22
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x8
  unsigned int v27; // w19
  _BYTE *v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7

  if ( a1
    && (v11 = *(_QWORD *)(a1 + 1360)) != 0
    && (qdf_mutex_acquire(v11 + 1656),
        v15 = *(_DWORD *)(*(_QWORD *)(v11 + 3880) + 164LL),
        qdf_mutex_release(v11 + 1656),
        v15 > 1) )
  {
    v16 = *(_QWORD *)(a1 + 1360);
    v17 = *(_QWORD *)(v16 + 2224);
    if ( v17 )
    {
      qdf_mutex_acquire(v16 + 1656);
      *(_DWORD *)(*(_QWORD *)(v16 + 3880) + 164LL) = 6;
      qdf_mutex_release(v16 + 1656);
      mlo_link_recfg_abort_if_in_progress(a1, 0);
      v26 = *(_QWORD *)(v17 + 280);
      if ( v26 )
      {
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: Pending disconnect from source %d, reason %d",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "mlo_mgr_link_switch_defer_disconnect_req",
          *(unsigned int *)(v26 + 4),
          *(unsigned int *)(v26 + 8));
        return 6;
      }
      else
      {
        v29 = (_BYTE *)_qdf_mem_malloc(0x14u, "mlo_mgr_link_switch_defer_disconnect_req", 2223);
        *(_QWORD *)(v17 + 280) = v29;
        if ( v29 )
        {
          *v29 = *(_BYTE *)(a1 + 168);
          *(_DWORD *)(*(_QWORD *)(v17 + 280) + 4LL) = a2;
          *(_DWORD *)(*(_QWORD *)(v17 + 280) + 8LL) = a3;
          qdf_trace_msg(
            0x8Fu,
            8u,
            "%s: Deferred disconnect source: %d, reason: %d",
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            "mlo_mgr_link_switch_defer_disconnect_req",
            a2,
            a3);
          return 0;
        }
        else
        {
          return 2;
        }
      }
    }
    else
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: sta ctx null",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "mlo_mgr_link_switch_defer_disconnect_req");
      return 29;
    }
  }
  else
  {
    v27 = 4;
    qdf_trace_msg(
      0x8Fu,
      4u,
      "%s: Link switch not in progress",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "mlo_mgr_link_switch_defer_disconnect_req");
  }
  return v27;
}
