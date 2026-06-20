__int64 __fastcall sde_vm_reclaim(__int64 a1)
{
  unsigned int v2; // w0
  __int64 result; // x0
  unsigned int v4; // w19
  void *v5; // x0

  v2 = sde_vm_reclaim_mem(a1);
  if ( v2 )
  {
    v4 = v2;
    v5 = &unk_2260C3;
LABEL_6:
    printk(v5, "_sde_vm_reclaim");
    return v4;
  }
  result = sde_vm_reclaim_irq(a1);
  if ( (_DWORD)result )
  {
    v4 = result;
    v5 = &unk_25215D;
    goto LABEL_6;
  }
  return result;
}
