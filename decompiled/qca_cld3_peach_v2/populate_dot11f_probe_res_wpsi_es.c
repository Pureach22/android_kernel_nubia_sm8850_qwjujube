__int64 __fastcall populate_dot11f_probe_res_wpsi_es(__int64 a1, __int64 a2, __int64 a3)
{
  size_t v5; // x2
  size_t v6; // x2
  size_t v7; // x2
  size_t v8; // x2
  size_t v9; // x2
  char v10; // w9
  char v11; // w8

  if ( (*(_BYTE *)(a3 + 1648) & 1) != 0 )
  {
    v10 = *(_BYTE *)(a2 + 2);
    *(_WORD *)a2 = 257;
    v11 = *(_BYTE *)(a3 + 1652);
    *(_BYTE *)(a2 + 2) = v11 & 0xF0 | v10 & 0xF;
    *(_BYTE *)(a2 + 2) = v11 & 0xF0 | *(_BYTE *)(a3 + 1652) & 0xF;
    if ( (*(_BYTE *)(a3 + 1648) & 2) != 0 )
    {
LABEL_3:
      *(_BYTE *)(a2 + 3) = 1;
      *(_BYTE *)(a2 + 4) = *(_DWORD *)(a3 + 1656);
      if ( (*(_BYTE *)(a3 + 1648) & 4) != 0 )
        goto LABEL_4;
      goto LABEL_20;
    }
  }
  else
  {
    *(_WORD *)a2 = 0;
    if ( (*(_BYTE *)(a3 + 1648) & 2) != 0 )
      goto LABEL_3;
  }
  *(_BYTE *)(a2 + 3) = 0;
  if ( (*(_BYTE *)(a3 + 1648) & 4) != 0 )
  {
LABEL_4:
    *(_BYTE *)(a2 + 5) = 1;
    *(_BYTE *)(a2 + 6) = *(_BYTE *)(a3 + 1660);
    if ( (*(_BYTE *)(a3 + 1648) & 8) != 0 )
      goto LABEL_5;
    goto LABEL_21;
  }
LABEL_20:
  *(_BYTE *)(a2 + 5) = 0;
  if ( (*(_BYTE *)(a3 + 1648) & 8) != 0 )
  {
LABEL_5:
    *(_BYTE *)(a2 + 7) = 1;
    *(_BYTE *)(a2 + 8) = *(_BYTE *)(a3 + 1661);
    if ( (*(_BYTE *)(a3 + 1648) & 0x10) != 0 )
      goto LABEL_6;
    goto LABEL_22;
  }
LABEL_21:
  *(_BYTE *)(a2 + 7) = 0;
  if ( (*(_BYTE *)(a3 + 1648) & 0x10) != 0 )
  {
LABEL_6:
    *(_BYTE *)(a2 + 10) = 1;
    *(_WORD *)(a2 + 12) = *(_WORD *)(a3 + 1662);
    if ( (*(_BYTE *)(a3 + 1648) & 0x20) != 0 )
      goto LABEL_7;
    goto LABEL_23;
  }
LABEL_22:
  *(_BYTE *)(a2 + 10) = 0;
  if ( (*(_BYTE *)(a3 + 1648) & 0x20) != 0 )
  {
LABEL_7:
    *(_BYTE *)(a2 + 14) = 1;
    *(_WORD *)(a2 + 16) = *(_WORD *)(a3 + 1664);
    if ( (*(_BYTE *)(a3 + 1648) & 0x40) != 0 )
      goto LABEL_8;
    goto LABEL_24;
  }
LABEL_23:
  *(_BYTE *)(a2 + 14) = 0;
  if ( (*(_BYTE *)(a3 + 1648) & 0x40) != 0 )
  {
LABEL_8:
    *(_BYTE *)(a2 + 18) = 1;
    *(_BYTE *)(a2 + 19) = *(_BYTE *)(a3 + 1666);
    if ( (*(_BYTE *)(a3 + 1648) & 0x80) != 0 )
      goto LABEL_9;
    goto LABEL_25;
  }
LABEL_24:
  *(_BYTE *)(a2 + 18) = 0;
  if ( (*(_BYTE *)(a3 + 1648) & 0x80) != 0 )
  {
LABEL_9:
    *(_BYTE *)(a2 + 20) = 1;
    qdf_mem_copy((void *)(a2 + 21), (const void *)(a3 + 1667), 0x10u);
    if ( (*(_BYTE *)(a3 + 1649) & 1) != 0 )
      goto LABEL_10;
    goto LABEL_26;
  }
LABEL_25:
  *(_BYTE *)(a2 + 20) = 0;
  if ( (*(_BYTE *)(a3 + 1649) & 1) != 0 )
  {
LABEL_10:
    *(_BYTE *)(a2 + 37) = 1;
    v5 = *(unsigned __int8 *)(a3 + 1683);
    *(_BYTE *)(a2 + 38) = v5;
    qdf_mem_copy((void *)(a2 + 39), (const void *)(a3 + 1684), v5);
    if ( (*(_BYTE *)(a3 + 1649) & 4) != 0 )
      goto LABEL_11;
    goto LABEL_27;
  }
LABEL_26:
  *(_BYTE *)(a2 + 37) = 0;
  if ( (*(_BYTE *)(a3 + 1649) & 4) != 0 )
  {
LABEL_11:
    *(_BYTE *)(a2 + 103) = 1;
    v6 = *(unsigned __int8 *)(a3 + 1748);
    *(_BYTE *)(a2 + 104) = v6;
    qdf_mem_copy((void *)(a2 + 105), (const void *)(a3 + 1749), v6);
    if ( (*(_BYTE *)(a3 + 1649) & 4) != 0 )
      goto LABEL_12;
    goto LABEL_28;
  }
LABEL_27:
  *(_BYTE *)(a2 + 103) = 0;
  if ( (*(_BYTE *)(a3 + 1649) & 4) != 0 )
  {
LABEL_12:
    *(_BYTE *)(a2 + 137) = 1;
    v7 = *(unsigned __int8 *)(a3 + 1781);
    *(_BYTE *)(a2 + 138) = v7;
    qdf_mem_copy((void *)(a2 + 139), (const void *)(a3 + 1782), v7);
    if ( (*(_BYTE *)(a3 + 1649) & 8) != 0 )
      goto LABEL_13;
    goto LABEL_29;
  }
LABEL_28:
  *(_BYTE *)(a2 + 137) = 0;
  if ( (*(_BYTE *)(a3 + 1649) & 8) != 0 )
  {
LABEL_13:
    *(_BYTE *)(a2 + 171) = 1;
    v8 = *(unsigned __int8 *)(a3 + 1814);
    *(_BYTE *)(a2 + 172) = v8;
    qdf_mem_copy((void *)(a2 + 173), (const void *)(a3 + 1815), v8);
    if ( (*(_BYTE *)(a3 + 1649) & 0x10) != 0 )
      goto LABEL_14;
    goto LABEL_30;
  }
LABEL_29:
  *(_BYTE *)(a2 + 171) = 0;
  if ( (*(_BYTE *)(a3 + 1649) & 0x10) != 0 )
  {
LABEL_14:
    *(_BYTE *)(a2 + 206) = 1;
    qdf_mem_copy((void *)(a2 + 210), (const void *)(a3 + 1852), 4u);
    *(_WORD *)(a2 + 208) = *(_DWORD *)(a3 + 1848);
    *(_WORD *)(a2 + 214) = *(_DWORD *)(a3 + 1856);
    if ( (*(_BYTE *)(a3 + 1649) & 0x20) != 0 )
      goto LABEL_15;
    goto LABEL_31;
  }
LABEL_30:
  *(_BYTE *)(a2 + 206) = 0;
  if ( (*(_BYTE *)(a3 + 1649) & 0x20) != 0 )
  {
LABEL_15:
    *(_BYTE *)(a2 + 216) = 1;
    v9 = *(unsigned __int8 *)(a3 + 1860);
    *(_BYTE *)(a2 + 217) = v9;
    qdf_mem_copy((void *)(a2 + 218), (const void *)(a3 + 1861), v9);
    if ( (*(_BYTE *)(a3 + 1649) & 0x40) != 0 )
      goto LABEL_16;
LABEL_32:
    *(_BYTE *)(a2 + 250) = 0;
    if ( (*(_BYTE *)(a3 + 1649) & 0x80) != 0 )
      goto LABEL_17;
LABEL_33:
    *(_BYTE *)(a2 + 254) = 0;
    return 0;
  }
LABEL_31:
  *(_BYTE *)(a2 + 216) = 0;
  if ( (*(_BYTE *)(a3 + 1649) & 0x40) == 0 )
    goto LABEL_32;
LABEL_16:
  *(_BYTE *)(a2 + 250) = 1;
  *(_WORD *)(a2 + 252) = *(_WORD *)(a3 + 1894);
  if ( (*(_BYTE *)(a3 + 1649) & 0x80) == 0 )
    goto LABEL_33;
LABEL_17:
  *(_BYTE *)(a2 + 254) = 1;
  *(_BYTE *)(a2 + 255) = *(_BYTE *)(a3 + 1896);
  return 0;
}
