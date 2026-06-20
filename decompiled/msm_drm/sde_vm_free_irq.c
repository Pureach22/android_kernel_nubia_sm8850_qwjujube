__int64 __fastcall sde_vm_free_irq(__int64 a1)
{
  __int64 v1; // x19

  if ( a1 && *(_QWORD *)(a1 + 8) )
  {
    v1 = a1;
    kfree(*(_QWORD *)(a1 + 8));
    a1 = v1;
  }
  return kfree(a1);
}
