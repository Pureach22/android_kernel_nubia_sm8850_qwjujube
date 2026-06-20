__int64 __fastcall rmnet_sch_enqueue(__int64 *a1, _DWORD *a2, __int64 **a3)
{
  int v3; // w20
  _DWORD *v4; // x19
  int v5; // w21
  _DWORD *v6; // x8
  _QWORD *v7; // x10
  int v8; // w9
  char v9; // w10
  int v11; // w9
  unsigned __int64 StatusReg; // x19
  __int64 v13; // x8
  unsigned int *v14; // x8
  unsigned int v15; // w11
  __int64 v16; // x8
  __int64 v17; // x8
  unsigned int *v18; // x8
  unsigned int v19; // w10
  __int64 v20; // x8
  __int64 *v21; // x23
  _DWORD *v23; // x22
  int v24; // w0
  unsigned __int16 v25; // w11
  __int64 v26; // x30
  unsigned int v27; // w8
  __int64 **v28; // x10
  __int64 **v29; // x8
  __int64 *v30; // x11
  int v31; // w12
  int v32; // w11
  _DWORD *v33; // x21

  v3 = *((_DWORD *)a1 + 10);
  v4 = a2 + 96;
  v5 = prio2queue[a1[18] & 0xF];
  if ( a2[42] >= *(_DWORD *)(**((_QWORD **)a2 + 8) + 1112LL) )
  {
    v21 = a1;
    v23 = a2;
    v24 = rmnet_sch_next_to_drop(a2 + 96);
    if ( v24 > 3 || (v27 = v24, v24 == v5) )
    {
      *v21 = (__int64)*a3;
      *a3 = v21;
      ++v23[50];
      return 1;
    }
    if ( (unsigned int)v24 > 3 )
    {
      __break(0x5512u);
      atomic_store(v25, (unsigned __int16 *)(v26 + 121));
      return rmnet_sch_dequeue();
    }
    a2 = v23;
    a1 = v21;
    v28 = (__int64 **)&v4[10 * v27];
    v29 = (__int64 **)*v28;
    if ( *v28 )
    {
      v30 = *v29;
      v31 = *((_DWORD *)v28 + 4) - 1;
      *v28 = *v29;
      *((_DWORD *)v28 + 4) = v31;
      if ( !v30 )
        v28[1] = nullptr;
      *v29 = nullptr;
      v32 = v23[42] - 1;
      v23[49] -= *((_DWORD *)v29 + 10);
      v23[42] = v32;
      *v29 = *a3;
      *a3 = (__int64 *)v29;
      ++v23[50];
    }
  }
  v6 = &v4[10 * v5];
  v7 = v6;
  if ( *((_QWORD *)v6 + 1) )
  {
    v7 = *((_QWORD **)v6 + 1);
    *a1 = 0;
  }
  *v7 = a1;
  v8 = v6[4];
  v9 = *((_BYTE *)a2 + 16);
  *((_QWORD *)v6 + 1) = a1;
  v6[4] = v8 + 1;
  if ( (v9 & 0x20) != 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(StatusReg + 16);
    v13 = *((_QWORD *)a2 + 11);
    v14 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v13);
    do
      v15 = __ldxr(v14);
    while ( __stxr(v15 + 1, v14) );
    v16 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v16;
    if ( !v16 || !*(_QWORD *)(StatusReg + 16) )
    {
      v33 = a2;
      preempt_schedule_notrace();
      a2 = v33;
    }
    ++*(_DWORD *)(StatusReg + 16);
    v17 = *((_QWORD *)a2 + 11);
    v18 = (unsigned int *)(v17 + _ReadStatusReg(TPIDR_EL1) + 4);
    do
      v19 = __ldxr(v18);
    while ( __stxr(v19 + v3, v18) );
    v20 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v20;
    if ( !v20 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace();
    return 0;
  }
  else
  {
    v11 = a2[42] + 1;
    a2[49] += v3;
    a2[42] = v11;
    return 0;
  }
}
