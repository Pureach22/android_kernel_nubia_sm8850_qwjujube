__int64 __fastcall rmnet_vnd_reset_mac_addr(__int64 result)
{
  __int64 v1; // x19

  if ( *(__int64 (__fastcall ***)())(result + 8) == rmnet_vnd_ops )
  {
    v1 = result;
    result = get_random_bytes(result + 791, 6);
    *(_BYTE *)(v1 + 791) = *(_BYTE *)(v1 + 791) & 0xFC | 2;
  }
  return result;
}
