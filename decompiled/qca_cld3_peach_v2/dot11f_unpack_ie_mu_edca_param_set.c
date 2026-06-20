__int64 __fastcall dot11f_unpack_ie_mu_edca_param_set(__int64 a1, _BYTE *a2, char a3, __int64 a4)
{
  unsigned __int8 v5; // w9
  __int16 v6; // w9
  unsigned __int8 v7; // w9
  __int16 v8; // w9

  if ( *(_BYTE *)a4 )
    return 32;
  *(_BYTE *)a4 = 1;
  if ( !a3 )
    goto LABEL_17;
  *(_BYTE *)(a4 + 1) = *a2;
  if ( a3 == 1 )
    goto LABEL_17;
  v5 = a2[1];
  *(_WORD *)(a4 + 2) = v5 & 0xF | (*(unsigned __int8 *)(a4 + 3) << 8) | v5 & 0x10 | v5 & 0x60 | v5 & 0x80;
  if ( a3 == 2 )
    goto LABEL_17;
  *(_WORD *)(a4 + 2) = v5 | ((a2[2] & 0xF) << 8) & 0xFFF | (((a2[2] >> 4) & 0xF) << 12);
  if ( a3 == 3 )
    goto LABEL_17;
  *(_BYTE *)(a4 + 4) = a2[3];
  if ( a3 == 4 )
    goto LABEL_17;
  v6 = a2[4] & 0xF | (*(unsigned __int8 *)(a4 + 6) << 8) | a2[4] & 0x10 | a2[4] & 0x60 | a2[4] & 0x80;
  *(_WORD *)(a4 + 5) = v6;
  if ( a3 == 5 )
    goto LABEL_17;
  *(_WORD *)(a4 + 5) = (unsigned __int8)v6 | ((a2[5] & 0xF) << 8) & 0xFFF | (a2[5] >> 4 << 12);
  if ( a3 == 6 )
    goto LABEL_17;
  *(_BYTE *)(a4 + 7) = a2[6];
  if ( a3 == 7
    || (v7 = a2[7],
        *(_WORD *)(a4 + 8) = v7 & 0xF | (*(unsigned __int8 *)(a4 + 9) << 8) | v7 & 0x10 | v7 & 0x60 | v7 & 0x80,
        a3 == 8)
    || (*(_WORD *)(a4 + 8) = v7 | ((a2[8] & 0xF) << 8) & 0xFFF | (((a2[8] >> 4) & 0xF) << 12), a3 == 9)
    || (*(_BYTE *)(a4 + 10) = a2[9], a3 == 10)
    || (v8 = a2[10] & 0xF | (*(unsigned __int8 *)(a4 + 12) << 8) | a2[10] & 0x10 | a2[10] & 0x60 | a2[10] & 0x80,
        *(_WORD *)(a4 + 11) = v8,
        a3 == 11)
    || (*(_WORD *)(a4 + 11) = (unsigned __int8)v8 | ((a2[11] & 0xF) << 8) & 0xFFF | (a2[11] >> 4 << 12), a3 == 12) )
  {
LABEL_17:
    *(_BYTE *)a4 = 0;
    return 4;
  }
  else
  {
    *(_BYTE *)(a4 + 13) = a2[12];
    return 0;
  }
}
