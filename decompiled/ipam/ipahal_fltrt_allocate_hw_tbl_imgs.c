__int64 __fastcall ipahal_fltrt_allocate_hw_tbl_imgs(_DWORD *a1)
{
  __int64 v1; // x21
  __int64 ipc_logbuf_low; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 ipc_logbuf; // x0
  __int64 v7; // x0
  __int64 v9; // x8
  unsigned int v10; // w9
  char *v11; // x24
  __int64 v12; // x1
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x1
  __int64 v16; // x8
  __int64 v17; // x0
  _DWORD *v18; // x8
  __int64 v19; // x0
  unsigned int v20; // w25
  void (__fastcall *v21)(__int64, __int64); // x10
  __int64 v22; // x1
  void (__fastcall *v23)(__int64, __int64); // x10
  __int64 v24; // x1
  unsigned int v25; // w24
  __int64 v26; // x0
  __int64 v27; // x0
  int v28; // w1
  __int64 v29; // x0
  unsigned int v30; // w21
  __int64 v31; // x0
  __int64 v32; // x0
  int v33; // w25
  _BYTE *v34; // x23
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x0
  __int64 v52; // x0

  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipahal %s:%d Entry\n", "ipahal_fltrt_allocate_hw_tbl_imgs", 5230);
  }
  if ( !a1 )
  {
    if ( !(unsigned int)__ratelimit(&ipahal_fltrt_allocate_hw_tbl_imgs__rs, "ipahal_fltrt_allocate_hw_tbl_imgs") )
    {
      if ( !ipa3_get_ipc_logbuf() )
        goto LABEL_13;
      goto LABEL_12;
    }
LABEL_79:
    printk(&unk_3CE9F3, "ipahal_fltrt_allocate_hw_tbl_imgs");
    if ( !ipa3_get_ipc_logbuf() )
    {
LABEL_13:
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v7 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v7, "ipahal %s:%d Input err: no params\n", "ipahal_fltrt_allocate_hw_tbl_imgs", 5234);
      }
      return 4294967274LL;
    }
