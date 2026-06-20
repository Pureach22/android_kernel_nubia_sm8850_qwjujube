__int64 __fastcall _lim_process_sme_register_mgmt_frame_req(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x3
  __int64 v13; // x4
  __int64 v14; // x5
  __int64 result; // x0
  _QWORD *v16; // x8
  size_t v17; // x2
  _QWORD *v18; // [xsp+8h] [xbp-18h] BYREF
  _QWORD *v19[2]; // [xsp+10h] [xbp-10h] BYREF

  v19[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(unsigned __int8 *)(a2 + 5);
  v13 = *(unsigned __int16 *)(a2 + 6);
  v14 = *(unsigned __int16 *)(a2 + 8);
  v18 = nullptr;
  v19[0] = nullptr;
  qdf_trace_msg(
    0x35u,
    8u,
    "Register Frame: register %d, type %d, match length %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    v12,
    v13,
    v14);
  qdf_mutex_acquire(a1 + 12280);
  qdf_list_peek_front((_QWORD *)(a1 + 12344), v19);
  result = qdf_mutex_release(a1 + 12280);
  v16 = v19[0];
  if ( v19[0] )
  {
    while ( 1 )
    {
      if ( *((unsigned __int16 *)v16 + 8) == *(unsigned __int16 *)(a2 + 6) )
      {
        v17 = *(unsigned __int16 *)(a2 + 8);
        if ( !*(_WORD *)(a2 + 8)
          || *((unsigned __int16 *)v16 + 9) == (_DWORD)v17
          && !(unsigned int)qdf_mem_cmp((char *)v16 + 22, (const void *)(a2 + 10), v17) )
        {
          break;
        }
      }
      qdf_mutex_acquire(a1 + 12280);
      qdf_list_peek_next((_QWORD *)(a1 + 12344), v19[0], &v18);
      result = qdf_mutex_release(a1 + 12280);
      v16 = v18;
      v18 = nullptr;
      v19[0] = v16;
      if ( !v16 )
        goto LABEL_11;
    }
    qdf_mutex_acquire(a1 + 12280);
    if ( !(unsigned int)qdf_list_remove_node(a1 + 12344, v19[0]) )
      _qdf_mem_free((__int64)v19[0]);
    result = qdf_mutex_release(a1 + 12280);
  }
LABEL_11:
  if ( *(_BYTE *)(a2 + 5) == 1 )
  {
    result = _qdf_mem_malloc(*(unsigned __int16 *)(a2 + 8) + 24LL, "__lim_process_sme_register_mgmt_frame_req", 9283);
    v19[0] = (_QWORD *)result;
    if ( result )
    {
      *(_WORD *)(result + 16) = *(_WORD *)(a2 + 6);
      *(_WORD *)(result + 18) = *(_WORD *)(a2 + 8);
      *(_WORD *)(result + 20) = *(unsigned __int8 *)(a2 + 4);
      if ( *(_WORD *)(a2 + 8) )
        qdf_mem_copy((void *)(result + 22), (const void *)(a2 + 10), *(unsigned __int16 *)(a2 + 8));
      qdf_mutex_acquire(a1 + 12280);
      qdf_list_insert_front((_QWORD *)(a1 + 12344), v19[0]);
      result = qdf_mutex_release(a1 + 12280);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
