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
  const char *v20; // x10
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  const char *v30; // x2
  unsigned int v31; // w8
  unsigned int v38; // w10
  unsigned int v41; // w9

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 13256);
  }
  else
  {
    raw_spin_lock_bh(a1 + 13256);
    *(_QWORD *)(a1 + 13264) |= 1uLL;
  }
  v9 = a2;
  if ( *(_DWORD *)(a1 + 13276) > (unsigned int)a2 )
  {
    v10 = *(_QWORD *)(*(_QWORD *)(a1 + 13088) + 8LL * a2);
    if ( !v10 )
      goto LABEL_9;
    if ( *(unsigned __int8 *)(v10 + 380) <= 2u )
    {
      v31 = *(_DWORD *)(v10 + 40);
      while ( v31 )
      {
        _X12 = (unsigned int *)(v10 + 40);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v38 = __ldxr(_X12);
          if ( v38 != v31 )
            break;
          if ( !__stlxr(v31 + 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v38 == v31;
        v31 = v38;
        if ( _ZF )
        {
          _X8 = (unsigned int *)(v10 + 308);
          __asm { PRFM            #0x11, [X8] }
          do
            v41 = __ldxr(_X8);
          while ( __stxr(v41 + 1, _X8) );
          goto LABEL_9;
        }
      }
    }
  }
  v10 = 0;
LABEL_9:
  v11 = *(_QWORD *)(a1 + 13264);
  if ( (v11 & 1) == 0 )
  {
    raw_spin_unlock(a1 + 13256);
    if ( v10 )
      goto LABEL_11;
LABEL_27:
    v30 = "%s: Couldn't find peer from ID %d - skipping security inits";
    return qdf_trace_msg(0x81u, 2u, v30, v12, v13, v14, v15, v16, v17, v18, v19, "dp_rx_sec_ind_handler", v9);
  }
  *(_QWORD *)(a1 + 13264) = v11 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(a1 + 13256);
  if ( !v10 )
    goto LABEL_27;
LABEL_11:
  if ( !*(_QWORD *)v10 )
  {
    v30 = "%s: Couldn't find txrx peer from ID %d - skipping security inits";
    return qdf_trace_msg(0x81u, 2u, v30, v12, v13, v14, v15, v16, v17, v18, v19, "dp_rx_sec_ind_handler", v9);
  }
  v20 = "mcast";
  if ( a4 )
    v20 = "ucast";
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
    v20,
    a3);
  *(_DWORD *)(*(_QWORD *)v10 + 12LL * (a4 != 0) + 64) = a3;
  return dp_peer_unref_delete(v10, 0xDu, v21, v22, v23, v24, v25, v26, v27, v28);
}
