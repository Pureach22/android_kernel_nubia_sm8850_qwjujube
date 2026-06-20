__int64 __fastcall gen8_hwsched_preempt_count_get(__int64 a1)
{
  __int64 v2; // x0
  int vrb_register; // w8
  __int64 result; // x0
  unsigned int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 8664);
  v5 = 0;
  vrb_register = gmu_core_get_vrb_register(v2, 5, &v5);
  result = 0;
  if ( !vrb_register )
  {
    result = v5;
    if ( !v5 )
    {
      if ( *(_DWORD *)(a1 + 11120) == 2 )
        result = gen8_hwsched_hfi_get_value((_QWORD *)a1, 120, 0);
      else
        result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
