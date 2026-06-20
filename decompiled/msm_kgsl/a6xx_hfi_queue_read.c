__int64 __fastcall a6xx_hfi_queue_read(__int64 a1, unsigned int a2, void *a3, unsigned int a4)
{
  _DWORD *v4; // x24
  __int64 result; // x0
  __int64 v10; // x21
  __int64 v11; // x24
  int v12; // t1
  __int64 v13; // x22
  __int64 v14; // x8
  int v15; // w20
  unsigned int v16; // w3
  __int64 v17; // x9
  _DWORD *v18; // x10
  unsigned __int64 StatusReg; // x19
  __int64 v20; // x1
  unsigned int v21; // w20
  __int64 v22; // x8

  result = a6xx_gmu_to_adreno(a1);
  if ( a2 >= 0x12 )
  {
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      v20 = (unsigned __int8)a2;
      v21 = result;
      ++*(_DWORD *)(StatusReg + 16);
      _traceiter_kgsl_hfi_receive(0, v20, (unsigned int)a1);
      result = v21;
      v22 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v22;
      if ( !v22 || !*(_QWORD *)(StatusReg + 16) )
      {
        preempt_schedule_notrace(v21);
        result = v21;
      }
    }
  }
  else
  {
    v10 = *(_QWORD *)(a1 + 40);
    v11 = *(_QWORD *)(v10 + 8) + 48LL * a2;
    v12 = *(_DWORD *)(v11 + 24);
    v4 = (_DWORD *)(v11 + 24);
    if ( !v12 )
      return 4294967274LL;
    if ( v4[10] == v4[11] )
      return 4294967235LL;
    v13 = result;
    memset(a3, 0, a4);
    v14 = *(_QWORD *)(v10 + 8) + (a2 << 12) + 848LL;
    v15 = *(_DWORD *)(v14 + 4LL * (unsigned int)v4[10]);
    if ( BYTE1(v15) > a4 >> 2 )
    {
      dev_err(*(_QWORD *)(v13 + 1544) + 16LL, "HFI message too big: hdr:0x%x rd idx=%d\n", v15, v4[10]);
      return 4294967206LL;
    }
    a4 = v4[10];
    v16 = v4[3];
    if ( a4 >= v16 )
    {
      dev_err(*(_QWORD *)(v13 + 1544) + 16LL, "Read index %d greater than queue size %d\n", v4[10], v16);
      result = 4294967235LL;
    }
    else if ( BYTE1(v15) )
    {
      v17 = BYTE1(v15);
      v18 = a3;
      do
      {
        --v17;
        *v18++ = *(_DWORD *)(v14 + 4LL * a4);
        a4 = (a4 + 1) % v4[3];
      }
      while ( v17 );
      result = BYTE1(v15);
    }
    else
    {
      result = 0;
    }
    if ( *(_DWORD *)(v13 + 8280) >> 29 )
      a4 = ((a4 + 3) & 0xFFFFFFFC) % v4[3];
  }
  __dsb(0xFu);
  v4[10] = a4;
  return result;
}
