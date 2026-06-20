__int64 __fastcall system_heap_allocate_0(__int64 a1, unsigned __int64 a2, int a3)
{
  __int64 v6; // x21
  __int64 drvdata; // x20
  __int64 v8; // x2
  __int64 v9; // x3
  __int64 v10; // x4
  unsigned int v11; // w25
  unsigned int v12; // w28
  unsigned __int64 StatusReg; // x26
  __int64 *v14; // x19
  __int64 v15; // x27
  __int64 v16; // x0
  __int64 v17; // x1
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x22
  int v21; // w9
  __int64 v22; // x21
  __int64 v23; // x0
  _DWORD *v24; // x8
  __int64 v25; // x22
  __int64 v26; // x0
  _DWORD *v27; // x8
  __int64 v28; // x22
  _QWORD *v29; // x1
  _QWORD *v30; // x0
  __int64 v31; // x0
  unsigned __int8 v32; // w8
  _QWORD *v33; // x26
  __int64 v34; // x21
  int v35; // w21
  __int64 v36; // x24
  int vmid_perms; // w0
  __int64 v38; // x8
  unsigned __int64 v39; // x0
  __int64 name; // x0
  __int64 v41; // x9
  unsigned __int64 v42; // x0
  __int64 dev; // x0
  __int64 v44; // x0
  int v45; // w0
  bool v46; // w19
  _QWORD *v47; // x9
  __int64 v48; // x9
  _QWORD *v49; // x23
  _QWORD *v50; // x1
  _QWORD *v51; // x8
  char v52; // w9
  __int64 v53; // x1
  _QWORD *v54; // x19
  int v56; // [xsp+4h] [xbp-ACh]
  _QWORD *v57; // [xsp+10h] [xbp-A0h]
  unsigned int v58; // [xsp+1Ch] [xbp-94h]
  __int64 v59; // [xsp+20h] [xbp-90h] BYREF
  _QWORD *v60; // [xsp+28h] [xbp-88h] BYREF
  _QWORD **v61; // [xsp+30h] [xbp-80h]
  _QWORD *v62; // [xsp+38h] [xbp-78h] BYREF
  _QWORD **v63; // [xsp+40h] [xbp-70h]
  __int64 v64; // [xsp+48h] [xbp-68h] BYREF
  __int64 v65; // [xsp+50h] [xbp-60h]
  _QWORD v66[2]; // [xsp+58h] [xbp-58h] BYREF
  void *v67; // [xsp+68h] [xbp-48h]
  __int64 v68; // [xsp+70h] [xbp-40h]
  __int64 v69; // [xsp+78h] [xbp-38h]
  __int64 v70; // [xsp+80h] [xbp-30h]
  _QWORD *v71; // [xsp+88h] [xbp-28h]
  __int64 v72; // [xsp+90h] [xbp-20h]
  __int64 v73; // [xsp+98h] [xbp-18h]
  __int64 v74; // [xsp+A0h] [xbp-10h]

  v74 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v71 = nullptr;
  v72 = 0;
  v73 = 0;
  v64 = 0;
  v65 = 0;
  v59 = 0;
  v67 = nullptr;
  v68 = 0;
  v69 = 0;
  v70 = 0;
  v66[0] = "qcom_dma_heaps";
  v66[1] = &_this_module;
  v62 = &v62;
  v63 = &v62;
  v60 = &v60;
  v61 = &v60;
  v6 = _kmalloc_cache_noprof(of_get_next_available_child, 3520, 176);
  if ( !v6 )
  {
    v36 = -12;
    goto LABEL_92;
  }
  v56 = a3;
  drvdata = dma_heap_get_drvdata(a1);
  qcom_sg_buffer_init(v6);
  v57 = (_QWORD *)v6;
  *(_BYTE *)(v6 + 112) = 1;
  *(_QWORD *)v6 = a1;
  *(_QWORD *)(v6 + 72) = a2;
  *(_QWORD *)(v6 + 160) = system_heap_free;
  if ( a2 )
  {
    v11 = 0;
    v12 = 9;
    v58 = 0;
    StatusReg = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      if ( (*(_QWORD *)StatusReg & 1) != 0 && (*(_BYTE *)(StatusReg + 2449) & 1) != 0 )
      {
LABEL_66:
        v33 = v57;
        goto LABEL_67;
      }
      v14 = *(__int64 **)drvdata;
      v15 = get_sys_heap_page_pool_qcom_sys_heap_pools;
      if ( !get_sys_heap_page_pool_qcom_sys_heap_pools )
      {
        v16 = dma_heap_find("qcom,system");
        if ( v16 )
        {
          v15 = *(_QWORD *)(dma_heap_get_drvdata(v16) + 8);
          get_sys_heap_page_pool_qcom_sys_heap_pools = v15;
          if ( !v15 )
            goto LABEL_65;
        }
        else
        {
          printk(&unk_DA0D, v17);
          v15 = get_sys_heap_page_pool_qcom_sys_heap_pools;
          if ( !get_sys_heap_page_pool_qcom_sys_heap_pools )
          {
LABEL_65:
            printk(&unk_DCDB, "alloc_largest_available");
            goto LABEL_66;
          }
        }
      }
      if ( v12 >= 9 && a2 >= 0x200000 )
      {
        v18 = raw_spin_lock_irqsave(*v14 + 64);
        v19 = *v14;
        v20 = v18;
        v21 = *(_DWORD *)*v14;
        if ( !v21 && !*(_DWORD *)(v19 + 4) )
        {
          raw_spin_unlock_irqrestore(v19 + 64, v18);
          goto LABEL_16;
        }
        v22 = dynamic_page_pool_remove(*v14, v21 != 0);
        raw_spin_unlock_irqrestore(*v14 + 64, v20);
        if ( v22 )
          goto LABEL_28;
      }
      if ( v12 < 4 )
        goto LABEL_22;
LABEL_16:
      if ( a2 < 0x10000 )
      {
LABEL_22:
        if ( a2 < 0x1000 )
          goto LABEL_33;
        goto LABEL_25;
      }
      v23 = raw_spin_lock_irqsave(v14[1] + 64);
      v24 = (_DWORD *)v14[1];
      v25 = v23;
      if ( *v24 || v24[1] )
      {
        v22 = dynamic_page_pool_remove(v14[1], *v24 != 0);
        raw_spin_unlock_irqrestore(v14[1] + 64, v25);
        if ( v22 )
          goto LABEL_28;
      }
      else
      {
        raw_spin_unlock_irqrestore(v24 + 16, v23);
      }
LABEL_25:
      v26 = raw_spin_lock_irqsave(v14[2] + 64);
      v27 = (_DWORD *)v14[2];
      v28 = v26;
      if ( *v27 || v27[1] )
      {
        v22 = dynamic_page_pool_remove(v14[2], *v27 != 0);
        raw_spin_unlock_irqrestore(v14[2] + 64, v28);
        if ( v22 )
        {
LABEL_28:
          v29 = v63;
          v30 = (_QWORD *)(v22 + 8);
          if ( (_QWORD **)(v22 + 8) == &v62 || v63 == v30 || *v63 != &v62 )
            goto LABEL_44;
          v63 = (_QWORD **)(v22 + 8);
          *(_QWORD *)(v22 + 8) = &v62;
          goto LABEL_38;
        }
      }
      else
      {
        raw_spin_unlock_irqrestore(v27 + 16, v26);
      }
LABEL_33:
      v31 = qcom_sys_heap_alloc_largest_available(v15, a2, v12, 0);
      if ( !v31 )
        goto LABEL_66;
      v29 = v61;
      v22 = v31;
      v30 = (_QWORD *)(v31 + 8);
      ++v58;
      if ( v30 == &v60 || v61 == v30 || *v61 != &v60 )
      {
LABEL_44:
        _list_add_valid_or_report(v30);
        goto LABEL_39;
      }
      v61 = (_QWORD **)v30;
      *(_QWORD *)(v22 + 8) = &v60;
LABEL_38:
      *(_QWORD *)(v22 + 16) = v29;
      *v29 = v30;
LABEL_39:
      if ( (*(_QWORD *)v22 & 0x40) != 0 )
      {
        v32 = *(_BYTE *)(v22 + 64);
        v12 = v32;
      }
      else
      {
        v32 = 0;
        v12 = 0;
      }
      ++v11;
      a2 += -4096LL << v32;
      if ( !a2 )
        goto LABEL_47;
    }
  }
  v58 = 0;
  v11 = 0;
