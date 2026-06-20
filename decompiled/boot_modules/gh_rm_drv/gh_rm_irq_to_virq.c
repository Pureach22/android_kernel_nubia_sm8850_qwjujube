__int64 __fastcall gh_rm_irq_to_virq(unsigned int a1, _DWORD *a2)
{
  __int64 irq_data; // x0

  irq_data = irq_domain_get_irq_data(gh_rm_irq_domain, a1);
  if ( !irq_data )
    return 4294967274LL;
  if ( a2 )
    *a2 = *(_QWORD *)(irq_data + 8);
  return 0;
}
