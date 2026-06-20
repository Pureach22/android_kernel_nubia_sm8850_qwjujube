__int64 __fastcall dot11f_unpack_tlv_p2_p_capability(__int64 a1, _BYTE *a2, __int16 a3, _BYTE *a4)
{
  *a4 = 1;
  if ( !a3 || (a4[1] = *a2, a3 == 1) )
  {
    *a4 = 0;
    return 4;
  }
  else
  {
    a4[2] = a2[1];
    return 0;
  }
}
