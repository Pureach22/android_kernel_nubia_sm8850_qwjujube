__int64 __fastcall dot11f_unpack_ie_pti_control(__int64 a1, _BYTE *a2, unsigned __int8 a3, _BYTE *a4)
{
  if ( *a4 )
    return 32;
  *a4 = 1;
  if ( a3 && (a4[1] = *a2, a3 > 2u) )
  {
    qdf_mem_copy(a4 + 2, a2 + 1, 2u);
    return 0;
  }
  else
  {
    *a4 = 0;
    return 4;
  }
}
