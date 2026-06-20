__int64 __fastcall cam_sfe_bus_parse_cache_cfg(__int64 result, unsigned int a2, __int64 a3)
{
  int v3; // w10
  char v4; // w8
  int v5; // w9
  char v6; // w10
  unsigned int v7; // w10
  unsigned int v8; // w8

  if ( a2 == 0xFFFFFF )
  {
    *(_BYTE *)(a3 + 8) = 1;
    return result;
  }
  v3 = (a2 >> 8) & 0xF;
  if ( (result & 1) != 0 )
    v4 = 12;
  else
    v4 = 16;
  v5 = (a2 >> 20) & 0xF;
  *(_BYTE *)(a3 + 13) = (a2 & 0xFC000000) != 0;
  if ( v3 == 1 )
  {
    if ( (result & 1) != 0 )
      v6 = 0;
    else
      v6 = 4;
    v7 = (a2 >> v6) & 0xF;
    if ( v7 <= 8 )
    {
      *(_DWORD *)a3 = v7;
      *(_BYTE *)(a3 + 10) = 1;
    }
    *(_BYTE *)(a3 + 9) = 0;
    if ( v5 == 1 )
      goto LABEL_19;
    goto LABEL_16;
  }
  if ( v3 == 15 )
  {
    *(_BYTE *)(a3 + 9) = 1;
    if ( v5 == 1 )
      goto LABEL_19;
LABEL_16:
    if ( v5 == 15 )
    {
      *(_BYTE *)(a3 + 8) = 0;
      *(_BYTE *)(a3 + 11) = 1;
    }
    else
    {
      *(_WORD *)(a3 + 11) = 0;
      *(_BYTE *)(a3 + 8) = 0;
    }
    return result;
  }
  *(_WORD *)(a3 + 9) = 0;
  if ( v5 != 1 )
    goto LABEL_16;
LABEL_19:
  v8 = (a2 >> v4) & 0xF;
  if ( v8 <= 8 )
  {
    *(_DWORD *)(a3 + 4) = v8;
    *(_BYTE *)(a3 + 12) = 1;
  }
  *(_BYTE *)(a3 + 11) = 0;
  *(_BYTE *)(a3 + 8) = 0;
  return result;
}
