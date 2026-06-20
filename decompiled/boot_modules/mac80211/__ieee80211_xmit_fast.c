__int64 __fastcall _ieee80211_xmit_fast(
        __int64 result,
        __int64 a2,
        __int64 *a3,
        __int64 a4,
        __int64 a5,
        int *a6,
        __int64 a7)
{
  __int64 v9; // x19
  __int64 v10; // x20
  __int64 v13; // x21
  int v14; // w27
  int v15; // w28
  __int64 v16; // x0
  __int64 v17; // x26
  __int64 v18; // x26
  unsigned __int16 *v19; // x9
  __int64 v20; // x8
  __int64 v21; // x13
  unsigned int v22; // w10
  unsigned int v23; // w11
  unsigned int v24; // w8
  unsigned int v25; // w9
  unsigned int v26; // w11
  unsigned int v27; // w8
  _QWORD *v28; // x11
  __int64 v29; // x8
  __int64 v30; // x10
  __int64 v31; // x1
  __int64 v32; // x13
  int v33; // w14
  __int64 **v34; // x9
  __int64 v35; // x13
  __int64 **v36; // t1
  int i; // w8
  int v38; // w10
  __int64 (__fastcall *v39)(_QWORD); // x8
  char v40; // w0
  __int64 v41; // x8
  int v42; // w8
  size_t v43; // x8
  __int64 v44; // x0
  __int16 v45; // w11
  __int16 v46; // w9
  int v47; // w8
  void *v48; // x0
  int v49; // w10
  int v50; // w8
  __int64 v51; // x10
  unsigned int v52; // w26
  __int64 v53; // x27
  int v54; // w9
  int v55; // w8
  __int64 v56; // x10
  unsigned __int16 *v57; // x26
  __int64 v58; // x8
  int v59; // w9
  __int16 v60; // w11
  __int64 v61; // x8
  int v62; // w8
  bool v63; // zf
  __int64 v64; // x8
  __int64 v65; // x8
  __int64 v66; // x3
  __int64 v67; // x2
  int v68; // w0
  __int64 *v69; // x8
  size_t n; // [xsp+8h] [xbp-88h]
  _QWORD *v71; // [xsp+10h] [xbp-80h]
  int v72; // [xsp+18h] [xbp-78h]
  char v73; // [xsp+18h] [xbp-78h]
  int v74; // [xsp+1Ch] [xbp-74h]
  int v75; // [xsp+20h] [xbp-70h]
  int v76; // [xsp+20h] [xbp-70h]
  int v77; // [xsp+24h] [xbp-6Ch]
  int v78; // [xsp+24h] [xbp-6Ch]
  unsigned int v79; // [xsp+28h] [xbp-68h]
  __int64 v80; // [xsp+28h] [xbp-68h]
  _QWORD *v81; // [xsp+28h] [xbp-68h]
  unsigned __int64 v82; // [xsp+30h] [xbp-60h]
  __int64 v83; // [xsp+30h] [xbp-60h]
  __int64 v84; // [xsp+38h] [xbp-58h]
  __int64 v85; // [xsp+40h] [xbp-50h] BYREF
  __int64 v86; // [xsp+48h] [xbp-48h] BYREF
  __int64 *v87; // [xsp+50h] [xbp-40h]
  __int64 v88; // [xsp+58h] [xbp-38h]
  __int64 v89; // [xsp+60h] [xbp-30h]
  __int64 v90; // [xsp+68h] [xbp-28h]
  __int64 v91; // [xsp+70h] [xbp-20h]
  __int64 v92; // [xsp+78h] [xbp-18h]
  __int64 v93; // [xsp+80h] [xbp-10h]
  __int64 v94; // [xsp+88h] [xbp-8h]

  v9 = a4;
  v10 = result;
  v94 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_QWORD *)(result + 1616);
  v92 = 0;
  v93 = 0;
  v14 = *((unsigned __int8 *)a3 + 8);
  v90 = 0;
  v91 = 0;
  v88 = 0;
  v89 = 0;
  v15 = *(_DWORD *)(v13 + 104);
  v86 = 0;
  v87 = nullptr;
  v85 = 0;
  if ( *(_DWORD *)(a4 + 236) == 1 )
  {
    if ( !a4 )
      goto LABEL_78;
    if ( (*((_WORD *)a3 + 7) & 0x80) == 0 )
      goto LABEL_58;
  }
  else
  {
    v16 = skb_clone(a4, 2080);
    if ( !v16 )
    {
LABEL_74:
      result = sk_skb_reason_drop(v16);
      goto LABEL_78;
    }
    v17 = v16;
    consume_skb(v9);
    v9 = v17;
    if ( (*((_WORD *)a3 + 7) & 0x80) == 0 )
      goto LABEL_58;
  }
  v18 = *(_QWORD *)(v10 + 1616);
  v19 = *(unsigned __int16 **)(a2 + 2720);
  v20 = *(_DWORD *)(v9 + 144) & 7;
  v21 = *(_QWORD *)(a2 + 8 * v20 + 2736);
  v22 = *v19;
  if ( (*(_QWORD *)(v18 + 96) & 0x800000000LL) != 0
    && (*(_BYTE *)(v10 + 5876) & 1) == 0
    && !*(_WORD *)(*(_QWORD *)(v9 + 216) + *(unsigned int *)(v9 + 212) + 4LL)
    && v21
    && (*(_QWORD *)(v21 - 8) & 4) == 0 )
  {
    v23 = v19[1];
    v75 = *(unsigned __int8 *)(v18 + 140);
    v77 = *(unsigned __int8 *)(a2 + 2717);
    v74 = *(_DWORD *)(v9 + 112);
    v24 = v19[v20 + 2];
    v84 = v21;
    if ( v22 >= v23 )
      v25 = v19[1];
    else
      v25 = *v19;
    if ( !v23 )
      v25 = v22;
    if ( v25 >= v24 )
      v26 = v24;
    else
      v26 = v25;
    if ( v24 )
      v27 = v26;
    else
      v27 = v25;
    v79 = v27;
    if ( (*(_BYTE *)(v9 + 130) & 6) == 0 )
      _skb_get_hash_net(0, v9);
    v82 = (*(unsigned int *)(v18 + 244) * (unsigned __int64)*(unsigned int *)(v9 + 152)) >> 32;
    raw_spin_lock_bh(v18 + 240);
    v28 = (_QWORD *)(*(_QWORD *)(v18 + 208) + 56LL * (unsigned int)v82);
    v29 = *v28;
    if ( *v28 )
    {
      v30 = v84;
      if ( v29 != v84 - 232 )
      {
        ++*(_DWORD *)(v84 - 116);
        ++*(_DWORD *)(v18 + 276);
        v28 = (_QWORD *)(v84 - 184);
        v29 = *(_QWORD *)(v84 - 184);
      }
    }
    else
    {
      v30 = v84;
    }
    if ( !v29 )
      ++*(_DWORD *)(v30 - 112);
    v31 = v28[4];
    if ( (_QWORD *)v31 == v28 + 3 )
      goto LABEL_57;
    if ( !v31 )
      goto LABEL_57;
    v32 = *(_QWORD *)(v31 + 216) + *(unsigned int *)(v31 + 212);
    if ( *(_WORD *)(v32 + 4) || *(_DWORD *)(v9 + 112) + *(_DWORD *)(v31 + 112) > v79 )
      goto LABEL_57;
    v33 = 2;
    v36 = *(__int64 ***)(v32 + 8);
    v35 = v32 + 8;
    v34 = v36;
    for ( i = *(unsigned __int8 *)(*(_QWORD *)(v9 + 216) + *(unsigned int *)(v9 + 212) + 2LL)
            + *(unsigned __int8 *)(v35 - 6)
            + 2; v34; i += v38 + 1 )
    {
      v35 = (__int64)v34;
      ++v33;
      v38 = *((unsigned __int8 *)v34[27] + *((unsigned int *)v34 + 53) + 2);
      v34 = (__int64 **)*v34;
    }
    if ( v77 && v33 > v77 || v75 && i > v75 )
      goto LABEL_57;
    v71 = v28;
    v76 = *(_DWORD *)(v31 + 232);
    v78 = *(_DWORD *)(v31 + 112);
    v39 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v18 + 464) + 808LL);
    v80 = v35;
    v83 = v28[4];
    v72 = v33;
    if ( v39 )
    {
      if ( *((_DWORD *)v39 - 1) != -1637983678 )
        __break(0x8228u);
      if ( (v39(v18) & 1) == 0 )
        goto LABEL_57;
    }
    v40 = ieee80211_amsdu_prepare_head(v10, a3, v83);
    v41 = v80;
    if ( (v40 & 1) == 0 )
    {
LABEL_57:
      raw_spin_unlock_bh(v18 + 240);
    }
    else
    {
      if ( v72 == 2 )
        v41 = *(_QWORD *)(v83 + 216) + *(unsigned int *)(v83 + 212) + 8LL;
      v81 = (_QWORD *)v41;
      v42 = *(_DWORD *)(v83 + 112) - (*((unsigned __int8 *)a3 + 8) ^ 2);
      if ( (v42 & 3) != 0 )
        v43 = 4 - (v42 & 3u);
      else
        v43 = 0;
      n = v43;
      v73 = ieee80211_amsdu_realloc_pad(v18, v9, (unsigned int)v43 | 8);
      if ( (v73 & 1) != 0 )
      {
        v44 = skb_push(v9, 8);
        *(_DWORD *)v44 = *a6;
        v45 = *((_WORD *)&rfc1042_header + 2);
        *(_WORD *)(v44 + 4) = *((_WORD *)a6 + 2);
        *(_DWORD *)(v44 + 6) = *(_DWORD *)a7;
        v46 = *(_WORD *)(a7 + 4);
        *(_WORD *)(v44 + 12) = bswap32(v74 - 6) >> 16;
        v47 = rfc1042_header;
        *(_WORD *)(v44 + 18) = v45;
        *(_WORD *)(v44 + 10) = v46;
        *(_DWORD *)(v44 + 14) = v47;
        v48 = (void *)skb_push(v9, n);
        memset(v48, 0, n);
        v49 = *(_DWORD *)(v83 + 116);
        *(_DWORD *)(v83 + 112) += *(_DWORD *)(v9 + 112);
        *(_DWORD *)(v83 + 116) = v49 + *(_DWORD *)(v9 + 112);
        *v81 = v9;
      }
      *(_DWORD *)(v18 + 256) += *(_DWORD *)(v83 + 232) - v76;
      v50 = *(_DWORD *)(v83 + 112) - v78;
      if ( v50 )
      {
        *((_DWORD *)v71 + 12) += v50;
        *(_DWORD *)(v84 - 128) += *(_DWORD *)(v83 + 112) - v78;
      }
      result = raw_spin_unlock_bh(v18 + 240);
      if ( (v73 & 1) != 0 )
        goto LABEL_78;
    }
  }
