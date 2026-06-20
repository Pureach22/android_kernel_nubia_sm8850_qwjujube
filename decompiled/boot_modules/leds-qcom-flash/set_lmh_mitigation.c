__int64 __fastcall set_lmh_mitigation(__int64 *a1, char a2)
{
  __int64 v2; // x19
  char v3; // w20
  __int64 result; // x0

  v2 = *a1;
  if ( (*(_BYTE *)(*a1 + 146) & 1) != 0 )
    return 0;
  v3 = a2 & 1;
  if ( *(_BYTE *)(v2 + 145) == (a2 & 1) )
    return 0;
  result = regmap_field_update_bits_base(*(_QWORD *)(v2 + 88), 0xFFFFFFFFLL, a2 & 1, 0, 0, 0);
  if ( (result & 0x80000000) == 0 )
  {
    *(_BYTE *)(v2 + 145) = v3;
    return 0;
  }
  return result;
}
