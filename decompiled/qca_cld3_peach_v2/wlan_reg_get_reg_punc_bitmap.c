__int64 __fastcall wlan_reg_get_reg_punc_bitmap(__int64 result)
{
  if ( result )
    return *(unsigned __int16 *)(result + 18);
  return result;
}
