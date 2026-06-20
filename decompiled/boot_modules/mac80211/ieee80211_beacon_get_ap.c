__int64 __fastcall ieee80211_beacon_get_ap(
        __int64 a1,
        _DWORD *a2,
        __int64 a3,
        _WORD *a4,
        char a5,
        __int64 a6,
        __int64 a7,
        unsigned __int8 a8)
{
  __int64 v13; // x21
  __int64 v15; // x21
  char v16; // w25
  unsigned __int8 v17; // w19
  __int64 lock; // x0
  _DWORD *v19; // x8
  __int64 v20; // x8
  __int64 v21; // x8
  bool v22; // zf
  int v23; // w11
  __int64 v24; // x8
  __int64 *v25; // x9
  __int64 v26; // x10
  unsigned __int64 v27; // x12
  __int64 v28; // x8
  unsigned __int64 v29; // x14
  char v30; // w9
  int v31; // w13
  __int64 v32; // x11
  unsigned __int64 v33; // x13
  _BYTE *v34; // x10
  __int64 v35; // x25
  __int64 v36; // x9
  __int64 v37; // x19
  _BYTE *v38; // x8
  __int64 v39; // x10
  _BYTE *v40; // x11
  __int64 v41; // x8
  __int64 *v42; // x9
  __int64 v43; // t1
  __int64 v44; // x0
  __int64 v45; // x26
  __int64 v46; // x8
  __int64 v47; // x24
  _WORD *v48; // x22
  __int64 v49; // x9
  size_t v50; // x28
  const void *v51; // x27
  void *v52; // x0
  __int64 v53; // x21
  _WORD *v54; // x28
  _BYTE *v55; // x8
  unsigned int v56; // w9
  _BYTE *v57; // x8
  __int64 v58; // x27
  const void *v59; // x28
  void *v60; // x0
  _BYTE *v61; // x8
  _BYTE *v62; // x8
  const void *v63; // x25
  __int64 v64; // x27
  void *v65; // x0
  unsigned __int8 *v66; // x8
  unsigned __int64 v67; // x28
  __int64 v68; // x21
  unsigned __int8 *v69; // x8
  const void *v70; // x25
  __int64 v71; // x27
  void *v72; // x0
  unsigned int v73; // w25
  const void *v74; // x27
  __int64 v75; // x11
  int v76; // w12
  int v77; // w13
  int *v78; // x14
  __int64 v79; // x15
  int v80; // w16
  int v81; // t1
  __int64 v82; // x9
  int *v83; // x10
  int v84; // t1
  __int64 v85; // x9
  __int64 v86; // x10
  __int64 v87; // x21
  unsigned __int64 v88; // x28
  _BYTE *v89; // x8
  const void *v90; // x25
  __int64 v91; // x27
  void *v92; // x0
  size_t v93; // x28
  void *v94; // x0
  size_t v95; // x2
  __int64 v96; // x8
  int v97; // w10
  int v98; // w0
  __int64 *v99; // x8
  __int64 v100; // x9
  _QWORD *v101; // x10
  int v103; // w11
  int *v104; // x12
  __int64 v105; // x13
  int v106; // w14
  int v107; // t1
  _BYTE *v108; // x11
  __int64 v109; // x8
  int *v110; // x9
  int v111; // t1
  __int64 v112; // [xsp+8h] [xbp-68h]
  char v113; // [xsp+14h] [xbp-5Ch]
  __int64 v114; // [xsp+18h] [xbp-58h]
  __int64 v115; // [xsp+20h] [xbp-50h] BYREF
  __int64 *v116; // [xsp+28h] [xbp-48h] BYREF
  __int64 v117; // [xsp+30h] [xbp-40h]
  __int64 v118; // [xsp+38h] [xbp-38h]
  __int64 v119; // [xsp+40h] [xbp-30h]
  _DWORD *v120; // [xsp+48h] [xbp-28h]
  __int64 v121; // [xsp+50h] [xbp-20h]
  __int64 v122; // [xsp+58h] [xbp-18h]
  __int64 v123; // [xsp+60h] [xbp-10h]
  __int64 v124; // [xsp+68h] [xbp-8h]

  v13 = a1;
  v124 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_WORD *)(a6 + 32) )
    goto LABEL_32;
  if ( (a5 & 1) == 0 )
  {
    v15 = *(unsigned int *)(a3 + 8);
    if ( (unsigned int)v15 < 0xF )
    {
      v16 = a5;
      v17 = a8;
      lock = _rcu_read_lock(a1, a2);
      v19 = &a2[2 * v15];
      v13 = a1;
      v20 = *((_QWORD *)v19 - 19);
      if ( v20 )
      {
        if ( *a2 != 1 )
        {
          if ( *a2 != 3 )
            goto LABEL_12;
          v21 = *(_QWORD *)(v20 + 536);
          if ( !v21 )
            goto LABEL_12;
LABEL_10:
          v22 = --*(_BYTE *)(v21 + 36) == 0;
          if ( v22 )
            __break(0x800u);
          goto LABEL_12;
        }
        v21 = *((_QWORD *)a2 - 285);
        if ( v21 )
          goto LABEL_10;
      }
LABEL_12:
      _rcu_read_unlock(lock);
      a8 = v17;
      a5 = v16;
      goto LABEL_13;
    }
    __break(0x800u);
    v13 = a1;
  }
