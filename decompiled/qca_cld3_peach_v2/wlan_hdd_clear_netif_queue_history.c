__int64 __fastcall wlan_hdd_clear_netif_queue_history(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x0
  __int64 v4; // x21
  __int64 v5; // x22
  __int64 v6; // x8
  __int64 result; // x0
  unsigned __int64 v8; // x28
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x20
  __int64 v18; // x8
  __int64 v19; // x8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x21
  __int64 v38; // x8
  __int64 v39; // x8
  unsigned int *v40; // x8
  unsigned int v41; // w10
  __int64 v42; // x8
  unsigned int v49; // w9
  _QWORD *v50; // x1
  __int64 v51; // x9
  unsigned __int64 v52; // x8
  __int64 v53; // x9
  unsigned int *v54; // x9
  unsigned int v55; // w12
  __int64 v56; // x9
  __int64 v58; // x0
  __int64 v59; // x20
  __int64 v60; // x9
  unsigned __int64 v61; // x8
  __int64 v62; // x9
  unsigned int *v63; // x9
  unsigned int v64; // w12
  __int64 v65; // x9
  _QWORD *v67; // x20
  unsigned int v69; // w9
  unsigned int v71; // w9
  _QWORD v72[2]; // [xsp+0h] [xbp-10h] BYREF

  v72[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 32);
  }
  else
  {
    raw_spin_lock_bh(a1 + 32);
    *(_QWORD *)(a1 + 40) |= 1uLL;
  }
  v72[0] = 0;
  v3 = qdf_list_peek_front((_QWORD *)(a1 + 48), v72);
  if ( (_DWORD)v3 || (v50 = (_QWORD *)v72[0], v4 = v72[0] - 8LL, v72[0] == 8) )
  {
    v4 = 0;
LABEL_7:
    v5 = 0;
    goto LABEL_8;
  }
  v51 = *(__int64 *)((char *)&off_18 + v72[0]);
  if ( v51 )
  {
    v52 = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(v52 + 16);
    v53 = *(_QWORD *)(v51 + 1320);
    v54 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v53);
    do
      v55 = __ldxr(v54);
    while ( __stxr(v55 + 1, v54) );
    v56 = *(_QWORD *)(v52 + 16) - 1LL;
    *(_DWORD *)(v52 + 16) = v56;
    if ( !v56 || !*(_QWORD *)(v52 + 16) )
    {
      v67 = v50;
      preempt_schedule_notrace(v3);
      v50 = v67;
    }
  }
  _X8 = (unsigned int *)(v50 + 6582);
  __asm { PRFM            #0x11, [X8] }
  do
    v69 = __ldxr(_X8);
  while ( __stxr(v69 + 1, _X8) );
  v72[0] = 0;
  v58 = qdf_list_peek_next((_QWORD *)(a1 + 48), v50, v72);
  if ( (_DWORD)v58 )
    goto LABEL_7;
  v59 = v72[0];
  v5 = v72[0] - 8LL;
  if ( v72[0] != 8 )
  {
    v60 = *(__int64 *)((char *)&off_18 + v72[0]);
    if ( v60 )
    {
      v61 = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(v61 + 16);
      v62 = *(_QWORD *)(v60 + 1320);
      v63 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v62);
      do
        v64 = __ldxr(v63);
      while ( __stxr(v64 + 1, v63) );
      v65 = *(_QWORD *)(v61 + 16) - 1LL;
      *(_DWORD *)(v61 + 16) = v65;
      if ( !v65 || !*(_QWORD *)(v61 + 16) )
        preempt_schedule_notrace(v58);
    }
    _X8 = (unsigned int *)(v59 + 52656);
    __asm { PRFM            #0x11, [X8] }
    do
      v71 = __ldxr(_X8);
    while ( __stxr(v71 + 1, _X8) );
  }
LABEL_8:
  v6 = *(_QWORD *)(a1 + 40);
  if ( (v6 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 40) = v6 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(a1 + 32);
    if ( v4 )
      goto LABEL_10;
  }
  else
  {
    result = raw_spin_unlock(a1 + 32);
    if ( v4 )
    {
LABEL_10:
      v8 = _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        qdf_mem_set((void *)(v4 + 51744), 0x120u, 0);
        qdf_mem_set((void *)(v4 + 42144), 0x2580u, 0);
        *(_BYTE *)(v4 + 42136) = 0;
        v19 = jiffies;
        *(_QWORD *)(v4 + 42120) = 0;
        *(_QWORD *)(v4 + 42128) = 0;
        *(_QWORD *)(v4 + 42112) = v19;
        *(_QWORD *)(v4 + 42104) = v19;
        hdd_adapter_dev_put_debug(v4, 0x23u, v20, v21, v22, v23, v24, v25, v26, v27);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v8 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v8 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(a1 + 32);
          if ( v5 )
            goto LABEL_18;
LABEL_12:
          v17 = 0;
          v4 = 0;
          v18 = *(_QWORD *)(a1 + 40);
          if ( (v18 & 1) == 0 )
            goto LABEL_13;
LABEL_31:
          *(_QWORD *)(a1 + 40) = v18 & 0xFFFFFFFFFFFFFFFELL;
          result = raw_spin_unlock_bh(a1 + 32);
          v5 = v17;
          if ( !v4 )
            break;
        }
        else
        {
          raw_spin_lock_bh(a1 + 32);
          *(_QWORD *)(a1 + 40) |= 1uLL;
          if ( !v5 )
            goto LABEL_12;
LABEL_18:
          v72[0] = 0;
          v28 = qdf_list_peek_next((_QWORD *)(a1 + 48), (_QWORD *)(v5 + 8), v72);
          v17 = v72[0] - 8LL;
          if ( (_DWORD)v28 )
            v37 = 0;
          else
            v37 = v72[0] - 8LL;
          if ( v5 == v37 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Validation failed",
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              "hdd_validate_next_adapter");
            hdd_adapter_dev_put_debug(v5, 0x23u, v9, v10, v11, v12, v13, v14, v15, v16);
            goto LABEL_12;
          }
          if ( v37 )
          {
            v38 = *(_QWORD *)(v37 + 32);
            if ( v38 )
            {
              ++*(_DWORD *)(v8 + 16);
              v39 = *(_QWORD *)(v38 + 1320);
              v40 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v39);
              do
                v41 = __ldxr(v40);
              while ( __stxr(v41 + 1, v40) );
              v42 = *(_QWORD *)(v8 + 16) - 1LL;
              *(_DWORD *)(v8 + 16) = v42;
              if ( !v42 || !*(_QWORD *)(v8 + 16) )
                preempt_schedule_notrace(v28);
            }
            _X8 = (unsigned int *)(v37 + 52664);
            __asm { PRFM            #0x11, [X8] }
            do
              v49 = __ldxr(_X8);
            while ( __stxr(v49 + 1, _X8) );
          }
          else
          {
            v17 = 0;
          }
          v4 = v5;
          v18 = *(_QWORD *)(a1 + 40);
          if ( (v18 & 1) != 0 )
            goto LABEL_31;
LABEL_13:
          result = raw_spin_unlock(a1 + 32);
          v5 = v17;
          if ( !v4 )
            break;
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
