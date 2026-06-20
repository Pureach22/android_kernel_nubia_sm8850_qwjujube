__int64 __fastcall hif_ce_interrupt_handler(__int64 a1, __int64 a2)
{
  return ce_dispatch_interrupt(*(_DWORD *)(a2 + 40), a2);
}
