__int64 __fastcall cfg80211_beacon_dup(char *a1)
{
  char *v1; // x23
  _BYTE *v2; // x11
  int v3; // w8
  __int64 v4; // x12
  _BYTE *v5; // x9
  __int64 v6; // x13
  int v7; // w10
  int v8; // w10
  int v9; // w14
  int *v10; // x15
  __int64 v11; // x16
  int v12; // w17
  int v13; // t1
  _BYTE *v14; // x14
  __int64 v15; // x11
  int *v16; // x12
  int v17; // t1
  __int64 v18; // x11
  __int64 v19; // x12
  int v20; // w13
  int *v21; // x14
  __int64 v22; // x15
  int v23; // w16
  int v24; // t1
  _BYTE *v25; // x13
  __int64 v26; // x9
  int *v27; // x11
  int v28; // t1
  unsigned __int64 v29; // x21
  char *v30; // x0
  char *v31; // x26
  _BYTE *v32; // x8
  _BYTE *v33; // x8
  __int64 v34; // x8
  char *v35; // x22
  size_t v36; // x2
  size_t v37; // x1
  __int64 v38; // x8
  unsigned __int64 v39; // x24
  __int64 v40; // x8
  __int64 v41; // x8
  __int64 v42; // x8
  __int64 v43; // x8
  __int64 v44; // x8
  _BYTE *v45; // x25
  size_t v46; // x2
  size_t v47; // x1
  __int64 v48; // x8
  size_t v49; // x2
  size_t v50; // x1
  __int64 v51; // x8
  size_t v52; // x2
  size_t v53; // x1
  __int64 v54; // x8
  size_t v55; // x2
  size_t v56; // x1
  __int64 v57; // x8
  size_t v58; // x2
  size_t v59; // x1
  __int64 v60; // x8
  _BYTE *v61; // x26
  __int64 v62; // x27
  unsigned __int64 v63; // x28
  int v64; // w8
  __int64 v65; // x20
  const void **v66; // x19
  size_t v67; // x2
  unsigned __int64 v68; // x8
  bool v69; // cf
  unsigned __int64 v70; // x8
  size_t v71; // x1
  const void *v72; // x8
  _BYTE *v73; // x9
  unsigned __int64 v74; // x9
  _BYTE *v75; // x25
  _BYTE *v76; // x26
  __int64 v77; // x27
  unsigned __int64 v78; // x28
  int v79; // w8
  __int64 v80; // x20
  const void **v81; // x19
  size_t v82; // x2
  unsigned __int64 v83; // x8
  unsigned __int64 v84; // x8
  size_t v85; // x1
  const void *v86; // x8
  _BYTE *v87; // x9
  unsigned __int64 v88; // x9
  __int64 v89; // x9
  size_t v90; // x2
  size_t v91; // x1
  __int64 v92; // x8
  size_t v93; // x2
  size_t v94; // x1
  int v96; // w8
  unsigned __int64 StatusReg; // x19
  __int64 v98; // x20
  char *v99; // [xsp+0h] [xbp-10h]
  char *v100; // [xsp+8h] [xbp-8h]

  v1 = a1;
  v2 = *((_BYTE **)a1 + 9);
  v3 = *((_DWORD *)a1 + 26)
     + *((_DWORD *)a1 + 24)
     + *((_DWORD *)a1 + 28)
     + *((_DWORD *)a1 + 30)
     + *((_DWORD *)a1 + 32)
     + *((_DWORD *)a1 + 34)
     + *((_DWORD *)a1 + 36)
     + *((_DWORD *)a1 + 38);
  if ( v2 )
  {
    v4 = (unsigned __int8)*v2;
    if ( !*v2 )
    {
      v7 = 0;
      goto LABEL_20;
    }
    v5 = *((_BYTE **)a1 + 10);
    if ( (_DWORD)v4 == 1 )
    {
      v6 = 0;
      v7 = 0;
    }
    else
    {
      v6 = (unsigned __int8)v4 & 0xFE;
      v8 = 0;
      v9 = 0;
      v10 = (int *)(v2 + 32);
      v11 = v6;
      do
      {
        v12 = *(v10 - 4);
        v13 = *v10;
        v10 += 8;
        v11 -= 2;
        v8 += v12;
        v9 += v13;
      }
      while ( v11 );
      v7 = v9 + v8;
      if ( v6 == v4 )
        goto LABEL_11;
    }
    v14 = &v2[16 * v6];
    v15 = v4 - v6;
    v16 = (int *)(v14 + 16);
    do
    {
      v17 = *v16;
      v16 += 4;
      --v15;
      v7 += v17;
    }
    while ( v15 );
LABEL_11:
    if ( !v5 )
      goto LABEL_20;
    v18 = (unsigned __int8)*v5;
    if ( !*v5 )
      goto LABEL_20;
    if ( (_DWORD)v18 == 1 )
    {
      v19 = 0;
    }
    else
    {
      v19 = (unsigned __int8)v18 & 0xFE;
      v20 = 0;
      v21 = (int *)(v5 + 32);
      v22 = v19;
      do
      {
        v23 = *(v21 - 4);
        v24 = *v21;
        v21 += 8;
        v22 -= 2;
        v7 += v23;
        v20 += v24;
      }
      while ( v22 );
      v7 += v20;
      if ( v19 == v18 )
        goto LABEL_20;
    }
    v25 = &v5[16 * v19];
    v26 = v18 - v19;
    v27 = (int *)(v25 + 16);
    do
    {
      v28 = *v27;
      v27 += 4;
      --v26;
      v7 += v28;
    }
    while ( v26 );
LABEL_20:
    v3 += v7;
  }
  v29 = v3 + 176LL;
  v30 = (char *)_kmalloc_noprof(v29, 3520);
  v31 = v30;
  if ( !v30 )
    return (__int64)v31;
  while ( 1 )
  {
    v32 = *((_BYTE **)v1 + 9);
    if ( v32 && *v32 )
    {
      v30 = (char *)_kmalloc_noprof((16LL * **((unsigned __int8 **)v1 + 9)) | 8, 3520);
      if ( v29 < 0x48 || (v29 & 0xFFFFFFFFFFFFFFF8LL) == 0x48 )
        goto LABEL_134;
      *((_QWORD *)v31 + 9) = v30;
      if ( !v30 )
        goto LABEL_130;
      v33 = *((_BYTE **)v1 + 10);
      if ( v33 )
      {
        if ( *v33 )
        {
          v30 = (char *)_kmalloc_noprof((16LL * **((unsigned __int8 **)v1 + 10)) | 8, 3520);
          if ( v29 < 0x50 || (v29 & 0xFFFFFFFFFFFFFFF8LL) == 0x50 )
            goto LABEL_134;
          *((_QWORD *)v31 + 10) = v30;
          if ( !v30 )
            break;
        }
      }
    }
    v34 = *((_QWORD *)v1 + 12);
    v35 = v31 + 176;
    if ( v34 )
    {
      if ( v29 < 0x60 )
        goto LABEL_134;
      if ( (v29 & 0xFFFFFFFFFFFFFFF8LL) == 0x60 )
        goto LABEL_134;
      *((_QWORD *)v31 + 12) = v34;
      if ( (v29 & 0xFFFFFFFFFFFFFFF8LL) == 8 )
        goto LABEL_134;
      v36 = *((_QWORD *)v1 + 12);
      *((_QWORD *)v31 + 1) = v35;
      if ( v29 >= 0xB0 )
        v37 = v29 - 176;
      else
        v37 = 0;
      if ( v37 < v36 )
        goto LABEL_132;
      v30 = (char *)memcpy(v31 + 176, *((const void **)v1 + 1), v36);
      v38 = *((_QWORD *)v1 + 12);
      v39 = v38 + 176;
      v35 += v38;
      v40 = *((_QWORD *)v1 + 13);
      if ( !v40 )
      {
LABEL_41:
        v41 = *((_QWORD *)v1 + 14);
        if ( !v41 )
          goto LABEL_42;
        goto LABEL_56;
      }
    }
    else
    {
      v39 = 176;
      v40 = *((_QWORD *)v1 + 13);
      if ( !v40 )
        goto LABEL_41;
    }
    if ( v29 < 0x68 )
      goto LABEL_134;
    if ( (v29 & 0xFFFFFFFFFFFFFFF8LL) == 0x68 )
      goto LABEL_134;
    *((_QWORD *)v31 + 13) = v40;
    if ( (v29 & 0xFFFFFFFFFFFFFFF8LL) == 0x10 )
      goto LABEL_134;
    v46 = *((_QWORD *)v1 + 13);
    *((_QWORD *)v31 + 2) = v35;
    if ( v29 >= v39 )
      v47 = v29 - v39;
    else
      v47 = 0;
    if ( v47 < v46 )
      goto LABEL_132;
    v30 = (char *)memcpy(v35, *((const void **)v1 + 2), v46);
    v48 = *((_QWORD *)v1 + 13);
    v39 += v48;
    v35 += v48;
    v41 = *((_QWORD *)v1 + 14);
    if ( !v41 )
    {
LABEL_42:
      v42 = *((_QWORD *)v1 + 15);
      if ( !v42 )
        goto LABEL_43;
      goto LABEL_64;
    }
LABEL_56:
    if ( v29 < 0x70 )
      goto LABEL_134;
    if ( (v29 & 0xFFFFFFFFFFFFFFF8LL) == 0x70 )
      goto LABEL_134;
    *((_QWORD *)v31 + 14) = v41;
    if ( (v29 & 0xFFFFFFFFFFFFFFF8LL) == 0x18 )
      goto LABEL_134;
    v49 = *((_QWORD *)v1 + 14);
    *((_QWORD *)v31 + 3) = v35;
    if ( v29 >= v39 )
      v50 = v29 - v39;
    else
      v50 = 0;
    if ( v50 < v49 )
      goto LABEL_132;
    v30 = (char *)memcpy(v35, *((const void **)v1 + 3), v49);
    v51 = *((_QWORD *)v1 + 14);
    v39 += v51;
    v35 += v51;
    v42 = *((_QWORD *)v1 + 15);
    if ( !v42 )
    {
LABEL_43:
      v43 = *((_QWORD *)v1 + 16);
      if ( !v43 )
        goto LABEL_44;
      goto LABEL_72;
    }
LABEL_64:
    if ( v29 < 0x78 )
      goto LABEL_134;
    if ( (v29 & 0xFFFFFFFFFFFFFFF8LL) == 0x78 )
      goto LABEL_134;
    *((_QWORD *)v31 + 15) = v42;
    if ( (v29 & 0xFFFFFFFFFFFFFFF8LL) == 0x20 )
      goto LABEL_134;
    v52 = *((_QWORD *)v1 + 15);
    *((_QWORD *)v31 + 4) = v35;
    if ( v29 >= v39 )
      v53 = v29 - v39;
    else
      v53 = 0;
    if ( v53 < v52 )
      goto LABEL_132;
    v30 = (char *)memcpy(v35, *((const void **)v1 + 4), v52);
    v54 = *((_QWORD *)v1 + 15);
    v39 += v54;
    v35 += v54;
    v43 = *((_QWORD *)v1 + 16);
    if ( !v43 )
    {
LABEL_44:
      v44 = *((_QWORD *)v1 + 17);
      if ( v44 )
        goto LABEL_80;
      goto LABEL_45;
    }
LABEL_72:
    if ( v29 < 0x80 )
      goto LABEL_134;
    if ( (v29 & 0xFFFFFFFFFFFFFFF8LL) == 0x80 )
      goto LABEL_134;
    *((_QWORD *)v31 + 16) = v43;
    if ( (v29 & 0xFFFFFFFFFFFFFFF8LL) == 0x28 )
      goto LABEL_134;
    v55 = *((_QWORD *)v1 + 16);
    *((_QWORD *)v31 + 5) = v35;
    if ( v29 >= v39 )
      v56 = v29 - v39;
    else
      v56 = 0;
    if ( v56 < v55 )
      goto LABEL_132;
    v30 = (char *)memcpy(v35, *((const void **)v1 + 5), v55);
    v57 = *((_QWORD *)v1 + 16);
    v39 += v57;
    v35 += v57;
    v44 = *((_QWORD *)v1 + 17);
    if ( v44 )
    {
LABEL_80:
      if ( v29 < 0x88 )
        goto LABEL_134;
      if ( (v29 & 0xFFFFFFFFFFFFFFF8LL) == 0x88 )
        goto LABEL_134;
      *((_QWORD *)v31 + 17) = v44;
      if ( (v29 & 0xFFFFFFFFFFFFFFF8LL) == 0x30 )
        goto LABEL_134;
      v58 = *((_QWORD *)v1 + 17);
      *((_QWORD *)v31 + 6) = v35;
      if ( v29 >= v39 )
        v59 = v29 - v39;
      else
        v59 = 0;
      if ( v59 < v58 )
        goto LABEL_132;
      v30 = (char *)memcpy(v35, *((const void **)v1 + 6), v58);
      v60 = *((_QWORD *)v1 + 17);
      v39 += v60;
      v35 += v60;
      v45 = *((_BYTE **)v1 + 9);
      if ( !v45 )
        goto LABEL_109;
LABEL_88:
      if ( *v45 )
      {
        v100 = v1;
        if ( v29 < 0x48 || (v29 & 0xFFFFFFFFFFFFFFF8LL) == 0x48 )
          goto LABEL_134;
        v99 = v31;
        v61 = *((_BYTE **)v31 + 9);
        v62 = 0;
        v63 = 0;
        v64 = 0;
        while ( 1 )
        {
          v65 = v64;
          v66 = (const void **)&v45[v62];
          v67 = *(_QWORD *)&v45[v62 + 16];
          v68 = v39 + v64;
          v69 = v29 >= v68;
          v70 = v29 - v68;
          v71 = v69 ? v70 : 0LL;
          if ( v71 < v67 )
            goto LABEL_132;
          v1 = &v35[v65];
          v30 = (char *)memcpy(&v35[v65], v66[1], v67);
          v72 = v66[2];
          v73 = &v61[v62];
          ++v63;
          v62 += 16;
          *((_QWORD *)v73 + 1) = &v35[v65];
          *((_QWORD *)v73 + 2) = v72;
          v64 = v65 + (_DWORD)v72;
          v74 = (unsigned __int8)*v45;
          if ( v63 >= v74 )
          {
            v1 = v100;
            *v61 = v74;
            v75 = *((_BYTE **)v100 + 10);
            v39 += v64;
            v35 += v64;
            if ( !v75 )
            {
LABEL_108:
              v31 = v99;
              goto LABEL_109;
            }
            v31 = v99;
            if ( !*v75 )
              goto LABEL_109;
            if ( v29 >= 0x50 && (v29 & 0xFFFFFFFFFFFFFFF8LL) != 0x50 )
            {
              v76 = *((_BYTE **)v99 + 10);
              v77 = 0;
              v78 = 0;
              v79 = 0;
              while ( 1 )
              {
                v80 = v79;
                v81 = (const void **)&v75[v77];
                v82 = *(_QWORD *)&v75[v77 + 16];
                v83 = v39 + v79;
                v69 = v29 >= v83;
                v84 = v29 - v83;
                v85 = v69 ? v84 : 0LL;
                if ( v85 < v82 )
                  goto LABEL_132;
                v1 = &v35[v80];
                v30 = (char *)memcpy(&v35[v80], v81[1], v82);
                v86 = v81[2];
                v87 = &v76[v77];
                ++v78;
                v77 += 16;
                *((_QWORD *)v87 + 1) = &v35[v80];
                *((_QWORD *)v87 + 2) = v86;
                v79 = v80 + (_DWORD)v86;
                v88 = (unsigned __int8)*v75;
                if ( v78 >= v88 )
                {
                  v1 = v100;
                  *v76 = v88;
                  v39 += v79;
                  v35 += v79;
                  goto LABEL_108;
                }
              }
            }
            goto LABEL_134;
          }
        }
      }
      goto LABEL_109;
    }
LABEL_45:
    v45 = *((_BYTE **)v1 + 9);
    if ( v45 )
      goto LABEL_88;
LABEL_109:
    if ( v29 < 0x59 )
      goto LABEL_134;
    v89 = *((_QWORD *)v1 + 7);
    v31[88] = v1[88];
    if ( v89 )
    {
      if ( v29 < 0x90 )
        goto LABEL_134;
      if ( (v29 & 0xFFFFFFFFFFFFFFF8LL) == 0x90 )
        goto LABEL_134;
      v90 = *((_QWORD *)v1 + 18);
      *((_QWORD *)v31 + 18) = v90;
      if ( (v29 & 0xFFFFFFFFFFFFFFF8LL) == 0x38 )
        goto LABEL_134;
      *((_QWORD *)v31 + 7) = v35;
      if ( v29 >= v39 )
        v91 = v29 - v39;
      else
        v91 = 0;
      if ( v91 < v90 )
        goto LABEL_132;
      v30 = (char *)memcpy(v35, *((const void **)v1 + 7), v90);
      v92 = *((_QWORD *)v1 + 18);
      v39 += v92;
      v35 += v92;
    }
    if ( !*((_QWORD *)v1 + 8) )
      return (__int64)v31;
    if ( v29 < 0x98 )
      goto LABEL_134;
    if ( (v29 & 0xFFFFFFFFFFFFFFF8LL) == 0x98 )
      goto LABEL_134;
    v93 = *((_QWORD *)v1 + 19);
    *((_QWORD *)v31 + 19) = v93;
    if ( (v29 & 0xFFFFFFFFFFFFFFF8LL) == 0x40 )
      goto LABEL_134;
    *((_QWORD *)v31 + 8) = v35;
    if ( v29 >= v39 )
      v94 = v29 - v39;
    else
      v94 = 0;
    if ( v94 >= v93 )
    {
      memcpy(v35, *((const void **)v1 + 8), v93);
      return (__int64)v31;
    }
LABEL_132:
    _fortify_panic(17);
    StatusReg = _ReadStatusReg(SP_EL0);
    v98 = *(_QWORD *)(StatusReg + 80);
    v29 = v96 + 176LL;
    *(_QWORD *)(StatusReg + 80) = &cfg80211_beacon_dup__alloc_tag;
    v30 = (char *)_kmalloc_noprof(v29, 3520);
    v31 = v30;
    *(_QWORD *)(StatusReg + 80) = v98;
    if ( !v30 )
      return (__int64)v31;
  }
  if ( (v29 & 0xFFFFFFFFFFFFFFF8LL) != 0x48 )
  {
    kfree(*((_QWORD *)v31 + 9));
LABEL_130:
    kfree(v31);
    return 0;
  }
LABEL_134:
  __break(1u);
  return cfg80211_get_chandef_type(v30);
}
