__int64 __fastcall qcom_ipcc_remove(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 168);
  irq_set_irq_wake(*(unsigned int *)(v1 + 180), 0);
  return irq_domain_remove(*(_QWORD *)(v1 + 16));
}
