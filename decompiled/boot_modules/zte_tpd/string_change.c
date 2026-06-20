_BYTE *__fastcall string_change(__int64 a1, char *s, _DWORD *a3)
{
  size_t v5; // x22
  char *v6; // x0
  const char *v7; // x20
  size_t v8; // x22
  _BYTE *v9; // x21
  char *v10; // x0
  char *v11; // x8
  char *v12; // x23
  int v13; // w24
  char v14; // w28
  int v15; // w25
  int v16; // w26
  char v17; // w0
  __int64 v18; // x8
  bool v19; // zf
  int v20; // w26
  int v21; // w23
  const char *v22; // x0
  _BOOL4 v23; // w8
  char *v24; // x27
  __int64 v25; // x8
  char *v26; // x0
  char *v27; // x25
  __int64 v28; // x26
  char v29; // w0
  __int64 v30; // x8
  char *v31; // x0
  __int64 v32; // x27
  char *v33; // x0
  __int64 v34; // x25
  char *v35; // x0
  __int64 v36; // x26
  char *v37; // x0
  __int16 v38; // w25
  __int16 v39; // w26
  int v40; // w8
  char v41; // w15
  __int16 v42; // kr00_2
  __int16 v43; // kr02_2
  __int16 v44; // w16
  __int16 v45; // kr06_2
  char v46; // w14
  char v47; // w15
  int v48; // w17
  int v49; // w16
  int v50; // w15
  int v51; // w14
  int v52; // w13
  int v53; // w12
  int v54; // w11
  unsigned __int64 StatusReg; // x20
  __int64 v56; // x22
  void *(*v57)(void *, int, size_t); // x0
  __int16 v59; // [xsp+8h] [xbp-48h]
  __int16 v60; // [xsp+10h] [xbp-40h]
  __int64 v61; // [xsp+18h] [xbp-38h]
  _BOOL4 v63; // [xsp+2Ch] [xbp-24h]
  char *v64; // [xsp+30h] [xbp-20h] BYREF
  char *v65; // [xsp+38h] [xbp-18h] BYREF
  char *stringp[2]; // [xsp+40h] [xbp-10h] BYREF

  stringp[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !s || !*s )
  {
    v9 = (_BYTE *)_kmalloc_cache_noprof(memset, 3264, 1);
    if ( !v9 )
      goto LABEL_77;
    goto LABEL_21;
  }
  v5 = strlen(s);
  v6 = (char *)_kmalloc_noprof(v5 + 1, 3264);
  v7 = v6;
  if ( !v6 )
  {
    v9 = nullptr;
    goto LABEL_77;
  }
  memcpy(v6, s, v5 + 1);
  v8 = 3 * strlen(s);
  v9 = (_BYTE *)_kmalloc_noprof(v8, 3264);
  if ( !v9 )
  {
    kfree(v7);
    goto LABEL_77;
  }
  v10 = strchr(v7, 58);
  v11 = (char *)v7;
  if ( v10 )
    v12 = v10 + 1;
  else
    v12 = nullptr;
  v65 = v12;
  stringp[0] = (char *)v7;
  if ( v10 )
  {
    *v10 = 0;
    v11 = stringp[0];
    if ( !stringp[0] )
    {
      v15 = 0;
      v14 = 0;
      v63 = 0;
      v12 = v10 + 1;
      if ( v10 == (char *)-1LL )
        goto LABEL_71;
      goto LABEL_27;
    }
  }
  if ( !*v11 || !strsep(stringp, ",") )
  {
    v15 = 0;
    v14 = 0;
    v63 = 0;
    if ( !v12 )
      goto LABEL_71;
    goto LABEL_27;
  }
  v13 = 0;
  v14 = 0;
  v15 = 0;
  v16 = 1;
  do
  {
    if ( *(_BYTE *)((__int64 (*)(void))trim)() )
    {
      v17 = ((__int64 (*)(void))simple_strtoul)();
      if ( v15 < 0 || (v18 = v15, v8 <= v15) )
      {
LABEL_73:
        __break(1u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v56 = *(_QWORD *)(StatusReg + 80);
        v57 = memset;
        *(_QWORD *)(StatusReg + 80) = &string_change__alloc_tag;
        v9 = (_BYTE *)_kmalloc_cache_noprof(v57, 3264, 1);
        *(_QWORD *)(StatusReg + 80) = v56;
        if ( !v9 )
        {
LABEL_77:
          *a3 = 0;
          goto LABEL_78;
        }
LABEL_21:
        *v9 = 0;
        goto LABEL_77;
      }
      v19 = v16 == 0;
      ++v15;
      v16 = 0;
      if ( !v19 )
      {
        v14 = v17;
        v13 = 1;
      }
      v9[v18] = v17;
    }
  }
  while ( strsep(stringp, ",") );
  v12 = v65;
  v63 = v13 != 0;
  if ( v65 )
  {
LABEL_27:
    if ( !*v12 || !strsep(&v65, ".") )
      goto LABEL_71;
    v20 = 1;
    v21 = v15;
    while ( 1 )
    {
      v22 = (const char *)((__int64 (*)(void))trim)();
      if ( !*v22 )
        goto LABEL_31;
      v23 = v63;
      v24 = (char *)v22;
      if ( v20 )
        v23 = 0;
      if ( v23 )
      {
        if ( v21 < 0 )
          goto LABEL_73;
        v25 = v21;
        if ( v8 <= v21 )
          goto LABEL_73;
        ++v21;
        v9[v25] = v14;
      }
      v26 = strchr(v22, 58);
      if ( v26 )
      {
        *v26 = 0;
        v27 = v26 + 1;
        v28 = trim(v24);
        v24 = (char *)trim(v27);
        if ( v28 )
        {
          v29 = simple_strtoul(v28, 0, 16);
          if ( v21 < 0 )
            goto LABEL_73;
          v30 = v21;
          if ( v8 <= v21 )
            goto LABEL_73;
          ++v21;
          v9[v30] = v29;
        }
      }
      v64 = v24;
      v31 = strsep(&v64, ",");
      if ( v31 )
      {
        v32 = trim(v31);
        v33 = strsep(&v64, ",");
        if ( v33 )
        {
          v34 = trim(v33);
          v35 = strsep(&v64, ",");
          if ( v35 )
          {
            v36 = trim(v35);
            v37 = strsep(&v64, ",");
            if ( v37 )
              break;
          }
        }
      }
LABEL_30:
      v20 = 0;
LABEL_31:
      if ( !strsep(&v65, ".") )
        goto LABEL_72;
    }
    v61 = trim(v37);
    v60 = simple_strtoul(v32, 0, 10);
    v59 = simple_strtoul(v34, 0, 10);
    v38 = simple_strtoul(v36, 0, 10);
    v39 = simple_strtoul(v61, 0, 10);
    printk(&unk_33FD8, "change_coordinate", *(unsigned int *)(a1 + 1544));
    v40 = *(_DWORD *)(a1 + 1544);
    if ( v40 == 3 )
    {
      v41 = 5 * v59;
      v45 = 10 * (2688 - v38) - 1;
      v44 = 10 * v59;
      v42 = (10 * (2688 - v60)) | 1;
      v43 = 10 * v39 - 1;
    }
    else
    {
      if ( v40 != 1 )
      {
        v46 = 0;
        v47 = 0;
        v42 = 0;
        v43 = 0;
        v45 = 0;
LABEL_54:
        if ( v21 < 0 )
          goto LABEL_73;
        if ( v8 <= v21 )
          goto LABEL_73;
        v48 = v21 + 1;
        v9[v21] = v46;
        if ( v21 + 1 < 0 )
          goto LABEL_73;
        if ( v8 <= v48 )
          goto LABEL_73;
        v49 = v21 + 2;
        v9[v48] = v47;
        if ( v21 + 2 < 0 )
          goto LABEL_73;
        if ( v8 <= v49 )
          goto LABEL_73;
        v50 = v21 + 3;
        v9[v49] = v45;
        if ( v21 + 3 < 0 )
          goto LABEL_73;
        if ( v8 <= v50 )
          goto LABEL_73;
        v51 = v21 + 4;
        v9[v50] = HIBYTE(v45);
        if ( v21 + 4 < 0 )
          goto LABEL_73;
        if ( v8 <= v51 )
          goto LABEL_73;
        v52 = v21 + 5;
        v9[v51] = v43;
        if ( v21 + 5 < 0 )
          goto LABEL_73;
        if ( v8 <= v52 )
          goto LABEL_73;
        v53 = v21 + 6;
        v9[v52] = HIBYTE(v43);
        if ( v21 + 6 < 0 )
          goto LABEL_73;
        if ( v8 <= v53 )
          goto LABEL_73;
        v54 = v21 + 7;
        v9[v53] = v42;
        if ( v21 + 7 < 0 || v8 <= v54 )
          goto LABEL_73;
        v21 += 8;
        v9[v54] = HIBYTE(v42);
        goto LABEL_30;
      }
      v41 = 5 * (-64 - v39);
      v42 = 10 * v38 - 1;
      v43 = 10 * (1216 - v59) - 1;
      v44 = 10 * (1216 - v39);
      v45 = (10 * v60) | 1;
    }
    v46 = (2 * v41) | 1;
    v47 = HIBYTE(v44);
    goto LABEL_54;
  }
LABEL_71:
  v21 = v15;
LABEL_72:
  kfree(v7);
  *a3 = v21;
LABEL_78:
  _ReadStatusReg(SP_EL0);
  return v9;
}