LABEL_12:
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipahal %s:%d Input err: no params\n", "ipahal_fltrt_allocate_hw_tbl_imgs", 5234);
    goto LABEL_13;
  }
  if ( *a1 >= 2u )
  {
    if ( (unsigned int)__ratelimit(&ipahal_fltrt_allocate_hw_tbl_imgs__rs_72, "ipahal_fltrt_allocate_hw_tbl_imgs") )
    {
      printk(&unk_3C5F30, "ipahal_fltrt_allocate_hw_tbl_imgs");
      if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_8:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v5 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v5,
            "ipahal %s:%d Input err: Invalid ip type %d\n",
            "ipahal_fltrt_allocate_hw_tbl_imgs",
            5238,
            *a1);
        }
        return 4294967274LL;
      }
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
      goto LABEL_8;
    }
    v4 = ipa3_get_ipc_logbuf();
    ipc_log_string(v4, "ipahal %s:%d Input err: Invalid ip type %d\n", "ipahal_fltrt_allocate_hw_tbl_imgs", 5238, *a1);
    goto LABEL_8;
  }
  v9 = ipahal_ctx;
  v10 = *(_DWORD *)ipahal_ctx;
  if ( *(_DWORD *)ipahal_ctx >= 0x1Bu )
    goto LABEL_108;
  if ( v10 == 26 )
    goto LABEL_78;
  v11 = (char *)&ipahal_fltrt_objs + 152 * v10;
  v12 = (unsigned int)(*((_DWORD *)v11 + 6) * a1[1]);
  a1[16] = v12;
  v13 = dma_alloc_attrs(*(_QWORD *)(v9 + 32), v12, a1 + 14, 3264, 0);
  *((_QWORD *)a1 + 6) = v13;
  if ( !v13 )
  {
    v14 = dma_alloc_attrs(*(_QWORD *)(ipahal_ctx + 32), (unsigned int)a1[16], a1 + 14, 2080, 0);
    *((_QWORD *)a1 + 6) = v14;
    if ( !v14 )
    {
      if ( (unsigned int)__ratelimit(&ipa_fltrt_alloc_init_tbl_hdr__rs_237, "ipa_fltrt_alloc_init_tbl_hdr") )
      {
        printk(&unk_3A5920, "ipa_fltrt_alloc_init_tbl_hdr");
        if ( !ipa3_get_ipc_logbuf() )
        {
LABEL_68:
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v43 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v43,
              "ipahal %s:%d fail to alloc DMA buff of size %d\n",
              "ipa_fltrt_alloc_init_tbl_hdr",
              5074,
              a1[16]);
          }
LABEL_70:
          if ( (unsigned int)__ratelimit(&ipahal_fltrt_allocate_hw_tbl_imgs__rs_75, "ipahal_fltrt_allocate_hw_tbl_imgs") )
          {
            printk(&unk_3FD04C, "ipahal_fltrt_allocate_hw_tbl_imgs");
            if ( !ipa3_get_ipc_logbuf() )
            {
LABEL_73:
              if ( ipa3_get_ipc_logbuf_low() )
              {
                v45 = ipa3_get_ipc_logbuf_low();
                ipc_log_string(
                  v45,
                  "ipahal %s:%d fail to alloc and init tbl hdr\n",
                  "ipahal_fltrt_allocate_hw_tbl_imgs",
                  5243);
              }
              return 4294967284LL;
            }
          }
          else if ( !ipa3_get_ipc_logbuf() )
          {
            goto LABEL_73;
          }
          v44 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v44,
            "ipahal %s:%d fail to alloc and init tbl hdr\n",
            "ipahal_fltrt_allocate_hw_tbl_imgs",
            5243);
          goto LABEL_73;
        }
      }
      else if ( !ipa3_get_ipc_logbuf() )
      {
        goto LABEL_68;
      }
      v42 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v42,
        "ipahal %s:%d fail to alloc DMA buff of size %d\n",
        "ipa_fltrt_alloc_init_tbl_hdr",
        5074,
        a1[16]);
      goto LABEL_68;
    }
  }
  if ( *v11 == 1 )
  {
    v15 = (unsigned int)(*((_DWORD *)v11 + 6) * a1[1]);
    v16 = ipahal_ctx;
    a1[10] = v15;
    v17 = dma_alloc_attrs(*(_QWORD *)(v16 + 32), v15, a1 + 8, 3264, 0);
    *((_QWORD *)a1 + 3) = v17;
    if ( !v17 )
    {
      if ( (unsigned int)__ratelimit(&ipa_fltrt_alloc_init_tbl_hdr__rs_238, "ipa_fltrt_alloc_init_tbl_hdr") )
      {
        printk(&unk_3A5920, "ipa_fltrt_alloc_init_tbl_hdr");
        if ( !ipa3_get_ipc_logbuf() )
          goto LABEL_62;
      }
      else if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_62:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v41 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v41,
            "ipahal %s:%d fail to alloc DMA buff of size %d\n",
            "ipa_fltrt_alloc_init_tbl_hdr",
            5085,
            a1[10]);
        }
        ipahal_free_dma_mem((__int64)(a1 + 12));
        goto LABEL_70;
      }
      v40 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v40,
        "ipahal %s:%d fail to alloc DMA buff of size %d\n",
        "ipa_fltrt_alloc_init_tbl_hdr",
        5085,
        a1[10]);
      goto LABEL_62;
    }
  }
  v18 = *((_DWORD **)v11 + 9);
  if ( *(v18 - 1) != -490786288 )
    __break(0x8228u);
  v19 = ((__int64 (__fastcall *)(_QWORD, __int64))v18)(0, 4096);
  if ( a1[1] )
  {
    v1 = v19;
    v20 = 0;
    do
    {
      v21 = *((void (__fastcall **)(__int64, __int64))v11 + 7);
      v22 = *((_QWORD *)a1 + 6) + *((_DWORD *)v11 + 6) * v20;
      if ( *((_DWORD *)v21 - 1) != 1677333388 )
        __break(0x822Au);
      v21(v1, v22);
      if ( *v11 == 1 )
      {
        v23 = *((void (__fastcall **)(__int64, __int64))v11 + 7);
        v24 = *((_QWORD *)a1 + 3) + *((_DWORD *)v11 + 6) * v20;
        if ( *((_DWORD *)v23 - 1) != 1677333388 )
          __break(0x822Au);
        v23(v1, v24);
      }
      ++v20;
    }
    while ( v20 < a1[1] );
  }
  v25 = *(_DWORD *)ipahal_ctx;
  if ( *(_DWORD *)ipahal_ctx < 0x1Bu )
  {
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v26 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v26,
        "ipahal %s:%d lcl tbl bdy total effective sizes: hash=%u nhash=%u\n",
        "ipa_fltrt_alloc_lcl_bdy",
        5151,
        a1[4],
        a1[5]);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v27 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v27,
        "ipahal %s:%d lcl tbl bdy count: hash=%u nhash=%u\n",
        "ipa_fltrt_alloc_lcl_bdy",
        5155,
        a1[2],
        a1[3]);
    }
    v28 = a1[5];
    v29 = (unsigned int)a1[3];
    if ( v28 + (_DWORD)v29 )
    {
      a1[28] = ipa_fltrt_get_aligned_lcl_bdy_size(v29, v28);
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v31 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v31,
          "ipahal %s:%d nhash lcl tbl bdy total h/w size = %u\n",
          "ipa_fltrt_alloc_lcl_bdy",
          5166,
          a1[28]);
      }
      v30 = 3264;
      v32 = dma_alloc_attrs(*(_QWORD *)(ipahal_ctx + 32), (unsigned int)a1[28], a1 + 26, 3264, 0);
      *((_QWORD *)a1 + 12) = v32;
      if ( !v32 )
      {
        v30 = 2080;
        v46 = dma_alloc_attrs(*(_QWORD *)(ipahal_ctx + 32), (unsigned int)a1[28], a1 + 26, 2080, 0);
        *((_QWORD *)a1 + 12) = v46;
        if ( !v46 )
        {
          printk(&unk_3A5920, "ipa_fltrt_alloc_lcl_bdy");
          if ( ipa3_get_ipc_logbuf() )
          {
            v49 = ipa3_get_ipc_logbuf();
            ipc_log_string(
              v49,
              "ipahal %s:%d fail to alloc DMA buff of size %d\n",
              "ipa_fltrt_alloc_lcl_bdy",
              5178,
              a1[28]);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v50 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v50,
              "ipahal %s:%d fail to alloc DMA buff of size %d\n",
              "ipa_fltrt_alloc_lcl_bdy",
              5178,
              a1[28]);
          }
          goto LABEL_99;
        }
        v33 = 0;
        if ( v25 != 26 )
        {
LABEL_44:
          v34 = (char *)&ipahal_fltrt_objs + 152 * v25;
          if ( (*v34 & 1) == 0 )
          {
            if ( !a1[22] )
              return 0;
            printk(&unk_3D4940, "ipa_fltrt_alloc_lcl_bdy");
            if ( ipa3_get_ipc_logbuf() )
            {
              v47 = ipa3_get_ipc_logbuf();
              ipc_log_string(
                v47,
                "ipahal %s:%d No HAL Hash tbls support - Will be ignored\n",
                "ipa_fltrt_alloc_lcl_bdy",
                5184);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v48 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(
                v48,
                "ipahal %s:%d No HAL Hash tbls support - Will be ignored\n",
                "ipa_fltrt_alloc_lcl_bdy",
                5184);
            }
            __break(0x800u);
            if ( (*v34 & 1) == 0 )
              return 0;
          }
          if ( !a1[22] )
            return 0;
          a1[22] = ipa_fltrt_get_aligned_lcl_bdy_size((unsigned int)a1[2], a1[4]);
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v35 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v35,
              "ipahal %s:%d hash lcl tbl bdy total h/w size = %u\n",
              "ipa_fltrt_alloc_lcl_bdy",
              5194,
              a1[22]);
          }
          v36 = dma_alloc_attrs(*(_QWORD *)(ipahal_ctx + 32), (unsigned int)a1[22], a1 + 20, v30, 0);
          *((_QWORD *)a1 + 9) = v36;
          if ( v36 )
            return 0;
          if ( v33 )
          {
            v37 = dma_alloc_attrs(*(_QWORD *)(ipahal_ctx + 32), (unsigned int)a1[22], a1 + 20, 2080, 0);
            *((_QWORD *)a1 + 9) = v37;
            if ( v37 )
              return 0;
          }
          printk(&unk_3A5920, "ipa_fltrt_alloc_lcl_bdy");
          if ( ipa3_get_ipc_logbuf() )
          {
            v38 = ipa3_get_ipc_logbuf();
            ipc_log_string(
              v38,
              "ipahal %s:%d fail to alloc DMA buff of size %d\n",
              "ipa_fltrt_alloc_lcl_bdy",
              5206,
              a1[22]);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v39 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v39,
              "ipahal %s:%d fail to alloc DMA buff of size %d\n",
              "ipa_fltrt_alloc_lcl_bdy",
              5206,
              a1[22]);
          }
          if ( a1[28] )
            ipahal_free_dma_mem((__int64)(a1 + 24));
