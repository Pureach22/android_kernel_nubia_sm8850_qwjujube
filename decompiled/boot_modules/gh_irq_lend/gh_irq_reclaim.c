__int64 __fastcall gh_irq_reclaim(unsigned int a1)
{
  __int64 result; // x0
  __int16 *v2; // x19

  if ( a1 > 5 )
    return 4294967274LL;
  v2 = &gh_irq_entries[20 * a1];
  if ( (*((_DWORD *)v2 + 8) | 2) != 3 )
    return 4294967274LL;
  result = gh_rm_vm_irq_reclaim(*((unsigned int *)v2 + 9));
  if ( !(_DWORD)result )
    *((_DWORD *)v2 + 8) = 0;
  return result;
}
