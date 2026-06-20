__int64 __fastcall adreno_queue_recurring_cmd(__int64 *a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v4; // x8
  __int64 result; // x0
  __int64 v6; // x20
  __int64 (__fastcall *v9)(__int64, __int64); // x8
  unsigned int v10; // w20
  unsigned int v11; // w20
  unsigned __int64 v18; // x9
  _QWORD v19[2]; // [xsp+0h] [xbp-10h] BYREF

  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a1;
  v19[0] = a3;
  v4 = *(_QWORD *)(v3 + 14264);
  if ( (*(_BYTE *)(v4 + 33) & 0x80) == 0 )
  {
    result = 4294967201LL;
    goto LABEL_8;
  }
  v6 = *(_QWORD *)(v4 + 40);
  if ( !*(_QWORD *)(v6 + 224) )
  {
    result = 4294967277LL;
    goto LABEL_8;
  }
  result = adreno_verify_cmdobj(a1, a2, (__int64)v19, 1u);
  if ( !(_DWORD)result )
  {
    rt_mutex_lock(v3 + 11088);
    if ( *(_QWORD *)(v3 + 22840) )
    {
      rt_mutex_unlock(v3 + 11088);
      result = 4294967274LL;
      goto LABEL_8;
    }
    if ( !a2 || (*(_QWORD *)(a2 + 32) & 4) != 0 )
    {
      v11 = -35;
    }
    else
    {
      if ( (*(_QWORD *)(a2 + 32) & 2) == 0 )
      {
        _X8 = (unsigned __int64 *)(a3 + 56);
        __asm { PRFM            #0x11, [X8] }
        do
          v18 = __ldxr(_X8);
        while ( __stxr(v18 | 0x20, _X8) );
        v9 = *(__int64 (__fastcall **)(__int64, __int64))(v6 + 224);
        if ( *((_DWORD *)v9 - 1) != -348536088 )
          __break(0x8228u);
        v10 = v9(v3, a3);
        rt_mutex_unlock(v3 + 11088);
        result = v10;
        if ( !v10 )
        {
          srcu_notifier_call_chain(v3 + 13424, 0, 0);
          result = 0;
        }
        goto LABEL_8;
      }
      v11 = -2;
    }
    rt_mutex_unlock(v3 + 11088);
    result = v11;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
