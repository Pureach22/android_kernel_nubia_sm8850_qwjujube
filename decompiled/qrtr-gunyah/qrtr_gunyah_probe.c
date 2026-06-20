unsigned __int64 __fastcall qrtr_gunyah_probe(__int64 a1)
{
  __int64 v1; // x22
  __int64 v3; // x20
  __int64 v4; // x0
  __int64 v5; // x19
  __int64 v6; // x0
  __int64 variable_u32_array; // x0
  __int64 property; // x0
  __int64 v9; // x21
  __int64 v10; // x0
  __int64 v11; // x0
  unsigned __int64 result; // x0
  __int64 v13; // x8
  __int64 compatible_node; // x0
  __int64 v15; // x23
  __int64 v16; // x22
  __int64 v17; // x23
  __int64 v18; // x13
  __int64 v19; // x8
  __int64 v20; // x17
  bool v21; // zf
  __int64 v22; // x9
  __int64 v23; // x16
  __int64 v24; // x1
  unsigned __int64 v25; // x16
  unsigned __int64 v26; // x8
  __int64 v27; // x2
  __int64 v28; // x16
  __int64 v29; // x8
  unsigned int v30; // w20
  unsigned __int64 v31; // x0
  char v32; // w8
  unsigned int v33; // w21
  unsigned __int64 v34; // x20
  unsigned __int64 v35; // x0
  __int64 v36; // x8
  __int64 v37; // x10
  unsigned __int64 v38; // x9
  unsigned __int64 v39; // x8
  __int64 v40; // x8
  unsigned __int64 v41; // x19
  unsigned int v42; // w20
  int v43; // [xsp+4h] [xbp-5Ch] BYREF
  __int64 v44; // [xsp+8h] [xbp-58h] BYREF
  __int64 v45; // [xsp+10h] [xbp-50h]
  __int64 v46; // [xsp+18h] [xbp-48h]
  __int64 v47; // [xsp+20h] [xbp-40h]
  __int64 v48; // [xsp+28h] [xbp-38h]
  __int64 v49; // [xsp+30h] [xbp-30h]
  __int64 v50; // [xsp+38h] [xbp-28h]
  __int64 v51; // [xsp+40h] [xbp-20h]
  __int64 v52; // [xsp+48h] [xbp-18h]
  __int64 v53; // [xsp+50h] [xbp-10h]
  __int64 v54; // [xsp+58h] [xbp-8h]

  v1 = a1 + 16;
  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 760);
  v4 = devm_kmalloc(a1 + 16, 424, 3520);
  if ( !v4 )
    goto LABEL_9;
  v5 = v4;
  *(_QWORD *)(v4 + 24) = v1;
  *(_QWORD *)(a1 + 168) = v4;
  v6 = devm_kmalloc(v1, 65568, 3520);
  *(_QWORD *)(v5 + 32) = v6;
  if ( !v6 )
    goto LABEL_9;
  _mutex_init(v5 + 208, "&qdev->state_lock", &qrtr_gunyah_probe___key);
  *(_BYTE *)(v5 + 256) = 0;
  *(_DWORD *)(v5 + 312) = 0;
  variable_u32_array = of_property_read_variable_u32_array(v3, "gunyah-label", v5 + 260, 1, 0);
  if ( (variable_u32_array & 0x80000000) != 0 )
  {
    v40 = *(_QWORD *)(v5 + 24);
    v41 = variable_u32_array;
    dev_err(v40, "failed to read label info %d\n", variable_u32_array);
    result = v41;
    goto LABEL_67;
  }
  property = of_find_property(v3, "qcom,master", 0);
  v9 = *(_QWORD *)(v5 + 24);
  *(_BYTE *)(v5 + 176) = property != 0;
  if ( !property )
  {
    v43 = 0;
    compatible_node = of_find_compatible_node(0, 0, "qcom,qrtr-gunyah-gen");
    if ( compatible_node )
    {
      v15 = compatible_node;
      while ( (of_property_read_variable_u32_array(v15, "qcom,label", &v43, 1, 0) & 0x80000000) != 0
           || v43 != *(_DWORD *)(v5 + 260) )
      {
        v15 = of_find_compatible_node(v15, 0, "qcom,qrtr-gunyah-gen");
        if ( !v15 )
          goto LABEL_75;
      }
      v52 = 0;
      v53 = 0;
      v50 = 0;
      v51 = 0;
      v48 = 0;
      v49 = 0;
      v46 = 0;
      v47 = 0;
      v44 = 0;
      v45 = 0;
      if ( !(unsigned int)_of_parse_phandle_with_args(v15, "memory-region", 0, 0, 0, &v44) )
      {
        v11 = v44;
        if ( v44 )
          goto LABEL_17;
      }
      dev_err(*(_QWORD *)(v5 + 24), "can't parse svm shared mem node!\n");
    }
LABEL_75:
    dev_err(v9, "can't parse shared mem node!\n");
    goto LABEL_76;
  }
  v10 = *(_QWORD *)(v9 + 744);
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = 0;
  v48 = 0;
  v49 = 0;
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  if ( (unsigned int)_of_parse_phandle_with_args(v10, "shared-buffer", 0, 0, 0, &v44) || (v11 = v44) == 0 )
  {
    result = dma_alloc_attrs(*(_QWORD *)(v5 + 24), 36864, v5 + 56, 3264, 64);
    *(_QWORD *)(v5 + 160) = result;
    if ( result )
    {
      *(_QWORD *)(v5 + 64) = *(_QWORD *)(v5 + 56) + 36863LL;
      v13 = 36864;
LABEL_20:
      *(_QWORD *)(v5 + 168) = v13;
      goto LABEL_21;
    }
LABEL_9:
    result = 4294967284LL;
    goto LABEL_67;
  }
