__int64 __fastcall qos_rec_irq_open(__int64 a1, __int64 a2)
{
  return single_open(a2, qos_rec_irq_read, *(_QWORD *)(a1 + 696));
}
