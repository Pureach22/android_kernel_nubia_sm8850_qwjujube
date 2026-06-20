__int64 *__fastcall rmnet_sch_dequeue(__int64 a1)
{
  int v1; // w9
  unsigned int v2; // w8
  __int64 v3; // x8
  __int64 *v4; // x19
  __int64 v5; // x9
  int v6; // w10
  int v7; // w10
  char v8; // w11
  __int64 v9; // x8
  __int64 v10; // x9
  __int64 v11; // x8
  unsigned __int64 StatusReg; // x20
  __int64 v13; // x8
  unsigned __int64 v14; // x9
  int v15; // w10
  unsigned int *v16; // x8
  unsigned int v17; // w11
  __int64 v18; // x8
  __int64 v19; // x8
  unsigned __int64 v20; // x9
  __int64 v21; // x10
  __int64 v22; // x11
  __int64 v23; // x10
  __int64 v24; // x8
  unsigned int *v25; // x8
  unsigned int v26; // w11
  __int64 v27; // x8
  unsigned __int64 v35; // x11
  unsigned __int64 v38; // x10
  unsigned __int64 v41; // x13
  unsigned __int64 v44; // x9
  __int64 v45; // [xsp+8h] [xbp-8h]

  v1 = *(_DWORD *)(a1 + 400);
  if ( v1 )
  {
    if ( *(int *)(a1 + 408) >= 1 )
    {
      v2 = 0;
      if ( *(int *)(a1 + 412) > 0 )
        goto LABEL_25;
    }
    v2 = 0;
    if ( !*(_DWORD *)(a1 + 440) )
    {
LABEL_5:
      if ( !*(_DWORD *)(a1 + 480) )
        goto LABEL_6;
LABEL_13:
      if ( *(int *)(a1 + 488) >= 1 && *(int *)(a1 + 492) > 0 )
      {
        v2 = 2;
        goto LABEL_25;
      }
      if ( v2 >= 2 )
        v2 = 2;
      if ( !*(_DWORD *)(a1 + 520) )
        goto LABEL_24;
LABEL_19:
      if ( *(int *)(a1 + 528) >= 1 && *(int *)(a1 + 532) > 0 )
      {
        v2 = 3;
        goto LABEL_25;
      }
      if ( v2 >= 3 )
        v2 = 3;
      goto LABEL_24;
    }
  }
  else
  {
    v2 = 4;
    if ( !*(_DWORD *)(a1 + 440) )
      goto LABEL_5;
  }
  if ( *(int *)(a1 + 448) >= 1 && *(int *)(a1 + 452) > 0 )
  {
    v2 = 1;
    goto LABEL_25;
  }
  v2 = v1 == 0;
  if ( *(_DWORD *)(a1 + 480) )
    goto LABEL_13;
LABEL_6:
  if ( *(_DWORD *)(a1 + 520) )
    goto LABEL_19;
LABEL_24:
  *(_QWORD *)(a1 + 408) = 0x4000000000008LL;
  *(_QWORD *)(a1 + 448) = 0x2000000000006LL;
  *(_QWORD *)(a1 + 488) = 0x1000000000004LL;
  *(_QWORD *)(a1 + 528) = 0x800000000002LL;
  if ( v2 > 3 )
    return nullptr;
LABEL_25:
  v3 = a1 + 384 + 40LL * v2;
  v4 = *(__int64 **)v3;
  if ( *(_QWORD *)v3 )
  {
    v5 = *v4;
    v6 = *(_DWORD *)(v3 + 16) - 1;
    *(_QWORD *)v3 = *v4;
    *(_DWORD *)(v3 + 16) = v6;
    if ( !v5 )
      *(_QWORD *)(v3 + 8) = 0;
    *v4 = 0;
    v7 = *(_DWORD *)(v3 + 28);
    v8 = *(_BYTE *)(a1 + 16);
    --*(_DWORD *)(v3 + 24);
    *(_DWORD *)(v3 + 28) = v7 - *((_DWORD *)v4 + 10);
    if ( (v8 & 0x20) != 0 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(StatusReg + 16);
      v13 = *(_QWORD *)(a1 + 88);
      v14 = _ReadStatusReg(TPIDR_EL1);
      v15 = -*((_DWORD *)v4 + 10);
      v16 = (unsigned int *)(v13 + v14 + 4);
      do
        v17 = __ldxr(v16);
      while ( __stxr(v17 + v15, v16) );
      v18 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v18;
      if ( !v18 || !*(_QWORD *)(StatusReg + 16) )
      {
        v45 = a1;
        preempt_schedule_notrace();
        a1 = v45;
      }
      v19 = *(_QWORD *)(a1 + 80);
      v20 = _ReadStatusReg(TPIDR_EL1);
      v21 = v4[27] + *((unsigned int *)v4 + 53);
      v22 = *((unsigned int *)v4 + 10);
      if ( *(_WORD *)(v21 + 4) )
        v23 = *(unsigned __int16 *)(v21 + 6);
      else
        v23 = 1;
      _X12 = (unsigned __int64 *)(v19 + v20);
      __asm { PRFM            #0x11, [X12] }
      do
        v41 = __ldxr(_X12);
      while ( __stxr(v41 + v22, _X12) );
      _X8 = (unsigned __int64 *)(v20 + v19 + 8);
      __asm { PRFM            #0x11, [X8] }
      do
        v44 = __ldxr(_X8);
      while ( __stxr(v44 + v23, _X8) );
      ++*(_DWORD *)(StatusReg + 16);
      v24 = *(_QWORD *)(a1 + 88);
      v25 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v24);
      do
        v26 = __ldxr(v25);
      while ( __stxr(v26 - 1, v25) );
      v27 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v27;
      if ( !v27 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace();
    }
    else
    {
      *(_DWORD *)(a1 + 196) -= *((_DWORD *)v4 + 10);
      v9 = v4[27] + *((unsigned int *)v4 + 53);
      v10 = *((unsigned int *)v4 + 10);
      if ( *(_WORD *)(v9 + 4) )
        v11 = *(unsigned __int16 *)(v9 + 6);
      else
        v11 = 1;
      _X10 = (unsigned __int64 *)(a1 + 176);
      __asm { PRFM            #0x11, [X10] }
      do
        v35 = __ldxr(_X10);
      while ( __stxr(v35 + v10, _X10) );
      _X9 = (unsigned __int64 *)(a1 + 184);
      __asm { PRFM            #0x11, [X9] }
      do
        v38 = __ldxr(_X9);
      while ( __stxr(v38 + v11, _X9) );
      --*(_DWORD *)(a1 + 168);
    }
  }
  return v4;
}
