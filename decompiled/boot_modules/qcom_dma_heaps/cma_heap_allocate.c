__int64 __fastcall cma_heap_allocate(__int64 a1, __int64 a2, int a3)
{
  unsigned __int64 v3; // x23
  size_t v6; // x25
  unsigned int v7; // w11
  unsigned int v8; // w22
  __int64 drvdata; // x0
  _QWORD *v10; // x21
  unsigned int v11; // w24
  __int64 v12; // x0
  __int64 v13; // x22
  unsigned __int64 v14; // x23
  __int64 v15; // x0
  __int64 v16; // x24
  int v17; // w26
  __int64 *v18; // x8
  __int64 v19; // x9
  unsigned __int64 v20; // x0
  __int64 dev; // x0
  __int64 v22; // x0
  __int64 name; // x0
  __int64 v24; // x8
  unsigned __int64 v25; // x0
  __int64 v26; // x19
  _QWORD v28[3]; // [xsp+0h] [xbp-50h] BYREF
  __int64 v29; // [xsp+18h] [xbp-38h]
  __int64 v30; // [xsp+20h] [xbp-30h]
  __int64 v31; // [xsp+28h] [xbp-28h]
  __int64 v32; // [xsp+30h] [xbp-20h]
  __int64 v33; // [xsp+38h] [xbp-18h]
  __int64 v34; // [xsp+40h] [xbp-10h]
  __int64 v35; // [xsp+48h] [xbp-8h]

  v3 = a2 + 4095;
  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = (a2 + 4095) & 0xFFFFFFFFFFFFF000LL;
  v32 = 0;
  v33 = 0;
  v34 = 0;
  v28[2] = 0;
  v29 = 0;
  v30 = 0;
  v31 = 0;
  v7 = 64 - __clz((v6 - 1) >> 12);
  v28[0] = "qcom_dma_heaps";
  v28[1] = &_this_module;
  if ( v6 == 4096 )
    v8 = 0;
  else
    v8 = v7;
  drvdata = dma_heap_get_drvdata(a1);
  v10 = (_QWORD *)drvdata;
  if ( v8 >= *(_DWORD *)(drvdata + 8) )
    v11 = *(_DWORD *)(drvdata + 8);
  else
    v11 = v8;
  v12 = _kmalloc_cache_noprof(of_get_next_available_child, 3520, 176);
  v13 = v12;
  if ( !v12 )
  {
    v26 = -12;
    goto LABEL_22;
  }
  v14 = v3 >> 12;
  qcom_sg_buffer_init(v12);
  *(_QWORD *)v13 = a1;
  *(_QWORD *)(v13 + 72) = v6;
  *(_BYTE *)(v13 + 112) = *((_BYTE *)v10 + 12);
  *(_QWORD *)(v13 + 160) = cma_heap_free;
  v15 = cma_alloc(*v10, v14, v11, 0);
  if ( !v15 )
  {
    v26 = -12;
    goto LABEL_19;
  }
  v16 = v15;
  memset((void *)(((v15 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL), 0, v6);
  v17 = sg_alloc_table(v13 + 80, 1, 3264);
  if ( v17 )
  {
LABEL_17:
    cma_release(*v10, v16, v14);
    v26 = v17;
LABEL_19:
    kfree(v13);
LABEL_22:
    _ReadStatusReg(SP_EL0);
    return v26;
  }
  if ( (v16 & 3) == 0 )
  {
    v18 = *(__int64 **)(v13 + 80);
    v19 = *v18;
    *((_DWORD *)v18 + 2) = 0;
    *((_DWORD *)v18 + 3) = v6;
    *v18 = v19 & 3 | v16;
    v20 = mem_buf_vmperm_alloc(v13 + 80, qcom_sg_release, v13 + 168);
    v17 = 0;
    *(_QWORD *)(v13 + 120) = v20;
    if ( v20 <= 0xFFFFFFFFFFFFF000LL )
    {
      if ( *(_BYTE *)(v13 + 112) == 1 )
      {
        dev = dma_heap_get_dev(a1);
        dma_map_sgtable(dev, v13 + 80, 0, 0);
        v22 = dma_heap_get_dev(a1);
        dma_unmap_sg_attrs(v22, *(_QWORD *)(v13 + 80), *(unsigned int *)(v13 + 92), 0, 0);
      }
      name = dma_heap_get_name(a1);
      v24 = *(_QWORD *)(v13 + 72);
      v28[0] = name;
      LODWORD(v30) = a3;
      v29 = v24;
      v32 = v13;
      v25 = mem_buf_dma_buf_export(v28, qcom_sg_buf_ops);
      v26 = v25;
      if ( v25 <= 0xFFFFFFFFFFFFF000LL )
      {
        qcom_store_dma_buf_fops(*(_QWORD *)(v25 + 8));
        goto LABEL_22;
      }
      mem_buf_vmperm_free(*(_QWORD *)(v13 + 120));
      v17 = v26;
    }
    sg_free_table(v13 + 80);
    goto LABEL_17;
  }
  __break(0x800u);
  return cma_heap_free();
}
