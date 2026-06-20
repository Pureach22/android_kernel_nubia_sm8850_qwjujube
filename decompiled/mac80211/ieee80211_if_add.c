__int64 __fastcall ieee80211_if_add(
        __int64 a1,
        const char *a2,
        unsigned int a3,
        unsigned __int64 *a4,
        unsigned int a5,
        __int64 a6)
{
  __int64 v7; // x21
  unsigned __int64 v12; // x25
  __int64 v13; // x23
  size_t v14; // x0
  unsigned __int64 v15; // x2
  unsigned __int64 v16; // x1
  unsigned __int64 v17; // x9
  __int16 v18; // w11
  __int64 v19; // x24
  signed int v20; // w25
  int v21; // w26
  __int64 v22; // x0
  __int16 v23; // w8
  unsigned int v24; // w0
  __int64 v25; // x2
  int v26; // w8
  __int64 v27; // x10
  __int64 v28; // x8
  __int64 v29; // x10
  int v30; // w9
  __int64 v31; // x8
  _QWORD *v32; // x1
  __int64 v33; // x9
  _QWORD *v34; // x8
  __int64 v35; // x11
  __int64 v36; // x8
  __int64 v37; // x10
  __int64 v38; // x8
  __int64 v39; // x10
  __int64 v40; // x8
  __int64 v41; // x10
  __int64 v42; // x8
  __int64 v43; // x10
  __int64 v44; // x8
  __int64 v45; // x10
  __int64 v46; // x8
  char v47; // w9
  char v48; // w9
  char v49; // w8
  __int64 v50; // x10
  __int64 v51; // x11
  __int64 v52; // x8
  int v53; // w8
  unsigned int v54; // w19
  __int64 result; // x0
  unsigned __int64 *v56; // x1
  __int64 v57; // x2

  v7 = a5;
  if ( (unsigned int)rtnl_is_locked() || (ieee80211_if_add___already_done & 1) != 0 )
  {
    if ( (_DWORD)v7 == 12 )
      goto LABEL_5;
  }
  else
  {
    ieee80211_if_add___already_done = 1;
    _warn_printk("RTNL: assertion failed at %s (%d)\n", "../soc-repo/net/mac80211/iface.c", 2066);
    __break(0x800u);
    if ( (_DWORD)v7 == 12 )
    {
LABEL_5:
      v12 = *(int *)(a1 + 112) + 5904LL;
      v13 = _kmalloc_noprof(v12, 3520);
      if ( v13 )
      {
        if ( v12 >= 0x648 && (v12 & 0xFFFFFFFFFFFFFFF8LL) != 0x648 )
        {
          *(_QWORD *)(v13 + 1608) = 0;
          v14 = strnlen(a2, 0x10u);
          if ( v14 == -1 )
          {
LABEL_86:
            _fortify_panic(2);
LABEL_87:
            _fortify_panic(7);
LABEL_88:
            _fortify_panic(17);
            _fortify_panic(16);
            goto LABEL_89;
          }
          if ( v14 == 16 )
            v15 = 16;
          else
            v15 = v14 + 1;
          if ( v15 >= 0x11 )
            goto LABEL_87;
          sized_strscpy(v13 + 1640, a2);
          ieee80211_assign_perm_addr(a1, v13 + 86, (unsigned int)v7);
          if ( v12 >= 0x16D2 )
            v16 = v12 - 5842;
          else
            v16 = 0;
          if ( v16 <= 5 )
            goto LABEL_88;
          v17 = v12 >> 1;
          v18 = *(_WORD *)(v13 + 90);
          *(_DWORD *)(v13 + 5842) = *(_DWORD *)(v13 + 86);
          *(_WORD *)(v13 + 5846) = v18;
          if ( v12 >> 1 >= 0xB6B && v12 >> 2 != 1209 )
          {
            *(_DWORD *)(v13 + 4836) = *(_DWORD *)(v13 + 5842);
            if ( v17 != 2923 && v17 != 2420 )
            {
              v19 = 0;
              *(_WORD *)(v13 + 4840) = *(_WORD *)(v13 + 5846);
              goto LABEL_35;
            }
          }
        }
        __break(1u);
        goto LABEL_86;
      }
      return 4294967284LL;
    }
  }
  if ( (_DWORD)v7 == 10 )
    goto LABEL_5;
  v20 = (*(_DWORD *)(a1 + 112) + 5911) & 0xFFFFFFF8;
  if ( (_DWORD)v7 == 4 || (_DWORD)v7 == 6 && (*(_BYTE *)a6 & 0x40) == 0 )
    v21 = 0;
  else
    v21 = *(_DWORD *)(a1 + 124) + 256;
  v22 = alloc_netdev_mqs((unsigned int)(v21 + v20), a2, a3, ieee80211_if_setup, 1, 1);
  if ( !v22 )
    return 4294967284LL;
  v19 = v22;
  atomic_store(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 1352LL), (unsigned __int64 *)(v22 + 280));
  *(_BYTE *)(v22 + 1372) = 2;
  v23 = *(_WORD *)(a1 + 1508);
  *(_WORD *)(v22 + 490) = 18;
  *(_WORD *)(v22 + 60) = v23 + 40;
  v24 = dev_alloc_name();
  if ( (v24 & 0x80000000) != 0 )
  {
LABEL_76:
    v54 = v24;
    free_netdev(v19);
    return v54;
  }
  ieee80211_assign_perm_addr(a1, v19 + 791, (unsigned int)v7);
  v25 = a6 + 8;
  v26 = *(_DWORD *)(a6 + 8);
  if ( (v26 & 1) != 0 || !(v26 | *(unsigned __int16 *)(a6 + 12)) )
    v25 = v19 + 791;
  dev_addr_mod(v19, 0, v25, 6);
  v27 = *(_QWORD *)(v19 + 1008);
  v13 = v19 + 2688;
  v28 = *(_QWORD *)(*(_QWORD *)(a1 + 72) + 488LL);
  *(_QWORD *)(v19 + 992) = v19 + 2704;
  *(_QWORD *)(v19 + 1472) = v28;
  LODWORD(v28) = *(_DWORD *)v27;
  LOWORD(v27) = *(_WORD *)(v27 + 4);
  *(_DWORD *)(v19 + 8530) = v28;
  *(_WORD *)(v19 + 8534) = v27;
  v29 = *(_QWORD *)(v19 + 304);
  v30 = *(_DWORD *)(v19 + 8530);
  *(_QWORD *)(v19 + 4328) = *(_QWORD *)(v19 + 296);
  LOWORD(v28) = *(_WORD *)(v19 + 8534);
  *(_DWORD *)(v19 + 7524) = v30;
  *(_WORD *)(v19 + 7528) = v28;
  *(_QWORD *)(v19 + 4336) = v29;
  if ( v21 )
    ieee80211_txq_init(v19 + 2688, 0, v13 + v20, 0);
  *(_QWORD *)(v19 + 4296) = v19;
