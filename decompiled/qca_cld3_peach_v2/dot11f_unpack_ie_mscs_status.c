__int64 __fastcall dot11f_unpack_ie_mscs_status(__int64 a1, _BYTE *a2, char a3, _BYTE *a4)
{
  if ( *a4 )
    return 32;
  *a4 = 1;
  if ( a3 )
  {
    a4[1] = *a2;
    return 0;
  }
  else
  {
    *a4 = 0;
    return 4;
  }
}
