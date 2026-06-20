__int64 __fastcall cfg80211_connect_done(__int64 a1, unsigned __int64 a2, unsigned int a3)
{
  unsigned __int64 v3; // x19
  int v4; // w21
  __int64 v5; // x26
  __int64 v6; // x24
  unsigned int v7; // w8
  __int64 v8; // x21
  unsigned __int64 v9; // x27
  __int64 v10; // x26
  __int64 **v11; // x28
  bool v12; // w9
  __int64 v13; // x22
  __int64 *v14; // x20
  __int64 *bss; // x0
  __int64 v16; // x9
  __int64 v17; // x9
  __int64 v18; // x10
  __int64 v20; // x10
  unsigned __int64 v21; // x20
  __int64 result; // x0
  __int64 v23; // x8
  __int64 v24; // x22
  __int64 v25; // x8
  __int64 v26; // x9
  unsigned __int64 v27; // x23
  __int16 v28; // w10
  size_t v29; // x2
  __int64 v30; // x8
  size_t v31; // x2
  __int64 v32; // x8
  size_t v33; // x2
  __int64 v34; // x8
  size_t v35; // x2
  __int64 v36; // x8
  _QWORD *v37; // x9
  __int64 v38; // x10
  int v39; // w9
  unsigned int v40; // w13
  unsigned __int64 v41; // x8
  unsigned __int64 v42; // x9
  unsigned __int64 v43; // x10
  unsigned __int64 v44; // x12
  bool v45; // w14
  unsigned __int64 v46; // x13
  __int64 v47; // x14
  unsigned __int64 v48; // x14
  __int64 v49; // x15
  unsigned __int64 v50; // x15
  __int64 v51; // x13
  __int64 v52; // x15
  __int16 v53; // w16
  unsigned __int64 v54; // x13
  __int64 v55; // x13
  __int64 v56; // x14
  __int16 v57; // w15
  unsigned int v63; // w16
  __int64 v64; // x14
  unsigned int v67; // w15
  __int64 v68; // x0
  __int64 v69; // x2
  __int64 v70; // x9
  unsigned __int64 StatusReg; // x22
  __int64 v72; // x23
  __int64 v73; // x9
  unsigned int v74; // w8
  unsigned __int64 v75; // x20
  _QWORD **v76; // x21
  bool v77; // w9
  bool v78; // cc
  __int64 v79; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(a1 + 992);
  v79 = *(_QWORD *)v6;
  if ( *(_QWORD *)v6 )
  {
    v7 = *(unsigned __int16 *)(a2 + 104);
    v8 = a3;
    v3 = a2;
    v9 = 0;
    v10 = 0;
    v11 = (__int64 **)(a2 + 128);
    v12 = *(_WORD *)(a2 + 104) == 0;
    do
    {
      if ( v12 || ((v7 >> v9) & 1) != 0 )
      {
        v13 = *(_QWORD *)v6;
        if ( !*(_QWORD *)v6 )
          goto LABEL_151;
        v14 = *v11;
        if ( *v11 && (__int64 *)*(v14 - 14) == v14 - 14 )
        {
          bss = _cfg80211_get_bss(
                  *(_QWORD *)v6,
                  nullptr,
                  (__int64)(v14 + 9),
                  (void *)(v6 + 286),
                  *(unsigned __int8 *)(v6 + 318),
                  *(_DWORD *)(v6 + 96),
                  2u,
                  1);
          if ( bss )
            *v11 = bss;
          else
            cfg80211_bss_update(v13 - 992, (__int64)(v14 - 14), 0, *(v14 - 6));
          cfg80211_put_bss(*(_QWORD *)v6, v14);
          v7 = *(unsigned __int16 *)(v3 + 104);
        }
        if ( *(v11 - 1) )
          v16 = 6;
        else
          v16 = 0;
        v17 = v16 + v10;
        if ( *(v11 - 2) )
          v18 = 6;
        else
          v18 = 0;
        v10 = v17 + v18;
      }
      v12 = v7 == 0;
      if ( !v7 )
        break;
      _CF = v9++ >= 0xE;
      v11 += 4;
    }
    while ( !_CF );
    v20 = 622;
    if ( !*(_QWORD *)(v3 + 96) )
      v20 = 616;
    v21 = *(_QWORD *)(v3 + 16)
        + v10
        + *(_QWORD *)(v3 + 32)
        + v20
        + *(_QWORD *)(v3 + 48)
        + *(_QWORD *)(v3 + 72)
        + 16LL * (*(_QWORD *)(v3 + 80) != 0);
    result = _kmalloc_noprof(v21, (unsigned int)v8 | 0x100);
    v8 = result;
    if ( result )
    {
LABEL_25:
      if ( v21 < 0x10 || (v21 & 0xFFFFFFFFFFFFFFFCLL) == 0x10 )
        goto LABEL_147;
      v23 = *(_QWORD *)(v3 + 96);
      v24 = v8 + 616;
      *(_DWORD *)(v8 + 16) = 0;
      if ( v23 )
      {
        if ( v21 < 0x78 || (v21 & 0xFFFFFFFFFFFFFFF8LL) == 0x78 )
          goto LABEL_147;
        *(_QWORD *)(v8 + 120) = v24;
        if ( v21 >= 0x268 )
          a2 = v21 - 616;
        else
          a2 = 0;
        if ( a2 <= 5 )
          goto LABEL_148;
        if ( (v21 & 0xFFFFFFFFFFFFFFF8LL) == 0x78 )
          goto LABEL_147;
        v25 = *(_QWORD *)(v3 + 96);
        v26 = *(_QWORD *)(v8 + 120);
        v24 = v8 + 622;
        v27 = 622;
        v28 = *(_WORD *)(v25 + 4);
        LODWORD(v25) = *(_DWORD *)v25;
        *(_WORD *)(v26 + 4) = v28;
        *(_DWORD *)v26 = v25;
        if ( !*(_QWORD *)(v3 + 16) )
        {
LABEL_36:
          if ( !*(_QWORD *)(v3 + 32) )
            goto LABEL_37;
          goto LABEL_52;
        }
      }
      else
      {
        v27 = 616;
        if ( !*(_QWORD *)(v3 + 16) )
          goto LABEL_36;
      }
      if ( v21 < 0x20 )
        goto LABEL_147;
      if ( (v21 & 0xFFFFFFFFFFFFFFF8LL) == 0x20 )
        goto LABEL_147;
      *(_QWORD *)(v8 + 32) = v24;
      if ( v21 < 0x28 || (v21 & 0xFFFFFFFFFFFFFFF8LL) == 0x28 )
        goto LABEL_147;
      v29 = *(_QWORD *)(v3 + 16);
      if ( v21 >= v27 )
        a2 = v21 - v27;
      else
        a2 = 0;
      *(_QWORD *)(v8 + 40) = v29;
      if ( a2 < v29 )
        goto LABEL_149;
      if ( (v21 & 0xFFFFFFFFFFFFFFF8LL) == 0x20 )
        goto LABEL_147;
      memcpy(*(void **)(v8 + 32), *(const void **)(v3 + 8), v29);
      v30 = *(_QWORD *)(v3 + 16);
      v27 += v30;
      v24 += v30;
      if ( !*(_QWORD *)(v3 + 32) )
      {
LABEL_37:
        if ( !*(_QWORD *)(v3 + 48) )
          goto LABEL_38;
        goto LABEL_62;
      }
LABEL_52:
      if ( v21 < 0x30 )
        goto LABEL_147;
      if ( (v21 & 0xFFFFFFFFFFFFFFF8LL) == 0x30 )
        goto LABEL_147;
      *(_QWORD *)(v8 + 48) = v24;
      if ( v21 < 0x38 || (v21 & 0xFFFFFFFFFFFFFFF8LL) == 0x38 )
        goto LABEL_147;
      v31 = *(_QWORD *)(v3 + 32);
      if ( v21 >= v27 )
        a2 = v21 - v27;
      else
        a2 = 0;
      *(_QWORD *)(v8 + 56) = v31;
      if ( a2 < v31 )
        goto LABEL_149;
      if ( (v21 & 0xFFFFFFFFFFFFFFF8LL) == 0x30 )
        goto LABEL_147;
      memcpy(*(void **)(v8 + 48), *(const void **)(v3 + 24), v31);
      v32 = *(_QWORD *)(v3 + 32);
      v27 += v32;
      v24 += v32;
      if ( !*(_QWORD *)(v3 + 48) )
      {
LABEL_38:
        if ( !*(_QWORD *)(v3 + 72) )
          goto LABEL_39;
        goto LABEL_72;
      }
LABEL_62:
      if ( v21 < 0x40 )
        goto LABEL_147;
      if ( (v21 & 0xFFFFFFFFFFFFFFF8LL) == 0x40 )
        goto LABEL_147;
      *(_QWORD *)(v8 + 64) = v24;
      if ( v21 < 0x48 || (v21 & 0xFFFFFFFFFFFFFFF8LL) == 0x48 )
        goto LABEL_147;
      v33 = *(_QWORD *)(v3 + 48);
      if ( v21 >= v27 )
        a2 = v21 - v27;
      else
        a2 = 0;
      *(_QWORD *)(v8 + 72) = v33;
      if ( a2 < v33 )
        goto LABEL_149;
      if ( (v21 & 0xFFFFFFFFFFFFFFF8LL) == 0x40 )
        goto LABEL_147;
      memcpy(*(void **)(v8 + 64), *(const void **)(v3 + 40), v33);
      v34 = *(_QWORD *)(v3 + 48);
      v27 += v34;
      v24 += v34;
      if ( !*(_QWORD *)(v3 + 72) )
      {
LABEL_39:
        if ( !*(_QWORD *)(v3 + 80) )
          goto LABEL_90;
LABEL_82:
        if ( v21 < 0x68 || (v21 & 0xFFFFFFFFFFFFFFF8LL) == 0x68 )
          goto LABEL_147;
        *(_QWORD *)(v8 + 104) = v24;
        if ( v21 >= v27 )
          a2 = v21 - v27;
        else
          a2 = 0;
        if ( a2 <= 0xF )
        {
LABEL_150:
          _fortify_panic(17, a2);
LABEL_151:
          __break(0x800u);
          goto LABEL_152;
        }
        if ( (v21 & 0xFFFFFFFFFFFFFFF8LL) == 0x68 )
          goto LABEL_147;
        v37 = *(_QWORD **)(v8 + 104);
        v27 += 16LL;
        v24 += 16;
        v38 = *(_QWORD *)(*(_QWORD *)(v3 + 80) + 8LL);
        *v37 = **(_QWORD **)(v3 + 80);
        v37[1] = v38;
LABEL_90:
        if ( v21 >= 0x51 )
        {
          v39 = *(unsigned __int8 *)(v3 + 56);
          *(_BYTE *)(v8 + 80) = v39;
          if ( v39 != 1 )
            goto LABEL_94;
          if ( v21 - 81 >= 3 )
          {
            *(_WORD *)(v8 + 82) = *(_WORD *)(v3 + 58);
LABEL_94:
            if ( v21 >= 0x80 && (v21 & 0xFFFFFFFFFFFFFFFELL) != 0x80 )
            {
              v40 = *(unsigned __int16 *)(v3 + 104);
              v41 = 0;
              v42 = v21 - 160;
              v43 = 160;
              v44 = v27;
              *(_WORD *)(v8 + 128) = v40;
              v45 = v40 == 0;
              do
              {
                if ( v45 || ((v40 >> v41) & 1) != 0 )
                {
                  v46 = v3 + v43;
                  v47 = *(_QWORD *)(v3 + v43 - 32);
                  if ( v47 )
                  {
                    _X15 = (unsigned int *)(v47 - 32);
                    __asm { PRFM            #0x11, [X15] }
                    do
                      v63 = __ldxr(_X15);
                    while ( __stxr(v63 + 1, _X15) );
                    v64 = *(_QWORD *)(v47 + 40);
                    if ( v64 )
                    {
                      _X14 = (unsigned int *)(v64 - 32);
                      __asm { PRFM            #0x11, [X14] }
                      do
                        v67 = __ldxr(_X14);
                      while ( __stxr(v67 + 1, _X14) );
                    }
                  }
                  if ( ((v43 - 8) & 0x8000000000000000LL) != 0 )
                    goto LABEL_147;
                  if ( v21 < v43 - 8 )
                    goto LABEL_147;
                  if ( v42 >= 0xFFFFFFFFFFFFFFF8LL )
                    goto LABEL_147;
                  *(_QWORD *)(v8 + v43 - 8) = *(_QWORD *)(v46 - 32);
                  if ( (v43 & 0x8000000000000000LL) != 0 || v21 < v43 || v42 < 2 )
                    goto LABEL_147;
                  v48 = v3 + v43;
                  v49 = *(_QWORD *)(v46 - 48);
                  *(_WORD *)(v8 + v43) = *(_WORD *)(v3 + v43 - 24);
                  if ( v49 )
                  {
                    v50 = v43 - 24;
                    if ( ((v43 - 24) & 0x8000000000000000LL) != 0 || v21 < v50 || v42 + 24 < 8 )
                      goto LABEL_147;
                    if ( v21 >= v44 )
                      a2 = v21 - v44;
                    else
                      a2 = 0;
                    *(_QWORD *)(v8 + v43 - 24) = v24;
                    if ( a2 <= 5 )
                      goto LABEL_148;
                    if ( v21 < v50 || v42 + 24 < 8 )
                      goto LABEL_147;
                    v51 = *(_QWORD *)(v46 - 48);
                    v52 = *(_QWORD *)(v8 + v43 - 24);
                    v44 += 6LL;
                    v27 += 6LL;
                    v24 += 6;
                    v53 = *(_WORD *)(v51 + 4);
                    LODWORD(v51) = *(_DWORD *)v51;
                    *(_WORD *)(v52 + 4) = v53;
                    *(_DWORD *)v52 = v51;
                  }
                  if ( *(_QWORD *)(v48 - 40) )
                  {
                    v54 = v43 - 16;
                    if ( (__int64)(v43 - 16) < 0 || v21 < v54 || v42 + 16 < 8 )
                      goto LABEL_147;
                    if ( v21 >= v27 )
                      a2 = v21 - v27;
                    else
                      a2 = 0;
                    *(_QWORD *)(v8 + v43 - 16) = v24;
                    if ( a2 <= 5 )
                      goto LABEL_148;
                    if ( v21 < v54 || v42 + 16 < 8 )
                      goto LABEL_147;
                    v55 = *(_QWORD *)(v48 - 40);
                    v56 = *(_QWORD *)(v8 + v43 - 16);
                    v44 += 6LL;
                    v27 += 6LL;
                    v24 += 6;
                    v57 = *(_WORD *)(v55 + 4);
                    LODWORD(v55) = *(_DWORD *)v55;
                    *(_WORD *)(v56 + 4) = v57;
                    *(_DWORD *)v56 = v55;
                  }
                }
                v40 = *(unsigned __int16 *)(v3 + 104);
                v45 = *(_WORD *)(v3 + 104) == 0;
                if ( !*(_WORD *)(v3 + 104) )
                  break;
                _CF = v41++ >= 0xE;
                v43 += 32LL;
                v42 -= 32LL;
              }
              while ( !_CF );
              if ( (v21 & 0xFFFFFFFFFFFFFFFCLL) != 0x18 )
              {
                *(_DWORD *)(v8 + 24) = *(_DWORD *)v3;
                if ( (v21 & 0xFFFFFFFFFFFFFFFCLL) != 0x70 )
                {
                  *(_DWORD *)(v8 + 112) = *(_DWORD *)(v3 + 88);
                  v68 = raw_spin_lock_irqsave(v6 + 160);
                  v69 = v6 + 144;
                  a2 = *(_QWORD *)(v6 + 152);
                  v70 = v68;
                  if ( v8 == v6 + 144 || a2 == v8 || *(_QWORD *)a2 != v69 )
                  {
LABEL_152:
                    _list_add_valid_or_report(v8, a2);
                    goto LABEL_146;
                  }
                  *(_QWORD *)(v6 + 152) = v8;
                  *(_QWORD *)v8 = v69;
                  if ( (v21 & 0xFFFFFFFFFFFFFFF8LL) != 8 )
                  {
                    *(_QWORD *)(v8 + 8) = a2;
                    *(_QWORD *)a2 = v8;
LABEL_146:
                    raw_spin_unlock_irqrestore(v6 + 160, v70);
                    return queue_work_on(32, cfg80211_wq, v79 - 656);
                  }
                }
              }
            }
          }
        }
LABEL_147:
        __break(1u);
LABEL_148:
        _fortify_panic(17, a2);
LABEL_149:
        _fortify_panic(17, a2);
        goto LABEL_150;
      }
LABEL_72:
      if ( v21 < 0x58 )
        goto LABEL_147;
      if ( (v21 & 0xFFFFFFFFFFFFFFF8LL) == 0x58 )
        goto LABEL_147;
      *(_QWORD *)(v8 + 88) = v24;
      if ( v21 < 0x60 || (v21 & 0xFFFFFFFFFFFFFFF8LL) == 0x60 )
        goto LABEL_147;
      v35 = *(_QWORD *)(v3 + 72);
      if ( v21 >= v27 )
        a2 = v21 - v27;
      else
        a2 = 0;
      *(_QWORD *)(v8 + 96) = v35;
      if ( a2 < v35 )
        goto LABEL_149;
      if ( (v21 & 0xFFFFFFFFFFFFFFF8LL) == 0x58 )
        goto LABEL_147;
      memcpy(*(void **)(v8 + 88), *(const void **)(v3 + 64), v35);
      v36 = *(_QWORD *)(v3 + 72);
      v27 += v36;
      v24 += v36;
      if ( !*(_QWORD *)(v3 + 80) )
        goto LABEL_90;
      goto LABEL_82;
    }
  }
  else
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v72 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cfg80211_connect_done__alloc_tag;
    v73 = 622;
    if ( !*(_QWORD *)(v3 + 96) )
      v73 = 616;
    v21 = *(_QWORD *)(v3 + 16)
        + v5
        + *(_QWORD *)(v3 + 32)
        + v73
        + *(_QWORD *)(v3 + 48)
        + *(_QWORD *)(v3 + 72)
        + 16LL * (*(_QWORD *)(v3 + 80) != 0);
    result = _kmalloc_noprof(v21, v4 | 0x100u);
    v8 = result;
    *(_QWORD *)(StatusReg + 80) = v72;
    if ( result )
      goto LABEL_25;
  }
  v74 = *(unsigned __int16 *)(v3 + 104);
  v75 = 0;
  v76 = (_QWORD **)(v3 + 128);
  v77 = *(_WORD *)(v3 + 104) == 0;
  do
  {
    if ( v77 || ((v74 >> v75) & 1) != 0 )
    {
      result = cfg80211_put_bss(*(_QWORD *)v6, *v76);
      v74 = *(unsigned __int16 *)(v3 + 104);
    }
    v77 = v74 == 0;
    if ( !v74 )
      break;
    v78 = v75++ > 0xD;
    v76 += 4;
  }
  while ( !v78 );
  return result;
}
