__int64 __fastcall dp_wfds_new_server(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 v8; // x20
  __int64 *context; // x19
  __int64 result; // x0
  _QWORD *v11; // x21
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
  __int64 v28; // x0
  __int64 (__fastcall *v29)(_QWORD); // x8
  __int64 v30; // x0
  unsigned int v31; // w0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // w22
  __int64 v41; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  _QWORD *v50; // x19
  void (__fastcall *v51)(_QWORD); // x8
  __int64 v52; // x0

  v8 = gp_dl_wfds_ctx;
  context = _cds_get_context(62, (__int64)"dp_wfds_new_server", a1, a2, a3, a4, a5, a6, a7, a8);
  result = 4;
  if ( v8 && context )
  {
    v11 = **(_QWORD ***)v8;
    if ( (pld_audio_is_direct_link_supported(*(_QWORD *)(v11[2] + 40LL)) & 1) == 0 )
    {
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: Audio Direct link cap not supported",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "dp_wfds_new_server");
      return 11;
    }
    *(_DWORD *)(v8 + 104) = 1;
    htc_vote_link_up(context, 6);
    qdf_trace_msg(
      0x45u,
      8u,
      "%s: Connected to WFDS QMI service, state: 0x%x",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "dp_wfds_new_server",
      *(unsigned int *)(v8 + 104));
    if ( *v11 )
      v28 = *(_QWORD *)(*v11 + 2808LL);
    else
      v28 = 0;
    dp_rx_handle_buf_pool_audio_smmu_mapping(v28, *(_BYTE *)(v11[1] + 40LL), 1);
    v29 = (__int64 (__fastcall *)(_QWORD))v11[89];
    if ( !v29 )
      goto LABEL_12;
    v30 = *v11;
    if ( *((_DWORD *)v29 - 1) != -770124015 )
      __break(0x8228u);
    v31 = v29(v30);
    if ( v31 )
    {
      v40 = v31;
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: DP LPASS SSR notifier registration failed %d",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "dp_wfds_new_server");
    }
    else
    {
LABEL_12:
      v41 = _qdf_mem_malloc(0x20u, "dp_wfds_event_post", 440);
      if ( v41 )
      {
        *(_DWORD *)(v41 + 16) = 0;
        v50 = (_QWORD *)v41;
        *(_QWORD *)(v41 + 24) = 0;
        qdf_spinlock_acquire(v8 + 64);
        qdf_list_insert_back((_QWORD *)(v8 + 80), v50);
        qdf_spinlock_release(v8 + 64);
        queue_work_on(32, *(_QWORD *)(v8 + 56), v8 + 8);
        return 0;
      }
      v40 = 2;
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: DP WFDS event post failed %d",
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        "dp_wfds_new_server",
        2);
      v51 = (void (__fastcall *)(_QWORD))v11[90];
      if ( v51 )
      {
        v52 = *v11;
        if ( *((_DWORD *)v51 - 1) != 1588979751 )
          __break(0x8228u);
        v51(v52);
      }
    }
    htc_vote_link_down(context, 6);
    result = v40;
    *(_DWORD *)(v8 + 104) = 0;
  }
  return result;
}
