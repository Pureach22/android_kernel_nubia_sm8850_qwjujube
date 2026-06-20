__int64 __fastcall rm_boost_target_cpu_set(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  unsigned int v5; // w21
  signed int v6; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v7; // [xsp+10h] [xbp-10h]
  __int64 v8; // [xsp+18h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = 0;
  result = kstrtouint(a1, 10, &v6);
  if ( !(_DWORD)result )
  {
    v5 = v6;
    if ( v5 >= (unsigned int)_sw_hweight64(_cpu_possible_mask) )
    {
      result = 4294967274LL;
    }
    else
    {
      result = param_set_int(a1, a2);
      if ( !(_DWORD)result && rm_status )
      {
        v7 = v6;
        smp_call_function_single();
        result = 0;
        *(_QWORD *)(rm_status + 24) = v7;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
