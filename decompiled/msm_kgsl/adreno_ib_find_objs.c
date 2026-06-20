__int64 __fastcall adreno_ib_find_objs(
        __int64 a1,
        __int64 a2,
        unsigned __int64 a3,
        unsigned __int64 a4,
        unsigned int a5,
        __int64 a6,
        unsigned int a7)
{
  unsigned __int64 v10; // x24
  __int64 v14; // x8
  __int64 v15; // x10
  unsigned __int64 v16; // x11
  __int64 result; // x0
  unsigned __int64 v19; // x21
  __int64 v20; // x8
  unsigned __int64 v21; // x9
  unsigned __int64 v22; // x11
  unsigned __int64 v23; // x8
  __int64 v24; // x8
  void (__fastcall *v25)(_QWORD); // x8
  unsigned __int64 v26; // x0
  __int64 v27; // x8
  __int64 v28; // x8
  unsigned int v29; // w8
  unsigned int v31; // w26
  __int64 v32; // x13
  int v33; // w27
  __int64 v34; // x26
  __int64 ib_base; // x4
  unsigned int v36; // w0
  unsigned int v37; // w8
  unsigned int *v38; // x1
  unsigned int v39; // w8
  unsigned int v40; // w9
  unsigned int v41; // w10
  __int64 v42; // x28
  int v43; // w9
  unsigned __int64 v44; // x22
  __int64 v45; // x1
  __int64 i; // x22
  __int64 v47; // x1
  __int64 v48; // x8
  void (__fastcall *v49)(_QWORD); // x8
  unsigned int v50; // w8
  unsigned int v51; // w8
  unsigned int v52; // w8
  unsigned int v53; // w8
  int v59; // w8
  int v61; // w8
  int v63; // w8
  __int64 v64; // [xsp+8h] [xbp-308h]
  __int64 v65; // [xsp+10h] [xbp-300h]
  __int64 v66; // [xsp+18h] [xbp-2F8h]
  unsigned __int64 v67; // [xsp+20h] [xbp-2F0h]
  _DWORD s[182]; // [xsp+28h] [xbp-2E8h] BYREF
  __int64 v69; // [xsp+300h] [xbp-10h]

  v10 = a4;
  v69 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(unsigned int *)(a6 + 8);
  if ( (int)v14 < 1 )
  {
LABEL_8:
    _X0 = kgsl_sharedmem_find(a2, a3);
    if ( !_X0 )
      goto LABEL_87;
    v19 = _X0 + 8;
    if ( _X0 + 8 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_15;
    v20 = 4 * v10;
    if ( 4 * v10 <= 1 )
      v20 = 1;
    if ( __CFADD__(a3, v20)
      || (v21 = *(_QWORD *)(_X0 + 32), v21 > a3)
      || (v22 = v20 + a3, v23 = *(_QWORD *)(_X0 + 48) + v21, v22 > v23) )
    {
LABEL_15:
      if ( _X0 <= 0xFFFFFFFFFFFFF000LL )
      {
        __asm { PRFM            #0x11, [X0] }
        do
          v59 = __ldxr((unsigned int *)_X0);
        while ( __stlxr(v59 - 1, (unsigned int *)_X0) );
        if ( v59 != 1 )
        {
          if ( v59 > 0 )
            goto LABEL_87;
LABEL_92:
          refcount_warn_saturate(_X0, 3);
          goto LABEL_87;
        }
LABEL_17:
        __dmb(9u);
        kgsl_mem_entry_destroy();
      }
LABEL_87:
      result = 4294967274LL;
      goto LABEL_88;
    }
    if ( v23 <= a3 )
      goto LABEL_29;
    v24 = *(_QWORD *)(_X0 + 72);
    v67 = _X0;
    if ( v24 )
    {
      v25 = *(void (__fastcall **)(_QWORD))(v24 + 24);
      if ( v25 )
      {
        v26 = _X0 + 8;
        if ( *((_DWORD *)v25 - 1) != -441828660 )
          __break(0x8228u);
        v25(v26);
        _X0 = v67;
      }
    }
    v27 = *(_QWORD *)(_X0 + 16);
    if ( !v27 || (v28 = v27 + a3 - *(_QWORD *)(_X0 + 32)) == 0 )
    {
LABEL_29:
      __asm { PRFM            #0x11, [X0] }
      do
        v61 = __ldxr((unsigned int *)_X0);
      while ( __stlxr(v61 - 1, (unsigned int *)_X0) );
      if ( v61 != 1 )
      {
        if ( v61 > 0 )
          goto LABEL_87;
        goto LABEL_92;
      }
      goto LABEL_17;
    }
    v66 = v28;
    memset(s, 0, sizeof(s));
    v29 = adreno_ib_add(a2, a3, a5, a6);
    _X0 = v67;
    v31 = v29;
    if ( !v29 )
    {
      v32 = v66;
      if ( v10 )
      {
        v33 = 0;
        do
        {
          v38 = (unsigned int *)(v32 + 4LL * v33);
          v39 = *v38;
          v40 = HIBYTE(*v38);
          if ( *v38 >> 28 == 4 )
          {
            if ( (((0x9669u >> (((v39 >> 20) ^ (v39 >> 12) ^ ((v39 ^ (v39 >> 8) & 0x70000) >> 16) ^ BYTE1(v39)) & 0xF))
                 ^ (v39 >> 27))
                & 1) != 0 )
              break;
            v41 = *v38 & 0x7F;
            if ( (((0x9669u >> (v39 & 0xF ^ ((unsigned __int8)(v39 & 0x7F) >> 4))) ^ (v39 >> 7)) & 1) != 0 )
              break;
          }
          else
          {
            if ( v40 != 112 )
              break;
            if ( (((0x9669u >> ((v39 >> 20) & 7 ^ BYTE2(v39) & 0xF)) ^ (v39 >> 23)) & 1) != 0 )
              break;
            v41 = *v38 & 0x3FFF;
            if ( (((0x9669u >> (((*v38 >> 4) ^ BYTE1(*v38) ^ (v41 >> 12) ^ *v38) & 0xF)) ^ (*v38 >> 15)) & 1) != 0 )
              break;
          }
          v42 = v41;
          if ( v10 < v41 )
            break;
          if ( v40 != 112
            || (((0x9669u >> ((v39 >> 20) & 7 ^ BYTE2(v39) & 0xF)) ^ (v39 >> 23)) & 1) != 0
            || (((0x9669u >> (((v39 >> 4) ^ BYTE1(v39) ^ (v39 >> 12) & 3 ^ v39) & 0xF)) ^ (v39 >> 15)) & 1) != 0 )
          {
            goto LABEL_34;
          }
          if ( (int)v39 > 1891270658 )
          {
            if ( v39 == 1891598339 )
              goto LABEL_31;
            v43 = 1891270659;
          }
          else
          {
            if ( v39 == 1882357763 )
              goto LABEL_31;
            v43 = 1882685443;
          }
          if ( v39 != v43 )
          {
            if ( (v39 & 0x7F0000) != 0x430000 )
              goto LABEL_34;
            v36 = ib_parse_type7_set_draw_state(a1, v38, a2, a6);
            goto LABEL_33;
          }
LABEL_31:
          v34 = *(unsigned int *)(v32 + 4LL * (v33 + 1));
          v65 = *(unsigned int *)(v32 + 4LL * (v33 + 3));
          v64 = *(unsigned int *)(v32 + 4LL * (v33 + 2));
          ib_base = get_ib_base(a1, a7 + 1);
          _X0 = v67;
          if ( ib_base == -22 )
            break;
          v36 = adreno_cp_parse_ibn(a1, a2, v34 | (v64 << 32), v65, ib_base, a6, a7);
LABEL_33:
          v37 = v36;
          v32 = v66;
          _X0 = v67;
          if ( v37 )
          {
            v31 = v37;
            goto LABEL_70;
          }
LABEL_34:
          v10 += ~v42;
          v33 += v42 + 1;
        }
        while ( v10 );
      }
      if ( a5 == 4 )
      {
        v44 = 0;
        do
        {
          if ( v44 > 0xB5 )
          {
LABEL_62:
            __break(1u);
            goto LABEL_63;
          }
          v45 = (unsigned int)s[v44];
          if ( (_DWORD)v45 )
          {
            _X0 = adreno_ib_add(a2, v45, 3, a6);
            if ( (_DWORD)_X0 )
              goto LABEL_69;
            s[v44++] = 0;
            if ( v44 == 182 )
              goto LABEL_62;
            s[v44] = 0;
          }
        }
        while ( v44++ < 0xE );
        for ( i = 0; i != 16; ++i )
        {
          v47 = (unsigned int)s[i + 16];
          if ( (_DWORD)v47 )
          {
            LODWORD(_X0) = adreno_ib_add(a2, v47, 3, a6);
            if ( (_DWORD)_X0 )
              goto LABEL_69;
            s[i + 16] = 0;
          }
        }
        if ( !s[48] || (v50 = adreno_ib_add(a2, s[48], 3, a6), _X0 = v67, (v31 = v50) == 0) )
        {
          v51 = adreno_ib_add(a2, s[49] & 0xFFFFFFE0, 3, a6);
          _X0 = v67;
          v31 = v51;
          if ( !v51 )
          {
            v52 = adreno_ib_add(a2, s[50] & 0xFFFFFFE0, 3, a6);
            _X0 = v67;
            v31 = v52;
            if ( !v52 )
            {
              v53 = adreno_ib_add(a2, s[51] & 0xFFFFFFE0, 3, a6);
              _X0 = v67;
              v31 = v53;
              if ( !v53 )
              {
                LODWORD(_X0) = adreno_ib_add(a2, s[52] & 0xFFFFFFE0, 3, a6);
LABEL_69:
                v31 = _X0;
                _X0 = v67;
              }
            }
          }
        }
      }
      else
      {
LABEL_63:
        v31 = 0;
      }
    }
LABEL_70:
    v48 = *(_QWORD *)(_X0 + 72);
    if ( v48 )
    {
      v49 = *(void (__fastcall **)(_QWORD))(v48 + 32);
      if ( v49 )
      {
        if ( *((_DWORD *)v49 - 1) != 1555154090 )
          __break(0x8228u);
        v49(v19);
        _X0 = v67;
      }
    }
    __asm { PRFM            #0x11, [X0] }
    do
      v63 = __ldxr((unsigned int *)_X0);
    while ( __stlxr(v63 - 1, (unsigned int *)_X0) );
    if ( v63 == 1 )
    {
      __dmb(9u);
      kgsl_mem_entry_destroy();
    }
    else if ( v63 <= 0 )
    {
      refcount_warn_saturate(_X0, 3);
    }
    result = v31;
    goto LABEL_88;
  }
  v15 = *(_QWORD *)a6 + 8LL;
  while ( 1 )
  {
    if ( *(_DWORD *)(v15 + 8) == a5 )
    {
      v16 = *(_QWORD *)(v15 - 8);
      if ( v16 <= a3 && *(_QWORD *)v15 + v16 >= a3 + 4 * a4 )
        break;
    }
    --v14;
    v15 += 32;
    if ( !v14 )
      goto LABEL_8;
  }
  result = 0;
LABEL_88:
  _ReadStatusReg(SP_EL0);
  return result;
}
