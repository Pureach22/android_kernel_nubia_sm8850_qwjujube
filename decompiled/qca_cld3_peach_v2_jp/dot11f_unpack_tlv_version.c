__int64 __fastcall dot11f_unpack_tlv_version(__int64 a1, _BYTE *a2, __int16 a3, _BYTE *a4)
{
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