LABEL_58:
  v51 = *(_QWORD *)(v9 + 216);
  v52 = v14 - 12;
  v53 = *(_QWORD *)(v10 + 1616);
  v54 = *(_DWORD *)(v9 + 224) - v51;
  v55 = v52 + v15 - v54;
  if ( (*(_BYTE *)(v9 + 126) & 1) == 0
    || (v56 = v51 + *(unsigned int *)(v9 + 212), (unsigned __int16)*(_DWORD *)(v56 + 32) == 1) )
  {
    if ( v55 < 1 )
      goto LABEL_67;
LABEL_66:
    if ( (unsigned int)pskb_expand_head(v9, v55 & (unsigned int)~(v55 >> 31), 0, 2080) )
    {
      dev_printk(&unk_BBEF5, *(_QWORD *)(v53 + 72) + 392LL, "failed to reallocate TX buffer\n");
      goto LABEL_73;
    }
    goto LABEL_67;
  }
  if ( (*(_QWORD *)(v53 + 96) & 0x8000000) == 0
    || (unsigned __int16)*(_DWORD *)(v56 + 32) - (*(int *)(v56 + 32) >> 16) != 1
    || v54 + 14 > (unsigned int)*(unsigned __int16 *)(v9 + 122)
    || v55 > 0 )
  {
    goto LABEL_66;
  }
