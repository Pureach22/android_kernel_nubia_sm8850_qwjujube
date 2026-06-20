__int64 __fastcall sub_5697D4(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 _X4)
{
  __asm { STZG            X4, [X2,#-0x880]! }
  return dp_tx_ring_access_end_wrapper(a1, a2, a3);
}
