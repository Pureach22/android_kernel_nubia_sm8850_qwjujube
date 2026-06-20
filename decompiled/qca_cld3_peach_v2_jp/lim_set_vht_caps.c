unsigned __int8 *__fastcall lim_set_vht_caps(__int64 a1, unsigned __int8 *a2, unsigned __int16 a3)
{
  unsigned __int8 *result; // x0
  unsigned int v6; // w8
  unsigned int v7; // w8
  unsigned int v8; // w8
  unsigned int v9; // w8
  unsigned int v10; // w8
  unsigned int v11; // w8
  unsigned int v12; // w8
  unsigned int v13; // w8
  unsigned int v14; // w8
  unsigned int v15; // w8
  unsigned int v16; // w8
  unsigned int v17; // w8
  unsigned int v18; // w8
  unsigned int v19; // w8
  unsigned int v20; // w8
  unsigned int v21; // w8
  unsigned int v22; // w8
  unsigned int v23; // w8
  unsigned int v24; // w8
  __int64 v25; // [xsp+8h] [xbp-18h] BYREF
  __int64 v26; // [xsp+10h] [xbp-10h]
  __int64 v27; // [xsp+18h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = 0;
  v26 = 0;
  populate_dot11f_vht_caps(a1, 0, &v25);
  result = wlan_get_ie_ptr_from_eid(0xBFu, a2, a3);
  if ( result )
  {
    v6 = *(_DWORD *)(result + 2) & 0xFFFFFFFC | BYTE1(v25) & 3;
    *(_DWORD *)(result + 2) = v6;
    v7 = v6 & 0xFFFFFFF3 | (4 * ((*(unsigned __int16 *)((char *)&v25 + 1) >> 2) & 3));
    *(_DWORD *)(result + 2) = v7;
    v8 = v7 & 0xFFFFFFEF | (16 * ((*(unsigned __int16 *)((char *)&v25 + 1) >> 4) & 1));
    *(_DWORD *)(result + 2) = v8;
    v9 = v8 & 0xFFFFFFDF | (32 * ((*(unsigned __int16 *)((char *)&v25 + 1) >> 5) & 1));
    *(_DWORD *)(result + 2) = v9;
    v10 = v9 & 0xFFFFFFBF | (((*(unsigned __int16 *)((char *)&v25 + 1) >> 6) & 1) << 6);
    *(_DWORD *)(result + 2) = v10;
    v11 = v10 & 0xFFFFFF7F | (((*(unsigned __int16 *)((char *)&v25 + 1) >> 7) & 1) << 7);
    *(_DWORD *)(result + 2) = v11;
    v12 = v11 & 0xFFFFF8FF | ((HIBYTE(*(unsigned __int16 *)((char *)&v25 + 1)) & 7) << 8);
    *(_DWORD *)(result + 2) = v12;
    v13 = v12 & 0xFFFFF7FF | (((*(unsigned __int16 *)((char *)&v25 + 1) >> 11) & 1) << 11);
    *(_DWORD *)(result + 2) = v13;
    v14 = v13 & 0xFFFFEFFF | (((*(unsigned __int16 *)((char *)&v25 + 1) >> 12) & 1) << 12);
    *(_DWORD *)(result + 2) = v14;
    v15 = v14 & 0xFFFF1FFF | (*(_WORD *)((char *)&v25 + 1) >> 13 << 13);
    *(_DWORD *)(result + 2) = v15;
    v16 = v15 & 0xFFF8FFFF | ((BYTE3(v25) & 7) << 16);
    *(_DWORD *)(result + 2) = v16;
    v17 = v16 & 0xFFF7FFFF | (((BYTE3(v25) >> 3) & 1) << 19);
    *(_DWORD *)(result + 2) = v17;
    v18 = v17 & 0xFFEFFFFF | (((BYTE3(v25) >> 4) & 1) << 20);
    *(_DWORD *)(result + 2) = v18;
    v19 = v18 & 0xFFDFFFFF | (((BYTE3(v25) >> 5) & 1) << 21);
    *(_DWORD *)(result + 2) = v19;
    v20 = v19 & 0xFFBFFFFF | (((BYTE3(v25) >> 6) & 1) << 22);
    *(_DWORD *)(result + 2) = v20;
    v21 = v20 & 0xFC7FFFFF | ((BYTE4(v25) & 7) << 23);
    *(_DWORD *)(result + 2) = v21;
    v22 = v21 & 0xF3FFFFFF | (((WORD2(v25) >> 3) & 3) << 26);
    *(_DWORD *)(result + 2) = v22;
    v23 = v22 & 0xEFFFFFFF | (((WORD2(v25) >> 5) & 1) << 28);
    *(_DWORD *)(result + 2) = v23;
    v24 = v23 & 0xDFFFFFFF | (((WORD2(v25) >> 6) & 1) << 29);
    *(_DWORD *)(result + 2) = v24;
    *(_DWORD *)(result + 2) = (WORD2(v25) << 23) & 0xC0000000 | v24 & 0x3FFFFFFF;
    *((_WORD *)result + 3) = HIWORD(v25);
    LOWORD(v24) = v26;
    *((_DWORD *)result + 2) = v26;
    *((_WORD *)result + 6) = v24 & 0xC000 | WORD2(v26) & 0x3FFF;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
