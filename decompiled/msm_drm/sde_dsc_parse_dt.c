__int64 __fastcall sde_dsc_parse_dt(__int64 a1, __int64 a2)
{
  _DWORD *v4; // x20
  __int64 v5; // x0
  char *v6; // x1
  __int64 v7; // x1
  int v8; // w8
  unsigned int v9; // w9
  __int64 v10; // x22
  __int64 v11; // x25
  __int64 v12; // x26
  __int64 v13; // x27
  __int64 v14; // x28
  __int64 result; // x0
  unsigned __int64 v18; // x9
  _DWORD *v19; // x23
  int v20; // w8
  __int64 v21; // x24
  unsigned __int64 v22; // x21
  int v23; // w9
  unsigned __int64 v24; // x8
  unsigned __int64 v25; // x9
  __int64 v26; // x8
  int v27; // w10
  int v28; // w9
  int v29; // w8
  unsigned __int64 v32; // x10
  unsigned __int64 v39; // x9
  unsigned __int64 v42; // x9
  unsigned __int64 v45; // x9
  unsigned __int64 v48; // x9
  unsigned __int64 v51; // x9
  unsigned __int64 v54; // x9
  unsigned int v55; // w19
  _BOOL4 v56; // [xsp+Ch] [xbp-64h]
  _DWORD *v57; // [xsp+10h] [xbp-60h]
  char *s1; // [xsp+18h] [xbp-58h] BYREF
  unsigned int v59; // [xsp+24h] [xbp-4Ch] BYREF
  __int64 v60; // [xsp+28h] [xbp-48h] BYREF
  __int16 v61; // [xsp+30h] [xbp-40h]
  _QWORD v62[7]; // [xsp+38h] [xbp-38h] BYREF

  v62[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v62, 0, 48);
  v61 = 0;
  v60 = 0;
  v59 = 0;
  s1 = nullptr;
  v4 = (_DWORD *)_kvmalloc_node_noprof(7680, 0, 3520, 0xFFFFFFFFLL);
  if ( !v4 )
  {
    result = 4294967284LL;
LABEL_54:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  LODWORD(v5) = validate_dt_entry(a1, &dsc_prop, 10, v62, &v59);
  if ( (_DWORD)v5
    || ((v6 = off_ADE8, *(_DWORD *)(a2 + 10392) = v59, !(unsigned int)of_property_read_string(a1, v6, &s1))
      ? (v56 = strcmp(s1, "dsc_1_2") == 0)
      : (v56 = 0),
        v5 = read_dt_entry(a1, &dsc_prop, 10, v62, &v60, v4),
        (_DWORD)v5) )
  {
LABEL_53:
    v55 = v5;
    kvfree(v4);
    result = v55;
    goto LABEL_54;
  }
  if ( HIBYTE(v61) == 1 )
    v8 = v4[1728];
  else
    v8 = 2048;
  v9 = v59;
  *(_DWORD *)(a2 + 21572) = v8;
  if ( !v9 )
  {
    LODWORD(v5) = 0;
    goto LABEL_53;
  }
  v10 = 0;
  v11 = -832;
  v12 = 10400;
  v13 = 10432;
  v14 = 10448;
  _ReadStatusReg(SP_EL0);
  v57 = v4;
  while ( v11 )
  {
    v19 = (_DWORD *)_kvmalloc_node_noprof(56, 0, 3520, 0xFFFFFFFFLL);
    if ( !v19 )
    {
      LODWORD(v5) = -12;
LABEL_52:
      v4 = v57;
      goto LABEL_53;
    }
    v20 = *v4;
    v21 = a2 + v11;
    v22 = v10 + 1;
    v23 = v57[192];
    *(_QWORD *)(v21 + 11288) = v19;
    *(_DWORD *)(v21 + 11248) = v10 + 1;
    *(_DWORD *)(v21 + 11252) = v20;
    *(_DWORD *)(v21 + 11256) = v23;
    v5 = snprintf((char *)(a2 + v12), 0x10u, "dsc_%u", v10);
    if ( (v60 & 0x100) == 0 )
      *(_DWORD *)(v21 + 11256) = 256;
    if ( *(_DWORD *)(a2 + 28) == 256 )
    {
      _X8 = (unsigned __int64 *)(a2 + v13);
      __asm { PRFM            #0x11, [X8] }
      do
        v39 = __ldxr(_X8);
      while ( __stxr(v39 | 2, _X8) );
      v24 = (unsigned int)v4[384];
      if ( !(_DWORD)v24 )
        goto LABEL_24;
LABEL_23:
      v25 = v24 >> 3;
      v26 = 1LL << v24;
      _X9 = (unsigned __int64 *)(a2 + v14 + (v25 & 0x1FFFFFF8));
      __asm { PRFM            #0x11, [X9] }
      do
        v32 = __ldxr(_X9);
      while ( __stxr(v32 | v26, _X9) );
      goto LABEL_24;
    }
    v24 = (unsigned int)v4[384];
    if ( (_DWORD)v24 )
      goto LABEL_23;
LABEL_24:
    if ( v56 )
    {
      v27 = v4[1152];
      v28 = v57[960];
      v19[5] = v4[768];
      v19[6] = v28;
      v29 = v57[1344];
      v19[12] = v27;
      v19[13] = v29;
      _X8 = (unsigned __int64 *)(a2 + v13);
      __asm { PRFM            #0x11, [X8] }
      do
        v42 = __ldxr(_X8);
      while ( __stxr(v42 | 8, _X8) );
      if ( v4[1536] )
      {
        _X8 = (unsigned __int64 *)(a2 + v13);
        __asm { PRFM            #0x11, [X8] }
        do
          v45 = __ldxr(_X8);
        while ( __stxr(v45 | 0x10, _X8) );
      }
      if ( *(_DWORD *)a2 >> 28 >= 9u )
      {
        _X8 = (unsigned __int64 *)(a2 + v13);
        __asm { PRFM            #0x11, [X8] }
        do
          v48 = __ldxr(_X8);
        while ( __stxr(v48 | 0x100, _X8) );
        if ( *(_DWORD *)a2 >> 29 >= 5u )
        {
          _X8 = (unsigned __int64 *)(a2 + v13);
          __asm { PRFM            #0x11, [X8] }
          do
            v54 = __ldxr(_X8);
          while ( __stxr(v54 | 0x200, _X8) );
        }
      }
      if ( *(_BYTE *)(a2 + 36) == 1 )
      {
        _X8 = (unsigned __int64 *)(a2 + v13);
        __asm { PRFM            #0x11, [X8] }
        do
          v51 = __ldxr(_X8);
        while ( __stxr(v51 | 0x20, _X8) );
      }
    }
    else
    {
      _X8 = (unsigned __int64 *)(a2 + v13);
      __asm { PRFM            #0x11, [X8] }
      do
        v18 = __ldxr(_X8);
      while ( __stxr(v18 | 4, _X8) );
    }
    v11 += 64;
    ++v4;
    v12 += 64;
    v13 += 64;
    v14 += 64;
    ++v10;
    if ( v22 >= v59 )
    {
      LODWORD(v5) = 0;
      goto LABEL_52;
    }
  }
  __break(0x5512u);
  return sde_vdc_parse_dt(v5, v7);
}
