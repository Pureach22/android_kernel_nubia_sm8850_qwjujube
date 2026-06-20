__int64 __fastcall wlan_mlme_set_edca_pifs_param(__int64 result, int a2)
{
  *(_BYTE *)result = a2;
  if ( a2 == 1 )
  {
    *(_WORD *)(result + 1) = 256;
    *(_BYTE *)(result + 3) = 2;
  }
  else if ( !a2 )
  {
    *(_WORD *)(result + 1) = *(_WORD *)(result + 1) & 0x80 | 0x3262;
    *(_WORD *)(result + 3) = 47;
  }
  return result;
}
