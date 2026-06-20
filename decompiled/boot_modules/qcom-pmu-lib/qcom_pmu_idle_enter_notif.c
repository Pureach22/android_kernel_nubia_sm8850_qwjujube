__int64 __fastcall qcom_pmu_idle_enter_notif(__int64 a1, unsigned int *a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v6; // x22
  __int64 v7; // x1
  __int64 result; // x0
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x25
  unsigned __int64 v12; // x24
  int *v13; // x28
  int v14; // w1
  unsigned __int64 StatusReg; // x8
  _UNKNOWN **v16; // x22
  _DWORD *v17; // x8
  __int64 v18; // x1
  __int64 v19; // x2
  unsigned int v25; // w8
  unsigned int v27; // w9
  _QWORD v28[4]; // [xsp+10h] [xbp-70h] BYREF
  _QWORD v29[8]; // [xsp+30h] [xbp-50h] BYREF
  __int64 v30; // [xsp+70h] [xbp-10h]
  __int64 v31; // [xsp+78h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(unsigned int *)(a3 + 4);
  if ( (unsigned int)v3 >= 0x20 )
LABEL_33:
    __break(0x5512u);
  v6 = *(_QWORD *)((char *)&cpu_ev_data + _per_cpu_offset[v3]);
  v30 = 0;
  memset(v29, 0, sizeof(v29));
  memset(v28, 0, sizeof(v28));
  v7 = raw_spin_lock_irqsave(v6 + 336);
  if ( (*(_BYTE *)v6 & 1) != 0 || (*(_BYTE *)(v6 + 1) & 1) != 0 || *(_BYTE *)(v6 + 2) == 1 )
  {
    result = raw_spin_unlock_irqrestore(v6 + 336, v7);
    goto LABEL_6;
  }
  _X23 = (unsigned int *)(v6 + 332);
  *(_BYTE *)v6 = 1;
  __asm { PRFM            #0x11, [X23] }
  do
    v25 = __ldxr(_X23);
  while ( __stxr(v25 + 1, _X23) );
  result = raw_spin_unlock_irqrestore(v6 + 336, v7);
  v10 = *(unsigned int *)(v6 + 328);
  if ( (_DWORD)v10 )
  {
    v11 = 0;
    v12 = 0;
    v13 = (int *)(v6 + 40);
    while ( 1 )
    {
      if ( v11 == 9 )
        goto LABEL_33;
      if ( *(v13 - 8) )
        break;
LABEL_10:
      ++v11;
      v13 += 10;
      if ( v11 >= v10 )
        goto LABEL_27;
    }
    v14 = *v13;
    result = *((_QWORD *)v13 - 3);
    if ( result )
    {
      if ( (unsigned int)v14 > 3 )
      {
        result = perf_event_read_local(result);
        StatusReg = 0;
LABEL_24:
        *((_QWORD *)v13 - 1) = StatusReg;
        if ( v12 > 7 )
          goto LABEL_33;
        *((_DWORD *)v28 + v12) = *(v13 - 8);
        v29[v12++] = StatusReg;
        v10 = *(unsigned int *)(v6 + 328);
        goto LABEL_10;
      }
    }
    else if ( (unsigned int)v14 > 3 )
    {
      goto LABEL_10;
    }
    if ( v14 > 1 )
    {
      if ( v14 == 2 )
        StatusReg = _ReadStatusReg(AMEVCNTR02_EL0);
      else
        StatusReg = _ReadStatusReg(AMEVCNTR03_EL0);
    }
    else if ( v14 )
    {
      StatusReg = _ReadStatusReg(AMEVCNTR00_EL0);
    }
    else
    {
      StatusReg = _ReadStatusReg(AMEVCNTR01_EL0);
    }
    goto LABEL_24;
  }
  LODWORD(v12) = 0;
LABEL_27:
  __asm { PRFM            #0x11, [X23] }
  do
    v27 = __ldxr(_X23);
  while ( __stxr(v27 - 1, _X23) );
  LODWORD(v30) = v12;
  v16 = (_UNKNOWN **)idle_notif_list;
  if ( idle_notif_list != (_UNKNOWN *)&idle_notif_list )
  {
    do
    {
      v17 = *(v16 - 1);
      v18 = *(unsigned int *)(a3 + 4);
      v19 = *a2;
      if ( *(v17 - 1) != 903771107 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64))v17)(v28, v18, v19);
      v16 = (_UNKNOWN **)*v16;
    }
    while ( v16 != &idle_notif_list );
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
