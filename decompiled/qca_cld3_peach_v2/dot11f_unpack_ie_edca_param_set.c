__int64 __fastcall dot11f_unpack_ie_edca_param_set(__int64 a1, _BYTE *a2, unsigned __int8 a3, __int64 a4)
{
  int v6; // w21
  unsigned __int8 v8; // w8
  int v9; // w22
  unsigned __int8 v10; // w8
  unsigned __int8 v11; // w8
  unsigned __int8 v12; // w8

  if ( *(_BYTE *)a4 )
    return 32;
  v6 = a3;
  *(_BYTE *)a4 = 1;
  if ( !a3 )
    goto LABEL_19;
  *(_BYTE *)(a4 + 1) = *a2;
  if ( a3 == 1 )
    goto LABEL_19;
  *(_BYTE *)(a4 + 2) = a2[1];
  if ( a3 == 2 )
    goto LABEL_19;
  v8 = a2[2];
  *(_WORD *)(a4 + 3) = v8 & 0xF | (*(unsigned __int8 *)(a4 + 4) << 8) | v8 & 0x10 | v8 & 0x60 | v8 & 0x80;
  if ( a3 == 3 )
    goto LABEL_19;
  v9 = a3 & 0xFE;
  *(_WORD *)(a4 + 3) = v8 | ((a2[3] & 0xF) << 8) & 0xFFF | (a2[3] >> 4 << 12);
  if ( v9 == 4 )
    goto LABEL_19;
  qdf_mem_copy((void *)(a4 + 6), a2 + 4, 2u);
  if ( v6 == 6 )
    goto LABEL_19;
  v10 = a2[6];
  *(_WORD *)(a4 + 8) = v10 & 0xF | (*(unsigned __int8 *)(a4 + 9) << 8) | v10 & 0x10 | v10 & 0x60 | v10 & 0x80;
  if ( v6 == 7 )
    goto LABEL_19;
  *(_WORD *)(a4 + 8) = v10 | ((a2[7] & 0xF) << 8) & 0xFFF | (a2[7] >> 4 << 12);
  if ( v9 == 8 )
    goto LABEL_19;
  qdf_mem_copy((void *)(a4 + 10), a2 + 8, 2u);
  if ( v6 == 10
    || (v11 = a2[10],
        *(_WORD *)(a4 + 12) = v11 & 0xF | (*(unsigned __int8 *)(a4 + 13) << 8) | v11 & 0x10 | v11 & 0x60 | v11 & 0x80,
        v6 == 11)
    || (*(_WORD *)(a4 + 12) = v11 | ((a2[11] & 0xF) << 8) & 0xFFF | (a2[11] >> 4 << 12), v9 == 12)
    || (qdf_mem_copy((void *)(a4 + 14), a2 + 12, 2u), v6 == 14)
    || (v12 = a2[14],
        *(_WORD *)(a4 + 16) = v12 & 0xF | (*(unsigned __int8 *)(a4 + 17) << 8) | v12 & 0x10 | v12 & 0x60 | v12 & 0x80,
        v6 == 15)
    || (*(_WORD *)(a4 + 16) = v12 | ((a2[15] & 0xF) << 8) & 0xFFF | (a2[15] >> 4 << 12), v9 == 16) )
  {
LABEL_19:
    *(_BYTE *)a4 = 0;
    return 4;
  }
  else
  {
    qdf_mem_copy((void *)(a4 + 18), a2 + 16, 2u);
    return 0;
  }
}
