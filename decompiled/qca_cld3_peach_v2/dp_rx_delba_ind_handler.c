__int64 __fastcall dp_rx_delba_ind_handler(__int64 a1, unsigned __int16 a2, unsigned int a3, unsigned __int16 a4)
{
  unsigned __int64 StatusReg; // x8
  unsigned int v9; // w23
  __int64 v10; // x21
  __int64 v11; // x8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x25
  unsigned __int64 v21; // x8
  __int64 v22; // x8
  __int16 v23; // w9
  _DWORD *v24; // x8
  __int64 v25; // x9
  __int64 v26; // x4
  __int64 v27; // x1
  __int64 v28; // x0
  unsigned int v29; // w19
  unsigned int v30; // w8
  unsigned int v37; // w10
  __int64 v40; // x0
  unsigned int v42; // w9

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 13304);
  }
  else
  {
    raw_spin_lock_bh(a1 + 13304);
    *(_QWORD *)(a1 + 13312) |= 1uLL;
  }
  v9 = a2;
  if ( *(_DWORD *)(a1 + 13324) > (unsigned int)a2 )
  {
    v10 = *(_QWORD *)(*(_QWORD *)(a1 + 13136) + 8LL * a2);
    if ( !v10 )
      goto LABEL_9;
    if ( *(unsigned __int8 *)(v10 + 388) <= 2u )
    {
      v30 = *(_DWORD *)(v10 + 40);
      while ( v30 )
      {
        _X12 = (unsigned int *)(v10 + 40);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v37 = __ldxr(_X12);
          if ( v37 != v30 )
            break;
          if ( !__stlxr(v30 + 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v37 == v30;
        v30 = v37;
        if ( _ZF )
        {
          _X8 = (unsigned int *)(v10 + 316);
          __asm { PRFM            #0x11, [X8] }
          do
            v42 = __ldxr(_X8);
          while ( __stxr(v42 + 1, _X8) );
          goto LABEL_9;
        }
      }
    }
  }
  v10 = 0;
LABEL_9:
  v11 = *(_QWORD *)(a1 + 13312);
  if ( (v11 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 13312) = v11 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 13304);
    if ( v10 )
      goto LABEL_11;
LABEL_42:
    qdf_trace_msg(
      0x81u,
      2u,
      "%s: %pK: Couldn't find peer from ID %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "dp_rx_delba_ind_handler",
      a1,
      v9);
    return 16;
  }
  raw_spin_unlock(a1 + 13304);
  if ( !v10 )
    goto LABEL_42;
LABEL_11:
  if ( (unsigned __int8)a3 >= 0x11u )
  {
    v40 = printk(
            &unk_AAA255,
            "tid < 17",
            "dp_rx_delba_ind_handler",
            "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_rx_tid.c");
    dump_stack(v40);
  }
  v20 = *(_QWORD *)(v10 + 88) + 144LL * (unsigned __int8)a3;
  if ( *(_QWORD *)(v20 + 32) )
  {
    if ( !*(_BYTE *)(v20 + 108) )
    {
      qdf_trace_msg(
        0x81u,
        5u,
        "%s: %pK: PEER_ID: %d TID: %d, BA win: %d ",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "dp_rx_delba_ind_handler",
        a1,
        v9,
        (unsigned __int8)a3,
        a4);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v21 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v21 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v21 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v20 + 88);
        v22 = *(_QWORD *)(v20 + 96);
      }
      else
      {
        raw_spin_lock_bh(v20 + 88);
        v22 = *(_QWORD *)(v20 + 96) | 1LL;
        *(_QWORD *)(v20 + 96) = v22;
      }
      *(_BYTE *)(v20 + 108) = 1;
      v23 = a4 >= 0x3Fu ? 63 : a4;
      *(_WORD *)(v20 + 122) = v23;
      *(_BYTE *)(v20 + 120) = 38;
      if ( (v22 & 1) != 0 )
      {
        *(_QWORD *)(v20 + 96) = v22 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v20 + 88);
      }
      else
      {
        raw_spin_unlock(v20 + 88);
      }
      v24 = *(_DWORD **)(*(_QWORD *)(a1 + 8) + 168LL);
      if ( v24 )
      {
        v25 = *(_QWORD *)(v10 + 24);
        v26 = *(unsigned __int8 *)(v20 + 120);
        v27 = *(unsigned __int8 *)(v25 + 59);
        v28 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v25 + 24) + 8LL) + 16LL);
        if ( *(v24 - 1) != -1677196783 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, __int64, _QWORD, __int64, _QWORD))v24)(v28, v27, v10 + 44, a3, v26, 0);
      }
    }
    v29 = 0;
  }
  else
  {
    qdf_trace_msg(
      0x81u,
      2u,
      "%s: %pK: BA session is not setup for TID:%d ",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "dp_rx_delba_ind_handler",
      a1,
      (unsigned __int8)a3);
    v29 = 16;
  }
  dp_peer_unref_delete(v10, 0xDu, v12, v13, v14, v15, v16, v17, v18, v19);
  return v29;
}