LABEL_67:
  v57 = (unsigned __int16 *)skb_push(v9, v52);
  memcpy(*(void **)(v9 + 224), (char *)a3 + 14, *((unsigned __int8 *)a3 + 8));
  v58 = *(_QWORD *)(v9 + 224) + *((unsigned __int8 *)a3 + 10);
  v59 = *a6;
  *(_WORD *)(v58 + 4) = *((_WORD *)a6 + 2);
  *(_DWORD *)v58 = v59;
  v60 = *(_WORD *)(a7 + 4);
  v61 = *(_QWORD *)(v9 + 224) + *((unsigned __int8 *)a3 + 9);
  *(_DWORD *)v61 = *(_DWORD *)a7;
  *(_WORD *)(v61 + 4) = v60;
  *(_QWORD *)(v9 + 40) = 0;
  *(_QWORD *)(v9 + 48) = 0;
  *(_QWORD *)(v9 + 56) = 0;
  *(_QWORD *)(v9 + 64) = 0;
  *(_QWORD *)(v9 + 72) = 0;
  *(_QWORD *)(v9 + 80) = 0;
  LOBYTE(v61) = *((_BYTE *)a3 + 12);
  *(_QWORD *)(v9 + 64) = v10 + 4720;
  *(_DWORD *)(v9 + 40) = 1073741840;
  *(_DWORD *)(v9 + 44) = v61 & 7;
  *(_DWORD *)(v9 + 80) = -268435440;
  v62 = *v57;
  if ( (v62 & 0x80) != 0 )
  {
    v63 = (~v62 & 0x300) == 0;
    v64 = 12;
    if ( v63 )
      v64 = 15;
    LOBYTE(v57[v64]) = *(_BYTE *)(v9 + 144) & 7;
  }
  HIDWORD(v93) = 2;
  v65 = *a3;
  LODWORD(v88) = 0;
  v86 = (__int64)&v86;
  v87 = &v86;
  v89 = v13;
  v90 = v10;
  v91 = a2;
  v92 = v65;
  result = ieee80211_queue_skb(v13, v10, a2, v9);
  if ( (result & 1) == 0 )
  {
    v66 = *a3;
    v67 = *((unsigned __int8 *)a3 + 11);
    v85 = v9;
    v68 = ieee80211_xmit_fast_finish(v10, a2, v67, v66, &v85);
    v85 = 0;
    if ( v68 )
    {
LABEL_73:
      v16 = 0;
      goto LABEL_74;
    }
    if ( *(_DWORD *)(v10 + 4720) == 4 )
      v10 = *(_QWORD *)(v10 + 2032) - 2264LL;
    v69 = v87;
    *(_QWORD *)v9 = &v86;
    *(_QWORD *)(v9 + 8) = v69;
    v87 = (__int64 *)v9;
    *v69 = v9;
    LODWORD(v88) = v88 + 1;
    result = ieee80211_tx_frags(v13, v10 + 4720, a2, &v86, 0);
  }
LABEL_78:
  _ReadStatusReg(SP_EL0);
  return result;
}
