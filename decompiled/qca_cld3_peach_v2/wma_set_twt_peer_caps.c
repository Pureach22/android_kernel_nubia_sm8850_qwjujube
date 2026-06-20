__int64 __fastcall wma_set_twt_peer_caps(__int64 result, __int64 a2)
{
  *(_BYTE *)(a2 + 363) = *(_BYTE *)(result + 253) != 0;
  *(_BYTE *)(a2 + 364) = *(_BYTE *)(result + 254) != 0;
  return result;
}
