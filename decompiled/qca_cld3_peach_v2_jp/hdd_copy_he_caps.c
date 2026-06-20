void *__fastcall hdd_copy_he_caps(_BYTE *a1, __int64 a2)
{
  void *result; // x0
  char v5; // w8
  char v6; // w8
  char v7; // w8
  char v8; // w8
  char v9; // w9
  char v10; // w8
  char v11; // w10
  char v12; // w9
  char v13; // w8
  char v14; // w10
  char v15; // w8
  char v16; // w10
  __int64 v17; // x9
  char v18; // w8
  char v19; // w8
  char v20; // w8
  char v21; // w8
  char v22; // w8
  char v23; // w8
  char v24; // w9
  char v25; // w8
  char v26; // w10
  char v27; // w8
  char v28; // w8
  char v29; // w8
  char v30; // w8
  char v31; // w9
  char v32; // w8
  char v33; // w10
  char v34; // w9
  char v35; // w10
  char v36; // w8
  char v37; // w8
  char v38; // w8
  char v39; // w8
  char v40; // w8
  char v41; // w8
  char v42; // w9
  __int64 v43; // x8
  char v44; // w9
  char v45; // w10
  char v46; // w8
  char v47; // w8
  char v48; // w8
  char v49; // w8
  char v50; // w8
  char v51; // w8
  unsigned __int64 v52; // x9
  char v53; // w8
  char v54; // w10
  char v55; // w8
  char v56; // w8
  char v57; // w8
  char v58; // w8
  char v59; // w8
  unsigned __int64 v60; // x8
  char v61; // w10
  __int64 v62; // x8
  char v63; // w9
  char v64; // w10
  char v65; // w8
  char v66; // w8
  char v67; // w8
  char v68; // w8
  char v69; // w9
  unsigned int v70; // w8
  unsigned int v71; // w8
  char v72; // w9
  char v73; // w10
  char v74; // w10
  unsigned int v75; // w9
  int v76; // w8
  char v77; // w10
  char v78; // w10
  unsigned int v79; // w9
  char v80; // w10
  unsigned __int64 v81; // x8
  char v82; // w10
  unsigned __int64 v83; // x8
  char v84; // w10
  unsigned __int64 v85; // x8
  char v86; // w10

  result = qdf_mem_set(a1 + 715, 0x11u, 0);
  v5 = a1[715];
  a1[715] = v5 & 0xFE;
  v6 = v5 & 0xFC | *(_BYTE *)(a2 + 1) & 1;
  a1[715] = v6;
  v7 = *(_BYTE *)(a2 + 1) & 2 | v6 & 0xFB;
  a1[715] = v7;
  v8 = *(_BYTE *)(a2 + 1) & 4 | v7 & 0xE7;
  a1[715] = v8;
  v9 = *(_BYTE *)(a2 + 1) & 0x18 | v8 & 7;
  v10 = a1[716];
  a1[715] = v9;
  v11 = *(_BYTE *)(a2 + 1);
  a1[716] = v10 & 0xFC;
  a1[715] = v11 & 0xE0 | v9;
  v12 = *(_BYTE *)(a2 + 2);
  v13 = v10 & 0xF0 | v12 & 3;
  a1[716] = v13;
  v14 = *(_BYTE *)(a2 + 2) & 0xC;
  a1[716] = v14 | v13 & 0x8F;
  v15 = *(_BYTE *)(a2 + 2) & 0x70 | v12 & 3 | v14;
  v16 = a1[717];
  a1[716] = v15;
  v17 = *(_QWORD *)(a2 + 1);
  a1[717] = v16 & 0xFE;
  a1[716] = v15 | (((v17 & 0x18000) != 0) << 7);
  if ( (*(_QWORD *)(a2 + 1) & 0x18000LL) != 0 )
    v18 = (v16 & 0xFC) + 1;
  else
    v18 = v16 & 0xFC;
  a1[717] = v18;
  v19 = *(_BYTE *)(a2 + 3) & 2 | v18 & 0xFB;
  a1[717] = v19;
  v20 = *(_BYTE *)(a2 + 3) & 4 | v19 & 0xF7;
  a1[717] = v20;
  v21 = *(_BYTE *)(a2 + 3) & 8 | v20 & 0xEF;
  a1[717] = v21;
  v22 = *(_BYTE *)(a2 + 3) & 0x10 | v21 & 0xCF;
  a1[717] = v22;
  v23 = *(_BYTE *)(a2 + 3) & 0x20 | v22 & 0x9F;
  a1[717] = v23;
  v24 = *(_BYTE *)(a2 + 3) & 0x40 | v23 & 0x3F;
  v25 = a1[718];
  a1[717] = v24;
  v26 = *(_BYTE *)(a2 + 3);
  a1[718] = v25 & 0xFD;
  a1[717] = v26 & 0x80 | v24;
  v27 = *(_BYTE *)(a2 + 4) & 2 | v25 & 0xF9;
  a1[718] = v27;
  v28 = *(_BYTE *)(a2 + 4) & 4 | v27 & 0xE7;
  a1[718] = v28;
  v29 = *(_BYTE *)(a2 + 4) & 0x18 | v28 & 0xDF;
  a1[718] = v29;
  v30 = *(_BYTE *)(a2 + 4) & 0x20 | v29 & 0xBF;
  a1[718] = v30;
  v31 = *(_BYTE *)(a2 + 4) & 0x40 | v30 & 0x3F;
  v32 = a1[719];
  a1[718] = v31;
  v33 = *(_BYTE *)(a2 + 4);
  a1[719] = v32 & 0xFE;
  v34 = v33 & 0x80 | v31;
  v35 = a1[720];
  a1[718] = v34;
  v36 = v32 & 0xFC | *(_BYTE *)(a2 + 5) & 1;
  a1[719] = v36;
  v37 = *(_BYTE *)(a2 + 5) & 2 | v36 & 0xFB;
  a1[719] = v37;
  v38 = *(_BYTE *)(a2 + 5) & 4 | v37 & 0xF7;
  a1[719] = v38;
  v39 = *(_BYTE *)(a2 + 5) & 8 | v38 & 0xEF;
  a1[719] = v39;
  v40 = *(_BYTE *)(a2 + 5) & 0x10 | v39 & 0xCF;
  a1[719] = v40;
  v41 = *(_BYTE *)(a2 + 5) & 0x20 | v40 & 0x9F;
  a1[719] = v41;
  v42 = *(_BYTE *)(a2 + 5) & 0x40 | v41 & 0x3F;
  a1[719] = v42;
  v43 = *(_QWORD *)(a2 + 1);
  a1[720] = v35 & 0xFC;
  LOBYTE(v43) = v42 | (((v43 & 0x70000000000LL) != 0) << 7);
  v44 = v35 & 0xF8;
  v45 = a1[721];
  a1[719] = v43;
  if ( (*(_QWORD *)(a2 + 1) & 0x70000000000LL) != 0 )
    v46 = v44 + 1;
  else
    v46 = v44;
  a1[720] = v46;
  v47 = (*(_QWORD *)(a2 + 1) >> 41) & 4 | v46 & 0xF7;
  a1[720] = v47;
  v48 = (*(_QWORD *)(a2 + 1) >> 41) & 8 | v47 & 0xEF;
  a1[720] = v48;
  v49 = (*(_QWORD *)(a2 + 1) >> 41) & 0x10 | v48 & 0xDF;
  a1[720] = v49;
  v50 = (*(_QWORD *)(a2 + 1) >> 41) & 0x20 | v49 & 0xBF;
  a1[720] = v50;
  v51 = (*(_QWORD *)(a2 + 1) >> 41) & 0x40 | v50 & 0x7F;
  a1[720] = v51;
  v52 = *(_QWORD *)(a2 + 1);
  a1[721] = v45 & 0xFD;
  v53 = (v52 >> 41) & 0x80 | v51;
  LOBYTE(v52) = v45 & 0xF9;
  v54 = a1[722];
  a1[720] = v53;
  v55 = (*(_QWORD *)(a2 + 1) >> 49) & 2 | v52;
  a1[721] = v55;
  v56 = (*(_QWORD *)(a2 + 1) >> 49) & 4 | v55 & 0xF7;
  a1[721] = v56;
  v57 = (*(_QWORD *)(a2 + 1) >> 49) & 8 | v56 & 0xEF;
  a1[721] = v57;
  v58 = (*(_QWORD *)(a2 + 1) >> 49) & 0x10 | v57 & 0xCF;
  a1[721] = v58;
  v59 = (*(_QWORD *)(a2 + 1) >> 49) & 0x20 | v58 & 0x9F;
  a1[721] = v59;
  LOBYTE(v52) = (*(_QWORD *)(a2 + 1) >> 49) & 0x40 | v59 & 0x3F;
  a1[721] = v52;
  v60 = *(_QWORD *)(a2 + 1);
  a1[722] = v54 & 0xF0;
  LOBYTE(v60) = (v60 >> 49) & 0x80 | v52;
  LOBYTE(v52) = v54 & 0xE0;
  v61 = a1[723];
  a1[721] = v60;
  LOBYTE(v60) = (*(_QWORD *)(a2 + 1) >> 57) & 0xF | v52;
  a1[722] = v60;
  LOBYTE(v60) = (*(_QWORD *)(a2 + 1) >> 57) & 0x10 | v60 & 0xDF;
  a1[722] = v60;
  LOBYTE(v60) = (*(_QWORD *)(a2 + 1) >> 57) & 0x20 | v60 & 0xBF;
  a1[722] = v60;
  LOBYTE(v52) = (*(_QWORD *)(a2 + 1) >> 57) & 0x40 | v60 & 0x3F;
  a1[722] = v52;
  v62 = *(_QWORD *)(a2 + 9);
  a1[723] = v61 & 0xFE;
  LOBYTE(v62) = v52 | (((v62 & 3) != 0) << 7);
  v63 = v61 & 0xFC;
  v64 = a1[724];
  a1[722] = v62;
  if ( (*(_QWORD *)(a2 + 9) & 3LL) != 0 )
    v65 = v63 + 1;
  else
    v65 = v63;
  a1[723] = v65;
  v66 = (*(_BYTE *)(a2 + 9) >> 1) & 2 | v65 & 0xF7;
  a1[723] = v66;
  v67 = v66 & 0xEF | *(_BYTE *)(a2 + 9) & 8;
  a1[723] = v67;
  v68 = v67 & 0x9F | *(_BYTE *)(a2 + 9) & 0x10;
  a1[723] = v68;
  v69 = *(_BYTE *)(a2 + 9) & 0x20 | v68 & 0x1F;
  a1[723] = v69;
  v70 = *(_DWORD *)(a2 + 9);
  a1[724] = v64 & 0xF8;
  a1[723] = (v70 >> 1) & 0xC0 | v69;
  v71 = *(_DWORD *)(a2 + 9);
  a1[724] = v64 & 0xC0 | (v71 >> 9) & 7;
  v72 = v64 & 0x80 | (v71 >> 9) & 7;
  v73 = (*(_DWORD *)(a2 + 9) >> 9) & 0x38;
  a1[724] = v73 | v72;
  LOBYTE(v71) = (*(_DWORD *)(a2 + 9) >> 9) & 0x40 | (v71 >> 9) & 7 | v73;
  v74 = a1[725];
  a1[724] = v71;
  v75 = *(_DWORD *)(a2 + 9);
  a1[725] = v74 & 0xFE;
  a1[724] = (v75 >> 9) & 0x80 | v71;
  v76 = *(_DWORD *)(a2 + 9);
  a1[725] = v74 & 0xFC | ((v76 & 0x20000) != 0);
  LOBYTE(v75) = v74 & 0xE0 | ((v76 & 0x20000) != 0);
  v77 = (*(_DWORD *)(a2 + 9) >> 17) & 2;
  a1[725] = v77 | v75;
  LOBYTE(v76) = (*(_DWORD *)(a2 + 9) >> 17) & 0x1C | ((v76 & 0x20000) != 0) | v77;
  v78 = a1[726];
  a1[725] = v76;
  v79 = *(_DWORD *)(a2 + 9);
  v78 &= 0xF8u;
  a1[726] = v78;
  a1[725] = (v79 >> 19) & 0xE0 | v76;
  LOBYTE(v76) = v78 | (*(_DWORD *)(a2 + 9) >> 27);
  v80 = a1[727];
  a1[726] = v76 & 0xC7;
  LOBYTE(v76) = (*(_QWORD *)(a2 + 9) >> 27) & 0x38 | v76 & 0x87;
  a1[726] = v76;
  LOBYTE(v79) = (*(_QWORD *)(a2 + 9) >> 27) & 0x40 | v76 & 0x3F;
  a1[726] = v79;
  v81 = *(_QWORD *)(a2 + 9);
  a1[727] = v80 & 0xFE;
  LOBYTE(v81) = (v81 >> 27) & 0x80 | v79;
  LOBYTE(v79) = v80 & 0xFC;
  v82 = a1[728];
  a1[726] = v81;
  LOBYTE(v81) = ((*(_QWORD *)(a2 + 9) & 0x800000000LL) != 0) | v79;
  a1[727] = v81;
  LOBYTE(v81) = (*(_QWORD *)(a2 + 9) >> 35) & 2 | v81 & 0xE3;
  a1[727] = v81;
  LOBYTE(v81) = (*(_QWORD *)(a2 + 9) >> 35) & 0x1C | v81 & 0xDF;
  a1[727] = v81;
  LOBYTE(v81) = (*(_QWORD *)(a2 + 9) >> 35) & 0x20 | v81 & 0x9F;
  a1[727] = v81;
  LOBYTE(v79) = (*(_QWORD *)(a2 + 9) >> 35) & 0x40 | v81 & 0x3F;
  a1[727] = v79;
  v83 = *(_QWORD *)(a2 + 9);
  a1[728] = v82 & 0xFE;
  LOBYTE(v83) = (v83 >> 35) & 0x80 | v79;
  LOBYTE(v79) = v82 & 0xFC;
  v84 = a1[729];
  a1[727] = v83;
  LOBYTE(v83) = ((*(_QWORD *)(a2 + 9) & 0x80000000000LL) != 0) | v79;
  a1[728] = v83;
  LOBYTE(v83) = (*(_QWORD *)(a2 + 9) >> 43) & 2 | v83 & 0xFB;
  a1[728] = v83;
  LOBYTE(v83) = (*(_QWORD *)(a2 + 9) >> 43) & 4 | v83 & 0xC7;
  a1[728] = v83;
  LOBYTE(v83) = (*(_QWORD *)(a2 + 9) >> 43) & 0x38 | v83 & 0x87;
  a1[728] = v83;
  LOBYTE(v79) = (*(_QWORD *)(a2 + 9) >> 43) & 0x40 | v83 & 0x3F;
  a1[728] = v79;
  v85 = *(_QWORD *)(a2 + 9);
  a1[729] = v84 & 0xFE;
  LOBYTE(v85) = (v85 >> 43) & 0x80 | v79;
  LOBYTE(v79) = v84 & 0xFC;
  v86 = a1[730];
  a1[728] = v85;
  LOBYTE(v85) = ((*(_QWORD *)(a2 + 9) & 0x8000000000000LL) != 0) | v79;
  a1[729] = v85;
  LOBYTE(v85) = (*(_QWORD *)(a2 + 9) >> 51) & 2 | v85 & 0xFB;
  a1[729] = v85;
  LOBYTE(v85) = (*(_QWORD *)(a2 + 9) >> 51) & 4 | v85 & 0xF7;
  a1[729] = v85;
  LOBYTE(v85) = (*(_QWORD *)(a2 + 9) >> 51) & 8 | v85 & 0xE7;
  a1[729] = v85;
  LOBYTE(v85) = (*(_QWORD *)(a2 + 9) >> 51) & 0x10 | v85 & 0xCF;
  a1[729] = v85;
  LOBYTE(v79) = (*(_QWORD *)(a2 + 9) >> 51) & 0x20 | v85 & 0x1F;
  a1[729] = v79;
  a1[729] = (*(_QWORD *)(a2 + 9) >> 51) & 0xC0 | v79;
  a1[730] = v86 & 0xFE;
  LOBYTE(v85) = ((*(_QWORD *)(a2 + 9) & 0x800000000000000LL) != 0) | v86 & 0xFC;
  a1[730] = v85;
  LOBYTE(v85) = (*(_QWORD *)(a2 + 9) >> 59) & 2 | v85 & 0xFB;
  a1[730] = v85;
  LOBYTE(v85) = (*(_QWORD *)(a2 + 9) >> 59) & 4 | v85 & 0xF7;
  a1[730] = v85;
  LOBYTE(v85) = (*(_QWORD *)(a2 + 9) >> 59) & 8 | v85 & 0xE7;
  a1[730] = v85;
  LOBYTE(v85) = (*(_QWORD *)(a2 + 9) >> 59) & 0x10 | v85 & 0xCF;
  a1[730] = v85;
  a1[730] = v85 & 0xDF | (32 * (*(_BYTE *)(a2 + 17) & 1));
  return result;
}
