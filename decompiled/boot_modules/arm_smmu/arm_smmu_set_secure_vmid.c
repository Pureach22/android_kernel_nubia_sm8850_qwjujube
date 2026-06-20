__int64 __fastcall arm_smmu_set_secure_vmid(__int64 a1, int a2)
{
  __int64 v2; // x19
  unsigned int v5; // w20

  v2 = a1 - 104;
  mutex_lock(a1 - 104);
  if ( *(_QWORD *)(a1 - 184) )
  {
    v5 = -1;
  }
  else if ( *(_DWORD *)(a1 - 44) == -1 )
  {
    v5 = 0;
    *(_DWORD *)(a1 - 44) = a2;
  }
  else
  {
    _warn_printk("secure vmid already set");
    __break(0x800u);
    v5 = -1;
  }
  mutex_unlock(v2);
  return v5;
}
