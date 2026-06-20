__int64 __fastcall dot11f_unpack_ie_time_advertisement(__int64 a1, _BYTE *a2, unsigned __int8 a3, _BYTE *a4)
{
  int v5; // w19

  if ( *a4 )
    return 32;
  v5 = a3;
  *a4 = 1;
  if ( a3 && (a4[1] = *a2, a3 > 0xAu) )
  {
    qdf_mem_copy(a4 + 2, a2 + 1, 0xAu);
    if ( (unsigned int)(v5 - 11) <= 4 )
    {
      *a4 = 0;
      return 4;
    }
    else
    {
      qdf_mem_copy(a4 + 12, a2 + 11, 5u);
      return 0;
    }
  }
  else
  {
    *a4 = 0;
    return 4;
  }
}
