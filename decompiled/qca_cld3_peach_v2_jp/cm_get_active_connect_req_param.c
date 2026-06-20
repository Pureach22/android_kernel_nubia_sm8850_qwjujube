__int64 __fastcall cm_get_active_connect_req_param(
        __int64 a1,
        __int64 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 cmpt_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x20
  _QWORD *v22; // x1
  __int64 v23; // x22
  int v24; // w8
  unsigned int v26; // w19
  __int64 result; // x0
  __int64 v28; // x20
  size_t v29; // x0
  void *v30; // x0
  size_t v31; // x0
  void *v32; // x0
  _QWORD *v33; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v34[2]; // [xsp+10h] [xbp-10h] BYREF

  v34[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33 = nullptr;
  v34[0] = 0;
  if ( !a1 )
  {
    v28 = jiffies;
    if ( cm_get_cm_ctx_fl___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s:%u: vdev is NULL",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "cm_get_active_connect_req_param",
        1687);
      cm_get_cm_ctx_fl___last_ticks = v28;
      result = 16;
      goto LABEL_15;
    }
    goto LABEL_14;
  }
  if ( (*(_DWORD *)(a1 + 16) & 0xFFFFFFFD) != 0 )
  {
LABEL_14:
    result = 16;
    goto LABEL_15;
  }
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1);
  if ( !cmpt_obj || (v21 = *(_QWORD *)(cmpt_obj + 496)) == 0 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s:%u: vdev %d cm_ctx is NULL",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "cm_get_active_connect_req_param",
      1687,
      *(unsigned __int8 *)(a1 + 104));
    result = 16;
    goto LABEL_15;
  }
  qdf_mutex_acquire(v21 + 120);
  qdf_list_peek_front((_QWORD *)(v21 + 96), v34);
  v22 = (_QWORD *)v34[0];
  if ( v34[0] )
  {
    while ( 1 )
    {
      qdf_list_peek_next((_QWORD *)(v21 + 96), v22, &v33);
      v23 = v34[0];
      v24 = *(_DWORD *)(v34[0] + 16LL);
      if ( v24 == *(_DWORD *)(v21 + 88) && (v24 & 0xF000000) == 201326592 )
        break;
      v22 = v33;
      v33 = nullptr;
      v34[0] = v22;
      if ( !v22 )
        goto LABEL_11;
    }
    memcpy(a2, (const void *)(v34[0] + 32LL), 0x330u);
    qdf_mem_set(a2 + 19, 0x10u, 0);
    qdf_mem_set(a2 + 21, 0x10u, 0);
    v29 = *(unsigned int *)(v23 + 184);
    if ( (_DWORD)v29 )
    {
      v30 = (void *)_qdf_mem_malloc(v29, "cm_get_active_connect_req_param", 1711);
      a2[20] = (__int64)v30;
      if ( !v30 )
        goto LABEL_26;
      qdf_mem_copy(v30, *(const void **)(v23 + 192), *(unsigned int *)(v23 + 184));
      *((_DWORD *)a2 + 38) = *(_DWORD *)(v23 + 184);
    }
    v31 = *(unsigned int *)(v23 + 200);
    if ( !(_DWORD)v31 )
    {
      v26 = 0;
      goto LABEL_12;
    }
    v32 = (void *)_qdf_mem_malloc(v31, "cm_get_active_connect_req_param", 1725);
    a2[22] = (__int64)v32;
    if ( v32 )
    {
      qdf_mem_copy(v32, *(const void **)(v23 + 208), *(unsigned int *)(v23 + 200));
      v26 = 0;
      *((_DWORD *)a2 + 42) = *(_DWORD *)(v23 + 200);
      goto LABEL_12;
    }
    _qdf_mem_free(a2[20]);
    qdf_mem_set(a2 + 19, 0x10u, 0);
LABEL_26:
    v26 = 2;
    goto LABEL_12;
  }
LABEL_11:
  v26 = 16;
LABEL_12:
  qdf_mutex_release(v21 + 120);
  result = v26;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
