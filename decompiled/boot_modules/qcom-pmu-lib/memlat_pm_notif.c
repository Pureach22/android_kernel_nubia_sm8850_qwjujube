__int64 __fastcall memlat_pm_notif(__int64 a1, __int64 a2)
{
  __int64 v2; // x22
  __int64 v3; // x24
  __int64 v5; // x21
  __int64 v6; // x19
  __int64 v7; // x22
  int v9; // w20
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x24
  char v13; // w9
  _BYTE *v14; // x11
  __int64 v15; // x27
  unsigned int v16; // w19
  __int64 v18; // x28
  int v19; // w1
  unsigned __int64 StatusReg; // x0
  __int64 v21; // x0
  _BYTE *v22; // x19
  unsigned int v23; // w8
  unsigned int v26; // w10
  unsigned int v31; // w9

  _ReadStatusReg(SP_EL0);
  v2 = *(unsigned int *)(_ReadStatusReg(SP_EL0) + 40);
  if ( (unsigned int)v2 >= 0x20 )
LABEL_54:
    __break(0x5512u);
  v3 = pmu_base;
  v5 = *(_QWORD *)((char *)&cpu_ev_data + _per_cpu_offset[v2]);
  v6 = raw_spin_lock_irqsave(v5 + 336);
  if ( *(_BYTE *)(v5 + 1) == 1 )
    goto LABEL_7;
  v7 = v3 + 40LL * (unsigned int)v2;
  if ( a2 == 2 )
  {
    if ( pmu_base )
      writel_relaxed(0, (unsigned int *)(v7 + 36));
    *(_BYTE *)(v5 + 2) = 0;
LABEL_7:
    raw_spin_unlock_irqrestore(v5 + 336, v6);
    goto LABEL_8;
  }
  if ( (*(_BYTE *)v5 & 1) != 0 || (*(_BYTE *)(v5 + 2) & 1) != 0 )
  {
    v9 = 0;
  }
  else
  {
    _X8 = (unsigned int *)(v5 + 332);
    __asm { PRFM            #0x11, [X8] }
    do
      v31 = __ldxr(_X8);
    while ( __stxr(v31 + 1, _X8) );
    v9 = 1;
  }
  *(_BYTE *)(v5 + 2) = 1;
  raw_spin_unlock_irqrestore(v5 + 336, v6);
  if ( pmu_base )
  {
    v11 = *(unsigned int *)(v5 + 328);
    if ( (_DWORD)v11 )
    {
      v12 = 0;
      v13 = 0;
      v14 = &loc_8000;
      while ( 2 )
      {
        v15 = v5 + 32 + 40 * v12++;
        while ( 1 )
        {
          if ( v12 == 10 )
            goto LABEL_54;
          if ( *(_DWORD *)(v15 - 24) )
          {
            v16 = *(_DWORD *)(v15 + 8);
            if ( v16 < 4 || *(_QWORD *)(v15 - 16) != 0 )
            {
              v18 = *(unsigned int *)(v15 + 12);
              if ( (unsigned int)v18 <= 8 && cpucp_map[16 * v18] == 1 )
                break;
            }
          }
          _CF = v12++ >= v11;
          v15 += 40;
          if ( _CF )
          {
            if ( (v13 & 1) == 0 )
              goto LABEL_52;
            goto LABEL_51;
          }
        }
        if ( (v9 & 1) != 0 )
        {
          v19 = *(_DWORD *)(v15 + 8);
          if ( (unsigned int)v19 > 3 )
          {
            v21 = *(_QWORD *)(v15 - 16);
            if ( v21 )
            {
              perf_event_read_local(v21);
              StatusReg = 0;
              v14 = &loc_8000;
            }
            else
            {
              StatusReg = *(_QWORD *)v15;
            }
          }
          else if ( v19 > 1 )
          {
            if ( v19 == 2 )
              StatusReg = _ReadStatusReg(AMEVCNTR02_EL0);
            else
              StatusReg = _ReadStatusReg(AMEVCNTR03_EL0);
          }
          else if ( v19 )
          {
            StatusReg = _ReadStatusReg(AMEVCNTR00_EL0);
          }
          else
          {
            StatusReg = _ReadStatusReg(AMEVCNTR01_EL0);
          }
          *(_QWORD *)v15 = StatusReg;
        }
        else
        {
          StatusReg = *(_QWORD *)v15;
        }
        if ( v16 >= 4 )
        {
          if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v15 - 16) + 152LL) + 328LL) < 6u )
          {
            v22 = v14;
            LODWORD(StatusReg) = StatusReg | 0x80000000;
          }
          else
          {
            v22 = v14;
            if ( v14[3520] )
              v23 = 0;
            else
              v23 = 0x80000000;
            LODWORD(StatusReg) = v23 | StatusReg;
          }
        }
        else
        {
          v22 = v14;
        }
        writel_relaxed(StatusReg, (unsigned int *)(v7 + 4 * v18));
        v11 = *(unsigned int *)(v5 + 328);
        v13 = 1;
        v14 = v22;
        if ( v12 < v11 )
          continue;
        break;
      }
LABEL_51:
      writel_relaxed(1u, (unsigned int *)(v7 + 36));
    }
  }
LABEL_52:
  if ( v9 )
  {
    _X8 = (unsigned int *)(v5 + 332);
    __asm { PRFM            #0x11, [X8] }
    do
      v26 = __ldxr(_X8);
    while ( __stxr(v26 - 1, _X8) );
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return 1;
}
