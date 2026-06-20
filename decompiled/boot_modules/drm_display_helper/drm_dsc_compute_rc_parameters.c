__int64 __fastcall drm_dsc_compute_rc_parameters(__int64 a1)
{
  unsigned int v1; // w9
  int v2; // w8
  unsigned int v3; // w12
  int v4; // w10
  char v5; // w11
  unsigned __int64 v6; // x10
  __int64 v7; // x13
  int v8; // w8
  bool v9; // zf
  __int64 v10; // x11
  unsigned int v11; // w8
  __int64 v12; // x14
  unsigned __int64 v13; // x12
  unsigned __int64 v14; // x13
  __int64 v15; // x12
  unsigned int v16; // w16
  int v17; // w12
  __int64 v18; // x13
  int v19; // w14
  int v20; // w15
  int v21; // w15
  __int64 v22; // x16
  unsigned int v23; // w1
  __int64 v25; // x17
  unsigned __int64 v26; // x8
  unsigned __int64 v27; // x11
  int v28; // w15
  int v29; // w14
  unsigned __int64 v30; // x10

  if ( (*(_BYTE *)(a1 + 129) & 1) != 0 || *(_BYTE *)(a1 + 128) == 1 )
  {
    v1 = *(unsigned __int16 *)(a1 + 16);
    v2 = *(unsigned __int16 *)(a1 + 4) >> 1;
    v3 = (v2 * v1 + 127) >> 7;
  }
  else
  {
    v2 = *(unsigned __int16 *)(a1 + 4);
    v1 = *(unsigned __int16 *)(a1 + 16);
    v4 = v1 * v2 + 254;
    if ( (int)(v1 * v2 + 127) >= 0 )
      v4 = v1 * v2 + 127;
    v3 = v4 >> 7;
  }
  v5 = *(_BYTE *)(a1 + 2);
  *(_WORD *)(a1 + 122) = v3;
  v6 = (1431655766 * (unsigned __int64)(unsigned int)(v2 + 2)) >> 32;
  if ( (v5 & 1) != 0 )
  {
    LODWORD(v7) = *(unsigned __int8 *)(a1 + 121);
    v8 = 3 * (v7 + 4 * *(unsigned __int8 *)(a1 + 1));
    v10 = (unsigned int)(v8 + 6);
    v9 = v8 == -6;
    v11 = *(unsigned __int16 *)(a1 + 6);
    if ( v9 )
    {
      v10 = 0;
      goto LABEL_18;
    }
  }
  else
  {
    v7 = *(unsigned __int8 *)(a1 + 121);
    if ( *(_BYTE *)(a1 + 128) == 1 )
      v10 = (12 * *(unsigned __int8 *)(a1 + 1) + 4 * (*(unsigned __int8 *)(a1 + 1) + (_DWORD)v7)) | 2u;
    else
      v10 = 3 * v7 + 12LL * *(unsigned __int8 *)(a1 + 1) + 2;
    v11 = *(unsigned __int16 *)(a1 + 6);
  }
  v12 = (int)(8 * (unsigned __int16)v3 * v11);
  v13 = (unsigned int)v7;
  v14 = v12 - v10;
  do
  {
    if ( !(v14 % v13) )
      break;
    --v10;
    ++v14;
  }
  while ( v10 );
LABEL_18:
  v15 = *(unsigned __int8 *)(a1 + 108);
  if ( v15 - 8 > v6 )
  {
    LOBYTE(v15) = v6 + 8;
    *(_BYTE *)(a1 + 108) = v6 + 8;
  }
  if ( (unsigned __int8)v15 < 9u )
    LOWORD(v16) = 4095;
  else
    v16 = (unsigned int)v6 / ((unsigned int)(unsigned __int8)v15 - 8);
  v17 = *(unsigned __int16 *)(a1 + 22);
  v18 = *(unsigned __int16 *)(a1 + 104);
  *(_WORD *)(a1 + 110) = v16;
  v19 = v1 * v17;
  v20 = v1 * v17 + 8;
  if ( v20 < 0 )
    v20 = v1 * v17 + 23;
  v21 = v10 + v18 - (v20 >> 4);
  *(_WORD *)(a1 + 118) = v21;
  if ( (unsigned int)v18 <= (unsigned __int16)v21 )
  {
    _drm_dev_dbg(0, 0, 2, "FinalOfs < RcModelSze for this InitialXmitDelay\n");
    return 4294967262LL;
  }
  else
  {
    v22 = 8 * (int)v18 / (int)(v18 - (unsigned __int16)v21);
    if ( v11 < 2 )
      LOWORD(v23) = 0;
    else
      v23 = (v11 + (*(unsigned __int8 *)(a1 + 27) << 11) - 2) / (v11 - 1);
    v25 = *(unsigned __int16 *)(a1 + 28);
    *(_WORD *)(a1 + 114) = v23;
    v26 = (((v10 + (unsigned int)v18 - v25) << 11) + (unsigned int)v6 * (unsigned __int64)v11 - 1)
        / ((unsigned int)v6
         * (unsigned __int64)v11);
    *(_WORD *)(a1 + 116) = v26;
    if ( (unsigned int)v22 < 0xA )
      LOWORD(v27) = 0;
    else
      v27 = ((unsigned __int64)(unsigned __int16)v21 << 11)
          / (((unsigned __int16)v26 + (unsigned __int64)(unsigned __int16)v23)
           * (v22 - 9));
    v28 = v19 + 15;
    v29 = v19 + 30;
    *(_WORD *)(a1 + 112) = v27;
    if ( v28 >= 0 )
      v29 = v28;
    v30 = (v1 + 16 * (v18 + (v29 >> 4) - v25 + *(unsigned __int8 *)(a1 + 27) * (unsigned __int64)(unsigned int)v6) - 1)
        / v1;
    *(_WORD *)(a1 + 24) = v30 - v17;
    *(_WORD *)(a1 + 124) = ((unsigned int)v30 * v1) >> 4;
    return 0;
  }
}
