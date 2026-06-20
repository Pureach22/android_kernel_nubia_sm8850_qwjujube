__int64 __fastcall get_dsc_v1_2_bpg_offset(__int64 a1)
{
  unsigned int v1; // w9
  unsigned int v2; // w8
  unsigned int v3; // w9
  int v4; // w10
  unsigned int v5; // w10
  unsigned __int8 v6; // w11
  int v7; // w8

  v1 = *(unsigned __int16 *)(a1 + 6);
  v2 = *(unsigned __int16 *)(a1 + 16);
  if ( v1 > 7 )
  {
    if ( v1 >= 0x14 )
    {
      if ( v1 < 0x2A )
        v4 = 14;
      else
        v4 = 15;
      if ( v1 >= 0x1F )
        v3 = v4;
      else
        v3 = 13;
    }
    else
    {
      v3 = 12;
    }
  }
  else
  {
    v3 = 2 * v1 - 2;
  }
  v5 = v2 >> 4;
  if ( *(_BYTE *)(a1 + 128) == 1 )
  {
    v6 = 12 * v5;
  }
  else
  {
    v6 = 9 * v5 + 6;
    if ( *(_BYTE *)(a1 + 129) == 1 )
      v6 = 3 * v5;
  }
  v7 = v6 - 3 * (unsigned __int8)(v2 >> 4);
  if ( v7 <= (unsigned __int8)v3 )
    return (unsigned int)v7;
  else
    return v3;
}
