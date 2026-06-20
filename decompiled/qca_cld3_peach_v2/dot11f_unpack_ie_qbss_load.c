__int64 __fastcall dot11f_unpack_ie_qbss_load(__int64 a1, _BYTE *a2, unsigned __int8 a3, _BYTE *a4)
{
  int v5; // w19

  if ( *a4 )
    return 32;
  v5 = a3;
  *a4 = 1;
  if ( a3 <= 1u )
  {
    *a4 = 0;
    return 4;
  }
  else
  {
    qdf_mem_copy(a4 + 2, a2, 2u);
    if ( v5 == 2 || (a4[4] = a2[2], (unsigned int)(v5 - 3) <= 1) )
    {
      *a4 = 0;
      return 4;
    }
    else
    {
      qdf_mem_copy(a4 + 6, a2 + 3, 2u);
      return 0;
    }
  }
}
