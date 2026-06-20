__int64 *__fastcall cvp_get_inst_from_id(__int64 a1, int a2)
{
  __int64 *result; // x0
  int v5; // w21
  unsigned __int64 StatusReg; // x8
  __int64 *v7; // x8
  unsigned int v8; // w9
  unsigned int v10; // w20
  unsigned int v16; // w10
  __int64 *v17; // x20
  __int64 *v18; // x21

  result = nullptr;
  if ( a1 && a2 )
  {
    v5 = 1000;
    do
    {
      if ( (unsigned int)mutex_trylock(a1) )
      {
        v7 = (__int64 *)(a1 + 280);
        do
        {
          v7 = (__int64 *)*v7;
          if ( v7 == (__int64 *)(a1 + 280) )
          {
            v17 = nullptr;
            goto LABEL_29;
          }
        }
        while ( (*((_DWORD *)v7 + 81) ^ *((_DWORD *)v7 + 80)) != a2 );
        v8 = *((_DWORD *)v7 + 3706);
        _X0 = (unsigned int *)(v7 + 1853);
        if ( v8 )
        {
          do
          {
            __asm { PRFM            #0x11, [X0] }
            do
              v16 = __ldxr(_X0);
            while ( v16 == v8 && __stxr(v8 + 1, _X0) );
            v10 = v8;
            if ( v16 == v8 )
              break;
            v10 = 0;
            v8 = v16;
          }
          while ( v16 );
        }
        else
        {
          v10 = 0;
        }
        if ( (((v10 + 1) | v10) & 0x80000000) != 0 )
        {
          v18 = v7;
          refcount_warn_saturate();
          v7 = v18;
        }
        if ( v10 )
          v17 = v7;
        else
          v17 = nullptr;
LABEL_29:
        mutex_unlock(a1);
        return v17;
      }
      if ( !*(_DWORD *)(a1 + 304) )
        return nullptr;
      usleep_range_state(100, 200, 2);
      --v5;
    }
    while ( v5 );
    result = nullptr;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_92261, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return nullptr;
    }
  }
  return result;
}
