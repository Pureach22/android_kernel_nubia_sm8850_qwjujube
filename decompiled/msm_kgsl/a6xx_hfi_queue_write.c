__int64 __fastcall a6xx_hfi_queue_write(__int64 a1, unsigned int a2, int *a3, unsigned int a4)
{
  __int64 v8; // x0
  _DWORD *v9; // x8
  unsigned int v10; // w9
  __int64 v11; // x8
  __int64 result; // x0
  __int64 v13; // x11
  __int64 v14; // x8
  int v15; // t1
  unsigned int v16; // w10
  bool v17; // cc
  unsigned int v18; // w12
  unsigned int v19; // w10
  __int64 v20; // x11
  unsigned int v21; // w12
  unsigned int v22; // w12
  __int64 v23; // x13
  int *v24; // x14
  int v25; // t1
  bool v26; // cf
  unsigned int v27; // w10
  unsigned int v28; // w12
  unsigned __int64 StatusReg; // x19
  _DWORD *v30; // x20
  unsigned int v31; // w21
  __int64 v32; // x0
  __int64 v33; // x10

  v8 = to_a6xx_gmu(a1);
  if ( a2 >= 0x12 )
  {
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      v30 = v9;
      v31 = v10;
      ++*(_DWORD *)(StatusReg + 16);
      v32 = _traceiter_kgsl_hfi_send(0);
      v33 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v33;
      if ( !v33 || (v10 = v31, v9 = v30, !*(_QWORD *)(StatusReg + 16)) )
      {
        preempt_schedule_notrace(v32);
        v10 = v31;
        v9 = v30;
      }
    }
LABEL_18:
    __dsb(0xEu);
    v9[11] = v10;
    result = 0;
    __dsb(0xEu);
    return result;
  }
  v11 = v8;
  result = 4294967274LL;
  if ( (a4 & 3) == 0 )
  {
    v13 = *(_QWORD *)(*(_QWORD *)(v11 + 40) + 8LL);
    v14 = v13 + 48LL * a2;
    v15 = *(_DWORD *)(v14 + 24);
    v9 = (_DWORD *)(v14 + 24);
    if ( v15 )
    {
      v10 = v9[11];
      v16 = v9[10];
      v18 = v16 - v10;
      v17 = v16 > v10;
      v19 = ((a4 >> 2) + 3) & 0x7FFFFFFC;
      if ( !v17 )
        v18 += v9[3];
      if ( v18 <= v19 )
        return 4294967268LL;
      v20 = v13 + ((a2 << 12) | 0x350);
      if ( a4 >= 4 )
      {
        v22 = v9[3];
        v23 = a4 >> 2;
        v24 = a3;
        do
        {
          v25 = *v24++;
          *(_DWORD *)(v20 + 4LL * v10) = v25;
          --v23;
          v10 = (v10 + 1) % v22;
        }
        while ( v23 );
        v21 = a4 >> 2;
      }
      else
      {
        v21 = 0;
      }
      if ( *(_DWORD *)(a1 + 8280) >> 29 )
      {
        v26 = v21 >= v19;
        v27 = v21 - v19;
        if ( !v26 )
        {
          v28 = v9[3];
          do
          {
            *(_DWORD *)(v20 + 4LL * v10) = -84215046;
            v26 = __CFADD__(v27++, 1);
            v10 = (v10 + 1) % v28;
          }
          while ( !v26 );
        }
      }
      goto LABEL_18;
    }
  }
  return result;
}
