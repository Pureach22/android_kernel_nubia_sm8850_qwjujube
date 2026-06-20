__int64 __fastcall cfg80211_connect(_BYTE **a1, __int64 a2, __int64 a3, __int64 a4, int *a5)
{
  unsigned __int64 v5; // x25
  _BYTE *v8; // x23
  __int64 v10; // x19
  size_t v11; // x2
  int *v12; // x24
  int v13; // w0
  __int64 result; // x0
  int *v15; // x28
  size_t v16; // x1
  unsigned int v17; // w9
  __int64 v18; // x10
  int v19; // w8
  int v20; // w9
  int v21; // w10
  size_t v22; // x2
  _DWORD *v23; // x8
  __int64 v24; // x8
  unsigned int v25; // w8
  __int64 v26; // x9
  __int64 v27; // x8
  __int64 v28; // x23
  unsigned __int64 v29; // x25
  __int64 v30; // x9
  __int64 v31; // x8
  unsigned int v34; // w8
  unsigned int v35; // w8
  unsigned int v38; // w8
  unsigned int v39; // w8
  char v40; // w8
  char v41; // w8
  __int64 v42; // x9
  int *v43; // x8
  int v44; // w8
  __int64 v45; // x26
  char *v46; // x24
  __int64 v47; // x0
  __int64 v48; // x0
  size_t v49; // x27
  size_t v50; // x2
  unsigned __int64 v51; // x8
  unsigned __int64 v52; // x8
  size_t v53; // x9
  size_t v54; // x2
  __int64 v55; // x8
  __int64 v56; // x8
  __int64 *bss; // x0
  __int64 v58; // x2
  __int64 v59; // x8
  int v60; // w10
  __int64 v61; // x8
  int v62; // w10
  __int64 *v63; // x20
  __int64 v64; // x9
  unsigned int v65; // w21
  __int64 v66; // x8
  unsigned int v67; // w20
  size_t v68; // x24
  unsigned __int64 v69; // x21
  __int64 v70; // x0
  __int64 v71; // x1
  __int64 v72; // x2
  __int64 v73; // x8
  unsigned __int64 StatusReg; // x23
  __int64 v75; // x24
  __int64 v76; // x0
  unsigned int v79; // w8
  unsigned int v80; // w8
  unsigned int v87; // w8
  unsigned int v88; // w8
  char *dest; // [xsp+8h] [xbp-18h]
  int v90; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v91; // [xsp+18h] [xbp-8h]

  v8 = (_BYTE *)a2;
  v91 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a2 + 992);
  v11 = *(unsigned __int8 *)(v10 + 318);
  if ( *(_BYTE *)(v10 + 318) )
  {
    if ( *(_QWORD *)(a3 + 40) != v11 )
      goto LABEL_10;
    v12 = a5;
    v13 = bcmp((const void *)(v10 + 286), *(const void **)(a3 + 32), v11);
    a5 = v12;
    if ( v13 )
      goto LABEL_10;
  }
  if ( (*(_BYTE *)(v10 + 164) & 1) == 0 )
    goto LABEL_5;
  if ( !a5 )
  {
LABEL_10:
    result = 4294967182LL;
    goto LABEL_11;
  }
  if ( *(_DWORD *)(v10 + 280) ^ *a5 | *(unsigned __int16 *)(v10 + 284) ^ *((unsigned __int16 *)a5 + 2) )
  {
    result = 4294967189LL;
    goto LABEL_11;
  }
