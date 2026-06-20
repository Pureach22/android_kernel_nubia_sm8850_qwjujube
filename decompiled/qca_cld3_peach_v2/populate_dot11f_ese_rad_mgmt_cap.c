__int64 __fastcall populate_dot11f_ese_rad_mgmt_cap(__int64 result)
{
  *(_BYTE *)(result + 2) = 0;
  *(_WORD *)result = 257;
  return result;
}
