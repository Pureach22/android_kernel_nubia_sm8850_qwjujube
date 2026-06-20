__int64 __fastcall wma_set_twt_peer_caps(__int64 result, __int64 a2)
{
  *(_BYTE *)(a2 + 362) = *(_BYTE *)(result + 241) != 0;
  *(_BYTE *)(a2 + 363) = *(_BYTE *)(result + 242) != 0;
  return result;
}
