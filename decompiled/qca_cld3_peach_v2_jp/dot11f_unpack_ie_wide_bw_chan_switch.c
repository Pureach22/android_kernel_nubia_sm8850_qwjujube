__int64 __fastcall dot11f_unpack_ie_wide_bw_chan_switch(__int64 a1, _BYTE *a2, char a3, _BYTE *a4)
{
  if ( *a4 )
    return 32;
  *a4 = 1;
  if ( !a3 || (a4[1] = *a2, a3 == 1) || (a4[2] = a2[1], a3 == 2) )
  {
    *a4 = 0;
    return 4;
  }
  else
  {
    a4[3] = a2[2];
    return 0;
  }
}
