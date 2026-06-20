__int64 __fastcall ieee80211_mgd_auth(__int64 a1, unsigned int ***a2)
{
  __int64 v2; // x8
  __int64 result; // x0
  __int64 v5; // x22
  __int64 v6; // x24
  __int16 v8; // w25
  __int64 v9; // x0
  unsigned int v10; // w21
  __int64 v11; // x1
  __int64 v12; // x0
  __int64 v13; // x0
  char v14; // w21
  __int64 v15; // x2
  __int64 v16; // x3
  unsigned __int64 v17; // x22
  __int64 v18; // x21
  unsigned __int64 v19; // x1
  __int64 v20; // x8
  int v21; // w9
  __int16 v22; // w8
  unsigned __int64 v23; // x8
  unsigned int **v24; // x8
  __int16 v25; // w9
  size_t v26; // x2
  size_t v27; // x1
  __int64 v28; // x8
  _BOOL4 v29; // w23
  size_t v30; // x2
  unsigned __int64 v31; // x8
  bool v32; // cf
  unsigned __int64 v33; // x8
  size_t v34; // x1
  size_t v35; // x2
  __int64 v36; // x8
  __int16 v37; // w10
  _BOOL8 v38; // x3
  __int64 v39; // x8
  int v40; // w0
  __int64 v41; // x8
  __int64 v42; // x8
  __int64 v43; // x1
  __int64 v44; // x2
  __int64 v45; // x3
  int v46; // w0
  int v47; // w20
  unsigned int v48; // w20
  unsigned __int64 StatusReg; // x23
  __int64 v50; // x26
  size_t v51; // [xsp+8h] [xbp-38h]
  __int64 v52; // [xsp+10h] [xbp-30h] BYREF
  _QWORD v53[3]; // [xsp+18h] [xbp-28h] BYREF
  __int16 v54; // [xsp+30h] [xbp-10h]
  __int64 v55; // [xsp+38h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *((unsigned int *)a2 + 9);
  if ( (unsigned int)v2 > 7 )
  {
    result = 4294967201LL;
    goto LABEL_5;
  }
  if ( *(_QWORD *)(a1 + 2488) )
  {
    result = 4294967280LL;
    goto LABEL_5;
  }
  v5 = (__int64)*a2;
  v6 = *(_QWORD *)(a1 + 1616);
  v8 = word_C1520[v2];
  v9 = ieee80211_freq_khz_to_channel(1000 * (**a2)[1]);
  v10 = v9;
  _rcu_read_lock(v9, v11);
  v12 = ieee80211_mgd_csa_present(a1, *(_QWORD *)(v5 + 16), v10, 0);
  if ( (v12 & 1) != 0 )
  {
    _rcu_read_unlock(v12);
    goto LABEL_85;
  }
  v13 = ieee80211_mgd_csa_present(a1, *(_QWORD *)(v5 + 24), v10, *(_BYTE *)(v5 + 83) & 1);
  v14 = v13;
  _rcu_read_unlock(v13);
  if ( (v14 & 1) != 0 )
  {
LABEL_85:
    printk(&unk_B8313, a1 + 1640, v15, v16);
    result = 4294967274LL;
    goto LABEL_5;
  }
  v17 = (unsigned __int64)a2[2] + (_QWORD)a2[8] + 72;
  v18 = _kmalloc_noprof(v17, 3520);
  if ( !v18 )
  {
LABEL_91:
    result = 4294967284LL;
    goto LABEL_5;
  }
  while ( 1 )
  {
    if ( v17 >= 0x30 )
      v19 = v17 - 48;
    else
      v19 = 0;
    if ( v19 <= 5 )
      goto LABEL_90;
    v20 = (__int64)a2[10];
    if ( !v20 )
      v20 = (__int64)(*a2 + 9);
    v21 = *(_DWORD *)v20;
    v22 = *(_WORD *)(v20 + 4);
    v52 = 0;
    *(_DWORD *)(v18 + 48) = v21;
    *(_WORD *)(v18 + 52) = v22;
    if ( v17 < 8 )
      goto LABEL_87;
    *(_QWORD *)v18 = *a2;
    if ( v17 < 0x2C || (v17 & 0xFFFFFFFFFFFFFFFCLL) == 0x2C )
      goto LABEL_87;
    v23 = (unsigned __int64)a2[8];
    *(_DWORD *)(v18 + 44) = *((char *)a2 + 72);
    if ( v23 >= 4 )
    {
      if ( *((_DWORD *)a2 + 9) == 4 )
      {
        if ( v17 < 0x36 )
          goto LABEL_87;
        if ( (v17 & 0xFFFFFFFFFFFFFFFELL) == 0x36 )
          goto LABEL_87;
        v24 = a2[7];
        *(_WORD *)(v18 + 54) = *(_WORD *)v24;
        if ( v17 < 0x38 || (v17 & 0xFFFFFFFFFFFFFFFELL) == 0x38 )
          goto LABEL_87;
        v25 = *((_WORD *)v24 + 1);
        v23 = (unsigned __int64)a2[8];
        *(_WORD *)(v18 + 56) = v25;
      }
      v26 = v23 - 4;
      if ( v17 >= 0x48 )
        v27 = v17 - 72;
      else
        v27 = 0;
      if ( v27 < v26 )
        goto LABEL_88;
      memcpy((void *)(v18 + 72), (char *)a2[7] + 4, v26);
      if ( v17 < 0x40 || (v17 & 0xFFFFFFFFFFFFFFF8LL) == 0x40 )
        goto LABEL_87;
      *(_QWORD *)(v18 + 64) = (char *)a2[8] + *(_QWORD *)(v18 + 64) - 4;
    }
    v28 = *(_QWORD *)(a1 + 2480);
    if ( v28 && *a2 == *(unsigned int ***)v28 )
    {
      v29 = *(_DWORD *)(v28 + 44) == *((char *)a2 + 72);
      if ( !a2[1] )
        goto LABEL_46;
    }
    else
    {
      v29 = 0;
      if ( !a2[1] )
        goto LABEL_46;
    }
    v30 = (size_t)a2[2];
    if ( v30 )
    {
      if ( v17 < 0x40 || (v17 & 0xFFFFFFFFFFFFFFF8LL) == 0x40 )
        goto LABEL_87;
      v31 = *(_QWORD *)(v18 + 64) + 72LL;
      v32 = v17 >= v31;
      v33 = v17 - v31;
      if ( v32 )
        v34 = v33;
      else
        v34 = 0;
      if ( v34 < v30 )
        goto LABEL_88;
      if ( (v17 & 0xFFFFFFFFFFFFFFF8LL) == 0x40 )
        goto LABEL_87;
      memcpy((void *)(v18 + 72 + *(_QWORD *)(v18 + 64)), a2[1], v30);
      *(_QWORD *)(v18 + 64) += a2[2];
    }
LABEL_46:
    if ( !a2[5] || !*((_BYTE *)a2 + 48) )
      goto LABEL_53;
    *(_BYTE *)(v18 + 37) = *((_BYTE *)a2 + 48);
    v35 = *((unsigned __int8 *)a2 + 48);
    *(_BYTE *)(v18 + 38) = *((_BYTE *)a2 + 49);
    if ( v17 - 24 >= v35 )
      break;
LABEL_88:
    _fortify_panic(17);
LABEL_89:
    __break(0x5512u);
LABEL_90:
    _fortify_panic(17);
    StatusReg = _ReadStatusReg(SP_EL0);
    v50 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &ieee80211_mgd_auth__alloc_tag;
    v17 = (unsigned __int64)a2[2] + (_QWORD)a2[8] + 72;
    v18 = _kmalloc_noprof(v17, 3520);
    *(_QWORD *)(StatusReg + 80) = v50;
    if ( !v18 )
      goto LABEL_91;
  }
  if ( (unsigned int)v35 >= 0xE && (ieee80211_mgd_auth___already_done_77 & 1) == 0 )
  {
    ieee80211_mgd_auth___already_done_77 = 1;
    v51 = v35;
    _warn_printk(
      "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
      v35,
      "field \"auth_data->key\" at ../soc-repo/net/mac80211/mlme.c:8493",
      0xDu);
    v35 = v51;
    __break(0x800u);
  }
  memcpy((void *)(v18 + 24), a2[5], v35);
LABEL_53:
  if ( (v17 & 0xFFFFFFFFFFFFFFFELL) == 0x14 )
    goto LABEL_87;
  v36 = *(_QWORD *)(a1 + 2480);
  *(_WORD *)(v18 + 20) = v8;
  if ( v36 )
  {
    if ( v29 && *((_DWORD *)a2 + 9) == 4 )
      *(_BYTE *)(v18 + 41) = *(_BYTE *)(v36 + 41);
    ieee80211_destroy_auth_data(a1, v29);
  }
  *(_QWORD *)(a1 + 2480) = v18;
  if ( !v29 || *((_DWORD *)a2 + 9) != 4 || *(_BYTE *)(v18 + 41) != 1 )
    goto LABEL_66;
  if ( v17 < 0x36 || (v17 & 0xFFFFFFFFFFFFFFFELL) == 0x36 )
  {
LABEL_87:
    __break(1u);
    goto LABEL_88;
  }
  if ( *(_WORD *)(v18 + 54) == 2 )
    ieee80211_mark_sta_auth(a1);
LABEL_66:
  if ( (*(_BYTE *)(a1 + 2477) & 8) != 0 )
  {
    v54 = 0;
    memset(v53, 0, sizeof(v53));
    printk(&unk_BA55E, a1 + 1640, a1 + 4802, v18 + 48);
    ieee80211_set_disassoc(a1, 0xC0u, 1u, 0, (__int64)v53);
    ieee80211_report_disconnect(a1, (__int64)v53, 26, 1, 1, 0);
  }
  v37 = *(_WORD *)(v18 + 52);
  *(_DWORD *)(a1 + 4802) = *(_DWORD *)(v18 + 48);
  *(_WORD *)(a1 + 4806) = v37;
  v38 = *((_BYTE *)*a2 + 104) == 1 && *(unsigned __int16 *)(v6 + 128) > 3u;
  v39 = ***a2;
  if ( (unsigned int)v39 >= 6 )
    goto LABEL_89;
  ieee80211_determine_our_sta_mode(a1, *(_QWORD *)(*(_QWORD *)(v6 + 72) + 8 * v39 + 328), 0, v38, &v52);
  v40 = ieee80211_prep_connection(a1, *a2, *((unsigned __int8 *)a2 + 72), a2[10], v29, &v52, 0);
  if ( v40 )
    goto LABEL_80;
  v41 = *((char *)a2 + 72);
  if ( (v41 & 0x8000000000000000LL) == 0 )
  {
    if ( (unsigned int)v41 <= 0xE )
    {
      v42 = *(_QWORD *)(a1 + 8 * v41 + 4568);
      goto LABEL_77;
    }
    goto LABEL_89;
  }
  v42 = a1 + 3616;
LABEL_77:
  if ( v42 )
  {
    printk(&unk_B9A61, a1 + 1640, v18 + 48, *(_QWORD *)(v42 + 944) + 28LL);
    v46 = ieee80211_auth_0((_QWORD *)a1, v43, v44, v45);
    if ( !v46 )
    {
      cfg80211_ref_bss(*(_QWORD *)(v6 + 72), *(_QWORD *)v18);
      result = 0;
      goto LABEL_5;
    }
    v47 = v46;
    sta_info_destroy_addr(a1, v18 + 48);
    v40 = v47;
  }
  else
  {
    __break(0x800u);
    v40 = -67;
  }
LABEL_80:
  v48 = v40;
  if ( !*(_WORD *)(a1 + 5800) )
  {
    *(_WORD *)(a1 + 4156) = 0;
    *(_DWORD *)(a1 + 4152) = 0;
    ieee80211_link_info_change_notify(a1, a1 + 3616, 128);
    ieee80211_link_release_channel((__int64 *)(a1 + 3616));
  }
  *(_QWORD *)(a1 + 2480) = 0;
  kfree(v18);
  result = v48;
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
