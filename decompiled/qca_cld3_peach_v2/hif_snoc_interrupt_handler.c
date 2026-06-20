__int64 __fastcall hif_snoc_interrupt_handler(unsigned int a1, __int64 a2)
{
  unsigned int ce_id; // w0

  ce_id = pld_get_ce_id(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 48) + 576LL) + 40LL), a1);
  return ce_dispatch_interrupt(ce_id, a2);
}
