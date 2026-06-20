__int64 qrtr_ns_worker()
{
  __int64 result; // x0
  _DWORD *v1; // x19
  int v2; // w0
  __int64 v3; // x3
  __int64 v4; // x4
  __int64 v5; // x5
  __int64 v6; // x6
  __int64 v7; // x7
  int v8; // w26
  int v9; // w2
  unsigned int v10; // w8
  unsigned int v11; // w21
  unsigned int v12; // w25
  __int64 *v13; // x20
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x27
  __int64 v17; // x0
  unsigned int *v18; // x21
  unsigned int v19; // w28
  unsigned int *v20; // x8
  unsigned int v21; // w27
  __int64 v22; // x21
  unsigned int v23; // w26
  unsigned int *v24; // x25
  __int64 v25; // x0
  unsigned __int64 v26; // x0
  __int64 v27; // x5
  __int64 v28; // x6
  __int64 v29; // x7
  unsigned int v30; // w0
  __int64 v31; // x3
  __int64 v32; // x4
  __int64 v33; // x5
  __int64 v34; // x6
  __int64 v35; // x7
  __int64 *k; // x21
  int v37; // w8
  int v38; // w8
  unsigned int v39; // w8
  unsigned int v40; // w9
  unsigned int v41; // w8
  unsigned int v42; // w10
  unsigned int v43; // w0
  unsigned int v44; // w20
  __int64 v45; // x3
  __int64 v46; // x4
  __int64 v47; // x5
  __int64 v48; // x6
  __int64 v49; // x7
  unsigned int v50; // w8
  unsigned int v51; // w9
  unsigned int v52; // w0
  unsigned int v53; // w20
  __int64 v54; // x6
  __int64 v55; // x7
  __int64 *v56; // x21
  int v57; // w20
  int v58; // w25
  unsigned int v59; // w0
  __int64 v60; // x0
  __int64 v61; // x3
  __int64 v62; // x4
  __int64 v63; // x5
  __int64 v64; // x6
  __int64 v65; // x7
  unsigned int *v66; // x21
  int v67; // w20
  unsigned int v68; // w26
  int v69; // w21
  unsigned int v70; // w25
  __int64 v71; // x0
  __int64 v72; // x0
  __int64 v73; // x1
  int v74; // w21
  int v75; // w26
  __int64 v76; // x0
  __int64 v77; // x8
  int v78; // w9
  __int64 **v79; // x1
  __int64 v80; // x0
  __int64 v81; // x25
  __int64 i; // x0
  int v83; // w8
  unsigned int v84; // w0
  unsigned int v85; // w20
  __int64 v86; // x3
  __int64 v87; // x4
  __int64 v88; // x5
  __int64 v89; // x6
  __int64 v90; // x7
  __int64 v91; // x0
  __int64 v92; // x20
  __int64 j; // x0
  __int64 v94; // x0
  __int64 v95; // x21
  __int64 v96; // x0
  unsigned int *v97; // x25
  unsigned int v98; // w8
  unsigned int v99; // w9
  unsigned int v100; // w0
  unsigned int v101; // w20
  __int64 v102; // x6
  __int64 v103; // x7
  __int64 v104; // x2
  __int64 v105; // x0
  __int64 v106; // x1
  unsigned int v107; // w0
  __int64 v108; // x3
  __int64 v109; // x4
  __int64 v110; // x5
  __int64 v111; // x6
  __int64 v112; // x7
  unsigned int v113; // w20
  unsigned int v114; // w0
  unsigned int v115; // w20
  __int64 v116; // x3
  __int64 v117; // x4
  __int64 v118; // x5
  __int64 v119; // x6
  __int64 v120; // x7
  __int64 *v121; // x9
  int v122; // w8
  __int64 **v123; // x8
  __int64 *v124; // x9
  __int64 *v125; // x10
  __int64 *v126; // x0
  unsigned int v127; // w8
  int v128; // w8
  __int64 **v129; // x8
  __int64 v130; // x2
  void *v131; // x0
  const char *v132; // x1
  _DWORD *v133; // [xsp+20h] [xbp-140h] BYREF
  __int64 v134; // [xsp+28h] [xbp-138h]
  _QWORD *v135; // [xsp+30h] [xbp-130h] BYREF
  int v136; // [xsp+38h] [xbp-128h]
  int v137; // [xsp+3Ch] [xbp-124h]
  __int64 v138; // [xsp+40h] [xbp-120h]
  __int64 v139; // [xsp+48h] [xbp-118h]
  __int64 v140; // [xsp+50h] [xbp-110h]
  __int64 v141; // [xsp+58h] [xbp-108h]
  __int64 v142; // [xsp+60h] [xbp-100h]
  __int64 v143; // [xsp+68h] [xbp-F8h]
  __int64 v144; // [xsp+70h] [xbp-F0h]
  __int64 v145; // [xsp+78h] [xbp-E8h]
  __int64 v146; // [xsp+80h] [xbp-E0h]
  __int64 v147; // [xsp+88h] [xbp-D8h]
  __int64 v148; // [xsp+90h] [xbp-D0h]
  _QWORD v149[2]; // [xsp+98h] [xbp-C8h] BYREF
  __int64 v150; // [xsp+A8h] [xbp-B8h] BYREF
  unsigned int v151; // [xsp+B0h] [xbp-B0h]
  __int64 v152; // [xsp+B8h] [xbp-A8h] BYREF
  _QWORD *v153; // [xsp+C0h] [xbp-A0h] BYREF
  __int64 v154; // [xsp+C8h] [xbp-98h]
  __int64 *v155; // [xsp+D0h] [xbp-90h] BYREF
  __int64 v156; // [xsp+D8h] [xbp-88h]
  __int64 v157; // [xsp+E0h] [xbp-80h]
  __int64 v158; // [xsp+E8h] [xbp-78h]
  __int64 v159; // [xsp+F0h] [xbp-70h]
  __int64 v160; // [xsp+F8h] [xbp-68h]
  __int64 v161; // [xsp+100h] [xbp-60h]
  __int64 v162; // [xsp+108h] [xbp-58h]
  __int64 v163; // [xsp+110h] [xbp-50h]
  __int64 v164; // [xsp+118h] [xbp-48h]
  __int64 v165; // [xsp+120h] [xbp-40h]
  __int64 v166; // [xsp+128h] [xbp-38h]
  __int64 v167; // [xsp+130h] [xbp-30h]
  _QWORD v168[5]; // [xsp+138h] [xbp-28h] BYREF

  v168[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v135 = v149;
  v137 = 0;
  LODWORD(v149[1]) = 0;
  v148 = 0;
  v149[0] = 0;
  v146 = 0;
  v147 = 0;
  v144 = 0;
  v145 = 0;
  v142 = 0;
  v143 = 0;
  v140 = 0;
  v141 = 0;
  v138 = 0;
  v139 = 0;
  v136 = 12;
  result = _kmalloc_cache_noprof(down_write, 3520, 4096);
  v1 = (_DWORD *)result;
  if ( result )
  {
    v133 = (_DWORD *)result;
    v134 = 4096;
    v2 = kernel_recvmsg(qrtr_ns, &v135, &v133, 1, 4096, 64);
    if ( v2 == -11 )
      goto LABEL_3;
    _ReadStatusReg(SP_EL0);
LABEL_8:
    if ( (v2 & 0x80000000) == 0 )
    {
      v8 = *v1;
      v9 = *v1;
      if ( *v1 <= 0xBu )
        v9 = *v1;
      v10 = v9 & 0xFFFFFFFE;
      if ( (v9 & 0xFFFFFFFE) == 2 )
      {
        ipc_log_string(ns_ilc, "cmd:0x%x node[0x%x]\n", v9, HIDWORD(v149[0]));
      }
      else if ( v9 == 6 )
      {
        ipc_log_string(ns_ilc, "cmd:0x%x addr[0x%x:0x%x]\n");
      }
      else if ( v10 == 10 )
      {
        ipc_log_string(ns_ilc, "cmd:0x%x SVC[0x%x:0x%x]\n");
      }
      else if ( v10 == 4 )
      {
        ipc_log_string(ns_ilc, "cmd:0x%x SVC[0x%x:0x%x] addr[0x%x:0x%x]\n", v9, v1[1], v1[2], v1[3], v1[4]);
      }
      if ( v8 > 4 )
      {
        if ( v8 > 9 )
        {
          if ( v8 == 10 )
          {
            if ( HIDWORD(v149[0]) != dword_D9F8 )
              goto LABEL_150;
            v74 = v1[1];
            v75 = v1[2];
            v150 = 0;
            v152 = 0;
            v76 = _kmalloc_cache_noprof(kfree, 3520, 40);
            if ( !v76 )
              goto LABEL_150;
            v77 = v149[0];
            v78 = v149[1];
            v79 = (__int64 **)qword_D988;
            *(_DWORD *)v76 = v74;
            *(_DWORD *)(v76 + 4) = v75;
            *(_QWORD *)(v76 + 8) = v77;
            *(_DWORD *)(v76 + 16) = v78;
            if ( v79 == (__int64 **)(v76 + 24) || *v79 != &qword_D980 )
            {
              _list_add_valid_or_report(v76 + 24, v79);
            }
            else
            {
              qword_D988 = v76 + 24;
              *(_QWORD *)(v76 + 24) = &qword_D980;
              *(_QWORD *)(v76 + 32) = v79;
              *v79 = (__int64 *)(v76 + 24);
            }
            v150 = 0;
            v80 = xa_find(&nodes, &v150, -1, 8);
            if ( v80 )
            {
              v81 = v80;
              do
              {
                v152 = 0;
                for ( i = xa_find(v81 + 8, &v152, -1, 8); i; i = xa_find_after(v81 + 8, &v152, -1, 8) )
                {
                  if ( (!v74 || *(_DWORD *)i == v74) && (!v75 || *(_DWORD *)(i + 4) == v75) )
                  {
                    v166 = 0;
                    v167 = 0;
                    v164 = 0;
                    v165 = 0;
                    v162 = 0;
                    v163 = 0;
                    v160 = 0;
                    v161 = 0;
                    v158 = 0;
                    v159 = 0;
                    v156 = 0;
                    v157 = 0;
                    v153 = v168;
                    v154 = 20;
                    *(_QWORD *)((char *)v168 + 4) = 0;
                    *(_QWORD *)((char *)&v168[1] + 4) = 0;
                    LODWORD(v168[0]) = 4;
                    HIDWORD(v168[0]) = *(_DWORD *)i;
                    v83 = *(_DWORD *)(i + 4);
                    v155 = v149;
                    LODWORD(v168[1]) = v83;
                    *(_QWORD *)((char *)&v168[1] + 4) = *(_QWORD *)(i + 8);
                    LODWORD(v156) = 12;
                    v84 = kernel_sendmsg(qrtr_ns, &v155, &v153, 1, 20);
                    if ( (v84 & 0x80000000) != 0 )
                    {
                      v85 = v84;
                      if ( v84 != -19 )
                      {
                        if ( (unsigned int)__ratelimit(&lookup_notify__rs, "lookup_notify") )
                          printk(&unk_E226, "lookup_notify", v85, v86, v87, v88, v89, v90);
                      }
                    }
                  }
                }
                v81 = xa_find_after(&nodes, &v150, -1, 8);
              }
              while ( v81 );
            }
            LODWORD(v168[0]) = 4;
            v166 = 0;
            v167 = 0;
            v164 = 0;
            v165 = 0;
            v162 = 0;
            v163 = 0;
            v160 = 0;
            v161 = 0;
            v158 = 0;
            v159 = 0;
            v156 = 12;
            v157 = 0;
            v153 = v168;
            v154 = 20;
            *(_QWORD *)((char *)v168 + 4) = 0;
            *(_QWORD *)((char *)&v168[1] + 4) = 0;
            v155 = v149;
            v114 = kernel_sendmsg(qrtr_ns, &v155, &v153, 1, 20);
            if ( (v114 & 0x80000000) != 0 )
            {
              v115 = v114;
              if ( v114 != -19 )
              {
                if ( (unsigned int)__ratelimit(&lookup_notify__rs, "lookup_notify") )
                  printk(&unk_E226, "lookup_notify", v115, v116, v117, v118, v119, v120);
              }
            }
          }
          else if ( v8 == 11 )
          {
            v56 = (__int64 *)qword_D980;
            if ( (__int64 *)qword_D980 != &qword_D980 )
            {
              v57 = v1[1];
              v58 = v1[2];
              do
              {
                v127 = *((_DWORD *)v56 - 3);
                v124 = v56;
                v56 = (__int64 *)*v56;
                if ( __PAIR64__(*((_DWORD *)v124 - 2), v127) == *(_QWORD *)((char *)v149 + 4) )
                {
                  v126 = v124 - 3;
                  if ( *((_DWORD *)v124 - 6) == v57 )
                  {
                    v128 = *((_DWORD *)v124 - 5);
                    if ( !v128 || v128 == v58 )
                    {
                      v129 = (__int64 **)v124[1];
                      if ( *v129 == v124 && (__int64 *)v56[1] == v124 )
                      {
                        v56[1] = (__int64)v129;
                        *v129 = v56;
                      }
                      else
                      {
                        _list_del_entry_valid_or_report(v124);
                        v126 = v125;
                      }
                      *v124 = 0xDEAD000000000100LL;
                      v124[1] = 0xDEAD000000000122LL;
                      kfree(v126);
                    }
                  }
                }
              }
              while ( v56 != &qword_D980 );
            }
          }
        }
        else if ( v8 == 5 )
        {
          v67 = HIDWORD(v149[0]);
          v68 = v149[1];
          v69 = dword_D9F8;
          v70 = v1[4];
          if ( HIDWORD(v149[0]) == dword_D9F8 )
            v71 = HIDWORD(v149[0]);
          else
            v71 = (unsigned int)v1[3];
          v72 = node_get(v71);
          if ( !v72 )
            goto LABEL_150;
          if ( v67 == v69 )
            v73 = v68;
          else
            v73 = v70;
          server_del(v72, v73, 1);
        }
        else if ( v8 == 6 )
        {
          v12 = v1[1];
          v11 = v1[2];
          v166 = 0;
          v167 = 0;
          v164 = 0;
          v165 = 0;
          v162 = 0;
          v163 = 0;
          v160 = 0;
          v161 = 0;
          v158 = 0;
          v159 = 0;
          v156 = 0;
          v157 = 0;
          v153 = v168;
          v154 = 20;
          v155 = nullptr;
          if ( HIDWORD(v149[0]) != v12 || dword_D9F8 == v12 && LODWORD(v149[1]) != v11 )
            goto LABEL_150;
          v13 = (__int64 *)qword_D980;
          memset(v168, 0, 20);
          v150 = 0;
          v151 = 0;
          v152 = 0;
          if ( (__int64 *)qword_D980 != &qword_D980 )
          {
            do
            {
              v122 = *((_DWORD *)v13 - 3);
              v121 = v13;
              v13 = (__int64 *)*v13;
              if ( v122 == v12 && *((_DWORD *)v121 - 2) == v11 )
              {
                v123 = (__int64 **)v121[1];
                if ( *v123 == v121 && (__int64 *)v13[1] == v121 )
                {
                  v13[1] = (__int64)v123;
                  *v123 = v13;
                }
                else
                {
                  _list_del_entry_valid_or_report(v121);
                }
                *v121 = 0xDEAD000000000100LL;
                v121[1] = 0xDEAD000000000122LL;
                kfree(v121 - 3);
              }
            }
            while ( v13 != &qword_D980 );
          }
          v14 = node_get(v12);
          if ( v14 )
            server_del(v14, v11, 0);
          v15 = node_get((unsigned int)dword_D9F8);
          if ( v15 )
          {
            v16 = v15;
            *(_QWORD *)((char *)&v168[1] + 4) = 0;
            LODWORD(v168[0]) = 6;
            HIDWORD(v168[0]) = v12;
            LODWORD(v168[1]) = v11;
            v152 = 0;
            v17 = xa_find(v15 + 8, &v152, -1, 8);
            if ( v17 )
            {
              v18 = (unsigned int *)v17;
              do
              {
                v50 = v18[2];
                v51 = v18[3];
                LOWORD(v150) = 42;
                HIDWORD(v150) = v50;
                v151 = v51;
                v155 = &v150;
                LODWORD(v156) = 12;
                v52 = kernel_sendmsg(qrtr_ns, &v155, &v153, 1, 20);
                if ( (v52 & 0x80000000) != 0 )
                {
                  v53 = v52;
                  if ( v52 != -19 )
                  {
                    if ( (unsigned int)__ratelimit(&ctrl_cmd_del_client__rs, "ctrl_cmd_del_client") )
                      printk(&unk_DB9C, "ctrl_cmd_del_client", *v18, v18[1], v18[3], v53, v54, v55);
                  }
                }
                v18 = (unsigned int *)xa_find_after(v16 + 8, &v152, -1, 8);
              }
              while ( v18 );
            }
          }
        }
        goto LABEL_7;
      }
      if ( v8 != 2 )
      {
        if ( v8 == 3 )
        {
          memset(v168, 0, 20);
          v151 = 0;
          v150 = 0;
          v166 = 0;
          v167 = 0;
          v164 = 0;
          v165 = 0;
          v162 = 0;
          v163 = 0;
          v160 = 0;
          v161 = 0;
          v158 = 0;
          v159 = 0;
          v156 = 0;
          v157 = 0;
          v154 = 20;
          v155 = nullptr;
          v153 = v168;
          v91 = node_get(HIDWORD(v149[0]));
          if ( v91 )
          {
            v92 = v91;
            v152 = 0;
            for ( j = xa_find(v91 + 8, &v152, -1, 8); j; j = xa_find_after(v92 + 8, &v152, -1, 8) )
              server_del(v92, *(unsigned int *)(j + 12), 1);
            v94 = node_get((unsigned int)dword_D9F8);
            if ( v94 )
            {
              v95 = v94;
              LODWORD(v168[2]) = 0;
              v168[1] = 0;
              LODWORD(v168[0]) = 3;
              HIDWORD(v168[0]) = HIDWORD(v149[0]);
              v152 = 0;
              v96 = xa_find(v94 + 8, &v152, -1, 8);
              if ( v96 )
              {
                v97 = (unsigned int *)v96;
                do
                {
                  v98 = v97[2];
                  v99 = v97[3];
                  LOWORD(v150) = 42;
                  HIDWORD(v150) = v98;
                  v151 = v99;
                  v155 = &v150;
                  LODWORD(v156) = 12;
                  v100 = kernel_sendmsg(qrtr_ns, &v155, &v153, 1, 20);
                  if ( (v100 & 0x80000000) != 0 )
                  {
                    v101 = v100;
                    if ( v100 != -19 )
                    {
                      if ( (unsigned int)__ratelimit(&ctrl_cmd_bye__rs, "ctrl_cmd_bye") )
                        printk(&unk_DC1C, "ctrl_cmd_bye", *v97, v97[1], v97[3], v101, v102, v103);
                    }
                  }
                  v97 = (unsigned int *)xa_find_after(v95 + 8, &v152, -1, 8);
                }
                while ( v97 );
              }
            }
          }
          goto LABEL_7;
        }
        if ( v8 != 4 )
          goto LABEL_7;
        v19 = v1[1];
        if ( HIDWORD(v149[0]) == dword_D9F8 )
          v20 = (unsigned int *)&v149[1];
        else
          v20 = v1 + 4;
        if ( HIDWORD(v149[0]) == dword_D9F8 )
          v21 = HIDWORD(v149[0]);
        else
          v21 = v1[3];
        if ( !v19 )
          goto LABEL_150;
        v22 = *v20;
        if ( !(_DWORD)v22 )
          goto LABEL_150;
        v23 = v1[2];
        v24 = (unsigned int *)_kmalloc_cache_noprof(kthread_create_on_node, 3520, 32);
        if ( !v24 )
          goto LABEL_150;
        *v24 = v19;
        v24[1] = v23;
        v24[2] = v21;
        v24[3] = v22;
        v25 = node_get(v21);
        if ( !v25 )
          goto LABEL_147;
        v26 = xa_store(v25 + 8, v22, v24, 3264);
        if ( v26 )
        {
          if ( v26 < 0xFFFFFFFFFFFFC006LL || (v26 & 3) != 2 )
          {
            kfree(v26);
            goto LABEL_49;
          }
          printk(&unk_E268, "server_add", *v24, v24[1], v26 >> 2, v27, v28, v29);
LABEL_147:
          kfree(v24);
          goto LABEL_150;
        }
LABEL_49:
        ipc_log_string(ns_ilc, "%s: [0x%x:0x%x]@[0x%x:0x%x]\n", "server_add", *v24, v24[1], v24[2], v24[3]);
        if ( v24[2] != dword_D9F8 || (v30 = service_announce_new(&word_D970, v24), (v30 & 0x80000000) == 0) )
        {
          for ( k = (__int64 *)qword_D980; k != &qword_D980; k = (__int64 *)*k )
          {
            v37 = *((_DWORD *)k - 6);
            if ( !v37 || v37 == v19 )
            {
              v38 = *((_DWORD *)k - 5);
              if ( !v38 || v38 == v23 )
              {
                v153 = v168;
                v154 = 20;
                v39 = *v24;
                v40 = v24[1];
                v166 = 0;
                v167 = 0;
                v164 = 0;
                v165 = 0;
                LODWORD(v168[0]) = 4;
                HIDWORD(v168[0]) = v39;
                v41 = v24[2];
                v42 = v24[3];
                v162 = 0;
                v163 = 0;
                v160 = 0;
                v161 = 0;
                v168[1] = __PAIR64__(v41, v40);
                v155 = k - 2;
                v158 = 0;
                v159 = 0;
                v156 = 12;
                v157 = 0;
                LODWORD(v168[2]) = v42;
                v43 = kernel_sendmsg(qrtr_ns, &v155, &v153, 1, 20);
                if ( (v43 & 0x80000000) != 0 )
                {
                  v44 = v43;
                  if ( v43 != -19 )
                  {
                    if ( (unsigned int)__ratelimit(&lookup_notify__rs, "lookup_notify") )
                      printk(&unk_E226, "lookup_notify", v44, v45, v46, v47, v48, v49);
                  }
                }
              }
            }
          }
          goto LABEL_7;
        }
        v130 = v30;
        v131 = &unk_DCF6;
        v132 = "ctrl_cmd_new_server";
LABEL_149:
        printk(v131, v132, v130, v31, v32, v33, v34, v35);
        goto LABEL_150;
      }
      LODWORD(v168[0]) = 2;
      v166 = 0;
      v167 = 0;
      v164 = 0;
      v165 = 0;
      v162 = 0;
      v163 = 0;
      v160 = 0;
      v161 = 0;
      v158 = 0;
      v159 = 0;
      v156 = 12;
      v157 = 0;
      v153 = v168;
      v154 = 20;
      *(_QWORD *)((char *)v168 + 4) = 0;
      *(_QWORD *)((char *)&v168[1] + 4) = 0;
      v155 = v149;
      v59 = kernel_sendmsg(qrtr_ns, &v155, &v153, 1, 20);
      if ( (v59 & 0x80000000) != 0 )
      {
        v130 = v59;
        v131 = &unk_E189;
        v132 = "say_hello";
        goto LABEL_149;
      }
      v168[0] = 0;
      v155 = nullptr;
      v60 = xa_find(&nodes, &v155, -1, 8);
      if ( !v60 )
        goto LABEL_7;
      v66 = (unsigned int *)v60;
      while ( 1 )
      {
        v104 = *v66;
        if ( (_DWORD)v104 == HIDWORD(v149[0]) )
        {
          printk(&unk_DF9E, "announce_servers", v104, v61, v62, v63, v64, v65);
        }
        else
        {
          v168[0] = 0;
          v105 = xa_find(v66 + 2, v168, -1, 8);
          if ( v105 )
          {
            v106 = v105;
            while ( 1 )
            {
              v107 = service_announce_new(v149, v106);
              if ( (v107 & 0x80000000) != 0 && v107 != -19 )
                break;
              v106 = xa_find_after(v66 + 2, v168, -1, 8);
              if ( !v106 )
                goto LABEL_113;
            }
            v113 = v107;
            printk(&unk_DCF6, "announce_servers", v107, v108, v109, v110, v111, v112);
            if ( (v113 & 0x80000000) != 0 )
LABEL_150:
              printk(&unk_E50D, "qrtr_ns_worker", HIDWORD(v149[0]), LODWORD(v149[1]), v4, v5, v6, v7);
LABEL_7:
            v133 = v1;
            v134 = 4096;
            v2 = kernel_recvmsg(qrtr_ns, &v135, &v133, 1, 4096, 64);
            if ( v2 == -11 )
              goto LABEL_3;
            goto LABEL_8;
          }
        }
LABEL_113:
        v66 = (unsigned int *)xa_find_after(&nodes, &v155, -1, 8);
        if ( !v66 )
          goto LABEL_7;
      }
    }
    printk(&unk_E593, "qrtr_ns_worker", v2, v3, v4, v5, v6, v7);
LABEL_3:
    result = kfree(v1);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
