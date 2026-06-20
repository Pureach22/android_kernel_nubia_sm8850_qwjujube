__int64 __fastcall hif_post_recv_buffers_for_pipe(__int64 *a1)
{
  __int64 v1; // x21
  __int64 v2; // x22
  __int64 v4; // x20
  unsigned int v5; // w23
  unsigned __int64 StatusReg; // x8
  unsigned int v7; // w27
  unsigned __int64 v8; // x24
  __int64 v9; // x7
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x7
  __int64 v13; // x25
  unsigned int v14; // w0
  __int64 v15; // x7
  __int64 v16; // x8
  __int64 v17; // x26
  unsigned int v18; // w0
  unsigned int v25; // w9
  __int64 v26; // x8
  unsigned int v28; // w8
  unsigned int v29; // w9
  unsigned int v30; // w10
  unsigned int v31; // w8
  unsigned int v32; // w11
  unsigned int v33; // w9
  unsigned int v34; // w10
  __int64 v35; // x8
  unsigned int v36; // w9
  unsigned int v37; // w20
  unsigned int v38; // w21
  __int64 vars0; // [xsp+0h] [xbp+0h]
  __int64 vars0a; // [xsp+0h] [xbp+0h]
  __int64 vars0b; // [xsp+0h] [xbp+0h]
  __int64 _8; // [xsp+8h] [xbp+8h]
  __int64 _8a; // [xsp+8h] [xbp+8h]
  __int64 _8b; // [xsp+8h] [xbp+8h]

  v1 = a1[4];
  if ( !v1 )
    return 0;
  v2 = *a1;
  if ( !*a1 )
  {
    qdf_trace_msg(61, 2, "%s: ce_hdl is NULL", "hif_post_recv_buffers_for_pipe");
    return 4;
  }
  v4 = a1[2];
  v5 = *(_DWORD *)(v2 + 8);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 5);
  }
  else
  {
    raw_spin_lock_bh(a1 + 5);
    a1[6] |= 1uLL;
  }
  if ( *((int *)a1 + 6) < 1 )
  {
    v7 = 0;
LABEL_29:
    v28 = *((_DWORD *)a1 + 19);
    v29 = *((_DWORD *)a1 + 20);
    v30 = *((_DWORD *)a1 + 21);
    _CF = v28 >= v7;
    v31 = v28 - v7;
    if ( _CF )
      v32 = v31;
    else
      v32 = 0;
    if ( v29 >= v7 )
      v33 = v29 - v7;
    else
      v33 = 0;
    _CF = v30 >= v7;
    v34 = v30 - v7;
    v35 = a1[6];
    *((_DWORD *)a1 + 19) = v32;
    *((_DWORD *)a1 + 20) = v33;
    if ( _CF )
      v36 = v34;
    else
      v36 = 0;
    *((_DWORD *)a1 + 21) = v36;
    if ( (v35 & 1) != 0 )
    {
      a1[6] = v35 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 5);
    }
    else
    {
      raw_spin_unlock(a1 + 5);
    }
    return 0;
  }
  v7 = 0;
  v8 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    _X8 = (unsigned int *)(a1 + 3);
    __asm { PRFM            #0x11, [X8] }
    do
      v25 = __ldxr(_X8);
    while ( __stxr(v25 - 1, _X8) );
    v26 = a1[6];
    if ( (v26 & 1) != 0 )
    {
      a1[6] = v26 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 5);
    }
    else
    {
      raw_spin_unlock(a1 + 5);
    }
    v10 = hif_record_ce_desc_event(v4, v5, 39, 0, 0, 0, 0, v9, vars0, _8);
    if ( (unsigned __int8)v5 >= 0xDu )
      break;
    v11 = _qdf_nbuf_alloc(
            *(_QWORD *)(v4 + 576),
            *(_QWORD *)(v4 + 136LL * (v5 & 0xF) + 27448),
            0,
            4,
            0,
            "hif_ce_rx_nbuf_alloc",
            3276);
    if ( !v11 )
    {
      hif_post_recv_buffers_failure(a1);
      return 2;
    }
    v13 = v11;
    hif_record_ce_desc_event(v4, v5, 40, 0, v11, 0, 0, v12, vars0a, _8a);
    v14 = _qdf_nbuf_map_single(*(_QWORD *)(v4 + 576), v13, 2);
    if ( v14 )
    {
      v37 = v14;
      hif_post_recv_buffers_failure(a1);
      _qdf_nbuf_free(v13);
      return v37;
    }
    v16 = 40;
    if ( (*(_BYTE *)(v13 + 68) & 4) != 0 )
      v16 = 80;
    v17 = *(_QWORD *)(v13 + v16);
    hif_record_ce_desc_event(v4, v5, 41, 0, v13, 0, 0, v15, vars0b, _8b);
    qdf_mem_dma_sync_single_for_device(*(_QWORD *)(v4 + 576), v17, v1, 2);
    v18 = ce_recv_buf_enqueue(v2, v13);
    if ( v18 )
    {
      v38 = v18;
      hif_post_recv_buffers_failure(a1);
      _qdf_nbuf_unmap_single(*(_QWORD *)(v4 + 576), v13, 2);
      _qdf_nbuf_free(v13);
      return v38;
    }
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v8 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v8 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 5);
    }
    else
    {
      raw_spin_lock_bh(a1 + 5);
      a1[6] |= 1uLL;
    }
    ++v7;
    if ( *((int *)a1 + 6) <= 0 )
      goto LABEL_29;
  }
  __break(0x5512u);
  return hif_post_recv_buffers_failure(v10);
}