LABEL_35:
  v31 = *(_QWORD *)(a1 + 72);
  *(_QWORD *)(v13 + 1616) = a1;
  *(_QWORD *)(v13 + 16) = v31;
  v12 = v13 + 16;
  ((void (__fastcall *)(__int64, __int64, __int64, __int64))ieee80211_link_init)(
    v13,
    0xFFFFFFFFLL,
    v13 + 3616,
    v13 + 4808);
  ieee80211_init_frag_cache(v13 + 1656);
  *(_QWORD *)(v13 + 1512) = v13 + 1512;
  *(_QWORD *)(v13 + 1520) = v13 + 1512;
  init_timer_key(v13 + 1568, &wiphy_delayed_work_timer, 0, 0, 0);
  *(_QWORD *)(v13 + 1536) = v13 + 1536;
  *(_QWORD *)(v13 + 1544) = v13 + 1536;
  v32 = (_QWORD *)(v13 + 2136);
  *(_QWORD *)(v13 + 1552) = ieee80211_delayed_tailroom_dec;
  v33 = *(_QWORD *)(*(_QWORD *)(a1 + 72) + 328LL);
  v34 = (_QWORD *)(v13 + 2070);
  if ( v33 )
  {
    *(_DWORD *)(v13 + 2040) = ~(-1 << *(_DWORD *)(v33 + 24));
    v35 = *(_QWORD *)(v33 + 33);
    *(_WORD *)(v13 + 2078) = *(_WORD *)(v33 + 41);
    *v34 = v35;
    ieee80211_get_vht_mask_from_cap(*(unsigned __int16 *)(v33 + 60), v32);
  }
  else
  {
    *(_DWORD *)(v13 + 2040) = 0;
    *v34 = 0;
    *(_WORD *)(v13 + 2078) = 0;
    *v32 = 0;
    *(_QWORD *)(v13 + 2144) = 0;
  }
  v36 = *(_QWORD *)(*(_QWORD *)(a1 + 72) + 336LL);
  if ( v36 )
  {
    *(_DWORD *)(v13 + 2044) = ~(-1 << *(_DWORD *)(v36 + 24));
    v37 = *(_QWORD *)(v36 + 33);
    *(_WORD *)(v13 + 2088) = *(_WORD *)(v36 + 41);
    *(_QWORD *)(v13 + 2080) = v37;
    ieee80211_get_vht_mask_from_cap(*(unsigned __int16 *)(v36 + 60), v13 + 2152);
  }
  else
  {
    *(_DWORD *)(v13 + 2044) = 0;
    *(_QWORD *)(v13 + 2080) = 0;
    *(_WORD *)(v13 + 2088) = 0;
    *(_QWORD *)(v13 + 2152) = 0;
    *(_QWORD *)(v13 + 2160) = 0;
  }
  v38 = *(_QWORD *)(*(_QWORD *)(a1 + 72) + 344LL);
  if ( v38 )
  {
    *(_DWORD *)(v13 + 2048) = ~(-1 << *(_DWORD *)(v38 + 24));
    v39 = *(_QWORD *)(v38 + 33);
    *(_WORD *)(v13 + 2098) = *(_WORD *)(v38 + 41);
    *(_QWORD *)(v13 + 2090) = v39;
    ieee80211_get_vht_mask_from_cap(*(unsigned __int16 *)(v38 + 60), v13 + 2168);
  }
  else
  {
    *(_DWORD *)(v13 + 2048) = 0;
    *(_WORD *)(v13 + 2098) = 0;
    *(_QWORD *)(v13 + 2090) = 0;
    *(_QWORD *)(v13 + 2168) = 0;
    *(_QWORD *)(v13 + 2176) = 0;
  }
  v40 = *(_QWORD *)(*(_QWORD *)(a1 + 72) + 352LL);
  if ( v40 )
  {
    *(_DWORD *)(v13 + 2052) = ~(-1 << *(_DWORD *)(v40 + 24));
    v41 = *(_QWORD *)(v40 + 33);
    *(_WORD *)(v13 + 2108) = *(_WORD *)(v40 + 41);
    *(_QWORD *)(v13 + 2100) = v41;
    ieee80211_get_vht_mask_from_cap(*(unsigned __int16 *)(v40 + 60), v13 + 2184);
  }
  else
  {
    *(_DWORD *)(v13 + 2052) = 0;
    *(_WORD *)(v13 + 2108) = 0;
    *(_QWORD *)(v13 + 2100) = 0;
    *(_QWORD *)(v13 + 2184) = 0;
    *(_QWORD *)(v13 + 2192) = 0;
  }
  v42 = *(_QWORD *)(*(_QWORD *)(a1 + 72) + 360LL);
  if ( v42 )
  {
    *(_DWORD *)(v13 + 2056) = ~(-1 << *(_DWORD *)(v42 + 24));
    v43 = *(_QWORD *)(v42 + 33);
    *(_WORD *)(v13 + 2118) = *(_WORD *)(v42 + 41);
    *(_QWORD *)(v13 + 2110) = v43;
    ieee80211_get_vht_mask_from_cap(*(unsigned __int16 *)(v42 + 60), v13 + 2200);
  }
  else
  {
    *(_DWORD *)(v13 + 2056) = 0;
    *(_WORD *)(v13 + 2118) = 0;
    *(_QWORD *)(v13 + 2110) = 0;
    *(_QWORD *)(v13 + 2200) = 0;
    *(_QWORD *)(v13 + 2208) = 0;
  }
  v44 = *(_QWORD *)(*(_QWORD *)(a1 + 72) + 368LL);
  if ( v44 )
  {
    *(_DWORD *)(v13 + 2060) = ~(-1 << *(_DWORD *)(v44 + 24));
    v45 = *(_QWORD *)(v44 + 33);
    *(_WORD *)(v13 + 2128) = *(_WORD *)(v44 + 41);
    *(_QWORD *)(v13 + 2120) = v45;
    ieee80211_get_vht_mask_from_cap(*(unsigned __int16 *)(v44 + 60), v13 + 2216);
  }
  else
  {
    *(_DWORD *)(v13 + 2060) = 0;
    *(_QWORD *)(v13 + 2120) = 0;
    *(_WORD *)(v13 + 2128) = 0;
    *(_QWORD *)(v13 + 2216) = 0;
    *(_QWORD *)(v13 + 2224) = 0;
  }
  v46 = *(_QWORD *)(v13 + 1616);
  *(_BYTE *)(v13 + 5850) = (__int64)(*(_QWORD *)(v46 + 96) << 45) >> 63;
  if ( (*(_QWORD *)(v46 + 96) & 0x40000) != 0 )
  {
    v47 = -1;
  }
  else
  {
    if ( *(unsigned __int16 *)(v46 + 128) <= 3u )
    {
      *(_BYTE *)(v13 + 5851) = 0;
      if ( (*(_QWORD *)(v46 + 96) & 0x40000) == 0 )
        goto LABEL_58;
LABEL_61:
      v48 = -1;
      goto LABEL_62;
    }
    v47 = 1;
  }
  *(_BYTE *)(v13 + 5851) = v47;
  if ( (*(_QWORD *)(v46 + 96) & 0x40000) != 0 )
    goto LABEL_61;
