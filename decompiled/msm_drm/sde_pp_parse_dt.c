__int64 __fastcall sde_pp_parse_dt(__int64 a1, __int64 a2)
{
  _DWORD *v4; // x20
  unsigned int v5; // w27
  __int64 dt_entry; // x0
  __int64 v7; // x1
  __int64 v8; // x24
  __int64 v9; // x28
  int *v10; // x25
  unsigned int v11; // w26
  __int64 v12; // x22
  unsigned __int64 v16; // x9
  __int64 v17; // x27
  unsigned __int64 v18; // x21
  int v19; // w8
  int v20; // w10
  int v21; // w9
  int v22; // w8
  int v23; // w3
  _DWORD *v24; // x8
  int v25; // w8
  int v26; // w8
  int v27; // w8
  int v28; // w8
  int v29; // w3
  int v30; // w9
  unsigned __int64 v33; // x9
  unsigned __int64 v36; // x9
  unsigned __int64 v39; // x10
  unsigned __int64 v42; // x9
  unsigned __int64 v45; // x9
  unsigned __int64 v52; // x9
  unsigned __int64 v55; // x9
  unsigned __int64 v58; // x9
  unsigned __int64 v61; // x9
  unsigned __int64 v64; // x9
  unsigned int v65; // [xsp+Ch] [xbp-54h] BYREF
  _QWORD v66[2]; // [xsp+10h] [xbp-50h] BYREF
  _QWORD v67[6]; // [xsp+20h] [xbp-40h] BYREF
  int v68; // [xsp+50h] [xbp-10h]
  __int64 v69; // [xsp+58h] [xbp-8h]

  v69 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v68 = 0;
  memset(v67, 0, sizeof(v67));
  *(_QWORD *)((char *)v66 + 5) = 0;
  v66[0] = 0;
  v65 = 0;
  v4 = (_DWORD *)_kvmalloc_node_noprof(9984, 0, 3520, 0xFFFFFFFFLL);
  if ( !v4 )
  {
LABEL_7:
    v5 = -12;
    goto LABEL_8;
  }
  v5 = validate_dt_entry(a1, &pp_prop, 13, v67, &v65);
  if ( v5 )
    goto LABEL_8;
  *(_DWORD *)(a2 + 9616) = v65;
  dt_entry = read_dt_entry(a1, &pp_prop, 13, v67, v66, v4);
  v5 = dt_entry;
  if ( (_DWORD)dt_entry )
    goto LABEL_8;
  if ( !v65 )
  {
    v5 = 0;
LABEL_8:
    kvfree(v4);
    _ReadStatusReg(SP_EL0);
    return v5;
  }
  v8 = 0;
  v9 = 0;
  v10 = (int *)(a2 + 19892);
  v11 = *(_DWORD *)a2 >> 28;
  v12 = a2 + 9624;
  _ReadStatusReg(SP_EL0);
  while ( v8 != 13 )
  {
    v17 = _kvmalloc_node_noprof(144, 0, 3520, 0xFFFFFFFFLL);
    if ( !v17 )
      goto LABEL_7;
    v18 = v9 + 1;
    v19 = v4[v8];
    *(_QWORD *)(v12 + 48) = v17;
    *(_DWORD *)(v12 + 16) = v9 + 1;
    *(_DWORD *)(v12 + 20) = v19;
    snprintf((char *)v12, 0x10u, "pingpong_%u", v9);
    v20 = *(_DWORD *)(v12 + 16);
    v21 = v4[v8 + 576];
    *(_DWORD *)(v12 + 24) = v4[192];
    *(_DWORD *)(v17 + 16) = 1;
    *(_DWORD *)(v17 + 20) = v21;
    dt_entry = snprintf((char *)v17, 0x10u, "te_%u", v20 - 1);
    if ( v11 <= 4 )
    {
      _X8 = (unsigned __int64 *)(v12 + 32);
      __asm { PRFM            #0x11, [X8] }
      do
        v52 = __ldxr(_X8);
      while ( __stxr(v52 | 2, _X8) );
    }
    v22 = v4[v8 + 960];
    *(_DWORD *)(v17 + 56) = v22;
    if ( v22 )
    {
      v23 = *(_DWORD *)(v12 + 16) - 1;
      *(_DWORD *)(v17 + 52) = 2;
      dt_entry = snprintf((char *)(v17 + 36), 0x10u, "te2_%u", v23);
      _X8 = (unsigned __int64 *)(v12 + 32);
      __asm { PRFM            #0x11, [X8] }
      do
        v33 = __ldxr(_X8);
      while ( __stxr(v33 | 4, _X8) );
      _X8 = (unsigned __int64 *)(v12 + 32);
      __asm { PRFM            #0x11, [X8] }
      do
        v36 = __ldxr(_X8);
      while ( __stxr(v36 | 8, _X8) );
    }
    v24 = &v4[v8];
    if ( v4[v8 + 1344] )
    {
      _X9 = (unsigned __int64 *)(v12 + 32);
      __asm { PRFM            #0x11, [X9] }
      do
        v39 = __ldxr(_X9);
      while ( __stxr(v39 | 0x10, _X9) );
      if ( !v24[384] )
        goto LABEL_22;
    }
    else if ( !v24[384] )
    {
      goto LABEL_22;
    }
    _X8 = (unsigned __int64 *)(v12 + 32);
    __asm { PRFM            #0x11, [X8] }
    do
      v42 = __ldxr(_X8);
    while ( __stxr(v42 | 0x200, _X8) );
    if ( (*(_QWORD *)(a2 + 22008) & 0x40) != 0 )
      ++*v10;
LABEL_22:
    v25 = *v10;
    if ( !*v10 )
      v25 = 5;
    *(_DWORD *)(v12 + 60) = v25;
    if ( v11 <= 6 )
    {
      v26 = v4[v8];
      *(_DWORD *)(v17 + 92) = v26;
      if ( v26 )
      {
        v27 = *(_DWORD *)(v12 + 16);
        *(_DWORD *)(v17 + 88) = 5;
        dt_entry = snprintf((char *)(v17 + 72), 0x10u, "dsc_%u", v27 - 1);
        _X8 = (unsigned __int64 *)(v12 + 32);
        __asm { PRFM            #0x11, [X8] }
        do
          v61 = __ldxr(_X8);
        while ( __stxr(v61 | 0x20, _X8) );
      }
    }
    if ( *(_DWORD *)(a2 + 22144) == 2 )
    {
      _X8 = (unsigned __int64 *)(v12 + 32);
      __asm { PRFM            #0x11, [X8] }
      do
        v55 = __ldxr(_X8);
      while ( __stxr(v55 | 0x800, _X8) );
    }
    v28 = v4[v8 + 1536];
    *(_DWORD *)(v17 + 128) = v28;
    if ( v28 )
    {
      v29 = *(_DWORD *)(v12 + 16);
      *(_DWORD *)(v17 + 124) = 6;
      dt_entry = snprintf((char *)(v17 + 108), 0x10u, "dither_%u", v29);
      _X8 = (unsigned __int64 *)(v12 + 32);
      __asm { PRFM            #0x11, [X8] }
      do
        v45 = __ldxr(_X8);
      while ( __stxr(v45 | 0x40, _X8) );
    }
    v30 = v4[1920];
    *(_DWORD *)(v17 + 132) = v4[1728];
    *(_DWORD *)(v17 + 140) = v30;
    if ( (*(_QWORD *)(a2 + 22008) & 0x20) != 0 && v4[v8 + 2112] )
    {
      _X8 = (unsigned __int64 *)(v12 + 32);
      __asm { PRFM            #0x11, [X8] }
      do
        v64 = __ldxr(_X8);
      while ( __stxr(v64 | 0x400, _X8) );
      if ( (*(_QWORD *)(a2 + 22008) & 0x40000000) == 0 )
        goto LABEL_35;
LABEL_34:
      _X8 = (unsigned __int64 *)(v12 + 32);
      __asm { PRFM            #0x11, [X8] }
      do
        v58 = __ldxr(_X8);
      while ( __stxr(v58 | 0x80, _X8) );
      goto LABEL_35;
    }
    if ( (*(_QWORD *)(a2 + 22008) & 0x40000000) != 0 )
      goto LABEL_34;
LABEL_35:
    if ( BYTE4(v66[1]) == 1 )
    {
      _X8 = (unsigned __int64 *)(v12 + 32);
      __asm { PRFM            #0x11, [X8] }
      do
        v16 = __ldxr(_X8);
      while ( __stxr(v16 | 0x100, _X8) );
      *(_DWORD *)(v12 + 56) = v4[v8 + 2304] + 1;
    }
    v5 = 0;
    ++v8;
    v12 += 64;
    ++v9;
    if ( v18 >= v65 )
      goto LABEL_8;
  }
  __break(0x5512u);
  return sde_mixer_parse_dt(dt_entry, v7);
}
