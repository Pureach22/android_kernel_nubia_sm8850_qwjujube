__int64 __fastcall dp_hdcp2p2_abort(__int64 result, char a2)
{
  *(_DWORD *)(result + 84) = a2 & 1;
  return result;
}
