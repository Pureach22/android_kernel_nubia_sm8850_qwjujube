__int64 __fastcall _qcom_pmu_read_all(unsigned int a1, __int64 a2)
{
  __int64 v4; // x21
  __int64 v5; // x1
  int v6; // w22
  unsigned __int64 v7; // x24
  signed int v8; // w23
  _QWORD *v9; // x26
  __int64 event; // x0
  int v11; // w9
  unsigned int v15; // w10
  unsigned int v21; // w9

  if ( qcom_pmu_inited != 1 )
    return 4294967277LL;
  if ( !a2 )
    return 4294967274LL;
  _X8 = (unsigned int *)a1;
  if ( ((*(_QWORD *)((char *)&_cpu_possible_mask + (((unsigned __int64)a1 >> 3) & 0x1FFFFFF8)) >> a1) & 1) == 0 )
    return 4294967274LL;
  if ( a1 >= 0x20 )
    goto LABEL_27;
  v4 = *(_QWORD *)((char *)&cpu_ev_data + _per_cpu_offset[a1]);
  v5 = raw_spin_lock_irqsave(v4 + 336);
  if ( (*(_BYTE *)(v4 + 1) & 1) != 0 || (*(_BYTE *)v4 & 1) != 0 || (*(_BYTE *)(v4 + 2) & 1) != 0 )
  {
    v6 = 1;
  }
  else
  {
    _X8 = (unsigned int *)(v4 + 332);
    __asm { PRFM            #0x11, [X8] }
    do
      v21 = __ldxr(_X8);
    while ( __stxr(v21 + 1, _X8) );
    v6 = 0;
  }
  raw_spin_unlock_irqrestore(v4 + 336, v5);
  _X8 = (unsigned int *)*(unsigned int *)(v4 + 328);
  if ( (_DWORD)_X8 )
  {
    v7 = 0;
    v8 = 0;
    v9 = (_QWORD *)(v4 + 32);
    while ( v7 != 9 )
    {
      v11 = *((_DWORD *)v9 - 6);
      if ( v11 )
      {
        if ( (unsigned int)v8 > 7 )
          break;
        *(_DWORD *)(a2 + 4LL * v8) = v11;
        if ( v6 )
          event = *v9;
        else
          event = read_event();
        *(_QWORD *)(a2 + 32 + 8LL * v8++) = event;
        _X8 = (unsigned int *)*(unsigned int *)(v4 + 328);
      }
      ++v7;
      v9 += 5;
      if ( v7 >= (unsigned __int64)_X8 )
        goto LABEL_22;
    }
LABEL_27:
    __break(0x5512u);
    goto LABEL_28;
  }
  v8 = 0;
LABEL_22:
  *(_DWORD *)(a2 + 96) = v8;
  if ( (v6 & 1) != 0 )
    return 0;
  _X8 = (unsigned int *)(v4 + 332);
LABEL_28:
  __asm { PRFM            #0x11, [X8] }
  do
    v15 = __ldxr(_X8);
  while ( __stxr(v15 - 1, _X8) );
  return 0;
}
