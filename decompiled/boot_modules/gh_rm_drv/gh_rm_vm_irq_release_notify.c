__int64 __fastcall gh_rm_vm_irq_release_notify(__int64 a1, int a2)
{
  return gh_rm_vm_irq_notify(nullptr, 0, 2, a2);
}
