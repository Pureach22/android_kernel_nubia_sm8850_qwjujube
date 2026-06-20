__int64 __fastcall qpnpint_irq_set_wake(__int64 a1)
{
  return irq_set_irq_wake(*(unsigned int *)(*(_QWORD *)(a1 + 48) + 164LL));
}
