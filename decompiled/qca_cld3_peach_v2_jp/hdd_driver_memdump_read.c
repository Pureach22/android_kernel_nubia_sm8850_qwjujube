unsigned __int64 __fastcall hdd_driver_memdump_read(__int64 a1, __int64 a2, unsigned __int64 a3, __int64 *a4)
{
  int v8; // w0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x19
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x23
  __int64 v36; // x8
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x0
  unsigned int v46; // w0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  bool v55; // cc
  unsigned __int64 v56; // x8
  __int64 v57; // x24
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // x8
  __int64 *v67[2]; // [xsp+0h] [xbp-10h] BYREF

  v67[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v67[0] = nullptr;
  v8 = _osif_driver_sync_op_start(v67, (__int64)"hdd_driver_memdump_read");
  if ( !v8 )
  {
    v17 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 696LL);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Read req for size:%zu pos:%llu",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "__hdd_driver_memdump_read",
      a3,
      *a4);
    if ( (unsigned int)_wlan_hdd_validate_context(
                         v17,
                         (__int64)"__hdd_driver_memdump_read",
                         v18,
                         v19,
                         v20,
                         v21,
                         v22,
                         v23,
                         v24,
                         v25) )
    {
LABEL_4:
      a3 = -22;
      goto LABEL_5;
    }
    mutex_lock(v17 + 1360);
    v35 = *a4;
    if ( *a4 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Invalid start offset for memdump read",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "__hdd_driver_memdump_read");
      mutex_unlock(v17 + 1360);
      goto LABEL_4;
    }
    if ( !a3 || (v36 = *(unsigned __int16 *)(v17 + 1408), *(_WORD *)(v17 + 1408)) && v35 >= (unsigned __int64)v36 )
    {
      mutex_unlock(v17 + 1360);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: No more data to copy",
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        "__hdd_driver_memdump_read");
      a3 = 0;
      goto LABEL_5;
    }
    v45 = *(_QWORD *)(v17 + 1416);
    if ( v35 )
    {
      if ( v45 )
        goto LABEL_21;
    }
    else if ( v45 )
    {
LABEL_18:
      v46 = qdf_state_info_dump_all(v45, 4096, (_WORD *)(v17 + 1408));
      if ( v46 )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Error in dump driver information, status %d",
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          "__hdd_driver_memdump_read",
          v46);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: driver_dump_size: %d",
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        "__hdd_driver_memdump_read",
        *(unsigned __int16 *)(v17 + 1408));
      v35 = *a4;
      v36 = *(unsigned __int16 *)(v17 + 1408);
LABEL_21:
      v55 = v36 <= v35;
      v56 = v36 - v35;
      if ( v55 )
      {
        mutex_unlock(v17 + 1360);
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Invalid POS pointer",
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          "__hdd_driver_memdump_read");
        a3 = -14;
      }
      else
      {
        if ( v56 < a3 )
          a3 = v56;
        if ( a3 >> 31 )
        {
          __break(0x800u);
        }
        else
        {
          v57 = *(_QWORD *)(v17 + 1416);
          _check_object_size(v57 + v35, a3, 1);
          if ( !inline_copy_to_user_0(a2, v57 + v35, a3) )
          {
            v66 = *a4 + a3;
            *a4 = v66;
            if ( v66 >= *(unsigned __int16 *)(v17 + 1408) )
              hdd_driver_mem_cleanup(v27, v28, v29, v30, v31, v32, v33, v34);
            mutex_unlock(v17 + 1360);
            goto LABEL_5;
          }
        }
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: copy to user space failed",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "__hdd_driver_memdump_read");
        mutex_unlock(v17 + 1360);
        a3 = -14;
      }
LABEL_5:
      _osif_driver_sync_op_stop(v67[0], (__int64)"hdd_driver_memdump_read");
      goto LABEL_6;
    }
    v45 = _qdf_mem_malloc(0x1000u, "__hdd_driver_memdump_read", 129);
    *(_QWORD *)(v17 + 1416) = v45;
    if ( !v45 )
    {
      mutex_unlock(v17 + 1360);
      a3 = -12;
      goto LABEL_5;
    }
    goto LABEL_18;
  }
  a3 = v8;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return a3;
}