LABEL_5:
  if ( *(_QWORD *)(v10 + 88) )
  {
    result = 4294967181LL;
    goto LABEL_11;
  }
  v15 = a5;
  cfg80211_oper_and_ht_capa((_BYTE *)(a3 + 246), a1[289]);
  cfg80211_oper_and_vht_capa((_BYTE *)(a3 + 284), a1[290]);
  if ( a4 )
  {
    v17 = *(_DWORD *)(a4 + 212);
    if ( (v17 & 0x80000000) != 0 )
    {
      __break(0x800u);
      result = 4294967274LL;
      goto LABEL_11;
    }
    if ( v17 >= 4 )
    {
      __break(0x5512u);
      goto LABEL_109;
    }
    v18 = a4 + 40LL * v17;
    v19 = *(_DWORD *)(v18 + 28);
    if ( (v19 & 0xFFFFFFFB) == 0xFAC01 )
    {
      *(_BYTE *)(a3 + 209) = v17;
      *(_QWORD *)(a3 + 200) = *(_QWORD *)v18;
      v20 = *(_DWORD *)(v18 + 16);
      v21 = *(_DWORD *)(a3 + 84);
      *(_BYTE *)(a3 + 208) = v20;
      if ( !v21 )
        *(_DWORD *)(a3 + 84) = v19;
      if ( !*(_DWORD *)(a3 + 88) )
      {
        *(_DWORD *)(a3 + 88) = 1;
        *(_DWORD *)(a3 + 92) = v19;
      }
    }
  }
  else
  {
    *(_QWORD *)(a3 + 200) = 0;
    *(_WORD *)(a3 + 208) = 0;
  }
  *(_QWORD *)(v10 + 88) = a4;
  v22 = *(_QWORD *)(a3 + 40);
  if ( v22 >= 0x21 && (cfg80211_connect___already_done & 1) == 0 )
  {
    cfg80211_connect___already_done = 1;
    v68 = v22;
    _warn_printk(
      "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
      v22,
      "field \"wdev->u.client.ssid\" at ../soc-repo/net/wireless/sme.c:1520",
      0x20u);
    v22 = v68;
    __break(0x800u);
  }
  memcpy((void *)(v10 + 286), *(const void **)(a3 + 32), v22);
  *(_BYTE *)(v10 + 318) = *(_QWORD *)(a3 + 40);
  *(_DWORD *)(v10 + 96) = *(unsigned __int8 *)(a3 + 296);
  if ( *((_QWORD *)*a1 + 46) )
  {
LABEL_25:
    v23 = *((_DWORD **)*a1 + 46);
    if ( *(v23 - 1) != -1422413864 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(_BYTE **, _BYTE *, __int64))v23)(a1 + 124, v8, a3);
    if ( (_DWORD)result )
      goto LABEL_60;
    goto LABEL_11;
  }
  if ( !*(_QWORD *)v10 )
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v75 = *(_QWORD *)(StatusReg + 80);
    v76 = register_netdevice_notifier;
    *(_QWORD *)(StatusReg + 80) = &cfg80211_sme_connect__alloc_tag;
    a1 = (_BYTE **)_kmalloc_cache_noprof(v76, 3520, 440);
    *(_QWORD *)(StatusReg + 80) = v75;
    *(_QWORD *)(v10 + 80) = a1;
    if ( a1 )
      goto LABEL_69;
