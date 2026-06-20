__int64 __fastcall dp_wfds_handle_request_mem_ind(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x25
  unsigned int *v10; // x20
  __int64 v11; // x8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w8
  __int64 v21; // x26
  unsigned __int64 v22; // x19
  unsigned __int16 *v23; // x27
  unsigned __int64 v24; // x22
  unsigned int v25; // w23
  __int64 v26; // x24
  unsigned int v27; // w8
  _QWORD *v28; // x19
  unsigned __int8 v29; // w8
  unsigned int v30; // w8
  unsigned __int8 v31; // w24
  unsigned int v32; // w26
  unsigned __int8 v33; // w22
  __int64 v34; // x1

  v9 = gp_dl_wfds_ctx;
  if ( !gp_dl_wfds_ctx )
    return result;
  v10 = (unsigned int *)result;
  qdf_trace_msg(
    0x45u,
    8u,
    "%s: Received request mem indication from QMI server",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "dp_wfds_handle_request_mem_ind");
  v11 = *v10;
  *(_DWORD *)(v9 + 108) = v11;
  result = _qdf_mem_malloc(40 * v11, "dp_wfds_handle_request_mem_ind", 574);
  *(_QWORD *)(v9 + 112) = result;
  if ( !result )
    return result;
  v20 = *(_DWORD *)(v9 + 108);
  if ( !v20 )
  {
LABEL_18:
    result = _qdf_mem_malloc(0x20u, "dp_wfds_event_post", 440);
    if ( result )
    {
      *(_QWORD *)(result + 24) = 0;
      v28 = (_QWORD *)result;
      *(_DWORD *)(result + 16) = 1;
      qdf_spinlock_acquire(v9 + 64);
      qdf_list_insert_back((_QWORD *)(v9 + 80), v28);
      qdf_spinlock_release(v9 + 64);
      return queue_work_on(32, *(_QWORD *)(v9 + 56), v9 + 8);
    }
    return result;
  }
  v21 = 0;
  v22 = 0;
  v23 = (unsigned __int16 *)v10 + 3;
  while ( v22 == 2 )
  {
LABEL_5:
    ++v22;
    v21 += 40;
    v23 += 2;
    if ( v20 <= (unsigned int)v22 )
      goto LABEL_18;
  }
  if ( v22 >= 8 )
  {
    __break(0x5512u);
    JUMPOUT(0x5B08D0);
  }
  v24 = *(v23 - 1);
  v25 = *v23;
  v26 = *(_QWORD *)(**(_QWORD **)v9 + 16LL);
  if ( !(_BYTE)v22 )
  {
    v27 = 14;
    goto LABEL_12;
  }
  if ( (unsigned __int8)v22 == 1 )
  {
    v27 = 13;
LABEL_12:
    dp_prealloc_get_multi_pages(v27, *(v23 - 1), v25, (_QWORD *)(result + v21), v12, v13, v14, v15, v16, v17, v18, v19);
    goto LABEL_14;
  }
  qdf_trace_msg(
    0x45u,
    8u,
    "%s: No desc type for mem arena %d",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "dp_wfds_get_desc_type_from_mem_arena",
    (unsigned int)v22);
LABEL_14:
  result = *(_QWORD *)(v9 + 112);
  if ( !*(_WORD *)(result + v21 + 2) )
  {
    qdf_mem_multi_pages_alloc(v26, result + v21, v24, v25, 0, 0);
    result = *(_QWORD *)(v9 + 112);
  }
  if ( *(_WORD *)(result + v21 + 2) )
  {
    v20 = *(_DWORD *)(v9 + 108);
    goto LABEL_5;
  }
  v29 = v22 - 1;
  if ( *(_WORD *)(result + 40LL * (unsigned __int8)(v22 - 1) + 2) )
  {
    do
    {
      v31 = v29;
      v32 = v29;
      v33 = v29;
      v34 = result + 40LL * v29;
      if ( *(_BYTE *)(v34 + 32) )
      {
        if ( (unsigned __int8)v22 == 1 )
        {
          v30 = 14;
        }
        else if ( (unsigned __int8)v22 == 2 )
        {
          v30 = 13;
        }
        else
        {
          qdf_trace_msg(
            0x45u,
            8u,
            "%s: No desc type for mem arena %d",
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            "dp_wfds_get_desc_type_from_mem_arena",
            v29);
          result = *(_QWORD *)(v9 + 112);
          v30 = 17;
        }
        dp_prealloc_put_multi_pages(v30, result + 40LL * v32, v12, v13, v14, v15, v16, v17, v18, v19);
      }
      else
      {
        qdf_mem_multi_pages_free(*(_QWORD *)(**(_QWORD **)v9 + 16LL), v34, 0, 0);
      }
      v29 = v33 - 1;
      result = *(_QWORD *)(v9 + 112);
      LOBYTE(v22) = v31;
    }
    while ( *(_WORD *)(result + 40LL * (unsigned __int8)(v33 - 1) + 2) );
  }
  result = _qdf_mem_free(result);
  *(_QWORD *)(v9 + 112) = 0;
  *(_DWORD *)(v9 + 108) = 0;
  return result;
}
