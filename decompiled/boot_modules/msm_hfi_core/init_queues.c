__int64 __fastcall init_queues(unsigned int a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  _DWORD *v5; // x30
  _DWORD *v6; // x27
  _DWORD *v8; // x19
  unsigned __int64 v9; // x21
  _DWORD *v10; // x24
  __int64 v11; // x3
  __int64 v12; // x4
  unsigned int *v13; // x20
  unsigned int v14; // w8
  unsigned int *v15; // x25
  unsigned int queue_mem_req; // w28
  int v17; // w0
  __int64 v18; // x4
  int v19; // w19
  unsigned int v20; // w8
  int v21; // w24
  __int64 v22; // x9
  _QWORD *v23; // x0
  __int64 v24; // x10
  __int64 v25; // x8
  _QWORD *v26; // x0
  unsigned __int64 v27; // x25
  unsigned int v28; // w8
  __int64 v29; // x1
  unsigned int v30; // w0
  __int64 v31; // x1
  unsigned int v32; // w0
  __int64 v33; // x1
  unsigned int v34; // w0
  __int64 v35; // x1
  unsigned int v36; // w0
  int v37; // w8
  unsigned int v38; // w8
  __int64 v39; // x1
  unsigned int v40; // w0
  unsigned int v41; // w0
  __int64 v42; // x1
  unsigned int v43; // w0
  unsigned int v44; // w0
  __int64 v45; // x1
  unsigned int v46; // w0
  unsigned int v47; // w0
  __int64 v48; // x1
  unsigned int v49; // w0
  unsigned int v50; // w0
  int v51; // w8
  __int64 result; // x0
  _DWORD *v53; // x30
  void *v54; // x0
  __int64 v55; // x2
  void *v56; // x0
  __int64 v57; // x2
  _DWORD *v58; // x30
  __int64 v59; // x4
  void *v60; // x0
  __int64 v61; // x2
  __int64 v62; // x4
  void *v63; // x0
  __int64 v64; // x2
  _DWORD *v65; // x30
  void *v66; // x0
  __int64 v67; // x2
  __int64 v68; // x0
  __int64 v69; // x0
  __int64 v70; // x0
  __int64 v71; // x0
  __int64 v72; // x0
  __int64 v73; // x0
  __int64 v74; // x0
  __int64 v75; // x0
  __int64 v76; // x4
  _DWORD *v77; // x3
  unsigned __int64 StatusReg; // x25
  _DWORD *v79; // x28
  __int64 (__fastcall *v80)(_QWORD, _QWORD); // x0
  __int64 v81; // x27
  unsigned __int64 v82; // [xsp+10h] [xbp-40h]
  _DWORD *v83; // [xsp+18h] [xbp-38h]
  __int64 v84; // [xsp+20h] [xbp-30h] BYREF
  const char *v85; // [xsp+28h] [xbp-28h]
  __int64 v86; // [xsp+30h] [xbp-20h]
  unsigned __int64 v87; // [xsp+38h] [xbp-18h]
  __int64 v88; // [xsp+40h] [xbp-10h]
  __int64 v89; // [xsp+48h] [xbp-8h]

  v6 = v5;
  LODWORD(v8) = a1;
  v89 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    printk(&unk_1E83A, "init_queues", 718, a4, a5);
    if ( (unsigned int)v8 < 4 )
      goto LABEL_3;
LABEL_91:
    printk(&unk_1D5EB, "init_queues", 721, v6, (unsigned int)v8);
    result = 4294967274LL;
    goto LABEL_151;
  }
  if ( a1 >= 4 )
    goto LABEL_91;
