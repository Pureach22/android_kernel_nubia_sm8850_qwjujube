__int64 __fastcall stm_enable(__int64 a1, __int64 a2, int a3)
{
  _DWORD *v3; // x20
  unsigned __int64 v11; // x8
  __int64 v12; // x19
  unsigned int v13; // w8
  __int64 v14; // x19
  __int64 v15; // x22
  __int64 v16; // x19
  unsigned int v17; // w0
  int v18; // w10
  __int64 v19; // x9
  int v20; // w10
  __int64 v21; // x8
  __int64 v22; // x8
  unsigned int v23; // w9
  unsigned int v24; // w21
  unsigned int v27; // w11
  __int64 v28; // x0
  unsigned int v29; // w19

  if ( a3 != 1 )
    return 4294967274LL;
  v3 = *(_DWORD **)(*(_QWORD *)(a1 + 152) + 152LL);
  _X10 = (unsigned __int64 *)(a1 + 968);
  __asm { PRFM            #0x11, [X10] }
  while ( 1 )
  {
    v11 = __ldxr(_X10);
    if ( v11 )
      break;
    if ( !__stlxr(1u, _X10) )
    {
      __dmb(0xBu);
      break;
    }
  }
  if ( v11 )
    return 4294967280LL;
  if ( *((_BYTE *)v3 + 176) == 1
    && (v12 = a1, v13 = coresight_trace_id_reserve_id(*((unsigned __int8 *)v3 + 144)), a1 = v12, v13) )
  {
    *(_QWORD *)(v12 + 968) = 0;
    v28 = v12 + 56;
    v29 = v13;
    dev_err(v28, "reserve ATID: %d fail\n", *((unsigned __int8 *)v3 + 144));
    return v29;
  }
  else
  {
    v14 = a1;
    ((void (*)(void))coresight_csr_set_etr_atid)();
    v15 = v14;
    v16 = *(_QWORD *)(v14 + 152);
    v17 = _pm_runtime_resume(v16, 4);
    if ( (v17 & 0x80000000) != 0 )
    {
      v23 = *(_DWORD *)(v16 + 480);
      v24 = v17;
      do
      {
        if ( !v23 )
          break;
        _X13 = (unsigned int *)(v16 + 480);
        __asm { PRFM            #0x11, [X13] }
        while ( 1 )
        {
          v27 = __ldxr(_X13);
          if ( v27 != v23 )
            break;
          if ( !__stlxr(v23 - 1, _X13) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v27 == v23;
        v23 = v27;
      }
      while ( !_ZF );
      coresight_csr_set_etr_atid(v15, *((unsigned __int8 *)v3 + 144), 0, 0);
      *(_QWORD *)(v15 + 968) = 0;
      return v24;
    }
    else
    {
      raw_spin_lock(v3 + 8);
      if ( v3[41] )
      {
        *(_DWORD *)(*(_QWORD *)v3 + 4016LL) = -978530731;
        __dsb(0xFu);
        v18 = v3[42];
        *(_DWORD *)(*(_QWORD *)v3 + 3424LL) = v3[43];
        *(_DWORD *)(*(_QWORD *)v3 + 3360LL) = v18;
        *(_DWORD *)(*(_QWORD *)v3 + 3328LL) = v3[41];
        *(_DWORD *)(*(_QWORD *)v3 + 3428LL) = 5;
        v19 = *(_QWORD *)v3;
        __dsb(0xFu);
        *(_DWORD *)(v19 + 4016) = 0;
      }
      *(_DWORD *)(*(_QWORD *)v3 + 4016LL) = -978530731;
      __dsb(0xFu);
      *(_DWORD *)(*(_QWORD *)v3 + 3696LL) = 16;
      v20 = v3[38];
      *(_DWORD *)(*(_QWORD *)v3 + 3680LL) = v3[39];
      *(_DWORD *)(*(_QWORD *)v3 + 3584LL) = v20;
      v21 = *(_QWORD *)v3;
      __dsb(0xFu);
      *(_DWORD *)(v21 + 4016) = 0;
      *(_DWORD *)(*(_QWORD *)v3 + 4016LL) = -978530731;
      __dsb(0xFu);
      *(_DWORD *)(*(_QWORD *)v3 + 3728LL) = 4095;
      *(_DWORD *)(*(_QWORD *)v3 + 3712LL) = (*((unsigned __int8 *)v3 + 144) << 16) | 3;
      v22 = *(_QWORD *)v3;
      __dsb(0xFu);
      *(_DWORD *)(v22 + 4016) = 0;
      raw_spin_unlock(v3 + 8);
      return 0;
    }
  }
}
