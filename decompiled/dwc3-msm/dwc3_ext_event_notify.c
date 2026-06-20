__int64 __fastcall dwc3_ext_event_notify(__int64 a1)
{
  __int64 v2; // x8
  int v3; // w4
  __int64 v4; // x0
  __int64 v5; // x0
  unsigned int v6; // w3
  __int64 v7; // x8
  __int64 v8; // x8
  __int64 v9; // x0
  int v10; // w4
  int v11; // w5
  __int64 v12; // x8
  __int64 v13; // x8
  __int64 v14; // x8
  int v15; // w5
  __int64 result; // x0
  __int64 v17; // x8
  int v18; // w9
  __int64 v19; // x8
  void (*v20)(void); // x8
  unsigned __int64 v23; // x10
  unsigned __int64 v30; // x9
  unsigned __int64 v33; // x10
  unsigned __int64 v36; // x9
  unsigned __int64 v39; // x10
  unsigned __int64 v42; // x9
  unsigned __int64 v45; // x9
  unsigned __int64 v48; // x10
  unsigned __int64 v51; // x10

  flush_work(a1 + 656);
  if ( *(_BYTE *)(a1 + 2582) == 1 && ((*(_BYTE *)(a1 + 746) & 1) != 0 || !*(_DWORD *)(a1 + 752)) )
    return dev_err(*(_QWORD *)a1, "%s: Event not allowed\n", "dwc3_ext_event_notify");
  v2 = *(_QWORD *)(a1 + 448);
  if ( v2 )
    v3 = *(_DWORD *)(v2 + 16);
  else
    v3 = 0;
  ipc_log_string(
    *(_QWORD *)(a1 + 1256),
    "%s: enter: mdwc->inputs:%lx hs_phy_flags:%x\n",
    "dwc3_ext_event_notify",
    *(_QWORD *)(a1 + 688),
    v3);
  v4 = *(_QWORD *)(a1 + 1256);
  if ( *(_DWORD *)(a1 + 752) == 1 )
  {
    ipc_log_string(v4, "%s: XCVR: ID set\n", "dwc3_ext_event_notify");
    _X8 = (unsigned __int64 *)(a1 + 688);
    __asm { PRFM            #0x11, [X8] }
    do
      v30 = __ldxr(_X8);
    while ( __stxr(v30 | 1, _X8) );
  }
  else
  {
    ipc_log_string(v4, "%s: XCVR: ID clear\n", "dwc3_ext_event_notify");
    _X8 = (unsigned __int64 *)(a1 + 688);
    __asm { PRFM            #0x11, [X8] }
    do
      v33 = __ldxr(_X8);
    while ( __stxr(v33 & 0xFFFFFFFFFFFFFFFELL, _X8) );
  }
  if ( *(_BYTE *)(a1 + 746) == 1 && (*(_BYTE *)(a1 + 632) & 1) == 0 )
  {
    v12 = *(_QWORD *)(a1 + 448);
    if ( v12 && (*(_BYTE *)(v12 + 16) & 0x40) != 0 )
    {
      ipc_log_string(*(_QWORD *)(a1 + 1256), "%s: XCVR: BSV clear\n", "dwc3_ext_event_notify");
      _X8 = (unsigned __int64 *)(a1 + 688);
      __asm { PRFM            #0x11, [X8] }
      do
        v51 = __ldxr(_X8);
      while ( __stxr(v51 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
    }
    else
    {
      ipc_log_string(*(_QWORD *)(a1 + 1256), "%s: XCVR: BSV set\n", "dwc3_ext_event_notify");
      _X8 = (unsigned __int64 *)(a1 + 688);
      __asm { PRFM            #0x11, [X8] }
      do
        v42 = __ldxr(_X8);
      while ( __stxr(v42 | 2, _X8) );
    }
  }
  else
  {
    ipc_log_string(*(_QWORD *)(a1 + 1256), "%s: XCVR: BSV clear\n", "dwc3_ext_event_notify");
    _X8 = (unsigned __int64 *)(a1 + 688);
    __asm { PRFM            #0x11, [X8] }
    do
      v23 = __ldxr(_X8);
    while ( __stxr(v23 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
  }
  v5 = *(_QWORD *)(a1 + 1256);
  if ( *(_BYTE *)(a1 + 748) == 1 )
  {
    ipc_log_string(v5, "%s: XCVR: SUSP set\n", "dwc3_ext_event_notify");
    _X8 = (unsigned __int64 *)(a1 + 688);
    __asm { PRFM            #0x11, [X8] }
    do
      v36 = __ldxr(_X8);
    while ( __stxr(v36 | 4, _X8) );
  }
  else
  {
    ipc_log_string(v5, "%s: XCVR: SUSP clear\n", "dwc3_ext_event_notify");
    _X8 = (unsigned __int64 *)(a1 + 688);
    __asm { PRFM            #0x11, [X8] }
    do
      v39 = __ldxr(_X8);
    while ( __stxr(v39 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
  }
  v6 = *(unsigned __int8 *)(a1 + 745);
  if ( __PAIR64__(*(unsigned __int8 *)(a1 + 746), v6) == 0x100000001LL )
  {
    v7 = *(_QWORD *)(a1 + 448);
    if ( v7 )
    {
      *(_DWORD *)(v7 + 16) &= 0xFFFFFF3F;
      v8 = *(_QWORD *)(a1 + 448);
      v9 = *(_QWORD *)(a1 + 1256);
      v6 = *(unsigned __int8 *)(a1 + 745);
      v10 = *(unsigned __int8 *)(a1 + 747);
      if ( v8 )
      {
        v11 = *(_DWORD *)(v8 + 16);
LABEL_25:
        ipc_log_string(v9, "%s: eud: state:%d active:%d hs_phy_flags:0x%x\n", "dwc3_ext_event_notify", v6, v10, v11);
        v13 = *(_QWORD *)(a1 + 448);
        if ( *(_BYTE *)(a1 + 747) == 1 )
        {
          if ( v13 )
            *(_DWORD *)(v13 + 16) |= 0x80u;
          ipc_log_string(*(_QWORD *)(a1 + 1256), "%s: EUD: XCVR: BSV set\n", "dwc3_ext_event_notify");
          _X8 = (unsigned __int64 *)(a1 + 688);
          __asm { PRFM            #0x11, [X8] }
          do
            v45 = __ldxr(_X8);
          while ( __stxr(v45 | 2, _X8) );
        }
        else
        {
          if ( v13 )
            *(_DWORD *)(v13 + 16) |= 0x40u;
          ipc_log_string(*(_QWORD *)(a1 + 1256), "%s: EUD: XCVR: BSV clear\n", "dwc3_ext_event_notify");
          _X8 = (unsigned __int64 *)(a1 + 688);
          __asm { PRFM            #0x11, [X8] }
          do
            v48 = __ldxr(_X8);
          while ( __stxr(v48 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
        }
        v6 = 0;
        *(_BYTE *)(a1 + 745) = 0;
        goto LABEL_33;
      }
    }
    else
    {
      v9 = *(_QWORD *)(a1 + 1256);
      v10 = *(unsigned __int8 *)(a1 + 747);
    }
    v11 = 0;
    goto LABEL_25;
  }
LABEL_33:
  v14 = *(_QWORD *)(a1 + 448);
  if ( v14 )
    v15 = *(_DWORD *)(v14 + 16);
  else
    v15 = 0;
  result = ipc_log_string(
             *(_QWORD *)(a1 + 1256),
             "%s: eud: state:%d active:%d hs_phy_flags:0x%x\n",
             "dwc3_ext_event_notify",
             v6,
             *(unsigned __int8 *)(a1 + 747),
             v15);
  if ( (*(_BYTE *)(a1 + 746) & 1) == 0
    && (v17 = *(_QWORD *)(a1 + 448)) != 0
    && (v18 = *(_DWORD *)(v17 + 16), (v18 & 0x40) != 0) )
  {
    *(_DWORD *)(v17 + 16) = v18 & 0xFFFFFFBF;
    v19 = *(_QWORD *)(a1 + 448);
    if ( v19 )
    {
      *(_DWORD *)(v19 + 16) |= 0x100u;
      result = *(_QWORD *)(a1 + 448);
      if ( result )
      {
        v20 = *(void (**)(void))(result + 296);
        if ( !v20 )
          goto LABEL_47;
        if ( *((_DWORD *)v20 - 1) != 711694717 )
          __break(0x8228u);
        v20();
        result = *(_QWORD *)(a1 + 448);
        if ( result )
LABEL_47:
          *(_DWORD *)(result + 16) &= ~0x100u;
      }
    }
  }
  else
  {
    ipc_log_string(
      *(_QWORD *)(a1 + 1256),
      "%s: exit: mdwc->inputs:%lx\n",
      "dwc3_ext_event_notify",
      *(_QWORD *)(a1 + 688));
    return queue_work_on(32, *(_QWORD *)(a1 + 648), a1 + 656);
  }
  return result;
}
