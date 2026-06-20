__int64 __fastcall sde_mixer_parse_dt(__int64 a1, __int64 a2)
{
  int v4; // w8
  unsigned __int64 dt_props; // x0
  unsigned __int64 v6; // x19
  unsigned int v7; // w21
  int v8; // w20
  int v9; // w24
  int v10; // w25
  __int64 child_by_name; // x0
  unsigned __int64 v12; // x0
  unsigned __int64 v13; // x22
  unsigned __int64 v14; // x0
  __int64 v15; // x1
  unsigned __int64 v16; // x28
  int v17; // w27
  int v18; // w22
  unsigned int v19; // w20
  __int64 v20; // x8
  __int64 v21; // x9
  __int64 v22; // x10
  unsigned int v23; // w14
  unsigned int v25; // w15
  __int64 v26; // x15
  unsigned __int64 v32; // x16
  unsigned __int64 v35; // x17
  unsigned __int64 v36; // x23
  unsigned __int64 v37; // x8
  _DWORD *v39; // x13
  int v40; // w12
  unsigned __int64 v42; // x12
  unsigned __int64 v43; // x20
  unsigned __int64 v44; // x21
  unsigned __int64 v48; // x10
  int v49; // w24
  __int64 v50; // x0
  _DWORD *v51; // x25
  __int64 v52; // x26
  int v53; // w8
  unsigned __int64 v54; // x24
  int v55; // w8
  int v56; // w8
  int v57; // w8
  int v58; // w9
  int v59; // w8
  int v60; // w9
  int v61; // w9
  unsigned __int64 v64; // x9
  unsigned __int64 v67; // x9
  unsigned __int64 v70; // x9
  unsigned __int64 v73; // x9
  unsigned __int64 v76; // x9
  unsigned __int64 v79; // x9
  unsigned __int64 v82; // x9
  unsigned __int64 v85; // x9
  unsigned __int64 v88; // x9
  unsigned __int64 v89; // [xsp+20h] [xbp-60h]
  unsigned __int64 v90; // [xsp+28h] [xbp-58h]
  int v91; // [xsp+34h] [xbp-4Ch]
  __int64 v92; // [xsp+38h] [xbp-48h]
  __int64 v93; // [xsp+44h] [xbp-3Ch]
  int v94; // [xsp+4Ch] [xbp-34h]
  int v95; // [xsp+50h] [xbp-30h]
  int v96; // [xsp+54h] [xbp-2Ch]
  const char *v97; // [xsp+58h] [xbp-28h] BYREF
  const char *v98; // [xsp+60h] [xbp-20h] BYREF
  const char *v99; // [xsp+68h] [xbp-18h] BYREF
  _QWORD v100[2]; // [xsp+70h] [xbp-10h] BYREF

  v100[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a2 + 21580);
  v100[0] = 0;
  v92 = a2 + 20480;
  v91 = v4;
  dt_props = sde_get_dt_props(a1, 8, &mixer_prop, 8, (char *)v100 + 4);
  v6 = dt_props;
  if ( dt_props >= 0xFFFFFFFFFFFFF001LL )
  {
    v7 = dt_props;
LABEL_50:
    _ReadStatusReg(SP_EL0);
    return v7;
  }
  v8 = *(_DWORD *)(a2 + 9616);
  v9 = *(_DWORD *)(a2 + 8160);
  v10 = *(_DWORD *)(a2 + 8840);
  child_by_name = of_get_child_by_name(a1, off_B0B8);
  if ( child_by_name )
  {
    v12 = sde_get_dt_props(child_by_name, 8, &mixer_blocks_prop, 1, 0);
    v13 = v12;
    if ( v12 >= 0xFFFFFFFFFFFFF001LL )
    {
      v7 = v12;
LABEL_48:
      if ( v6 )
      {
        kvfree(*(_QWORD *)(v6 + 320));
        kvfree(v6);
      }
      goto LABEL_50;
    }
  }
  else
  {
    v13 = 0;
  }
  v14 = sde_get_dt_props(a1, 1, &mixer_blend_prop, 1, v100);
  if ( v14 > 0xFFFFFFFFFFFFF000LL )
  {
    v7 = v14;
LABEL_46:
    if ( v13 )
    {
      kvfree(*(_QWORD *)(v13 + 320));
      kvfree(v13);
    }
    goto LABEL_48;
  }
  v89 = v13;
  v90 = v14;
  if ( HIDWORD(v100[0]) )
  {
    v96 = v8;
    v16 = 0;
    v17 = 0;
    v18 = 0;
    v19 = 0;
    v94 = v10;
    v95 = v9;
    v93 = 0;
    _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v98 = nullptr;
      v99 = nullptr;
      v97 = nullptr;
      if ( v16 == 64 )
        goto LABEL_134;
      v49 = *(_DWORD *)(*(_QWORD *)(v6 + 320) + 4 * v16);
      if ( v49 )
        break;
      v54 = v16 + 1;
LABEL_53:
      v16 = v54;
      if ( v54 >= HIDWORD(v100[0]) )
        goto LABEL_12;
    }
    if ( v19 > 0xC )
      goto LABEL_134;
    v50 = _kvmalloc_node_noprof(128, 0, 3520, 0xFFFFFFFFLL);
    v51 = (_DWORD *)v50;
    if ( !v50 )
    {
      v13 = v89;
      v36 = v90;
      v7 = -12;
      if ( v90 )
        goto LABEL_45;
      goto LABEL_46;
    }
    v52 = a2 + 6960 + 96LL * v19;
    *(_QWORD *)(v52 + 48) = v50;
    *(_DWORD *)(v52 + 20) = v49;
    if ( *(_BYTE *)(v6 + 1) == 1 )
      v53 = *(_DWORD *)(*(_QWORD *)(v6 + 320) + 768LL);
    else
      v53 = 256;
    v54 = v16 + 1;
    *(_DWORD *)(v52 + 24) = v53;
    *(_DWORD *)(v52 + 16) = v16 + 1;
    v14 = snprintf((char *)v52, 0x10u, "lm_%u", v16);
    v55 = *(_DWORD *)(*(_QWORD *)(v6 + 320) + 4 * v16 + 1536);
    if ( v55 )
      *(_QWORD *)(v52 + 80) = 1 << v55;
    v56 = v100[0];
    *v51 = *(_DWORD *)(v92 + 1096);
    v51[1] = v91;
    if ( v56 )
    {
      v51[2] = **(_DWORD **)(v90 + 320);
      if ( v56 != 1 )
      {
        v51[3] = *(_DWORD *)(*(_QWORD *)(v90 + 320) + 4LL);
        if ( v56 != 2 )
        {
          v51[4] = *(_DWORD *)(*(_QWORD *)(v90 + 320) + 8LL);
          if ( v56 != 3 )
          {
            v51[5] = *(_DWORD *)(*(_QWORD *)(v90 + 320) + 12LL);
            if ( v56 != 4 )
            {
              v51[6] = *(_DWORD *)(*(_QWORD *)(v90 + 320) + 16LL);
              if ( v56 != 5 )
              {
                v51[7] = *(_DWORD *)(*(_QWORD *)(v90 + 320) + 20LL);
                if ( v56 != 6 )
                {
                  v51[8] = *(_DWORD *)(*(_QWORD *)(v90 + 320) + 24LL);
                  if ( v56 != 7 )
                  {
                    v51[9] = *(_DWORD *)(*(_QWORD *)(v90 + 320) + 28LL);
                    if ( v56 != 8 )
                    {
                      v51[10] = *(_DWORD *)(*(_QWORD *)(v90 + 320) + 32LL);
                      if ( v56 != 9 )
                      {
                        v51[11] = *(_DWORD *)(*(_QWORD *)(v90 + 320) + 36LL);
                        if ( v56 != 10 )
                        {
                          v51[12] = *(_DWORD *)(*(_QWORD *)(v90 + 320) + 40LL);
                          if ( v56 != 11 )
                          {
                            v51[13] = *(_DWORD *)(*(_QWORD *)(v90 + 320) + 44LL);
                            if ( v56 != 12 )
                              goto LABEL_134;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    if ( (*(_QWORD *)(a2 + 22008) & 0x8000) != 0 )
    {
      _X8 = (unsigned __int64 *)(v52 + 32);
      __asm { PRFM            #0x11, [X8] }
      do
        v64 = __ldxr(_X8);
      while ( __stxr(v64 | 4, _X8) );
      if ( (*(_QWORD *)(a2 + 22008) & 2) == 0 )
      {
LABEL_79:
        if ( (*(_QWORD *)(a2 + 22008) & 0x1000) == 0 )
          goto LABEL_84;
        goto LABEL_83;
      }
    }
    else if ( (*(_QWORD *)(a2 + 22008) & 2) == 0 )
    {
      goto LABEL_79;
    }
    _X8 = (unsigned __int64 *)(v52 + 32);
    __asm { PRFM            #0x11, [X8] }
    do
      v67 = __ldxr(_X8);
    while ( __stxr(v67 | 0x10, _X8) );
    if ( (*(_QWORD *)(a2 + 22008) & 0x1000) == 0 )
    {
LABEL_84:
      if ( *(_DWORD *)a2 >> 28 < 0xBu )
      {
        if ( (*(_QWORD *)(a2 + 22008) & 0x400000000000LL) == 0 )
        {
LABEL_88:
          of_property_read_string_helper(a1, off_B0D0, &v99, 1, (unsigned int)v16);
          if ( v99 && !strcmp(v99, "primary") )
          {
            _X8 = (unsigned __int64 *)(v52 + 32);
            __asm { PRFM            #0x11, [X8] }
            do
              v82 = __ldxr(_X8);
            while ( __stxr(v82 | 0x20, _X8) );
          }
          of_property_read_string_helper(a1, off_B0E8, &v98, 1, (unsigned int)v16);
          if ( v98 && !strcmp(v98, "cwb") )
          {
            _X8 = (unsigned __int64 *)(v52 + 32);
            __asm { PRFM            #0x11, [X8] }
            do
              v85 = __ldxr(_X8);
            while ( __stxr(v85 | 0x80, _X8) );
          }
          of_property_read_string_helper(a1, off_B100, &v97, 1, (unsigned int)v16);
          v14 = (unsigned __int64)v97;
          if ( v97 )
          {
            v14 = strcmp(v97, "dcwb");
            if ( !(_DWORD)v14 )
            {
              _X8 = (unsigned __int64 *)(v52 + 32);
              __asm { PRFM            #0x11, [X8] }
              do
                v88 = __ldxr(_X8);
              while ( __stxr(v88 | 0x100, _X8) );
              if ( *(_DWORD *)(v52 + 20) == 3855 )
              {
                *(_QWORD *)(v52 + 20) = 0;
                *(_BYTE *)(v52 + 72) = 1;
              }
            }
          }
          if ( v96 > 0 )
            v57 = v18 + 1;
          else
            v57 = 14;
          ++v18;
          if ( v95 > 0 )
            v58 = v17 + 1;
          else
            v58 = 5;
          ++v17;
          *(_DWORD *)(v52 + 56) = v58;
          *(_DWORD *)(v52 + 60) = v57;
          if ( v94 > 0 )
            v59 = v93 + 1;
          else
            v59 = 5;
          --v95;
          --v96;
          *(_DWORD *)(v52 + 64) = v59;
          *(_DWORD *)(v52 + 68) = HIDWORD(v93) + 1;
          v60 = v19++ & 1;
          HIDWORD(v93) += v60;
          --v94;
          v51[18] = 3;
          if ( v89 && *(_BYTE *)v89 == 1 )
          {
            v51[19] = **(_DWORD **)(v89 + 320);
            v61 = *(_DWORD *)(*(_QWORD *)(v89 + 320) + 4LL);
            v51[20] = 0;
            v51[22] = v61;
            _X9 = (unsigned __int64 *)(v52 + 32);
            __asm { PRFM            #0x11, [X9] }
            do
              v48 = __ldxr(_X9);
            while ( __stxr(v48 | 8, _X9) );
          }
          LODWORD(v93) = v93 + 1;
          goto LABEL_53;
        }
      }
      else
      {
        _X8 = (unsigned __int64 *)(v52 + 32);
        __asm { PRFM            #0x11, [X8] }
        do
          v73 = __ldxr(_X8);
        while ( __stxr(v73 | 0x800, _X8) );
        if ( (*(_QWORD *)(a2 + 22008) & 0x400000000000LL) == 0 )
          goto LABEL_88;
      }
      _X8 = (unsigned __int64 *)(v52 + 32);
      __asm { PRFM            #0x11, [X8] }
      do
        v76 = __ldxr(_X8);
      while ( __stxr(v76 | 0x1000, _X8) );
      _X8 = (unsigned __int64 *)(v52 + 32);
      __asm { PRFM            #0x11, [X8] }
      do
        v79 = __ldxr(_X8);
      while ( __stxr(v79 | 0x2000, _X8) );
      goto LABEL_88;
    }
LABEL_83:
    _X8 = (unsigned __int64 *)(v52 + 32);
    __asm { PRFM            #0x11, [X8] }
    do
      v70 = __ldxr(_X8);
    while ( __stxr(v70 | 0x200, _X8) );
    goto LABEL_84;
  }
  v19 = 0;
LABEL_12:
  if ( *(_DWORD *)(a2 + 56) == 41 && *(int *)(v6 + 92) >= 1 )
  {
    v20 = 0;
    v21 = 5636;
    v22 = a2 + 6960;
    while ( v20 != 64 )
    {
      v23 = *(_DWORD *)(*(_QWORD *)(v6 + 320) + v21 - 4);
      if ( v23 > 0xC )
        break;
      _X15 = (unsigned __int64 *)(v22 + 96LL * v23 + 32);
      __asm { PRFM            #0x11, [X15] }
      do
        v32 = __ldxr(_X15);
      while ( __stxr(v32 | 0x8000, _X15) );
      v25 = *(_DWORD *)(*(_QWORD *)(v6 + 320) + v21);
      if ( v25 > 0xC )
        break;
      v26 = v22 + 96LL * v25;
      _X16 = (unsigned __int64 *)(v26 + 32);
      __asm { PRFM            #0x11, [X16] }
      do
      {
        v35 = __ldxr(_X16);
        v14 = __stxr(v35 | 0x4000, _X16);
      }
      while ( (_DWORD)v14 );
      *(_DWORD *)(v26 + 88) = v23;
      ++v20;
      v21 += 8;
      if ( v20 >= *(int *)(v6 + 92) )
        goto LABEL_26;
    }
    goto LABEL_134;
  }
LABEL_26:
  *(_DWORD *)(a2 + 6952) = v19;
  LODWORD(v99) = 0;
  v14 = sde_get_dt_props(a1, 2, &noise_layer_prop, 2, &v99);
  v13 = v89;
  v36 = v90;
  if ( v14 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_22B847, "_sde_lm_noise_parse_dt");
    goto LABEL_44;
  }
  if ( (*(_BYTE *)v14 & 1) == 0 || (*(_BYTE *)(v14 + 1) & 1) == 0 )
  {
    v43 = v14;
    if ( (_drm_debug & 4) != 0 )
      printk(&unk_26D6ED, *(unsigned __int8 *)v14);
    else
      printk(&unk_24A022, "_sde_lm_noise_parse_dt");
    v14 = v43;
LABEL_42:
    if ( v14 )
    {
      v44 = v14;
      kvfree(*(_QWORD *)(v14 + 320));
      kvfree(v44);
    }
LABEL_44:
    v7 = 0;
    if ( v90 )
    {
LABEL_45:
      kvfree(*(_QWORD *)(v36 + 320));
      kvfree(v36);
    }
    goto LABEL_46;
  }
  if ( !*(_DWORD *)(a2 + 6952) )
    goto LABEL_42;
  v37 = 0;
  _X9 = (unsigned __int64 *)(a2 + 6992);
  while ( v37 != 13 )
  {
    v39 = (_DWORD *)_X9[2];
    v39[28] = **(_DWORD **)(v14 + 320);
    v40 = *(_DWORD *)(*(_QWORD *)(v14 + 320) + 768LL);
    v39[29] = 4;
    v39[31] = v40;
    __asm { PRFM            #0x11, [X9] }
    do
      v42 = __ldxr(_X9);
    while ( __stxr(v42 | 0x400, _X9) );
    ++v37;
    _X9 += 12;
    if ( v37 >= *(unsigned int *)(a2 + 6952) )
      goto LABEL_42;
  }
LABEL_134:
  __break(0x5512u);
  return sde_intf_parse_dt(v14, v15);
}
