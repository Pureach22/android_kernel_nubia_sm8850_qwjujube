__int64 __fastcall rmnet_wlan_ingress_rx_handler(__int64 *a1)
{
  __int64 v1; // x20
  __int64 unlock; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 result; // x0
  __int64 v8; // x19
  int v9; // w8
  int v10; // w8
  int v11; // w9
  __int64 *v12; // x20
  int v13; // w8
  int v14; // w8
  int v15; // w9
  __int64 *v16; // x20
  __int64 v17; // x8
  __int64 v18; // x20
  int v19; // w22
  int v20; // w8
  int v21; // w8
  int v22; // w8
  int v23; // w9
  unsigned __int64 v24; // x21
  int v25; // w8
  int v26; // w8
  char v27; // w8
  int v28; // w8
  int v29; // w9
  __int64 *v30; // x21
  unsigned __int64 v31; // x8
  __int64 v32; // x9
  __int64 v33; // x10
  _QWORD *v34; // t2
  __int64 lock; // x0
  __int64 *i; // x21
  int v37; // w8
  __int64 v38; // x21
  unsigned __int64 v39; // x0
  unsigned __int64 v40; // x10
  __int64 v41; // x11
  unsigned int v42; // w8
  int v43; // w9
  __int64 v44; // x11
  unsigned __int64 v45; // x12
  unsigned __int64 *v46; // x10
  unsigned __int64 v47; // x8
  int v48; // w8
  int v49; // w8
  int v50; // w8
  __int64 v51; // x1
  int v52; // w8
  int v53; // w8
  int v54; // w9
  __int64 *v55; // x20
  __int64 dev; // x0
  __int64 v57; // x0
  int v58; // w9
  int v59; // w8
  unsigned __int64 v60; // x0
  __int64 v61; // x0
  int v62; // w8
  int v63; // w9
  __int64 *v64; // x21
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x8
  __int64 v68; // x8
  int v69; // w9
  _DWORD *v70; // x8
  unsigned __int64 v71; // x0
  int v72; // w8
  int v73; // w9
  __int64 *v74; // x20
  __int64 v75; // x0
  __int64 v76; // x0
  int v77; // w9
  unsigned __int64 v78; // x1
  __int64 v79; // x0
  int v80; // w8
  int v81; // w9
  __int64 *v82; // x21
  __int64 v83; // x8
  __int64 v84; // x8
  _DWORD *v85; // x8
  unsigned __int64 v86; // x1
  __int64 v87; // x0
  int v88; // w10
  _DWORD *v89; // x8
  unsigned __int64 v90; // x21
  __int64 (*v91)(void); // x8
  unsigned __int64 v92; // x20
  __int64 v93; // x8
  int v95; // w8
  int v96; // w9
  __int64 *v97; // x20
  __int64 v98; // x0
  __int64 v99; // x0
  int v100; // w9
  unsigned __int64 v101; // x1
  __int64 v102; // x0
  unsigned __int64 v103; // x21
  __int64 (*v104)(void); // x8
  unsigned __int64 v105; // x20
  __int64 v106; // x8
  unsigned __int64 v107; // x0
  int v108; // w8
  int v109; // w9
  __int64 *v110; // x21
  __int64 v111; // x8
  __int64 v112; // x8
  _DWORD *v113; // x8
  unsigned __int64 v114; // x1
  __int64 v115; // x0
  int v116; // w10
  _DWORD *v117; // x8
  unsigned __int64 v118; // x0
  int v119; // w19
  __int64 v120; // x0
  unsigned int v121; // w8
  int v122; // w9
  unsigned int v123; // w8
  int v124; // w9
  _DWORD *v125; // x8
  unsigned int v126; // w8
  int v127; // w9
  unsigned int v128; // w8
  int v129; // w9
  _DWORD *v130; // x8
  int v131; // w19
  unsigned __int64 v132; // x0
  unsigned __int64 v133; // x0
  unsigned int v134; // w8
  int v135; // w9
  unsigned int v136; // w8
  int v137; // w9
  _DWORD *v138; // x8
  unsigned int v139; // w8
  int v140; // w9
  unsigned int v141; // w8
  int v142; // w9
  _DWORD *v143; // x8
  int v149; // w8
  _BYTE v150[4]; // [xsp+Ch] [xbp-D4h] BYREF
  __int64 v151; // [xsp+10h] [xbp-D0h] BYREF
  __int64 v152; // [xsp+18h] [xbp-C8h]
  __int64 v153; // [xsp+20h] [xbp-C0h]
  __int64 v154; // [xsp+28h] [xbp-B8h]
  unsigned __int64 v155; // [xsp+30h] [xbp-B0h] BYREF
  __int64 v156; // [xsp+38h] [xbp-A8h]
  unsigned __int64 v157; // [xsp+40h] [xbp-A0h] BYREF
  __int64 v158; // [xsp+48h] [xbp-98h]
  int v159; // [xsp+50h] [xbp-90h]
  __int64 v160; // [xsp+58h] [xbp-88h] BYREF
  __int64 v161; // [xsp+60h] [xbp-80h]
  __int64 v162; // [xsp+68h] [xbp-78h]
  __int64 v163; // [xsp+70h] [xbp-70h]
  __int64 v164; // [xsp+78h] [xbp-68h]
  __int64 v165; // [xsp+80h] [xbp-60h]
  __int64 v166; // [xsp+88h] [xbp-58h]
  __int64 v167; // [xsp+90h] [xbp-50h]
  __int64 v168; // [xsp+98h] [xbp-48h]
  __int64 v169; // [xsp+A0h] [xbp-40h]
  __int64 v170; // [xsp+A8h] [xbp-38h]
  __int64 v171; // [xsp+B0h] [xbp-30h] BYREF
  __int64 v172; // [xsp+B8h] [xbp-28h]
  __int64 v173; // [xsp+C0h] [xbp-20h]
  __int64 v174; // [xsp+C8h] [xbp-18h]
  __int64 v175; // [xsp+D0h] [xbp-10h]
  __int64 v176; // [xsp+D8h] [xbp-8h]

  v176 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    goto LABEL_10;
  if ( !*a1 )
    goto LABEL_10;
  v1 = *(_QWORD *)(*a1 + 16);
  if ( !v1 )
    goto LABEL_10;
  unlock = rmnet_wlan_strlcmp(v1 + 296, "r_rmnet_data", 12);
  if ( !(_DWORD)unlock )
  {
    v8 = *a1;
    v159 = 0;
    v157 = 0;
    v158 = 0;
    v155 = 0;
    v156 = 0;
    if ( !v8 || (*(_BYTE *)(v8 + 128) & 7) == 5 )
      goto LABEL_10;
    v9 = *(unsigned __int16 *)(v8 + 180);
    v153 = 0;
    v154 = 0;
    v151 = 0;
    v152 = 0;
    if ( v9 == 56710 )
    {
      v14 = *(_DWORD *)(v8 + 112);
      v15 = *(_DWORD *)(v8 + 116);
      v163 = 0;
      v164 = 0;
      v161 = 0;
      v162 = 0;
      v160 = 0;
      if ( v14 - v15 <= 39 )
      {
        v16 = &v160;
        unlock = skb_copy_bits(v8, 0, &v160, 40);
        if ( (unlock & 0x80000000) != 0 )
          goto LABEL_62;
      }
      else
      {
        v16 = *(__int64 **)(v8 + 224);
        if ( !v16 )
          goto LABEL_62;
      }
      v17 = v16[2];
      v152 = v16[1];
      v153 = v17;
      LOBYTE(v154) = 6;
    }
    else
    {
      if ( v9 != 8 )
        goto LABEL_62;
      v10 = *(_DWORD *)(v8 + 112);
      v11 = *(_DWORD *)(v8 + 116);
      LODWORD(v162) = 0;
      v160 = 0;
      v161 = 0;
      if ( v10 - v11 <= 19 )
      {
        v12 = &v160;
        unlock = skb_copy_bits(v8, 0, &v160, 20);
        if ( (unlock & 0x80000000) != 0 )
          goto LABEL_62;
      }
      else
      {
        v12 = *(__int64 **)(v8 + 224);
        if ( !v12 )
          goto LABEL_62;
      }
      v13 = *((_DWORD *)v12 + 3);
      LOBYTE(v154) = 4;
      LODWORD(v152) = v13;
    }
    ((void (*)(void))_rcu_read_lock)();
    v18 = rmnet_wlan_fwd_info_find(&v151);
    unlock = ((__int64 (*)(void))_rcu_read_unlock)();
    if ( v18 )
    {
      v19 = *(unsigned __int8 *)(v18 + 97);
      if ( v19 == 255 )
        goto LABEL_63;
      if ( *(_QWORD *)(v8 + 16) )
      {
        v20 = *(_DWORD *)(v8 + 129);
        *(_QWORD *)(v8 + 104) = 7;
        *(_DWORD *)(v8 + 129) = v20 | 0x800000;
      }
      v21 = *(unsigned __int16 *)(v8 + 180);
      if ( v21 == 56710 )
      {
        v28 = *(_DWORD *)(v8 + 112);
        v29 = *(_DWORD *)(v8 + 116);
        v163 = 0;
        v164 = 0;
        v161 = 0;
        v162 = 0;
        v160 = 0;
        LOWORD(v171) = 0;
        if ( v28 - v29 <= 39 )
        {
          v30 = &v160;
          unlock = skb_copy_bits(v8, 0, &v160, 40);
          if ( (unlock & 0x80000000) != 0 )
            goto LABEL_63;
        }
        else
        {
          v30 = *(__int64 **)(v8 + 224);
          if ( !v30 )
            goto LABEL_63;
        }
        v150[0] = *((_BYTE *)v30 + 6);
        unlock = ipv6_skip_exthdr(v8, 40, v150, &v171);
        if ( (unlock & 0x80000000) != 0 || (_WORD)v171 && v150[0] == 44 )
        {
LABEL_63:
          v49 = *(_DWORD *)(v8 + 116);
          if ( v49 && *(_DWORD *)(v8 + 112) == v49 )
          {
            v50 = *(unsigned __int16 *)(v8 + 180);
            if ( v50 == 8 )
            {
              v51 = 20;
            }
            else
            {
              if ( v50 != 56710 )
              {
                v61 = 43;
                goto LABEL_214;
              }
              v51 = 40;
            }
            if ( !_pskb_pull_tail(v8, v51) )
            {
              v61 = 45;
              goto LABEL_214;
            }
            *(_WORD *)(v8 + 184) = *(_WORD *)(v8 + 224) - *(_DWORD *)(v8 + 216);
            unlock = rmnet_wlan_forward_stats_update(44);
          }
          if ( !*(_QWORD *)(v8 + 16) )
            goto LABEL_215;
          v52 = *(unsigned __int16 *)(v8 + 180);
          if ( v19 == 2 && v52 == 8 )
          {
            v53 = *(_DWORD *)(v8 + 112);
            v54 = *(_DWORD *)(v8 + 116);
            LODWORD(v173) = 0;
            v171 = 0;
            v172 = 0;
            v165 = 0;
            v166 = 0;
            v163 = 0;
            v164 = 0;
            v161 = 0;
            v162 = 0;
            v160 = 0;
            if ( v53 - v54 <= 19 )
            {
              v55 = &v171;
              unlock = skb_copy_bits(v8, 0, &v171, 20);
              if ( (unlock & 0x80000000) == 0 )
                goto LABEL_76;
            }
            else
            {
              v55 = *(__int64 **)(v8 + 224);
              if ( v55 )
              {
LABEL_76:
                dev = rmnet_wlan_get_dev(unlock);
                v57 = dev_get_by_name_rcu(&init_net, dev);
                if ( !v57 )
                {
                  v61 = 5;
                  goto LABEL_214;
                }
                *(_QWORD *)(v8 + 16) = v57;
                v58 = *(_DWORD *)(v57 + 224);
                LODWORD(v165) = *((_DWORD *)v55 + 3);
                v59 = *((_DWORD *)v55 + 4);
                LODWORD(v160) = v58;
                BYTE3(v162) = 2;
                HIDWORD(v165) = v59;
                v60 = ip_route_output_flow(&init_net, &v160, 0);
                if ( v60 >= 0xFFFFFFFFFFFFF001LL )
                {
                  v61 = 6;
LABEL_214:
                  rmnet_wlan_forward_stats_update(v61);
                  goto LABEL_215;
                }
                v90 = v60;
                v91 = *(__int64 (**)(void))(*(_QWORD *)(v60 + 8) + 104LL);
                if ( *((_DWORD *)v91 - 1) != -1062013958 )
                  __break(0x8228u);
                v92 = v91();
                dst_release(v90);
                if ( v92 > 0xFFFFFFFFFFFFF000LL || !v92 )
                {
                  v61 = 7;
                  goto LABEL_214;
                }
                v93 = *(_QWORD *)(v92 + 360);
                if ( v93 != *(_QWORD *)(v8 + 16) || !*(_QWORD *)(v93 + 16) )
                {
                  rmnet_wlan_forward_stats_update(8);
                  _X0 = (unsigned int *)(v92 + 48);
                  __asm { PRFM            #0x11, [X0] }
                  do
                    v149 = __ldxr(_X0);
                  while ( __stlxr(v149 - 1, _X0) );
                  if ( v149 == 1 )
                  {
                    __dmb(9u);
                    neigh_destroy(v92);
                  }
                  else if ( v149 <= 0 )
                  {
                    refcount_warn_saturate();
                  }
                  goto LABEL_215;
                }
                v119 = neigh_resolve_output(v92, v8);
                neigh_release(v92);
                v120 = 2 * (unsigned int)((v119 & 0xFFFFFFFD) != 0);
LABEL_199:
                rmnet_wlan_forward_stats_update(v120);
LABEL_216:
                result = 0;
                goto LABEL_11;
              }
            }
LABEL_203:
            v61 = 18;
            goto LABEL_214;
          }
          if ( v19 == 2 && v52 == 56710 )
          {
            v62 = *(_DWORD *)(v8 + 112);
            v63 = *(_DWORD *)(v8 + 116);
            v174 = 0;
            v175 = 0;
            v172 = 0;
            v173 = 0;
            v170 = 0;
            v171 = 0;
            v168 = 0;
            v169 = 0;
            v167 = 0;
            v165 = 0;
            v166 = 0;
            v163 = 0;
            v164 = 0;
            v161 = 0;
            v162 = 0;
            v160 = 0;
            if ( v62 - v63 <= 39 )
            {
              v64 = &v171;
              unlock = skb_copy_bits(v8, 0, &v171, 40);
              if ( (unlock & 0x80000000) == 0 )
                goto LABEL_83;
            }
            else
            {
              v64 = *(__int64 **)(v8 + 224);
              if ( v64 )
              {
LABEL_83:
                v65 = rmnet_wlan_get_dev(unlock);
                v66 = dev_get_by_name_rcu(&init_net, v65);
                if ( !v66 )
                {
                  v61 = 10;
                  goto LABEL_214;
                }
                *(_QWORD *)(v8 + 16) = v66;
                v67 = v64[2];
                v167 = v64[1];
                v168 = v67;
                v68 = v64[4];
                v165 = v64[3];
                v166 = v68;
                v69 = *(_DWORD *)(v66 + 224);
                BYTE3(v162) = 2;
                v70 = *(_DWORD **)(ipv6_stub + 16LL);
                LODWORD(v160) = v69;
                if ( *(v70 - 1) != 1634652463 )
                  __break(0x8228u);
                v71 = ((__int64 (__fastcall *)(void *, _QWORD, __int64 *, _QWORD))v70)(&init_net, 0, &v160, 0);
                if ( v71 >= 0xFFFFFFFFFFFFF001LL )
                {
                  v61 = 11;
                  goto LABEL_214;
                }
                v103 = v71;
                v104 = *(__int64 (**)(void))(*(_QWORD *)(v71 + 8) + 104LL);
                if ( *((_DWORD *)v104 - 1) != -1062013958 )
                  __break(0x8228u);
                v105 = v104();
                dst_release(v103);
                if ( v105 > 0xFFFFFFFFFFFFF000LL || !v105 )
                {
                  v61 = 12;
                  goto LABEL_214;
                }
                v106 = *(_QWORD *)(v105 + 360);
                if ( v106 == *(_QWORD *)(v8 + 16) && *(_QWORD *)(v106 + 16) )
                {
                  v131 = neigh_resolve_output(v105, v8);
                  neigh_release(v105);
                  if ( (v131 & 0xFFFFFFFD) != 0 )
                    v120 = 3;
                  else
                    v120 = 1;
                  goto LABEL_199;
                }
                rmnet_wlan_forward_stats_update(13);
                neigh_release(v105);
LABEL_215:
                sk_skb_reason_drop(0, v8, 2);
                goto LABEL_216;
              }
            }
            v61 = 9;
            goto LABEL_214;
          }
          if ( v19 == 1 && v52 == 8 )
          {
            v72 = *(_DWORD *)(v8 + 112);
            v73 = *(_DWORD *)(v8 + 116);
            LODWORD(v173) = 0;
            v171 = 0;
            v172 = 0;
            v165 = 0;
            v166 = 0;
            v163 = 0;
            v164 = 0;
            v161 = 0;
            v162 = 0;
            v160 = 0;
            if ( v72 - v73 <= 19 )
            {
              v74 = &v171;
              unlock = skb_copy_bits(v8, 0, &v171, 20);
              if ( (unlock & 0x80000000) == 0 )
                goto LABEL_92;
            }
            else
            {
              v74 = *(__int64 **)(v8 + 224);
              if ( v74 )
              {
LABEL_92:
                v75 = rmnet_wwan_get_dev(unlock);
                v76 = dev_get_by_name_rcu(&init_net, v75);
                if ( !v76 )
                {
                  v61 = 38;
                  goto LABEL_214;
                }
                v77 = *(_DWORD *)(v76 + 224);
                HIDWORD(v165) = *((_DWORD *)v74 + 4);
                LODWORD(v160) = v77;
                BYTE3(v162) = 2;
                v78 = ip_route_output_flow(&init_net, &v160, 0);
                if ( v78 >= 0xFFFFFFFFFFFFF001LL )
                {
                  rmnet_wlan_forward_stats_update(40);
                  v79 = dev_get_by_name_rcu(&init_net, "dummy0");
                  if ( !v79 )
                  {
                    v61 = 36;
                    goto LABEL_214;
                  }
                  LODWORD(v160) = *(_DWORD *)(v79 + 224);
                  BYTE3(v162) = 2;
                  v78 = ip_route_output_flow(&init_net, &v160, 0);
                  if ( v78 > 0xFFFFFFFFFFFFF000LL )
                  {
                    v61 = 37;
                    goto LABEL_214;
                  }
                }
                LODWORD(v165) = *((_DWORD *)v74 + 3);
                v107 = xfrm_lookup(&init_net, v78, &v160, 0, 0);
                if ( v107 >= 0xFFFFFFFFFFFFF001LL )
                {
                  v61 = 34;
                  goto LABEL_214;
                }
                v121 = *(_DWORD *)(v8 + 129);
                *(_QWORD *)(v8 + 88) = v107;
                v122 = (v121 >> 23) & 1;
                v123 = v121 & 0xFF7FFFFF;
                if ( v107 )
                  v122 = 1;
                if ( v122 )
                  v124 = 0x800000;
                else
                  v124 = 0;
                *(_DWORD *)(v8 + 129) = v124 | v123;
                v125 = *(_DWORD **)((v107 & 0xFFFFFFFFFFFFFFFELL) + 48);
                if ( *(v125 - 1) != -18035962 )
                  __break(0x8228u);
                ((void (__fastcall *)(void *, _QWORD, __int64))v125)(&init_net, 0, v8);
                v120 = 35;
                goto LABEL_199;
              }
            }
            v61 = 41;
            goto LABEL_214;
          }
          if ( v19 == 1 && v52 == 56710 )
          {
            v80 = *(_DWORD *)(v8 + 112);
            v81 = *(_DWORD *)(v8 + 116);
            v174 = 0;
            v175 = 0;
            v172 = 0;
            v173 = 0;
            v170 = 0;
            v171 = 0;
            v168 = 0;
            v169 = 0;
            v167 = 0;
            v165 = 0;
            v166 = 0;
            v163 = 0;
            v164 = 0;
            v161 = 0;
            v162 = 0;
            v160 = 0;
            if ( v80 - v81 <= 39 )
            {
              v82 = &v171;
              if ( (skb_copy_bits(v8, 0, &v171, 40) & 0x80000000) == 0 )
              {
LABEL_103:
                v83 = v82[2];
                v167 = v82[1];
                v168 = v83;
                v84 = v82[4];
                v165 = v82[3];
                v166 = v84;
                v85 = *(_DWORD **)(ipv6_stub + 16LL);
                if ( *(v85 - 1) != 1634652463 )
                  __break(0x8228u);
                v86 = ((__int64 (__fastcall *)(void *, _QWORD, __int64 *, _QWORD))v85)(&init_net, 0, &v160, 0);
                if ( v86 >= 0xFFFFFFFFFFFFF001LL )
                {
                  rmnet_wlan_forward_stats_update(27);
                  v87 = dev_get_by_name_rcu(&init_net, "dummy0");
                  if ( !v87 )
                  {
                    v61 = 30;
                    goto LABEL_214;
                  }
                  v88 = *(_DWORD *)(v87 + 224);
                  BYTE3(v162) = 2;
                  v89 = *(_DWORD **)(ipv6_stub + 16LL);
                  LODWORD(v160) = v88;
                  if ( *(v89 - 1) != 1634652463 )
                    __break(0x8228u);
                  v86 = ((__int64 (__fastcall *)(void *, _QWORD, __int64 *, _QWORD))v89)(&init_net, 0, &v160, 0);
                  if ( v86 > 0xFFFFFFFFFFFFF000LL )
                  {
                    v61 = 31;
                    goto LABEL_214;
                  }
                }
                v118 = xfrm_lookup(&init_net, v86, &v160, 0, 0);
                if ( v118 >= 0xFFFFFFFFFFFFF001LL )
                {
                  v61 = 28;
                  goto LABEL_214;
                }
                v126 = *(_DWORD *)(v8 + 129);
                *(_QWORD *)(v8 + 88) = v118;
                v127 = (v126 >> 23) & 1;
                v128 = v126 & 0xFF7FFFFF;
                if ( v118 )
                  v127 = 1;
                if ( v127 )
                  v129 = 0x800000;
                else
                  v129 = 0;
                *(_DWORD *)(v8 + 129) = v129 | v128;
                v130 = *(_DWORD **)((v118 & 0xFFFFFFFFFFFFFFFELL) + 48);
                if ( *(v130 - 1) != -18035962 )
                  __break(0x8228u);
                ((void (__fastcall *)(void *, _QWORD, __int64))v130)(&init_net, 0, v8);
                v120 = 29;
                goto LABEL_199;
              }
            }
            else
            {
              v82 = *(__int64 **)(v8 + 224);
              if ( v82 )
                goto LABEL_103;
            }
            v61 = 26;
            goto LABEL_214;
          }
          if ( !v19 && v52 == 8 )
          {
            v95 = *(_DWORD *)(v8 + 112);
            v96 = *(_DWORD *)(v8 + 116);
            LODWORD(v173) = 0;
            v171 = 0;
            v172 = 0;
            v165 = 0;
            v166 = 0;
            v163 = 0;
            v164 = 0;
            v161 = 0;
            v162 = 0;
            v160 = 0;
            if ( v95 - v96 <= 19 )
            {
              v97 = &v171;
              unlock = skb_copy_bits(v8, 0, &v171, 20);
              if ( (unlock & 0x80000000) != 0 )
                goto LABEL_203;
            }
            else
            {
              v97 = *(__int64 **)(v8 + 224);
              if ( !v97 )
                goto LABEL_203;
            }
            v98 = rmnet_wlan_get_dev(unlock);
            v99 = dev_get_by_name_rcu(&init_net, v98);
            if ( !v99 )
            {
              v61 = 42;
              goto LABEL_214;
            }
            v100 = *(_DWORD *)(v99 + 224);
            HIDWORD(v165) = *((_DWORD *)v97 + 4);
            LODWORD(v160) = v100;
            BYTE3(v162) = 2;
            v101 = ip_route_output_flow(&init_net, &v160, 0);
            if ( v101 >= 0xFFFFFFFFFFFFF001LL )
            {
              rmnet_wlan_forward_stats_update(19);
              v102 = dev_get_by_name_rcu(&init_net, "dummy0");
              if ( !v102 )
              {
                v61 = 24;
                goto LABEL_214;
              }
              LODWORD(v160) = *(_DWORD *)(v102 + 224);
              BYTE3(v162) = 2;
              v101 = ip_route_output_flow(&init_net, &v160, 0);
              if ( v101 > 0xFFFFFFFFFFFFF000LL )
              {
                v61 = 25;
                goto LABEL_214;
              }
            }
            LODWORD(v165) = *((_DWORD *)v97 + 3);
            v132 = xfrm_lookup(&init_net, v101, &v160, 0, 0);
            if ( v132 >= 0xFFFFFFFFFFFFF001LL )
            {
              v61 = 20;
              goto LABEL_214;
            }
            v134 = *(_DWORD *)(v8 + 129);
            *(_QWORD *)(v8 + 88) = v132;
            v135 = (v134 >> 23) & 1;
            v136 = v134 & 0xFF7FFFFF;
            if ( v132 )
              v135 = 1;
            if ( v135 )
              v137 = 0x800000;
            else
              v137 = 0;
            *(_DWORD *)(v8 + 129) = v137 | v136;
            v138 = *(_DWORD **)((v132 & 0xFFFFFFFFFFFFFFFELL) + 48);
            if ( *(v138 - 1) != -18035962 )
              __break(0x8228u);
            ((void (__fastcall *)(void *, _QWORD, __int64))v138)(&init_net, 0, v8);
            v120 = 21;
            goto LABEL_199;
          }
          if ( v19 || v52 != 56710 )
            goto LABEL_215;
          v108 = *(_DWORD *)(v8 + 112);
          v109 = *(_DWORD *)(v8 + 116);
          v174 = 0;
          v175 = 0;
          v172 = 0;
          v173 = 0;
          v170 = 0;
          v171 = 0;
          v168 = 0;
          v169 = 0;
          v167 = 0;
          v165 = 0;
          v166 = 0;
          v163 = 0;
          v164 = 0;
          v161 = 0;
          v162 = 0;
          v160 = 0;
          if ( v108 - v109 <= 39 )
          {
            v110 = &v171;
            if ( (skb_copy_bits(v8, 0, &v171, 40) & 0x80000000) == 0 )
            {
LABEL_142:
              v111 = v110[2];
              v167 = v110[1];
              v168 = v111;
              v112 = v110[4];
              v165 = v110[3];
              v166 = v112;
              v113 = *(_DWORD **)(ipv6_stub + 16LL);
              if ( *(v113 - 1) != 1634652463 )
                __break(0x8228u);
              v114 = ((__int64 (__fastcall *)(void *, _QWORD, __int64 *, _QWORD))v113)(&init_net, 0, &v160, 0);
              if ( v114 >= 0xFFFFFFFFFFFFF001LL )
              {
                rmnet_wlan_forward_stats_update(15);
                v115 = dev_get_by_name_rcu(&init_net, "dummy0");
                if ( !v115 )
                {
                  v61 = 22;
                  goto LABEL_214;
                }
                v116 = *(_DWORD *)(v115 + 224);
                BYTE3(v162) = 2;
                v117 = *(_DWORD **)(ipv6_stub + 16LL);
                LODWORD(v160) = v116;
                if ( *(v117 - 1) != 1634652463 )
                  __break(0x8228u);
                v114 = ((__int64 (__fastcall *)(void *, _QWORD, __int64 *, _QWORD))v117)(&init_net, 0, &v160, 0);
                if ( v114 > 0xFFFFFFFFFFFFF000LL )
                {
                  v61 = 23;
                  goto LABEL_214;
                }
              }
              v133 = xfrm_lookup(&init_net, v114, &v160, 0, 0);
              if ( v133 >= 0xFFFFFFFFFFFFF001LL )
              {
                v61 = 16;
                goto LABEL_214;
              }
              v139 = *(_DWORD *)(v8 + 129);
              *(_QWORD *)(v8 + 88) = v133;
              v140 = (v139 >> 23) & 1;
              v141 = v139 & 0xFF7FFFFF;
              if ( v133 )
                v140 = 1;
              if ( v140 )
                v142 = 0x800000;
              else
                v142 = 0;
              *(_DWORD *)(v8 + 129) = v142 | v141;
              v143 = *(_DWORD **)((v133 & 0xFFFFFFFFFFFFFFFELL) + 48);
              if ( *(v143 - 1) != -18035962 )
                __break(0x8228u);
              ((void (__fastcall *)(void *, _QWORD, __int64))v143)(&init_net, 0, v8);
              v120 = 17;
              goto LABEL_199;
            }
          }
          else
          {
            v110 = *(__int64 **)(v8 + 224);
            if ( v110 )
              goto LABEL_142;
          }
          v61 = 14;
          goto LABEL_214;
        }
        if ( v150[0] != 6 )
        {
          if ( v150[0] != 58 )
            goto LABEL_63;
          v31 = v30[1];
          v32 = v30[2];
          v34 = v30 + 3;
          v24 = v30[3];
          v33 = v34[1];
          v155 = v31;
          v156 = v32;
          v27 = 6;
          v157 = v24;
          v158 = v33;
LABEL_39:
          LOBYTE(v159) = v27;
          lock = _rcu_read_lock(unlock);
          for ( i = (__int64 *)rmnet_wlan_connection_hash[(unsigned int)(1640531527 * v24) >> 28]; i; i = (__int64 *)*i )
          {
            if ( (i[11] & 1) == 0 )
            {
              v37 = *((unsigned __int8 *)i + 64);
              if ( v37 == (unsigned __int8)v159 )
              {
                if ( v37 == 4 )
                {
                  if ( *((_DWORD *)i + 8) == (_DWORD)v155 && *((_DWORD *)i + 12) == (_DWORD)v157 )
                    goto LABEL_50;
                }
                else
                {
                  lock = ipv6_addr_cmp((unsigned __int64 *)i + 4, &v155);
                  if ( !(_DWORD)lock )
                  {
                    lock = ipv6_addr_cmp((unsigned __int64 *)i + 6, &v157);
                    if ( !(_DWORD)lock )
                    {
LABEL_50:
                      i[10] = jiffies;
                      unlock = _rcu_read_unlock(lock);
                      goto LABEL_63;
                    }
                  }
                }
              }
            }
          }
          _rcu_read_unlock(lock);
          v38 = raw_spin_lock_irqsave(&rmnet_wlan_connection_lock);
          v39 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 2336, 96);
          if ( v39 )
          {
            v40 = v157;
            v41 = v158;
            v42 = 1640531527 * v157;
            *(_QWORD *)(v39 + 72) = v18 + 72;
            v43 = v159;
            *(_QWORD *)(v39 + 48) = v40;
            *(_QWORD *)(v39 + 56) = v41;
            v45 = v155;
            v44 = v156;
            *(_DWORD *)(v39 + 64) = v43;
            *(_QWORD *)(v39 + 32) = v45;
            *(_QWORD *)(v39 + 40) = v44;
            v46 = &rmnet_wlan_connection_hash[v42 >> 28];
            v47 = *v46;
            *(_QWORD *)v39 = *v46;
            *(_QWORD *)(v39 + 8) = v46;
            atomic_store(v39, v46);
            if ( v47 )
              *(_QWORD *)(v47 + 8) = v39;
            v48 = rmnet_wlan_connection_hash_size;
            if ( !rmnet_wlan_connection_hash_size )
            {
              queue_delayed_work_on(32, system_wq, &rmnet_wlan_connection_work, 125);
              v48 = rmnet_wlan_connection_hash_size;
            }
            rmnet_wlan_connection_hash_size = v48 + 1;
          }
          unlock = raw_spin_unlock_irqrestore(&rmnet_wlan_connection_lock, v38);
          goto LABEL_63;
        }
      }
      else
      {
        if ( v21 != 8 )
          goto LABEL_63;
        v22 = *(_DWORD *)(v8 + 112);
        v23 = *(_DWORD *)(v8 + 116);
        LODWORD(v162) = 0;
        v160 = 0;
        v161 = 0;
        if ( v22 - v23 <= 19 )
        {
          v24 = (unsigned __int64)&v160;
          unlock = skb_copy_bits(v8, 0, &v160, 20);
          if ( (unlock & 0x80000000) != 0 )
            goto LABEL_63;
        }
        else
        {
          v24 = *(_QWORD *)(v8 + 224);
          if ( !v24 )
            goto LABEL_63;
        }
        v25 = *(unsigned __int8 *)(v24 + 9);
        if ( v25 != 6 )
        {
          if ( v25 != 1 )
            goto LABEL_63;
          v26 = *(_DWORD *)(v24 + 12);
          LODWORD(v24) = *(_DWORD *)(v24 + 16);
          LODWORD(v155) = v26;
          v27 = 4;
          LODWORD(v157) = v24;
          goto LABEL_39;
        }
      }
      unlock = rmnet_wlan_tcp_mss_clamp(v8, 512);
      goto LABEL_63;
    }
LABEL_62:
    v19 = 255;
    goto LABEL_63;
  }
  v4 = rmnet_wwan_get_dev(unlock);
  v5 = rmnet_wlan_strlcmp(v1 + 296, v4, 16);
  if ( (_DWORD)v5 )
  {
    v6 = rmnet_wlan_get_dev(v5);
    if ( (unsigned int)rmnet_wlan_strlcmp(v1 + 296, v6, 16) )
    {
LABEL_10:
      result = 3;
      goto LABEL_11;
    }
  }
  result = rmnet_wlan_rx_handler(a1);
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