LABEL_13:
  v23 = *a2;
  v24 = 16;
  if ( *a2 == 1 )
  {
    v25 = (__int64 *)a6;
  }
  else
  {
    v25 = (__int64 *)a6;
    if ( v23 != 7 )
    {
      if ( v23 != 3 )
        goto LABEL_32;
      v25 = (__int64 *)(a6 + 8);
      v24 = 20;
    }
  }
  v26 = *v25;
  v27 = *(int *)(a6 + v24);
  v28 = *(_QWORD *)(a3 + 544);
  v29 = *(unsigned __int16 *)(a6 + 32);
  v30 = *(_BYTE *)(a6 + 36);
  v31 = *(unsigned __int8 *)(*(_QWORD *)(a3 + 944) + 830LL);
  if ( *(_WORD *)(a6 + 32) )
  {
    if ( v29 >= v27 )
      goto LABEL_94;
    *(_BYTE *)(v26 + v29) = v30;
    v23 = *a2;
  }
  v22 = v23 == 3;
  v32 = v28 + 24;
  if ( v22 && v28 )
    *(_BYTE *)(v32 + *(unsigned __int16 *)(v28 + 20)) = v30;
  if ( v31 )
  {
    v33 = *(unsigned __int16 *)(a6 + 34);
    if ( !*(_WORD *)(a6 + 34) )
    {
LABEL_29:
      if ( *a2 == 3 && v28 )
        *(_BYTE *)(v32 + *(unsigned __int16 *)(v28 + 22)) = v30;
      goto LABEL_32;
    }
    if ( v33 < v27 )
    {
      *(_BYTE *)(v26 + v33) = v30;
      goto LABEL_29;
    }
LABEL_94:
    __break(0x800u);
  }
LABEL_32:
  v34 = *(_BYTE **)(a6 + 40);
  v35 = a8;
  v113 = a5;
  if ( !v34 )
  {
    LODWORD(v37) = 0;
    goto LABEL_42;
  }
  v36 = (unsigned __int8)*v34;
  LODWORD(v37) = 0;
  if ( !*v34 || (unsigned int)v36 < a8 )
    goto LABEL_42;
  v38 = *(_BYTE **)(a6 + 48);
  if ( (unsigned int)v36 > a8 )
  {
    v37 = *(_QWORD *)&v34[16 * a8 + 16];
    if ( v38 )
    {
      v39 = (unsigned __int8)*v38;
      v37 += *(_QWORD *)&v38[16 * a8 + 16];
      if ( (unsigned int)v36 < (unsigned int)v39 )
      {
        v40 = &v38[16 * v36];
        v41 = v39 - v36;
        v42 = (__int64 *)(v40 + 16);
        do
        {
          v43 = *v42;
          v42 += 2;
          --v41;
          LODWORD(v37) = v43 + v37;
        }
        while ( v41 );
      }
    }
    goto LABEL_42;
  }
  if ( (unsigned int)v36 < 2 )
  {
    v75 = 0;
    LODWORD(v37) = 0;
LABEL_65:
    v82 = v36 - v75;
    v83 = (int *)&v34[16 * v75 + 16];
    do
    {
      v84 = *v83;
      v83 += 4;
      --v82;
      LODWORD(v37) = v37 + v84;
    }
    while ( v82 );
    goto LABEL_67;
  }
  v75 = (unsigned __int8)v36 & 0xFE;
  v76 = 0;
  v77 = 0;
  v78 = (int *)(v34 + 32);
  v79 = v75;
  do
  {
    v80 = *(v78 - 4);
    v81 = *v78;
    v78 += 8;
    v79 -= 2;
    v76 += v80;
    v77 += v81;
  }
  while ( v79 );
  LODWORD(v37) = v77 + v76;
  if ( v75 != v36 )
    goto LABEL_65;
