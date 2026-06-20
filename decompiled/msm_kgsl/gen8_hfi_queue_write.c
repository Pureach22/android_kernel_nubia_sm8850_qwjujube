__int64 __fastcall gen8_hfi_queue_write(__int64 a1, unsigned int a2, int *a3, unsigned int a4)
{
  __int64 v7; // x0
  _DWORD *v8; // x8
  unsigned int v9; // w9
  __int64 v10; // x8
  __int64 result; // x0
  __int64 v12; // x11
  __int64 v13; // x8
  int v14; // t1
  unsigned int v15; // w2
  unsigned int v16; // w10
  bool v17; // cc
  unsigned int v18; // w12
  unsigned int v19; // w10
  __int64 v20; // x11
  bool v21; // cf
  int v22; // w10
  unsigned int v23; // w12
  __int64 v24; // x13
  int *v25; // x14
  int v26; // t1
  unsigned int v27; // w12
  unsigned __int64 StatusReg; // x19
  _DWORD *v29; // x20
  unsigned int v30; // w21
  __int64 v31; // x0
  __int64 v32; // x10

  v7 = to_gen8_gmu(a1);
  if ( a2 >= 0x12 )
  {
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      v29 = v8;
      v30 = v9;
      ++*(_DWORD *)(StatusReg + 16);
      v31 = _traceiter_kgsl_hfi_send(0);
      v32 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v32;
      if ( !v32 || (v9 = v30, v8 = v29, !*(_QWORD *)(StatusReg + 16)) )
      {
        preempt_schedule_notrace(v31);
        v9 = v30;
        v8 = v29;
      }
    }
    goto LABEL_18;
  }
  v10 = v7;
  result = 4294967274LL;
  if ( (a4 & 3) == 0 )
  {
    v12 = *(_QWORD *)(*(_QWORD *)(v10 + 48) + 8LL);
    v13 = v12 + 48LL * a2;
    v14 = *(_DWORD *)(v13 + 24);
    v8 = (_DWORD *)(v13 + 24);
    if ( v14 )
    {
      v15 = a4 >> 2;
      v9 = v8[11];
      v16 = v8[10];
      v18 = v16 - v9;
      v17 = v16 > v9;
      v19 = ((a4 >> 2) + 3) & 0x7FFFFFFC;
      if ( !v17 )
        v18 += v8[3];
      if ( v18 <= v19 )
        return 4294967268LL;
      v20 = v12 + ((a2 << 12) | 0x350);
      if ( a4 >= 4 )
      {
        v23 = v8[3];
        v24 = a4 >> 2;
        v25 = a3;
        do
        {
          v26 = *v25++;
          *(_DWORD *)(v20 + 4LL * v9) = v26;
          --v24;
          v9 = (v9 + 1) % v23;
        }
        while ( v24 );
        v21 = v15 >= v19;
        v22 = v15 - v19;
        if ( v21 )
          goto LABEL_18;
      }
      else
      {
        v21 = v19 == 0;
        v22 = -v19;
        if ( v21 )
        {
LABEL_18:
          __dsb(0xEu);
          v8[11] = v9;
          result = 0;
          __dsb(0xEu);
          return result;
        }
      }
      v27 = v8[3];
      do
      {
        *(_DWORD *)(v20 + 4LL * v9) = -84215046;
        v21 = __CFADD__(v22++, 1);
        v9 = (v9 + 1) % v27;
      }
      while ( !v21 );
      goto LABEL_18;
    }
  }
  return result;
}
