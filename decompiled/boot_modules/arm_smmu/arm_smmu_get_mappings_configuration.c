__int64 __fastcall arm_smmu_get_mappings_configuration(__int64 a1)
{
  __int64 v1; // x19
  unsigned int v3; // w20

  v1 = a1 - 104;
  mutex_lock(a1 - 104);
  if ( *(_QWORD *)(a1 - 184) )
    v3 = *(_BYTE *)(a1 - 47) & 7;
  else
    v3 = -1;
  mutex_unlock(v1);
  return v3;
}