LABEL_67:
  if ( v38 )
  {
    v85 = (unsigned __int8)*v38;
    if ( *v38 )
    {
      if ( (_DWORD)v85 == 1 )
      {
        v86 = 0;
      }
      else
      {
        v86 = (unsigned __int8)v85 & 0xFE;
        v103 = 0;
        v104 = (int *)(v38 + 32);
        v105 = v86;
        do
        {
          v106 = *(v104 - 4);
          v107 = *v104;
          v104 += 8;
          v105 -= 2;
          LODWORD(v37) = v37 + v106;
          v103 += v107;
        }
        while ( v105 );
        LODWORD(v37) = v103 + v37;
        if ( v86 == v85 )
          goto LABEL_42;
      }
      v108 = &v38[16 * v86];
      v109 = v85 - v86;
      v110 = (int *)(v108 + 16);
      do
      {
        v111 = *v110;
        v110 += 4;
        --v109;
        LODWORD(v37) = v37 + v111;
      }
      while ( v109 );
    }
  }
LABEL_42:
  v44 = _netdev_alloc_skb(
          0,
          (unsigned int)(v37
                       + *(_DWORD *)(v13 + 1508)
                       + *(_DWORD *)(a6 + 16)
                       + *(_DWORD *)(a6 + 20)
                       + *(_DWORD *)(v13 + 108)
                       + 256),
          2080);
  v45 = v44;
  if ( v44 )
  {
    v46 = *(int *)(v13 + 1508);
    v47 = a3;
    v48 = a4;
    v112 = a7;
    v49 = *(_QWORD *)(v44 + 224) + v46;
    v114 = v13;
    LODWORD(v46) = *(_DWORD *)(v44 + 208) + v46;
    *(_QWORD *)(v44 + 224) = v49;
    *(_DWORD *)(v44 + 208) = v46;
    v50 = *(unsigned int *)(a6 + 16);
    v51 = *(const void **)a6;
    v52 = (void *)skb_put(v44, (unsigned int)v50);
    memcpy(v52, v51, v50);
    v53 = *((_QWORD *)a2 - 388);
    if ( *(_BYTE *)(v53 + 1464) == 1 )
    {
      _ieee80211_beacon_add_tim(v47, a2 - 610, v45, v113 & 1);
      v54 = v48;
      if ( v48 )
        goto LABEL_45;
    }
    else
    {
      raw_spin_lock_bh(v53 + 1604);
      _ieee80211_beacon_add_tim(v47, a2 - 610, v45, v113 & 1);
      raw_spin_unlock_bh(v53 + 1604);
      v54 = v48;
      if ( v48 )
      {
LABEL_45:
        *v54 = *(_DWORD *)(a6 + 16);
        v54[1] = *(_DWORD *)(v45 + 112) - *(_DWORD *)(a6 + 16);
        v54[2] = *(_WORD *)(a6 + 32);
        if ( (_DWORD)v37 )
        {
          v55 = *(_BYTE **)(a6 + 40);
          if ( v55 )
          {
            v56 = (unsigned __int8)*v55;
            if ( *v55 )
            {
              if ( v56 >= (unsigned int)v35 )
              {
                if ( v56 > (unsigned int)v35 )
                {
                  v57 = &v55[16 * (unsigned int)v35];
                  v59 = *((const void **)v57 + 1);
                  v58 = *((_QWORD *)v57 + 2);
                  v60 = (void *)skb_put(v45, (unsigned int)v58);
                  memcpy(v60, v59, (unsigned int)v58);
                  v61 = *(_BYTE **)(a6 + 48);
                  if ( v61 )
                  {
                    if ( *v61 )
                    {
                      v62 = &v61[16 * v35];
                      v63 = *((const void **)v62 + 1);
                      v64 = *((_QWORD *)v62 + 2);
                      v65 = (void *)skb_put(v45, (unsigned int)v64);
                      memcpy(v65, v63, (unsigned int)v64);
                      v66 = *(unsigned __int8 **)(a6 + 48);
                      v67 = **(unsigned __int8 **)(a6 + 40);
                      if ( (unsigned int)v67 < *v66 )
                      {
                        v68 = 16 * v67;
                        do
                        {
                          v69 = &v66[v68];
                          v70 = *((const void **)v69 + 1);
                          v71 = *((_QWORD *)v69 + 2);
                          v72 = (void *)skb_put(v45, (unsigned int)v71);
                          memcpy(v72, v70, (unsigned int)v71);
                          v66 = *(unsigned __int8 **)(a6 + 48);
                          ++v67;
                          v68 += 16;
                        }
                        while ( v67 < *v66 );
                      }
                    }
                  }
                }
                else
                {
                  v87 = 0;
                  v88 = 0;
                  do
                  {
                    v89 = &v55[v87];
                    v90 = *((const void **)v89 + 1);
                    v91 = *((_QWORD *)v89 + 2);
                    v92 = (void *)skb_put(v45, (unsigned int)v91);
                    memcpy(v92, v90, (unsigned int)v91);
                    v55 = *(_BYTE **)(a6 + 40);
                    ++v88;
                    v87 += 16;
                  }
                  while ( v88 < (unsigned __int8)*v55 );
                }
              }
            }
          }
          v54 = v48;
          v48[4] = *(_WORD *)(v45 + 112) - v37;
        }
        v73 = *(_DWORD *)(v45 + 112);
        v74 = *(const void **)(a6 + 8);
        if ( v74 )
          goto LABEL_74;
        goto LABEL_75;
      }
    }
    v73 = 0;
    v74 = *(const void **)(a6 + 8);
    if ( v74 )
    {
LABEL_74:
      v93 = *(unsigned int *)(a6 + 20);
      v94 = (void *)skb_put(v45, (unsigned int)v93);
      v95 = v93;
      v54 = v48;
      memcpy(v94, v74, v95);
    }
LABEL_75:
    v120 = nullptr;
    v121 = 0;
    v118 = 0;
    v119 = 0;
    v116 = nullptr;
    v117 = 0;
    v115 = 0;
    v96 = *(_QWORD *)(v47 + 128);
    v122 = v96;
    v123 = 0;
    if ( v96 )
    {
      v97 = *(_DWORD *)(v96 + 40);
      if ( (v97 & 2) == 0 )
      {
        if ( (v97 & 1) != 0 && (*(_WORD *)(v96 + 552) & 0x10) == 0 )
          *(_QWORD *)(v45 + 72) = v96 + 536;
        v119 = v114;
        v120 = a2 - 1180;
        *(_QWORD *)v45 = &v116;
        *(_QWORD *)(v45 + 8) = &v116;
        v117 = v45;
        v116 = (__int64 *)v45;
        LODWORD(v118) = 1;
        v98 = ieee80211_tx_h_encrypt((__int64)&v115);
        v99 = v116;
        if ( v116 == (__int64 *)&v116 )
          v99 = nullptr;
        if ( v99 )
        {
          LODWORD(v118) = v118 - 1;
          v100 = *v99;
          v101 = (_QWORD *)v99[1];
          *v99 = 0;
          v99[1] = 0;
          *(_QWORD *)(v100 + 8) = v101;
          *v101 = v100;
        }
        if ( v99 == (__int64 *)v45 )
        {
          if ( !v98 )
            goto LABEL_86;
        }
        else
        {
          __break(0x800u);
          if ( !v98 )
            goto LABEL_86;
        }
        __break(0x800u);
      }
      consume_skb(v45);
      v45 = 0;
      goto LABEL_87;
    }
LABEL_86:
    ieee80211_beacon_get_finish(v114, a2, v47, v54, a6, v45, v112, v73);
  }
LABEL_87:
  _ReadStatusReg(SP_EL0);
  return v45;
}
