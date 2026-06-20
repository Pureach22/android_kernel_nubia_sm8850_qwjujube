__int64 __fastcall wlan_sm_reset(__int64 result, char a2)
{
  *(_BYTE *)(result + 64) = a2;
  return result;
}
