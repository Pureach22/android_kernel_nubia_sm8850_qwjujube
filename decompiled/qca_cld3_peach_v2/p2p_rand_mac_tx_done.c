__int64 __fastcall p2p_rand_mac_tx_done(
        __int64 result,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  if ( a2 && result && (*(_BYTE *)(a2 + 63) & 1) != 0 )
    return p2p_random_mac_handle_tx_done(
             result,
             *(_DWORD *)(a2 + 24),
             *(int *)(a2 + 40),
             *(_DWORD *)(a2 + 64),
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10);
  return result;
}
