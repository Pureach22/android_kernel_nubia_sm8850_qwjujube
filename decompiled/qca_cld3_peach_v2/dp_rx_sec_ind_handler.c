__int64 __fastcall dp_rx_sec_ind_handler(__int64 a1, unsigned __int16 a2, int a3, int a4)
{
  unsigned __int64 StatusReg; // x8
  unsigned int v9; // w23
  __int64 v10; // x22
  __int64 v11; // x8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _QWORD *v20; // x8
  const char *v21; // x10
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  const char *v31; // x2
  unsigned int v32; // w8
  unsigned int v39; // w10
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
      v32 = *(_DWORD *)(v10 + 40);
      while ( v32 )
      {
        _X12 = (unsigned int *)(v10 + 40);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v39 = __ldxr(_X12);
          if ( v39 != v32 )
            break;
          if ( !__stlxr(v32 + 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v39 == v32;
        v32 = v39;
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
LABEL_30:
    v31 = "%s: Couldn't find peer from ID %d - skipping security inits";
    return qdf_trace_msg(0x81u, 2u, v31, v12, v13, v14, v15, v16, v17, v18, v19, "dp_rx_sec_ind_handler", v9);
  }
  raw_spin_unlock(a1 + 13304);
  if ( !v10 )
    goto LABEL_30;
LABEL_11:
  if ( *(_DWORD *)(v10 + 408) != 1 || (v20 = *(_QWORD **)(v10 + 416)) == nullptr )
  {
    if ( *(_QWORD *)v10 )
      goto LABEL_14;
    goto LABEL_18;
  }
  if ( !*v20 )
  {
LABEL_18:
    v31 = "%s: Couldn't find txrx peer from ID %d - skipping security inits";
    return qdf_trace_msg(0x81u, 2u, v31, v12, v13, v14, v15, v16, v17, v18, v19, "dp_rx_sec_ind_handler", v9);
  }
LABEL_14:
  v21 = "mcast";
  if ( a4 )
    v21 = "ucast";
  qdf_trace_msg(
    0x81u,
    5u,
    "%s: %pK: sec spec for peer %pK %02x:%02x:%02x:**:**:%02x: %s key of type %d",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "dp_rx_sec_ind_handler",
    a1,
    v10,
    *(unsigned __int8 *)(v10 + 44),
    *(unsigned __int8 *)(v10 + 45),
    *(unsigned __int8 *)(v10 + 46),
    *(unsigned __int8 *)(v10 + 49),
    v21,
    a3);
  *(_DWORD *)(*(_QWORD *)v10 + 12LL * (a4 != 0) + 64) = a3;
  return dp_peer_unref_delete(v10, 0xDu, v22, v23, v24, v25, v26, v27, v28, v29);
}
