__int64 __fastcall populate_dot11f_beacon_wpsi_es(__int64 a1, __int64 a2, __int64 a3)
{
  char v5; // w9
  char v6; // w8

  if ( (*(_BYTE *)(a3 + 1900) & 1) != 0 )
  {
    v5 = *(_BYTE *)(a2 + 2);
    *(_WORD *)a2 = 257;
    v6 = *(_BYTE *)(a3 + 1904);
    *(_BYTE *)(a2 + 2) = v6 & 0xF0 | v5 & 0xF;
    *(_BYTE *)(a2 + 2) = v6 & 0xF0 | *(_BYTE *)(a3 + 1904) & 0xF;
    if ( (*(_BYTE *)(a3 + 1900) & 2) != 0 )
    {
LABEL_3:
      *(_BYTE *)(a2 + 3) = 1;
      *(_BYTE *)(a2 + 4) = *(_DWORD *)(a3 + 1908);
      if ( (*(_BYTE *)(a3 + 1900) & 4) != 0 )
        goto LABEL_4;
      goto LABEL_12;
    }
  }
  else
  {
    *(_WORD *)a2 = 0;
    if ( (*(_BYTE *)(a3 + 1900) & 2) != 0 )
      goto LABEL_3;
  }
  *(_BYTE *)(a2 + 3) = 0;
  if ( (*(_BYTE *)(a3 + 1900) & 4) != 0 )
  {
LABEL_4:
    *(_BYTE *)(a2 + 5) = 1;
    *(_BYTE *)(a2 + 6) = *(_BYTE *)(a3 + 1912);
    if ( (*(_BYTE *)(a3 + 1900) & 8) != 0 )
      goto LABEL_5;
    goto LABEL_13;
  }
LABEL_12:
  *(_BYTE *)(a2 + 5) = 0;
  if ( (*(_BYTE *)(a3 + 1900) & 8) != 0 )
  {
LABEL_5:
    *(_BYTE *)(a2 + 7) = 1;
    *(_BYTE *)(a2 + 8) = *(_BYTE *)(a3 + 1913);
    if ( (*(_BYTE *)(a3 + 1900) & 0x10) != 0 )
      goto LABEL_6;
    goto LABEL_14;
  }
LABEL_13:
  *(_BYTE *)(a2 + 7) = 0;
  if ( (*(_BYTE *)(a3 + 1900) & 0x10) != 0 )
  {
LABEL_6:
    *(_BYTE *)(a2 + 10) = 1;
    *(_WORD *)(a2 + 12) = *(_WORD *)(a3 + 1914);
    if ( (*(_BYTE *)(a3 + 1900) & 0x20) != 0 )
      goto LABEL_7;
    goto LABEL_15;
  }
LABEL_14:
  *(_BYTE *)(a2 + 10) = 0;
  if ( (*(_BYTE *)(a3 + 1900) & 0x20) != 0 )
  {
LABEL_7:
    *(_BYTE *)(a2 + 14) = 1;
    *(_WORD *)(a2 + 16) = *(_WORD *)(a3 + 1916);
    if ( (*(_BYTE *)(a3 + 1900) & 0x80) != 0 )
      goto LABEL_8;
LABEL_16:
    *(_BYTE *)(a2 + 18) = 0;
    if ( (*(_BYTE *)(a3 + 1901) & 1) != 0 )
      goto LABEL_9;
LABEL_17:
    *(_BYTE *)(a2 + 35) = 0;
    return 0;
  }
LABEL_15:
  *(_BYTE *)(a2 + 14) = 0;
  if ( (*(_BYTE *)(a3 + 1900) & 0x80) == 0 )
    goto LABEL_16;
LABEL_8:
  *(_BYTE *)(a2 + 18) = 1;
  qdf_mem_copy((void *)(a2 + 19), (const void *)(a3 + 1918), 0x10u);
  if ( (*(_BYTE *)(a3 + 1901) & 1) == 0 )
    goto LABEL_17;
LABEL_9:
  *(_BYTE *)(a2 + 35) = 1;
  *(_BYTE *)(a2 + 36) = *(_BYTE *)(a3 + 1934);
  return 0;
}
