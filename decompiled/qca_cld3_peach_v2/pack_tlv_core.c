__int64 __fastcall pack_tlv_core(__int64 a1, __int64 a2, char *a3, unsigned int a4, _DWORD *a5, __int64 a6, _DWORD *a7)
{
  __int64 result; // x0
  unsigned __int16 *v9; // x25
  unsigned int v10; // w28
  int v11; // w8
  unsigned __int8 *v12; // x20
  int v13; // w8
  int v14; // w8
  unsigned int v15; // w9
  bool v16; // zf
  char *v17; // x10
  unsigned __int8 v18; // w8
  char v19; // w10
  bool v20; // zf
  char *v21; // x11
  __int16 v22; // w8
  unsigned int v23; // w19
  int v24; // w21
  char v25; // w8
  int v26; // w22
  void *v27; // x21
  char *v28; // x26
  unsigned int v29; // w19
  unsigned int v30; // w8
  int v31; // w8
  unsigned int v32; // w19
  int v33; // w21
  __int16 v34; // w8
  int v35; // w19
  unsigned __int8 *v36; // x1
  char *v37; // x20
  unsigned int v38; // w21
  int v39; // w0
  int v40; // w22
  char v41; // w8
  char v42; // w8
  __int16 v43; // w8
  __int16 v44; // w8
  char *v45; // x22
  _BYTE *v46; // x26
  unsigned int v47; // w9
  char v48; // w9
  __int16 v49; // w8
  void *v50; // x21
  char *v51; // x26
  int v52; // w9
  __int64 v53; // x1
  unsigned int v54; // w8
  __int16 v55; // w10
  bool v56; // zf
  void *v57; // x8
  void *v58; // x22
  int v59; // w26
  __int16 v60; // w9
  void *v61; // x21
  char *v62; // x28
  unsigned int v63; // w19
  int v64; // w21
  _BYTE *v65; // x22
  char *v66; // x26
  unsigned int v67; // w19
  int v68; // w9
  int v69; // w8
  char *v70; // x20
  char *v71; // x22
  unsigned int v72; // w8
  bool v73; // zf
  const void *v74; // x1
  char *v75; // x20
  int v76; // w19
  char *v77; // x20
  unsigned int v78; // w21
  void *v79; // x0
  char *v80; // x22
  unsigned int v81; // w8
  __int16 v82; // w9
  __int16 v83; // w9
  unsigned int v84; // [xsp+Ch] [xbp-34h]
  __int64 v85; // [xsp+10h] [xbp-30h]
  __int64 v86; // [xsp+18h] [xbp-28h]
  _DWORD *v87; // [xsp+20h] [xbp-20h]
  _DWORD *v88; // [xsp+28h] [xbp-18h]
  int v89; // [xsp+30h] [xbp-10h] BYREF
  int v90; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v91; // [xsp+38h] [xbp-8h]

  v91 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    result = 268435460;
    if ( a3 && a4 && a5 )
    {
      if ( *(_DWORD *)(a6 + 20) != 0xFFFF )
      {
        result = 0;
        v9 = (unsigned __int16 *)(a6 + 16);
        v10 = 268435457;
        v88 = a7;
        v86 = a2;
        v87 = a5;
        v85 = a1;
        while ( 1 )
        {
          v12 = (unsigned __int8 *)(a2 + *((unsigned int *)v9 - 4));
          if ( v12[*((unsigned int *)v9 - 3)] )
          {
            if ( *((_DWORD *)v9 + 3) > a4 )
            {
              result = 268435461;
              goto LABEL_8;
            }
            v13 = *v9;
            v89 = 0;
            switch ( v13 )
            {
              case 1:
                if ( a4 < 8 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v24 = result;
                v45 = a3;
                v46 = a3 + 1;
                v23 = a4;
                *a3 = 1;
                v89 = 2;
                qdf_mem_copy(a3 + 2, v12 + 1, 6u);
                v47 = v89 + 6;
                goto LABEL_181;
              case 2:
              case 38:
                if ( a4 < 3 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v15 = 3;
                v17 = a3 + 1;
                v16 = a3 + 1 == nullptr;
                *a3 = 3;
                v18 = v12[1];
                goto LABEL_98;
              case 3:
                if ( a4 < 3 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                *a3 = 0;
                goto LABEL_97;
              case 4:
                if ( a4 < 5 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v22 = 22288;
                goto LABEL_199;
              case 5:
                if ( a4 < 6 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v43 = 528;
                goto LABEL_189;
              case 6:
                if ( a4 < 6 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v43 = 2064;
                goto LABEL_189;
              case 7:
                if ( a4 < 6 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v43 = 2320;
                goto LABEL_189;
              case 8:
                v14 = 268435461;
                if ( (unsigned int)v12[1] + 4 > a4 )
                  goto LABEL_202;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v32 = a4;
                v33 = result;
                v34 = 4368;
                goto LABEL_145;
              case 9:
                if ( a4 < 6 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v43 = 4624;
                goto LABEL_189;
              case 10:
                if ( a4 < 7 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v84 = v10;
                *a3 = 8;
                v58 = a3 + 5;
                v59 = result;
                v60 = *((_WORD *)v12 + 1);
                v61 = a3 + 1;
                v62 = a3;
                v63 = a4;
                v89 = 3;
                LOWORD(v90) = v60;
                qdf_mem_copy(a3 + 3, &v90, 2u);
                LOWORD(v90) = *((_WORD *)v12 + 2);
                v89 += 2;
                qdf_mem_copy(v58, &v90, 2u);
                v47 = v89 + 2;
                v89 += 2;
                if ( v61 )
                {
                  LOWORD(v90) = v47 - 3;
                  qdf_mem_copy(v61, &v90, 2u);
                  a2 = v86;
                  a5 = v87;
                  a3 = v62;
                  a7 = v88;
                  v10 = v84;
                  v14 = 0;
                  LODWORD(result) = v59;
                  a4 = v63;
                  goto LABEL_202;
                }
                a2 = v86;
                a5 = v87;
                a3 = v62;
                a7 = v88;
                v10 = v84;
                v14 = 0;
                LODWORD(result) = v59;
                a4 = v63;
                goto LABEL_203;
              case 11:
                if ( a4 < 8 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v32 = a4;
                v40 = result;
                v41 = 6;
                goto LABEL_110;
              case 12:
                v14 = 268435461;
                if ( (unsigned int)v12[1] + 4 > a4 )
                  goto LABEL_202;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v32 = a4;
                v33 = result;
                v34 = 8464;
                goto LABEL_145;
              case 13:
                if ( a4 < 4 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v55 = 1;
                v57 = a3 + 1;
                v56 = a3 + 1 == nullptr;
                v15 = 4;
                *a3 = 1;
                a3[3] = v12[1];
                goto LABEL_130;
              case 14:
                v14 = 268435461;
                if ( (unsigned int)v12[1] + 4 > a4 )
                  goto LABEL_202;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v32 = a4;
                v33 = result;
                v34 = 8976;
                goto LABEL_145;
              case 15:
                v14 = 268435461;
                if ( (unsigned int)v12[1] + 4 > a4 )
                  goto LABEL_202;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v32 = a4;
                v33 = result;
                v34 = 9232;
                goto LABEL_145;
              case 16:
                v14 = 268435461;
                if ( (unsigned int)v12[3] + 5 > a4 )
                  goto LABEL_202;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v26 = result;
                *a3 = 12;
                v27 = a3 + 1;
                v28 = a3;
                v29 = a4;
                a3[3] = v12[1];
                a3[4] = v12[2];
                v30 = v12[3];
                v89 = 5;
                qdf_mem_copy(a3 + 5, v12 + 4, v30);
                v31 = v12[3];
                goto LABEL_120;
              case 17:
                if ( a4 < 8 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v32 = a4;
                v40 = result;
                v41 = 17;
LABEL_110:
                *a3 = v41;
                v50 = a3 + 1;
                v51 = a3;
                v89 = 3;
                qdf_mem_copy(a3 + 3, v12 + 1, 3u);
                v52 = v89;
                v51[6] = v12[4];
                v47 = v52 + 5;
                v51[7] = v12[5];
                v89 = v47;
                if ( v50 )
                {
                  LOWORD(v90) = v47 - 3;
                  qdf_mem_copy(v50, &v90, 2u);
                  a3 = v51;
                  v14 = 0;
                  LODWORD(result) = v40;
                  goto LABEL_174;
                }
                a3 = v51;
                v14 = 0;
                LODWORD(result) = v40;
                goto LABEL_176;
              case 18:
                if ( a4 < 5 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v55 = 2;
                v15 = 5;
                *a3 = 2;
                a3[3] = v12[1];
                v57 = a3 + 1;
                v56 = a3 + 1 == nullptr;
                a3[4] = v12[2];
LABEL_130:
                v89 = v15;
                if ( v56 )
                  goto LABEL_216;
                LOWORD(v90) = v55;
                goto LABEL_158;
              case 19:
                if ( a4 < 9 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v29 = a4;
                v26 = result;
                v28 = a3;
                v27 = a3 + 1;
                *a3 = 3;
                v79 = a3 + 3;
                v89 = 3;
                goto LABEL_165;
              case 20:
                v35 = result;
                v53 = (__int64)v12;
                v37 = a3;
                v38 = a4;
                v39 = dot11f_pack_tlv_p2_p_device_info(v85, v53, (__int64)a3, a4, &v89);
                goto LABEL_113;
              case 21:
                v14 = 268435461;
                if ( (unsigned int)v12[1] + 3 > a4 )
                  goto LABEL_202;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v26 = result;
                *a3 = 14;
                v54 = v12[1];
                v28 = a3;
                v27 = a3 + 1;
                v29 = a4;
                v89 = 3;
                qdf_mem_copy(a3 + 3, v12 + 2, v54);
                v31 = v12[1];
LABEL_120:
                v47 = v89 + v31;
                goto LABEL_166;
              case 22:
                if ( a4 < 4 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                *a3 = 0;
                goto LABEL_156;
              case 23:
                if ( a4 < 0xC )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v32 = a4;
                v33 = result;
                v44 = 21520;
                goto LABEL_171;
              case 24:
                if ( a4 < 5 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v22 = 15376;
                goto LABEL_199;
              case 25:
                if ( a4 < 0xC )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v32 = a4;
                v33 = result;
                v44 = 27152;
LABEL_171:
                *(_WORD *)a3 = v44;
                v80 = a3;
                *((_WORD *)a3 + 2) = bswap32(*((unsigned __int16 *)v12 + 1)) >> 16;
                v89 = 6;
                qdf_mem_copy(a3 + 6, v12 + 4, 4u);
                a3 = v80;
                v73 = v80 + 2 == nullptr;
                v47 = v89 + 6;
                *((_WORD *)v80 + 5) = bswap32(*((unsigned __int16 *)v12 + 4)) >> 16;
                goto LABEL_172;
              case 26:
                if ( a4 < 5 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v22 = 14864;
                goto LABEL_199;
              case 27:
                if ( a4 < 5 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v22 = 15120;
                goto LABEL_199;
              case 28:
                if ( a4 < 5 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v22 = 16656;
                goto LABEL_199;
              case 29:
                if ( a4 < 6 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v43 = 21264;
LABEL_189:
                *(_WORD *)a3 = v43;
                v15 = 6;
                *((_WORD *)a3 + 2) = bswap32(*((unsigned __int16 *)v12 + 1)) >> 16;
                v89 = 6;
                if ( a3 == (char *)-2LL )
                  goto LABEL_216;
                v82 = 512;
                goto LABEL_201;
              case 30:
                v14 = 268435461;
                if ( (unsigned int)v12[1] + 4 > a4 )
                  goto LABEL_202;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v32 = a4;
                v33 = result;
                v34 = 16912;
LABEL_145:
                *(_WORD *)a3 = v34;
                v71 = a3;
                v72 = v12[1];
                v89 = 4;
                qdf_mem_copy(a3 + 4, v12 + 2, v72);
                a3 = v71;
                v73 = v71 + 2 == nullptr;
                v47 = v89 + v12[1];
                goto LABEL_172;
              case 31:
                if ( a4 < 0x14 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v32 = a4;
                v33 = result;
                v49 = 18192;
                goto LABEL_149;
              case 32:
                if ( a4 < 0x14 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v32 = a4;
                v33 = result;
                v49 = 18448;
LABEL_149:
                v74 = v12 + 1;
                v75 = a3;
                *(_WORD *)a3 = v49;
                v89 = 4;
                qdf_mem_copy(a3 + 4, v74, 0x10u);
                a3 = v75;
                v73 = v75 + 2 == nullptr;
                v47 = v89 + 16;
LABEL_172:
                v14 = 0;
                v89 = v47;
                if ( !v73 )
                {
                  LODWORD(result) = v33;
                  *((_WORD *)a3 + 1) = bswap32(v47 - 4) >> 16;
LABEL_174:
                  a2 = v86;
                  a5 = v87;
                  a4 = v32;
                  a7 = v88;
                  goto LABEL_202;
                }
                LODWORD(result) = v33;
LABEL_176:
                a2 = v86;
                a5 = v87;
                a4 = v32;
                a7 = v88;
                goto LABEL_203;
              case 33:
                v35 = result;
                v36 = v12;
                v37 = a3;
                v38 = a4;
                v39 = dot11f_pack_tlv_vendor_extension(v85, v36);
LABEL_113:
                a2 = v86;
                a5 = v87;
                a3 = v37;
                a7 = v88;
                a4 = v38;
                v14 = v39;
                LODWORD(result) = v35;
                goto LABEL_202;
              case 34:
                if ( a4 < 5 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v22 = 18960;
                goto LABEL_199;
              case 35:
                if ( a4 < 5 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v22 = 17424;
LABEL_199:
                *(_WORD *)a3 = v22;
                v15 = 5;
                a3[4] = v12[1];
                v89 = 5;
                if ( a3 == (char *)-2LL )
                  goto LABEL_216;
                v82 = 256;
LABEL_201:
                v14 = 0;
                *((_WORD *)a3 + 1) = v82;
                goto LABEL_202;
              case 36:
              case 42:
                if ( a4 < 3 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                *a3 = 4;
                goto LABEL_97;
              case 37:
                if ( a4 < 4 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v64 = result;
                *a3 = 8;
                v83 = *((_WORD *)v12 + 1);
                v70 = a3;
                v65 = a3 + 1;
                v67 = a4;
                v89 = 2;
                LOWORD(v90) = v83;
                qdf_mem_copy(a3 + 2, &v90, 2u);
                v47 = v89 + 2;
                goto LABEL_194;
              case 39:
              case 45:
                if ( a4 < 3 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                *a3 = 5;
                goto LABEL_97;
              case 40:
                if ( a4 < 0xB )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v64 = result;
                v65 = a3 + 1;
                *a3 = 14;
                v66 = a3;
                v67 = a4;
                a3[2] = v12[1];
                v68 = *((_DWORD *)v12 + 1);
                v89 = 3;
                v90 = v68;
                qdf_mem_copy(a3 + 3, &v90, 4u);
                v69 = *((_DWORD *)v12 + 2);
                v70 = v66;
                v90 = v69;
                qdf_mem_copy(v66 + 7, &v90, 4u);
                v47 = v89 + 8;
LABEL_194:
                v14 = 0;
                v89 = v47;
                if ( v65 )
                {
                  a2 = v86;
                  a5 = v87;
                  a7 = v88;
                  *v65 = v47 - 2;
                  LODWORD(result) = v64;
                  a4 = v67;
                  a3 = v70;
                  goto LABEL_202;
                }
                a2 = v86;
                a5 = v87;
                LODWORD(result) = v64;
                a7 = v88;
                a4 = v67;
                a3 = v70;
                goto LABEL_203;
              case 41:
                v14 = 268435461;
                if ( (unsigned int)v12[2] + 3 > a4 )
                  goto LABEL_202;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v23 = a4;
                v24 = result;
                v25 = 13;
                goto LABEL_180;
              case 43:
                if ( a4 < 5 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v19 = 3;
                v21 = a3 + 1;
                v20 = a3 + 1 == nullptr;
                v15 = 5;
                *a3 = 3;
                a3[2] = v12[1];
                a3[3] = v12[2];
                a3[4] = v12[3];
                goto LABEL_208;
              case 44:
                if ( a4 < 3 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                *a3 = 8;
                goto LABEL_97;
              case 46:
                if ( a4 < 4 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v42 = 9;
                goto LABEL_214;
              case 47:
                if ( a4 < 3 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v19 = 1;
                v21 = a3 + 1;
                v20 = a3 + 1 == nullptr;
                v15 = 3;
                *a3 = 1;
                a3[2] = v12[1];
LABEL_208:
                v89 = v15;
                if ( v20 )
                  goto LABEL_216;
                v14 = 0;
                *v21 = v19;
                goto LABEL_202;
              case 48:
                v14 = 268435461;
                if ( (unsigned int)v12[2] + 3 > a4 )
                  goto LABEL_202;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v23 = a4;
                v24 = result;
                v25 = 2;
LABEL_180:
                *a3 = v25;
                v46 = a3 + 1;
                v45 = a3;
                a3[2] = v12[1];
                v81 = v12[2];
                v89 = 3;
                qdf_mem_copy(a3 + 3, v12 + 3, v81);
                v47 = v89 + v12[2];
LABEL_181:
                v14 = 0;
                v89 = v47;
                if ( v46 )
                {
                  a2 = v86;
                  a5 = v87;
                  a7 = v88;
                  *v46 = v47 - 2;
                  LODWORD(result) = v24;
                  a4 = v23;
                  a3 = v45;
                  goto LABEL_202;
                }
                a2 = v86;
                a5 = v87;
                LODWORD(result) = v24;
                a7 = v88;
                a4 = v23;
                a3 = v45;
                goto LABEL_203;
              case 49:
                if ( a4 < 3 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                *a3 = 101;
                goto LABEL_97;
              case 50:
                if ( a4 < 4 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v42 = 1;
                goto LABEL_214;
              case 51:
                if ( a4 < 3 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                *a3 = 103;
                goto LABEL_97;
              case 52:
                if ( a4 < 4 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v42 = 102;
LABEL_214:
                *a3 = v42;
                v17 = a3 + 1;
                v15 = 4;
                a3[2] = v12[1];
                a3[3] = v12[2];
                v89 = 4;
                if ( a3 == (char *)-1LL )
                  goto LABEL_216;
                v14 = 0;
                v48 = 2;
                goto LABEL_100;
              case 53:
              case 55:
                if ( a4 < 3 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                *a3 = 6;
                goto LABEL_97;
              case 54:
              case 56:
                if ( a4 < 3 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                *a3 = 7;
                goto LABEL_97;
              case 57:
                if ( a4 < 3 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                *a3 = 2;
LABEL_97:
                v18 = v12[1];
                v17 = a3 + 1;
                v16 = a3 + 1 == nullptr;
                v15 = 3;
LABEL_98:
                a3[2] = v18;
                v89 = 3;
                if ( v16 )
                  goto LABEL_216;
                v14 = 0;
                v48 = 1;
LABEL_100:
                *v17 = v48;
                goto LABEL_202;
              case 58:
                if ( a4 < 9 )
                  goto LABEL_211;
                v14 = *v12;
                if ( !*v12 )
                  goto LABEL_202;
                v26 = result;
                v29 = a4;
                v28 = a3;
                *a3 = 16;
                v79 = a3 + 3;
                v27 = a3 + 1;
                v89 = 3;
LABEL_165:
                qdf_mem_copy(v79, v12 + 1, 6u);
                v47 = v89 + 6;
LABEL_166:
                v89 = v47;
                if ( v27 )
                {
                  LOWORD(v90) = v47 - 3;
                  qdf_mem_copy(v27, &v90, 2u);
                  a2 = v86;
                  a5 = v87;
                  v14 = 0;
                  a7 = v88;
                  LODWORD(result) = v26;
                  a4 = v29;
                  a3 = v28;
                  goto LABEL_202;
                }
                a2 = v86;
                a5 = v87;
                v14 = 0;
                a7 = v88;
                LODWORD(result) = v26;
                a4 = v29;
                a3 = v28;
                goto LABEL_203;
              case 59:
                if ( a4 < 4 )
                {
LABEL_211:
                  result = (unsigned int)result | 0x10000005;
                }
                else
                {
                  v14 = *v12;
                  if ( *v12 )
                  {
                    *a3 = 10;
LABEL_156:
                    v57 = a3 + 1;
                    v15 = 4;
                    a3[3] = v12[1];
                    v89 = 4;
                    if ( a3 == (char *)-1LL )
                    {
LABEL_216:
                      a3 += v15;
                      a4 -= v15;
                      *a5 += v15;
LABEL_204:
                      ++*a7;
                      break;
                    }
                    LOWORD(v90) = 1;
LABEL_158:
                    v76 = result;
                    v77 = a3;
                    v78 = a4;
                    qdf_mem_copy(v57, &v90, 2u);
                    a2 = v86;
                    a5 = v87;
                    a3 = v77;
                    a7 = v88;
                    a4 = v78;
                    LODWORD(result) = v76;
                    v14 = 0;
                  }
LABEL_202:
                  v47 = v89;
LABEL_203:
                  a3 += v47;
                  result = v14 | (unsigned int)result;
                  a4 -= v47;
                  *a5 += v47;
                  if ( v47 )
                    goto LABEL_204;
                }
                break;
              default:
                result = v10;
                goto LABEL_8;
            }
          }
          else
          {
            v89 = 0;
          }
          v11 = *((_DWORD *)v9 + 11);
          v9 += 20;
          if ( v11 == 0xFFFF )
            goto LABEL_8;
        }
      }
      result = 0;
    }
  }
  else
  {
    result = 268435459;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
