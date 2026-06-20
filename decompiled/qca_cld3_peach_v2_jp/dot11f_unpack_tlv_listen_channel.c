__int64 __fastcall dot11f_unpack_tlv_listen_channel(__int64 a1, _BYTE *a2, unsigned __int16 a3, _BYTE *a4)
{
  int v4; // w22
  __int64 result; // x0

  v4 = a3;
  *a4 = 1;
  if ( a3 <= 2u || (qdf_mem_copy(a4 + 1, a2, 3u), v4 == 3) || (a4[4] = a2[3], a3 == 4) )
  {
    *a4 = 0;
    return 4;
  }
  else
  {
    result = 0;
    a4[5] = a2[4];
  }
  return result;
}