LABEL_116:
    result = 4294967284LL;
    goto LABEL_60;
  }
  v24 = *(_QWORD *)(*(_QWORD *)v10 - 992LL);
  if ( !*(_QWORD *)(v24 + 336) || !*(_QWORD *)(v24 + 344) )
  {
    result = 4294967201LL;
    goto LABEL_60;
  }
  v25 = *(unsigned __int16 *)(v10 + 1472);
  if ( *(_WORD *)(v10 + 1472) && (v25 & 1) == 0 )
  {
LABEL_40:
    v28 = 472;
    v29 = 1;
    while ( 1 )
    {
      if ( ((v25 >> v29) & 1) == 0 )
        goto LABEL_47;
      v30 = *(_QWORD *)(v10 + v28);
      if ( !v30 )
        goto LABEL_47;
      _X10 = (unsigned int *)(v30 + 80);
      __asm { PRFM            #0x11, [X10] }
      do
      {
        v34 = __ldxr(_X10);
        v35 = v34 - 1;
      }
      while ( __stlxr(v35, _X10) );
      __dmb(0xBu);
      if ( (v35 & 0x80000000) != 0 )
      {
        __break(0x800u);
        v31 = *(_QWORD *)(v30 + 152);
        if ( v31 )
        {
LABEL_45:
          _X9 = (unsigned int *)(v31 - 32);
          __asm { PRFM            #0x11, [X9] }
          do
          {
            v38 = __ldxr(_X9);
            v39 = v38 - 1;
          }
          while ( __stlxr(v39, _X9) );
          __dmb(0xBu);
          if ( (v39 & 0x80000000) != 0 )
            __break(0x800u);
        }
      }
      else
      {
        v31 = *(_QWORD *)(v30 + 152);
        if ( v31 )
          goto LABEL_45;
      }
      cfg80211_put_bss(*(_QWORD *)v10, (_QWORD *)(*(_QWORD *)(v10 + v28) + 112LL));
      *(_QWORD *)(v10 + v28) = 0;
      v25 = *(unsigned __int16 *)(v10 + 1472);
LABEL_47:
      if ( v25 )
      {
        _CF = v29++ >= 0xE;
        v28 += 72;
        if ( !_CF )
          continue;
      }
      goto LABEL_62;
    }
  }
  v26 = *(_QWORD *)(v10 + 400);
  if ( !v26 )
    goto LABEL_39;
  while ( 1 )
  {
    _X10 = (unsigned int *)(v26 + 80);
    __asm { PRFM            #0x11, [X10] }
    do
    {
      v79 = __ldxr(_X10);
      v80 = v79 - 1;
    }
    while ( __stlxr(v80, _X10) );
    __dmb(0xBu);
    if ( (v80 & 0x80000000) != 0 )
    {
      __break(0x800u);
      v27 = *(_QWORD *)(v26 + 152);
      if ( v27 )
      {
LABEL_37:
        _X9 = (unsigned int *)(v27 - 32);
        __asm { PRFM            #0x11, [X9] }
        do
        {
          v87 = __ldxr(_X9);
          v88 = v87 - 1;
        }
        while ( __stlxr(v88, _X9) );
        __dmb(0xBu);
        if ( (v88 & 0x80000000) != 0 )
          __break(0x800u);
      }
    }
    else
    {
      v27 = *(_QWORD *)(v26 + 152);
      if ( v27 )
        goto LABEL_37;
    }
    cfg80211_put_bss(*(_QWORD *)v10, (_QWORD *)(*(_QWORD *)(v10 + 400) + 112LL));
    v25 = *(unsigned __int16 *)(v10 + 1472);
    *(_QWORD *)(v10 + 400) = 0;
LABEL_39:
    if ( v25 )
      goto LABEL_40;
LABEL_62:
    v41 = *(_BYTE *)(v10 + 164);
    v42 = *(_QWORD *)(v10 + 80);
    if ( (v41 & 1) != 0 )
    {
      if ( v42 )
      {
        kfree(*(_QWORD *)(v42 + 416));
        kfree(*(_QWORD *)(v10 + 80));
        v41 = *(_BYTE *)(v10 + 164);
        *(_QWORD *)(v10 + 80) = 0;
      }
      *(_BYTE *)(v10 + 164) = v41 & 0xFE;
    }
    else if ( v42 )
    {
      result = 4294967181LL;
      goto LABEL_60;
    }
    a1 = (_BYTE **)_kmalloc_cache_noprof(register_netdevice_notifier, 3520, 440);
    *(_QWORD *)(v10 + 80) = a1;
    if ( !a1 )
      goto LABEL_116;
LABEL_69:
    memcpy(a1, (const void *)a3, 0x190u);
    v43 = *(int **)(a3 + 16);
    if ( v43 )
    {
      a1[2] = (char *)a1 + 404;
      v26 = *((unsigned __int16 *)v43 + 2);
      v44 = *v43;
      *((_WORD *)a1 + 204) = v26;
      *((_DWORD *)a1 + 101) = v44;
    }
    v45 = *(_QWORD *)v10;
    if ( *(_QWORD *)v10 )
      break;
    __break(0x800u);
  }
  v46 = *(char **)(a3 + 56);
  v8 = *(_BYTE **)(a3 + 64);
  if ( *(_BYTE *)(v45 + 296)
    && (!v46 || !cfg80211_find_elem_match(0x7Fu, *(unsigned __int8 **)(a3 + 56), (unsigned int)v8, nullptr, 0, 0)) )
  {
    v5 = (unsigned __int64)&v8[*(unsigned __int8 *)(v45 + 296) + 2];
    v48 = _kmalloc_noprof(v5, 3264);
    if ( !v48 )
      goto LABEL_126;
    dest = (char *)v48;
    if ( v8 )
    {
      v49 = ieee80211_ie_split_ric(v46, v8, "0.F6;H", 6, 0, 0, 0);
      if ( v5 < v49 )
      {
LABEL_111:
        _fortify_panic(17, v5);
        v69 = _ReadStatusReg(SP_EL0);
        if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                         + (((unsigned __int64)*(unsigned int *)(v69 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(v69 + 40))
            & 1) != 0 )
        {
          ++*(_DWORD *)(v69 + 16);
          v70 = _traceiter_rdev_connect(0, a1 + 124, v8, a3);
          v73 = *(_QWORD *)(v69 + 16) - 1LL;
          *(_DWORD *)(v69 + 16) = v73;
          if ( !v73 || !*(_QWORD *)(v69 + 16) )
            preempt_schedule_notrace(v70, v71, v72);
        }
        goto LABEL_25;
      }
      memcpy(dest, v46, v49);
      v50 = (size_t)&v8[-v49];
      v51 = v49 + *(unsigned __int8 *)(v45 + 296) + 2;
      _CF = v5 >= v51;
      v52 = v5 - v51;
      if ( _CF )
        v16 = v52;
      else
        v16 = 0;
      if ( v16 < v50 )
      {
LABEL_110:
        _fortify_panic(17, v16);
        goto LABEL_111;
      }
      memcpy(&dest[v49 + 2 + *(unsigned __int8 *)(v45 + 296)], &v46[v49], v50);
    }
    else
    {
      v49 = 0;
    }
    if ( (v49 & 0x8000000000000000LL) == 0 && v5 > v49 )
    {
      v53 = v49 + 1;
      dest[v49] = 127;
      if ( (__int64)(v49 + 1) >= 0 && v5 != v53 && v5 > v49 )
      {
        v54 = *(unsigned __int8 *)(v45 + 296);
        dest[v53] = v54;
        if ( v5 >= v49 + 2 )
          v16 = v5 - (v49 + 2);
        else
          v16 = 0;
        if ( v16 >= v54 )
        {
          memcpy(&dest[v49 + 2], *(const void **)(v45 + 280), v54);
          a1[52] = dest;
          v8 += *(unsigned __int8 *)(v45 + 296) + 2;
          goto LABEL_96;
        }
        goto LABEL_110;
      }
    }
LABEL_109:
    __break(1u);
    goto LABEL_110;
  }
  v47 = kmemdup_noprof(v46, v8, 3264);
  a1[52] = (_BYTE *)v47;
  if ( !v47 )
  {
LABEL_126:
    v67 = -12;
LABEL_127:
    kfree(*(_QWORD *)(v10 + 80));
    *(_QWORD *)(v10 + 80) = 0;
    result = v67;
    goto LABEL_60;
  }
LABEL_96:
  a1[8] = v8;
  *(_QWORD *)(*(_QWORD *)(v10 + 80) + 56LL) = *(_QWORD *)(*(_QWORD *)(v10 + 80) + 416LL);
  v55 = *(_QWORD *)(v10 + 80);
  if ( *(_DWORD *)(a3 + 48) == 8 )
  {
    *(_BYTE *)(v55 + 432) = 1;
    *(_DWORD *)(*(_QWORD *)(v10 + 80) + 48LL) = 0;
  }
  else
  {
    *(_BYTE *)(v55 + 432) = 0;
  }
  *(_QWORD *)(*(_QWORD *)(v10 + 80) + 32LL) = v10 + 286;
  *(_QWORD *)(*(_QWORD *)(v10 + 80) + 40LL) = *(unsigned __int8 *)(v10 + 318);
  v56 = *(_QWORD *)(v10 + 80);
  bss = _cfg80211_get_bss(
          *(_QWORD *)v10,
          *(_DWORD **)v56,
          *(_QWORD *)(v56 + 16),
          *(void **)(v56 + 32),
          *(_QWORD *)(v56 + 40),
          *(_DWORD *)(v10 + 96),
          *(unsigned __int8 *)(v56 + 72) ^ 1u,
          1);
  if ( v15 )
  {
    v59 = *(_QWORD *)(v10 + 80);
    v60 = *v15;
    *(_WORD *)(v59 + 414) = *((_WORD *)v15 + 2);
    *(_DWORD *)(v59 + 410) = v60;
    *(_BYTE *)(*(_QWORD *)(v10 + 80) + 433LL) = 1;
  }
  if ( bss )
  {
    v61 = *(_QWORD *)(v10 + 80);
    v62 = *((_DWORD *)bss + 18);
    v63 = bss;
    *(_WORD *)(v61 + 408) = *((_WORD *)bss + 38);
    *(_DWORD *)(v61 + 404) = v62;
    *(_QWORD *)(v61 + 16) = v61 + 404;
    v64 = *bss;
    *(_DWORD *)(v61 + 400) = 2;
    *(_QWORD *)v61 = v64;
    v65 = cfg80211_conn_do_work((__int64 *)v10, &v90, v58);
    cfg80211_put_bss(*(_QWORD *)v10, v63);
    result = v65;
LABEL_105:
    if ( (_DWORD)result )
    {
      v66 = *(_QWORD *)(v10 + 80);
      if ( v66 )
      {
        v67 = result;
        kfree(*(_QWORD *)(v66 + 416));
        goto LABEL_127;
      }
LABEL_60:
      v40 = *(_BYTE *)(v10 + 164);
      *(_QWORD *)(v10 + 88) = 0;
      if ( (v40 & 1) == 0 )
        *(_BYTE *)(v10 + 318) = 0;
    }
  }
  else
  {
    result = cfg80211_conn_scan(v10);
    if ( (_DWORD)result != -16 )
      goto LABEL_105;
    result = 0;
    *(_DWORD *)(*(_QWORD *)(v10 + 80) + 400LL) = 1;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
