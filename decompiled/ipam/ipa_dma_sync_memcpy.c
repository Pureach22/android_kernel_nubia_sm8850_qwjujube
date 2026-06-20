__int64 __fastcall ipa_dma_sync_memcpy(unsigned __int64 a1, unsigned __int64 a2, unsigned int a3)
{
  __int64 ipc_logbuf_low; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  unsigned __int64 v10; // x9
  unsigned __int64 v11; // x10
  __int64 v12; // x0
  __int64 v13; // x19
  unsigned int ep_mapping; // w0
  __int64 v15; // x27
  unsigned int v16; // w0
  __int64 v17; // x26
  __int64 v18; // x0
  _QWORD *v19; // x19
  _QWORD *v20; // x21
  _QWORD **v21; // x23
  _QWORD *v22; // x1
  int hw_type; // w0
  int v25; // w8
  __int64 v26; // x8
  unsigned int v27; // w0
  __int64 v28; // x10
  __int64 v29; // x0
  unsigned int v30; // w0
  __int64 v31; // x8
  unsigned int v32; // w0
  __int64 v33; // x10
  __int64 v34; // x0
  unsigned int v35; // w0
  unsigned int v36; // w20
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x8
  unsigned int v43; // w0
  __int64 v44; // x9
  unsigned int v45; // w0
  _QWORD *v46; // x21
  __int64 v47; // x0
  int i; // w24
  int v49; // w0
  int v50; // w28
  __int64 v51; // x0
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x0
  __int64 v55; // x0
  __int64 v56; // x0
  bool v57; // zf
  _QWORD *v58; // x8
  __int64 v59; // x9
  _QWORD **v60; // x8
  __int64 v61; // x0
  __int64 result; // x0
  __int64 v63; // x0
  __int64 v64; // x0
  __int64 ipc_logbuf; // x0
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
  __int64 v110; // x0
  __int64 v111; // x0
  __int64 v112; // x0
  __int64 v113; // x0
  __int64 v114; // x0
  __int64 v115; // x0
  __int64 v116; // x0
  _QWORD *v117; // x8
  __int64 v118; // x9
  unsigned int v124; // w9
  __int64 v125; // x0
  __int64 v126; // x0
  __int64 v127; // x0
  __int64 v128; // x0
  __int64 v129; // x0
  unsigned int v130; // w19
  unsigned int v133; // w9
  unsigned int v136; // w10
  unsigned int v139; // w10
  int v140; // [xsp+Ch] [xbp-54h]
  __int64 v141; // [xsp+10h] [xbp-50h] BYREF
  __int64 v142; // [xsp+18h] [xbp-48h]
  __int64 v143; // [xsp+20h] [xbp-40h]
  unsigned __int64 v144; // [xsp+28h] [xbp-38h] BYREF
  __int64 v145; // [xsp+30h] [xbp-30h]
  _QWORD *v146; // [xsp+38h] [xbp-28h]
  unsigned __int64 v147; // [xsp+40h] [xbp-20h] BYREF
  __int64 v148; // [xsp+48h] [xbp-18h]
  __int64 v149; // [xsp+50h] [xbp-10h]
  __int64 v150; // [xsp+58h] [xbp-8h]

  v150 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v148 = 0;
  v149 = 0;
  v147 = 0;
  v145 = 0;
  v146 = nullptr;
  v143 = 0;
  v144 = 0;
  v141 = 0;
  v142 = 0;
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(a1);
  if ( ipc_logbuf_low )
  {
    v7 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_logbuf_low = ipc_log_string(v7, "ipa_dma %s:%d ENTRY\n", "ipa_dma_sync_memcpy", 540);
  }
  v8 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
  if ( v8 )
  {
    v9 = ipa3_get_ipc_logbuf_low(v8);
    ipc_log_string(v9, "ipa_dma %s:%d dest =  0x%llx, src = 0x%llx, len = %d\n", "ipa_dma_sync_memcpy", 542, a1, a2, a3);
  }
  if ( !ipa3_dma_ctx )
  {
    v64 = printk(&unk_3C6AD0, "ipa_dma_sync_memcpy");
    ipc_logbuf = ipa3_get_ipc_logbuf(v64);
    if ( ipc_logbuf )
    {
      v66 = ipa3_get_ipc_logbuf(ipc_logbuf);
      ipc_logbuf = ipc_log_string(
                     v66,
                     "ipa_dma %s:%d IPADMA isn't initialized, can't memcpy\n",
                     "ipa_dma_sync_memcpy",
                     544);
    }
    v67 = ipa3_get_ipc_logbuf_low(ipc_logbuf);
    if ( v67 )
    {
      v68 = ipa3_get_ipc_logbuf_low(v67);
      ipc_log_string(v68, "ipa_dma %s:%d IPADMA isn't initialized, can't memcpy\n", "ipa_dma_sync_memcpy", 544);
    }
    result = 0xFFFFFFFFLL;
    goto LABEL_72;
  }
  if ( a2 <= a1 )
    v10 = a1;
  else
    v10 = a2;
  if ( a2 >= a1 )
    v11 = a1;
  else
    v11 = a2;
  if ( v10 - v11 < (int)a3 )
  {
    v69 = printk(&unk_3CF782, "ipa_dma_sync_memcpy");
    v70 = ipa3_get_ipc_logbuf(v69);
    if ( v70 )
    {
      v71 = ipa3_get_ipc_logbuf(v70);
      v70 = ipc_log_string(v71, "ipa_dma %s:%d invalid addresses - overlapping buffers\n", "ipa_dma_sync_memcpy", 548);
    }
    v72 = ipa3_get_ipc_logbuf_low(v70);
    if ( v72 )
    {
      v73 = ipa3_get_ipc_logbuf_low(v72);
      ipc_log_string(v73, "ipa_dma %s:%d invalid addresses - overlapping buffers\n", "ipa_dma_sync_memcpy", 548);
      result = 4294967274LL;
      goto LABEL_72;
    }
LABEL_100:
    result = 4294967274LL;
    goto LABEL_72;
  }
  if ( a3 - 0x10000 <= 0xFFFF0000 )
  {
    v74 = printk(&unk_3F7C64, "ipa_dma_sync_memcpy");
    v75 = ipa3_get_ipc_logbuf(v74);
    if ( v75 )
    {
      v76 = ipa3_get_ipc_logbuf(v75);
      v75 = ipc_log_string(v76, "ipa_dma %s:%d invalid len, %d\n", "ipa_dma_sync_memcpy", 552, a3);
    }
    v77 = ipa3_get_ipc_logbuf_low(v75);
    if ( v77 )
    {
      v78 = ipa3_get_ipc_logbuf_low(v77);
      ipc_log_string(v78, "ipa_dma %s:%d invalid len, %d\n", "ipa_dma_sync_memcpy", 552, a3);
      result = 4294967274LL;
      goto LABEL_72;
    }
    goto LABEL_100;
  }
  v12 = raw_spin_lock_irqsave(ipa3_dma_ctx + 120);
  v13 = v12;
  if ( *(_DWORD *)ipa3_dma_ctx )
  {
    _X8 = (unsigned int *)(ipa3_dma_ctx + 176);
    __asm { PRFM            #0x11, [X8] }
    do
      v124 = __ldxr(_X8);
    while ( __stxr(v124 + 1, _X8) );
    raw_spin_unlock_irqrestore(ipa3_dma_ctx + 120, v12);
    ep_mapping = ipa_get_ep_mapping(45);
    if ( ep_mapping == -1 )
    {
      v84 = printk(&unk_3D2709, "ipa_dma_sync_memcpy");
      v85 = ipa3_get_ipc_logbuf(v84);
      if ( v85 )
      {
        v86 = ipa3_get_ipc_logbuf(v85);
        v85 = ipc_log_string(v86, "ipa_dma %s:%d Client %u is not mapped\n", "ipa_dma_sync_memcpy", 567, 45);
      }
      v87 = ipa3_get_ipc_logbuf_low(v85);
      if ( v87 )
      {
        v88 = ipa3_get_ipc_logbuf_low(v87);
        ipc_log_string(v88, "ipa_dma %s:%d Client %u is not mapped\n", "ipa_dma_sync_memcpy", 567, 45);
LABEL_99:
        result = 4294967282LL;
        goto LABEL_72;
      }
    }
    else
    {
      if ( ep_mapping >= 0x24 )
        goto LABEL_130;
      v15 = *(_QWORD *)(ipa3_ctx + 480LL * ep_mapping + 640);
      v16 = ipa_get_ep_mapping(44);
      if ( v16 != -1 )
      {
        if ( v16 <= 0x23 )
        {
          v17 = *(_QWORD *)(ipa3_ctx + 480LL * v16 + 640);
          v18 = kmem_cache_alloc_noprof(*(_QWORD *)(ipa3_dma_ctx + 8), 3520);
          v19 = (_QWORD *)v18;
          if ( !v18 )
          {
            v125 = printk(&unk_3AC858, "ipa_dma_sync_memcpy");
            v126 = ipa3_get_ipc_logbuf(v125);
            if ( v126 )
            {
              v127 = ipa3_get_ipc_logbuf(v126);
              v126 = ipc_log_string(
                       v127,
                       "ipa_dma %s:%d failed to alloc xfer descr wrapper\n",
                       "ipa_dma_sync_memcpy",
                       583);
            }
            v128 = ipa3_get_ipc_logbuf_low(v126);
            if ( v128 )
            {
              v129 = ipa3_get_ipc_logbuf_low(v128);
              ipc_log_string(v129, "ipa_dma %s:%d failed to alloc xfer descr wrapper\n", "ipa_dma_sync_memcpy", 583);
            }
            result = 4294967284LL;
            goto LABEL_139;
          }
          *(_QWORD *)v18 = a2;
          *(_QWORD *)(v18 + 8) = a1;
          *(_WORD *)(v18 + 16) = a3;
          *(_DWORD *)(v18 + 40) = 0;
          _init_swait_queue_head(v18 + 48, "&x->wait", &init_completion___key_0);
          mutex_lock(ipa3_dma_ctx + 16);
          v20 = v19 + 3;
          v21 = (_QWORD **)(v15 + 1632);
          v22 = *(_QWORD **)(v15 + 1640);
          if ( v19 + 3 == (_QWORD *)(v15 + 1632) || v22 == v20 || (_QWORD **)*v22 != v21 )
          {
            _list_add_valid_or_report(v19 + 3, v22);
          }
          else
          {
            *(_QWORD *)(v15 + 1640) = v20;
            v19[3] = v21;
            v19[4] = v22;
            *v22 = v20;
          }
          ++*(_DWORD *)v15;
          v144 = a1;
          LOWORD(v145) = a3;
          HIDWORD(v145) = 0;
          WORD1(v145) = 512;
          v147 = a2;
          LOWORD(v148) = a3;
          HIDWORD(v148) = 0;
          v149 = 0;
          hw_type = ipa_get_hw_type();
          _ZF = a3 < 9 && hw_type == 12;
          v25 = _ZF;
          v140 = v25;
          if ( _ZF )
          {
            v26 = *(_QWORD *)(v15 + 1624);
            v146 = nullptr;
            v27 = gsi_queue_xfer(*(_QWORD *)(v26 + 8), 1, &v144, 0);
            if ( v27 )
            {
              v36 = v27;
              v94 = printk(&unk_3E93E8, "ipa_dma_sync_memcpy");
              v95 = ipa3_get_ipc_logbuf(v94);
              if ( v95 )
              {
                v96 = ipa3_get_ipc_logbuf(v95);
                v95 = ipc_log_string(
                        v96,
                        "ipa_dma %s:%d Failed: gsi_queue_xfer dest descr res:%d\n",
                        "ipa_dma_sync_memcpy",
                        619,
                        v36);
              }
              v97 = ipa3_get_ipc_logbuf_low(v95);
              if ( v97 )
              {
                v98 = ipa3_get_ipc_logbuf_low(v97);
                ipc_log_string(
                  v98,
                  "ipa_dma %s:%d Failed: gsi_queue_xfer dest descr res:%d\n",
                  "ipa_dma_sync_memcpy",
                  619,
                  v36);
              }
              goto LABEL_125;
            }
            v28 = *(_QWORD *)(v15 + 1624);
            v145 = 33554440;
            v146 = v19;
            v29 = *(_QWORD *)(v28 + 8);
            v144 = *(_QWORD *)(ipa3_dma_ctx + 232);
            v30 = gsi_queue_xfer(v29, 1, &v144, 1);
            if ( v30 )
            {
              v36 = v30;
              v104 = printk(&unk_3FB164, "ipa_dma_sync_memcpy");
              v105 = ipa3_get_ipc_logbuf(v104);
              if ( v105 )
              {
                v106 = ipa3_get_ipc_logbuf(v105);
                v105 = ipc_log_string(
                         v106,
                         "ipa_dma %s:%d Failed: gsi_queue_xfer dummy dest descr res:%d\n",
                         "ipa_dma_sync_memcpy",
                         633,
                         v36);
              }
              v107 = ipa3_get_ipc_logbuf_low(v105);
              if ( v107 )
              {
                v108 = ipa3_get_ipc_logbuf_low(v107);
                ipc_log_string(
                  v108,
                  "ipa_dma %s:%d Failed: gsi_queue_xfer dummy dest descr res:%d\n",
                  "ipa_dma_sync_memcpy",
                  633,
                  v36);
              }
              goto LABEL_125;
            }
            v31 = *(_QWORD *)(v17 + 1624);
            WORD1(v148) = 1;
            v32 = gsi_queue_xfer(*(_QWORD *)(v31 + 8), 1, &v147, 0);
            if ( v32 )
            {
              v36 = v32;
              v113 = printk(&unk_3A6718, "ipa_dma_sync_memcpy");
              v114 = ipa3_get_ipc_logbuf(v113);
              if ( v114 )
              {
                v115 = ipa3_get_ipc_logbuf(v114);
                v114 = ipc_log_string(
                         v115,
                         "ipa_dma %s:%d Failed: gsi_queue_xfer src descr res:%d\n",
                         "ipa_dma_sync_memcpy",
                         642,
                         v36);
              }
              v40 = ipa3_get_ipc_logbuf_low(v114);
              if ( v40 )
              {
                v116 = ipa3_get_ipc_logbuf_low(v40);
                v40 = ipc_log_string(
                        v116,
                        "ipa_dma %s:%d Failed: gsi_queue_xfer src descr res:%d\n",
                        "ipa_dma_sync_memcpy",
                        642,
                        v36);
              }
            }
            else
            {
              v33 = *(_QWORD *)(v17 + 1624);
              v148 = 33554440;
              v149 = 0;
              v34 = *(_QWORD *)(v33 + 8);
              v147 = *(_QWORD *)(ipa3_dma_ctx + 208);
              v35 = gsi_queue_xfer(v34, 1, &v147, 1);
              if ( !v35 )
                goto LABEL_43;
              v36 = v35;
              v37 = printk(&unk_3AC88C, "ipa_dma_sync_memcpy");
              v38 = ipa3_get_ipc_logbuf(v37);
              if ( v38 )
              {
                v39 = ipa3_get_ipc_logbuf(v38);
                v38 = ipc_log_string(
                        v39,
                        "ipa_dma %s:%d Failed: gsi_queue_xfer dummy src descr res:%d\n",
                        "ipa_dma_sync_memcpy",
                        657,
                        v36);
              }
              v40 = ipa3_get_ipc_logbuf_low(v38);
              if ( v40 )
              {
                v41 = ipa3_get_ipc_logbuf_low(v40);
                v40 = ipc_log_string(
                        v41,
                        "ipa_dma %s:%d Failed: gsi_queue_xfer dummy src descr res:%d\n",
                        "ipa_dma_sync_memcpy",
                        657,
                        v36);
              }
            }
          }
          else
          {
            v42 = *(_QWORD *)(v15 + 1624);
            v146 = v19;
            v43 = gsi_queue_xfer(*(_QWORD *)(v42 + 8), 1, &v144, 1);
            if ( v43 )
            {
              v36 = v43;
              v99 = printk(&unk_3E93E8, "ipa_dma_sync_memcpy");
              v100 = ipa3_get_ipc_logbuf(v99);
              if ( v100 )
              {
                v101 = ipa3_get_ipc_logbuf(v100);
                v100 = ipc_log_string(
                         v101,
                         "ipa_dma %s:%d Failed: gsi_queue_xfer dest descr res:%d\n",
                         "ipa_dma_sync_memcpy",
                         668,
                         v36);
              }
              v102 = ipa3_get_ipc_logbuf_low(v100);
              if ( v102 )
              {
                v103 = ipa3_get_ipc_logbuf_low(v102);
                ipc_log_string(
                  v103,
                  "ipa_dma %s:%d Failed: gsi_queue_xfer dest descr res:%d\n",
                  "ipa_dma_sync_memcpy",
                  668,
                  v36);
              }
              goto LABEL_125;
            }
            v44 = *(_QWORD *)(v17 + 1624);
            WORD1(v148) = 512;
            v45 = gsi_queue_xfer(*(_QWORD *)(v44 + 8), 1, &v147, 1);
            if ( !v45 )
            {
LABEL_43:
              v46 = *v21;
              if ( v19 != *v21 - 3 )
              {
                mutex_unlock(ipa3_dma_ctx + 16);
                wait_for_completion(v19 + 5);
                v47 = mutex_lock(ipa3_dma_ctx + 16);
                v46 = *v21;
                if ( v19 != *v21 - 3 )
                  ((void (__fastcall *)(__int64))ipa_assert)(v47);
              }
              mutex_unlock(ipa3_dma_ctx + 16);
              for ( i = 0; ; ++i )
              {
                v49 = gsi_poll_channel(*(_QWORD *)(*(_QWORD *)(v15 + 1624) + 8LL), &v141);
                if ( v49 != 9 )
                {
                  if ( !v49 )
                  {
                    v56 = usleep_range_state(1010, 1050, 2);
                    if ( v140 )
                      v57 = WORD2(v143) == 8;
                    else
                      v57 = WORD2(v143) == a3;
                    if ( !v57 )
                      v56 = ((__int64 (__fastcall *)(__int64))ipa_assert)(v56);
                    if ( *(_QWORD *)(v142 + 8) != a1 )
                      ((void (__fastcall *)(__int64))ipa_assert)(v56);
                    mutex_lock(ipa3_dma_ctx + 16);
                    v58 = (_QWORD *)v46[1];
                    if ( (_QWORD *)*v58 == v46 && (v59 = *v46, *(_QWORD **)(*v46 + 8LL) == v46) )
                    {
                      *(_QWORD *)(v59 + 8) = v58;
                      *v58 = v59;
                    }
                    else
                    {
                      _list_del_entry_valid_or_report(v46);
                    }
                    *v46 = 0xDEAD000000000100LL;
                    v46[1] = 0xDEAD000000000122LL;
                    --*(_DWORD *)v15;
                    kmem_cache_free(*(_QWORD *)(ipa3_dma_ctx + 8), v19);
                    v60 = *(_QWORD ***)(v15 + 1632);
                    if ( v60 != v21 )
                      complete(v60 + 2);
                    v61 = mutex_unlock(ipa3_dma_ctx + 16);
                    _X8 = (unsigned int *)(ipa3_dma_ctx + 188);
                    __asm { PRFM            #0x11, [X8] }
                    do
                      v133 = __ldxr(_X8);
                    while ( __stxr(v133 + 1, _X8) );
                    _X8 = (unsigned int *)(ipa3_dma_ctx + 176);
                    __asm { PRFM            #0x11, [X8] }
                    do
                      v136 = __ldxr(_X8);
                    while ( __stxr(v136 - 1, _X8) );
                    if ( *(_BYTE *)(ipa3_dma_ctx + 4) == 1 )
                    {
                      v61 = ipa3_dma_work_pending(v61);
                      if ( (v61 & 1) == 0 )
                        v61 = complete(ipa3_dma_ctx + 128);
                    }
                    result = ipa3_get_ipc_logbuf_low(v61);
                    if ( result )
                    {
                      v63 = ipa3_get_ipc_logbuf_low(result);
                      ipc_log_string(v63, "ipa_dma %s:%d EXIT\n", "ipa_dma_sync_memcpy", 741);
                      result = 0;
                    }
                    goto LABEL_72;
                  }
                  v50 = v49;
                  v51 = printk(&unk_3B1F60, "ipa_dma_sync_memcpy");
                  v52 = ipa3_get_ipc_logbuf(v51);
                  if ( v52 )
                  {
                    v53 = ipa3_get_ipc_logbuf(v52);
                    v52 = ipc_log_string(
                            v53,
                            "ipa_dma %s:%d Failed: gsi_poll_chanel, returned %d loop#:%d\n",
                            "ipa_dma_sync_memcpy",
                            706,
                            v50,
                            i);
                  }
                  v54 = ipa3_get_ipc_logbuf_low(v52);
                  if ( v54 )
                  {
                    v55 = ipa3_get_ipc_logbuf_low(v54);
                    ipc_log_string(
                      v55,
                      "ipa_dma %s:%d Failed: gsi_poll_chanel, returned %d loop#:%d\n",
                      "ipa_dma_sync_memcpy",
                      706,
                      v50,
                      i);
                  }
                }
                usleep_range_state(1010, 1050, 2);
              }
            }
            v36 = v45;
            v109 = printk(&unk_3A6718, "ipa_dma_sync_memcpy");
            v110 = ipa3_get_ipc_logbuf(v109);
            if ( v110 )
            {
              v111 = ipa3_get_ipc_logbuf(v110);
              v110 = ipc_log_string(
                       v111,
                       "ipa_dma %s:%d Failed: gsi_queue_xfer src descr res:%d\n",
                       "ipa_dma_sync_memcpy",
                       677,
                       v36);
            }
            v40 = ipa3_get_ipc_logbuf_low(v110);
            if ( v40 )
            {
              v112 = ipa3_get_ipc_logbuf_low(v40);
              v40 = ipc_log_string(
                      v112,
                      "ipa_dma %s:%d Failed: gsi_queue_xfer src descr res:%d\n",
                      "ipa_dma_sync_memcpy",
                      677,
                      v36);
            }
          }
          ((void (__fastcall *)(__int64))ipa_assert)(v40);
LABEL_125:
          v117 = (_QWORD *)v19[4];
          if ( (_QWORD *)*v117 == v20 && (v118 = *v20, *(_QWORD **)(*v20 + 8LL) == v20) )
          {
            *(_QWORD *)(v118 + 8) = v117;
            *v117 = v118;
          }
          else
          {
            _list_del_entry_valid_or_report(v19 + 3);
          }
          v19[3] = 0xDEAD000000000100LL;
          v19[4] = 0xDEAD000000000122LL;
          --*(_DWORD *)v15;
          mutex_unlock(ipa3_dma_ctx + 16);
          kmem_cache_free(*(_QWORD *)(ipa3_dma_ctx + 8), v19);
          result = v36;
LABEL_139:
          _X8 = (unsigned int *)(ipa3_dma_ctx + 176);
          __asm { PRFM            #0x11, [X8] }
          do
            v139 = __ldxr(_X8);
          while ( __stxr(v139 - 1, _X8) );
          if ( *(_BYTE *)(ipa3_dma_ctx + 4) == 1 )
          {
            v130 = result;
            if ( (ipa3_dma_work_pending(result) & 1) == 0 )
              complete(ipa3_dma_ctx + 128);
            result = v130;
          }
          goto LABEL_72;
        }
LABEL_130:
        __break(0x5512u);
      }
      v89 = printk(&unk_3D2709, "ipa_dma_sync_memcpy");
      v90 = ipa3_get_ipc_logbuf(v89);
      if ( v90 )
      {
        v91 = ipa3_get_ipc_logbuf(v90);
        v90 = ipc_log_string(v91, "ipa_dma %s:%d Client %u is not mapped\n", "ipa_dma_sync_memcpy", 575, 44);
      }
      v92 = ipa3_get_ipc_logbuf_low(v90);
      if ( v92 )
      {
        v93 = ipa3_get_ipc_logbuf_low(v92);
        ipc_log_string(v93, "ipa_dma %s:%d Client %u is not mapped\n", "ipa_dma_sync_memcpy", 575, 44);
        goto LABEL_99;
      }
    }
    result = 4294967282LL;
    goto LABEL_72;
  }
  v79 = printk(&unk_3F4EBC, "ipa_dma_sync_memcpy");
  v80 = ipa3_get_ipc_logbuf(v79);
  if ( v80 )
  {
    v81 = ipa3_get_ipc_logbuf(v80);
    v80 = ipc_log_string(v81, "ipa_dma %s:%d can't memcpy, IPADMA isn't enabled\n", "ipa_dma_sync_memcpy", 557);
  }
  v82 = ipa3_get_ipc_logbuf_low(v80);
  if ( v82 )
  {
    v83 = ipa3_get_ipc_logbuf_low(v82);
    ipc_log_string(v83, "ipa_dma %s:%d can't memcpy, IPADMA isn't enabled\n", "ipa_dma_sync_memcpy", 557);
  }
  raw_spin_unlock_irqrestore(ipa3_dma_ctx + 120, v13);
  result = 0xFFFFFFFFLL;
LABEL_72:
  _ReadStatusReg(SP_EL0);
  return result;
}
