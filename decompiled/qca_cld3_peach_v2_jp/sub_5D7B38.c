__int64 __fastcall sub_5D7B38(__int64 a1)
{
  __asm { PRFM            #0x1C, [X28],#0xFF }
  return dp_rx_fst_detach(a1);
}
