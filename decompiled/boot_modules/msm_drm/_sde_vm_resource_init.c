__int64 sde_vm_resource_init()
{
  __int64 result; // x0
  unsigned int v1; // w19

  result = ((__int64 (*)(void))sde_kms_vm_trusted_resource_init)();
  if ( (_DWORD)result )
  {
    v1 = result;
    printk(&unk_27C146, "_sde_vm_resource_init");
    return v1;
  }
  return result;
}
