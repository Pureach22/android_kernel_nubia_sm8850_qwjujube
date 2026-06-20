__int64 __fastcall dot11f_get_packed_ie_transmit_power_env(__int64 a1, _BYTE *a2, int *a3)
{
  int v3; // w8
  int v4; // w8
  unsigned int v5; // w9

  if ( *a2 )
  {
    v3 = *a3 + 1;
    *a3 = v3;
    v4 = v3 + (unsigned __int8)a2[2];
    *a3 = v4;
    v5 = (((unsigned __int8)a2[1] >> 3) & 7) - 1;
    if ( v5 <= 4 )
      *a3 = v4 + dword_B08190[v5];
  }
  return 0;
}
