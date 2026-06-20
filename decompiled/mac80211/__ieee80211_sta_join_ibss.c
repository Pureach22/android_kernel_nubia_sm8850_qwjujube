_QWORD *__fastcall _ieee80211_sta_join_ibss(
        __int64 a1,
        int *a2,
        __int16 a3,
        __int64 a4,
        unsigned int a5,
        __int16 a6,
        __int64 a7,
        char a8)
{
  __int64 v10; // x20
  __int64 v14; // x21
  __int64 v17; // x0
  __int64 v18; // x1
  __int64 v19; // x8
  unsigned int *v20; // x22
  __int64 v21; // x9
  __int64 v22; // x10
  __int64 v23; // x0
  __int64 v24; // x2
  __int64 v25; // x3
  __int64 v26; // x0
  unsigned int v27; // w9
  int v28; // w0
  int v29; // w24
  int v30; // w9
  _QWORD *result; // x0
  _QWORD *v32; // x23
  size_t v33; // x2
  __int64 v34; // x25
  __int64 v35; // x24
  __int64 v36; // x8
  __int64 (__fastcall *v37)(__int64, __int64); // x8
  int v38; // w0
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x3
  __int64 v42; // x0
  void *v43; // x0
  __int64 v44; // x9
  __int64 v45; // x1
  _WORD *v46; // x8
  unsigned int v47; // w20
  __int64 v48; // x3
  size_t v49; // x27
  _BYTE v51[4]; // [xsp+Ch] [xbp-94h] BYREF
  unsigned int *v52; // [xsp+10h] [xbp-90h] BYREF
  __int64 v53; // [xsp+18h] [xbp-88h]
  __int64 v54; // [xsp+20h] [xbp-80h]
  __int64 v55; // [xsp+28h] [xbp-78h]
  __int64 v56; // [xsp+30h] [xbp-70h]
  __int64 v57; // [xsp+38h] [xbp-68h]
  __int64 v58; // [xsp+40h] [xbp-60h]
  __int64 v59; // [xsp+48h] [xbp-58h]
  int v60; // [xsp+54h] [xbp-4Ch] BYREF
  __int64 v61; // [xsp+58h] [xbp-48h]
  _QWORD v62[8]; // [xsp+60h] [xbp-40h] BYREF

  v10 = a1 + 2346;
  v62[7] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(_QWORD *)(a1 + 1616);
  v58 = 0;
  v59 = 0;
  v56 = 0;
  v57 = 0;
  v54 = 0;
  v55 = 0;
  v52 = nullptr;
  v53 = 0;
  memset(v62, 0, 56);
  v51[0] = 0;
  drv_reset_tsf(v14, a1);
  if ( *a2 ^ *(_DWORD *)v10 | *((unsigned __int16 *)a2 + 2) ^ *(unsigned __int16 *)(a1 + 2350) )
    _sta_info_flush(a1, 0, 0xFFFFFFFFLL);
  if ( *(_BYTE *)(v10 + 2383) == 1 )
  {
    v17 = *(_QWORD *)(a1 + 1608);
    *(_BYTE *)(v10 + 2510) = 0;
    *(_WORD *)(v10 + 2383) = 0;
    netif_carrier_off(v17);
    ieee80211_bss_info_change_notify(a1, 2560);
    drv_leave_ibss(v14, a1);
  }
  v18 = *(_QWORD *)(a1 + 2440);
  *(_QWORD *)(a1 + 2440) = 0;
  if ( v18 )
    kvfree_call_rcu(v18 + 56, v18);
  v20 = *(unsigned int **)a4;
  v19 = *(_QWORD *)(a4 + 8);
  v21 = *(_QWORD *)(a4 + 16);
  v22 = *(_QWORD *)(a4 + 24);
  v23 = *(_QWORD *)(v14 + 72);
  v61 = 0;
  v52 = v20;
  v53 = v19;
  v54 = v21;
  v55 = v22;
  v60 = 1;
  if ( (cfg80211_reg_check_beaconing(v23, &v52, &v60) & 1) == 0 )
  {
    if ( (unsigned int)v53 <= 7 && ((1 << v53) & 0xC3) != 0
      || (v26 = *(_QWORD *)(v14 + 72),
          LODWORD(v53) = 1,
          v27 = v20[1],
          v60 = 1,
          v61 = 0,
          HIDWORD(v53) = v27,
          (cfg80211_reg_check_beaconing(v26, &v52, &v60) & 1) == 0) )
    {
      v43 = &unk_B799D;
LABEL_34:
      result = (_QWORD *)printk(v43, a1 + 1640, v24, v25);
      goto LABEL_35;
    }
  }
  v28 = cfg80211_chandef_dfs_required(*(_QWORD *)(*(_QWORD *)(a1 + 1616) + 72LL), &v52, 1);
  if ( v28 < 0 )
  {
    v43 = &unk_BAE9A;
    goto LABEL_34;
  }
  v29 = v28;
  if ( v28 && (*(_BYTE *)(a1 + 2344) & 1) == 0 )
  {
    v43 = &unk_BBB77;
    goto LABEL_34;
  }
  if ( (unsigned int)ieee80211_link_use_channel(a1 + 3616, (__int64 *)&v52, *(unsigned __int8 *)(a1 + 2341) ^ 1u, 0) )
  {
    v43 = &unk_B91E6;
    goto LABEL_34;
  }
  *(_BYTE *)(a1 + 4072) = v29 != 0;
  v30 = *a2;
  *(_WORD *)(v10 + 4) = *((_WORD *)a2 + 2);
  *(_DWORD *)v10 = v30;
  result = (_QWORD *)ieee80211_ibss_build_presp(a1, a3, a5, a6, a7, &v52, v51, nullptr);
  if ( result )
  {
    atomic_store((unsigned __int64)result, (unsigned __int64 *)(a1 + 2440));
    v32 = result;
    v33 = *(unsigned __int8 *)(a1 + 2384);
    v34 = *result;
    *(_DWORD *)(a1 + 4880) = a5;
    *(_BYTE *)(v10 + 2510) = 1;
    *(_WORD *)(a1 + 4858) = a3;
    *(_QWORD *)(a1 + 4792) = v33;
    if ( v33 >= 0x21 && (_ieee80211_sta_join_ibss___already_done_38 & 1) == 0 )
    {
      _ieee80211_sta_join_ibss___already_done_38 = 1;
      v49 = v33;
      _warn_printk(
        "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
        v33,
        "field \"sdata->vif.cfg.ssid\" at ../soc-repo/net/mac80211/ibss.c:322",
        0x20u);
      v33 = v49;
      __break(0x800u);
    }
    memcpy((void *)(a1 + 4760), (const void *)(a1 + 2352), v33);
    v35 = ieee80211_reset_erp_info(a1);
    *(_BYTE *)(v10 + 2509) = *v20 == 1;
    *(_BYTE *)(a1 + 3752) = (*v20 == 0) & v51[0];
    ieee80211_set_wmm_default(a1 + 3616, 1, 0);
    v36 = *(_QWORD *)(a1 + 1616);
    *(_BYTE *)(v10 + 2383) = 1;
    *(_BYTE *)(v10 + 2384) = a8 & 1;
    if ( (*(_BYTE *)(v36 + 1471) & 1) != 0
      || (*(_DWORD *)(a1 + 1624) & 0x20) != 0
      || (drv_join_ibss___already_done & 1) != 0 )
    {
      if ( (*(_BYTE *)(a1 + 1624) & 0x20) != 0 )
        goto LABEL_23;
    }
    else
    {
      v44 = *(_QWORD *)(a1 + 1608);
      drv_join_ibss___already_done = 1;
      if ( v44 )
        v45 = v44 + 296;
      else
        v45 = a1 + 1640;
      _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v45);
      __break(0x800u);
      if ( (*(_BYTE *)(a1 + 1624) & 0x20) != 0 )
      {
LABEL_23:
        v37 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(v14 + 464) + 696LL);
        if ( v37 )
        {
          if ( *((_DWORD *)v37 - 1) != 844051912 )
            __break(0x8228u);
          v38 = v37(v14, a1 + 4720);
        }
        else
        {
          v38 = 0;
        }
        if ( !v38 )
        {
          ieee80211_bss_info_change_notify(a1, v35 | 0x8BF8);
          *(_DWORD *)(a1 + 2520) = 1;
          v39 = round_jiffies(jiffies + 7500LL);
          mod_timer(a1 + 2264, v39);
          v40 = *(_QWORD *)(v14 + 72);
          v41 = *((int *)v32 + 4);
          v62[0] = v20;
          v42 = cfg80211_inform_bss_frame_data(v40, v62, v34, v41, 3264);
          cfg80211_put_bss(*(_QWORD *)(v14 + 72), v42);
          netif_carrier_on(*(_QWORD *)(a1 + 1608));
          result = (_QWORD *)cfg80211_ibss_joined(*(_QWORD *)(a1 + 1608), v10, v20, 3264);
          goto LABEL_35;
        }
LABEL_41:
        v46 = (_WORD *)(v10 + 2383);
        *(_BYTE *)(v10 + 2510) = 0;
        v47 = v38;
        *v46 = 0;
        *(_QWORD *)(a1 + 4792) = 0;
        *(_QWORD *)(a1 + 2440) = 0;
        kvfree_call_rcu(v32 + 7, v32);
        ieee80211_link_release_channel((__int64 *)(a1 + 3616));
        result = (_QWORD *)printk(&unk_BC518, a1 + 1640, v47, v48);
        goto LABEL_35;
      }
    }
    v38 = -5;
    goto LABEL_41;
  }
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
