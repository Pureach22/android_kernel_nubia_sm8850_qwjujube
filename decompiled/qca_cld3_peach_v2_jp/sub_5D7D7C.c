__int64 __fastcall sub_5D7D7C(__int64 a1)
{
  __asm { PRFM            #0x1C, [X28],#0xFF }
  return dp_rx_fst_requeue_wq(a1);
}