LABEL_47:
  v33 = v57;
  if ( (unsigned int)sg_alloc_table(v57 + 10, v11, 3264) )
  {
LABEL_67:
    v46 = 0;
    v36 = -12;
    goto LABEL_68;
  }
  v34 = v57[10];
  if ( v58 )
  {
    if ( (unsigned int)sg_alloc_table(&v64, v58, 3264) )
    {
      v35 = 0;
      LODWORD(v36) = -12;
LABEL_62:
      sg_free_table(v57 + 10);
      v36 = (int)v36;
      v46 = v35 != 0;
LABEL_68:
      v47 = v62;
      if ( v62 != &v62 )
      {
        do
        {
          v49 = (_QWORD *)*v47;
          v50 = v47 - 1;
          if ( (*(v47 - 1) & 0x40) != 0 && *((_BYTE *)v47 + 56) == 9 )
          {
            v48 = 0;
          }
          else if ( (*v50 & 0x40) != 0 && *((_BYTE *)v47 + 56) == 4 )
          {
            v48 = 1;
          }
          else if ( (*v50 & 0x40) != 0 )
          {
            if ( *((_BYTE *)v47 + 56) )
              v48 = 3;
            else
              v48 = 2;
          }
          else
          {
            v48 = 2;
          }
          dynamic_page_pool_free(*(_QWORD *)(*(_QWORD *)drvdata + 8 * v48), (__int64)v50, v8, v9, v10);
          v47 = v49;
        }
        while ( v49 != &v62 );
      }
      v51 = v60;
      v52 = v60 == &v60 || v46;
      if ( (v52 & 1) == 0 )
      {
        do
        {
          v54 = (_QWORD *)*v51;
          if ( (*(v51 - 1) & 0x40) != 0 )
            v53 = *((unsigned __int8 *)v51 + 56);
          else
            v53 = 0;
          _free_pages(v51 - 1, v53);
          v51 = v54;
        }
        while ( v54 != &v60 );
      }
      kfree(v33);
      goto LABEL_92;
    }
    page_list_merge(&v62, &v60, v34, v64);
    dev = dma_heap_get_dev(a1);
    dma_map_sgtable(dev, &v64, 0, 0);
    v44 = dma_heap_get_dev(a1);
    dma_unmap_sg_attrs(v44, v64, HIDWORD(v65), 0, 0);
    v45 = hyp_assign_sg_from_flags(&v64, *(int *)(drvdata + 8), 1);
    if ( v45 )
    {
      LODWORD(v36) = -12;
      if ( v45 == -99 )
        v35 = -99;
      else
        v35 = 0;
LABEL_61:
      sg_free_table(&v64);
      goto LABEL_62;
    }
  }
  else
  {
    page_list_merge(&v62, &v60, v34, 0);
  }
  vmid_perms = msm_secure_get_vmid_perms(*(unsigned int *)(drvdata + 8));
  v38 = *(int *)(drvdata + 8);
  HIDWORD(v59) = vmid_perms;
  LODWORD(v59) = get_secure_vmid(v38);
  v39 = mem_buf_vmperm_alloc_staticvm(v57 + 10, &v59, (char *)&v59 + 4, 1, qcom_sg_release, v57 + 21);
  LODWORD(v36) = v39;
  v57[15] = v39;
  if ( v39 > 0xFFFFFFFFFFFFF000LL )
  {
LABEL_55:
    v35 = hyp_unassign_sg_from_flags(&v64, *(int *)(drvdata + 8), 1);
    if ( !v58 )
      goto LABEL_62;
    goto LABEL_61;
  }
  name = dma_heap_get_name(a1);
  v41 = v57[9];
  v66[0] = name;
  v67 = &unk_578;
  v68 = v41;
  v71 = v57;
  LODWORD(v69) = v56;
  v42 = mem_buf_dma_buf_export(v66, qcom_sg_buf_ops);
  v36 = v42;
  if ( v42 >= 0xFFFFFFFFFFFFF001LL )
  {
    mem_buf_vmperm_free(v57[15]);
    goto LABEL_55;
  }
  qcom_store_dma_buf_fops(*(_QWORD *)(v42 + 8));
  if ( v58 )
    sg_free_table(&v64);
LABEL_92:
  _ReadStatusReg(SP_EL0);
  return v36;
}