LABEL_17:
  if ( (unsigned int)of_address_to_resource(v11, 0, v5 + 56) )
  {
    dev_err(v9, "of_address_to_resource failed!\n");
LABEL_76:
    result = 4294967274LL;
    goto LABEL_67;
  }
  v17 = *(_QWORD *)(v5 + 56);
  v16 = *(_QWORD *)(v5 + 64);
  result = devm_ioremap_resource(v9, v5 + 56);
  *(_QWORD *)(v5 + 160) = result;
  if ( result <= 0xFFFFFFFFFFFFF000LL )
  {
    v13 = v16 - v17 + 1;
    goto LABEL_20;
  }
  dev_err(v9, "ioremap failed!\n");
  result = *(_QWORD *)(v5 + 160);
  if ( (_DWORD)result )
    goto LABEL_67;
LABEL_21:
  if ( (*(_BYTE *)(v5 + 176) & 1) == 0 )
  {
    v18 = 20480;
    *(_DWORD *)result = 608784451;
    v19 = 12;
    v20 = *(_QWORD *)(v5 + 160);
    v21 = *(_BYTE *)(v5 + 176) == 0;
    v22 = 24;
    if ( *(_BYTE *)(v5 + 176) )
      v23 = 4;
    else
      v23 = 12;
    if ( *(_BYTE *)(v5 + 176) )
      v24 = 8;
    else
      v24 = 16;
    if ( !*(_BYTE *)(v5 + 176) )
      v19 = 4;
    v25 = result + v23;
    v26 = result + v19;
    if ( *(_BYTE *)(v5 + 176) )
      v27 = 4096;
    else
      v27 = 20480;
    *(_QWORD *)(v5 + 320) = v25;
    *(_QWORD *)(v5 + 328) = result + v24;
    if ( v21 )
      v28 = 24;
    else
      v28 = 20;
    if ( v21 )
      v18 = 4096;
    *(_QWORD *)(v5 + 352) = 0x4000;
    *(_QWORD *)(v5 + 360) = v26;
    if ( v21 )
      v29 = 8;
    else
      v29 = 16;
    if ( v21 )
      v22 = 20;
    *(_QWORD *)(v5 + 336) = result + v28;
    *(_QWORD *)(v5 + 344) = v20 + v27;
    *(_QWORD *)(v5 + 384) = v20 + v18;
    *(_QWORD *)(v5 + 392) = 0x4000;
    *(_QWORD *)(v5 + 368) = result + v29;
    *(_QWORD *)(v5 + 376) = result + v22;
    *(_DWORD *)(result + v24) = 0;
    **(_DWORD **)(v5 + 336) = 0;
    **(_DWORD **)(v5 + 360) = 0;
  }
  _init_waitqueue_head(v5 + 400, "&qdev->tx_avail_notify", &qrtr_gunyah_probe___key_6);
  if ( *(_BYTE *)(v5 + 176) == 1 )
  {
    if ( (of_property_read_variable_u32_array(v3, "peer-name", v5 + 180, 1, 0) & 0x80000000) != 0 )
      *(_DWORD *)(v5 + 180) = 0;
    *(_QWORD *)(v5 + 184) = qrtr_gunyah_vm_cb;
    *(_DWORD *)(v5 + 200) = 2147483646;
    gunyah_qtvm_register_notifier();
  }
  v30 = *(_DWORD *)(v5 + 260);
  v31 = gh_dbl_tx_register(v30);
  *(_QWORD *)(v5 + 264) = v31;
  if ( !v31 || v31 >= 0xFFFFFFFFFFFFF001LL )
  {
    v42 = v31;
    dev_err(*(_QWORD *)(v5 + 24), "failed to get gunyah tx dbl %d\n", v31);
    result = v42;
LABEL_55:
    if ( *(_BYTE *)(v5 + 176) == 1 )
    {
      v34 = result;
      gunyah_qtvm_unregister_notifier(v5 + 184);
      result = v34;
    }
    goto LABEL_67;
  }
  *(_QWORD *)(v5 + 280) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v5 + 288) = v5 + 288;
  *(_QWORD *)(v5 + 296) = v5 + 288;
  v32 = *(_BYTE *)(v5 + 176);
  *(_QWORD *)(v5 + 304) = qrtr_gunyah_retry_work;
  *(_QWORD *)v5 = &qrtr_gunyah_send;
  if ( (v32 & 1) == 0 )
  {
    v33 = qrtr_endpoint_register(v5, 1, 0, 0);
    if ( v33 )
    {
LABEL_54:
      cancel_work_sync(v5 + 280);
      gh_dbl_tx_unregister(*(_QWORD *)(v5 + 264));
      result = v33;
      goto LABEL_55;
    }
  }
  v35 = gh_dbl_rx_register(v30, qrtr_gunyah_cb, v5);
  v33 = v35;
  *(_QWORD *)(v5 + 272) = v35;
  if ( !v35 || v35 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(*(_QWORD *)(v5 + 24), "failed to get gunyah rx dbl %d\n", v35);
    qrtr_endpoint_unregister(v5);
    goto LABEL_54;
  }
  if ( (*(_BYTE *)(v5 + 176) & 1) == 0 )
  {
    v36 = **(unsigned int **)(v5 + 368);
    v37 = **(unsigned int **)(v5 + 360);
    v38 = *(_QWORD *)(v5 + 392);
    if ( (unsigned int)v36 >= (unsigned int)v37 )
      v39 = (unsigned int)(v36 - v37);
    else
      v39 = v36 - v37 + v38;
    if ( v39 > v38 )
    {
      result = 0;
      __break(0x800u);
      goto LABEL_67;
    }
    if ( v39 )
      qrtr_gunyah_read(v5);
  }
  result = 0;
LABEL_67:
  _ReadStatusReg(SP_EL0);
  return result;
}
