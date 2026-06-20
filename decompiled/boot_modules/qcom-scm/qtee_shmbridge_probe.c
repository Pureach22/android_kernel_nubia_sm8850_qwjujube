__int64 __fastcall qtee_shmbridge_probe(__int64 a1)
{
  const char **v1; // x19
  __int64 v3; // x0
  __int64 property; // x0
  __int64 v5; // x2
  int *v6; // x20
  int v7; // w0
  __int64 v8; // x8
  unsigned __int64 v9; // x8
  unsigned int v10; // w9
  __int64 v11; // x1
  __int64 free_pages_noprof; // x0
  __int64 result; // x0
  void *v14; // x0
  __int64 v15; // x1
  __int64 v16; // x22
  __int64 v17; // x24
  char v18; // w0
  __int64 v19; // x2
  unsigned int v20; // w20
  char v21; // w25
  const char *v22; // x0
  const char *v23; // x2
  __int64 v24; // x0
  __int64 v25; // x2
  unsigned int v26; // w0
  __int64 v27; // x0
  __int64 v28; // x1
  __int64 v29; // x2
  __int64 v30; // x3
  __int64 v31; // x4
  __int64 v32; // x5
  __int64 v33; // x6
  __int64 v34; // x7
  unsigned int v35; // w0
  __int64 v36; // x2
  unsigned int v37; // w0
  __int64 v38; // x0
  __int64 v39; // x1
  __int64 v40; // x2
  __int64 v41; // x3
  __int64 v42; // x4
  __int64 v43; // x5
  __int64 v44; // x6
  __int64 v45; // x7
  const char *v46; // x2
  unsigned int v47; // w9
  __int64 v48; // x1
  unsigned int v49; // w21
  __int64 v50; // x2
  int v51; // [xsp+8h] [xbp-18h] BYREF
  int v52; // [xsp+Ch] [xbp-14h] BYREF
  int v53; // [xsp+10h] [xbp-10h] BYREF
  char v54; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v55; // [xsp+18h] [xbp-8h]

  v1 = (const char **)(a1 + 16);
  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  dma_set_mask(a1 + 16, -1);
  v3 = *(_QWORD *)(a1 + 760);
  v53 = 3;
  v51 = 0;
  v52 = 6;
  property = of_find_property(v3, "qcom,support-hypervisor", 0);
  if ( property )
    v6 = (int *)&v54;
  else
    v6 = &v53;
  support_hyp = property != 0;
  if ( qword_13960 )
  {
    v14 = &unk_125A7;
    v15 = 490;
LABEL_15:
    printk(v14, v15, v5);
    result = 0;
    goto LABEL_13;
  }
  v7 = of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,custom-bridge-size", &v51, 1, 0);
  LODWORD(v8) = v51 << 12;
  if ( v7 < 0 )
    v8 = 0x400000;
  else
    v8 = (unsigned int)v8;
  qword_13968 = v8;
  v9 = v8 - 1;
  v10 = 64 - __clz(v9 >> 12);
  if ( v9 >= 0x1000 )
    v11 = v10;
  else
    v11 = 0;
  free_pages_noprof = get_free_pages_noprof(265408, v11);
  qword_13960 = free_pages_noprof;
  if ( !free_pages_noprof )
  {
    result = 4294967284LL;
    goto LABEL_13;
  }
  v16 = qword_13968;
  v17 = free_pages_noprof;
  v18 = is_vmalloc_addr(free_pages_noprof);
  if ( (v18 & 1) != 0 && (dma_map_single_attrs___already_done_1 & 1) == 0 )
  {
    v21 = v18;
    dma_map_single_attrs___already_done_1 = 1;
    v22 = (const char *)dev_driver_string(v1);
    v23 = *(const char **)(a1 + 128);
    if ( !v23 )
      v23 = *v1;
    _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v22, v23);
    __break(0x800u);
    if ( (v21 & 1) != 0 )
      goto LABEL_19;
  }
  else if ( (v18 & 1) != 0 )
  {
LABEL_19:
    default_bridge = -1;
LABEL_20:
    printk(&unk_12808, 510, v19);
    v20 = -12;
LABEL_37:
    v47 = 64 - __clz((unsigned __int64)(qword_13968 - 1) >> 12);
    if ( (unsigned __int64)(qword_13968 - 1) >= 0x1000 )
      v48 = v47;
    else
      v48 = 0;
    free_pages(qword_13960, v48);
    result = v20;
    qword_13960 = 0;
    goto LABEL_13;
  }
  default_bridge = dma_map_page_attrs(
                     v1,
                     ((unsigned __int64)((v17 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
                     v17 & 0xFFF,
                     v16,
                     1,
                     0);
  if ( default_bridge == -1 )
    goto LABEL_20;
  qword_13988 = (__int64)v1;
  dword_13978 = 12;
  v24 = gen_pool_create(12, 0xFFFFFFFFLL);
  qword_13980 = v24;
  if ( !v24 )
  {
    printk(&unk_11FCE, 521, v25);
    v20 = -12;
LABEL_36:
    dma_unmap_page_attrs(v1, default_bridge, qword_13968, 1, 0);
    goto LABEL_37;
  }
  gen_pool_set_algo(v24, &gen_pool_best_fit, 0);
  v26 = gen_pool_add_owner(qword_13980, qword_13960, default_bridge, qword_13968, 0xFFFFFFFFLL, 0);
  if ( v26 )
  {
    v20 = v26;
    printk(&unk_1217F, 531, v26);
LABEL_35:
    gen_pool_destroy(qword_13980);
    goto LABEL_36;
  }
  v27 = _mutex_init(&unk_13920, "&bridge_list_head.lock", &qtee_shmbridge_init___key);
  bridge_list_head = (__int64)&bridge_list_head;
  qword_13918 = (__int64)&bridge_list_head;
  qtee_shmbridge_enabled = 0;
  v35 = qcom_scm_enable_shm_bridge(v27, v28, v29, v30, v31, v32, v33, v34);
  if ( v35 )
  {
    v49 = v35;
    printk(&unk_12413, 123, v35);
    if ( v49 != -5 && v49 != 4 )
    {
      result = 0;
      goto LABEL_13;
    }
    v14 = &unk_12D72;
    v15 = 126;
    goto LABEL_15;
  }
  qtee_shmbridge_enabled = 1;
  printk(&unk_12B7F, 130, v36);
  v37 = qtee_shmbridge_register(
          default_bridge,
          qword_13968,
          v6,
          &v52,
          (unsigned __int8)support_hyp ^ 1u,
          6u,
          &qword_13970);
  if ( v37 )
  {
    v20 = v37;
    printk(&unk_1285A, 560, qword_13968);
    qtee_shmbridge_deregister(qword_13970);
    qtee_shmbridge_enabled = 0;
    printk(&unk_123E7, 116, v50);
    goto LABEL_35;
  }
  v38 = printk(&unk_1289A, 565, qword_13968);
  if ( (unsigned int)scm_mem_protection_init_do(v38, v39, v40, v41, v42, v43, v44, v45) )
    v46 = "Not enabled";
  else
    v46 = "Enabled";
  printk(&unk_121E5, 570, v46);
  result = 0;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
