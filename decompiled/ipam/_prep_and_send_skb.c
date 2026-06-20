__int64 __fastcall prep_and_send_skb(
        __int64 a1,
        __int64 a2,
        int a3,
        char a4,
        __int64 a5,
        __int64 a6,
        unsigned int a7,
        unsigned int a8,
        unsigned __int8 a9,
        char a10)
{
  _DWORD *v17; // x25
  __int64 v18; // x28
  __int64 result; // x0
  size_t v20; // x21
  const void *v21; // x22
  size_t v22; // x27
  const void *v23; // x28
  size_t v24; // x20
  __int64 v25; // x0
  void *v26; // x0
  _WORD *v27; // x21
  _DWORD *v28; // x20
  int v29; // w9
  unsigned int v30; // w8
  __int64 v31; // x22
  _DWORD *v32; // x27
  const void *v33; // x20
  unsigned int v34; // t1
  void *v35; // x0
  int v36; // w11
  __int64 v37; // x13
  int v38; // w8
  __int64 v39; // x9
  unsigned int v40; // w26
  __int64 v41; // x20
  unsigned int *v42; // x12
  unsigned __int64 v43; // x10
  unsigned __int64 v44; // x11
  int v45; // w13
  unsigned int v46; // t1
  __int64 v47; // x1
  unsigned __int64 v48; // t2
  unsigned int v49; // w8
  __int16 v50; // w8
  __int64 v51; // x8
  __int64 v52; // x11
  int v53; // w9
  __int64 v54; // x9
  __int64 v55; // x8
  __int64 v56; // x8
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x8
  __int64 v60; // x0
  __int64 v61; // x0
  __int64 v62; // x8
  __int64 v63; // x0
  void *src; // [xsp+0h] [xbp-30h]
  __int64 v65; // [xsp+8h] [xbp-28h]
  __int64 v66; // [xsp+10h] [xbp-20h]
  char v67; // [xsp+1Ch] [xbp-14h]
  int v68; // [xsp+20h] [xbp-10h]
  int v69; // [xsp+24h] [xbp-Ch]
  int v70; // [xsp+28h] [xbp-8h]

  raw_spin_lock(ipa3_ctx + 32048);
  if ( !*(_DWORD *)a2 )
  {
LABEL_5:
    v18 = 0;
    v17 = nullptr;
    goto LABEL_7;
  }
  v17 = *(_DWORD **)(a2 + 376);
  if ( v17 )
  {
    if ( !*(_DWORD *)(a2 + 456) )
    {
      v18 = *(_QWORD *)(a2 + 368);
      goto LABEL_7;
    }
    goto LABEL_5;
  }
  v18 = 0;
LABEL_7:
  result = raw_spin_unlock(ipa3_ctx + 32048);
  if ( !v17 )
    return result;
  v69 = *(unsigned __int8 *)(a5 + 12);
  v70 = *(unsigned __int8 *)(a5 + 28);
  if ( a1 )
  {
    ++*(_QWORD *)(ipa3_ctx + 33856);
    goto LABEL_24;
  }
  v66 = a6;
  v67 = a4;
  v68 = a3;
  v20 = *(unsigned int *)(a5 + 8);
  v21 = *(const void **)(a5 + 16);
  src = *(void **)(a5 + 32);
  v22 = *(unsigned int *)(a5 + 40);
  v65 = v18;
  v23 = *(const void **)a5;
  v24 = *(unsigned int *)(a5 + 24);
  v25 = _alloc_skb(*(_DWORD *)(a5 + 44) + a8, 2080, 0, 0xFFFFFFFFLL);
  if ( v25 )
  {
    a1 = v25;
    ++*(_QWORD *)(ipa3_ctx + 33864);
    *(_WORD *)(v25 + 180) = v70;
    v26 = (void *)skb_put(v25, (unsigned int)v20);
    memcpy(v26, v23, v20);
    *(_WORD *)(a1 + 186) = *(_WORD *)(a1 + 224) - *(_DWORD *)(a1 + 216);
    v27 = (_WORD *)skb_put(a1, (unsigned int)v24);
    memcpy(v27, v21, v24);
    if ( v69 == 4 )
    {
      v27[2] = bswap32((bswap32((unsigned __int16)v27[2]) >> 16) + a9) >> 16;
      v27[1] = bswap32(v22 + a8 + v24) >> 16;
    }
    else
    {
      v27[2] = bswap32(v22 + a8) >> 16;
    }
    a4 = v67;
    a3 = v68;
    v18 = v65;
    *(_WORD *)(a1 + 184) = *(_WORD *)(a1 + 224) - *(_DWORD *)(a1 + 216);
    v28 = (_DWORD *)skb_put(a1, (unsigned int)v22);
    memcpy(v28, src, v22);
    if ( v70 == 6 )
    {
      if ( a8 <= 1 )
        v29 = 1;
      else
        v29 = a8;
      v30 = *(_DWORD *)(a5 + 48) + v29;
      *(_DWORD *)(a5 + 48) = v30;
      v28[1] = bswap32(v30);
    }
    else
    {
      *((_WORD *)v28 + 2) = bswap32(a8 + 8) >> 16;
    }
    a6 = v66;
    *(_WORD *)(a1 + 182) = *(_WORD *)(a1 + 224) - *(_DWORD *)(a1 + 216);
    if ( a7 )
    {
      v31 = a7;
      v32 = (_DWORD *)(v66 + 8);
      do
      {
        v33 = *((const void **)v32 - 1);
        v34 = *v32;
        v32 += 4;
        v35 = (void *)skb_put(a1, v34);
        memcpy(v35, v33, v34);
        --v31;
      }
      while ( v31 );
      a4 = v67;
      a3 = v68;
      a6 = v66;
    }
LABEL_24:
    if ( (a10 & 1) == 0 )
    {
LABEL_34:
      v51 = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212);
      *(_WORD *)(v51 + 6) = a7;
      *(_WORD *)(v51 + 4) = *(_DWORD *)(a6 + 8);
      if ( v70 == 6 )
      {
        v52 = 34072;
        if ( v69 == 4 )
          v53 = 1;
        else
          v53 = 16;
        *(_DWORD *)(v51 + 24) = v53;
        v54 = 34064;
      }
      else
      {
        v52 = 34088;
        *(_DWORD *)(v51 + 24) = 0x20000;
        v54 = 34080;
      }
      v55 = ipa3_ctx;
      ++*(_QWORD *)(ipa3_ctx + v54);
      *(_QWORD *)(v55 + v52) += a8;
      *(_BYTE *)(a1 + 44) = a4;
      v56 = ipa3_ctx;
      *(_WORD *)(a1 + 40) = HIWORD(a3);
      if ( v56 )
      {
        v57 = *(_QWORD *)(v56 + 34160);
        if ( !v57
          || (ipc_log_string(
                v57,
                "ipa %s:%d meta_data: 0x%x cb: 0x%x\n",
                "_prep_and_send_skb",
                4922,
                a3,
                *(_DWORD *)(a1 + 40)),
              (v56 = ipa3_ctx) != 0) )
        {
          v58 = *(_QWORD *)(v56 + 34160);
          if ( v58 )
            ipc_log_string(v58, "ipa %s:%d ucp: %d\n", "_prep_and_send_skb", 4923, *(unsigned __int8 *)(a1 + 44));
        }
      }
      if ( *(v17 - 1) != 420538815 )
        __break(0x8239u);
      return ((__int64 (__fastcall *)(__int64, _QWORD, __int64))v17)(v18, 0, a1);
    }
    if ( !a5 )
    {
      printk(&unk_3BDDFF, "_calc_partial_csum");
      v59 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v60 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v60 )
        {
          ipc_log_string(
            v60,
            "ipa %s:%d NULL args: skb(%p) and/or hdr_data(%p)\n",
            "_calc_partial_csum",
            4676,
            (const void *)a1,
            nullptr);
          v59 = ipa3_ctx;
        }
        v61 = *(_QWORD *)(v59 + 34160);
        if ( v61 )
          ipc_log_string(
            v61,
            "ipa %s:%d NULL args: skb(%p) and/or hdr_data(%p)\n",
            "_calc_partial_csum",
            4676,
            (const void *)a1,
            nullptr);
      }
      goto LABEL_34;
    }
    v36 = *(unsigned __int8 *)(a5 + 12);
    v37 = *(unsigned int *)(a5 + 24);
    v38 = *(_DWORD *)(a5 + 40);
    v39 = *(_QWORD *)(a1 + 224) + *(unsigned int *)(a5 + 8);
    v40 = *(unsigned __int8 *)(a5 + 28);
    v41 = v39 + v37;
    *(_BYTE *)(a1 + 128) |= 0x60u;
    if ( v36 == 4 )
    {
      *(_WORD *)(v39 + 10) = 0;
      v42 = (unsigned int *)(v39 + 16);
      v43 = *(_QWORD *)(v39 + 8);
      v44 = v43 + __CFADD__(v43, *(_QWORD *)v39) + *(_QWORD *)v39;
      v45 = (*(_BYTE *)v39 & 0xF) - 3;
      do
      {
        v46 = *v42++;
        --v45;
        v44 += v46;
      }
      while ( v45 > 1 );
      v47 = *(unsigned int *)(v39 + 16);
      HIDWORD(v48) = (__ROR8__(v44, 32) + v44) >> 32;
      LODWORD(v48) = HIDWORD(v48);
      *(_WORD *)(v39 + 10) = ~(((unsigned int)(v48 >> 16) + HIDWORD(v48)) >> 16);
      HIDWORD(v48) = csum_tcpudp_nofold(HIDWORD(v43), v47, v38 + a8, v40, 0);
      LODWORD(v48) = HIDWORD(v48);
      v49 = ((unsigned int)(v48 >> 16) + HIDWORD(v48)) >> 16;
      if ( v40 != 6 )
        goto LABEL_30;
    }
    else
    {
      LOWORD(v49) = ~(unsigned __int16)csum_ipv6_magic(v39 + 8, v39 + 24, v38 + a8, v40, 0);
      if ( v40 != 6 )
      {
LABEL_30:
        *(_WORD *)(v41 + 6) = v49;
        v50 = 6;
LABEL_33:
        *(_WORD *)(a1 + 142) = v50;
        goto LABEL_34;
      }
    }
    *(_WORD *)(v41 + 16) = v49;
    v50 = 16;
    goto LABEL_33;
  }
  result = printk(&unk_3CC7B5, "_prep_and_send_skb");
  v62 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v63 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v63 )
    {
      ipc_log_string(v63, "ipa %s:%d skb alloc failure\n", "_prep_and_send_skb", 4816);
      v62 = ipa3_ctx;
    }
    result = *(_QWORD *)(v62 + 34160);
    if ( result )
      return ipc_log_string(result, "ipa %s:%d skb alloc failure\n", "_prep_and_send_skb", 4816);
  }
  return result;
}
