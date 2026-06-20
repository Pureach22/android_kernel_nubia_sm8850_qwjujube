__int64 __fastcall dot11f_unpack_ie_neighbor_rpt(__int64 a1, _BYTE *a2, unsigned __int8 a3, __int64 a4, char a5)
{
  __int64 v5; // x29
  __int64 v6; // x30
  int v8; // w24
  char v14; // w8
  __int16 v15; // w8
  __int64 v16; // x7
  __int64 v17; // [xsp+8h] [xbp-38h]

  if ( *(_BYTE *)a4 )
    return 32;
  v17 = v6;
  v8 = a3;
  *(_BYTE *)a4 = 1;
  if ( a3 <= 5u )
    goto LABEL_12;
  qdf_mem_copy((void *)(a4 + 1), a2, 6u);
  if ( v8 == 6
    || (v14 = a2[6],
        v15 = v14 & 3 | (*(unsigned __int8 *)(a4 + 8) << 8) | v14 & 0x1C | v14 & 0xE0,
        *(_WORD *)(a4 + 7) = v15,
        a3 == 7)
    || (*(_WORD *)(a4 + 7) = (unsigned __int8)v15
                           | ((a2[7] & 1) << 8) & 0x1FF
                           | (((a2[7] & 2) != 0) << 9) & 0x3FF
                           | (((a2[7] & 4) != 0) << 10) & 0x7FF
                           | (a2[7] >> 3 << 11),
        (a3 & 0xFE) == 8)
    || (qdf_mem_copy((void *)(a4 + 10), a2 + 8, 2u), a3 == 10)
    || (*(_BYTE *)(a4 + 12) = a2[10], a3 == 11)
    || (*(_BYTE *)(a4 + 13) = a2[11], a3 == 12) )
  {
LABEL_12:
    *(_BYTE *)a4 = 0;
    return 4;
  }
  else
  {
    *(_BYTE *)(a4 + 14) = a2[12];
    return unpack_core(
             a1,
             a2 + 13,
             (unsigned __int8)(a3 - 13),
             &FFS_neighbor_rpt,
             &IES_neighbor_rpt,
             a4,
             a5 & 1,
             v16,
             v5,
             v17);
  }
}
