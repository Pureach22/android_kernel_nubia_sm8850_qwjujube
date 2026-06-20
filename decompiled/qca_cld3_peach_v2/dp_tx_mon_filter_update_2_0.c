__int64 __fastcall dp_tx_mon_filter_update_2_0(
        _QWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x20
  __int64 v11; // x8
  int v12; // w12
  __int64 v13; // x9
  __int64 v14; // x11
  unsigned int v15; // w13
  unsigned __int64 v16; // x12
  unsigned int v17; // w13
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int num_mac_rings; // w0
  __int64 v27; // x21
  int v28; // w22
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x19
  __int64 v38; // x21
  __int64 v39; // x0
  __int64 v40; // x20
  __int64 v41; // x2
  const char *v42; // x2
  __int64 result; // x0
  int v44; // w8
  int v45; // w9
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  int *v54; // x21
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  int v63; // w8
  int v64; // w8
  int v65; // w8
  int v66; // w8
  int v67; // w9
  int v68; // w8
  int v69; // w9
  int v70; // w9
  int v71; // w8
  unsigned __int64 v72; // x9
  int v73; // w8
  unsigned __int64 v74; // x9
  int v75; // w8
  int v76; // w9
  int v77; // w8
  int v78; // w8
  int v79; // w9
  int v80; // w9
  int v81; // w8
  unsigned int v82; // w8
  unsigned int v83; // w8
  unsigned int v84; // w8
  unsigned int v85; // w8
  unsigned int v86; // w8
  int v87; // w8
  int v88; // w9
  int v89; // w9
  int v90; // w8
  int v91; // w8
  int v92; // w9
  __int64 v93; // x0
  __int64 v94; // x21
  int v95; // w8
  int v96; // w8
  __int64 v97; // [xsp+0h] [xbp-F0h] BYREF
  __int64 v98; // [xsp+8h] [xbp-E8h]
  __int64 v99; // [xsp+10h] [xbp-E0h]
  __int64 v100; // [xsp+18h] [xbp-D8h]
  __int64 v101; // [xsp+20h] [xbp-D0h]
  __int64 v102; // [xsp+28h] [xbp-C8h]
  __int64 v103; // [xsp+30h] [xbp-C0h]
  __int64 v104; // [xsp+38h] [xbp-B8h]
  __int64 v105; // [xsp+40h] [xbp-B0h]
  __int64 v106; // [xsp+48h] [xbp-A8h]
  __int64 v107; // [xsp+50h] [xbp-A0h]
  __int64 v108; // [xsp+58h] [xbp-98h]
  unsigned __int64 v109; // [xsp+60h] [xbp-90h]
  __int64 v110; // [xsp+68h] [xbp-88h]
  __int64 v111; // [xsp+70h] [xbp-80h]
  __int64 v112; // [xsp+78h] [xbp-78h]
  __int64 v113; // [xsp+80h] [xbp-70h]
  __int64 v114; // [xsp+88h] [xbp-68h]
  _QWORD v115[6]; // [xsp+90h] [xbp-60h] BYREF
  __int64 v116; // [xsp+C0h] [xbp-30h]
  __int64 v117; // [xsp+C8h] [xbp-28h]
  __int64 v118; // [xsp+D0h] [xbp-20h]
  __int64 v119; // [xsp+D8h] [xbp-18h]
  __int64 v120; // [xsp+E0h] [xbp-10h]
  __int64 v121; // [xsp+E8h] [xbp-8h]

  v121 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v113 = 0;
  v114 = 0;
  v111 = 0;
  v112 = 0;
  v109 = 0;
  v110 = 0;
  v107 = 0;
  v108 = 0;
  v105 = 0;
  v106 = 0;
  v103 = 0;
  v104 = 0;
  v101 = 0;
  v102 = 0;
  v99 = 0;
  v100 = 0;
  v97 = 0;
  v98 = 0;
  if ( a1 )
  {
    v9 = a1[1];
    if ( v9 )
    {
      v11 = 0;
      v12 = 0;
      v13 = a1[12057];
      do
      {
        v14 = *(_QWORD *)(*(_QWORD *)(v13 + 39328) + v11);
        if ( *(_BYTE *)(v14 + 716) == 1 )
        {
          v15 = HIDWORD(v108);
          LODWORD(v114) = v12 | 0x1000000;
          HIDWORD(v108) = *(_DWORD *)(v14 + 668) & 1
                        | HIDWORD(v108) & 0xFFFF0001
                        | (2 * (((unsigned int)(*(_DWORD *)(v14 + 668) | HIDWORD(v108)) >> 1) & 1)) & 0xFFFF0003
                        | (4 * (((unsigned int)(*(_DWORD *)(v14 + 668) | HIDWORD(v108)) >> 2) & 1)) & 0xFFFF0007
                        | (8 * (((unsigned int)(*(_DWORD *)(v14 + 668) | HIDWORD(v108)) >> 3) & 1)) & 0xFFFF000F
                        | (16 * (((unsigned int)(*(_DWORD *)(v14 + 668) | HIDWORD(v108)) >> 4) & 1)) & 0xFFFF001F
                        | (32 * (((unsigned int)(*(_DWORD *)(v14 + 668) | HIDWORD(v108)) >> 5) & 1)) & 0xFFFF003F
                        | ((((unsigned int)(*(_DWORD *)(v14 + 668) | HIDWORD(v108)) >> 6) & 1) << 6) & 0xFFFF007F
                        | ((((unsigned int)(*(_DWORD *)(v14 + 668) | HIDWORD(v108)) >> 7) & 1) << 7) & 0xFFFF00FF
                        | ((((unsigned int)(*(_DWORD *)(v14 + 668) | HIDWORD(v108)) >> 8) & 1) << 8) & 0xFFFF01FF
                        | ((((unsigned int)(*(_DWORD *)(v14 + 668) | HIDWORD(v108)) >> 9) & 1) << 9) & 0xFFFF03FF
                        | ((((unsigned int)(*(_DWORD *)(v14 + 668) | HIDWORD(v108)) >> 10) & 1) << 10) & 0xFFFF07FF
                        | ((((unsigned int)(*(_DWORD *)(v14 + 668) | HIDWORD(v108)) >> 11) & 1) << 11) & 0xFFFF0FFF
                        | ((((unsigned int)(*(_DWORD *)(v14 + 668) | HIDWORD(v108)) >> 12) & 1) << 12) & 0xFFFF1FFF
                        | ((((unsigned int)(*(_DWORD *)(v14 + 668) | HIDWORD(v108)) >> 13) & 1) << 13) & 0xFFFF3FFF
                        | ((((unsigned int)(*(_DWORD *)(v14 + 668) | HIDWORD(v108)) >> 14) & 1) << 14) & 0xFFFF7FFF
                        | ((((unsigned int)(*(_DWORD *)(v14 + 668) | HIDWORD(v108)) >> 15) & 1) << 15);
          HIDWORD(v108) = HIDWORD(v108) & 0xFF80FFFF
                        | ((((*(_DWORD *)(v14 + 668) | v15) >> 16) & 1) << 16) & 0xFF81FFFF
                        | ((((*(_DWORD *)(v14 + 668) | v15) >> 17) & 1) << 17) & 0xFF83FFFF
                        | ((((*(_DWORD *)(v14 + 668) | v15) >> 18) & 1) << 18) & 0xFF87FFFF
                        | ((((*(_DWORD *)(v14 + 668) | v15) >> 19) & 1) << 19) & 0xFF8FFFFF
                        | ((((*(_DWORD *)(v14 + 668) | v15) >> 20) & 1) << 20) & 0xFF9FFFFF
                        | ((((*(_DWORD *)(v14 + 668) | v15) >> 21) & 1) << 21) & 0xFFBFFFFF
                        | ((((*(_DWORD *)(v14 + 668) | v15) >> 22) & 1) << 22);
          v16 = v109;
          v109 = *(_QWORD *)(v14 + 672) & 1LL
               | v109 & 0xFFFFFFFFFFFFC001LL
               | (2 * (((unsigned __int64)(*(_DWORD *)(v14 + 672) | (unsigned int)v109) >> 1) & 1))
               & 0xFFFFFFFFFFFFC003LL
               | (4 * (((unsigned __int64)(*(_DWORD *)(v14 + 672) | (unsigned int)v109) >> 2) & 1))
               & 0xFFFFFFFFFFFFC007LL
               | (8 * (((unsigned __int64)(*(_DWORD *)(v14 + 672) | (unsigned int)v109) >> 3) & 1))
               & 0xFFFFFFFFFFFFC00FLL
               | (16 * (((unsigned __int64)(*(_DWORD *)(v14 + 672) | (unsigned int)v109) >> 4) & 1))
               & 0xFFFFFFFFFFFFC01FLL
               | (32 * (((unsigned __int64)(*(_DWORD *)(v14 + 672) | (unsigned int)v109) >> 5) & 1))
               & 0xFFFFFFFFFFFFC03FLL
               | ((((unsigned __int64)(*(_DWORD *)(v14 + 672) | (unsigned int)v109) >> 6) & 1) << 6)
               & 0xFFFFFFFFFFFFC07FLL
               | ((((unsigned __int64)(*(_DWORD *)(v14 + 672) | (unsigned int)v109) >> 7) & 1) << 7)
               & 0xFFFFFFFFFFFFC0FFLL
               | ((((unsigned __int64)(*(_DWORD *)(v14 + 672) | (unsigned int)v109) >> 8) & 1) << 8)
               & 0xFFFFFFFFFFFFC1FFLL
               | ((((unsigned __int64)(*(_DWORD *)(v14 + 672) | (unsigned int)v109) >> 9) & 1) << 9)
               & 0xFFFFFFFFFFFFC3FFLL
               | ((((unsigned __int64)(*(_DWORD *)(v14 + 672) | (unsigned int)v109) >> 10) & 1) << 10)
               & 0xFFFFFFFFFFFFC7FFLL
               | ((((unsigned __int64)(*(_DWORD *)(v14 + 672) | (unsigned int)v109) >> 11) & 1) << 11)
               & 0xFFFFFFFFFFFFCFFFLL
               | ((((unsigned __int64)(*(_DWORD *)(v14 + 672) | (unsigned int)v109) >> 12) & 1) << 12)
               & 0xFFFFFFFFFFFFDFFFLL
               | ((((unsigned __int64)(*(_DWORD *)(v14 + 672) | (unsigned int)v109) >> 13) & 1) << 13);
          v109 = v109 & 0xFFFFFFFFF0003FFFLL
               | ((((unsigned __int64)(*(_DWORD *)(v14 + 672) | (unsigned int)v16) >> 14) & 1) << 14)
               & 0xFFFFFFFFF0007FFFLL
               | ((((unsigned __int64)(*(_DWORD *)(v14 + 672) | (unsigned int)v16) >> 15) & 1) << 15)
               & 0xFFFFFFFFF000FFFFLL
               | ((((unsigned __int64)(*(_DWORD *)(v14 + 672) | (unsigned int)v16) >> 16) & 1) << 16)
               & 0xFFFFFFFFF001FFFFLL
               | ((((unsigned __int64)(*(_DWORD *)(v14 + 672) | (unsigned int)v16) >> 17) & 1) << 17)
               & 0xFFFFFFFFF003FFFFLL
               | ((((unsigned __int64)(*(_DWORD *)(v14 + 672) | (unsigned int)v16) >> 18) & 1) << 18)
               & 0xFFFFFFFFF007FFFFLL
               | ((((unsigned __int64)(*(_DWORD *)(v14 + 672) | (unsigned int)v16) >> 19) & 1) << 19)
               & 0xFFFFFFFFF00FFFFFLL
               | ((((unsigned __int64)(*(_DWORD *)(v14 + 672) | (unsigned int)v16) >> 20) & 1) << 20)
               & 0xFFFFFFFFF01FFFFFLL
               | ((((unsigned __int64)(*(_DWORD *)(v14 + 672) | (unsigned int)v16) >> 21) & 1) << 21)
               & 0xFFFFFFFFF03FFFFFLL
               | ((((unsigned __int64)(*(_DWORD *)(v14 + 672) | (unsigned int)v16) >> 22) & 1) << 22)
               & 0xFFFFFFFFF07FFFFFLL
               | ((((unsigned __int64)(*(_DWORD *)(v14 + 672) | (unsigned int)v16) >> 23) & 1) << 23)
               & 0xFFFFFFFFF0FFFFFFLL
               | ((((unsigned __int64)(*(_DWORD *)(v14 + 672) | (unsigned int)v16) >> 24) & 1) << 24)
               & 0xFFFFFFFFF1FFFFFFLL
               | ((((unsigned __int64)(*(_DWORD *)(v14 + 672) | (unsigned int)v16) >> 25) & 1) << 25)
               & 0xFFFFFFFFF3FFFFFFLL
               | ((((unsigned __int64)(*(_DWORD *)(v14 + 672) | (unsigned int)v16) >> 26) & 1) << 26)
               & 0xFFFFFFFFF7FFFFFFLL
               | ((((unsigned __int64)(*(_DWORD *)(v14 + 672) | (unsigned int)v16) >> 27) & 1) << 27);
          v109 = v109 & 0xFFFFF8000FFFFFFFLL
               | ((((unsigned __int64)(*(_DWORD *)(v14 + 672) | (unsigned int)v16) >> 28) & 1) << 28)
               & 0xFFFFF8001FFFFFFFLL
               | ((((unsigned __int64)(*(_DWORD *)(v14 + 672) | (unsigned int)v16) >> 29) & 1) << 29)
               & 0xFFFFF8003FFFFFFFLL
               | ((((unsigned __int64)(*(_DWORD *)(v14 + 672) | (unsigned int)v16) >> 30) & 1) << 30)
               & 0xFFFFF8007FFFFFFFLL
               | ((((unsigned __int64)(*(_DWORD *)(v14 + 672) | (unsigned int)v16) >> 31) & 1) << 31)
               & 0xFFFFF800FFFFFFFFLL
               | ((((*(_QWORD *)(v14 + 672) | v16) >> 32) & 1) << 32) & 0xFFFFF801FFFFFFFFLL
               | ((((*(_QWORD *)(v14 + 672) | v16) >> 33) & 1) << 33) & 0xFFFFF803FFFFFFFFLL
               | ((((*(_QWORD *)(v14 + 672) | v16) >> 34) & 1) << 34) & 0xFFFFF807FFFFFFFFLL
               | ((((*(_QWORD *)(v14 + 672) | v16) >> 35) & 1) << 35) & 0xFFFFF80FFFFFFFFFLL
               | ((((*(_QWORD *)(v14 + 672) | v16) >> 36) & 1) << 36) & 0xFFFFF81FFFFFFFFFLL
               | ((((*(_QWORD *)(v14 + 672) | v16) >> 37) & 1) << 37) & 0xFFFFF83FFFFFFFFFLL
               | ((((*(_QWORD *)(v14 + 672) | v16) >> 38) & 1) << 38) & 0xFFFFF87FFFFFFFFFLL
               | ((((*(_QWORD *)(v14 + 672) | v16) >> 39) & 1) << 39) & 0xFFFFF8FFFFFFFFFFLL
               | ((((*(_QWORD *)(v14 + 672) | v16) >> 40) & 1) << 40) & 0xFFFFF9FFFFFFFFFFLL
               | ((((*(_QWORD *)(v14 + 672) | v16) >> 41) & 1) << 41) & 0xFFFFFBFFFFFFFFFFLL
               | ((((*(_QWORD *)(v14 + 672) | v16) >> 42) & 1) << 42);
          v109 = v109 & 0xF80007FFFFFFFFFFLL
               | ((((*(_QWORD *)(v14 + 672) | v16) >> 43) & 1) << 43) & 0xF8000FFFFFFFFFFFLL
               | ((((*(_QWORD *)(v14 + 672) | v16) >> 44) & 1) << 44) & 0xF8001FFFFFFFFFFFLL
               | ((((*(_QWORD *)(v14 + 672) | v16) >> 45) & 1) << 45) & 0xF8003FFFFFFFFFFFLL
               | ((((*(_QWORD *)(v14 + 672) | v16) >> 46) & 1) << 46) & 0xF8007FFFFFFFFFFFLL
               | ((((*(_QWORD *)(v14 + 672) | v16) >> 47) & 1) << 47) & 0xF800FFFFFFFFFFFFLL
               | ((((*(_QWORD *)(v14 + 672) | v16) >> 48) & 1) << 48) & 0xF801FFFFFFFFFFFFLL
               | ((((*(_QWORD *)(v14 + 672) | v16) >> 49) & 1) << 49) & 0xF803FFFFFFFFFFFFLL
               | ((((*(_QWORD *)(v14 + 672) | v16) >> 50) & 1) << 50) & 0xF807FFFFFFFFFFFFLL
               | ((((*(_QWORD *)(v14 + 672) | v16) >> 51) & 1) << 51) & 0xF80FFFFFFFFFFFFFLL
               | ((((*(_QWORD *)(v14 + 672) | v16) >> 52) & 1) << 52) & 0xF81FFFFFFFFFFFFFLL
               | ((((*(_QWORD *)(v14 + 672) | v16) >> 53) & 1) << 53) & 0xF83FFFFFFFFFFFFFLL
               | ((((*(_QWORD *)(v14 + 672) | v16) >> 54) & 1) << 54) & 0xF87FFFFFFFFFFFFFLL
               | ((((*(_QWORD *)(v14 + 672) | v16) >> 55) & 1) << 55) & 0xF8FFFFFFFFFFFFFFLL
               | ((((*(_QWORD *)(v14 + 672) | v16) >> 56) & 1) << 56) & 0xF9FFFFFFFFFFFFFFLL
               | ((((*(_QWORD *)(v14 + 672) | v16) >> 57) & 1) << 57) & 0xFBFFFFFFFFFFFFFFLL
               | ((((*(_QWORD *)(v14 + 672) | v16) >> 58) & 1) << 58);
          v109 = (*(_QWORD *)(v14 + 672) | v16) & 0x8000000000000000LL
               | v109 & 0x7FFFFFFFFFFFFFFLL
               | ((((*(_QWORD *)(v14 + 672) | v16) >> 59) & 1) << 59) & 0xFFFFFFFFFFFFFFFLL
               | ((((*(_QWORD *)(v14 + 672) | v16) >> 60) & 1) << 60) & 0x1FFFFFFFFFFFFFFFLL
               | ((((*(_QWORD *)(v14 + 672) | v16) >> 61) & 1) << 61) & 0x3FFFFFFFFFFFFFFFLL
               | ((((*(_QWORD *)(v14 + 672) | v16) >> 62) & 1) << 62) & 0x7FFFFFFFFFFFFFFFLL;
          LODWORD(v16) = v110;
          LODWORD(v110) = *(_DWORD *)(v14 + 680) & 1
                        | v110 & 0xFFFF0001
                        | (2 * (((*(_DWORD *)(v14 + 680) | (unsigned int)v110) >> 1) & 1)) & 0xFFFF0003
                        | (4 * (((*(_DWORD *)(v14 + 680) | (unsigned int)v110) >> 2) & 1)) & 0xFFFF0007
                        | (8 * (((*(_DWORD *)(v14 + 680) | (unsigned int)v110) >> 3) & 1)) & 0xFFFF000F
                        | (16 * (((*(_DWORD *)(v14 + 680) | (unsigned int)v110) >> 4) & 1)) & 0xFFFF001F
                        | (32 * (((*(_DWORD *)(v14 + 680) | (unsigned int)v110) >> 5) & 1)) & 0xFFFF003F
                        | ((((*(_DWORD *)(v14 + 680) | (unsigned int)v110) >> 6) & 1) << 6) & 0xFFFF007F
                        | ((((*(_DWORD *)(v14 + 680) | (unsigned int)v110) >> 7) & 1) << 7) & 0xFFFF00FF
                        | ((((*(_DWORD *)(v14 + 680) | (unsigned int)v110) >> 8) & 1) << 8) & 0xFFFF01FF
                        | ((((*(_DWORD *)(v14 + 680) | (unsigned int)v110) >> 9) & 1) << 9) & 0xFFFF03FF
                        | ((((*(_DWORD *)(v14 + 680) | (unsigned int)v110) >> 10) & 1) << 10) & 0xFFFF07FF
                        | ((((*(_DWORD *)(v14 + 680) | (unsigned int)v110) >> 11) & 1) << 11) & 0xFFFF0FFF
                        | ((((*(_DWORD *)(v14 + 680) | (unsigned int)v110) >> 12) & 1) << 12) & 0xFFFF1FFF
                        | ((((*(_DWORD *)(v14 + 680) | (unsigned int)v110) >> 13) & 1) << 13) & 0xFFFF3FFF
                        | ((((*(_DWORD *)(v14 + 680) | (unsigned int)v110) >> 14) & 1) << 14) & 0xFFFF7FFF
                        | ((((*(_DWORD *)(v14 + 680) | (unsigned int)v110) >> 15) & 1) << 15);
          LODWORD(v110) = v110 & 0xFFC0FFFF
                        | ((((*(_DWORD *)(v14 + 680) | (unsigned int)v16) >> 16) & 1) << 16) & 0xFFC1FFFF
                        | ((((*(_DWORD *)(v14 + 680) | (unsigned int)v16) >> 17) & 1) << 17) & 0xFFC3FFFF
                        | ((((*(_DWORD *)(v14 + 680) | (unsigned int)v16) >> 18) & 1) << 18) & 0xFFC7FFFF
                        | ((((*(_DWORD *)(v14 + 680) | (unsigned int)v16) >> 19) & 1) << 19) & 0xFFCFFFFF
                        | ((((*(_DWORD *)(v14 + 680) | (unsigned int)v16) >> 20) & 1) << 20) & 0xFFDFFFFF
                        | ((((*(_DWORD *)(v14 + 680) | (unsigned int)v16) >> 21) & 1) << 21);
          HIDWORD(v110) |= *(_DWORD *)(v14 + 684);
          v111 |= *(_QWORD *)(v14 + 688);
          LODWORD(v112) = v112 | *(_DWORD *)(v14 + 696);
          WORD2(v112) |= *(_WORD *)(v14 + 700);
          LOBYTE(v113) = v113 | *(_BYTE *)(v14 + 704);
          *(_DWORD *)((char *)&v113 + 2) |= *(_DWORD *)(v14 + 706);
          v17 = v114;
          HIWORD(v113) |= *(_WORD *)(v14 + 710);
          LODWORD(v114) = *(_DWORD *)(v14 + 712) & 7
                        | v114 & 0xFFE00007
                        | (8 * (((*(_DWORD *)(v14 + 712) | (unsigned int)v114) >> 3) & 7)) & 0xFFE0003F
                        | ((((*(_DWORD *)(v14 + 712) | (unsigned int)v114) >> 6) & 7) << 6) & 0xFFE001FF
                        | ((((*(_DWORD *)(v14 + 712) | (unsigned int)v114) >> 9) & 1) << 9) & 0xFFE003FF
                        | ((((*(_DWORD *)(v14 + 712) | (unsigned int)v114) >> 10) & 1) << 10) & 0xFFE007FF
                        | ((((*(_DWORD *)(v14 + 712) | (unsigned int)v114) >> 11) & 1) << 11) & 0xFFE00FFF
                        | ((((*(_DWORD *)(v14 + 712) | (unsigned int)v114) >> 12) & 1) << 12) & 0xFFE01FFF
                        | (((((unsigned int)v114 | (16 * *(_DWORD *)(v14 + 712))) >> 13) & 1) << 13) & 0xFFE03FFF
                        | (((((unsigned int)v114 | (16 * *(_DWORD *)(v14 + 712))) >> 14) & 1) << 14) & 0xFFE07FFF
                        | (((((unsigned int)v114 | (16 * *(_DWORD *)(v14 + 712))) >> 15) & 1) << 15) & 0xFFE0FFFF
                        | (((((unsigned int)v114 | (16 * *(_DWORD *)(v14 + 712))) >> 16) & 1) << 16) & 0xFFE1FFFF
                        | (((((unsigned int)v114 | (*(_DWORD *)(v14 + 712) << 8)) >> 17) & 1) << 17) & 0xFFE3FFFF
                        | (((((unsigned int)v114 | (*(_DWORD *)(v14 + 712) << 8)) >> 18) & 1) << 18) & 0xFFE7FFFF
                        | (((((unsigned int)v114 | (*(_DWORD *)(v14 + 712) << 8)) >> 19) & 1) << 19) & 0xFFEFFFFF
                        | (((((unsigned int)v114 | (*(_DWORD *)(v14 + 712) << 8)) >> 20) & 1) << 20);
          v12 = v114 & 0xFF1FFFFF
              | ((((*(_DWORD *)(v14 + 712) | v17) >> 21) & 1) << 21) & 0xFF3FFFFF
              | ((((*(_DWORD *)(v14 + 712) | v17) >> 22) & 1) << 22) & 0xFF7FFFFF
              | ((((*(_DWORD *)(v14 + 712) | v17) >> 23) & 1) << 23);
          LODWORD(v114) = v12;
        }
        v11 += 8;
      }
      while ( v11 != 32 );
      qdf_trace_msg(
        0x73u,
        8u,
        "TXMON FINAL FILTER CONFIG:",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        v97,
        v98,
        v99,
        v100,
        v101,
        v102,
        v103,
        v104,
        v105,
        v106,
        v107,
        v108);
      dp_tx_mon_filter_show_filter((__int64)&v97, v18, v19, v20, v21, v22, v23, v24, v25);
      num_mac_rings = wlan_cfg_get_num_mac_rings(a1[36]);
      v27 = *(_QWORD *)(v9 + 20112);
      v28 = *(_DWORD *)(a1[12057] + 39352LL);
      qdf_trace_msg(
        0x73u,
        5u,
        "%s: %pK: srng type %d Max_mac_rings %d ",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "dp_tx_mon_ht2_ring_cfg",
        v9,
        4,
        num_mac_rings);
      v37 = *(_QWORD *)(v9 + 48);
      v38 = *(_QWORD *)(v27 + 536);
      v119 = 0;
      v120 = 0;
      v117 = 0;
      v118 = 0;
      v116 = 0;
      memset(v115, 0, sizeof(v115));
      v39 = _qdf_nbuf_alloc_no_recycler(60, 8, 4);
      if ( !v39 )
        goto LABEL_333;
      v40 = v39;
      hal_get_srng_params(*(_QWORD *)(v37 + 16), v38, (__int64)v115);
      if ( *(_DWORD *)(v40 + 116) )
      {
        v41 = 52;
      }
      else
      {
        v45 = *(_DWORD *)(v40 + 208);
        v44 = *(_DWORD *)(v40 + 212);
        if ( (unsigned int)(v44 - v45) > 0x33 )
          goto LABEL_16;
        v41 = (unsigned int)(v45 - v44 + 52);
      }
      if ( (unsigned int)pskb_expand_head(v40, 0, v41, 2080) )
      {
        dev_kfree_skb_any_reason(v40, 1);
        goto LABEL_331;
      }
LABEL_16:
      if ( skb_put(v40, 52) )
      {
        v54 = *(int **)(v40 + 224);
        skb_push(v40, 0);
        *v54 = 27;
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: pdev id %d, target_pdev_id %d",
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          "htt_h2t_tx_ring_cfg",
          0xFFFFFFFFLL,
          0);
        v63 = *v54 | 0xA0000;
        *v54 = v63;
        v64 = ((_DWORD)v116 << 21) & 0x1000000 | v63;
        *v54 = v64;
        v65 = (4 * v114) & 0x4000000 | v64;
        if ( v28 == 3 )
          v65 |= 0x8000000u;
        *v54 = v65;
        v54[1] = 2048;
        if ( WORD1(v113) )
          v66 = 2049;
        else
          v66 = 2048;
        v54[1] = v66;
        if ( HIWORD(v113) )
        {
          v66 |= 2u;
          v54[1] = v66;
        }
        if ( WORD2(v113) )
        {
          v66 |= 4u;
          v54[1] = v66;
        }
        v67 = v114;
        if ( (v114 & 7) != 0 )
        {
          v66 |= (v114 & 7) << 16;
          v54[1] = v66;
          v67 = v114;
        }
        if ( (v67 & 0x38) != 0 )
        {
          v66 |= (v67 << 16) & 0x380000;
          v54[1] = v66;
          v67 = v114;
        }
        if ( (v67 & 0x1C0) != 0 )
          v54[1] = (v67 << 16) & 0x1C00000 | v66;
        v54[2] = 0;
        v68 = WORD1(v113) != 0;
        v54[2] = v68;
        if ( HIWORD(v113) )
        {
          v68 |= 2u;
          v54[2] = v68;
        }
        if ( WORD2(v113) )
        {
          v68 |= 4u;
          v54[2] = v68;
        }
        v69 = v114;
        if ( (v114 & 0x1000) != 0 )
        {
          v68 |= 8u;
          v54[2] = v68;
          v69 = v114;
          if ( (v114 & 0x10000) == 0 )
          {
LABEL_38:
            if ( (v69 & 0x100000) == 0 )
              goto LABEL_39;
            goto LABEL_55;
          }
        }
        else if ( (v114 & 0x10000) == 0 )
        {
          goto LABEL_38;
        }
        v68 |= 0x10u;
        v54[2] = v68;
        v69 = v114;
        if ( (v114 & 0x100000) == 0 )
        {
LABEL_39:
          if ( (v69 & 0x800) == 0 )
            goto LABEL_40;
          goto LABEL_56;
        }
LABEL_55:
        v68 |= 0x20u;
        v54[2] = v68;
        v69 = v114;
        if ( (v114 & 0x800) == 0 )
        {
LABEL_40:
          if ( (v69 & 0x8000) == 0 )
            goto LABEL_41;
          goto LABEL_57;
        }
LABEL_56:
        v68 |= 0x40u;
        v54[2] = v68;
        v69 = v114;
        if ( (v114 & 0x8000) == 0 )
        {
LABEL_41:
          if ( (v69 & 0x80000) == 0 )
            goto LABEL_42;
          goto LABEL_58;
        }
LABEL_57:
        v68 |= 0x80u;
        v54[2] = v68;
        v69 = v114;
        if ( (v114 & 0x80000) == 0 )
        {
LABEL_42:
          if ( (v69 & 0x200) == 0 )
            goto LABEL_43;
          goto LABEL_59;
        }
LABEL_58:
        v68 |= 0x100u;
        v54[2] = v68;
        v69 = v114;
        if ( (v114 & 0x200) == 0 )
        {
LABEL_43:
          if ( (v69 & 0x2000) == 0 )
            goto LABEL_44;
          goto LABEL_60;
        }
LABEL_59:
        v68 |= 0x200u;
        v54[2] = v68;
        v69 = v114;
        if ( (v114 & 0x2000) == 0 )
        {
LABEL_44:
          if ( (v69 & 0x20000) == 0 )
            goto LABEL_45;
          goto LABEL_61;
        }
LABEL_60:
        v68 |= 0x400u;
        v54[2] = v68;
        v69 = v114;
        if ( (v114 & 0x20000) == 0 )
        {
LABEL_45:
          if ( (v69 & 0x400) == 0 )
            goto LABEL_46;
          goto LABEL_62;
        }
LABEL_61:
        v68 |= 0x800u;
        v54[2] = v68;
        v69 = v114;
        if ( (v114 & 0x400) == 0 )
        {
LABEL_46:
          if ( (v69 & 0x4000) == 0 )
            goto LABEL_47;
          goto LABEL_63;
        }
LABEL_62:
        v68 |= 0x1000u;
        v54[2] = v68;
        v69 = v114;
        if ( (v114 & 0x4000) == 0 )
        {
LABEL_47:
          if ( (v69 & 0x40000) == 0 )
            goto LABEL_48;
          goto LABEL_64;
        }
LABEL_63:
        v68 |= 0x2000u;
        v54[2] = v68;
        if ( (v114 & 0x40000) == 0 )
        {
LABEL_48:
          if ( !(_BYTE)v113 )
            goto LABEL_50;
          goto LABEL_49;
        }
LABEL_64:
        v68 |= 0x4000u;
        v54[2] = v68;
        if ( !(_BYTE)v113 )
        {
LABEL_50:
          v54[3] = 0;
          v70 = HIDWORD(v108);
          if ( (v108 & 0x100000000LL) != 0 )
          {
            v71 = 1;
            v54[3] = 1;
            v70 = HIDWORD(v108);
            if ( (v108 & 0x200000000LL) == 0 )
              goto LABEL_68;
          }
          else
          {
            v71 = 0;
            if ( (v108 & 0x200000000LL) == 0 )
            {
LABEL_68:
              if ( (v70 & 4) != 0 )
              {
                v71 |= 4u;
                v54[3] = v71;
                v70 = HIDWORD(v108);
                if ( (v108 & 0x800000000LL) == 0 )
                {
LABEL_70:
                  if ( (v70 & 0x10) == 0 )
                    goto LABEL_71;
                  goto LABEL_95;
                }
              }
              else if ( (v70 & 8) == 0 )
              {
                goto LABEL_70;
              }
              v71 |= 8u;
              v54[3] = v71;
              v70 = HIDWORD(v108);
              if ( (v108 & 0x1000000000LL) == 0 )
              {
LABEL_71:
                if ( (v70 & 0x20) == 0 )
                  goto LABEL_72;
                goto LABEL_96;
              }
LABEL_95:
              v71 |= 0x10u;
              v54[3] = v71;
              v70 = HIDWORD(v108);
              if ( (v108 & 0x2000000000LL) == 0 )
              {
LABEL_72:
                if ( (v70 & 0x40) == 0 )
                  goto LABEL_73;
                goto LABEL_97;
              }
LABEL_96:
              v71 |= 0x20u;
              v54[3] = v71;
              v70 = HIDWORD(v108);
              if ( (v108 & 0x4000000000LL) == 0 )
              {
LABEL_73:
                if ( (v70 & 0x80) == 0 )
                  goto LABEL_74;
                goto LABEL_98;
              }
LABEL_97:
              v71 |= 0x40u;
              v54[3] = v71;
              v70 = HIDWORD(v108);
              if ( (v108 & 0x8000000000LL) == 0 )
              {
LABEL_74:
                if ( (v70 & 0x100) == 0 )
                  goto LABEL_75;
                goto LABEL_99;
              }
LABEL_98:
              v71 |= 0x80u;
              v54[3] = v71;
              v70 = HIDWORD(v108);
              if ( (v108 & 0x10000000000LL) == 0 )
              {
LABEL_75:
                if ( (v70 & 0x200) == 0 )
                  goto LABEL_76;
                goto LABEL_100;
              }
LABEL_99:
              v71 |= 0x100u;
              v54[3] = v71;
              v70 = HIDWORD(v108);
              if ( (v108 & 0x20000000000LL) == 0 )
              {
LABEL_76:
                if ( (v70 & 0x400) == 0 )
                  goto LABEL_77;
                goto LABEL_101;
              }
LABEL_100:
              v71 |= 0x200u;
              v54[3] = v71;
              v70 = HIDWORD(v108);
              if ( (v108 & 0x40000000000LL) == 0 )
              {
LABEL_77:
                if ( (v70 & 0x800) == 0 )
                  goto LABEL_78;
                goto LABEL_102;
              }
LABEL_101:
              v71 |= 0x400u;
              v54[3] = v71;
              v70 = HIDWORD(v108);
              if ( (v108 & 0x80000000000LL) == 0 )
              {
LABEL_78:
                if ( (v70 & 0x1000) == 0 )
                  goto LABEL_79;
                goto LABEL_103;
              }
LABEL_102:
              v71 |= 0x800u;
              v54[3] = v71;
              v70 = HIDWORD(v108);
              if ( (v108 & 0x100000000000LL) == 0 )
              {
LABEL_79:
                if ( (v70 & 0x2000) == 0 )
                  goto LABEL_80;
                goto LABEL_104;
              }
LABEL_103:
              v71 |= 0x1000u;
              v54[3] = v71;
              v70 = HIDWORD(v108);
              if ( (v108 & 0x200000000000LL) == 0 )
              {
LABEL_80:
                if ( (v70 & 0x4000) == 0 )
                  goto LABEL_81;
                goto LABEL_105;
              }
LABEL_104:
              v71 |= 0x2000u;
              v54[3] = v71;
              v70 = HIDWORD(v108);
              if ( (v108 & 0x400000000000LL) == 0 )
              {
LABEL_81:
                if ( (v70 & 0x8000) == 0 )
                  goto LABEL_82;
                goto LABEL_106;
              }
LABEL_105:
              v71 |= 0x4000u;
              v54[3] = v71;
              v70 = HIDWORD(v108);
              if ( (v108 & 0x800000000000LL) == 0 )
              {
LABEL_82:
                if ( (v70 & 0x10000) == 0 )
                  goto LABEL_83;
                goto LABEL_107;
              }
LABEL_106:
              v71 |= 0x8000u;
              v54[3] = v71;
              v70 = HIDWORD(v108);
              if ( (v108 & 0x1000000000000LL) == 0 )
              {
LABEL_83:
                if ( (v70 & 0x20000) == 0 )
                  goto LABEL_84;
                goto LABEL_108;
              }
LABEL_107:
              v71 |= 0x10000u;
              v54[3] = v71;
              v70 = HIDWORD(v108);
              if ( (v108 & 0x2000000000000LL) == 0 )
              {
LABEL_84:
                if ( (v70 & 0x40000) == 0 )
                  goto LABEL_85;
                goto LABEL_109;
              }
LABEL_108:
              v71 |= 0x20000u;
              v54[3] = v71;
              v70 = HIDWORD(v108);
              if ( (v108 & 0x4000000000000LL) == 0 )
              {
LABEL_85:
                if ( (v70 & 0x80000) == 0 )
                  goto LABEL_86;
                goto LABEL_110;
              }
LABEL_109:
              v71 |= 0x40000u;
              v54[3] = v71;
              v70 = HIDWORD(v108);
              if ( (v108 & 0x8000000000000LL) == 0 )
              {
LABEL_86:
                if ( (v70 & 0x100000) == 0 )
                  goto LABEL_87;
                goto LABEL_111;
              }
LABEL_110:
              v71 |= 0x80000u;
              v54[3] = v71;
              v70 = HIDWORD(v108);
              if ( (v108 & 0x10000000000000LL) == 0 )
              {
LABEL_87:
                if ( (v70 & 0x200000) == 0 )
                  goto LABEL_88;
                goto LABEL_112;
              }
LABEL_111:
              v71 |= 0x100000u;
              v54[3] = v71;
              v70 = HIDWORD(v108);
              if ( (v108 & 0x20000000000000LL) == 0 )
              {
LABEL_88:
                if ( (v70 & 0x400000) == 0 )
                  goto LABEL_90;
                goto LABEL_89;
              }
LABEL_112:
              v71 |= 0x200000u;
              v54[3] = v71;
              if ( (v108 & 0x40000000000000LL) == 0 )
              {
LABEL_90:
                v54[4] = 0;
                v72 = v109;
                if ( (v109 & 1) != 0 )
                {
                  v73 = 1;
                  v54[4] = 1;
                  v72 = v109;
                  if ( (v109 & 2) == 0 )
                    goto LABEL_116;
                }
                else
                {
                  v73 = 0;
                  if ( (v109 & 2) == 0 )
                  {
LABEL_116:
                    if ( (v72 & 4) != 0 )
                    {
                      v73 |= 4u;
                      v54[4] = v73;
                      v72 = v109;
                      if ( (v109 & 8) == 0 )
                      {
LABEL_118:
                        if ( (v72 & 0x10) == 0 )
                          goto LABEL_119;
                        goto LABEL_152;
                      }
                    }
                    else if ( (v72 & 8) == 0 )
                    {
                      goto LABEL_118;
                    }
                    v73 |= 8u;
                    v54[4] = v73;
                    v72 = v109;
                    if ( (v109 & 0x10) == 0 )
                    {
LABEL_119:
                      if ( (v72 & 0x20) == 0 )
                        goto LABEL_120;
                      goto LABEL_153;
                    }
LABEL_152:
                    v73 |= 0x10u;
                    v54[4] = v73;
                    v72 = v109;
                    if ( (v109 & 0x20) == 0 )
                    {
LABEL_120:
                      if ( (v72 & 0x40) == 0 )
                        goto LABEL_121;
                      goto LABEL_154;
                    }
LABEL_153:
                    v73 |= 0x20u;
                    v54[4] = v73;
                    v72 = v109;
                    if ( (v109 & 0x40) == 0 )
                    {
LABEL_121:
                      if ( (v72 & 0x80) == 0 )
                        goto LABEL_122;
                      goto LABEL_155;
                    }
LABEL_154:
                    v73 |= 0x40u;
                    v54[4] = v73;
                    v72 = v109;
                    if ( (v109 & 0x80) == 0 )
                    {
LABEL_122:
                      if ( (v72 & 0x100) == 0 )
                        goto LABEL_123;
                      goto LABEL_156;
                    }
LABEL_155:
                    v73 |= 0x80u;
                    v54[4] = v73;
                    v72 = v109;
                    if ( (v109 & 0x100) == 0 )
                    {
LABEL_123:
                      if ( (v72 & 0x200) == 0 )
                        goto LABEL_124;
                      goto LABEL_157;
                    }
LABEL_156:
                    v73 |= 0x100u;
                    v54[4] = v73;
                    v72 = v109;
                    if ( (v109 & 0x200) == 0 )
                    {
LABEL_124:
                      if ( (v72 & 0x400) == 0 )
                        goto LABEL_125;
                      goto LABEL_158;
                    }
LABEL_157:
                    v73 |= 0x200u;
                    v54[4] = v73;
                    v72 = v109;
                    if ( (v109 & 0x400) == 0 )
                    {
LABEL_125:
                      if ( (v72 & 0x800) == 0 )
                        goto LABEL_126;
                      goto LABEL_159;
                    }
LABEL_158:
                    v73 |= 0x400u;
                    v54[4] = v73;
                    v72 = v109;
                    if ( (v109 & 0x800) == 0 )
                    {
LABEL_126:
                      if ( (v72 & 0x1000) == 0 )
                        goto LABEL_127;
                      goto LABEL_160;
                    }
LABEL_159:
                    v73 |= 0x800u;
                    v54[4] = v73;
                    v72 = v109;
                    if ( (v109 & 0x1000) == 0 )
                    {
LABEL_127:
                      if ( (v72 & 0x2000) == 0 )
                        goto LABEL_128;
                      goto LABEL_161;
                    }
LABEL_160:
                    v73 |= 0x1000u;
                    v54[4] = v73;
                    v72 = v109;
                    if ( (v109 & 0x2000) == 0 )
                    {
LABEL_128:
                      if ( (v72 & 0x4000) == 0 )
                        goto LABEL_129;
                      goto LABEL_162;
                    }
LABEL_161:
                    v73 |= 0x2000u;
                    v54[4] = v73;
                    v72 = v109;
                    if ( (v109 & 0x4000) == 0 )
                    {
LABEL_129:
                      if ( (v72 & 0x8000) == 0 )
                        goto LABEL_130;
                      goto LABEL_163;
                    }
LABEL_162:
                    v73 |= 0x4000u;
                    v54[4] = v73;
                    v72 = v109;
                    if ( (v109 & 0x8000) == 0 )
                    {
LABEL_130:
                      if ( (v72 & 0x10000) == 0 )
                        goto LABEL_131;
                      goto LABEL_164;
                    }
LABEL_163:
                    v73 |= 0x8000u;
                    v54[4] = v73;
                    v72 = v109;
                    if ( (v109 & 0x10000) == 0 )
                    {
LABEL_131:
                      if ( (v72 & 0x20000) == 0 )
                        goto LABEL_132;
                      goto LABEL_165;
                    }
LABEL_164:
                    v73 |= 0x10000u;
                    v54[4] = v73;
                    v72 = v109;
                    if ( (v109 & 0x20000) == 0 )
                    {
LABEL_132:
                      if ( (v72 & 0x40000) == 0 )
                        goto LABEL_133;
                      goto LABEL_166;
                    }
LABEL_165:
                    v73 |= 0x20000u;
                    v54[4] = v73;
                    v72 = v109;
                    if ( (v109 & 0x40000) == 0 )
                    {
LABEL_133:
                      if ( (v72 & 0x80000) == 0 )
                        goto LABEL_134;
                      goto LABEL_167;
                    }
LABEL_166:
                    v73 |= 0x40000u;
                    v54[4] = v73;
                    v72 = v109;
                    if ( (v109 & 0x80000) == 0 )
                    {
LABEL_134:
                      if ( (v72 & 0x100000) == 0 )
                        goto LABEL_135;
                      goto LABEL_168;
                    }
LABEL_167:
                    v73 |= 0x80000u;
                    v54[4] = v73;
                    v72 = v109;
                    if ( (v109 & 0x100000) == 0 )
                    {
LABEL_135:
                      if ( (v72 & 0x200000) == 0 )
                        goto LABEL_136;
                      goto LABEL_169;
                    }
LABEL_168:
                    v73 |= 0x100000u;
                    v54[4] = v73;
                    v72 = v109;
                    if ( (v109 & 0x200000) == 0 )
                    {
LABEL_136:
                      if ( (v72 & 0x400000) == 0 )
                        goto LABEL_137;
                      goto LABEL_170;
                    }
LABEL_169:
                    v73 |= 0x200000u;
                    v54[4] = v73;
                    v72 = v109;
                    if ( (v109 & 0x400000) == 0 )
                    {
LABEL_137:
                      if ( (v72 & 0x800000) == 0 )
                        goto LABEL_138;
                      goto LABEL_171;
                    }
LABEL_170:
                    v73 |= 0x400000u;
                    v54[4] = v73;
                    v72 = v109;
                    if ( (v109 & 0x800000) == 0 )
                    {
LABEL_138:
                      if ( (v72 & 0x1000000) == 0 )
                        goto LABEL_139;
                      goto LABEL_172;
                    }
LABEL_171:
                    v73 |= 0x800000u;
                    v54[4] = v73;
                    v72 = v109;
                    if ( (v109 & 0x1000000) == 0 )
                    {
LABEL_139:
                      if ( (v72 & 0x2000000) == 0 )
                        goto LABEL_140;
                      goto LABEL_173;
                    }
LABEL_172:
                    v73 |= 0x1000000u;
                    v54[4] = v73;
                    v72 = v109;
                    if ( (v109 & 0x2000000) == 0 )
                    {
LABEL_140:
                      if ( (v72 & 0x4000000) == 0 )
                        goto LABEL_141;
                      goto LABEL_174;
                    }
LABEL_173:
                    v73 |= 0x2000000u;
                    v54[4] = v73;
                    v72 = v109;
                    if ( (v109 & 0x4000000) == 0 )
                    {
LABEL_141:
                      if ( (v72 & 0x8000000) == 0 )
                        goto LABEL_142;
                      goto LABEL_175;
                    }
LABEL_174:
                    v73 |= 0x4000000u;
                    v54[4] = v73;
                    v72 = v109;
                    if ( (v109 & 0x8000000) == 0 )
                    {
LABEL_142:
                      if ( (v72 & 0x10000000) == 0 )
                        goto LABEL_143;
                      goto LABEL_176;
                    }
LABEL_175:
                    v73 |= 0x8000000u;
                    v54[4] = v73;
                    v72 = v109;
                    if ( (v109 & 0x10000000) == 0 )
                    {
LABEL_143:
                      if ( (v72 & 0x20000000) == 0 )
                        goto LABEL_144;
                      goto LABEL_177;
                    }
LABEL_176:
                    v73 |= 0x10000000u;
                    v54[4] = v73;
                    v72 = v109;
                    if ( (v109 & 0x20000000) == 0 )
                    {
LABEL_144:
                      if ( (v72 & 0x200000000000000LL) == 0 )
                        goto LABEL_145;
                      goto LABEL_178;
                    }
LABEL_177:
                    v73 |= 0x20000000u;
                    v54[4] = v73;
                    v72 = v109;
                    if ( (v109 & 0x200000000000000LL) == 0 )
                    {
LABEL_145:
                      if ( (v72 & 0x100000000000000LL) == 0 )
                        goto LABEL_147;
                      goto LABEL_146;
                    }
LABEL_178:
                    v73 |= 0x40000000u;
                    v54[4] = v73;
                    if ( (v109 & 0x100000000000000LL) == 0 )
                    {
LABEL_147:
                      v54[5] = 0;
                      v74 = v109;
                      if ( (v109 & 0x80000000000000LL) != 0 )
                      {
                        v75 = 1;
                        v54[5] = 1;
                        v74 = v109;
                        if ( (v109 & 0x40000000000000LL) == 0 )
                          goto LABEL_182;
                      }
                      else
                      {
                        v75 = 0;
                        if ( (v109 & 0x40000000000000LL) == 0 )
                        {
LABEL_182:
                          if ( (v74 & 0x20000000000000LL) != 0 )
                          {
                            v75 |= 4u;
                            v54[5] = v75;
                            v74 = v109;
                            if ( (v109 & 0x10000000000000LL) == 0 )
                            {
LABEL_184:
                              if ( (v74 & 0x8000000000000LL) == 0 )
                                goto LABEL_185;
                              goto LABEL_217;
                            }
                          }
                          else if ( (v74 & 0x10000000000000LL) == 0 )
                          {
                            goto LABEL_184;
                          }
                          v75 |= 8u;
                          v54[5] = v75;
                          v74 = v109;
                          if ( (v109 & 0x8000000000000LL) == 0 )
                          {
LABEL_185:
                            if ( (v74 & 0x4000000000000LL) == 0 )
                              goto LABEL_186;
                            goto LABEL_218;
                          }
LABEL_217:
                          v75 |= 0x10u;
                          v54[5] = v75;
                          v74 = v109;
                          if ( (v109 & 0x4000000000000LL) == 0 )
                          {
LABEL_186:
                            if ( (v74 & 0x2000000000000LL) == 0 )
                              goto LABEL_187;
                            goto LABEL_219;
                          }
LABEL_218:
                          v75 |= 0x20u;
                          v54[5] = v75;
                          v74 = v109;
                          if ( (v109 & 0x2000000000000LL) == 0 )
                          {
LABEL_187:
                            if ( (v74 & 0x1000000000000LL) == 0 )
                              goto LABEL_188;
                            goto LABEL_220;
                          }
LABEL_219:
                          v75 |= 0x40u;
                          v54[5] = v75;
                          v74 = v109;
                          if ( (v109 & 0x1000000000000LL) == 0 )
                          {
LABEL_188:
                            if ( (v74 & 0x800000000000LL) == 0 )
                              goto LABEL_189;
                            goto LABEL_221;
                          }
LABEL_220:
                          v75 |= 0x80u;
                          v54[5] = v75;
                          v74 = v109;
                          if ( (v109 & 0x800000000000LL) == 0 )
                          {
LABEL_189:
                            if ( (v74 & 0x400000000000LL) == 0 )
                              goto LABEL_190;
                            goto LABEL_222;
                          }
LABEL_221:
                          v75 |= 0x100u;
                          v54[5] = v75;
                          v74 = v109;
                          if ( (v109 & 0x400000000000LL) == 0 )
                          {
LABEL_190:
                            if ( (v74 & 0x400000000000000LL) == 0 )
                              goto LABEL_191;
                            goto LABEL_223;
                          }
LABEL_222:
                          v75 |= 0x200u;
                          v54[5] = v75;
                          v74 = v109;
                          if ( (v109 & 0x400000000000000LL) == 0 )
                          {
LABEL_191:
                            if ( (v74 & 0x10000000000LL) == 0 )
                              goto LABEL_192;
                            goto LABEL_224;
                          }
LABEL_223:
                          v75 |= 0x400u;
                          v54[5] = v75;
                          v74 = v109;
                          if ( (v109 & 0x10000000000LL) == 0 )
                          {
LABEL_192:
                            if ( (v74 & 0x20000000000LL) == 0 )
                              goto LABEL_193;
                            goto LABEL_225;
                          }
LABEL_224:
                          v75 |= 0x800u;
                          v54[5] = v75;
                          v74 = v109;
                          if ( (v109 & 0x20000000000LL) == 0 )
                          {
LABEL_193:
                            if ( (v74 & 0x40000000000LL) == 0 )
                              goto LABEL_194;
                            goto LABEL_226;
                          }
LABEL_225:
                          v75 |= 0x1000u;
                          v54[5] = v75;
                          v74 = v109;
                          if ( (v109 & 0x40000000000LL) == 0 )
                          {
LABEL_194:
                            if ( (v74 & 0x80000000000LL) == 0 )
                              goto LABEL_195;
                            goto LABEL_227;
                          }
LABEL_226:
                          v75 |= 0x2000u;
                          v54[5] = v75;
                          v74 = v109;
                          if ( (v109 & 0x80000000000LL) == 0 )
                          {
LABEL_195:
                            if ( (v74 & 0x100000000000LL) == 0 )
                              goto LABEL_196;
                            goto LABEL_228;
                          }
LABEL_227:
                          v75 |= 0x4000u;
                          v54[5] = v75;
                          v74 = v109;
                          if ( (v109 & 0x100000000000LL) == 0 )
                          {
LABEL_196:
                            if ( (v74 & 0x200000000000LL) == 0 )
                              goto LABEL_197;
                            goto LABEL_229;
                          }
LABEL_228:
                          v75 |= 0x8000u;
                          v54[5] = v75;
                          v74 = v109;
                          if ( (v109 & 0x200000000000LL) == 0 )
                          {
LABEL_197:
                            if ( (v74 & 0x400000000LL) == 0 )
                              goto LABEL_198;
                            goto LABEL_230;
                          }
LABEL_229:
                          v75 |= 0x10000u;
                          v54[5] = v75;
                          v74 = v109;
                          if ( (v109 & 0x400000000LL) == 0 )
                          {
LABEL_198:
                            if ( (v74 & 0x800000000LL) == 0 )
                              goto LABEL_199;
                            goto LABEL_231;
                          }
LABEL_230:
                          v75 |= 0x20000u;
                          v54[5] = v75;
                          v74 = v109;
                          if ( (v109 & 0x800000000LL) == 0 )
                          {
LABEL_199:
                            if ( (v74 & 0x1000000000LL) == 0 )
                              goto LABEL_200;
                            goto LABEL_232;
                          }
LABEL_231:
                          v75 |= 0x40000u;
                          v54[5] = v75;
                          v74 = v109;
                          if ( (v109 & 0x1000000000LL) == 0 )
                          {
LABEL_200:
                            if ( (v74 & 0x2000000000LL) == 0 )
                              goto LABEL_201;
                            goto LABEL_233;
                          }
LABEL_232:
                          v75 |= 0x80000u;
                          v54[5] = v75;
                          v74 = v109;
                          if ( (v109 & 0x2000000000LL) == 0 )
                          {
LABEL_201:
                            if ( (v74 & 0x4000000000LL) == 0 )
                              goto LABEL_202;
                            goto LABEL_234;
                          }
LABEL_233:
                          v75 |= 0x100000u;
                          v54[5] = v75;
                          v74 = v109;
                          if ( (v109 & 0x4000000000LL) == 0 )
                          {
LABEL_202:
                            if ( (v74 & 0x8000000000LL) == 0 )
                              goto LABEL_203;
                            goto LABEL_235;
                          }
LABEL_234:
                          v75 |= 0x200000u;
                          v54[5] = v75;
                          v74 = v109;
                          if ( (v109 & 0x8000000000LL) == 0 )
                          {
LABEL_203:
                            if ( (v74 & 0x200000000LL) == 0 )
                              goto LABEL_204;
                            goto LABEL_236;
                          }
LABEL_235:
                          v75 |= 0x400000u;
                          v54[5] = v75;
                          v74 = v109;
                          if ( (v109 & 0x200000000LL) == 0 )
                          {
LABEL_204:
                            if ( (v74 & 0x100000000LL) == 0 )
                              goto LABEL_205;
                            goto LABEL_237;
                          }
LABEL_236:
                          v75 |= 0x800000u;
                          v54[5] = v75;
                          v74 = v109;
                          if ( (v109 & 0x100000000LL) == 0 )
                          {
LABEL_205:
                            if ( (v74 & 0x80000000) == 0 )
                              goto LABEL_206;
                            goto LABEL_238;
                          }
LABEL_237:
                          v75 |= 0x1000000u;
                          v54[5] = v75;
                          v74 = v109;
                          if ( (v109 & 0x80000000) == 0 )
                          {
LABEL_206:
                            if ( (v74 & 0x40000000) == 0 )
                              goto LABEL_207;
                            goto LABEL_239;
                          }
LABEL_238:
                          v75 |= 0x2000000u;
                          v54[5] = v75;
                          v74 = v109;
                          if ( (v109 & 0x40000000) == 0 )
                          {
LABEL_207:
                            if ( (v74 & 0x800000000000000LL) == 0 )
                              goto LABEL_208;
                            goto LABEL_240;
                          }
LABEL_239:
                          v75 |= 0x4000000u;
                          v54[5] = v75;
                          v74 = v109;
                          if ( (v109 & 0x800000000000000LL) == 0 )
                          {
LABEL_208:
                            if ( (v74 & 0x1000000000000000LL) == 0 )
                              goto LABEL_209;
                            goto LABEL_241;
                          }
LABEL_240:
                          v75 |= 0x8000000u;
                          v54[5] = v75;
                          v74 = v109;
                          if ( (v109 & 0x1000000000000000LL) == 0 )
                          {
LABEL_209:
                            if ( (v74 & 0x2000000000000000LL) == 0 )
                              goto LABEL_210;
                            goto LABEL_242;
                          }
LABEL_241:
                          v75 |= 0x10000000u;
                          v54[5] = v75;
                          v74 = v109;
                          if ( (v109 & 0x2000000000000000LL) == 0 )
                          {
LABEL_210:
                            if ( (v74 & 0x4000000000000000LL) == 0 )
                              goto LABEL_211;
                            goto LABEL_243;
                          }
LABEL_242:
                          v75 |= 0x20000000u;
                          v54[5] = v75;
                          v74 = v109;
                          if ( (v109 & 0x4000000000000000LL) == 0 )
                          {
LABEL_211:
                            if ( (v74 & 0x8000000000000000LL) == 0 )
                              goto LABEL_212;
LABEL_244:
                            v54[5] = v75 | 0x80000000;
LABEL_212:
                            v54[6] = 0;
                            v76 = v110;
                            if ( (v110 & 1) != 0 )
                            {
                              v77 = 1;
                              v54[6] = 1;
                              v76 = v110;
                              if ( (v110 & 2) == 0 )
                                goto LABEL_247;
                            }
                            else
                            {
                              v77 = 0;
                              if ( (v110 & 2) == 0 )
                              {
LABEL_247:
                                if ( (v76 & 4) != 0 )
                                {
                                  v77 |= 4u;
                                  v54[6] = v77;
                                  v76 = v110;
                                  if ( (v110 & 8) == 0 )
                                  {
LABEL_249:
                                    if ( (v76 & 0x10) == 0 )
                                      goto LABEL_250;
                                    goto LABEL_305;
                                  }
                                }
                                else if ( (v76 & 8) == 0 )
                                {
                                  goto LABEL_249;
                                }
                                v77 |= 8u;
                                v54[6] = v77;
                                v76 = v110;
                                if ( (v110 & 0x10) == 0 )
                                {
LABEL_250:
                                  if ( (v76 & 0x20) == 0 )
                                    goto LABEL_251;
                                  goto LABEL_306;
                                }
LABEL_305:
                                v77 |= 0x10u;
                                v54[6] = v77;
                                v76 = v110;
                                if ( (v110 & 0x20) == 0 )
                                {
LABEL_251:
                                  if ( (v76 & 0x40) == 0 )
                                    goto LABEL_252;
                                  goto LABEL_307;
                                }
LABEL_306:
                                v77 |= 0x20u;
                                v54[6] = v77;
                                v76 = v110;
                                if ( (v110 & 0x40) == 0 )
                                {
LABEL_252:
                                  if ( (v76 & 0x80) == 0 )
                                    goto LABEL_253;
                                  goto LABEL_308;
                                }
LABEL_307:
                                v77 |= 0x40u;
                                v54[6] = v77;
                                v76 = v110;
                                if ( (v110 & 0x80) == 0 )
                                {
LABEL_253:
                                  if ( (v76 & 0x100) == 0 )
                                    goto LABEL_254;
                                  goto LABEL_309;
                                }
LABEL_308:
                                v77 |= 0x80u;
                                v54[6] = v77;
                                v76 = v110;
                                if ( (v110 & 0x100) == 0 )
                                {
LABEL_254:
                                  if ( (v76 & 0x200) == 0 )
                                    goto LABEL_255;
                                  goto LABEL_310;
                                }
LABEL_309:
                                v77 |= 0x100u;
                                v54[6] = v77;
                                v76 = v110;
                                if ( (v110 & 0x200) == 0 )
                                {
LABEL_255:
                                  if ( (v76 & 0x400) == 0 )
                                    goto LABEL_256;
                                  goto LABEL_311;
                                }
LABEL_310:
                                v77 |= 0x200u;
                                v54[6] = v77;
                                v76 = v110;
                                if ( (v110 & 0x400) == 0 )
                                {
LABEL_256:
                                  if ( (v76 & 0x800) == 0 )
                                    goto LABEL_257;
                                  goto LABEL_312;
                                }
LABEL_311:
                                v77 |= 0x400u;
                                v54[6] = v77;
                                v76 = v110;
                                if ( (v110 & 0x800) == 0 )
                                {
LABEL_257:
                                  if ( (v76 & 0x1000) == 0 )
                                    goto LABEL_258;
                                  goto LABEL_313;
                                }
LABEL_312:
                                v77 |= 0x800u;
                                v54[6] = v77;
                                v76 = v110;
                                if ( (v110 & 0x1000) == 0 )
                                {
LABEL_258:
                                  if ( (v76 & 0x2000) == 0 )
                                    goto LABEL_259;
                                  goto LABEL_314;
                                }
LABEL_313:
                                v77 |= 0x1000u;
                                v54[6] = v77;
                                v76 = v110;
                                if ( (v110 & 0x2000) == 0 )
                                {
LABEL_259:
                                  if ( (v76 & 0x4000) == 0 )
                                    goto LABEL_260;
                                  goto LABEL_315;
                                }
LABEL_314:
                                v77 |= 0x2000u;
                                v54[6] = v77;
                                v76 = v110;
                                if ( (v110 & 0x4000) == 0 )
                                {
LABEL_260:
                                  if ( (v76 & 0x8000) == 0 )
                                    goto LABEL_261;
                                  goto LABEL_316;
                                }
LABEL_315:
                                v77 |= 0x4000u;
                                v54[6] = v77;
                                v76 = v110;
                                if ( (v110 & 0x8000) == 0 )
                                {
LABEL_261:
                                  if ( (v76 & 0x10000) == 0 )
                                    goto LABEL_262;
                                  goto LABEL_317;
                                }
LABEL_316:
                                v77 |= 0x8000u;
                                v54[6] = v77;
                                v76 = v110;
                                if ( (v110 & 0x10000) == 0 )
                                {
LABEL_262:
                                  if ( (v76 & 0x20000) == 0 )
                                    goto LABEL_263;
                                  goto LABEL_318;
                                }
LABEL_317:
                                v77 |= 0x10000u;
                                v54[6] = v77;
                                v76 = v110;
                                if ( (v110 & 0x20000) == 0 )
                                {
LABEL_263:
                                  if ( (v76 & 0x40000) == 0 )
                                    goto LABEL_264;
                                  goto LABEL_319;
                                }
LABEL_318:
                                v77 |= 0x20000u;
                                v54[6] = v77;
                                v76 = v110;
                                if ( (v110 & 0x40000) == 0 )
                                {
LABEL_264:
                                  if ( (v76 & 0x80000) == 0 )
                                    goto LABEL_265;
                                  goto LABEL_320;
                                }
LABEL_319:
                                v77 |= 0x40000u;
                                v54[6] = v77;
                                v76 = v110;
                                if ( (v110 & 0x80000) == 0 )
                                {
LABEL_265:
                                  if ( (v76 & 0x100000) == 0 )
                                    goto LABEL_266;
                                  goto LABEL_321;
                                }
LABEL_320:
                                v77 |= 0x80000u;
                                v54[6] = v77;
                                v76 = v110;
                                if ( (v110 & 0x100000) == 0 )
                                {
LABEL_266:
                                  if ( (v76 & 0x200000) == 0 )
                                    goto LABEL_268;
                                  goto LABEL_267;
                                }
LABEL_321:
                                v77 |= 0x100000u;
                                v54[6] = v77;
                                if ( (v110 & 0x200000) == 0 )
                                {
LABEL_268:
                                  v54[7] = 0;
                                  v78 = BYTE2(v112);
                                  if ( BYTE2(v112) )
                                    v54[7] = BYTE2(v112);
                                  v79 = (unsigned __int16)v111;
                                  if ( (_WORD)v111 )
                                  {
                                    if ( (unsigned __int16)v111 >= 0x100u )
                                    {
                                      printk(
                                        &unk_94DB9D,
                                        "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/monitor/2.0/dp_mon_filter_2.0.c",
                                        1904,
                                        "!((htt_tlv_filter->wmask.tx_peer_entry) & ~((HTT_TX_MONITOR_CFG_TX_PEER_ENTRY_WO"
                                        "RD_MASK_M) >> (HTT_TX_MONITOR_CFG_TX_PEER_ENTRY_WORD_MASK_S)))");
                                      v79 = (unsigned __int16)v111;
                                      v78 = v54[7];
                                    }
                                    v78 |= v79 << 8;
                                    v54[7] = v78;
                                  }
                                  v80 = WORD1(v111);
                                  if ( WORD1(v111) )
                                  {
                                    if ( WORD1(v111) >= 0x100u )
                                    {
                                      printk(
                                        &unk_94DB9D,
                                        "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/monitor/2.0/dp_mon_filter_2.0.c",
                                        1908,
                                        "!((htt_tlv_filter->wmask.tx_queue_ext) & ~((HTT_TX_MONITOR_CFG_TX_QUEUE_EXT_WORD"
                                        "_MASK_M) >> (HTT_TX_MONITOR_CFG_TX_QUEUE_EXT_WORD_MASK_S)))");
                                      v80 = WORD1(v111);
                                      v78 = v54[7];
                                    }
                                    v78 |= v80 << 16;
                                    v54[7] = v78;
                                  }
                                  if ( BYTE3(v112) )
                                    v54[7] = v78 | (BYTE3(v112) << 24);
                                  v54[8] = 0;
                                  v54[8] = HIDWORD(v110);
                                  v54[9] = 0;
                                  v81 = BYTE4(v112);
                                  if ( BYTE4(v112) )
                                    v54[9] = BYTE4(v112);
                                  if ( BYTE5(v112) )
                                  {
                                    v81 |= BYTE5(v112) << 8;
                                    v54[9] = v81;
                                  }
                                  v82 = ((unsigned int)v114 >> 5) & 0x10000 | v81;
                                  v54[9] = v82;
                                  v83 = ((unsigned int)v114 >> 5) & 0x20000 | v82;
                                  v54[9] = v83;
                                  v84 = ((unsigned int)v114 >> 5) & 0x40000 | v83;
                                  v54[9] = v84;
                                  v85 = ((unsigned int)v114 >> 2) & 0x80000 | v84;
                                  v54[9] = v85;
                                  v86 = ((unsigned int)v114 >> 2) & 0x100000 | v85;
                                  v54[9] = v86;
                                  v54[9] = ((unsigned int)v114 >> 2) & 0x200000 | v86;
                                  v54[10] = 0;
                                  v87 = WORD1(v111);
                                  if ( WORD1(v111) )
                                  {
                                    if ( WORD1(v111) >= 0x1000u )
                                    {
                                      printk(
                                        &unk_94DB9D,
                                        "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/monitor/2.0/dp_mon_filter_2.0.c",
                                        1958,
                                        "!((htt_tlv_filter->wmask.tx_queue_ext) & ~((HTT_TX_MONITOR_CFG_TX_QUEUE_EXT_V2_W"
                                        "ORD_MASK_M) >> (HTT_TX_MONITOR_CFG_TX_QUEUE_EXT_V2_WORD_MASK_S)))");
                                      v87 = WORD1(v111);
                                      v88 = v54[10];
                                    }
                                    else
                                    {
                                      v88 = 0;
                                    }
                                    v87 |= v88;
                                    v54[10] = v87;
                                  }
                                  v89 = (unsigned __int16)v111;
                                  if ( (_WORD)v111 )
                                  {
                                    if ( (unsigned __int16)v111 >= 0x1000u )
                                    {
                                      printk(
                                        &unk_94DB9D,
                                        "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/monitor/2.0/dp_mon_filter_2.0.c",
                                        1962,
                                        "!((htt_tlv_filter->wmask.tx_peer_entry) & ~((HTT_TX_MONITOR_CFG_TX_PEER_ENTRY_V2"
                                        "_WORD_MASK_M) >> (HTT_TX_MONITOR_CFG_TX_PEER_ENTRY_V2_WORD_MASK_S)))");
                                      v89 = (unsigned __int16)v111;
                                      v87 = v54[10];
                                    }
                                    v54[10] = v87 | (v89 << 12);
                                  }
                                  v54[11] = 0;
                                  v90 = WORD2(v111);
                                  if ( WORD2(v111) )
                                    v54[11] = WORD2(v111);
                                  if ( HIWORD(v111) )
                                    v54[11] = v90 | (HIWORD(v111) << 16);
                                  v54[12] = 0;
                                  v91 = (unsigned __int16)v112;
                                  if ( (_WORD)v112 )
                                  {
                                    if ( (unsigned __int16)v112 >= 0x800u )
                                    {
                                      printk(
                                        &unk_94DB9D,
                                        "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/monitor/2.0/dp_mon_filter_2.0.c",
                                        1982,
                                        "!((htt_tlv_filter->wmask.tx_fes_status_prot) & ~((HTT_TX_MONITOR_CFG_FES_STATUS_"
                                        "PROT_WORD_MASK_M) >> (HTT_TX_MONITOR_CFG_FES_STATUS_PROT_WORD_MASK_S)))");
                                      v91 = (unsigned __int16)v112;
                                      v92 = v54[12];
                                    }
                                    else
                                    {
                                      v92 = 0;
                                    }
                                    v54[12] = v92 | v91;
                                  }
                                  v93 = htt_htc_pkt_alloc(v37);
                                  if ( v93 )
                                  {
                                    *(_QWORD *)v93 = 0;
                                    *(_QWORD *)(v93 + 32) = dp_htt_h2t_send_complete_free_netbuf_0;
                                    v94 = v93;
                                    *(_QWORD *)(v93 + 48) = *(_QWORD *)(v40 + 224);
                                    if ( (*(_BYTE *)(v40 + 68) & 4) != 0 )
                                      v95 = *(unsigned __int16 *)(v40 + 66);
                                    else
                                      v95 = 0;
                                    *(_DWORD *)(v93 + 60) = *(_DWORD *)(v40 + 112) + v95;
                                    v96 = *(_DWORD *)(v37 + 64);
                                    *(_WORD *)(v93 + 72) = 13;
                                    *(_DWORD *)(v93 + 88) = 0;
                                    *(_BYTE *)(v93 + 80) = 0;
                                    *(_DWORD *)(v93 + 64) = v96;
                                    *(_QWORD *)(v93 + 112) = v40;
                                    if ( (unsigned int)htc_send_pkt(*(_QWORD *)(v37 + 48), v93 + 16) )
                                    {
                                      ++*(_DWORD *)(v37 + 104);
                                      _qdf_nbuf_free(v40);
                                      htt_htc_pkt_free(v37, v94);
                                    }
                                    else if ( (*(_DWORD *)(v94 + 68) | 8) == 9 )
                                    {
                                      ++*(_DWORD *)(v37 + 104);
                                    }
                                    goto LABEL_333;
                                  }
LABEL_332:
                                  _qdf_nbuf_free(v40);
LABEL_333:
                                  result = 0;
                                  goto LABEL_334;
                                }
LABEL_267:
                                v54[6] = v77 | 0x200000;
                                goto LABEL_268;
                              }
                            }
                            v77 |= 2u;
                            v54[6] = v77;
                            v76 = v110;
                            goto LABEL_247;
                          }
LABEL_243:
                          v75 |= 0x40000000u;
                          v54[5] = v75;
                          if ( (v109 & 0x8000000000000000LL) == 0 )
                            goto LABEL_212;
                          goto LABEL_244;
                        }
                      }
                      v75 |= 2u;
                      v54[5] = v75;
                      v74 = v109;
                      goto LABEL_182;
                    }
LABEL_146:
                    v54[4] = v73 | 0x80000000;
                    goto LABEL_147;
                  }
                }
                v73 |= 2u;
                v54[4] = v73;
                v72 = v109;
                goto LABEL_116;
              }
LABEL_89:
              v54[3] = v71 | 0x400000;
              goto LABEL_90;
            }
          }
          v71 |= 2u;
          v54[3] = v71;
          v70 = HIDWORD(v108);
          goto LABEL_68;
        }
LABEL_49:
        v54[2] = v68 | 0x8000;
        goto LABEL_50;
      }
LABEL_331:
      qdf_trace_msg(
        0x3Fu,
        2u,
        "%s: Failed to expand head for TX Ring Cfg msg",
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        "htt_h2t_tx_ring_cfg");
      goto LABEL_332;
    }
    v42 = "%s: soc Context is null";
  }
  else
  {
    v42 = "%s: pdev Context is null";
  }
  qdf_trace_msg(
    0x73u,
    2u,
    v42,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "dp_tx_mon_filter_update_2_0",
    v97,
    v98,
    v99,
    v100,
    v101,
    v102,
    v103,
    v104,
    v105,
    v106,
    v107,
    v108);
  result = 16;
LABEL_334:
  _ReadStatusReg(SP_EL0);
  return result;
}
