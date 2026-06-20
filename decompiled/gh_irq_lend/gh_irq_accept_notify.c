__int64 __fastcall gh_irq_accept_notify(unsigned int a1)
{
  __int16 *v1; // x8

  if ( a1 <= 5 && (v1 = &gh_irq_entries[20 * a1], *((_DWORD *)v1 + 8) == 4) )
    return gh_rm_vm_irq_accept_notify((unsigned __int16)*v1, *((unsigned int *)v1 + 9));
  else
    return 4294967274LL;
}
