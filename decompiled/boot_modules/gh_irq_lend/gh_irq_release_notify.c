__int64 __fastcall gh_irq_release_notify(unsigned int a1)
{
  __int16 *v1; // x8
  int v2; // w9
  bool v3; // zf

  if ( a1 <= 5 && ((v1 = &gh_irq_entries[20 * a1], v2 = *((_DWORD *)v1 + 8), v2 != 4) ? (v3 = v2 == 2) : (v3 = 1), v3) )
    return gh_rm_vm_irq_release_notify((unsigned __int16)*v1, *((unsigned int *)v1 + 9));
  else
    return 4294967274LL;
}
