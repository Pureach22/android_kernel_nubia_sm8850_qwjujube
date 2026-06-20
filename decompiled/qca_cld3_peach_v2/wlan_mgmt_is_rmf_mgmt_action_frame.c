bool __fastcall wlan_mgmt_is_rmf_mgmt_action_frame(unsigned __int8 a1)
{
  unsigned int v1; // w8
  _BOOL8 result; // x0

  v1 = a1;
  result = 1;
  if ( v1 > 0x1D || ((1 << v1) & 0x3F8D676F) == 0 )
    return v1 == 126;
  return result;
}
