__int64 __fastcall arm_smmu_enable_nesting(__int64 a1)
{
  __int64 v1; // x19
  unsigned int v3; // w20

  v1 = a1 - 104;
  mutex_lock(a1 - 104);
  if ( *(_QWORD *)(a1 - 184) )
  {
    v3 = -1;
  }
  else
  {
    v3 = 0;
    *(_DWORD *)(a1 - 112) = 2;
  }
  mutex_unlock(v1);
  return v3;
}
