__int64 __fastcall _qdf_nbuf_sw_tso_prepare_nbuf_list(__int64 a1, __int64 a2, __int64 *a3, __int64 a4)
{
  __int64 tso_num_seg; // x0
  __int64 v8; // x4
  int v9; // w20
  int v10; // w19
  __int64 v11; // x8
  __int64 v12; // x23
  int v13; // w22
  int v14; // w24
  int v15; // w8
  int v16; // w9
  int *v17; // x8
  unsigned int v18; // w20
  bool v19; // nf
  __int64 v20; // x9
  __int64 v21; // x10
  __int64 v22; // x8
  int v23; // w10
  unsigned int v24; // w22
  int v25; // w19
  char *v26; // x28
  unsigned int v27; // w26
  __int64 *v28; // x25
  unsigned int v29; // w24
  __int64 v30; // x27
  unsigned __int64 v31; // x0
  __int64 v32; // x8
  __int64 dma_addr; // x0
  unsigned __int64 v34; // x8
  __int64 v35; // x0
  __int64 v36; // x10
  __int64 v37; // x9
  __int64 v38; // x10
  __int64 v39; // x11
  __int64 v40; // x12
  __int64 *v41; // x8
  int v42; // w25
  __int64 v43; // x11
  __int16 v44; // w9
  unsigned __int16 v45; // w8
  __int16 v46; // w10
  __int16 v47; // w12
  __int64 v48; // x10
  __int64 v49; // x11
  __int64 v50; // x8
  __int16 v51; // x8^2
  __int64 v52; // x9
  __int64 v53; // x9
  unsigned int v54; // w8
  unsigned int v55; // w10
  unsigned int v56; // w23
  unsigned int v57; // w9
  bool v58; // cf
  __int64 v59; // x11
  __int64 v60; // x11
  __int64 v61; // x11
  __int64 v62; // x12
  __int64 v63; // t1
  __int64 v64; // x13
  _QWORD *v65; // x0
  void (*v66)(void); // x8
  _QWORD *v67; // x20
  _QWORD *v68; // x0
  void (*v69)(void); // x8
  _QWORD *v70; // x20
  __int64 result; // x0
  unsigned int v72; // [xsp+Ch] [xbp-44h]
  __int64 v73; // [xsp+10h] [xbp-40h]
  __int64 v74; // [xsp+18h] [xbp-38h]
  __int64 *v75; // [xsp+20h] [xbp-30h]
  size_t v76; // [xsp+28h] [xbp-28h]
  int v77; // [xsp+30h] [xbp-20h]
  unsigned int v78; // [xsp+34h] [xbp-1Ch]
  unsigned __int64 v79; // [xsp+38h] [xbp-18h]
  unsigned int v80; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v81; // [xsp+48h] [xbp-8h]

  v81 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v78 = *(unsigned __int16 *)(*(_QWORD *)(a2 + 216) + *(unsigned int *)(a2 + 212) + 4LL);
  tso_num_seg = _qdf_nbuf_get_tso_num_seg(a2);
  v9 = *(unsigned __int16 *)(a2 + 180);
  v10 = *(_DWORD *)(a2 + 112);
  v11 = *(unsigned __int16 *)(a2 + 120);
  v74 = a4;
  if ( v9 != 43144 && v9 != 129 )
    goto LABEL_22;
  if ( *(_WORD *)(a2 + 120) )
  {
    if ( (unsigned int)v11 <= 3 )
    {
      v9 = 0;
      __break(0x800u);
      *a3 = 0;
      if ( (_DWORD)tso_num_seg )
        goto LABEL_23;
      goto LABEL_95;
    }
    v12 = v11 - 4;
  }
  else
  {
    v12 = 14;
  }
  v13 = 0;
  v14 = -(int)v12;
  v15 = *(_DWORD *)(a2 + 112);
  while ( 1 )
  {
    v16 = *(_DWORD *)(a2 + 116);
    v80 = 0;
    if ( v14 + v13 + v15 - v16 < 4 )
      break;
    v17 = (int *)(*(_QWORD *)(a2 + 224) + v12);
    if ( !v17 )
      goto LABEL_20;
LABEL_11:
    if ( v13 == -28 )
      goto LABEL_20;
    v9 = *((unsigned __int16 *)v17 + 1);
    if ( v9 != 43144 && v9 != 129 )
      goto LABEL_21;
    v15 = *(_DWORD *)(a2 + 112);
    v12 += 4;
    v13 -= 4;
  }
  if ( a2 )
  {
    v18 = tso_num_seg;
    v19 = (int)skb_copy_bits(a2, (unsigned int)v12, &v80, 4) < 0;
    tso_num_seg = v18;
    v17 = v19 ? nullptr : (int *)&v80;
    if ( v17 )
      goto LABEL_11;
  }
LABEL_20:
  v9 = 0;
LABEL_21:
  a4 = v74;
LABEL_22:
  *a3 = 0;
  if ( !(_DWORD)tso_num_seg )
  {
LABEL_95:
    qdf_trace_msg(56, 2, "%s: sw tso: failed to prepare skb list for tso packet", "__qdf_nbuf_sw_tso_prepare_nbuf_list");
LABEL_96:
    result = 16;
    goto LABEL_97;
  }
LABEL_23:
  v20 = *(_QWORD *)(a2 + 216);
  v21 = *(unsigned __int16 *)(a2 + 182);
  v77 = tso_num_seg;
  v22 = v20 + v21;
  v23 = ((*(unsigned __int16 *)(v20 + v21 + 12) >> 2) & 0x3C) + v21 - *(unsigned __int16 *)(a2 + 186);
  v24 = *(_DWORD *)(a2 + 112) - *(_DWORD *)(a2 + 116) - v23;
  v25 = v10 - v23;
  v26 = (char *)(*(_QWORD *)(a2 + 224) + v23);
  v75 = a3;
  v76 = v23;
  if ( v24 >= v78 )
    v27 = v78;
  else
    v27 = *(_DWORD *)(a2 + 112) - *(_DWORD *)(a2 + 116) - v23;
  if ( v9 == 8 )
    v72 = bswap32(*(unsigned __int16 *)(v20 + *(unsigned __int16 *)(a2 + 184) + 4)) >> 16;
  else
    v72 = 0;
  v28 = nullptr;
  v79 = 0;
  v29 = bswap32(*(_DWORD *)(v22 + 4));
  v73 = v23 + v78;
  while ( 2 )
  {
    if ( a4
      && (v80 = 0, tso_num_seg = _qdf_page_pool_empty(a4), (tso_num_seg & 1) == 0)
      && (tso_num_seg = _qdf_nbuf_page_pool_alloc(
                          tso_num_seg,
                          v73,
                          0,
                          0,
                          a4,
                          &v80,
                          "qdf_tx_page_pool_nbuf_alloc_map",
                          4886)) != 0 )
    {
      v30 = tso_num_seg;
      v31 = ((unsigned __int64)(((__int64)(*(_QWORD *)(tso_num_seg + 224) << 8) >> 8) + 0x8000000000LL) >> 12 << 6)
          - 0x140000000LL;
      v32 = *(_QWORD *)(v31 + 8);
      if ( (v32 & 1) != 0 )
        v31 = v32 - 1;
      dma_addr = _qdf_page_pool_get_dma_addr(v31);
      v34 = dma_addr + v80 + (unsigned __int64)(unsigned int)(*(_DWORD *)(v30 + 224) - *(_DWORD *)(v30 + 216));
      *(_QWORD *)(v30 + 40) = v34;
    }
    else
    {
      v35 = _qdf_nbuf_alloc(tso_num_seg, v73, 0, 0, v8, "__qdf_nbuf_sw_tso_prepare_nbuf_list", 4977);
      if ( !v35 )
      {
        qdf_trace_msg(56, 2, "%s: sw tso: failed to allocate buffer", "__qdf_nbuf_sw_tso_prepare_nbuf_list");
        qdf_nbuf_list_free(*v75);
        result = 2;
        goto LABEL_97;
      }
      v34 = *(_QWORD *)(v35 + 40);
      v30 = v35;
    }
    *(_QWORD *)(v30 + 16) = 51931;
    v36 = *(_QWORD *)(a2 + 48);
    *(_QWORD *)(v30 + 40) = *(_QWORD *)(a2 + 40);
    *(_QWORD *)(v30 + 48) = v36;
    v38 = *(_QWORD *)(a2 + 72);
    v37 = *(_QWORD *)(a2 + 80);
    v39 = *(_QWORD *)(a2 + 56);
    v40 = *(_QWORD *)(a2 + 64);
    *(_QWORD *)(v30 + 40) = v34;
    *(_QWORD *)(v30 + 72) = v38;
    *(_QWORD *)(v30 + 80) = v37;
    *(_QWORD *)(v30 + 56) = v39;
    *(_QWORD *)(v30 + 64) = v40;
    if ( *v75 )
      v41 = v28;
    else
      v41 = v75;
    *v41 = v30;
    *(_QWORD *)v30 = 0;
    memcpy(*(void **)(v30 + 224), *(const void **)(a2 + 224), v76);
    memcpy((void *)(*(_QWORD *)(v30 + 224) + v76), v26, v27);
    v42 = v27 + v76;
    tso_num_seg = skb_put(v30, v27 + (unsigned int)v76);
    v43 = *(_QWORD *)(v30 + 216);
    v44 = *(_DWORD *)(v30 + 224) - v43;
    v45 = *(_WORD *)(a2 + 182) - *(_WORD *)(a2 + 186) + v44;
    *(_WORD *)(v30 + 182) = v45;
    v46 = *(_WORD *)(a2 + 184);
    v47 = *(_WORD *)(a2 + 186);
    *(_WORD *)(v30 + 186) = v44;
    *(_WORD *)(v30 + 184) = v46 - v47 + v44;
    *(_DWORD *)(v43 + v45 + 4) = bswap32(v29);
    LOBYTE(v44) = *(_BYTE *)(v30 + 128);
    v48 = *(_QWORD *)(v30 + 216);
    v49 = *(unsigned __int16 *)(v30 + 182);
    *(_WORD *)(v30 + 180) = *(_WORD *)(a2 + 180);
    *(_BYTE *)(v30 + 128) = v44 | 0x60;
    *(_WORD *)(v48 + v49 + 12) &= ~0x800u;
    v50 = *(_QWORD *)(v30 + 216) + *(unsigned __int16 *)(v30 + 182);
    *(_WORD *)(v50 + 12) &= ~0x100u;
    if ( v9 == 8 )
    {
      v51 = bswap32(v72++) >> 16;
      *(_WORD *)(*(_QWORD *)(v30 + 216) + *(unsigned __int16 *)(v30 + 184) + 4LL) = v51;
      *(_WORD *)(*(_QWORD *)(v30 + 216) + *(unsigned __int16 *)(v30 + 184) + 2LL) = bswap32(
                                                                                      v42
                                                                                    - *(unsigned __int16 *)(v30 + 184)
                                                                                    + *(unsigned __int16 *)(v30 + 186)) >> 16;
    }
    else if ( v9 == 56710 )
    {
      *(_WORD *)(*(_QWORD *)(v30 + 216) + *(unsigned __int16 *)(v30 + 184) + 4LL) = bswap32(
                                                                                      *(unsigned __int16 *)(v30 + 186)
                                                                                    + v42
                                                                                    - *(unsigned __int16 *)(v30 + 182)) >> 16;
    }
    if ( v77 == 1 )
    {
      v52 = *(_QWORD *)(v30 + 216) + *(unsigned __int16 *)(v30 + 182);
      *(_WORD *)(v52 + 12) = *(_WORD *)(v52 + 12) & 0xF7FF
                           | *(_WORD *)(*(_QWORD *)(a2 + 216) + *(unsigned __int16 *)(a2 + 182) + 12LL) & 0x800;
      v53 = *(_QWORD *)(v30 + 216) + *(unsigned __int16 *)(v30 + 182);
      *(_WORD *)(v53 + 12) = *(_WORD *)(v53 + 12) & 0xFEFF
                           | *(_WORD *)(*(_QWORD *)(a2 + 216) + *(unsigned __int16 *)(a2 + 182) + 12LL) & 0x100;
    }
    v25 -= v27;
    if ( !v25 )
      break;
    v54 = v78;
    v29 += v27;
    while ( 2 )
    {
      v55 = v78;
      v56 = v54 - v27;
      v57 = v27;
      if ( v54 > v27 )
        v55 = v54 - v27;
      if ( v27 )
      {
        v58 = v24 >= v27;
        v24 -= v27;
        if ( v24 != 0 && v58 )
        {
          v26 += v27;
          if ( v24 >= v55 )
            v27 = v55;
          else
            v27 = v24;
          if ( v54 <= v57 )
            break;
          goto LABEL_71;
        }
      }
      v59 = *(_QWORD *)(a2 + 216) + *(unsigned int *)(a2 + 212);
      if ( !*(_BYTE *)(v59 + 2) )
      {
        v65 = (_QWORD *)*v75;
        if ( *v75 )
        {
          do
          {
            while ( 1 )
            {
              v66 = (void (*)(void))nbuf_free_cb;
              v67 = (_QWORD *)*v65;
              if ( nbuf_free_cb )
                break;
              dev_kfree_skb_any_reason(v65, 1);
              v65 = v67;
              if ( !v67 )
                goto LABEL_96;
            }
            if ( *((_DWORD *)nbuf_free_cb - 1) != 303786302 )
              __break(0x8228u);
            v66();
            v65 = v67;
          }
          while ( v67 );
        }
        goto LABEL_96;
      }
      if ( (int)v79 >= *(unsigned __int8 *)(v59 + 2) )
      {
        v68 = (_QWORD *)*v75;
        if ( *v75 )
        {
          do
          {
            while ( 1 )
            {
              v69 = (void (*)(void))nbuf_free_cb;
              v70 = (_QWORD *)*v68;
              if ( nbuf_free_cb )
                break;
              dev_kfree_skb_any_reason(v68, 1);
              v68 = v70;
              if ( !v70 )
                goto LABEL_96;
            }
            if ( *((_DWORD *)nbuf_free_cb - 1) != 303786302 )
              __break(0x8228u);
            v69();
            v68 = v70;
          }
          while ( v70 );
        }
        goto LABEL_96;
      }
      if ( v79 >= 0x12 )
        __break(0x5512u);
      v60 = v59 + 16 * v79;
      v63 = *(_QWORD *)(v60 + 88);
      v61 = v60 + 88;
      v62 = v63;
      v24 = *(_DWORD *)(v61 + 8);
      if ( v24 >= v55 )
        v27 = v55;
      else
        v27 = *(_DWORD *)(v61 + 8);
      if ( (v62 & 1) != 0 )
        v64 = 0;
      else
        v64 = v62;
      v26 = (char *)((((v64 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
                   + *(unsigned int *)(v61 + 12));
      ++v79;
      if ( v54 > v57 )
      {
LABEL_71:
        memcpy((void *)(*(_QWORD *)(v30 + 224) + (unsigned __int16)v42), v26, v27);
        v42 += v27;
        tso_num_seg = skb_put(v30, v27);
        if ( v9 == 8 )
        {
          *(_WORD *)(*(_QWORD *)(v30 + 216) + *(unsigned __int16 *)(v30 + 184) + 2LL) = bswap32(
                                                                                          v42
                                                                                        - *(unsigned __int16 *)(v30 + 184)
                                                                                        + *(unsigned __int16 *)(v30 + 186)) >> 16;
        }
        else if ( v9 == 56710 )
        {
          *(_WORD *)(*(_QWORD *)(v30 + 216) + *(unsigned __int16 *)(v30 + 184) + 4LL) = bswap32(
                                                                                          *(unsigned __int16 *)(v30 + 186)
                                                                                        + v42
                                                                                        - *(unsigned __int16 *)(v30 + 182)) >> 16;
        }
        v25 -= v27;
        v29 += v27;
        v54 = v56;
        if ( !v25 )
          goto LABEL_92;
        continue;
      }
      break;
    }
    a4 = v74;
    v28 = (__int64 *)v30;
    if ( --v77 )
      continue;
    break;
  }
LABEL_92:
  result = 0;
LABEL_97:
  _ReadStatusReg(SP_EL0);
  return result;
}
