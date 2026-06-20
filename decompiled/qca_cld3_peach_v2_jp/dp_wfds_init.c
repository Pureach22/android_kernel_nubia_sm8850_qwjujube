__int64 __fastcall dp_wfds_init(__int64 a1)
{
  __int64 v2; // x23
  __int64 v3; // x0
  __int64 v4; // x19
  __int64 v5; // x20
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v15; // w21
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7

  v2 = *(_QWORD *)(*(_QWORD *)a1 + 16LL);
  v3 = _qdf_mem_malloc(0xF8u, "dp_wfds_init", 818);
  if ( v3 )
  {
    *(_DWORD *)(v3 + 64) = 0;
    *(_QWORD *)(v3 + 72) = 0;
    v4 = v3;
    *(_QWORD *)(v3 + 80) = v3 + 80;
    *(_QWORD *)(v3 + 88) = v3 + 80;
    *(_QWORD *)(v3 + 8) = 0xFFFFFFFE00000LL;
    v5 = v3 + 8;
    *(_QWORD *)(v3 + 96) = 0;
    *(_QWORD *)(v3 + 40) = dp_wfds_work;
    *(_QWORD *)(v3 + 48) = v3;
    *(_QWORD *)(v3 + 16) = v3 + 16;
    *(_QWORD *)(v3 + 24) = v3 + 16;
    *(_QWORD *)(v3 + 32) = _qdf_defer_func;
    v6 = alloc_workqueue("dp_wfds_wq", 2, 0);
    *(_QWORD *)(v4 + 56) = v6;
    if ( v6 )
    {
      *(_DWORD *)(v4 + 104) = 0;
      v15 = wlan_qmi_wfds_init(**(_QWORD **)a1);
      if ( !v15 )
      {
        *(_QWORD *)(a1 + 24) = v4;
        *(_QWORD *)v4 = a1;
        v32 = *(_QWORD *)(v2 + 40);
        gp_dl_wfds_ctx = v4;
        *(_BYTE *)(v4 + 244) = pld_is_audio_shared_iommu_group(v32) & 1;
        qdf_trace_msg(0x45u, 8u, "%s: WFDS QMI init successful", v33, v34, v35, v36, v37, v38, v39, v40, "dp_wfds_init");
        return v15;
      }
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: WFDS QMI initialization failed %d",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "dp_wfds_init",
        v15);
      _flush_workqueue(*(_QWORD *)(v4 + 56));
      destroy_workqueue(*(_QWORD *)(v4 + 56));
    }
    else
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: DP QMI workqueue allocate failed",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "dp_wfds_init");
      v15 = 0;
    }
    flush_work(v5);
    cancel_work_sync(v5);
    if ( *(_DWORD *)(v4 + 96) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: list length not equal to zero",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "qdf_list_destroy");
    _qdf_mem_free(v4);
  }
  else
  {
    return 2;
  }
  return v15;
}
