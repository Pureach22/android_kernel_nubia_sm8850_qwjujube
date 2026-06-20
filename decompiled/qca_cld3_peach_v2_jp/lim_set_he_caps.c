unsigned __int8 *__fastcall lim_set_he_caps(__int64 a1, unsigned __int8 *a2, unsigned __int16 a3, char a4)
{
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned __int8 *result; // x0
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
  unsigned int v27; // w8
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
  unsigned __int64 v38; // x9
  unsigned __int64 v39; // x9
  unsigned __int64 v40; // x9
  unsigned __int64 v41; // x9
  unsigned __int64 v42; // x9
  unsigned __int64 v43; // x9
  unsigned __int64 v44; // x9
  unsigned __int64 v45; // x9
  unsigned int v46; // w8
  unsigned __int64 v47; // x9
  unsigned __int64 v48; // x9
  unsigned __int64 v49; // x9
  unsigned __int64 v50; // x9
  unsigned __int64 v51; // x9
  unsigned __int64 v52; // x9
  unsigned __int64 v53; // x9
  unsigned __int64 v54; // x9
  unsigned __int64 v55; // x9
  unsigned int v56; // w8
  unsigned int v57; // w8
  unsigned __int64 v58; // x9
  unsigned __int64 v59; // x9
  unsigned __int64 v60; // x9
  unsigned __int64 v61; // x9
  unsigned __int64 v62; // x9
  unsigned __int64 v63; // x9
  unsigned __int64 v64; // x9
  unsigned __int64 v65; // x9
  unsigned __int64 v66; // x9
  unsigned __int64 v67; // x9
  unsigned __int64 v68; // x9
  unsigned __int64 v69; // x9
  unsigned __int64 v70; // x9
  unsigned __int64 v71; // x10
  int v72; // w8
  unsigned int v73; // w8
  unsigned int v74; // w8
  unsigned int v75; // w8
  unsigned int v76; // w8
  unsigned int v77; // w8
  unsigned int v78; // w8
  unsigned int v79; // w8
  unsigned int v80; // w8
  unsigned int v81; // w8
  unsigned int v82; // w8
  unsigned int v83; // w8
  unsigned int v84; // w8
  unsigned int v85; // w8
  unsigned int v86; // w8
  unsigned int v87; // w8
  unsigned int v88; // w8
  __int64 v89; // x8
  _QWORD v90[3]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v91; // [xsp+20h] [xbp-30h]
  __int64 v92; // [xsp+28h] [xbp-28h]
  __int64 v93; // [xsp+30h] [xbp-20h]
  __int64 v94; // [xsp+38h] [xbp-18h]
  int v95; // [xsp+40h] [xbp-10h]
  __int64 v96; // [xsp+48h] [xbp-8h]

  v96 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v95 = 0;
  v93 = 0;
  v94 = 0;
  v91 = 0;
  v92 = 0;
  memset(v90, 0, sizeof(v90));
  v7 = populate_dot11f_he_caps_by_band(a1, a4 == 1, (int)v90);
  lim_log_he_cap(v8, v9, v10, v11, v12, v13, v14, v15, v7, (__int64)v90);
  result = wlan_get_ext_ie_ptr_from_ext_id("#", 1u, a2, a3);
  if ( result )
  {
    v17 = *(_DWORD *)(result + 3) & 0xFFFFFFFE | BYTE1(v90[0]) & 1;
    *(_DWORD *)(result + 3) = v17;
    v18 = v17 & 0xFFFFFFFD | (2 * ((*(_DWORD *)((char *)v90 + 1) >> 1) & 1));
    *(_DWORD *)(result + 3) = v18;
    v19 = v18 & 0xFFFFFFFB | (4 * ((*(_DWORD *)((char *)v90 + 1) >> 2) & 1));
    *(_DWORD *)(result + 3) = v19;
    v20 = v19 & 0xFFFFFFE7 | (8 * ((*(_DWORD *)((char *)v90 + 1) >> 3) & 3));
    *(_DWORD *)(result + 3) = v20;
    v21 = v20 & 0xFFFFFF1F | (32 * (BYTE1(v90[0]) >> 5));
    *(_DWORD *)(result + 3) = v21;
    v22 = v21 & 0xFFFFFCFF | (((*(_DWORD *)((char *)v90 + 1) >> 8) & 3) << 8);
    *(_DWORD *)(result + 3) = v22;
    v23 = v22 & 0xFFFFF3FF | (((*(_DWORD *)((char *)v90 + 1) >> 10) & 3) << 10);
    *(_DWORD *)(result + 3) = v23;
    v24 = v23 & 0xFFFF8FFF | (((*(_DWORD *)((char *)v90 + 1) >> 12) & 7) << 12);
    *(_DWORD *)(result + 3) = v24;
    v25 = v24 & 0xFFFE7FFF | (((*(_DWORD *)((char *)v90 + 1) >> 15) & 3) << 15);
    *(_DWORD *)(result + 3) = v25;
    v26 = v25 & 0xFFFDFFFF | (((*(_DWORD *)((char *)v90 + 1) >> 17) & 1) << 17);
    *(_DWORD *)(result + 3) = v26;
    v27 = v26 & 0xFFFBFFFF | (((*(_DWORD *)((char *)v90 + 1) >> 18) & 1) << 18);
    *(_DWORD *)(result + 3) = v27;
    v28 = v27 & 0xFFF7FFFF | (((*(_DWORD *)((char *)v90 + 1) >> 19) & 1) << 19);
    *(_DWORD *)(result + 3) = v28;
    v29 = v28 & 0xFFEFFFFF | (((*(_DWORD *)((char *)v90 + 1) >> 20) & 1) << 20);
    *(_DWORD *)(result + 3) = v29;
    v30 = v29 & 0xFFDFFFFF | (((*(_DWORD *)((char *)v90 + 1) >> 21) & 1) << 21);
    *(_DWORD *)(result + 3) = v30;
    v31 = v30 & 0xFFBFFFFF | (((*(_DWORD *)((char *)v90 + 1) >> 22) & 1) << 22);
    *(_DWORD *)(result + 3) = v31;
    v32 = v31 & 0xFF7FFFFF | (((*(_DWORD *)((char *)v90 + 1) >> 23) & 1) << 23);
    *(_DWORD *)(result + 3) = v32;
    v33 = v32 & 0xFDFFFFFF | (((*(_DWORD *)((char *)v90 + 1) >> 25) & 1) << 25);
    *(_DWORD *)(result + 3) = v33;
    v34 = v33 & 0xFBFFFFFF | (((*(_DWORD *)((char *)v90 + 1) >> 26) & 1) << 26);
    *(_DWORD *)(result + 3) = v34;
    v35 = v34 & 0xE7FFFFFF | (((*(_DWORD *)((char *)v90 + 1) >> 27) & 3) << 27);
    *(_DWORD *)(result + 3) = v35;
    v36 = v35 & 0xDFFFFFFF | (((*(_DWORD *)((char *)v90 + 1) >> 29) & 1) << 29);
    *(_DWORD *)(result + 3) = v36;
    v37 = v36 & 0xBFFFFFFF | (((*(_DWORD *)((char *)v90 + 1) >> 30) & 1) << 30);
    *(_DWORD *)(result + 3) = v37;
    *(_DWORD *)(result + 3) = *(_DWORD *)((_BYTE *)v90 + 1) & 0x80000000 | v37 & 0x7FFFFFFF;
    v38 = *(_QWORD *)(result + 7) & 0xFFFFFFFFFFFFFFFELL | HIDWORD(*(_QWORD *)((char *)v90 + 1)) & 1LL;
    *(_QWORD *)(result + 7) = v38;
    v39 = v38 & 0xFFFFFFFFFFFFFFFDLL | (2 * ((*(_QWORD *)((char *)v90 + 1) >> 33) & 1LL));
    *(_QWORD *)(result + 7) = v39;
    v40 = v39 & 0xFFFFFFFFFFFFFFFBLL | (4 * ((*(_QWORD *)((char *)v90 + 1) >> 34) & 1LL));
    *(_QWORD *)(result + 7) = v40;
    v41 = v40 & 0xFFFFFFFFFFFFFFF7LL | (8 * ((*(_QWORD *)((char *)v90 + 1) >> 35) & 1LL));
    *(_QWORD *)(result + 7) = v41;
    v42 = v41 & 0xFFFFFFFFFFFFFFDFLL | (32 * ((*(_QWORD *)((char *)v90 + 1) >> 37) & 1LL));
    *(_QWORD *)(result + 7) = v42;
    v43 = v42 & 0xFFFFFFFFFFFFFFEFLL | (16 * ((*(_QWORD *)((char *)v90 + 1) >> 36) & 1LL));
    *(_QWORD *)(result + 7) = v43;
    v44 = v43 & 0xFFFFFFFFFFFFFFBFLL | (((*(_QWORD *)((char *)v90 + 1) >> 38) & 1LL) << 6);
    *(_QWORD *)(result + 7) = v44;
    v45 = v44 & 0xFFFFFFFFFFFFDFFFLL | (((*(_QWORD *)((char *)v90 + 1) >> 46) & 1LL) << 13);
    *(_QWORD *)(result + 7) = v45;
    if ( *(_DWORD *)(a1 + 17124) )
    {
      v46 = *(_DWORD *)(result + 15);
    }
    else
    {
      *(_QWORD *)((char *)v90 + 1) &= 0xFFC7FFFFFFFFFFFFLL;
      v45 = *(_QWORD *)(result + 7);
      v46 = *(_DWORD *)(result + 15) & 0xFFFBFFFF;
      *(_DWORD *)(result + 15) = v46;
    }
    v47 = v45 & 0xFFFFFFFFFF01FFFFLL | (((*(_QWORD *)((char *)v90 + 1) >> 50) & 0x7FLL) << 17);
    *(_QWORD *)(result + 7) = v47;
    v48 = v47 & 0xFFFFFFFFF0FFFFFFLL | (((*(_QWORD *)((char *)v90 + 1) >> 57) & 0xFLL) << 24);
    *(_QWORD *)(result + 7) = v48;
    v49 = v48 & 0xFFFFFFFFEFFFFFFFLL | (((*(_QWORD *)((char *)v90 + 1) >> 61) & 1LL) << 28);
    *(_QWORD *)(result + 7) = v49;
    v50 = v49 & 0xFFFFFFFFDFFFFFFFLL | (((*(_QWORD *)((char *)v90 + 1) >> 62) & 1LL) << 29);
    *(_QWORD *)(result + 7) = v50;
    v51 = v50 & 0xFFFFFFFFBFFFFFFFLL | (*(_QWORD *)((char *)v90 + 1) >> 63 << 30);
    *(_QWORD *)(result + 7) = v51;
    v52 = v51 & 0xFFFFFFFE7FFFFFFFLL | ((unsigned __int64)(BYTE1(v90[1]) & 3) << 31);
    *(_QWORD *)(result + 7) = v52;
    v53 = v52 & 0xFFFFFFFDFFFFFFFFLL | (((*(_QWORD *)((char *)&v90[1] + 1) >> 2) & 1LL) << 33);
    *(_QWORD *)(result + 7) = v53;
    v54 = v53 & 0xFFFFFFFBFFFFFFFFLL | (((*(_QWORD *)((char *)&v90[1] + 1) >> 3) & 1LL) << 34);
    *(_QWORD *)(result + 7) = v54;
    v55 = v54 & 0xFFFFFFF7FFFFFFFFLL | (((*(_QWORD *)((char *)&v90[1] + 1) >> 4) & 1LL) << 35);
    *(_QWORD *)(result + 7) = v55;
    v56 = v46 & 0xFFFFBFFF | ((((unsigned int)(*(_QWORD *)((char *)&v90[1] + 1) >> 35) >> 14) & 1) << 14);
    *(_DWORD *)(result + 15) = v56;
    v57 = v56 & 0xFFFF7FFF | ((((unsigned int)(*(_QWORD *)((char *)&v90[1] + 1) >> 35) >> 15) & 1) << 15);
    *(_DWORD *)(result + 15) = v57;
    v58 = v55 & 0xFFFFFFCFFFFFFFFFLL | (((*(_QWORD *)((char *)&v90[1] + 1) >> 5) & 3LL) << 36);
    *(_QWORD *)(result + 7) = v58;
    v59 = v58 & 0xFFFFFF3FFFFFFFFFLL | (((*(_QWORD *)((char *)&v90[1] + 1) >> 7) & 3LL) << 38);
    *(_QWORD *)(result + 7) = v59;
    v60 = v59 & 0xFFFFF8FFFFFFFFFFLL | (((*(_QWORD *)((char *)&v90[1] + 1) >> 9) & 7LL) << 40);
    *(_QWORD *)(result + 7) = v60;
    v61 = v60 & 0xFFFFC7FFFFFFFFFFLL | (((*(_QWORD *)((char *)&v90[1] + 1) >> 12) & 7LL) << 43);
    *(_QWORD *)(result + 7) = v61;
    v62 = v61 & 0xFFFFBFFFFFFFFFFFLL | (((*(_QWORD *)((char *)&v90[1] + 1) >> 15) & 1LL) << 46);
    *(_QWORD *)(result + 7) = v62;
    v63 = v62 & 0xFFFF7FFFFFFFFFFFLL | (((*(_QWORD *)((char *)&v90[1] + 1) >> 16) & 1LL) << 47);
    *(_QWORD *)(result + 7) = v63;
    v64 = v63 & 0xFFFEFFFFFFFFFFFFLL | (((*(_QWORD *)((char *)&v90[1] + 1) >> 17) & 1LL) << 48);
    *(_QWORD *)(result + 7) = v64;
    v65 = v64 & 0xFFFDFFFFFFFFFFFFLL | (((*(_QWORD *)((char *)&v90[1] + 1) >> 18) & 1LL) << 49);
    *(_QWORD *)(result + 7) = v65;
    v66 = v65 & 0xFFE3FFFFFFFFFFFFLL | (((*(_QWORD *)((char *)&v90[1] + 1) >> 19) & 7LL) << 50);
    *(_QWORD *)(result + 7) = v66;
    v67 = v66 & 0xFF1FFFFFFFFFFFFFLL | (((*(_QWORD *)((char *)&v90[1] + 1) >> 24) & 7LL) << 53);
    *(_QWORD *)(result + 7) = v67;
    v68 = v67 & 0xF8FFFFFFFFFFFFFFLL | (((*(_QWORD *)((char *)&v90[1] + 1) >> 27) & 7LL) << 56);
    *(_QWORD *)(result + 7) = v68;
    v69 = v68 & 0xC7FFFFFFFFFFFFFFLL | (((*(_QWORD *)((char *)&v90[1] + 1) >> 30) & 7LL) << 59);
    *(_QWORD *)(result + 7) = v69;
    v70 = v69 & 0xBFFFFFFFFFFFFFFFLL | (((*(_QWORD *)((char *)&v90[1] + 1) >> 33) & 1LL) << 62);
    *(_QWORD *)(result + 7) = v70;
    v71 = (*(_QWORD *)((char *)&v90[1] + 1) << 29) & 0x8000000000000000LL | v70 & 0x7FFFFFFFFFFFFFFFLL;
    *(_QWORD *)(result + 7) = v71;
    v72 = v57 & 0xFFFFFFFE | (*(_QWORD *)((char *)&v90[1] + 1) >> 35) & 1;
    *(_DWORD *)(result + 15) = v72;
    v73 = v72 & 0xFFFFFFFD | (2 * (((unsigned int)(*(_QWORD *)((char *)&v90[1] + 1) >> 35) >> 1) & 1));
    *(_DWORD *)(result + 15) = v73;
    v74 = v73 & 0xFFFFFFE3 | (4 * (((unsigned int)(*(_QWORD *)((char *)&v90[1] + 1) >> 35) >> 2) & 7));
    *(_DWORD *)(result + 15) = v74;
    v75 = v74 & 0xFFFFFFDF | (32 * (((unsigned int)(*(_QWORD *)((char *)&v90[1] + 1) >> 35) >> 5) & 1));
    *(_DWORD *)(result + 15) = v75;
    v76 = v75 & 0xFFFFFFBF | ((((unsigned int)(*(_QWORD *)((char *)&v90[1] + 1) >> 35) >> 6) & 1) << 6);
    *(_DWORD *)(result + 15) = v76;
    v77 = v76 & 0xFFFFFF7F | ((((unsigned int)(*(_QWORD *)((char *)&v90[1] + 1) >> 35) >> 7) & 1) << 7);
    *(_DWORD *)(result + 15) = v77;
    v78 = v77 & 0xFFFFFEFF | ((((unsigned int)(*(_QWORD *)((char *)&v90[1] + 1) >> 35) >> 8) & 1) << 8);
    *(_DWORD *)(result + 15) = v78;
    v79 = v78 & 0xFFFFFDFF | ((((unsigned int)(*(_QWORD *)((char *)&v90[1] + 1) >> 35) >> 9) & 1) << 9);
    *(_DWORD *)(result + 15) = v79;
    v80 = v79 & 0xFBFFFFFF | ((((unsigned int)(*(_QWORD *)((char *)&v90[1] + 1) >> 35) >> 26) & 1) << 26);
    *(_DWORD *)(result + 15) = v80;
    v81 = v80 & 0xF7FFFFFF | ((((unsigned int)(*(_QWORD *)((char *)&v90[1] + 1) >> 35) >> 27) & 1) << 27);
    *(_DWORD *)(result + 15) = v81;
    v82 = v81 & 0xFFFFFBFF | ((((unsigned int)(*(_QWORD *)((char *)&v90[1] + 1) >> 35) >> 10) & 1) << 10);
    *(_DWORD *)(result + 15) = v82;
    v83 = v82 & 0xFFFFC7FF | ((((unsigned int)(*(_QWORD *)((char *)&v90[1] + 1) >> 35) >> 11) & 7) << 11);
    *(_DWORD *)(result + 15) = v83;
    v84 = v83 & 0xFFFEFFFF | ((((unsigned int)(*(_QWORD *)((char *)&v90[1] + 1) >> 35) >> 16) & 1) << 16);
    *(_DWORD *)(result + 15) = v84;
    v85 = v84 & 0xFFFDFFFF | ((((unsigned int)(*(_QWORD *)((char *)&v90[1] + 1) >> 35) >> 17) & 1) << 17);
    *(_DWORD *)(result + 15) = v85;
    v86 = v85 & 0xFFFBFFFF | ((((unsigned int)(*(_QWORD *)((char *)&v90[1] + 1) >> 35) >> 18) & 1) << 18);
    *(_DWORD *)(result + 15) = v86;
    v87 = v86 & 0xFFF7FFFF | ((((unsigned int)(*(_QWORD *)((char *)&v90[1] + 1) >> 35) >> 19) & 1) << 19);
    *(_DWORD *)(result + 15) = v87;
    v88 = v87 & 0xFFEFFFFF | ((((unsigned int)(*(_QWORD *)((char *)&v90[1] + 1) >> 35) >> 20) & 1) << 20);
    *(_DWORD *)(result + 15) = v88;
    *(_DWORD *)(result + 15) = v88 & 0xFFDFFFFF
                             | ((((unsigned int)(*(_QWORD *)((char *)&v90[1] + 1) >> 35) >> 21) & 1) << 21);
    *(_QWORD *)(result + 7) = v71 & 0xFFFFFFFFFFFEFFFFLL | (((*(_QWORD *)((char *)v90 + 1) >> 49) & 1LL) << 16);
    *((_DWORD *)result + 5) = HIDWORD(v90[2]);
    v89 = *(_QWORD *)((char *)v90 + 1);
    if ( (*(_QWORD *)((char *)v90 + 1) & 0x10000000000000LL) != 0 )
    {
      *((_DWORD *)result + 6) = v91;
      v89 = *(_QWORD *)((char *)v90 + 1);
      a2[1] += 4;
    }
    if ( (v89 & 0x20000000000000LL) != 0 )
    {
      *((_DWORD *)result + 7) = HIDWORD(v91);
      a2[1] += 4;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
