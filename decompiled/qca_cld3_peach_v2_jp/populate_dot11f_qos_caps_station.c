__int64 __fastcall populate_dot11f_qos_caps_station(__int64 result, __int64 a2, _BYTE *a3)
{
  char v3; // w8
  char v4; // w8
  char v5; // w8
  char v6; // w8

  v3 = a3[1] & 0xF | (32 * (*(_BYTE *)(*(_QWORD *)(result + 8) + 5454LL) & 3));
  a3[1] = v3;
  if ( *(_BYTE *)(result + 8896) )
  {
    v4 = *(_BYTE *)(a2 + 7273) & 8 | v3 & 0xE7;
    a3[1] = v4;
    v5 = v4 & 0xFB | *(_BYTE *)(a2 + 7273) & 4;
    a3[1] = v5;
    v6 = v5 & 0xFD | *(_BYTE *)(a2 + 7273) & 2;
    a3[1] = v6;
    a3[1] = v6 & 0xFE | *(_BYTE *)(a2 + 7273) & 1;
  }
  *a3 = 1;
  return result;
}
