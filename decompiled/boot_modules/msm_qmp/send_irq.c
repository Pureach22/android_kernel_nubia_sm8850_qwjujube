__int64 __fastcall send_irq(__int64 a1)
{
  __int64 v2; // x0
  __int64 result; // x0

  __dsb(0xEu);
  v2 = *(_QWORD *)(a1 + 128);
  if ( v2 )
  {
    mbox_send_message(v2, 0);
    result = mbox_client_txdone(*(_QWORD *)(a1 + 128), 0);
  }
  else
  {
    result = writel_relaxed(*(unsigned int *)(a1 + 56));
  }
  ++*(_DWORD *)(a1 + 64);
  return result;
}
