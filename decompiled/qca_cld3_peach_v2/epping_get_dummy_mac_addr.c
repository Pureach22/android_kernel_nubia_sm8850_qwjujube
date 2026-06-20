__int64 __fastcall epping_get_dummy_mac_addr(__int64 result)
{
  *(_WORD *)(result + 4) = 18254;
  *(_DWORD *)result = 1230000197;
  return result;
}
