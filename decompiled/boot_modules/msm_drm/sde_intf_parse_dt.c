__int64 __fastcall sde_intf_parse_dt(__int64 a1, __int64 a2)
{
  __int64 v4; // x21
  __int64 v5; // x0
  __int64 v6; // x1
  __int64 v7; // x26
  unsigned __int64 v8; // x25
  __int64 v9; // x22
  __int64 v10; // x24
  __int64 v11; // x28
  unsigned int v12; // w19
  unsigned __int64 v16; // x9
  int v17; // w8
  __int64 v18; // x27
  unsigned __int64 v19; // x23
  _DWORD *v20; // x8
  char *v21; // x25
  int v22; // w8
  __int64 v23; // x9
  __int64 v24; // x8
  __int64 v25; // x8
  __int64 v26; // x3
  unsigned __int64 v33; // x9
  unsigned __int64 v36; // x9
  unsigned __int64 v39; // x9
  unsigned __int64 v42; // x9
  unsigned __int64 v45; // x9
  unsigned __int64 v48; // x9
  unsigned __int64 v51; // x9
  unsigned __int64 v54; // x9
  unsigned __int64 v57; // x9
  unsigned __int64 v60; // x9
  unsigned __int64 v63; // x9
  unsigned __int64 v66; // x9
  unsigned __int64 v69; // x9
  unsigned __int64 v72; // x9
  unsigned __int64 v75; // x9
  unsigned __int64 v78; // x9
  unsigned __int64 v81; // x9
  unsigned __int64 v84; // x9
  unsigned __int64 v87; // x9
  unsigned __int64 v90; // x9
  unsigned __int64 v93; // x9
  __int64 v94; // [xsp+0h] [xbp-50h]
  __int64 v95; // [xsp+8h] [xbp-48h]
  char *s1; // [xsp+18h] [xbp-38h] BYREF
  unsigned int v97; // [xsp+24h] [xbp-2Ch] BYREF
  int v98; // [xsp+28h] [xbp-28h] BYREF
  char v99; // [xsp+2Ch] [xbp-24h]
  _QWORD v100[2]; // [xsp+30h] [xbp-20h] BYREF
  int v101; // [xsp+40h] [xbp-10h]
  __int64 v102; // [xsp+48h] [xbp-8h]

  v102 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v101 = 0;
  v100[0] = 0;
  v100[1] = 0;
  v99 = 0;
  v97 = 0;
  v98 = 0;
  s1 = nullptr;
  v4 = _kvmalloc_node_noprof(3840, 0, 3520, 0xFFFFFFFFLL);
  if ( !v4 )
  {
    LODWORD(v5) = -12;
    goto LABEL_8;
  }
  LODWORD(v5) = validate_dt_entry(a1, &intf_prop, 5, v100, &v97);
  if ( (_DWORD)v5 )
    goto LABEL_8;
  *(_DWORD *)(a2 + 13400) = v97;
  v5 = read_dt_entry(a1, &intf_prop, 5, v100, &v98, v4);
  if ( (_DWORD)v5 )
    goto LABEL_8;
  if ( !v97 )
  {
    LODWORD(v5) = 0;
LABEL_8:
    v12 = v5;
    kvfree(v4);
    _ReadStatusReg(SP_EL0);
    return v12;
  }
  v7 = 0;
  v8 = 0;
  v9 = 13440;
  v10 = 13408;
  v11 = 13472;
  v94 = 0;
  v95 = 0;
  while ( v7 != 52 )
  {
    v17 = *(_DWORD *)(v4 + 768);
    v18 = a2 + v11;
    v19 = v8 + 1;
    *(_DWORD *)(v18 - 44) = *(_DWORD *)(v4 + v7);
    *(_DWORD *)(v18 - 40) = v17;
    *(_DWORD *)(v18 - 48) = v8 + 1;
    snprintf((char *)(a2 + v10), 0x10u, "intf_%u", v8);
    if ( (v98 & 0x100) == 0 )
      *(_DWORD *)(v18 - 40) = 256;
    LODWORD(v5) = add_to_irq_offset_list(a2, 1, *(unsigned int *)(v18 - 48), *(unsigned int *)(v18 - 44));
    if ( (_DWORD)v5 )
      goto LABEL_8;
    v20 = (_DWORD *)(a2 + 21792);
    if ( BYTE2(v98) )
      v20 = (_DWORD *)(v4 + v7 + 1536);
    *(_DWORD *)(a2 + v11 - 8) = *v20;
    if ( (*(_QWORD *)(a2 + 680) & 0x8000) != 0 )
      *(_DWORD *)(a2 + v11) = 10;
    of_property_read_string_helper(a1, off_B1C0, &s1, 1, (unsigned int)v8);
    v21 = s1;
    if ( !strcmp(s1, "dsi") )
    {
      v24 = a2 + v11;
      *(_DWORD *)(v24 - 16) = 1;
      *(_DWORD *)(v24 - 12) = HIDWORD(v95)++;
    }
    else if ( !strcmp(v21, "hdmi") )
    {
      v25 = a2 + v11;
      *(_DWORD *)(v25 - 16) = 3;
      *(_DWORD *)(v25 - 12) = HIDWORD(v94)++;
    }
    else
    {
      v22 = (unsigned __int8)*v21 - 100;
      if ( *v21 == 100 )
      {
        v22 = (unsigned __int8)v21[1] - 112;
        if ( v21[1] == 112 )
          v22 = (unsigned __int8)v21[2];
      }
      v23 = a2 + v11;
      if ( v22 )
      {
        *(_DWORD *)(v23 - 16) = 0;
        *(_DWORD *)(v23 - 12) = v95;
        LODWORD(v95) = v95 + 1;
      }
      else
      {
        *(_DWORD *)(v23 - 16) = 10;
        *(_DWORD *)(v23 - 12) = v94;
        LODWORD(v94) = v94 + 1;
      }
    }
    if ( *(_DWORD *)(a2 + 28) == 256 )
    {
      _X8 = (unsigned __int64 *)(a2 + v9);
      __asm { PRFM            #0x11, [X8] }
      do
        v33 = __ldxr(_X8);
      while ( __stxr(v33 | 2, _X8) );
      if ( (v99 & 1) != 0 )
      {
LABEL_32:
        v26 = *(unsigned int *)(v4 + v7 + 3072);
        *(_DWORD *)(a2 + v11 - 4) = v26;
        if ( (_DWORD)v26 )
          goto LABEL_37;
        goto LABEL_39;
      }
    }
    else if ( (v99 & 1) != 0 )
    {
      goto LABEL_32;
    }
    v26 = *(unsigned int *)(a2 + v11 - 4);
    if ( (_DWORD)v26 )
    {
LABEL_37:
      LODWORD(v5) = add_to_irq_offset_list(a2, 3, *(unsigned int *)(v18 - 48), v26);
      if ( (_DWORD)v5 )
        goto LABEL_8;
      _X8 = (unsigned __int64 *)(a2 + v9);
      __asm { PRFM            #0x11, [X8] }
      do
        v36 = __ldxr(_X8);
      while ( __stxr(v36 | 4, _X8) );
    }
LABEL_39:
    if ( *(_DWORD *)a2 >> 28 >= 5u )
    {
      _X8 = (unsigned __int64 *)(a2 + v9);
      __asm { PRFM            #0x11, [X8] }
      do
        v39 = __ldxr(_X8);
      while ( __stxr(v39 | 0x80, _X8) );
      if ( *(_DWORD *)a2 >> 28 >= 7u )
      {
        _X8 = (unsigned __int64 *)(a2 + v9);
        __asm { PRFM            #0x11, [X8] }
        do
          v42 = __ldxr(_X8);
        while ( __stxr(v42 | 8, _X8) );
        if ( (*(_DWORD *)a2 & 0x80000000) != 0 )
        {
          _X8 = (unsigned __int64 *)(a2 + v9);
          __asm { PRFM            #0x11, [X8] }
          do
            v45 = __ldxr(_X8);
          while ( __stxr(v45 | 0x40, _X8) );
          _X8 = (unsigned __int64 *)(a2 + v9);
          __asm { PRFM            #0x11, [X8] }
          do
            v48 = __ldxr(_X8);
          while ( __stxr(v48 | 0x100, _X8) );
          _X8 = (unsigned __int64 *)(a2 + v9);
          __asm { PRFM            #0x11, [X8] }
          do
            v51 = __ldxr(_X8);
          while ( __stxr(v51 | 0x200, _X8) );
          _X8 = (unsigned __int64 *)(a2 + v9);
          __asm { PRFM            #0x11, [X8] }
          do
            v54 = __ldxr(_X8);
          while ( __stxr(v54 | 0x1000, _X8) );
          if ( *(_DWORD *)a2 >> 28 >= 9u )
          {
            _X8 = (unsigned __int64 *)(a2 + v9);
            __asm { PRFM            #0x11, [X8] }
            do
              v57 = __ldxr(_X8);
            while ( __stxr(v57 | 0x400, _X8) );
            _X8 = (unsigned __int64 *)(a2 + v9);
            __asm { PRFM            #0x11, [X8] }
            do
              v60 = __ldxr(_X8);
            while ( __stxr(v60 | 0x4000, _X8) );
            if ( *(_DWORD *)a2 >> 29 >= 5u )
            {
              _X8 = (unsigned __int64 *)(a2 + v9);
              __asm { PRFM            #0x11, [X8] }
              do
                v63 = __ldxr(_X8);
              while ( __stxr(v63 | 0x800, _X8) );
              _X8 = (unsigned __int64 *)(a2 + v9);
              __asm { PRFM            #0x11, [X8] }
              do
                v66 = __ldxr(_X8);
              while ( __stxr(v66 | 0x10, _X8) );
              _X8 = (unsigned __int64 *)(a2 + v9);
              __asm { PRFM            #0x11, [X8] }
              do
                v69 = __ldxr(_X8);
              while ( __stxr(v69 | 0x20, _X8) );
              _X8 = (unsigned __int64 *)(a2 + v9);
              __asm { PRFM            #0x11, [X8] }
              do
                v72 = __ldxr(_X8);
              while ( __stxr(v72 | 0x8000, _X8) );
              _X8 = (unsigned __int64 *)(a2 + v9);
              __asm { PRFM            #0x11, [X8] }
              do
                v75 = __ldxr(_X8);
              while ( __stxr(v75 | 0x10000, _X8) );
              _X8 = (unsigned __int64 *)(a2 + v9);
              __asm { PRFM            #0x11, [X8] }
              do
                v78 = __ldxr(_X8);
              while ( __stxr(v78 | 0x20000, _X8) );
              _X8 = (unsigned __int64 *)(a2 + v9);
              __asm { PRFM            #0x11, [X8] }
              do
                v81 = __ldxr(_X8);
              while ( __stxr(v81 | 0x40000, _X8) );
              _X8 = (unsigned __int64 *)(a2 + v9);
              __asm { PRFM            #0x11, [X8] }
              do
                v84 = __ldxr(_X8);
              while ( __stxr(v84 | 0x400000, _X8) );
              if ( *(_DWORD *)a2 >> 29 >= 5u )
              {
                _X8 = (unsigned __int64 *)(a2 + v9);
                __asm { PRFM            #0x11, [X8] }
                do
                  v87 = __ldxr(_X8);
                while ( __stxr(v87 | 0x200000, _X8) );
                if ( *(_DWORD *)a2 >> 30 == 3 )
                {
                  _X8 = (unsigned __int64 *)(a2 + v9);
                  __asm { PRFM            #0x11, [X8] }
                  do
                    v90 = __ldxr(_X8);
                  while ( __stxr(v90 | 0x2000, _X8) );
                  _X8 = (unsigned __int64 *)(a2 + v9);
                  __asm { PRFM            #0x11, [X8] }
                  do
                    v93 = __ldxr(_X8);
                  while ( __stxr(v93 | 0x80000, _X8) );
                  _X8 = (unsigned __int64 *)(a2 + v9);
                  __asm { PRFM            #0x11, [X8] }
                  do
                    v16 = __ldxr(_X8);
                  while ( __stxr(v16 | 0x800000, _X8) );
                }
              }
            }
          }
        }
      }
    }
    v5 = 0;
    v7 += 4;
    v9 += 72;
    v10 += 72;
    v11 += 72;
    v8 = v19;
    if ( v19 >= v97 )
      goto LABEL_8;
  }
  __break(0x5512u);
  return sde_wb_parse_dt(v5, v6);
}