LABEL_3:
  if ( !a2 || (v9 = a2 + 16, (v10 = *(_DWORD **)(a2 + 16 + 176LL * (unsigned int)v8 + 88)) == nullptr) )
  {
    v53 = v6;
    v54 = &unk_1905C;
    v55 = 727;
LABEL_93:
    printk(v54, "init_queues", v55, v53, a5);
    result = 4294967274LL;
    goto LABEL_151;
  }
  if ( !*v10 )
  {
    v53 = v6;
    v54 = &unk_198C9;
    v55 = 734;
    goto LABEL_93;
  }
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    printk(&unk_1E83A, "setup_vq_queues", 661, a4, a5);
  v13 = (unsigned int *)_kmalloc_cache_noprof(mbox_send_message, 3520, 104);
  if ( !v13 )
    goto LABEL_154;
  do
  {
    *(_QWORD *)(v9 + 176LL * (unsigned int)v8 + 128) = v13;
    v82 = v9 + 176LL * (unsigned int)v8;
    v83 = v6;
    v14 = v10[12];
    *v13 = v14;
    if ( !v14 )
    {
LABEL_41:
      v27 = v82;
      v8 = *(_DWORD **)(v82 + 88);
      if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
        printk(&unk_1E83A, "add_tx_buffers_to_pool", 474, v11, v12);
      a2 = *(_QWORD *)(v82 + 128);
      v10 = v83;
      if ( !a2 )
      {
        v8 = v83;
        printk(&unk_1905C, "add_tx_buffers_to_pool", 477, v83, v12);
        a2 = 4294967274LL;
LABEL_121:
        v63 = &unk_1990F;
        v64 = 685;
        goto LABEL_128;
      }
      v28 = *(_DWORD *)a2;
      if ( !*(_DWORD *)a2 )
        goto LABEL_61;
      v29 = *(_QWORD *)(a2 + 16);
      if ( v29 )
      {
        v30 = submit_all_buffers(1, v29, v8 + 44, (unsigned int)v8[29], (unsigned int)v8[31], 1);
        if ( v30 )
        {
          a2 = v30;
          v9 = 0;
          goto LABEL_120;
        }
        v28 = *(_DWORD *)a2;
      }
      if ( v28 < 2 )
        goto LABEL_61;
      v31 = *(_QWORD *)(a2 + 40);
      if ( v31 )
      {
        v9 = 1;
        v32 = submit_all_buffers(1, v31, v8 + 72, (unsigned int)v8[57], (unsigned int)v8[59], 1);
        if ( v32 )
        {
          a2 = v32;
          goto LABEL_120;
        }
        v28 = *(_DWORD *)a2;
      }
      if ( v28 < 3 )
        goto LABEL_61;
      v33 = *(_QWORD *)(a2 + 64);
      if ( !v33 )
        goto LABEL_56;
      v34 = submit_all_buffers(1, v33, v8 + 100, (unsigned int)v8[85], (unsigned int)v8[87], 1);
      if ( !v34 )
      {
        v28 = *(_DWORD *)a2;
LABEL_56:
        if ( v28 < 4 )
          goto LABEL_61;
        v35 = *(_QWORD *)(a2 + 88);
        if ( !v35 )
        {
LABEL_60:
          if ( v28 > 4 )
            goto LABEL_153;
LABEL_61:
          v37 = msm_hfi_core_debug_level;
          if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
          {
            printk(&unk_1C28B, "add_tx_buffers_to_pool", 500, v11, v12);
            v37 = msm_hfi_core_debug_level;
          }
          a2 = *(_QWORD *)(v82 + 88);
          if ( (~v37 & 0x10001) != 0 )
          {
            v8 = *(_DWORD **)(v82 + 128);
            if ( v8 )
              goto LABEL_65;
          }
          else
          {
            printk(&unk_1E83A, "add_rx_buffers_to_fw_queue", 513, v11, v12);
            v8 = *(_DWORD **)(v82 + 128);
            if ( v8 )
            {
LABEL_65:
              v38 = *v8;
              if ( !*v8 )
                goto LABEL_86;
              v39 = *((_QWORD *)v8 + 3);
              if ( v39 )
              {
                v40 = submit_all_buffers(2, v39, a2 + 176, *(unsigned int *)(a2 + 120), *(unsigned int *)(a2 + 128), 0);
                if ( v40 )
                {
                  a2 = v40;
                  v9 = 0;
                  goto LABEL_123;
                }
                v41 = set_param_hfi_queue(*((_QWORD *)v8 + 3), 5u, 0, 0);
                if ( v41 )
                {
                  a2 = v41;
                  v62 = 0;
                  goto LABEL_125;
                }
                v38 = *v8;
              }
              if ( v38 < 2 )
                goto LABEL_86;
              v42 = *((_QWORD *)v8 + 6);
              if ( v42 )
              {
                v43 = submit_all_buffers(2, v42, a2 + 288, *(unsigned int *)(a2 + 232), *(unsigned int *)(a2 + 240), 0);
                if ( v43 )
                {
                  a2 = v43;
                  v9 = 1;
                  goto LABEL_123;
                }
                v44 = set_param_hfi_queue(*((_QWORD *)v8 + 6), 5u, 0, 0);
                if ( v44 )
                {
                  a2 = v44;
                  v62 = 1;
                  goto LABEL_125;
                }
                v38 = *v8;
              }
              if ( v38 < 3 )
                goto LABEL_86;
              v45 = *((_QWORD *)v8 + 9);
              if ( !v45 )
                goto LABEL_80;
              v9 = 2;
              v46 = submit_all_buffers(2, v45, a2 + 400, *(unsigned int *)(a2 + 344), *(unsigned int *)(a2 + 352), 0);
              if ( v46 )
              {
                a2 = v46;
                goto LABEL_123;
              }
              v47 = set_param_hfi_queue(*((_QWORD *)v8 + 9), 5u, 0, 0);
              if ( !v47 )
              {
                v38 = *v8;
LABEL_80:
                if ( v38 < 4 )
                  goto LABEL_86;
                v48 = *((_QWORD *)v8 + 12);
                if ( !v48 )
                  goto LABEL_85;
                v49 = submit_all_buffers(2, v48, a2 + 512, *(unsigned int *)(a2 + 456), *(unsigned int *)(a2 + 464), 0);
                if ( !v49 )
                {
                  v50 = set_param_hfi_queue(*((_QWORD *)v8 + 12), 5u, 0, 0);
                  if ( !v50 )
                  {
                    v38 = *v8;
LABEL_85:
                    if ( v38 > 4 )
                      goto LABEL_153;
LABEL_86:
                    v51 = msm_hfi_core_debug_level;
                    if ( (~msm_hfi_core_debug_level & 0x10001) != 0
                      || (printk(&unk_1C28B, "add_rx_buffers_to_fw_queue", 548, v11, v12),
                          v51 = msm_hfi_core_debug_level,
                          (~msm_hfi_core_debug_level & 0x10001) != 0) )
                    {
                      if ( (~v51 & 0x10001) == 0 )
LABEL_100:
                        printk(&unk_1C28B, "init_queues", 744, v11, v12);
                    }
                    else
                    {
                      printk(&unk_1C28B, "setup_vq_queues", 696, v11, v12);
                      if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
                        goto LABEL_100;
                    }
                    result = 0;
                    goto LABEL_151;
                  }
                  a2 = v50;
                  v62 = 3;
                  goto LABEL_125;
                }
                a2 = v49;
                v9 = 3;
LABEL_123:
                v65 = v83;
                v66 = &unk_1B884;
                v67 = 534;
                v62 = (unsigned int)v9;
LABEL_126:
                v8 = v65;
                printk(v66, "add_rx_buffers_to_fw_queue", v67, v65, v62);
                goto LABEL_127;
              }
              a2 = v47;
              v62 = 2;
LABEL_125:
              v65 = v83;
              v66 = &unk_1CE37;
              v67 = 543;
              goto LABEL_126;
            }
          }
          v8 = v83;
          printk(&unk_1905C, "add_rx_buffers_to_fw_queue", 516, v83, v12);
          a2 = 4294967274LL;
LABEL_127:
          v63 = &unk_1C37E;
          v64 = 692;
LABEL_128:
          printk(v63, "setup_vq_queues", v64, v8, v59);
          if ( !*v13 )
            goto LABEL_149;
          goto LABEL_129;
        }
        v36 = submit_all_buffers(1, v35, v8 + 128, (unsigned int)v8[113], (unsigned int)v8[115], 1);
        if ( !v36 )
        {
          v28 = *(_DWORD *)a2;
          goto LABEL_60;
        }
        a2 = v36;
        v9 = 3;
        goto LABEL_120;
      }
      a2 = v34;
      v9 = 2;
LABEL_120:
      v8 = v83;
      printk(&unk_1D67D, "add_tx_buffers_to_pool", 495, v83, (unsigned int)v9);
      goto LABEL_121;
    }
    v6 = nullptr;
    v9 = 0;
    v15 = v10 + 26;
    while ( 1 )
    {
      v87 = 0;
      v88 = 0;
      v85 = nullptr;
      v86 = 0;
      v84 = 0;
      if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
        printk(&unk_1E83A, "create_queue", 560, v11, v12);
      if ( (_DWORD *)((char *)v6 + (_QWORD)v13) == (_DWORD *)-8LL || !v15 || !*(_QWORD *)a2 )
      {
        v10 = v83;
        v60 = &unk_1905C;
        v61 = 563;
LABEL_105:
        v8 = v10;
        printk(v60, "create_queue", v61, v10, v12);
        goto LABEL_108;
      }
      queue_mem_req = get_queue_mem_req(v15[3], 1024);
      v17 = get_queue_mem_req(v15[4], 1024);
      v18 = v15[14];
      if ( v17 + queue_mem_req > (unsigned int)v18 )
      {
        v10 = v83;
        v56 = &unk_1A0BC;
        v57 = 575;
        v58 = v83;
        goto LABEL_103;
      }
      if ( v6 == _ksymtab_hfi_core_release_rx_buffer )
        goto LABEL_152;
      v19 = v17;
      *(_DWORD *)((char *)v6 + (_QWORD)v13 + 8) = v15[2];
      v18 = v15[1];
      if ( (_DWORD)v18 == 1 )
      {
        v20 = v15[3];
        if ( !v20 )
          goto LABEL_94;
        v21 = 0;
        goto LABEL_29;
      }
      if ( (_DWORD)v18 == 2 )
        break;
      if ( (_DWORD)v18 != 3 || (v20 = v15[3]) == 0 || !v15[4] )
      {
LABEL_94:
        v10 = v83;
        v56 = &unk_1EBF6;
        v57 = 596;
        v58 = v83;
LABEL_103:
        v8 = v58;
        printk(v56, "create_queue", v57, v58, v18);
        goto LABEL_108;
      }
      v21 = 1;
LABEL_29:
      v84 = *(_QWORD *)a2;
      v85 = "HFI_TX_QUEUE";
      v22 = *((_QWORD *)v15 + 5);
      v87 = __PAIR64__(v20, queue_mem_req);
      LODWORD(v88) = 1024;
      v86 = v22;
      BYTE4(v88) = 1;
      v23 = create_hfi_queue(&v84);
      if ( (unsigned __int64)(v6 - 22) < 0xFFFFFFFFFFFFFF98LL )
        goto LABEL_152;
      *(_QWORD *)((char *)v6 + (_QWORD)v13 + 16) = v23;
      if ( !v23 )
      {
        v10 = v83;
        v60 = &unk_1DCB2;
        v61 = 612;
        goto LABEL_105;
      }
      if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
      {
        if ( v21 )
          goto LABEL_35;
      }
      else
      {
        printk(&unk_19094, "create_queue", 619, *v15, v15[2]);
        if ( (v21 & 1) != 0 )
          goto LABEL_35;
      }
LABEL_11:
      if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
        printk(&unk_1C28B, "create_queue", 644, v11, v12);
      ++v9;
      v6 += 6;
      v15 += 28;
      if ( v9 >= *v13 )
        goto LABEL_41;
    }
    if ( !v15[4] )
      goto LABEL_94;
LABEL_35:
    v24 = *(_QWORD *)a2;
    v88 = 0x100000400LL;
    v84 = v24;
    v85 = "HFI_RX_QUEUE";
    v25 = *((_QWORD *)v15 + 5);
    LODWORD(v87) = v19;
    v86 = v25 + queue_mem_req;
    HIDWORD(v87) = v15[4];
    v26 = create_hfi_queue(&v84);
    if ( (unsigned __int64)(v6 - 20) < 0xFFFFFFFFFFFFFF98LL )
      goto LABEL_152;
    *(_QWORD *)((char *)v6 + (_QWORD)v13 + 24) = v26;
    if ( v26 )
    {
      if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
        printk(&unk_1D3A3, "create_queue", 641, *v15, v15[2]);
      goto LABEL_11;
    }
    v8 = v83;
    printk(&unk_1C3B9, "create_queue", 634, v83, v12);
    if ( (unsigned __int64)(v6 - 22) < 0xFFFFFFFFFFFFFF98LL )
LABEL_152:
      __break(1u);
    destroy_hfi_queue(*(_QWORD *)((char *)v6 + (_QWORD)v13 + 16));
    v10 = v83;
LABEL_108:
    v27 = v82;
    printk(&unk_1C053, "setup_vq_queues", 677, v8, (unsigned int)v9);
    a2 = 4294967274LL;
    if ( !*v13 )
    {
LABEL_149:
      kfree(v13);
      *(_QWORD *)(v27 + 128) = 0;
      v77 = v10;
      goto LABEL_150;
    }
LABEL_129:
    v68 = *((_QWORD *)v13 + 2);
    if ( v68 )
      destroy_hfi_queue(v68);
    v69 = *((_QWORD *)v13 + 3);
    if ( v69 )
      destroy_hfi_queue(v69);
    if ( *v13 < 2 )
      goto LABEL_149;
    v70 = *((_QWORD *)v13 + 5);
    if ( v70 )
      destroy_hfi_queue(v70);
    v71 = *((_QWORD *)v13 + 6);
    if ( v71 )
      destroy_hfi_queue(v71);
    if ( *v13 < 3 )
      goto LABEL_149;
    v72 = *((_QWORD *)v13 + 8);
    if ( v72 )
      destroy_hfi_queue(v72);
    v73 = *((_QWORD *)v13 + 9);
    if ( v73 )
      destroy_hfi_queue(v73);
    if ( *v13 < 4 )
      goto LABEL_149;
    v74 = *((_QWORD *)v13 + 11);
    if ( v74 )
      destroy_hfi_queue(v74);
    v75 = *((_QWORD *)v13 + 12);
    if ( v75 )
      destroy_hfi_queue(v75);
    if ( *v13 <= 4 )
      goto LABEL_149;
LABEL_153:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v79 = v6;
    v80 = mbox_send_message;
    v81 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &setup_vq_queues__alloc_tag;
    v13 = (unsigned int *)_kmalloc_cache_noprof(v80, 3520, 104);
    *(_QWORD *)(StatusReg + 80) = v81;
    v6 = v79;
  }
  while ( v13 );
LABEL_154:
  printk(&unk_18E35, "setup_vq_queues", 666, v6, v12);
  v77 = v6;
  LODWORD(a2) = -12;
LABEL_150:
  printk(&unk_1CD56, "init_queues", 740, v77, v76);
  result = (unsigned int)a2;
LABEL_151:
  _ReadStatusReg(SP_EL0);
  return result;
}
