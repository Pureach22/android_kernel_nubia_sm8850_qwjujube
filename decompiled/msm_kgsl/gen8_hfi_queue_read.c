__int64 __fastcall gen8_hfi_queue_read(__int64 a1, unsigned int a2, void *a3, unsigned int a4)
{
  __int64 v8; // x0
  __int64 v9; // x21
  __int64 v10; // x23
  _DWORD *v11; // x23
  int v12; // t1
  __int64 result; // x0
  __int64 v14; // x24
  __int64 v15; // x8
  int v16; // w20
  unsigned int v17; // w22
  unsigned int v18; // w3
  __int64 v19; // x9
  _DWORD *v20; // x10
  unsigned __int64 StatusReg; // x22
  unsigned int v22; // w19
  __int64 v23; // x0
  __int64 v24; // x8

  v8 = gen8_gmu_to_adreno(a1);
  if ( a2 >= 0x12 )
  {
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v22 = v8;
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v23 = _traceiter_kgsl_hfi_receive(0, (unsigned __int8)a2, (unsigned int)a1);
      v24 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v24;
      if ( !v24 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v23);
    }
    return v22;
  }
  else
  {
    v9 = *(_QWORD *)(a1 + 48);
    v10 = *(_QWORD *)(v9 + 8) + 48LL * a2;
    v12 = *(_DWORD *)(v10 + 24);
    v11 = (_DWORD *)(v10 + 24);
    if ( v12 )
    {
      if ( v11[10] == v11[11] )
      {
        return 4294967235LL;
      }
      else
      {
        v14 = v8;
        memset(a3, 0, a4);
        v15 = *(_QWORD *)(v9 + 8) + (a2 << 12) + 848LL;
        v16 = *(_DWORD *)(v15 + 4LL * (unsigned int)v11[10]);
        if ( BYTE1(v16) > a4 >> 2 )
        {
          dev_err(*(_QWORD *)(v14 + 1544) + 16LL, "HFI message too big: hdr:0x%x rd idx=%d\n", v16, v11[10]);
          return 4294967206LL;
        }
        else
        {
          v17 = v11[10];
          v18 = v11[3];
          if ( v17 >= v18 )
          {
            dev_err(*(_QWORD *)(v14 + 1544) + 16LL, "Read index %d greater than queue size %d\n", v11[10], v18);
            v18 = v11[3];
            result = 4294967235LL;
          }
          else if ( BYTE1(v16) )
          {
            v19 = BYTE1(v16);
            v20 = a3;
            do
            {
              --v19;
              *v20++ = *(_DWORD *)(v15 + 4LL * v17);
              v18 = v11[3];
              v17 = (v17 + 1) % v18;
            }
            while ( v19 );
            result = BYTE1(v16);
          }
          else
          {
            result = 0;
          }
          __dsb(0xFu);
          v11[10] = ((v17 + 3) & 0xFFFFFFFC) % v18;
        }
      }
    }
    else
    {
      return 4294967274LL;
    }
  }
  return result;
}
