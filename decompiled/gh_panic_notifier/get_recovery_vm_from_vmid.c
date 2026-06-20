__int64 __fastcall get_recovery_vm_from_vmid(__int64 a1)
{
  unsigned __int16 v1; // w19
  unsigned int vm_name; // w0
  __int64 result; // x0
  unsigned int v4; // w8
  int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v1 = a1;
  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 0;
  vm_name = gh_rm_get_vm_name(a1, &v5);
  if ( vm_name )
  {
    printk(&unk_766D, v1, vm_name);
    result = 0;
    goto LABEL_7;
  }
  if ( v5 == 2 )
  {
    v4 = 0;
    goto LABEL_6;
  }
  result = 0;
  if ( v5 == 4 )
  {
    v4 = 1;
LABEL_6:
    result = recovery_vms + 40LL * v4;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