LABEL_99:
          if ( (unsigned int)__ratelimit(&ipahal_fltrt_allocate_hw_tbl_imgs__rs_78, "ipahal_fltrt_allocate_hw_tbl_imgs") )
          {
            printk(&unk_3B6E80, "ipahal_fltrt_allocate_hw_tbl_imgs");
            if ( !ipa3_get_ipc_logbuf() )
              goto LABEL_102;
          }
          else if ( !ipa3_get_ipc_logbuf() )
          {
LABEL_102:
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v52 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(v52, "ipahal %s:%d fail to alloc tbl bodies\n", "ipahal_fltrt_allocate_hw_tbl_imgs", 5248);
            }
            ipahal_free_dma_mem((__int64)(a1 + 12));
            if ( a1[10] )
              ipahal_free_dma_mem((__int64)(a1 + 6));
            return 4294967284LL;
          }
          v51 = ipa3_get_ipc_logbuf();
          ipc_log_string(v51, "ipahal %s:%d fail to alloc tbl bodies\n", "ipahal_fltrt_allocate_hw_tbl_imgs", 5248);
          goto LABEL_102;
        }
        goto LABEL_78;
      }
    }
    else
    {
      v30 = 3264;
    }
    v33 = 1;
    if ( v25 != 26 )
      goto LABEL_44;
LABEL_78:
    __break(1u);
    goto LABEL_79;
  }
LABEL_108:
  __break(0x5512u);
  return ipahal_fltrt_allocate_hw_sys_tbl(v1 | 0x7E00000);
}
