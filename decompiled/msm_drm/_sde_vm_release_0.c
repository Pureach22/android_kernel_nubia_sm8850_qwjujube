__int64 __fastcall sde_vm_release_0(__int64 a1)
{
  __int64 result; // x0
  unsigned int v3; // w19

  if ( !*(_QWORD *)(a1 + 6384) )
    return 0;
  sde_kms_vm_trusted_resource_deinit();
  if ( (unsigned int)sde_vm_release_irq(*(_QWORD *)(a1 + 6384)) )
    printk(&unk_272272, "_sde_vm_release");
  result = sde_vm_release_mem(*(_QWORD *)(a1 + 6384));
  if ( (_DWORD)result )
  {
    v3 = result;
    printk(&unk_23DF6F, "_sde_vm_release");
    return v3;
  }
  return result;
}
