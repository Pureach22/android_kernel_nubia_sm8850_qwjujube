unsigned int *__fastcall gen8_hwsched_set_pwrconstraint(__int64 a1, unsigned int a2)
{
  unsigned int v5; // w22
  unsigned int v11; // w8
  __int64 v12; // x20
  unsigned int *result; // x0
  int v14; // w8
  int v15; // w9
  int v16; // w10
  int v17; // w21
  int v18; // w8
  int v20; // w8
  __int64 v21; // [xsp+8h] [xbp-18h] BYREF
  __int64 v22; // [xsp+10h] [xbp-10h]
  __int64 v23; // [xsp+18h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  raw_read_lock(a1 + 11208);
  _X0 = idr_find(a1 + 11184, a2);
  if ( !_X0 || (*(_QWORD *)(_X0 + 32) & 2) != 0 )
  {
    result = (unsigned int *)raw_read_unlock(a1 + 11208);
  }
  else
  {
    v5 = *(_DWORD *)_X0;
    if ( *(_DWORD *)_X0 )
    {
      do
      {
        __asm { PRFM            #0x11, [X0] }
        do
          v11 = __ldxr((unsigned int *)_X0);
        while ( v11 == v5 && __stxr(v5 + 1, (unsigned int *)_X0) );
        if ( v11 == v5 )
          break;
        v5 = v11;
      }
      while ( v11 );
    }
    v12 = _X0;
    if ( (((v5 + 1) | v5) & 0x80000000) != 0 )
      refcount_warn_saturate(_X0, 0);
    result = (unsigned int *)raw_read_unlock(a1 + 11208);
    if ( v5 )
    {
      v14 = *(unsigned __int8 *)(v12 + 288);
      result = (unsigned int *)v12;
      v21 = 0;
      v22 = 0;
      if ( v14 == 1 && *(_DWORD *)(a1 + 11120) == 2 )
      {
        v15 = *(_DWORD *)(v12 + 4);
        LODWORD(v21) = 140;
        HIDWORD(v21) = v15;
        v16 = *(_DWORD *)(v12 + 212);
        LODWORD(v22) = *(_DWORD *)(v12 + 208);
        HIDWORD(v22) = v16;
        v17 = gen8_hfi_send_cmd_async(a1, &v21, 16);
        result = (unsigned int *)v12;
        if ( v17 )
        {
          v18 = __ratelimit(&gen8_hwsched_set_pwrconstraint__rs, "gen8_hwsched_set_pwrconstraint");
          result = (unsigned int *)v12;
          if ( v18 )
          {
            dev_err(
              *(_QWORD *)(a1 + 1544) + 16LL,
              "Failed to set perf hint type %d, sub type %d for context %d, ret: %d\n",
              v22,
              HIDWORD(v22),
              HIDWORD(v21),
              v17);
            result = (unsigned int *)v12;
          }
        }
      }
      __asm { PRFM            #0x11, [X0] }
      do
        v20 = __ldxr(result);
      while ( __stlxr(v20 - 1, result) );
      if ( v20 == 1 )
      {
        __dmb(9u);
        result = (unsigned int *)kgsl_context_destroy(result);
      }
      else if ( v20 <= 0 )
      {
        result = (unsigned int *)refcount_warn_saturate(result, 3);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
