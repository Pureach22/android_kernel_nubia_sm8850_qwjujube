__int64 __fastcall gh_rm_virq_to_irq(__int64 a1, __int64 a2)
{
  __int64 v2; // x2

  if ( gh_rm_intc )
    v2 = gh_rm_intc + 24;
  else
    v2 = 0;
  return gh_get_irq(a1, a2, v2);
}
