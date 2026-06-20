__int64 __fastcall fast_smmu_alloc(__int64 a1, __int64 a2, __int64 *a3, int a4, __int64 a5)
{
  __int64 domain_for_dev; // x0
  unsigned __int64 v11; // x19
  __int64 lock_irqsave; // x1
  __int64 v13; // x8
  unsigned __int64 v14; // x9
  __int64 v15; // x19
  unsigned __int64 v16; // x20
  int v17; // w27
  unsigned __int64 v18; // x25
  char v19; // w0
  __int64 v20; // x8
  __int64 v21; // x21
  unsigned __int64 v22; // x20
  char v23; // w22
  unsigned int v24; // w9
  __int64 v25; // x1
  __int64 result; // x0
  __int64 v27; // x23
  unsigned __int64 v28; // x24
  char v29; // w23
  __int64 v30; // x0
  __int64 v31; // x24
  unsigned __int64 v32; // x0
  __int64 v33; // x25
  __int64 v34; // x26
  __int64 v35; // x20
  __int64 v36; // x0
  unsigned __int64 v37; // x19
  __int64 v38; // x22
  __int64 v39; // x0
  unsigned __int64 v40; // x28
  unsigned __int64 v41; // x27
  unsigned __int64 v42; // x20
  __int64 v43; // x0
  __int64 v44; // x19
  unsigned int v45; // w9
  __int64 v46; // x1
  unsigned __int64 v47; // x20
  unsigned __int64 *v48; // [xsp+10h] [xbp-90h]
  __int64 v49; // [xsp+20h] [xbp-80h]
  unsigned __int64 v50; // [xsp+28h] [xbp-78h]
  __int64 v51[2]; // [xsp+38h] [xbp-68h] BYREF
  unsigned __int64 v52; // [xsp+48h] [xbp-58h]
  __int64 v53; // [xsp+50h] [xbp-50h]
  __int64 v54; // [xsp+58h] [xbp-48h]
  __int64 v55; // [xsp+60h] [xbp-40h]
  __int64 v56; // [xsp+68h] [xbp-38h]
  __int64 v57; // [xsp+70h] [xbp-30h]
  __int64 v58; // [xsp+78h] [xbp-28h]
  __int64 v59; // [xsp+80h] [xbp-20h] BYREF
  __int64 v60; // [xsp+88h] [xbp-18h]
  _QWORD v61[2]; // [xsp+90h] [xbp-10h] BYREF

  v61[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  domain_for_dev = iommu_get_domain_for_dev(a1);
  if ( domain_for_dev )
  {
    v11 = domain_for_dev;
    lock_irqsave = raw_read_lock_irqsave(&mappings_lock);
    v13 = mappings;
    if ( mappings )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          v14 = *(_QWORD *)(v13 - 128);
          if ( v14 <= v11 )
            break;
          v13 = *(_QWORD *)(v13 + 16);
          if ( !v13 )
            goto LABEL_8;
        }
        if ( v14 >= v11 )
          break;
        v13 = *(_QWORD *)(v13 + 8);
        if ( !v13 )
          goto LABEL_8;
      }
      v15 = v13 - 136;
    }
    else
    {
LABEL_8:
      v15 = 0;
    }
    raw_read_unlock_irqrestore(&mappings_lock, lock_irqsave);
  }
  else
  {
    v15 = -22;
  }
  v16 = a2 + 4095;
  v59 = 0;
  v60 = 0;
  v57 = 0;
  v58 = 0;
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v51[1] = 0;
  v52 = 0;
  v51[0] = 0;
  if ( (a5 & 0x8000) != 0 )
  {
    v17 = 1;
  }
  else if ( (a5 & 0x10000) != 0 )
  {
    v17 = 0;
  }
  else
  {
    v17 = (*(unsigned __int8 *)(a1 + 844) >> 5) & 1;
  }
  v18 = v16 >> 12;
  v19 = qcom_dma_info_to_prot(0, v17, a5);
  if ( arm64_use_ng_mappings )
    v20 = 0x68000000000F03LL;
  else
    v20 = 0x68000000000703LL;
  if ( (((a5 & 4) == 0) & (unsigned __int8)v17) != 0 )
    v21 = v20;
  else
    v21 = v20 | 0x60000000000008LL;
  if ( v16 >> 44 )
  {
    dev_err(a1, "count: %zx exceeds UNIT_MAX\n", v16 >> 12);
    goto LABEL_85;
  }
  v22 = v16 & 0xFFFFFFFFFFFFF000LL;
  *a3 = -1;
  if ( (a4 & 0x400) != 0 )
  {
    if ( (a5 & 0x40) != 0 )
    {
      result = _fast_smmu_alloc_contiguous(a1, v22, a3, a4 | 0x100u, a5);
      goto LABEL_86;
    }
    v28 = (unsigned int)(8 * v18);
    v29 = v19;
    v48 = (unsigned __int64 *)a3;
    v50 = v22;
    if ( (unsigned int)v28 > 0x1000 )
      v30 = vzalloc_noprof((unsigned int)(8 * v18));
    else
      v30 = _kmalloc_noprof((unsigned int)(8 * v18), 3520);
    v34 = v30;
    if ( v30 )
    {
      v49 = a1;
      if ( !(_DWORD)v18 )
      {
LABEL_55:
        if ( (unsigned int)sg_alloc_table_from_pages_segment(
                             &v59,
                             v34,
                             (unsigned int)v18,
                             0,
                             v50,
                             0xFFFFFFFFLL,
                             a4 | 0x100u) )
        {
          dev_err(a1, "no sg tablen\n");
        }
        else
        {
          if ( (v17 & 1) == 0 )
          {
            sg_miter_start(v51, v59, HIDWORD(v60), 4);
            while ( (sg_miter_next(v51) & 1) != 0 )
              qcom_arch_dma_prep_coherent(v51[0], v52);
            sg_miter_stop(v51);
          }
          v38 = raw_spin_lock_irqsave(v15 + 104);
          v39 = _fast_smmu_alloc_iova(v15, v50);
          if ( v39 == -1 )
          {
            dev_err(v49, "no iova\n");
          }
          else
          {
            v40 = v39;
            sg_miter_start(v51, v59, HIDWORD(v60), 5);
            if ( (sg_miter_next(v51) & 1) != 0 )
            {
              v41 = v40;
              while ( !(unsigned int)av8l_fast_map_public(
                                       *(_QWORD *)(v15 + 96),
                                       v41,
                                       (v51[0] + ((memstart_addr >> 6) & 0x3FFFFFFFFFFFFC0LL) + 0x140000000LL) << 6,
                                       v52,
                                       v29) )
              {
                v41 += v52;
                if ( (sg_miter_next(v51) & 1) == 0 )
                  goto LABEL_66;
              }
              dev_err(v49, "no map public\n");
              v42 = v50;
            }
            else
            {
LABEL_66:
              sg_miter_stop(v51);
              raw_spin_unlock_irqrestore(v15 + 104, v38);
              v42 = v50;
              v43 = qcom_dma_common_pages_remap(v34, v50, v21);
              if ( v43 )
              {
                v44 = v43;
                *v48 = v40;
                sg_free_table(&v59);
                result = v44;
                goto LABEL_86;
              }
              dev_err(v49, "no common pages\n");
              v38 = raw_spin_lock_irqsave(v15 + 104);
              av8l_fast_unmap_public(*(_QWORD *)(v15 + 96), v40, v50);
            }
            _fast_smmu_free_iova(v15, v40, v42);
          }
          raw_spin_unlock_irqrestore(v15 + 104, v38);
          sg_free_table(&v59);
        }
        if ( (int)v18 < 1 )
        {
LABEL_84:
          kvfree(v34);
          goto LABEL_85;
        }
        v47 = 0;
        while ( v47 < v28 )
        {
          _free_pages(*(_QWORD *)(v34 + v47), 0);
          v47 += 8LL;
          if ( 8 * v18 == v47 )
            goto LABEL_84;
        }
LABEL_90:
        __break(1u);
      }
      v35 = 0;
      _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        v36 = _alloc_pages_noprof(a4 | 0x2102u, 0, 0, 0);
        if ( !v36 )
          break;
        if ( v35 == v28 >> 3 || v28 <= 8 * v35 )
          goto LABEL_90;
        *(_QWORD *)(v34 + 8 * v35++) = v36;
        if ( v35 == v18 )
          goto LABEL_55;
      }
      if ( (int)v35 >= 1 )
      {
        v37 = 0;
        while ( v28 != v37 && v37 < v28 )
        {
          _free_pages(*(_QWORD *)(v34 + v37), 0);
          --v35;
          v37 += 8LL;
          if ( !v35 )
            goto LABEL_53;
        }
        goto LABEL_90;
      }
LABEL_53:
      kvfree(v34);
    }
    dev_err(a1, "no pages\n");
    goto LABEL_85;
  }
  v61[0] = 0;
  v23 = qcom_dma_info_to_prot(0, v17, a5);
  if ( !v17 )
  {
    v27 = (__int64)qcom_dma_alloc_from_pool(*(_QWORD *)v15, v22, v61);
    if ( !v27 )
      goto LABEL_85;
    goto LABEL_35;
  }
  v24 = 64 - __clz((v22 - 1) >> 12);
  if ( v22 == 4096 )
    v25 = 0;
  else
    v25 = v24;
  result = _alloc_pages_noprof(a4 | 0x100u, v25, 0, 0);
  v61[0] = result;
  if ( result )
  {
    v27 = ((result << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL;
LABEL_35:
    v31 = raw_spin_lock_irqsave(v15 + 104);
    v32 = _fast_smmu_alloc_iova(v15, v22);
    if ( v32 == -1 )
    {
      dev_err(*(_QWORD *)v15, "no iova\n");
    }
    else
    {
      v33 = v32;
      if ( !(unsigned int)av8l_fast_map_public(
                            *(_QWORD *)(v15 + 96),
                            v32,
                            (v61[0] + ((memstart_addr >> 6) & 0x3FFFFFFFFFFFFC0LL) + 0x140000000LL) << 6,
                            v22,
                            v23) )
      {
        raw_spin_unlock_irqrestore(v15 + 104, v31);
        *a3 = v33;
        result = v27;
        goto LABEL_86;
      }
      dev_err(*(_QWORD *)v15, "no map public\n");
      _fast_smmu_free_iova(v15, v33, v22);
    }
    raw_spin_unlock_irqrestore(v15 + 104, v31);
    if ( v17 )
    {
      v45 = 64 - __clz((v22 - 1) >> 12);
      if ( v22 == 4096 )
        v46 = 0;
      else
        v46 = v45;
      _free_pages(v61[0], v46);
    }
    else
    {
      qcom_dma_free_from_pool(*(_QWORD *)v15, v27, v22);
    }
LABEL_85:
    result = 0;
  }
LABEL_86:
  _ReadStatusReg(SP_EL0);
  return result;
}
