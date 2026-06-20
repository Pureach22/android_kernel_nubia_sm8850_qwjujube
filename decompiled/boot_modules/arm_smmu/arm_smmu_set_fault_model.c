__int64 __fastcall arm_smmu_set_fault_model(__int64 a1, char a2)
{
  __int64 v2; // x19
  unsigned int v5; // w20

  v2 = a1 - 104;
  mutex_lock(a1 - 104);
  if ( *(_QWORD *)(a1 - 184) )
  {
    v5 = -1;
  }
  else
  {
    v5 = 0;
    *(_BYTE *)(a1 - 48) = *(_BYTE *)(a1 - 48) & 0xF0 | a2 & 0xF;
  }
  mutex_unlock(v2);
  return v5;
}
