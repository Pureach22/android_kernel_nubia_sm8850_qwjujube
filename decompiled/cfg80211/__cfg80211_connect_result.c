__int64 __fastcall _cfg80211_connect_result(__int64 result, __int64 a2)
{
  int v2; // w21
  __int64 v3; // x22
  __int64 v4; // x19
  int v6; // w9
  __int16 v8; // w9
  __int64 v9; // x9
  unsigned __int64 v10; // x8
  __int64 v11; // x9
  unsigned int v12; // w8
  __int64 v13; // x8
  __int64 v14; // x24
  unsigned __int64 v15; // x26
  __int64 v16; // x9
  __int64 v17; // x8
  unsigned int v20; // w8
  unsigned int v21; // w8
  unsigned int v24; // w8
  unsigned int v25; // w8
  __int64 v26; // x8
  unsigned int v27; // w8
  unsigned int v28; // w21
  _QWORD **v29; // x22
  bool v30; // w9
  unsigned int v31; // w10
  _QWORD *v32; // x9
  unsigned int v33; // w23
  _WORD *v34; // x24
  bool v35; // w9
  __int64 *bss; // x0
  unsigned int v39; // w9
  __int64 v40; // x8
  unsigned int v43; // w9
  __int64 v44; // x21
  unsigned int v45; // w8
  unsigned int v46; // w24
  int **v47; // x23
  __int64 v48; // x25
  bool v49; // w9
  unsigned int v50; // w9
  __int64 v51; // x8
  __int64 v52; // x8
  unsigned int v55; // w9
  unsigned int v56; // w9
  unsigned int v59; // w8
  unsigned int v60; // w8
  unsigned int v61; // w9
  _QWORD *v62; // x10
  unsigned int v63; // w8
  __int64 v64; // x11
  bool v65; // w12
  unsigned int v66; // w8
  unsigned int v67; // w9
  bool v68; // w10
  int v69; // w8
  __int64 v70; // x0
  _BYTE *lock; // x0
  unsigned int v72; // w8
  unsigned int v73; // w21
  _QWORD *v74; // x23
  bool v75; // w9
  __int64 v76; // x21
  char *v77; // x22
  unsigned int v78; // w8
  unsigned int v79; // w21
  _QWORD *v80; // x22
  bool v81; // w9
  size_t v82; // x2
  _BYTE *v83; // x20
  size_t v84; // x21
  unsigned int v87; // w8
  unsigned int v88; // w8
  unsigned int v94; // w8
  unsigned int v95; // w8

  v4 = *(_QWORD *)(result + 992);
  v6 = *(_DWORD *)(v4 + 8);
  _ZF = v6 == 2 || v6 == 8;
  if ( !_ZF
    || (v8 = *(_WORD *)(a2 + 104)) != 0
    && (!*(_QWORD *)(a2 + 96)
     || (v8 & 1) != 0 && !*(_QWORD *)(a2 + 112)
     || (v8 & 2) != 0 && !*(_QWORD *)(a2 + 144)
     || (v8 & 4) != 0 && !*(_QWORD *)(a2 + 176)
     || (v8 & 8) != 0 && !*(_QWORD *)(a2 + 208)
     || (v8 & 0x10) != 0 && !*(_QWORD *)(a2 + 240)
     || (v8 & 0x20) != 0 && !*(_QWORD *)(a2 + 272)
     || (v8 & 0x40) != 0 && !*(_QWORD *)(a2 + 304)
     || (v8 & 0x80) != 0 && !*(_QWORD *)(a2 + 336)
     || (*(_WORD *)(a2 + 104) & 0x100) != 0 && !*(_QWORD *)(a2 + 368)
     || (*(_WORD *)(a2 + 104) & 0x200) != 0 && !*(_QWORD *)(a2 + 400)
     || (*(_WORD *)(a2 + 104) & 0x400) != 0 && !*(_QWORD *)(a2 + 432)
     || (*(_WORD *)(a2 + 104) & 0x800) != 0 && !*(_QWORD *)(a2 + 464)
     || (*(_WORD *)(a2 + 104) & 0x1000) != 0 && !*(_QWORD *)(a2 + 496)
     || (*(_WORD *)(a2 + 104) & 0x2000) != 0 && !*(_QWORD *)(a2 + 528)
     || (*(_WORD *)(a2 + 104) & 0x4000) != 0 && !*(_QWORD *)(a2 + 560)
     || *(_QWORD *)(v4 + 88)) )
  {
    __break(0x800u);
    v27 = *(unsigned __int16 *)(a2 + 104);
    v28 = 0;
    v29 = (_QWORD **)(a2 + 128);
    v30 = *(_WORD *)(a2 + 104) == 0;
    do
    {
      if ( v30 || (((unsigned __int64)v27 >> v28) & 1) != 0 )
      {
        result = cfg80211_put_bss(*(_QWORD *)v4, *v29);
        v27 = *(unsigned __int16 *)(a2 + 104);
      }
      v30 = v27 == 0;
      if ( !v27 )
        break;
      _CF = v28++ >= 0xE;
      v29 += 4;
    }
    while ( !_CF );
    return result;
  }
  v9 = *(_QWORD *)v4;
  *(_QWORD *)(v4 + 272) = 0;
  if ( !v9 )
  {
    __break(0x800u);
    goto LABEL_174;
  }
  nl80211_send_connect_result(v9 - 992, result, a2, 0xCC0u);
  v10 = *(unsigned __int16 *)(a2 + 104);
  v11 = 120;
  if ( *(_WORD *)(a2 + 104) )
    v11 = 96;
  v3 = *(_QWORD *)(a2 + v11);
  if ( *(_DWORD *)a2 )
  {
    v2 = 0;
    goto LABEL_44;
  }
  v9 = *(_QWORD *)v4;
  if ( !*(_QWORD *)v4 )
  {
LABEL_174:
    __break(0x800u);
    goto LABEL_175;
  }
  if ( !*(_QWORD *)(*(_QWORD *)(v9 - 992) + 368LL) )
  {
    v31 = 0;
    v32 = (_QWORD *)(a2 + 128);
    while ( *(_WORD *)(a2 + 104) && ((v10 >> v31) & 1) == 0 || *v32 )
    {
      if ( *(_WORD *)(a2 + 104) )
      {
        _CF = v31++ >= 0xE;
        v32 += 4;
        if ( !_CF )
          continue;
      }
      goto LABEL_89;
    }
    __break(0x800u);
    LODWORD(v10) = *(unsigned __int16 *)(a2 + 104);
  }
LABEL_89:
  v33 = 0;
  v34 = (_WORD *)(a2 + 136);
  v35 = (_DWORD)v10 == 0;
  do
  {
    if ( (v35 || (((unsigned __int64)(unsigned int)v10 >> v33) & 1) != 0) && !*v34 && !*((_QWORD *)v34 - 1) )
    {
      v2 = 1;
      bss = _cfg80211_get_bss(
              *(_QWORD *)v4,
              nullptr,
              *((_QWORD *)v34 - 2),
              (void *)(v4 + 286),
              *(unsigned __int8 *)(v4 + 318),
              *(_DWORD *)(v4 + 96),
              2u,
              1);
      *((_QWORD *)v34 - 1) = bss;
      if ( !bss )
        break;
      _X8 = (unsigned int *)(bss - 4);
      __asm { PRFM            #0x11, [X8] }
      do
        v39 = __ldxr(_X8);
      while ( __stxr(v39 + 1, _X8) );
      v40 = bss[5];
      if ( v40 )
      {
        _X8 = (unsigned int *)(v40 - 32);
        __asm { PRFM            #0x11, [X8] }
        do
          v43 = __ldxr(_X8);
        while ( __stxr(v43 + 1, _X8) );
      }
    }
    LODWORD(v10) = *(unsigned __int16 *)(a2 + 104);
    v2 = 0;
    v35 = *(_WORD *)(a2 + 104) == 0;
    if ( !*(_WORD *)(a2 + 104) )
      break;
    _CF = v33++ >= 0xE;
    v34 += 16;
  }
  while ( !_CF );
LABEL_44:
  v12 = *(unsigned __int16 *)(v4 + 1472);
  if ( *(_WORD *)(v4 + 1472) && (v12 & 1) == 0 )
    goto LABEL_51;
  v9 = *(_QWORD *)(v4 + 400);
  if ( !v9 )
    goto LABEL_51;
LABEL_175:
  _X10 = (unsigned int *)(v9 + 80);
  __asm { PRFM            #0x11, [X10] }
  do
  {
    v87 = __ldxr(_X10);
    v88 = v87 - 1;
  }
  while ( __stlxr(v88, _X10) );
  __dmb(0xBu);
  if ( (v88 & 0x80000000) != 0 )
  {
    __break(0x800u);
    v13 = *(_QWORD *)(v9 + 152);
    if ( !v13 )
      goto LABEL_50;
LABEL_49:
    _X9 = (unsigned int *)(v13 - 32);
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v94 = __ldxr(_X9);
      v95 = v94 - 1;
    }
    while ( __stlxr(v95, _X9) );
    __dmb(0xBu);
    if ( (v95 & 0x80000000) != 0 )
      __break(0x800u);
    goto LABEL_50;
  }
  v13 = *(_QWORD *)(v9 + 152);
  if ( v13 )
    goto LABEL_49;
LABEL_50:
  cfg80211_put_bss(*(_QWORD *)v4, (_QWORD *)(*(_QWORD *)(v4 + 400) + 112LL));
  v12 = *(unsigned __int16 *)(v4 + 1472);
  *(_QWORD *)(v4 + 400) = 0;
LABEL_51:
  if ( v12 )
  {
    v14 = 472;
    v15 = 1;
    while ( 1 )
    {
      if ( ((v12 >> v15) & 1) == 0 )
        goto LABEL_59;
      v16 = *(_QWORD *)(v4 + v14);
      if ( !v16 )
        goto LABEL_59;
      _X10 = (unsigned int *)(v16 + 80);
      __asm { PRFM            #0x11, [X10] }
      do
      {
        v20 = __ldxr(_X10);
        v21 = v20 - 1;
      }
      while ( __stlxr(v21, _X10) );
      __dmb(0xBu);
      if ( (v21 & 0x80000000) != 0 )
      {
        __break(0x800u);
        v17 = *(_QWORD *)(v16 + 152);
        if ( v17 )
        {
LABEL_57:
          _X9 = (unsigned int *)(v17 - 32);
          __asm { PRFM            #0x11, [X9] }
          do
          {
            v24 = __ldxr(_X9);
            v25 = v24 - 1;
          }
          while ( __stlxr(v25, _X9) );
          __dmb(0xBu);
          if ( (v25 & 0x80000000) != 0 )
            __break(0x800u);
        }
      }
      else
      {
        v17 = *(_QWORD *)(v16 + 152);
        if ( v17 )
          goto LABEL_57;
      }
      cfg80211_put_bss(*(_QWORD *)v4, (_QWORD *)(*(_QWORD *)(v4 + v14) + 112LL));
      *(_QWORD *)(v4 + v14) = 0;
      v12 = *(unsigned __int16 *)(v4 + 1472);
LABEL_59:
      if ( v12 )
      {
        _CF = v15++ >= 0xE;
        v14 += 72;
        if ( !_CF )
          continue;
      }
      break;
    }
  }
  if ( *(_DWORD *)a2 )
  {
    kfree_sensitive(*(_QWORD *)(v4 + 88));
    *(_QWORD *)(v4 + 88) = 0;
    *(_BYTE *)(v4 + 318) = 0;
    *(_DWORD *)(v4 + 100) = 0;
    result = cfg80211_connect_result_release_bsses(v4, a2);
    v26 = *(_QWORD *)(v4 + 80);
    if ( v26 )
    {
      kfree(*(_QWORD *)(v26 + 416));
      result = kfree(*(_QWORD *)(v4 + 80));
      *(_QWORD *)(v4 + 80) = 0;
    }
    return result;
  }
  if ( v2 )
  {
    __break(0x800u);
    return cfg80211_connect_result_release_bsses(v4, a2);
  }
  v44 = v4 + 392;
  memset((void *)(v4 + 392), 0, 0x438u);
  v45 = *(unsigned __int16 *)(a2 + 104);
  v46 = 0;
  v47 = (int **)(a2 + 112);
  v48 = a2 + 128;
  v49 = *(_WORD *)(a2 + 104) == 0;
  do
  {
    if ( (v49 || (((unsigned __int64)v45 >> v46) & 1) != 0) && *(_WORD *)(v48 + 8) )
    {
      v50 = v45 & ~(unsigned int)(1LL << v46);
      *(_WORD *)(a2 + 104) = v45 & ~(unsigned __int16)(1LL << v46);
      v51 = *(_QWORD *)v48;
      if ( !*(_QWORD *)v48 )
      {
        v45 = (unsigned __int16)v50;
        goto LABEL_117;
      }
      _X10 = (unsigned int *)(v51 - 32);
      __asm { PRFM            #0x11, [X10] }
      do
      {
        v55 = __ldxr(_X10);
        v56 = v55 - 1;
      }
      while ( __stlxr(v56, _X10) );
      __dmb(0xBu);
      if ( (v56 & 0x80000000) != 0 )
      {
        __break(0x800u);
        v52 = *(_QWORD *)(v51 + 40);
        if ( !v52 )
          goto LABEL_115;
      }
      else
      {
        v52 = *(_QWORD *)(v51 + 40);
        if ( !v52 )
        {
LABEL_115:
          cfg80211_put_bss(*(_QWORD *)v4, *(_QWORD **)v48);
          v45 = *(unsigned __int16 *)(a2 + 104);
          goto LABEL_117;
        }
      }
      _X9 = (unsigned int *)(v52 - 32);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v59 = __ldxr(_X9);
        v60 = v59 - 1;
      }
      while ( __stlxr(v60, _X9) );
      __dmb(0xBu);
      if ( (v60 & 0x80000000) != 0 )
        __break(0x800u);
      goto LABEL_115;
    }
LABEL_117:
    v49 = v45 == 0;
    if ( !v45 )
      break;
    _CF = v46++ >= 0xE;
    v48 += 32;
  }
  while ( !_CF );
  *(_WORD *)(v4 + 1472) = v45;
  v61 = 0;
  v62 = (_QWORD *)(a2 + 128);
  v63 = *(unsigned __int16 *)(a2 + 104);
  v64 = 400;
  v65 = *(_WORD *)(a2 + 104) == 0;
  do
  {
    if ( v65 || (((unsigned __int64)v63 >> v61) & 1) != 0 )
    {
      *(_QWORD *)(v4 + v64) = *v62 - 112LL;
      v63 = *(unsigned __int16 *)(a2 + 104);
    }
    v65 = v63 == 0;
    if ( !v63 )
      break;
    _CF = v61++ >= 0xE;
    v62 += 4;
    v64 += 72;
  }
  while ( !_CF );
  *(_BYTE *)(v4 + 164) |= 1u;
  *(_DWORD *)(v4 + 280) = *(_DWORD *)v3;
  *(_WORD *)(v4 + 284) = *(_WORD *)(v3 + 4);
  v66 = *(unsigned __int16 *)(a2 + 104);
  if ( *(_WORD *)(a2 + 104) )
  {
    v67 = 0;
    v68 = 0;
    do
    {
      if ( v68 || (((unsigned __int64)v66 >> v67) & 1) != 0 )
      {
        v69 = **v47;
        *(_WORD *)(v44 + 4) = *((_WORD *)*v47 + 2);
        *(_DWORD *)v44 = v69;
        v66 = *(unsigned __int16 *)(a2 + 104);
      }
      v68 = v66 == 0;
      if ( !v66 )
        break;
      _CF = v67++ >= 0xE;
      v47 += 4;
      v44 += 72;
    }
    while ( !_CF );
  }
  v70 = ((__int64 (__fastcall *)(__int64))cfg80211_upload_connect_keys)(v4);
  lock = (_BYTE *)_rcu_read_lock(v70);
  v72 = *(unsigned __int16 *)(a2 + 104);
  v73 = 0;
  v74 = (_QWORD *)(a2 + 128);
  v75 = *(_WORD *)(a2 + 104) == 0;
  while ( 1 )
  {
    if ( !v75 && (((unsigned __int64)v72 >> v73) & 1) == 0 )
      goto LABEL_148;
    lock = (_BYTE *)ieee80211_bss_get_elem(*v74, 7);
    if ( lock )
      break;
    v72 = *(unsigned __int16 *)(a2 + 104);
LABEL_148:
    v75 = v72 == 0;
    if ( v72 )
    {
      _CF = v73++ >= 0xE;
      v74 += 4;
      if ( !_CF )
        continue;
    }
    return _rcu_read_unlock(lock);
  }
  v76 = (unsigned __int8)lock[1];
  v77 = (char *)kmemdup_noprof(lock + 2, v76, 2080);
  result = _rcu_read_unlock(v77);
  if ( v77 )
  {
    regulatory_hint_country_ie(*(_QWORD *)v4, **(unsigned int **)*v74, v77, v76);
    result = kfree(v77);
    if ( !*(_BYTE *)(v4 + 318) )
    {
      lock = (_BYTE *)_rcu_read_lock(result);
      v78 = *(unsigned __int16 *)(a2 + 104);
      v79 = 0;
      v80 = (_QWORD *)(a2 + 128);
      v81 = *(_WORD *)(a2 + 104) == 0;
      while ( 1 )
      {
        if ( v81 || (((unsigned __int64)v78 >> v79) & 1) != 0 )
        {
          lock = (_BYTE *)ieee80211_bss_get_elem(*v80, 0);
          if ( lock )
          {
            v82 = (unsigned __int8)lock[1];
            if ( lock[1] )
              break;
          }
        }
        v78 = *(unsigned __int16 *)(a2 + 104);
        v81 = *(_WORD *)(a2 + 104) == 0;
        if ( *(_WORD *)(a2 + 104) )
        {
          _CF = v79++ >= 0xE;
          v80 += 4;
          if ( !_CF )
            continue;
        }
        return _rcu_read_unlock(lock);
      }
      v83 = lock;
      if ( (unsigned int)v82 >= 0x21 && (_cfg80211_connect_result___already_done_6 & 1) == 0 )
      {
        _cfg80211_connect_result___already_done_6 = 1;
        v84 = v82;
        _warn_printk(
          "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
          v82,
          "field \"wdev->u.client.ssid\" at ../soc-repo/net/wireless/sme.c:912",
          0x20u);
        v82 = v84;
        __break(0x800u);
      }
      lock = memcpy((void *)(v4 + 286), v83 + 2, v82);
      *(_BYTE *)(v4 + 318) = v83[1];
      return _rcu_read_unlock(lock);
    }
  }
  return result;
}
