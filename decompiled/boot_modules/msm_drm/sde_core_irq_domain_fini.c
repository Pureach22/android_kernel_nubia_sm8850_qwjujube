__int64 __fastcall sde_core_irq_domain_fini(__int64 a1)
{
  if ( *(_QWORD *)(a1 + 1888) )
  {
    irq_domain_remove();
    *(_QWORD *)(a1 + 1888) = 0;
  }
  return 0;
}
