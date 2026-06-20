__int64 __fastcall p2p_adjust_tx_wait(__int64 result)
{
  unsigned int v1; // w8

  v1 = *(_DWORD *)(result + 248) - 1;
  if ( v1 <= 7 && ((0x8Bu >> v1) & 1) != 0 )
    *(_DWORD *)(result + 64) += dword_B35668[v1];
  return result;
}
