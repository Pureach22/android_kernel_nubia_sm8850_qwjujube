__int64 __fastcall lim_set_ht_caps(__int64 a1, unsigned __int8 *a2, unsigned __int16 a3)
{
  unsigned __int8 *ie_ptr_from_eid; // x19
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 result; // x0
  int v15; // w8
  unsigned int v16; // w8
  unsigned int v17; // w8
  unsigned int v18; // w8
  unsigned int v19; // w8
  unsigned int v20; // w8
  unsigned int v21; // w8
  unsigned int v22; // w8
  unsigned int v23; // w8
  unsigned int v24; // w8
  unsigned int v25; // w8
  unsigned int v26; // w8
  unsigned __int8 v27; // w9
  unsigned int v28; // w8
  unsigned int v29; // w8
  unsigned int v30; // w8
  unsigned int v31; // w8
  unsigned int v32; // w8
  unsigned int v33; // w8
  unsigned int v34; // w8
  unsigned int v35; // w8
  unsigned int v36; // w8
  unsigned int v37; // w8
  unsigned int v38; // w8
  unsigned int v39; // w8
  unsigned int v40; // w8
  int v41; // w9
  unsigned int v42; // w9
  int v43; // w9
  unsigned int v44; // w9
  unsigned int v45; // w9
  unsigned int v46; // w9
  unsigned int v47; // w9
  unsigned int v48; // w9
  unsigned int v49; // w9
  _QWORD v50[2]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v51; // [xsp+18h] [xbp-38h]
  __int64 v52; // [xsp+20h] [xbp-30h]
  __int64 v53; // [xsp+28h] [xbp-28h]
  __int64 v54; // [xsp+30h] [xbp-20h]
  __int64 v55; // [xsp+38h] [xbp-18h]
  int v56; // [xsp+40h] [xbp-10h]
  __int64 v57; // [xsp+48h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v56 = 0;
  v54 = 0;
  v55 = 0;
  v52 = 0;
  v53 = 0;
  v50[1] = 0;
  v51 = 0;
  v50[0] = 0;
  populate_dot11f_ht_caps(a1, 0, v50);
  ie_ptr_from_eid = wlan_get_ie_ptr_from_eid(0x2Du, a2, a3);
  result = qdf_trace_msg(
             0x35u,
             8u,
             "%s: p_ie: %pK dot11_ht_cap.supportedMCSSet[0]: 0x%x",
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             "lim_set_ht_caps",
             ie_ptr_from_eid,
             BYTE4(v50[0]));
  if ( ie_ptr_from_eid )
  {
    v15 = *((_WORD *)ie_ptr_from_eid + 1) & 0xFFFE | BYTE1(v50[0]) & 1;
    *((_WORD *)ie_ptr_from_eid + 1) = v15;
    v16 = v15 & 0xFFFFFFFD | (2 * ((*(unsigned __int16 *)((char *)v50 + 1) >> 1) & 1));
    *((_WORD *)ie_ptr_from_eid + 1) = v16;
    v17 = v16 & 0xFFFFFFF3 | (4 * ((*(unsigned __int16 *)((char *)v50 + 1) >> 2) & 3));
    *((_WORD *)ie_ptr_from_eid + 1) = v17;
    v18 = v17 & 0xFFFFFFEF | (16 * ((*(unsigned __int16 *)((char *)v50 + 1) >> 4) & 1));
    *((_WORD *)ie_ptr_from_eid + 1) = v18;
    v19 = v18 & 0xFFFFFFDF | (32 * ((*(unsigned __int16 *)((char *)v50 + 1) >> 5) & 1));
    *((_WORD *)ie_ptr_from_eid + 1) = v19;
    v20 = v19 & 0xFFFFFFBF | (((*(unsigned __int16 *)((char *)v50 + 1) >> 6) & 1) << 6);
    *((_WORD *)ie_ptr_from_eid + 1) = v20;
    v21 = v20 & 0xFFFFFF7F | (((*(unsigned __int16 *)((char *)v50 + 1) >> 7) & 1) << 7);
    *((_WORD *)ie_ptr_from_eid + 1) = v21;
    v22 = v21 & 0xFFFFFCFF | ((HIBYTE(*(unsigned __int16 *)((char *)v50 + 1)) & 3) << 8);
    *((_WORD *)ie_ptr_from_eid + 1) = v22;
    v23 = v22 & 0xFFFFFBFF | (((*(unsigned __int16 *)((char *)v50 + 1) >> 10) & 1) << 10);
    *((_WORD *)ie_ptr_from_eid + 1) = v23;
    v24 = v23 & 0xFFFFF7FF | (((*(unsigned __int16 *)((char *)v50 + 1) >> 11) & 1) << 11);
    *((_WORD *)ie_ptr_from_eid + 1) = v24;
    v25 = v24 & 0xFFFFEFFF | (((*(unsigned __int16 *)((char *)v50 + 1) >> 12) & 1) << 12);
    *((_WORD *)ie_ptr_from_eid + 1) = v25;
    v26 = v25 & 0xFFFFDFFF | (((*(unsigned __int16 *)((char *)v50 + 1) >> 13) & 1) << 13);
    *((_WORD *)ie_ptr_from_eid + 1) = v26;
    LOWORD(v26) = v26 & 0xBFFF | (((*(_WORD *)((char *)v50 + 1) >> 14) & 1) << 14);
    *((_WORD *)ie_ptr_from_eid + 1) = v26;
    *((_WORD *)ie_ptr_from_eid + 1) = *(_WORD *)((_BYTE *)v50 + 1) & 0x8000 | v26 & 0x7FFF;
    v27 = ie_ptr_from_eid[4] & 0xFC | BYTE3(v50[0]) & 3;
    ie_ptr_from_eid[4] = v27;
    ie_ptr_from_eid[4] = v27 & 0xE3 | BYTE3(v50[0]) & 0x1C;
    result = (__int64)qdf_mem_copy(ie_ptr_from_eid + 5, (char *)v50 + 4, 0x10u);
    v28 = *(_DWORD *)(ie_ptr_from_eid + 21) & 0xFFFFFFFE | BYTE4(v51) & 1;
    *(_DWORD *)(ie_ptr_from_eid + 21) = v28;
    v29 = v28 & 0xFFFFFFF9 | (2 * ((HIDWORD(v51) >> 1) & 3));
    *(_DWORD *)(ie_ptr_from_eid + 21) = v29;
    v30 = v29 & 0xFFFFFCFF | (((HIDWORD(v51) >> 8) & 3) << 8);
    *(_DWORD *)(ie_ptr_from_eid + 21) = v30;
    v31 = v30 & 0xFFFEFFFF | ((HIWORD(HIDWORD(v51)) & 1) << 16);
    *(_DWORD *)(ie_ptr_from_eid + 21) = v31;
    v32 = v31 & 0xFFFDFFFF | (((HIDWORD(v51) >> 17) & 1) << 17);
    *(_DWORD *)(ie_ptr_from_eid + 21) = v32;
    v33 = v32 & 0xFFFBFFFF | (((HIDWORD(v51) >> 18) & 1) << 18);
    *(_DWORD *)(ie_ptr_from_eid + 21) = v33;
    v34 = v33 & 0xFFF7FFFF | (((HIDWORD(v51) >> 19) & 1) << 19);
    *(_DWORD *)(ie_ptr_from_eid + 21) = v34;
    v35 = v34 & 0xFFEFFFFF | (((HIDWORD(v51) >> 20) & 1) << 20);
    *(_DWORD *)(ie_ptr_from_eid + 21) = v35;
    v36 = v35 & 0xFFDFFFFF | (((HIDWORD(v51) >> 21) & 1) << 21);
    *(_DWORD *)(ie_ptr_from_eid + 21) = v36;
    v37 = v36 & 0xFF3FFFFF | (((HIDWORD(v51) >> 22) & 3) << 22);
    *(_DWORD *)(ie_ptr_from_eid + 21) = v37;
    v38 = v37 & 0xFEFFFFFF | ((HIBYTE(HIDWORD(v51)) & 1) << 24);
    *(_DWORD *)(ie_ptr_from_eid + 21) = v38;
    v39 = v38 & 0xFDFFFFFF | (((HIDWORD(v51) >> 25) & 1) << 25);
    *(_DWORD *)(ie_ptr_from_eid + 21) = v39;
    v40 = v39 & 0xE3FFFFFF | (((HIDWORD(v51) >> 26) & 7) << 26);
    *(_DWORD *)(ie_ptr_from_eid + 21) = v40;
    *(_DWORD *)(ie_ptr_from_eid + 21) = HIDWORD(v51) & 0xE0000000 | v40 & 0x1FFFFFFF;
    v41 = *(_WORD *)(ie_ptr_from_eid + 25) & 0xFFF8 | v52 & 7;
    *(_WORD *)(ie_ptr_from_eid + 25) = v41;
    v42 = v41 & 0xFFFFFFE7 | (8 * (((unsigned __int16)v52 >> 3) & 3));
    *(_WORD *)(ie_ptr_from_eid + 25) = v42;
    LOWORD(v42) = v42 & 0xFF9F | (32 * (((unsigned __int16)v52 >> 5) & 3));
    *(_WORD *)(ie_ptr_from_eid + 25) = v42;
    LOWORD(v40) = v42 & 0xFE7F | v52 & 0x180;
    v43 = ie_ptr_from_eid[27];
    *(_WORD *)(ie_ptr_from_eid + 25) = v40;
    v44 = v43 & 0xFFFFFFFE | BYTE2(v52) & 1;
    ie_ptr_from_eid[27] = v44;
    v45 = v44 & 0xFFFFFFFD | (2 * ((BYTE2(v52) >> 1) & 1));
    ie_ptr_from_eid[27] = v45;
    v46 = v45 & 0xFFFFFFFB | (4 * ((BYTE2(v52) >> 2) & 1));
    ie_ptr_from_eid[27] = v46;
    v47 = v46 & 0xFFFFFFF7 | (8 * ((BYTE2(v52) >> 3) & 1));
    ie_ptr_from_eid[27] = v47;
    v48 = v47 & 0xFFFFFFEF | (16 * ((BYTE2(v52) >> 4) & 1));
    ie_ptr_from_eid[27] = v48;
    v49 = v48 & 0xFFFFFFDF | (32 * ((BYTE2(v52) >> 5) & 1));
    ie_ptr_from_eid[27] = v49;
    ie_ptr_from_eid[27] = v49 & 0xBF | BYTE2(v52) & 0x40;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
