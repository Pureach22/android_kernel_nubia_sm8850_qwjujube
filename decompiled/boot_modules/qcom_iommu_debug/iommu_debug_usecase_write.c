__int64 __fastcall iommu_debug_usecase_write(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x20
  __int64 result; // x0
  __int64 v6; // x21
  unsigned int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  v7 = 0;
  if ( (unsigned int)kstrtouint_from_user(a2, a3, 0, &v7) )
  {
    result = -22;
  }
  else
  {
    result = -22;
    if ( v7 < *(_DWORD *)(v4 + 8) )
    {
      mutex_lock(v4 + 56);
      v6 = iommu_debug_switch_usecase((__int64 *)v4, v7);
      mutex_unlock(v4 + 56);
      result = -22;
      if ( v6 )
        result = a3;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
