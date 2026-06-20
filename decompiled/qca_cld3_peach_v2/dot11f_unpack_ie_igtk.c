__int64 __fastcall dot11f_unpack_ie_igtk(__int64 a1, _BYTE *a2, unsigned __int8 a3, _BYTE *a4)
{
  int v5; // w21

  if ( *a4 )
    return 32;
  v5 = a3;
  *a4 = 1;
  if ( a3 <= 1u
    || (qdf_mem_copy(a4 + 1, a2, 2u), (unsigned int)(v5 - 2) <= 5)
    || (qdf_mem_copy(a4 + 3, a2 + 2, 6u), v5 == 8)
    || (a4[9] = a2[8], (unsigned int)(v5 - 9) <= 0x17) )
  {
    *a4 = 0;
    return 4;
  }
  else
  {
    qdf_mem_copy(a4 + 10, a2 + 9, 0x18u);
    return 0;
  }
}
