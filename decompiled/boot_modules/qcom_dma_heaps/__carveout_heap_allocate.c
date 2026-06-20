__int64 __fastcall _carveout_heap_allocate(_QWORD *a1, __int64 a2, int a3, __int64 a4)
{
  __int64 v8; // x0
  __int64 v9; // x21
  __int64 v10; // x8
  __int64 v11; // x24
  __int64 v12; // x0
  __int64 v13; // x0
  unsigned __int64 v14; // x23
  __int64 *v15; // x10
  __int64 v16; // x8
  __int64 v17; // x11
  unsigned __int64 v18; // x0
  __int64 name; // x0
  __int64 v20; // x8
  unsigned __int64 v21; // x0
  __int64 v22; // x0
  _QWORD v24[3]; // [xsp+0h] [xbp-50h] BYREF
  __int64 v25; // [xsp+18h] [xbp-38h]
  __int64 v26; // [xsp+20h] [xbp-30h]
  __int64 v27; // [xsp+28h] [xbp-28h]
  __int64 v28; // [xsp+30h] [xbp-20h]
  __int64 v29; // [xsp+38h] [xbp-18h]
  __int64 v30; // [xsp+40h] [xbp-10h]
  __int64 v31; // [xsp+48h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28 = 0;
  v29 = 0;
  v30 = 0;
  v24[2] = 0;
  v25 = 0;
  v26 = 0;
  v27 = 0;
  v24[0] = "qcom_dma_heaps";
  v24[1] = &_this_module;
  v8 = _kmalloc_cache_noprof(of_get_next_available_child, 3520, 176);
  v9 = v8;
  if ( !v8 )
  {
    v11 = -12;
    goto LABEL_18;
  }
  qcom_sg_buffer_init(v8);
  v10 = *a1;
  *(_QWORD *)(v9 + 72) = a2;
  *(_QWORD *)(v9 + 160) = a4;
  *(_QWORD *)v9 = v10;
  *(_BYTE *)(v9 + 112) = 1;
  LODWORD(v11) = sg_alloc_table(v9 + 80, 1, 3264);
  if ( (_DWORD)v11 )
    goto LABEL_14;
  down_read(a1 + 1);
  v12 = a1[9];
  if ( v12 && (v13 = gen_pool_alloc_algo_owner(v12, a2, *(_QWORD *)(v12 + 32), *(_QWORD *)(v12 + 40), 0)) != 0 )
  {
    v14 = v13;
    up_read(a1 + 1);
    if ( v14 == -1 )
    {
      LODWORD(v11) = -12;
      goto LABEL_13;
    }
    v15 = *(__int64 **)(v9 + 80);
    v16 = memstart_addr;
    v17 = *v15;
    *((_DWORD *)v15 + 2) = 0;
    *((_DWORD *)v15 + 3) = a2;
    *v15 = ((((v14 >> 6) & 0x3FFFFFFFFFFFFC0LL) - (v16 >> 12 << 6)) & 0xFFFFFFFFFFFFFFFCLL | v17 & 3) - 0x140000000LL;
    v18 = carveout_setup_vmperm((__int64)a1, v9);
    LODWORD(v11) = 0;
    *(_QWORD *)(v9 + 120) = v18;
    if ( v18 <= 0xFFFFFFFFFFFFF000LL )
    {
      name = dma_heap_get_name(*a1);
      v20 = *(_QWORD *)(v9 + 72);
      v24[0] = name;
      LODWORD(v26) = a3;
      v25 = v20;
      v28 = v9;
      v21 = mem_buf_dma_buf_export(v24, qcom_sg_buf_ops);
      v11 = v21;
      if ( v21 <= 0xFFFFFFFFFFFFF000LL )
      {
        qcom_store_dma_buf_fops(*(_QWORD *)(v21 + 8));
        goto LABEL_18;
      }
      mem_buf_vmperm_free(*(_QWORD *)(v9 + 120));
    }
    down_read(a1 + 1);
    v22 = a1[9];
    if ( v22 )
      gen_pool_free_owner(v22, v14, a2, 0);
  }
  else
  {
    LODWORD(v11) = -12;
  }
  up_read(a1 + 1);
LABEL_13:
  sg_free_table(v9 + 80);
LABEL_14:
  kfree(v9);
  v11 = (int)v11;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return v11;
}
