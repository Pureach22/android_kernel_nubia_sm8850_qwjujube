__int64 __fastcall hw_fence_soccp_irq_handler(__int64 a1, __int64 a2)
{
  int signaled_clients_mask; // w0
  unsigned int v11; // w9

  signaled_clients_mask = hw_fence_ipcc_get_signaled_clients_mask(a2);
  _X8 = (unsigned int *)(a2 + 33600);
  __asm { PRFM            #0x11, [X8] }
  do
    v11 = __ldxr(_X8);
  while ( __stxr(v11 | signaled_clients_mask, _X8) );
  _wake_up(a2 + 33576, 3, 0, 0);
  return 1;
}
