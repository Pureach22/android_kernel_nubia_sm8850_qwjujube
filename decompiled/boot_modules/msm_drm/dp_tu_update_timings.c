__int64 __fastcall dp_tu_update_timings(__int64 result, __int64 a2)
{
  __int64 v2; // x8
  int v3; // w20
  int v4; // w19
  __int64 v5; // x8
  __int64 v6; // x8
  unsigned __int64 v7; // x10
  unsigned __int64 v8; // x9
  unsigned __int64 v9; // x12
  int v10; // w10
  unsigned __int64 v11; // x12
  __int64 v12; // x14
  bool v13; // cf
  unsigned __int64 v14; // x12
  int v15; // w10
  int v16; // w13
  __int64 v17; // x8
  bool v18; // nf
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x9
  __int64 v21; // x8
  bool v22; // nf
  __int64 v23; // x8
  unsigned __int64 v24; // x11
  unsigned __int64 v25; // x8
  int v26; // w14
  __int64 v27; // x14
  __int64 v28; // x13
  char v29; // w16
  bool v30; // cc
  signed __int64 v31; // x12
  __int64 v32; // x12
  char v33; // w14
  __int64 v34; // x12
  char v35; // w15
  bool v36; // cc
  signed __int64 v37; // x9
  __int64 v38; // x9
  char v39; // w13
  char v40; // w14
  bool v41; // cc
  signed __int64 v42; // x11
  __int64 v43; // x11
  char v44; // w12
  int v45; // w10
  int v46; // w11
  int v47; // w10
  unsigned int v48; // w12
  signed __int64 v49; // x11
  unsigned __int64 v50; // x14
  int v51; // w12
  unsigned __int64 v52; // x14
  __int64 v53; // x16
  int v54; // w13
  bool v55; // nf
  __int64 v56; // x10
  __int64 v57; // x13
  __int64 v58; // x10
  unsigned __int64 v59; // x12
  __int64 v60; // x10
  char v61; // w15
  __int64 v62; // x12
  __int64 v63; // x11
  char v64; // w12
  __int64 v65; // x11
  __int64 v66; // x12
  unsigned int v67; // w12
  unsigned int v68; // w10
  __int64 v69; // x9
  __int64 v70; // x11
  __int64 v71; // x10
  char v72; // w13
  bool v73; // cc
  __int64 v74; // x9
  __int64 v75; // x9
  char v76; // w11
  int v77; // w21
  bool v78; // zf
  int v79; // w9
  int v80; // w8
  unsigned __int64 v81; // x9
  unsigned __int64 v82; // x10
  unsigned __int64 v83; // x12
  int v84; // w9
  unsigned __int64 v85; // x12
  __int64 v86; // x14
  __int64 v87; // x9
  __int64 v88; // x8
  __int64 v89; // x10
  __int64 v90; // x11
  unsigned int v91; // w12
  unsigned int v92; // w11
  __int64 v93; // x10
  __int64 v94; // x13
  __int64 v95; // x12
  char v96; // w15
  __int64 v97; // x10
  __int64 v98; // x11
  char v99; // w10
  unsigned __int64 v100; // x10
  unsigned __int64 v101; // x11
  __int64 v102; // x11
  char v103; // w14
  bool v104; // cc
  __int64 v105; // x9
  char v106; // w13
  __int64 v107; // x12
  __int64 v108; // x9
  __int64 v109; // x13
  unsigned int v110; // w13
  unsigned int v111; // w11
  __int64 v112; // x9
  __int64 v113; // x8
  __int64 v114; // x9
  unsigned int v115; // w10
  unsigned int v116; // w9
  __int64 v117; // x8
  __int64 v118; // x24
  __int64 v119; // x25
  __int64 ipc_log_context; // x0

  v2 = *(_QWORD *)result;
  v3 = *(_DWORD *)(result + 32);
  v4 = *(_DWORD *)(result + 60);
  if ( *(__int64 *)result < 0 )
    v2 = -v2;
  v5 = v2 << 32;
  if ( *(__int64 *)result < 0 )
    v5 = -v5;
  *(_QWORD *)a2 = v5;
  *(_QWORD *)(a2 + 8) = v5;
  v6 = *(_QWORD *)(result + 8);
  if ( v6 >= 0 )
    v7 = *(_QWORD *)(result + 8);
  else
    v7 = -v6;
  v8 = v7 / 0x3E8;
  v9 = v7 % 0x3E8;
  v10 = -32;
  do
  {
    v11 = 2 * v9;
    if ( v11 <= 0x3E7 )
      v12 = 0;
    else
      v12 = -1000;
    v13 = __CFADD__(v10++, 1);
    v8 = (v11 > 0x3E7) | (2 * v8);
    v9 = v12 + v11;
  }
  while ( !v13 );
  if ( 2 * v9 > 0x3E7 )
    ++v8;
  if ( v6 >= 0 )
    v14 = v8;
  else
    v14 = -(__int64)v8;
  *(_QWORD *)(a2 + 16) = v14;
  *(_QWORD *)(a2 + 24) = v14;
  *(_QWORD *)(a2 + 32) = *(_QWORD *)(result + 16);
  *(_QWORD *)(a2 + 56) = *(_QWORD *)(result + 24);
  *(_DWORD *)(a2 + 76) = *(_DWORD *)(result + 32);
  v15 = *(_DWORD *)(result + 36);
  *(_DWORD *)(a2 + 80) = v15;
  v16 = *(_DWORD *)(result + 40);
  *(_DWORD *)(a2 + 84) = v16;
  *(_DWORD *)(a2 + 88) = *(_DWORD *)(result + 44);
  *(_DWORD *)(a2 + 96) = *(_DWORD *)(result + 52);
  *(_DWORD *)(a2 + 92) = *(_DWORD *)(result + 48);
  v17 = *(_QWORD *)(result + 16);
  v18 = v17 < 0;
  if ( v17 < 0 )
    v17 = -v17;
  v19 = v17 << 32;
  if ( v18 )
    v20 = -(__int64)v19;
  else
    v20 = v19;
  *(_QWORD *)(a2 + 40) = v20;
  *(_DWORD *)(a2 + 48) = *(_QWORD *)(result + 16);
  v21 = *(_QWORD *)(result + 24);
  v22 = v21 < 0;
  if ( v21 < 0 )
    v21 = -v21;
  v23 = v21 << 32;
  if ( v22 )
    v24 = -v23;
  else
    v24 = v23;
  *(_QWORD *)(a2 + 64) = v24;
  *(_DWORD *)(a2 + 72) = *(_QWORD *)(result + 24);
  *(_DWORD *)(a2 + 104) = *(_QWORD *)(result + 24) < 0xA0u;
  v25 = *(_QWORD *)(result + 64);
  *(_QWORD *)(a2 + 480) = v25;
  v26 = *(_DWORD *)(result + 72);
  *(_DWORD *)(a2 + 488) = v26;
  if ( *(_QWORD *)(result + 64) )
  {
    if ( v26 == 4 )
      goto LABEL_31;
  }
  else
  {
    v25 = 8;
    *(_QWORD *)(a2 + 480) = 8;
    if ( *(_DWORD *)(result + 72) == 4 )
    {
LABEL_31:
      if ( v16 != 422 )
        goto LABEL_32;
LABEL_59:
      if ( v15 == 30 )
      {
        v45 = 20;
        v46 = 10;
      }
      else
      {
        v45 = 16;
        v46 = 8;
      }
      *(_DWORD *)(a2 + 80) = v45;
      *(_DWORD *)(a2 + 100) = v46;
      if ( !*(_DWORD *)(result + 44) )
        goto LABEL_168;
LABEL_63:
      *(_DWORD *)(a2 + 80) = 24;
      v47 = *(_DWORD *)(result + 56);
      if ( v47 >= 0 )
        v48 = *(_DWORD *)(result + 56);
      else
        v48 = -v47;
      v49 = v48 / 0x64uLL;
      v50 = v48 % 0x64;
      v51 = -32;
      do
      {
        v52 = 2 * v50;
        if ( v52 <= 0x63 )
          v53 = 0;
        else
          v53 = -100;
        v13 = __CFADD__(v51++, 1);
        v49 = (v52 > 0x63) | (unsigned __int64)(2 * v49);
        v50 = v53 + v52;
      }
      while ( !v13 );
      v54 = *(_DWORD *)(result + 36);
      if ( 2 * v50 > 0x63 )
        ++v49;
      if ( v47 < 0 )
        v49 = -v49;
      v55 = v54 < 0;
      if ( v54 >= 0 )
        v56 = (unsigned int)v54;
      else
        v56 = (unsigned int)-v54;
      v57 = 62;
      v58 = v56 << 32;
      if ( v55 )
        v59 = -v58;
      else
        v59 = v58;
      do
      {
        if ( ((v59 >> v57) & 1) != v59 >> 63 )
          break;
        --v57;
      }
      while ( v57 );
      v60 = 62;
      v61 = v57 - 30;
      v62 = v59 << (62 - (unsigned __int8)v57);
      if ( (unsigned int)(62 - v57) >= 0x20 )
        v61 = 0;
      v63 = v62 / (v49 >> v61);
      v64 = 30 - v57;
      if ( (unsigned int)(62 - v57) <= 0x20 )
        v64 = 0;
      v65 = v63 >> v64;
      do
      {
        if ( ((v20 >> v60) & 1) != v20 >> 63 )
          break;
        --v60;
      }
      while ( v60 );
      v66 = 62;
      do
      {
        if ( (((unsigned __int64)v65 >> v66) & 1) != (unsigned __int64)v65 >> 63 )
          break;
        --v66;
      }
      while ( v66 );
      v67 = v66 + v60;
      v68 = v67 - 61;
      if ( v67 <= 0x3D )
      {
        v69 = v65 * v20;
        LOBYTE(v68) = 0;
      }
      else
      {
        v69 = ((__int64)v20 >> ((v68 >> 1) + (v68 & 1))) * (v65 >> (v68 >> 1));
        if ( v68 >= 0x21 )
        {
          v69 <<= (unsigned __int8)v67 - 93;
LABEL_99:
          v70 = 62;
          do
          {
            if ( (((unsigned __int64)v69 >> v70) & 1) != (unsigned __int64)v69 >> 63 )
              break;
            --v70;
          }
          while ( v70 );
          v71 = 62;
          v72 = v70 - 30;
          v73 = (unsigned int)(62 - v70) > 0x20;
          v74 = v69 << (62 - (unsigned __int8)v70);
          if ( (unsigned int)(62 - v70) >= 0x20 )
            v72 = 0;
          v75 = v74 / (__int64)(0x800000000uLL >> v72);
          v76 = 30 - v70;
          if ( !v73 )
            v76 = 0;
          v77 = (int)((unsigned __int64)(v75 >> v76) >> 32) / v4;
          do
          {
            v78 = ((v25 >> v71) & 1) != v25 >> 63 || v71 == 1;
            --v71;
          }
          while ( !v78 );
          if ( !v77 )
          {
            v118 = a2;
            v119 = result;
            ipc_log_context = get_ipc_log_context(result);
            ipc_log_string(
              ipc_log_context,
              "[w][%-4d]incorrect no of bytes per slice=%d\n",
              *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
              0);
            printk(&unk_26F123, "dp_tu_update_timings");
            result = v119;
            a2 = v118;
          }
          if ( v77 % v3 )
            v79 = (v3 - v77 % v3) * v4;
          else
            v79 = 0;
          v80 = v79 + (v77 + v3) * v4;
          if ( v80 >= 0 )
            v81 = (unsigned int)v80;
          else
            v81 = (unsigned int)-v80;
          v82 = v81 / 3;
          v83 = v81 % 3;
          v84 = -32;
          do
          {
            v85 = 2 * v83;
            if ( v85 <= 2 )
              v86 = 0;
            else
              v86 = -3;
            v13 = __CFADD__(v84++, 1);
            v82 = (v85 > 2) | (2 * v82);
            v83 = v86 + v85;
          }
          while ( !v13 );
          v87 = *(_QWORD *)(a2 + 16);
          if ( 2 * v83 > 2 )
            ++v82;
          if ( v80 >= 0 )
            v88 = v82;
          else
            v88 = -(__int64)v82;
          v89 = 62;
          do
          {
            if ( (((unsigned __int64)v87 >> v89) & 1) != (unsigned __int64)v87 >> 63 )
              break;
            --v89;
          }
          while ( v89 );
          v90 = 62;
          do
          {
            if ( (((unsigned __int64)v88 >> v90) & 1) != (unsigned __int64)v88 >> 63 )
              break;
            --v90;
          }
          while ( v90 );
          v91 = v90 + v89;
          v92 = v90 + v89 - 61;
          if ( v91 <= 0x3D )
          {
            v93 = v87 * v88;
            LOBYTE(v92) = 0;
          }
          else
          {
            v93 = (v87 >> ((v92 >> 1) + (v92 & 1))) * (v88 >> (v92 >> 1));
            if ( v92 >= 0x21 )
            {
              v93 <<= (unsigned __int8)v91 - 93;
LABEL_142:
              v94 = 62;
              do
              {
                if ( (((unsigned __int64)v93 >> v94) & 1) != (unsigned __int64)v93 >> 63 )
                  break;
                --v94;
              }
              while ( v94 );
              v95 = 62;
              v96 = v94 - 30;
              v97 = v93 << (62 - (unsigned __int8)v94);
              if ( (unsigned int)(62 - v94) >= 0x20 )
                v96 = 0;
              v98 = v97 / (*(__int64 *)(a2 + 40) >> v96);
              v99 = 30 - v94;
              if ( (unsigned int)(62 - v94) <= 0x20 )
                v99 = 0;
              v100 = v98 >> v99;
              v101 = (unsigned __int64)v98 >> 63;
              do
              {
                if ( ((v100 >> v95) & 1) != v101 )
                  break;
                --v95;
              }
              while ( v95 );
              v102 = 62;
              v103 = v95 - 30;
              v104 = (unsigned int)(62 - v95) > 0x20;
              if ( (unsigned int)(62 - v95) >= 0x20 )
                v103 = 0;
              v105 = (__int64)(v100 << (62 - (unsigned __int8)v95)) / (v87 >> v103);
              v106 = 30 - v95;
              v107 = *(_QWORD *)(a2 + 64);
              if ( !v104 )
                v106 = 0;
              v108 = v105 >> v106;
              do
              {
                if ( (((unsigned __int64)v107 >> v102) & 1) != (unsigned __int64)v107 >> 63 )
                  break;
                --v102;
              }
              while ( v102 );
              v109 = 62;
              do
              {
                if ( (((unsigned __int64)v108 >> v109) & 1) != (unsigned __int64)v108 >> 63 )
                  break;
                --v109;
              }
              while ( v109 );
              v110 = v109 + v102;
              v111 = v110 - 61;
              if ( v110 <= 0x3D )
              {
                v112 = v108 * v107;
                LOBYTE(v111) = 0;
              }
              else
              {
                v112 = (v107 >> ((v111 >> 1) + (v111 & 1))) * (v108 >> (v111 >> 1));
                if ( v111 >= 0x21 )
                {
                  v112 <<= (unsigned __int8)v110 - 93;
LABEL_167:
                  *(_QWORD *)(a2 + 16) = v100;
                  *(_QWORD *)(a2 + 40) = v88;
                  *(_QWORD *)(a2 + 64) = v112;
                  goto LABEL_168;
                }
                if ( v110 == 93 )
                  goto LABEL_167;
              }
              v112 >>= 32 - (unsigned __int8)v111;
              goto LABEL_167;
            }
            if ( v92 == 32 )
              goto LABEL_142;
          }
          v93 >>= 32 - (unsigned __int8)v92;
          goto LABEL_142;
        }
        if ( v67 == 93 )
          goto LABEL_99;
      }
      v69 >>= 32 - (unsigned __int8)v68;
      goto LABEL_99;
    }
  }
  *(_DWORD *)(a2 + 488) = 2;
  if ( v16 == 422 )
    goto LABEL_59;
LABEL_32:
  if ( v16 == 420 )
  {
    v27 = 62;
    do
    {
      if ( ((v14 >> v27) & 1) != v14 >> 63 )
        break;
      --v27;
    }
    while ( v27 );
    v28 = 62;
    v29 = v27 - 30;
    v30 = (unsigned int)(62 - v27) > 0x20;
    v31 = v14 << (62 - (unsigned __int8)v27);
    if ( (unsigned int)(62 - v27) >= 0x20 )
      v29 = 0;
    v32 = v31 / (__int64)(0x200000000uLL >> v29);
    v33 = 30 - v27;
    if ( !v30 )
      v33 = 0;
    *(_QWORD *)(a2 + 16) = v32 >> v33;
    do
    {
      if ( ((v20 >> v28) & 1) != v20 >> 63 )
        break;
      --v28;
    }
    while ( v28 );
    v34 = 62;
    v35 = v28 - 30;
    v36 = (unsigned int)(62 - v28) > 0x20;
    v37 = v20 << (62 - (unsigned __int8)v28);
    if ( (unsigned int)(62 - v28) >= 0x20 )
      v35 = 0;
    v38 = v37 / (__int64)(0x200000000uLL >> v35);
    v39 = 30 - v28;
    if ( !v36 )
      v39 = 0;
    v20 = v38 >> v39;
    *(_QWORD *)(a2 + 40) = v20;
    do
    {
      if ( ((v24 >> v34) & 1) != v24 >> 63 )
        break;
      --v34;
    }
    while ( v34 );
    v40 = v34 - 30;
    v41 = (unsigned int)(62 - v34) > 0x20;
    v42 = v24 << (62 - (unsigned __int8)v34);
    if ( (unsigned int)(62 - v34) >= 0x20 )
      v40 = 0;
    v43 = v42 / (__int64)(0x200000000uLL >> v40);
    v44 = 30 - v34;
    if ( !v41 )
      v44 = 0;
    *(_QWORD *)(a2 + 64) = v43 >> v44;
  }
  *(_DWORD *)(a2 + 100) = v15 / 3;
  if ( *(_DWORD *)(result + 44) )
    goto LABEL_63;
LABEL_168:
  if ( !*(_DWORD *)(result + 52) )
    return result;
  v113 = *(_QWORD *)a2;
  v114 = 62;
  while ( (((unsigned __int64)v113 >> v114) & 1) == *(_QWORD *)a2 >> 63 )
  {
    if ( !--v114 )
    {
      v115 = 31;
      goto LABEL_174;
    }
  }
  v115 = v114 + 31;
LABEL_174:
  v116 = v115 - 61;
  if ( v115 <= 0x3D )
  {
    v117 = 4191888081LL * v113;
    LOBYTE(v116) = 0;
LABEL_178:
    v117 >>= 32 - (unsigned __int8)v116;
    goto LABEL_179;
  }
  v117 = (v113 >> ((v116 >> 1) + (v116 & 1))) * (0xF9DB22D1uLL >> (v116 >> 1));
  if ( v116 < 0x21 )
  {
    if ( v115 == 93 )
      goto LABEL_179;
    goto LABEL_178;
  }
  v117 <<= (unsigned __int8)v115 - 93;
LABEL_179:
  *(_QWORD *)a2 = v117;
  return result;
}
