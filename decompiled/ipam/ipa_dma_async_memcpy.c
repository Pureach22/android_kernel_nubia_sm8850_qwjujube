__int64 __fastcall ipa_dma_async_memcpy(
        unsigned __int64 a1,
        unsigned __int64 a2,
        unsigned int a3,
        _QWORD *a4,
        __int64 a5)
{
  __int64 v5; // x26
  __int64 v6; // x27
  __int64 ipc_logbuf_low; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  unsigned __int64 v16; // x9
  unsigned __int64 v17; // x10
  __int64 v18; // x0
  _UNKNOWN **v19; // x19
  unsigned int ep_mapping; // w0
  _QWORD *v21; // x1
  unsigned int v22; // w0
  __int64 v23; // x0
  __int64 v24; // x8
  __int64 v25; // x0
  void *v26; // x2
  int hw_type; // w0
  __int64 v28; // x8
  unsigned int v29; // w0
  __int64 v30; // x10
  __int64 v31; // x0
  unsigned int v32; // w0
  __int64 v33; // x8
  __int64 v34; // x0
  unsigned int v35; // w0
  __int64 v36; // x10
  __int64 v37; // x0
  unsigned int v38; // w0
  unsigned int v39; // w22
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x8
  unsigned int v46; // w0
  __int64 v47; // x8
  __int64 v48; // x0
  unsigned int v49; // w0
  __int64 v50; // x0
  __int64 result; // x0
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 ipc_logbuf; // x0
  __int64 v55; // x0
  __int64 v56; // x0
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x0
  __int64 v62; // x0
  __int64 v63; // x0
  __int64 v64; // x0
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x0
  __int64 v68; // x0
  __int64 v69; // x0
  __int64 v70; // x0
  __int64 v71; // x0
  __int64 v72; // x0
  __int64 v73; // x0
  __int64 v74; // x0
  __int64 v75; // x0
  __int64 v76; // x0
  __int64 v77; // x0
  __int64 v78; // x0
  __int64 v79; // x0
  __int64 v80; // x0
  __int64 v81; // x0
  __int64 v82; // x0
  __int64 v83; // x0
  __int64 v84; // x0
  __int64 v85; // x0
  __int64 v86; // x0
  __int64 v87; // x0
  __int64 v88; // x0
  __int64 v89; // x0
  __int64 v90; // x0
  __int64 v91; // x0
  __int64 v92; // x0
  __int64 v93; // x0
  __int64 v94; // x0
  __int64 v95; // x0
  __int64 v96; // x0
  __int64 v97; // x0
  __int64 v98; // x0
  __int64 v99; // x0
  __int64 v100; // x0
  __int64 v101; // x0
  __int64 v102; // x0
  __int64 v103; // x0
  __int64 v104; // x0
  __int64 v105; // x0
  __int64 v106; // x0
  __int64 v107; // x0
  __int64 v108; // x0
  __int64 v109; // x0
  _QWORD *v110; // x8
  __int64 v111; // x9
  __int64 v112; // x0
  unsigned int v119; // w9
  unsigned int v120; // w19
  unsigned int v123; // w10
  unsigned __int64 v124; // [xsp+8h] [xbp-38h] BYREF
  __int64 v125; // [xsp+10h] [xbp-30h]
  __int64 v126; // [xsp+18h] [xbp-28h]
  unsigned __int64 v127; // [xsp+20h] [xbp-20h] BYREF
  __int64 v128; // [xsp+28h] [xbp-18h]
  _UNKNOWN **v129; // [xsp+30h] [xbp-10h]
  __int64 v130; // [xsp+38h] [xbp-8h]

  v130 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v128 = 0;
  v129 = nullptr;
  v126 = 0;
  v127 = 0;
  v124 = 0;
  v125 = 0;
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(a1);
  if ( ipc_logbuf_low )
  {
    v13 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_logbuf_low = ipc_log_string(v13, "ipa_dma %s:%d ENTRY\n", "ipa_dma_async_memcpy", 784);
  }
  v14 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
  if ( v14 )
  {
    v15 = ipa3_get_ipc_logbuf_low(v14);
    ipc_log_string(
      v15,
      "ipa_dma %s:%d dest =  0x%llx, src = 0x%llx, len = %d\n",
      "ipa_dma_async_memcpy",
      786,
      a1,
      a2,
      a3);
  }
  if ( !ipa3_dma_ctx )
  {
    v53 = printk(&unk_3C6AD0, "ipa_dma_async_memcpy");
    ipc_logbuf = ipa3_get_ipc_logbuf(v53);
    if ( ipc_logbuf )
    {
      v55 = ipa3_get_ipc_logbuf(ipc_logbuf);
      ipc_logbuf = ipc_log_string(
                     v55,
                     "ipa_dma %s:%d IPADMA isn't initialized, can't memcpy\n",
                     "ipa_dma_async_memcpy",
                     788);
    }
    v56 = ipa3_get_ipc_logbuf_low(ipc_logbuf);
    if ( v56 )
    {
      v57 = ipa3_get_ipc_logbuf_low(v56);
      ipc_log_string(v57, "ipa_dma %s:%d IPADMA isn't initialized, can't memcpy\n", "ipa_dma_async_memcpy", 788);
    }
    result = 0xFFFFFFFFLL;
    goto LABEL_111;
  }
  if ( a2 <= a1 )
    v16 = a1;
  else
    v16 = a2;
  if ( a2 >= a1 )
    v17 = a1;
  else
    v17 = a2;
  if ( v16 - v17 < (int)a3 )
  {
    v58 = printk(&unk_3CF782, "ipa_dma_async_memcpy");
    v59 = ipa3_get_ipc_logbuf(v58);
    if ( v59 )
    {
      v60 = ipa3_get_ipc_logbuf(v59);
      v59 = ipc_log_string(v60, "ipa_dma %s:%d invalid addresses - overlapping buffers\n", "ipa_dma_async_memcpy", 792);
    }
    v61 = ipa3_get_ipc_logbuf_low(v59);
    if ( v61 )
    {
      v62 = ipa3_get_ipc_logbuf_low(v61);
      ipc_log_string(v62, "ipa_dma %s:%d invalid addresses - overlapping buffers\n", "ipa_dma_async_memcpy", 792);
LABEL_57:
      result = 4294967274LL;
      goto LABEL_111;
    }
LABEL_58:
    result = 4294967274LL;
    goto LABEL_111;
  }
  if ( a3 - 0x10000 <= 0xFFFF0000 )
  {
    v63 = printk(&unk_3F7C64, "ipa_dma_async_memcpy");
    v64 = ipa3_get_ipc_logbuf(v63);
    if ( v64 )
    {
      v65 = ipa3_get_ipc_logbuf(v64);
      v64 = ipc_log_string(v65, "ipa_dma %s:%d invalid len, %d\n", "ipa_dma_async_memcpy", 796, a3);
    }
    v66 = ipa3_get_ipc_logbuf_low(v64);
    if ( v66 )
    {
      v67 = ipa3_get_ipc_logbuf_low(v66);
      ipc_log_string(v67, "ipa_dma %s:%d invalid len, %d\n", "ipa_dma_async_memcpy", 796, a3);
      result = 4294967274LL;
      goto LABEL_111;
    }
    goto LABEL_58;
  }
  if ( !a4 )
  {
    v68 = printk(&unk_3D5644, "ipa_dma_async_memcpy");
    v69 = ipa3_get_ipc_logbuf(v68);
    if ( v69 )
    {
      v70 = ipa3_get_ipc_logbuf(v69);
      v69 = ipc_log_string(v70, "ipa_dma %s:%d null pointer: user_cb\n", "ipa_dma_async_memcpy", 800);
    }
    v71 = ipa3_get_ipc_logbuf_low(v69);
    if ( v71 )
    {
      v72 = ipa3_get_ipc_logbuf_low(v71);
      ipc_log_string(v72, "ipa_dma %s:%d null pointer: user_cb\n", "ipa_dma_async_memcpy", 800);
      goto LABEL_57;
    }
    goto LABEL_58;
  }
  v18 = raw_spin_lock_irqsave(ipa3_dma_ctx + 120);
  v19 = (_UNKNOWN **)v18;
  if ( !*(_DWORD *)ipa3_dma_ctx )
  {
    v73 = printk(&unk_3E62A0, "ipa_dma_async_memcpy");
    v74 = ipa3_get_ipc_logbuf(v73);
    if ( v74 )
    {
      v75 = ipa3_get_ipc_logbuf(v74);
      v74 = ipc_log_string(v75, "ipa_dma %s:%d can't memcpy, IPA_DMA isn't enabled\n", "ipa_dma_async_memcpy", 805);
    }
    v76 = ipa3_get_ipc_logbuf_low(v74);
    if ( v76 )
    {
      v77 = ipa3_get_ipc_logbuf_low(v76);
      ipc_log_string(v77, "ipa_dma %s:%d can't memcpy, IPA_DMA isn't enabled\n", "ipa_dma_async_memcpy", 805);
    }
    raw_spin_unlock_irqrestore(ipa3_dma_ctx + 120, v19);
    result = 0xFFFFFFFFLL;
    goto LABEL_111;
  }
  _X8 = (unsigned int *)(ipa3_dma_ctx + 180);
  __asm { PRFM            #0x11, [X8] }
  do
    v119 = __ldxr(_X8);
  while ( __stxr(v119 + 1, _X8) );
  raw_spin_unlock_irqrestore(ipa3_dma_ctx + 120, v18);
  ep_mapping = ipa_get_ep_mapping(47);
  if ( ep_mapping == -1 )
  {
    v78 = printk(&unk_3D2709, "ipa_dma_async_memcpy");
    v79 = ipa3_get_ipc_logbuf(v78);
    if ( v79 )
    {
      v80 = ipa3_get_ipc_logbuf(v79);
      v79 = ipc_log_string(v80, "ipa_dma %s:%d Client %u is not mapped\n", "ipa_dma_async_memcpy", 815, 47);
    }
    v81 = ipa3_get_ipc_logbuf_low(v79);
    if ( v81 )
    {
      v82 = ipa3_get_ipc_logbuf_low(v81);
      ipc_log_string(v82, "ipa_dma %s:%d Client %u is not mapped\n", "ipa_dma_async_memcpy", 815, 47);
LABEL_72:
      result = 4294967282LL;
      goto LABEL_111;
    }
LABEL_73:
    result = 4294967282LL;
    goto LABEL_111;
  }
  if ( ep_mapping >= 0x24 )
  {
LABEL_101:
    __break(0x5512u);
    goto LABEL_102;
  }
  v19 = &off_1F7000;
  v6 = *(_QWORD *)(ipa3_ctx + 480LL * ep_mapping + 640);
  v22 = ipa_get_ep_mapping(46);
  if ( v22 == -1 )
  {
    v83 = printk(&unk_3D2709, "ipa_dma_async_memcpy");
    v84 = ipa3_get_ipc_logbuf(v83);
    if ( v84 )
    {
      v85 = ipa3_get_ipc_logbuf(v84);
      v84 = ipc_log_string(v85, "ipa_dma %s:%d Client %u is not mapped\n", "ipa_dma_async_memcpy", 823, 46);
    }
    v86 = ipa3_get_ipc_logbuf_low(v84);
    if ( v86 )
    {
      v87 = ipa3_get_ipc_logbuf_low(v86);
      ipc_log_string(v87, "ipa_dma %s:%d Client %u is not mapped\n", "ipa_dma_async_memcpy", 823, 46);
      goto LABEL_72;
    }
    goto LABEL_73;
  }
  if ( v22 > 0x23 )
    goto LABEL_101;
  v5 = *(_QWORD *)(ipa3_ctx + 480LL * v22 + 640);
  v23 = kmem_cache_alloc_noprof(*(_QWORD *)(ipa3_dma_ctx + 8), 3520);
  v19 = (_UNKNOWN **)v23;
  if ( !v23 )
  {
    result = 4294967284LL;
    goto LABEL_106;
  }
  v24 = ipa3_dma_ctx;
  *(_QWORD *)v23 = a2;
  *(_QWORD *)(v23 + 8) = a1;
  *(_WORD *)(v23 + 16) = a3;
  *(_QWORD *)(v23 + 72) = a4;
  *(_QWORD *)(v23 + 80) = a5;
  v25 = raw_spin_lock_irqsave(v24 + 64);
  a4 = v19 + 3;
  v26 = (void *)(v6 + 1632);
  v21 = *(_QWORD **)(v6 + 1640);
  a5 = v25;
  if ( v19 + 3 != (_UNKNOWN **)(v6 + 1632) && v21 != a4 && (void *)*v21 == v26 )
  {
    *(_QWORD *)(v6 + 1640) = a4;
    v19[3] = v26;
    v19[4] = v21;
    *v21 = a4;
    goto LABEL_26;
  }
LABEL_102:
  _list_add_valid_or_report(a4, v21);
LABEL_26:
  ++*(_DWORD *)v6;
  hw_type = ipa_get_hw_type();
  v127 = a1;
  LOWORD(v128) = a3;
  HIDWORD(v128) = 0;
  WORD1(v128) = 512;
  if ( a3 <= 8 && hw_type == 12 )
  {
    v28 = *(_QWORD *)(v6 + 1624);
    v129 = nullptr;
    v29 = gsi_queue_xfer(*(_QWORD *)(v28 + 8), 1, &v127, 0);
    if ( v29 )
    {
      v39 = v29;
      v92 = printk(&unk_3A9A27, "ipa_dma_async_memcpy");
      v93 = ipa3_get_ipc_logbuf(v92);
      if ( v93 )
      {
        v94 = ipa3_get_ipc_logbuf(v93);
        v93 = ipc_log_string(
                v94,
                "ipa_dma %s:%d Failed: gsi_queue_xfer on dest descr res: %d\n",
                "ipa_dma_async_memcpy",
                859,
                v39);
      }
      v95 = ipa3_get_ipc_logbuf_low(v93);
      if ( v95 )
      {
        v96 = ipa3_get_ipc_logbuf_low(v95);
        ipc_log_string(
          v96,
          "ipa_dma %s:%d Failed: gsi_queue_xfer on dest descr res: %d\n",
          "ipa_dma_async_memcpy",
          859,
          v39);
      }
      goto LABEL_96;
    }
    v30 = *(_QWORD *)(v6 + 1624);
    v128 = 33554440;
    v129 = v19;
    v31 = *(_QWORD *)(v30 + 8);
    v127 = *(_QWORD *)(ipa3_dma_ctx + 280);
    v32 = gsi_queue_xfer(v31, 1, &v127, 1);
    if ( v32 )
    {
      v39 = v32;
      v101 = printk(&unk_3D566B, "ipa_dma_async_memcpy");
      v102 = ipa3_get_ipc_logbuf(v101);
      if ( v102 )
      {
        v103 = ipa3_get_ipc_logbuf(v102);
        v102 = ipc_log_string(
                 v103,
                 "ipa_dma %s:%d Failed: gsi_queue_xfer on dummy dest descr res: %d\n",
                 "ipa_dma_async_memcpy",
                 873,
                 v39);
      }
      v104 = ipa3_get_ipc_logbuf_low(v102);
      if ( v104 )
      {
        v105 = ipa3_get_ipc_logbuf_low(v104);
        ipc_log_string(
          v105,
          "ipa_dma %s:%d Failed: gsi_queue_xfer on dummy dest descr res: %d\n",
          "ipa_dma_async_memcpy",
          873,
          v39);
      }
      goto LABEL_96;
    }
    v33 = *(_QWORD *)(v5 + 1624);
    LOWORD(v125) = a3;
    HIDWORD(v125) = 0;
    WORD1(v125) = 1;
    v126 = 0;
    v34 = *(_QWORD *)(v33 + 8);
    v124 = a2;
    v35 = gsi_queue_xfer(v34, 1, &v124, 0);
    if ( v35 )
    {
      v39 = v35;
      v106 = printk(&unk_3B7DAE, "ipa_dma_async_memcpy");
      v107 = ipa3_get_ipc_logbuf(v106);
      if ( v107 )
      {
        v108 = ipa3_get_ipc_logbuf(v107);
        v107 = ipc_log_string(
                 v108,
                 "ipa_dma %s:%d Failed: gsi_queue_xfer on src descr res: %d\n",
                 "ipa_dma_async_memcpy",
                 887,
                 v39);
      }
      v43 = ipa3_get_ipc_logbuf_low(v107);
      if ( v43 )
      {
        v109 = ipa3_get_ipc_logbuf_low(v43);
        v43 = ipc_log_string(
                v109,
                "ipa_dma %s:%d Failed: gsi_queue_xfer on src descr res: %d\n",
                "ipa_dma_async_memcpy",
                887,
                v39);
      }
      goto LABEL_95;
    }
    v36 = *(_QWORD *)(v5 + 1624);
    v125 = 33554440;
    v126 = 0;
    v37 = *(_QWORD *)(v36 + 8);
    v124 = *(_QWORD *)(ipa3_dma_ctx + 256);
    v38 = gsi_queue_xfer(v37, 1, &v124, 1);
    if ( v38 )
    {
      v39 = v38;
      v40 = printk(&unk_3B1F9F, "ipa_dma_async_memcpy");
      v41 = ipa3_get_ipc_logbuf(v40);
      if ( v41 )
      {
        v42 = ipa3_get_ipc_logbuf(v41);
        v41 = ipc_log_string(
                v42,
                "ipa_dma %s:%d Failed: gsi_queue_xfer on dummy src descr res: %d\n",
                "ipa_dma_async_memcpy",
                902,
                v39);
      }
      v43 = ipa3_get_ipc_logbuf_low(v41);
      if ( v43 )
      {
        v44 = ipa3_get_ipc_logbuf_low(v43);
        v43 = ipc_log_string(
                v44,
                "ipa_dma %s:%d Failed: gsi_queue_xfer on dummy src descr res: %d\n",
                "ipa_dma_async_memcpy",
                902,
                v39);
      }
LABEL_95:
      ((void (__fastcall *)(__int64))ipa_assert)(v43);
LABEL_96:
      v110 = v19[4];
      if ( (_QWORD *)*v110 == a4 && (v111 = *a4, *(_QWORD **)(*a4 + 8LL) == a4) )
      {
        *(_QWORD *)(v111 + 8) = v110;
        *v110 = v111;
      }
      else
      {
        _list_del_entry_valid_or_report(a4);
      }
      v112 = ipa3_dma_ctx + 64;
      v19[3] = (_UNKNOWN *)0xDEAD000000000100LL;
      v19[4] = (_UNKNOWN *)0xDEAD000000000122LL;
      raw_spin_unlock_irqrestore(v112, a5);
      kmem_cache_free(*(_QWORD *)(ipa3_dma_ctx + 8), v19);
      result = v39;
LABEL_106:
      _X8 = (unsigned int *)(ipa3_dma_ctx + 180);
      __asm { PRFM            #0x11, [X8] }
      do
        v123 = __ldxr(_X8);
      while ( __stxr(v123 - 1, _X8) );
      if ( *(_BYTE *)(ipa3_dma_ctx + 4) == 1 )
      {
        v120 = result;
        if ( (ipa3_dma_work_pending(result) & 1) == 0 )
          complete(ipa3_dma_ctx + 128);
        result = v120;
      }
      goto LABEL_111;
    }
  }
  else
  {
    v45 = *(_QWORD *)(v6 + 1624);
    v129 = v19;
    v46 = gsi_queue_xfer(*(_QWORD *)(v45 + 8), 1, &v127, 1);
    if ( v46 )
    {
      v39 = v46;
      v88 = printk(&unk_3D566B, "ipa_dma_async_memcpy");
      v89 = ipa3_get_ipc_logbuf(v88);
      if ( v89 )
      {
        v90 = ipa3_get_ipc_logbuf(v89);
        v89 = ipc_log_string(
                v90,
                "ipa_dma %s:%d Failed: gsi_queue_xfer on dummy dest descr res: %d\n",
                "ipa_dma_async_memcpy",
                918,
                v39);
      }
      v43 = ipa3_get_ipc_logbuf_low(v89);
      if ( v43 )
      {
        v91 = ipa3_get_ipc_logbuf_low(v43);
        v43 = ipc_log_string(
                v91,
                "ipa_dma %s:%d Failed: gsi_queue_xfer on dummy dest descr res: %d\n",
                "ipa_dma_async_memcpy",
                918,
                v39);
      }
      goto LABEL_95;
    }
    LOWORD(v125) = a3;
    WORD1(v125) = 512;
    v47 = *(_QWORD *)(v5 + 1624);
    HIDWORD(v125) = 0;
    v126 = 0;
    v48 = *(_QWORD *)(v47 + 8);
    v124 = a2;
    v49 = gsi_queue_xfer(v48, 1, &v124, 1);
    if ( v49 )
    {
      v39 = v49;
      v97 = printk(&unk_3B1F9F, "ipa_dma_async_memcpy");
      v98 = ipa3_get_ipc_logbuf(v97);
      if ( v98 )
      {
        v99 = ipa3_get_ipc_logbuf(v98);
        v98 = ipc_log_string(
                v99,
                "ipa_dma %s:%d Failed: gsi_queue_xfer on dummy src descr res: %d\n",
                "ipa_dma_async_memcpy",
                932,
                v39);
      }
      v43 = ipa3_get_ipc_logbuf_low(v98);
      if ( v43 )
      {
        v100 = ipa3_get_ipc_logbuf_low(v43);
        v43 = ipc_log_string(
                v100,
                "ipa_dma %s:%d Failed: gsi_queue_xfer on dummy src descr res: %d\n",
                "ipa_dma_async_memcpy",
                932,
                v39);
      }
      goto LABEL_95;
    }
  }
  v50 = raw_spin_unlock_irqrestore(ipa3_dma_ctx + 64, a5);
  result = ipa3_get_ipc_logbuf_low(v50);
  if ( result )
  {
    v52 = ipa3_get_ipc_logbuf_low(result);
    ipc_log_string(v52, "ipa_dma %s:%d EXIT\n", "ipa_dma_async_memcpy", 939);
    result = 0;
  }
LABEL_111:
  _ReadStatusReg(SP_EL0);
  return result;
}
