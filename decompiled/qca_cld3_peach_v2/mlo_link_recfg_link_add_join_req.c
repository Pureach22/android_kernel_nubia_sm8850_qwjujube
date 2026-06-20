__int64 __fastcall mlo_link_recfg_link_add_join_req(
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
  __int64 v9; // x20
  __int64 v10; // x21
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x8
  unsigned int *v29; // x22
  __int64 v30; // x9
  unsigned int v31; // w0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x4
  __int64 v41; // x5
  unsigned int v42; // w19
  const char *v43; // x2

  v9 = *(_QWORD *)(a1 + 1360);
  if ( v9 )
  {
    v10 = *(_QWORD *)(v9 + 3888);
    if ( v10 )
    {
      qdf_mutex_acquire(v10 + 760);
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: vdev %d recfg_type %d join_pending_vdev_id %d",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "mlo_link_recfg_link_add_join_req",
        *(unsigned __int8 *)(a1 + 168),
        *(unsigned int *)(v10 + 284),
        *(unsigned __int8 *)(v10 + 288));
      if ( *(_DWORD *)(v10 + 284) == 4 )
      {
        if ( (unsigned int)*(char *)(v10 + 3024) >= 7 )
        {
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: unexpected curr_state_idx %d",
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            "mlo_link_recfg_get_curr_tran_req");
        }
        else
        {
          v28 = v10 + 312LL * *(char *)(v10 + 3024);
          v29 = (unsigned int *)(v28 + 840);
          if ( v28 != -840 )
          {
            v30 = *(_QWORD *)(v10 + 8);
            *(_BYTE *)(v10 + 288) = *(_BYTE *)(a1 + 168);
            v31 = wlan_sm_dispatch(
                    *(_QWORD *)(*(_QWORD *)(v30 + 3888) + 824LL),
                    6u,
                    0x108u,
                    v28 + 848,
                    v20,
                    v21,
                    v22,
                    v23,
                    v24,
                    v25,
                    v26,
                    v27);
            if ( v31 )
            {
              v40 = *v29;
              v41 = v29[1];
              v42 = v31;
              *(_BYTE *)(v10 + 288) = -1;
              qdf_trace_msg(
                0x8Fu,
                2u,
                "%s: state %d event %d status %d",
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                v39,
                "mlo_link_recfg_link_add_join_req",
                v40,
                v41,
                v31);
            }
            else
            {
              v42 = 24;
            }
            goto LABEL_14;
          }
        }
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: curr tran ctx null",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "mlo_link_recfg_link_add_join_req");
        v42 = 4;
      }
      else
      {
        v42 = 0;
      }
LABEL_14:
      qdf_mutex_release(*(_QWORD *)(v9 + 3888) + 760LL);
      return v42;
    }
    v43 = "%s: invalid recfg_ctx";
  }
  else
  {
    v43 = "%s: invalid mlo_dev_ctx";
  }
  qdf_trace_msg(0x8Fu, 2u, v43, a2, a3, a4, a5, a6, a7, a8, a9, "mlo_link_recfg_link_add_join_req");
  return 4;
}
