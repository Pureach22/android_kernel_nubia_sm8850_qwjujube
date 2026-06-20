__int64 __fastcall show_mem_stats(__int64 a1, __int64 a2, __int64 a3)
{
  signed __int64 v4; // x23
  unsigned __int64 v5; // x26
  __int64 v6; // x22
  __int64 i; // x0
  int v8; // w10
  char v9; // w8
  const char *v10; // x3
  unsigned int v11; // w28
  unsigned int v12; // w22
  int v13; // w0
  unsigned int v14; // w23
  __int64 v15; // x28
  int v16; // w22
  int v17; // w0
  unsigned int v18; // w23
  __int64 v19; // x28
  int v20; // w0
  unsigned int v21; // w23
  __int64 v22; // x28
  int v23; // w0
  unsigned int v24; // w23
  __int64 v25; // x28
  int v26; // w0
  unsigned int v27; // w23
  __int64 v28; // x28
  int v29; // w0
  unsigned int v30; // w23
  __int64 v31; // x28
  int v32; // w0
  int v33; // w0
  __int64 v34; // x22
  unsigned int v35; // w24
  __int64 v36; // x23
  const char *v37; // x3
  __int64 v38; // x20
  __int64 v39; // x20
  __int64 v40; // x0
  __int64 v41; // x27
  __int64 v42; // x0
  unsigned int v43; // w25
  unsigned int v44; // w8
  __int64 v45; // x20
  __int64 v46; // x8
  int v47; // w0
  __int64 v48; // x20
  __int64 v49; // x0
  __int64 v50; // x27
  unsigned int v51; // w25
  unsigned int v52; // w24
  __int64 v53; // x9
  int v54; // w0
  __int64 v55; // x21
  __int64 v56; // x22
  unsigned int v57; // w21
  unsigned int v58; // w8
  unsigned int v59; // w27
  unsigned int v60; // w9
  __int64 v61; // x8
  __int64 v62; // x9
  int v63; // w0
  __int64 v64; // x22
  unsigned int v65; // w21
  unsigned int v66; // w24
  __int64 v67; // x8
  __int64 v68; // x9
  __int64 v69; // x20
  int v70; // w0
  unsigned __int64 v71; // x9
  __int64 v72; // x21
  unsigned __int64 v73; // x8
  unsigned __int64 v74; // x10
  unsigned __int64 v75; // x8
  unsigned __int64 v76; // x12
  unsigned __int64 v77; // x10
  unsigned __int64 v78; // x10
  unsigned __int64 v79; // x9
  __int64 v80; // x13
  __int64 v81; // x11
  __int64 v82; // x10
  unsigned __int64 v83; // x14
  __int64 *v84; // x12
  unsigned __int64 v85; // x13
  unsigned int v86; // w14
  __int64 v87; // x16
  __int64 v88; // x17
  __int64 v89; // x15
  __int64 v90; // x1
  unsigned __int64 v91; // x10
  unsigned __int64 v92; // x9
  unsigned int v93; // w11
  __int64 v94; // x12
  unsigned __int64 v95; // x9
  unsigned __int64 v96; // x9
  __int64 v97; // x8
  unsigned __int64 v98; // x9
  __int64 v99; // x8
  __int64 v100; // x11
  __int64 v101; // x10
  __int64 *v102; // x11
  unsigned __int64 v103; // x12
  __int64 v104; // x13
  __int64 v105; // x14
  unsigned __int64 v106; // x10
  unsigned __int64 v107; // x9
  __int64 v108; // x11
  __int64 v109; // x24
  __int64 v110; // x20
  __int64 v111; // x20
  __int64 v112; // x19
  unsigned __int64 StatusReg; // x20
  __int64 v114; // x21
  int v116; // [xsp+8h] [xbp-38h]
  unsigned __int64 v117; // [xsp+10h] [xbp-30h]
  int v118; // [xsp+1Ch] [xbp-24h]
  char v119; // [xsp+20h] [xbp-20h]
  __int64 v120; // [xsp+20h] [xbp-20h]
  __int64 v121; // [xsp+20h] [xbp-20h]
  unsigned int v122; // [xsp+2Ch] [xbp-14h]
  __int64 v123; // [xsp+30h] [xbp-10h]
  unsigned __int64 v124; // [xsp+38h] [xbp-8h]

  v4 = start_section_nr / (unsigned __int64)(unsigned int)sections_per_block;
  v5 = (unsigned int)(end_section_nr / (unsigned __int64)(unsigned int)sections_per_block) - (unsigned int)v4;
  v117 = end_section_nr / (unsigned __int64)(unsigned int)sections_per_block;
  LODWORD(v6) = v5 + 1;
  v124 = 8LL * (unsigned int)(2 * (v5 + 1));
  for ( i = _kmalloc_noprof(v124, 3520); i; *(_QWORD *)(StatusReg + 80) = v114 )
  {
    v122 = v6;
    v8 = 0;
    LODWORD(v6) = 0;
    v9 = 1;
    v123 = i;
    v116 = v4;
    do
    {
      v118 = v8;
      v119 = v9;
      if ( (v9 & 1) != 0 )
        v10 = "ONLINE";
      else
        v10 = "OFFLINE";
      v11 = scnprintf(a3 + (unsigned int)v6, 4096LL - (unsigned int)v6, "\n\t%s\n\t\t\t", v10) + v6;
      if ( (unsigned int)v117 >= (unsigned int)v4 )
      {
        v12 = v4;
        do
        {
          v13 = scnprintf(a3 + v11, 4096LL - v11, "%s%d\t\t", "mem", v12++);
          v11 += v13;
        }
        while ( v12 <= (unsigned int)v117 );
      }
      v15 = (unsigned int)scnprintf(a3 + v11, 4096LL - v11, "\n") + v11;
      v14 = 0;
      LODWORD(v15) = v15 + scnprintf(a3 + v15, 4096 - v15, "\tLast recd time:\t");
      v16 = v118 * v122;
      do
      {
        v17 = scnprintf(
                a3 + (unsigned int)v15,
                4096LL - (unsigned int)v15,
                "%luus\t\t",
                *(_QWORD *)(mem_info + 72LL * (v16 + v14++) + 48));
        v15 = (unsigned int)(v17 + v15);
      }
      while ( v14 <= (unsigned int)v5 );
      v19 = (unsigned int)scnprintf(a3 + v15, 4096 - v15, "\n") + (unsigned int)v15;
      v18 = 0;
      LODWORD(v19) = v19 + scnprintf(a3 + v19, 4096 - v19, "\tAvg time:\t");
      do
      {
        v20 = scnprintf(
                a3 + (unsigned int)v19,
                4096LL - (unsigned int)v19,
                "%luus\t\t",
                *(_QWORD *)(mem_info + 72LL * (v16 + v18++) + 16));
        v19 = (unsigned int)(v20 + v19);
      }
      while ( v18 <= (unsigned int)v5 );
      v22 = (unsigned int)scnprintf(a3 + v19, 4096 - v19, "\n") + (unsigned int)v19;
      v21 = 0;
      LODWORD(v22) = v22 + scnprintf(a3 + v22, 4096 - v22, "\tBest time:\t");
      do
      {
        v23 = scnprintf(
                a3 + (unsigned int)v22,
                4096LL - (unsigned int)v22,
                "%luus\t\t",
                *(_QWORD *)(mem_info + 72LL * (v16 + v21++) + 24));
        v22 = (unsigned int)(v23 + v22);
      }
      while ( v21 <= (unsigned int)v5 );
      v25 = (unsigned int)scnprintf(a3 + v22, 4096 - v22, "\n") + (unsigned int)v22;
      v24 = 0;
      LODWORD(v25) = v25 + scnprintf(a3 + v25, 4096 - v25, "\tWorst time:\t");
      do
      {
        v26 = scnprintf(
                a3 + (unsigned int)v25,
                4096LL - (unsigned int)v25,
                "%luus\t\t",
                *(_QWORD *)(mem_info + 72LL * (v16 + v24++) + 32));
        v25 = (unsigned int)(v26 + v25);
      }
      while ( v24 <= (unsigned int)v5 );
      v28 = (unsigned int)scnprintf(a3 + v25, 4096 - v25, "\n") + (unsigned int)v25;
      v27 = 0;
      LODWORD(v28) = v28 + scnprintf(a3 + v28, 4096 - v28, "\tSuccess count:\t");
      do
      {
        v29 = scnprintf(
                a3 + (unsigned int)v28,
                4096LL - (unsigned int)v28,
                "%lu\t\t",
                *(_QWORD *)(mem_info + 72LL * (v16 + v27++)));
        v28 = (unsigned int)(v29 + v28);
      }
      while ( v27 <= (unsigned int)v5 );
      v31 = (unsigned int)scnprintf(a3 + v28, 4096 - v28, "\n") + (unsigned int)v28;
      v30 = 0;
      LODWORD(v31) = v31 + scnprintf(a3 + v31, 4096 - v31, "\tFail count:\t");
      do
      {
        v32 = scnprintf(
                a3 + (unsigned int)v31,
                4096LL - (unsigned int)v31,
                "%lu\t\t",
                *(_QWORD *)(mem_info + 72LL * (v16 + v30++) + 8));
        v31 = (unsigned int)(v32 + v31);
      }
      while ( v30 <= (unsigned int)v5 );
      v33 = scnprintf(a3 + v31, 4096 - v31, "\n");
      LODWORD(v4) = v116;
      v9 = 0;
      v8 = 1;
      v6 = (unsigned int)(v33 + v31);
    }
    while ( (v119 & 1) != 0 );
    v34 = (unsigned int)scnprintf(a3 + v6, 4096 - v6, "\n") + (unsigned int)v6;
    v35 = 0;
    LODWORD(v36) = v34 + scnprintf(a3 + v34, 4096 - v34, "\tState:\t\t");
    do
    {
      if ( *(_DWORD *)(mem_sec_state + 4LL * v35) )
        v37 = "Offline";
      else
        v37 = "Online";
      ++v35;
      v36 = (unsigned int)scnprintf(a3 + (unsigned int)v36, 4096LL - (unsigned int)v36, "%s\t\t", v37)
          + (unsigned int)v36;
    }
    while ( v35 <= (unsigned int)v5 );
    v38 = (unsigned int)scnprintf(a3 + v36, 4096 - v36, "\n") + (unsigned int)v36;
    v39 = (unsigned int)v38 + (unsigned int)scnprintf(a3 + v38, 4096 - v38, "\n");
    v40 = scnprintf(a3 + v39, 4096 - v39, "\tOnline time:\t");
    v41 = (unsigned int)(v39 + v40);
    v42 = ktime_get(v40);
    v43 = 0;
    v44 = 0;
    v4 = (signed __int64)"%llus\t\t";
    v120 = v42;
    while ( 1 )
    {
      v45 = v44;
      v46 = *(_DWORD *)(mem_sec_state + 4LL * v44) ? 0LL : v120 - *(_QWORD *)(mem_info + 72LL * v44 + 64);
      v6 = *(_QWORD *)(mem_info + 72LL * (unsigned int)v45 + 56) + v46;
      v47 = scnprintf(a3 + v41 + v43, 4096 - (v41 + v43), "%llus\t\t", v6 / 1000000000);
      if ( v124 <= 8 * v45 )
        break;
      v44 = v45 + 1;
      v43 += v47;
      *(_QWORD *)(v123 + 8 * v45) = v6;
      if ( (int)v45 + 1 > (unsigned int)v5 )
      {
        v48 = (unsigned int)scnprintf(a3 + v43 + (unsigned int)v41, 4096LL - (v43 + (unsigned int)v41), "\n")
            + v43
            + (_DWORD)v41;
        v49 = scnprintf(a3 + v48, 4096 - v48, "\tOffline time:\t");
        v50 = (unsigned int)(v48 + v49);
        v51 = 0;
        v52 = 0;
        v121 = ktime_get(v49);
        while ( 1 )
        {
          v6 = (unsigned int)v5 + v52 + 1;
          v53 = *(_DWORD *)(mem_sec_state + 4LL * v52) == 1
              ? v121 - *(_QWORD *)(mem_info + 72LL * (unsigned int)v6 + 64)
              : 0LL;
          v4 = *(_QWORD *)(mem_info + 72LL * (unsigned int)v6 + 56) + v53;
          v54 = scnprintf(a3 + v50 + v51, 4096 - (v50 + v51), "%llus\t\t", v4 / 1000000000);
          if ( v124 <= 8 * v6 )
            goto LABEL_89;
          ++v52;
          v51 += v54;
          *(_QWORD *)(v123 + 8 * v6) = v4;
          if ( v52 > (unsigned int)v5 )
          {
            v55 = (unsigned int)scnprintf(a3 + v51 + (unsigned int)v50, 4096LL - (v51 + (unsigned int)v50), "\n")
                + v51
                + (_DWORD)v50;
            v56 = (unsigned int)v55 + (unsigned int)scnprintf(a3 + v55, 4096 - v55, "\n");
            v4 = (unsigned int)v56 + (unsigned int)scnprintf(a3 + v56, 4096 - v56, "\tOnline %%:\t");
            v57 = 0;
            v58 = 0;
            v6 = (__int64)"%d%%\t\t";
            while ( v124 > 8 * (unsigned __int64)v58 )
            {
              v59 = v58;
              v60 = v5 + v58 + 1;
              if ( v124 <= 8 * (unsigned __int64)v60 )
                break;
              v61 = *(_QWORD *)(v123 + 8LL * v58);
              v62 = *(_QWORD *)(v123 + 8LL * v60) + v61;
              if ( v62 < 0 )
                __break(0x800u);
              v63 = scnprintf(a3 + v4 + v57, 4096 - (v4 + v57), "%d%%\t\t", 100 * v61 / v62);
              v58 = v59 + 1;
              v57 += v63;
              if ( v59 + 1 > (unsigned int)v5 )
              {
                v64 = (unsigned int)scnprintf(a3 + v57 + (unsigned int)v4, 4096LL - (v57 + (unsigned int)v4), "\n")
                    + v57
                    + (_DWORD)v4;
                v4 = (unsigned int)v64 + (unsigned int)scnprintf(a3 + v64, 4096 - v64, "\tOffline %%:\t");
                v65 = 0;
                v66 = 0;
                v6 = (__int64)"%d%%\t\t";
                while ( v124 > 8 * (unsigned __int64)(v122 + v66) && v124 > 8 * (unsigned __int64)v66 )
                {
                  v67 = *(_QWORD *)(v123 + 8LL * (v122 + v66));
                  v68 = *(_QWORD *)(v123 + 8LL * v66) + v67;
                  if ( v68 < 0 )
                    __break(0x800u);
                  ++v66;
                  v65 += scnprintf(a3 + v4 + v65, 4096 - (v4 + v65), "%d%%\t\t", 100 * v67 / v68);
                  if ( v66 > (unsigned int)v5 )
                  {
                    v6 = (__int64)"\n";
                    v69 = (unsigned int)scnprintf(a3 + v65 + (unsigned int)v4, 4096LL - (v65 + (unsigned int)v4), "\n")
                        + v65
                        + (_DWORD)v4;
                    v70 = scnprintf(a3 + v69, 4096 - v69, "\n");
                    v71 = 0;
                    v72 = 0;
                    v73 = v124 - 8LL * v122;
                    if ( v124 < 8 * (unsigned __int64)v122 )
                      v73 = 0;
                    v74 = v73 >> 3;
                    v75 = v124 >> 3;
                    if ( v74 >= v5 )
                      v74 = v5;
                    if ( v74 >= v75 )
                      v76 = v124 >> 3;
                    else
                      v76 = v74;
                    if ( v76 >= 2 )
                    {
                      v77 = v124 - 8LL * v122;
                      v71 = 0;
                      v72 = 0;
                      if ( v124 < 8 * (unsigned __int64)v122 )
                        v77 = 0;
                      v78 = v77 >> 3;
                      if ( v78 >= v5 )
                        v78 = v5;
                      if ( v78 >= v75 )
                        v78 = v124 >> 3;
                      if ( -2 - (int)v5 >= (unsigned int)v78 )
                      {
                        v79 = v76 + 1;
                        v80 = 2;
                        v81 = 0;
                        v82 = 0;
                        if ( ((v76 + 1) & 1) != 0 )
                          v80 = (v76 + 1) & 1;
                        v83 = ~v76;
                        v84 = (__int64 *)(v123 + 8);
                        v71 = v79 - v80;
                        v85 = v83 + v80;
                        v86 = v5 + 2;
                        do
                        {
                          v87 = *(v84 - 1);
                          v88 = *v84;
                          v89 = *(_QWORD *)(v123 + 8LL * (v86 - 1));
                          v90 = *(_QWORD *)(v123 + 8LL * v86);
                          v85 += 2LL;
                          v84 += 2;
                          v86 += 2;
                          v81 += v87 + v89;
                          v82 += v88 + v90;
                        }
                        while ( v85 );
                        v72 = v82 + v81;
                      }
                    }
                    v91 = 8 * v71;
                    v92 = v71 - 1;
                    while ( v124 > v91 )
                    {
                      v93 = v5 + v92 + 2;
                      if ( v124 <= 8 * (unsigned __int64)v93 )
                        break;
                      v94 = *(_QWORD *)(v123 + v91);
                      ++v92;
                      v91 += 8LL;
                      v72 += v94 + *(_QWORD *)(v123 + 8LL * v93);
                      if ( v92 >= v5 )
                      {
                        if ( v5 >= v75 )
                          v95 = v124 >> 3;
                        else
                          v95 = v5;
                        if ( v95 >= 2 )
                        {
                          v98 = v95 + 1;
                          v99 = 0;
                          v100 = v98 & 1;
                          v101 = 0;
                          if ( (v98 & 1) == 0 )
                            v100 = 2;
                          v96 = v98 - v100;
                          v102 = (__int64 *)(v123 + 8);
                          v103 = v96;
                          do
                          {
                            v104 = *(v102 - 1);
                            v105 = *v102;
                            v103 -= 2LL;
                            v102 += 2;
                            v99 += v104;
                            v101 += v105;
                          }
                          while ( v103 );
                          v97 = v101 + v99;
                        }
                        else
                        {
                          v96 = 0;
                          v97 = 0;
                        }
                        v106 = 8 * v96;
                        v107 = v96 - 1;
                        while ( v124 > v106 )
                        {
                          v108 = *(_QWORD *)(v123 + v106);
                          ++v107;
                          v106 += 8LL;
                          v97 += v108;
                          if ( v107 >= v5 )
                          {
                            v109 = v72 - v97;
                            v110 = (unsigned int)scnprintf(
                                                   a3 + (unsigned int)(v69 + v70),
                                                   4096LL - (unsigned int)(v69 + v70),
                                                   "\tAvg Online %%:\t%lld%%\n",
                                                   100 * v97 / v72)
                                 + (_DWORD)v69
                                 + v70;
                            v111 = (unsigned int)scnprintf(
                                                   a3 + v110,
                                                   4096 - v110,
                                                   "\tAvg Offline %%:\t%lld%%\n",
                                                   100 * v109 / v72)
                                 + (unsigned int)v110;
                            v112 = (unsigned int)v111 + (unsigned int)scnprintf(a3 + v111, 4096 - v111, "\n");
                            kfree(v123);
                            return v112;
                          }
                        }
                        goto LABEL_89;
                      }
                    }
                    goto LABEL_89;
                  }
                }
                goto LABEL_89;
              }
            }
            goto LABEL_89;
          }
        }
      }
    }
LABEL_89:
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v114 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &show_mem_stats__alloc_tag;
    v124 = 8LL * (unsigned int)(2 * v6);
    i = _kmalloc_noprof(v124, 3520);
  }
  return -12;
}