LABEL_58:
  if ( *(unsigned __int16 *)(v46 + 128) <= 3u )
  {
    *(_BYTE *)(v13 + 5852) = 0;
    if ( (*(_QWORD *)(v46 + 96) & 0x40000) == 0 )
      goto LABEL_63;
LABEL_66:
    v49 = -1;
    goto LABEL_67;
  }
  v48 = 2;
LABEL_62:
  *(_BYTE *)(v13 + 5852) = v48;
  if ( (*(_QWORD *)(v46 + 96) & 0x40000) != 0 )
    goto LABEL_66;
LABEL_63:
  if ( *(unsigned __int16 *)(v46 + 128) <= 3u )
  {
    *(_BYTE *)(v13 + 5853) = 0;
    goto LABEL_69;
  }
  v49 = 3;
LABEL_67:
  *(_BYTE *)(v13 + 5853) = v49;
LABEL_69:
  *(_BYTE *)(v13 + 5849) = -1;
  *(_DWORD *)(v13 + 4068) = 0x80000000;
  *(_DWORD *)(v13 + 4064) = *(_DWORD *)(a1 + 5156);
  ieee80211_setup_sdata(v13, v7);
  if ( v19 )
  {
    *(_BYTE *)(*(_QWORD *)(v19 + 992) + 65LL) = *(_DWORD *)(a6 + 4) != 0;
    if ( (_DWORD)v7 == 2 )
      *(_BYTE *)(v13 + 2524) = *(_DWORD *)(a6 + 4);
    v50 = *(_QWORD *)v19;
    v51 = *(_QWORD *)(v19 + 496);
    v52 = *(_QWORD *)(v19 + 184) | *(_QWORD *)(a1 + 160);
    *(_QWORD *)(v19 + 184) = v52;
    *(_QWORD *)v19 = v50 | 0x8000;
    *(_QWORD *)(v19 + 496) = v51 | v52 & 0x20006401D003BLL;
    *(_QWORD *)(v13 + 5864) = *(_QWORD *)(a1 + 160);
    netdev_set_default_ethtool_ops(v19, &ieee80211_ethtool_ops);
    *(_DWORD *)(v19 + 536) = 256;
    v53 = (_DWORD)v7 == 6 ? 0 : *(_DWORD *)(a1 + 176);
    *(_DWORD *)(v19 + 540) = v53;
    v24 = cfg80211_register_netdevice(v19);
    if ( v24 )
      goto LABEL_76;
  }
  v7 = 4648;
  mutex_lock(a1 + 4648);
  v56 = *(unsigned __int64 **)(a1 + 4624);
  v57 = a1 + 4616;
  if ( v13 != a1 + 4616 && v56 != (unsigned __int64 *)v13 && *v56 == v57 )
  {
    *(_QWORD *)v13 = v57;
    *(_QWORD *)(v13 + 8) = v56;
    atomic_store(v13, v56);
    *(_QWORD *)(a1 + 4624) = v13;
    goto LABEL_81;
  }
LABEL_89:
  _list_add_valid_or_report(v13, v56);
LABEL_81:
  mutex_unlock(a1 + v7);
  result = 0;
  if ( a4 )
    *a4 = v12;
  return result;
}
