__int64 __fastcall wma_set_peer_assoc_params_bw_320(__int64 result, int a2)
{
  if ( a2 == 7 )
    *(_WORD *)(result + 352) |= 0x100u;
  return result;
}
