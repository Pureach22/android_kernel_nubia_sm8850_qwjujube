__int64 __fastcall arm_smmu_get_asid_nr(__int64 a1)
{
  __int64 v1; // x19
  unsigned int v3; // w20

  v1 = a1 - 104;
  mutex_lock(a1 - 104);
  if ( *(_QWORD *)(a1 - 184) )
    v3 = *(unsigned __int16 *)(a1 - 134);
  else
    v3 = -22;
  mutex_unlock(v1);
  return v3;
}
