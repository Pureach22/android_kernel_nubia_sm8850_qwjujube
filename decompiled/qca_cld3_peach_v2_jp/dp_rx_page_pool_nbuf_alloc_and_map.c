__int64 __fastcall dp_rx_page_pool_nbuf_alloc_and_map(__int64 a1, unsigned __int64 *a2, unsigned int a3, char a4)
{
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v10; // x24
  __int64 v11; // x0
  __int64 v12; // x23
  __int64 v13; // x0
  unsigned __int64 StatusReg; // x8
  __int64 result; // x0
  unsigned __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  char v23; // w8
  __int64 v24; // x0
  __int64 v25; // x23
  unsigned __int64 v26; // x0
  __int64 v27; // x8
  __int64 v28; // x22
  __int64 dma_addr; // x0
  unsigned __int64 v30; // x8
  __int64 v31; // x3
  int v32; // w8
  __int64 v33; // x2
  __int64 v34; // x8
  __int64 v35; // x0
  __int64 v36; // x8
  __int64 v37; // x19
  __int64 v38; // x20
  __int64 v39; // x0
  __int64 v40; // x1
  __int64 v41; // x8
  __int64 v42; // x8
  unsigned int v43; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v44; // [xsp+8h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 >= 5 )
    goto LABEL_65;
  v5 = a1 + 544LL * a3;
  v6 = *(_QWORD *)(a1 + 40);
  v43 = 0;
  v10 = v5 + 20224;
  if ( (wlan_cfg_get_dp_rx_buffer_recycle(v6) & 1) == 0 || (*(_BYTE *)(v10 + 440) & 1) == 0 )
    goto LABEL_15;
  if ( *(_DWORD *)(v10 + 288) )
  {
    v11 = *(_QWORD *)(v10 + 16);
    if ( !v11 || (v12 = v10, (_qdf_page_pool_empty(v11) & 1) != 0) )
    {
      v13 = *(_QWORD *)(v10 + 208);
      if ( !v13 || (_qdf_page_pool_empty(v13) & 1) != 0 )
        goto LABEL_15;
      v12 = v10 + 192;
    }
    if ( v12 )
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v10 + 256);
      }
      else
      {
        raw_spin_lock_bh(v10 + 256);
        *(_QWORD *)(v10 + 264) |= 1uLL;
      }
      goto LABEL_41;
    }
LABEL_15:
    ++*(_QWORD *)(v10 + 456);
LABEL_16:
    result = 16;
    goto LABEL_17;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v16 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v16 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v16 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v10 + 256);
  }
  else
  {
    raw_spin_lock_bh(v10 + 256);
    *(_QWORD *)(v10 + 264) |= 1uLL;
  }
  if ( *(unsigned __int8 *)(v10 + 248) > 4uLL )
LABEL_65:
    __break(0x5512u);
  v12 = v10 + 48LL * *(unsigned __int8 *)(v10 + 248);
  v17 = *(_QWORD *)(v12 + 16);
  if ( v17 && (_qdf_page_pool_empty(v17) & 1) == 0 )
    goto LABEL_41;
  v18 = *(_QWORD *)(v10 + 16);
  if ( v18 && (_qdf_page_pool_empty(v18) & 1) == 0 )
  {
    v12 = v10;
    *(_BYTE *)(v10 + 248) = 0;
    goto LABEL_41;
  }
  v19 = *(_QWORD *)(v10 + 64);
  if ( v19 && (_qdf_page_pool_empty(v19) & 1) == 0 )
  {
    v23 = 1;
    v12 = v10 + 48;
LABEL_40:
    *(_BYTE *)(v10 + 248) = v23;
    goto LABEL_41;
  }
  v20 = *(_QWORD *)(v10 + 112);
  if ( v20 && (_qdf_page_pool_empty(v20) & 1) == 0 )
  {
    v23 = 2;
    v12 = v10 + 96;
    goto LABEL_40;
  }
  v21 = *(_QWORD *)(v10 + 160);
  if ( v21 && (_qdf_page_pool_empty(v21) & 1) == 0 )
  {
    v23 = 3;
    v12 = v10 + 144;
    goto LABEL_40;
  }
  v22 = *(_QWORD *)(v10 + 208);
  if ( !v22 || (_qdf_page_pool_empty(v22) & 1) != 0 )
    goto LABEL_52;
  v12 = v10 + 192;
LABEL_41:
  v24 = _qdf_nbuf_page_pool_alloc(
          *(_QWORD *)(a1 + 24),
          *(_QWORD *)(v10 + 528),
          0,
          *(_DWORD *)(v10 + 536),
          *(_QWORD *)(v12 + 16),
          &v43,
          "dp_rx_page_pool_nbuf_alloc_and_map",
          567);
  if ( !v24 )
  {
LABEL_52:
    v41 = *(_QWORD *)(v10 + 264);
    ++*(_QWORD *)(v10 + 456);
    if ( (v41 & 1) != 0 )
    {
      *(_QWORD *)(v10 + 264) = v41 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v10 + 256);
    }
    else
    {
      raw_spin_unlock(v10 + 256);
    }
    goto LABEL_16;
  }
  v25 = v24;
  v26 = ((unsigned __int64)(((__int64)(*(_QWORD *)(v24 + 224) << 8) >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL;
  v27 = *(_QWORD *)(v26 + 8);
  v28 = a1 + 120LL * a3 + 12368;
  if ( (v27 & 1) != 0 )
    v26 = v27 - 1;
  dma_addr = _qdf_page_pool_get_dma_addr(v26);
  v30 = dma_addr + v43 + (unsigned __int64)(unsigned int)(*(_DWORD *)(v25 + 224) - *(_DWORD *)(v25 + 216));
  *(_QWORD *)(v25 + 40) = v30;
  *a2 = v30;
  a2[1] = v25;
  if ( (a4 & 1) != 0 )
    dp_ipa_handle_rx_buf_smmu_mapping(
      a1,
      v25,
      *(unsigned __int16 *)(v28 + 74),
      1,
      (__int64)"dp_rx_page_pool_nbuf_alloc_and_map",
      0x24Du,
      3);
  v31 = *(unsigned __int16 *)(v28 + 74);
  if ( *(_DWORD *)(a1 + 20208) && (*(_BYTE *)(*(_QWORD *)(a1 + 40) + 831LL) & 1) == 0 )
  {
    v32 = *(_DWORD *)(v25 + 48);
    if ( (v32 & 0x2000000) != 0 )
    {
      if ( a1 )
        ++*(_DWORD *)(a1 + 14024);
    }
    else
    {
      v33 = *(_QWORD *)(v25 + 40);
      *(_DWORD *)(v25 + 48) = v32 | 0x2000000;
      v34 = *(_QWORD *)(a1 + 24);
      v35 = *(_QWORD *)(v34 + 40);
      if ( *(_BYTE *)(v34 + 608) == 1 && (v36 = *(_QWORD *)(v34 + 616)) != 0 )
      {
        v37 = v35;
        v38 = v31;
        v39 = iommu_iova_to_phys(v36, v33);
        v33 = *(_QWORD *)(v25 + 40);
        v31 = v38;
        v40 = v39;
        v35 = v37;
      }
      else
      {
        v40 = v33;
      }
      pld_audio_smmu_map(v35, v40, v33, v31);
    }
  }
  v42 = *(_QWORD *)(v10 + 264);
  if ( (v42 & 1) != 0 )
  {
    *(_QWORD *)(v10 + 264) = v42 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v10 + 256);
  }
  else
  {
    raw_spin_unlock(v10 + 256);
  }
  result = 0;
  ++*(_QWORD *)(v10 + 448);
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
