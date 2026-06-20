__int64 __fastcall wma_convert_eht_cap(__int64 result, _DWORD *a2, unsigned int *a3, unsigned int *a4, int a5)
{
  unsigned __int64 v5; // x8
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x8
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x8
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x8
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x8
  unsigned __int64 v22; // x8
  unsigned __int64 v23; // x8
  unsigned __int64 v24; // x8
  unsigned __int64 v25; // x8
  unsigned __int64 v26; // x8
  unsigned __int64 v27; // x8
  unsigned __int64 v28; // x8
  unsigned __int64 v29; // x8
  unsigned __int64 v30; // x8
  unsigned __int64 v31; // x8
  unsigned __int64 v32; // x8
  unsigned __int64 v33; // x8
  unsigned __int64 v34; // x8
  unsigned __int64 v35; // x8
  unsigned __int64 v36; // x8
  unsigned __int64 v37; // x8
  unsigned __int64 v38; // x8
  unsigned __int64 v39; // x8
  unsigned __int64 v40; // x8
  unsigned __int64 v41; // x8
  unsigned __int64 v42; // x8
  unsigned __int64 v43; // x8
  unsigned __int64 v44; // x9
  __int64 v45; // x8
  unsigned __int64 v46; // x8
  unsigned __int64 v47; // x8
  unsigned __int64 v48; // x8
  unsigned __int64 v49; // x8
  unsigned __int64 v50; // x8
  unsigned __int64 v51; // x8
  unsigned __int64 v52; // x8
  unsigned __int64 v53; // x8
  unsigned __int64 v54; // x8
  unsigned __int64 v55; // x8
  unsigned __int64 v56; // x8
  unsigned __int64 v57; // x8
  unsigned __int64 v58; // x8
  unsigned __int64 v59; // x8
  unsigned __int64 v60; // x8
  unsigned __int64 v61; // x8
  unsigned __int64 v62; // x8
  __int64 v63; // x9
  unsigned __int64 v64; // x10
  __int64 v65; // x8
  unsigned __int64 v66; // x10
  unsigned __int64 v67; // x9
  unsigned __int64 v68; // x8
  unsigned __int64 v69; // x8
  unsigned __int64 v70; // x9
  unsigned int v71; // w11

  *(_BYTE *)result = 1;
  v5 = *(_QWORD *)(result + 1) & 0xFFFFFFFFFFFFFFFELL | *a2 & 1;
  *(_QWORD *)(result + 1) = v5;
  v6 = v5 & 0xFFFFFFFFFFFFFFFDLL | (2 * (((unsigned __int64)(unsigned int)*a2 >> 1) & 1));
  *(_QWORD *)(result + 1) = v6;
  v7 = v6 & 0xFFFFFFFFFFFFFFFBLL | (4 * (((unsigned __int64)(unsigned int)*a2 >> 2) & 1));
  *(_QWORD *)(result + 1) = v7;
  v8 = v7 & 0xFFFFFFFFFFFFFFF7LL | (8 * (((unsigned __int64)(unsigned int)*a2 >> 3) & 1));
  *(_QWORD *)(result + 1) = v8;
  v9 = v8 & 0xFFFFFFFFFFFFFFEFLL | (16 * (((unsigned __int64)(unsigned int)*a2 >> 4) & 1));
  *(_QWORD *)(result + 1) = v9;
  v10 = v9 & 0xFFFFFFFFFFFFFFDFLL | (32 * (((unsigned __int64)(unsigned int)*a2 >> 5) & 1));
  *(_QWORD *)(result + 1) = v10;
  v11 = v10 & 0xFFFFFFFFFFFFFF3FLL | ((((unsigned __int64)(unsigned int)*a2 >> 6) & 3) << 6);
  *(_QWORD *)(result + 1) = v11;
  v12 = v11 & 0xFFFFFFFFFFFFFEFFLL | ((((unsigned __int64)(unsigned int)*a2 >> 8) & 1) << 8);
  *(_QWORD *)(result + 1) = v12;
  v13 = v12 & 0xFFFFFFFFFFFFFDFFLL | ((((unsigned __int64)(unsigned int)*a2 >> 9) & 1) << 9);
  *(_QWORD *)(result + 1) = v13;
  v14 = v13 & 0xFFFFFFFFFFFFFBFFLL | ((((unsigned __int64)(unsigned int)*a2 >> 10) & 1) << 10);
  *(_QWORD *)(result + 1) = v14;
  v15 = v14 & 0xFFFFFFFFFFFFF7FFLL | ((((unsigned __int64)(unsigned int)*a2 >> 11) & 1) << 11);
  *(_QWORD *)(result + 1) = v15;
  v16 = v15 & 0xFFFFFFFFFFFFCFFFLL | ((((unsigned __int64)(unsigned int)*a2 >> 12) & 3) << 12);
  *(_QWORD *)(result + 1) = v16;
  v17 = v16 & 0xFFFFFFFFFFFDFFFFLL | ((((unsigned __int64)*a3 >> 1) & 1) << 17);
  *(_QWORD *)(result + 1) = v17;
  v18 = v17 & 0xFFFFFFFFFFFBFFFFLL | ((((unsigned __int64)*a3 >> 2) & 1) << 18);
  *(_QWORD *)(result + 1) = v18;
  v19 = v18 & 0xFFFFFFFFFFF7FFFFLL | ((((unsigned __int64)*a3 >> 3) & 1) << 19);
  *(_QWORD *)(result + 1) = v19;
  v20 = v19 & 0xFFFFFFFFFFEFFFFFLL | ((((unsigned __int64)*a3 >> 4) & 1) << 20);
  *(_QWORD *)(result + 1) = v20;
  v21 = v20 & 0xFFFFFFFFFFDFFFFFLL | ((((unsigned __int64)*a3 >> 5) & 1) << 21);
  *(_QWORD *)(result + 1) = v21;
  v22 = v21 & 0xFFFFFFFFFFBFFFFFLL | ((((unsigned __int64)*a3 >> 6) & 1) << 22);
  *(_QWORD *)(result + 1) = v22;
  v23 = v22 & 0xFFFFFFFFF8FFFFFFLL | ((((unsigned __int64)*a3 >> 7) & 7) << 24);
  *(_QWORD *)(result + 1) = v23;
  v24 = v23 & 0xFFFFFFFFC7FFFFFFLL | ((((unsigned __int64)*a3 >> 10) & 7) << 27);
  *(_QWORD *)(result + 1) = v24;
  v25 = v24 & 0xFFFFFFFE3FFFFFFFLL | ((unsigned __int64)((unsigned __int8)BYTE1(*a3) >> 5) << 30);
  *(_QWORD *)(result + 1) = v25;
  v26 = v25 & 0xFFFFFFF1FFFFFFFFLL | ((unsigned __int64)(*((_WORD *)a3 + 1) & 7) << 33);
  *(_QWORD *)(result + 1) = v26;
  v27 = v26 & 0xFFFFFF8FFFFFFFFFLL | ((unsigned __int64)((*a3 >> 19) & 7) << 36);
  *(_QWORD *)(result + 1) = v27;
  v28 = v27 & 0xFFFFFC7FFFFFFFFFLL | ((unsigned __int64)((*a3 >> 22) & 7) << 39);
  *(_QWORD *)(result + 1) = v28;
  v29 = v28 & 0xFFFFFBFFFFFFFFFFLL | ((unsigned __int64)((*a3 & 0x2000000) != 0) << 42);
  *(_QWORD *)(result + 1) = v29;
  v30 = v29 & 0xFFFFF7FFFFFFFFFFLL | ((unsigned __int64)((*a3 & 0x4000000) != 0) << 43);
  *(_QWORD *)(result + 1) = v30;
  v31 = v30 & 0xFFFFEFFFFFFFFFFFLL | ((unsigned __int64)((*a3 & 0x8000000) != 0) << 44);
  *(_QWORD *)(result + 1) = v31;
  v32 = v31 & 0xFFFFDFFFFFFFFFFFLL | ((unsigned __int64)((*a3 & 0x10000000) != 0) << 45);
  *(_QWORD *)(result + 1) = v32;
  v33 = v32 & 0xFFFFBFFFFFFFFFFFLL | ((unsigned __int64)((*a3 & 0x20000000) != 0) << 46);
  *(_QWORD *)(result + 1) = v33;
  v34 = v33 & 0xFFFF7FFFFFFFFFFFLL | ((unsigned __int64)((*a3 & 0x40000000) != 0) << 47);
  *(_QWORD *)(result + 1) = v34;
  v35 = v34 & 0xFFFEFFFFFFFFFFFFLL | ((((unsigned __int64)*a3 >> 31) & 1) << 48);
  *(_QWORD *)(result + 1) = v35;
  v36 = v35 & 0xFFFDFFFFFFFFFFFFLL | ((unsigned __int64)(a3[1] & 1) << 49);
  *(_QWORD *)(result + 1) = v36;
  v37 = v36 & 0xFFFBFFFFFFFFFFFFLL | ((unsigned __int64)((a3[1] & 2) != 0) << 50);
  *(_QWORD *)(result + 1) = v37;
  v38 = v37 & 0xFFF7FFFFFFFFFFFFLL | ((unsigned __int64)((a3[1] & 4) != 0) << 51);
  *(_QWORD *)(result + 1) = v38;
  v39 = v38 & 0xFFEFFFFFFFFFFFFFLL | ((unsigned __int64)((a3[1] & 8) != 0) << 52);
  *(_QWORD *)(result + 1) = v39;
  v40 = v39 & 0xF0FFFFFFFFFFFFFFLL | ((unsigned __int64)(((unsigned __int8)a3[1] >> 4) & 0xF) << 56);
  *(_QWORD *)(result + 1) = v40;
  v41 = v40 & 0xEFFFFFFFFFFFFFFFLL | ((unsigned __int64)(BYTE1(a3[1]) & 1) << 60);
  *(_QWORD *)(result + 1) = v41;
  v42 = v41 & 0xDFFFFFFFFFFFFFFFLL | ((unsigned __int64)((a3[1] & 0x200) != 0) << 61);
  *(_QWORD *)(result + 1) = v42;
  v43 = v42 & 0xBFFFFFFFFFFFFFFFLL | ((unsigned __int64)((a3[1] & 0x400) != 0) << 62);
  *(_QWORD *)(result + 1) = v43;
  v44 = ((unsigned __int64)a3[1] << 52) & 0x8000000000000000LL | v43 & 0x7FFFFFFFFFFFFFFFLL;
  v45 = *(_QWORD *)(result + 9);
  *(_QWORD *)(result + 1) = v44;
  v46 = v45 & 0xFFFFFFFFFFFFFFFCLL | ((unsigned __int64)a3[1] >> 12) & 3;
  *(_QWORD *)(result + 9) = v46;
  v47 = v46 & 0xFFFFFFFFFFFFFF83LL | (4 * (((unsigned __int64)a3[1] >> 14) & 0x1F));
  *(_QWORD *)(result + 9) = v47;
  v48 = v47 & 0xFFFFFFFFFFFFF87FLL | ((((unsigned __int64)a3[1] >> 19) & 0xF) << 7);
  *(_QWORD *)(result + 9) = v48;
  v49 = v48 & 0xFFFFFFFFFFFFF7FFLL | ((((unsigned __int64)a3[1] >> 23) & 1) << 11);
  *(_QWORD *)(result + 9) = v49;
  v50 = v49 & 0xFFFFFFFFFFFFEFFFLL | ((((unsigned __int64)a3[1] >> 24) & 1) << 12);
  *(_QWORD *)(result + 9) = v50;
  v51 = v50 & 0xFFFFFFFFFFFFDFFFLL | ((((unsigned __int64)a3[1] >> 25) & 1) << 13);
  *(_QWORD *)(result + 9) = v51;
  v52 = v51 & 0xFFFFFFFFFFFFBFFFLL | ((((unsigned __int64)a3[1] >> 26) & 1) << 14);
  *(_QWORD *)(result + 9) = v52;
  v53 = v52 & 0xFFFFFFFFFFFF7FFFLL | ((((unsigned __int64)a3[1] >> 27) & 1) << 15);
  *(_QWORD *)(result + 9) = v53;
  v54 = v53 & 0xFFFFFFFFFFFEFFFFLL | ((((unsigned __int64)a3[1] >> 28) & 1) << 16);
  *(_QWORD *)(result + 9) = v54;
  v55 = v54 & 0xFFFFFFFFFFFDFFFFLL | ((((unsigned __int64)a3[1] >> 29) & 1) << 17);
  *(_QWORD *)(result + 9) = v55;
  v56 = v55 & 0xFFFFFFFFFFFBFFFFLL | ((((unsigned __int64)a3[1] >> 30) & 1) << 18);
  *(_QWORD *)(result + 9) = v56;
  v57 = v56 & 0xFFFFFFFFFFF7FFFFLL | ((((unsigned __int64)a3[1] >> 31) & 1) << 19);
  *(_QWORD *)(result + 9) = v57;
  v58 = v57 & 0xFFFFFFFFFFEFFFFFLL | ((unsigned __int64)(a3[2] & 1) << 20);
  *(_QWORD *)(result + 9) = v58;
  v59 = v58 & 0xFFFFFFFFFFDFFFFFLL | ((((unsigned __int64)a3[2] >> 1) & 1) << 21);
  *(_QWORD *)(result + 9) = v59;
  v60 = v59 & 0xFFFFFFFFFFBFFFFFLL | ((((unsigned __int64)a3[2] >> 2) & 1) << 22);
  *(_QWORD *)(result + 9) = v60;
  v61 = v60 & 0xFFFFFFFFFF7FFFFFLL | ((((unsigned __int64)a3[2] >> 3) & 1) << 23);
  *(_QWORD *)(result + 9) = v61;
  v62 = v61 & 0xFFFFFFFFFEFFFFFFLL | ((((unsigned __int64)a3[2] >> 4) & 1) << 24);
  *(_QWORD *)(result + 9) = v62;
  v63 = *a4;
  v64 = v62 & 0xFF0000000FFFFFFFLL
      | (unsigned int)((_DWORD)v63 << 28)
      | ((unsigned __int64)((unsigned __int8)v63 >> 4) << 32)
      | ((unsigned __int64)(((unsigned int)v63 >> 8) & 0xF) << 36)
      | ((unsigned __int64)((unsigned __int16)v63 >> 12) << 40)
      | ((unsigned __int64)(WORD1(v63) & 0xF) << 44)
      | (v63 << 28) & 0xF0000000000000LL
      | ((unsigned __int64)(((unsigned int)v63 >> 20) & 0xF) << 48);
  v65 = *(_QWORD *)(result + 17);
  v66 = v64 & 0xF0FFFFFFFFFFFFFFLL | ((unsigned __int64)((unsigned int)v63 >> 28) << 56);
  *(_QWORD *)(result + 9) = v66;
  v67 = a4[1];
  v68 = v65 & 0xFFFFFFFFFFF00000LL | (v67 >> 4) & 0xFFFFF;
  *(_QWORD *)(result + 9) = v66 & 0xFFFFFFFFFFFFFFFLL | ((unsigned __int64)(unsigned __int8)v67 << 60);
  *(_QWORD *)(result + 17) = v68;
  if ( a5 == 2 )
  {
    v69 = (a4[2] << 20)
        | ((unsigned __int64)((unsigned __int16)a4[2] >> 12) << 32)
        | ((unsigned __int64)(HIWORD(a4[2]) & 0xF) << 36)
        | ((unsigned __int64)((a4[2] >> 20) & 0xF) << 40)
        | v68 & 0xFFFFF000000FFFFFLL;
    *(_QWORD *)(result + 17) = v69;
    v70 = a4[3];
    v71 = *(_BYTE *)(result + 25) & 0xF0 | ((unsigned int)v70 >> 20) & 0xF;
    *(_QWORD *)(result + 17) = v69 & 0xFFFFFFFFFFFLL
                             | ((v70 & 0xF) << 44)
                             | ((unsigned __int64)((unsigned __int8)v70 >> 4) << 48)
                             | ((unsigned __int64)(((unsigned int)v70 >> 8) & 0xF) << 52)
                             | ((unsigned __int64)((unsigned __int16)v70 >> 12) << 56)
                             | (v70 >> 16 << 60);
    *(_BYTE *)(result + 25) = v71;
  }
  return result;
}
