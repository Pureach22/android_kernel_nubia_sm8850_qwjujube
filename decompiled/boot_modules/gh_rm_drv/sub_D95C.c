__int64 __fastcall sub_D95C(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, unsigned __int64 *a6)
{
  unsigned int v6; // w21
  unsigned int v7; // w25

  __stxp(__PAIR64__(v6, v7), a6);
  return gh_rm_vm_irq_release_notify();
}
