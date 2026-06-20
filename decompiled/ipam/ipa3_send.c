__int64 __fastcall ipa3_send(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v5; // x0
  unsigned int v6; // w20
  __int64 v7; // x12
  __int64 v8; // x23
  unsigned __int64 v9; // x24
  __int64 v10; // x21
  unsigned __int64 v11; // x26
  _QWORD *v12; // x9
  _QWORD *v13; // x8
  __int64 v14; // x10
  unsigned __int64 v15; // x20
  _QWORD *v16; // x28
  int *v17; // x27
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x9
  __int16 v21; // w8
  int v22; // w8
  __int64 v23; // x8
  __int64 v24; // x3
  __int64 v25; // x0
  int v26; // w19
  __int64 v27; // x26
  __int64 v28; // x25
  __int64 *v29; // x8
  __int64 v30; // x1
  char v31; // w0
  char v32; // w22
  __int64 v33; // x0
  __int64 v34; // x8
  __int64 v35; // x0
  const char *v36; // x0
  const char *v37; // x2
  int v38; // w8
  _QWORD *v39; // x1
  int v40; // w9
  _BOOL4 v41; // w8
  bool v42; // zf
  __int64 v43; // x9
  __int64 v44; // x0
  __int64 v45; // x8
  __int64 v46; // x0
  __int64 v47; // x0
  unsigned int v48; // w20
  unsigned __int64 v49; // x0
  _QWORD *v50; // x8
  __int64 v51; // x24
  int v52; // w8
  __int64 v53; // x0
  __int64 v55; // x8
  __int64 v56; // x0
  __int64 v57; // x0
  __int64 v58; // x8
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x8
  __int64 v62; // x0
  __int64 v63; // x0
  __int64 v64; // x8
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x8
  __int64 v68; // x0
  __int64 v69; // x0
  __int64 v70; // x8
  __int64 v71; // x0
  __int64 v72; // x0
  __int64 v73; // x8
  __int64 v74; // x0
  __int64 v75; // x0
  __int64 v76; // x8
  __int64 v77; // x0
  __int64 v78; // x0
  char v79; // [xsp+Ch] [xbp-244h]
  __int64 v80; // [xsp+10h] [xbp-240h]
  unsigned int v81; // [xsp+1Ch] [xbp-234h]
  int v82; // [xsp+20h] [xbp-230h]
  const char **v83; // [xsp+20h] [xbp-230h]
  __int64 v84; // [xsp+28h] [xbp-228h]
  __int64 v85; // [xsp+30h] [xbp-220h]
  __int64 v86; // [xsp+38h] [xbp-218h]
  _QWORD *v87; // [xsp+40h] [xbp-210h]
  _QWORD *v88; // [xsp+48h] [xbp-208h]
  __int64 v90; // [xsp+58h] [xbp-1F8h] BYREF
  _BYTE s[480]; // [xsp+60h] [xbp-1F0h] BYREF
  __int64 v92; // [xsp+240h] [xbp-10h]

  v92 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  v5 = ((__int64 (__fastcall *)(_QWORD))ipa_get_gsi_ep_info)(*(unsigned int *)(*(_QWORD *)(a1 + 1624) + 4LL));
  if ( !v5 )
  {
    printk(&unk_3C3B35, "ipa3_send");
    v67 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v68 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v68 )
      {
        ipc_log_string(
          v68,
          "ipa %s:%d failed to get gsi EP config for client=%d\n",
          "ipa3_send",
          651,
          *(_DWORD *)(*(_QWORD *)(a1 + 1624) + 4LL));
        v67 = ipa3_ctx;
      }
      v69 = *(_QWORD *)(v67 + 34160);
      if ( v69 )
      {
        ipc_log_string(
          v69,
          "ipa %s:%d failed to get gsi EP config for client=%d\n",
          "ipa3_send",
          651,
          *(_DWORD *)(*(_QWORD *)(a1 + 1624) + 4LL));
        v48 = -14;
        goto LABEL_104;
      }
    }
LABEL_152:
    v48 = -14;
    goto LABEL_104;
  }
  if ( a2 >= 0x15 )
  {
    printk(&unk_3F7D42, "ipa3_send");
    v70 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v71 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v71 )
      {
        ipc_log_string(v71, "ipa %s:%d max descriptors reached need=%d max=%d\n", "ipa3_send", 656, a2, 20);
        v70 = ipa3_ctx;
      }
      v72 = *(_QWORD *)(v70 + 34160);
      if ( v72 )
        ipc_log_string(v72, "ipa %s:%d max descriptors reached need=%d max=%d\n", "ipa3_send", 656, a2, 20);
    }
    goto LABEL_139;
  }
  v6 = *(_DWORD *)(v5 + 8);
  if ( (*(_DWORD *)(v5 + 20) & 0xFFFFFFFE) == 2 )
    v6 -= *(unsigned __int8 *)(v5 + 24);
  if ( v6 < a2 )
  {
    printk(&unk_3FB1E0, "ipa3_send");
    v73 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v74 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v74 )
      {
        ipc_log_string(v74, "ipa %s:%d Too many chained descriptors need=%d max=%d\n", "ipa3_send", 668, a2, v6);
        v73 = ipa3_ctx;
      }
      v75 = *(_QWORD *)(v73 + 34160);
      if ( v75 )
        ipc_log_string(v75, "ipa %s:%d Too many chained descriptors need=%d max=%d\n", "ipa3_send", 668, a2, v6);
    }
LABEL_139:
    __break(0x800u);
    v48 = -1;
    goto LABEL_104;
  }
  memset(s, 0, 24 * a2);
  raw_spin_lock_bh(a1 + 1684);
  if ( *(_DWORD *)(*(_QWORD *)(a1 + 1624) + 456LL) )
  {
    printk(&unk_3C0A73, "ipa3_send");
    v76 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v77 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v77 )
      {
        ipc_log_string(v77, "ipa %s:%d Pipe disconnect in progress dropping the packet\n", "ipa3_send", 679);
        v76 = ipa3_ctx;
      }
      v78 = *(_QWORD *)(v76 + 34160);
      if ( v78 )
        ipc_log_string(v78, "ipa %s:%d Pipe disconnect in progress dropping the packet\n", "ipa3_send", 679);
    }
    raw_spin_unlock_bh(a1 + 1684);
    goto LABEL_152;
  }
  if ( !a2 )
  {
    v80 = 0;
    v11 = 0;
    v79 = 0;
LABEL_75:
    if ( ipa3_ctx )
    {
      v44 = *(_QWORD *)(ipa3_ctx + 34160);
      if ( v44 )
        ipc_log_string(
          v44,
          "ipa %s:%d ch:%lu queue xfer\n",
          "ipa3_send",
          803,
          *(_QWORD *)(*(_QWORD *)(a1 + 1624) + 8LL));
    }
    if ( !(unsigned int)gsi_queue_xfer(*(_QWORD *)(*(_QWORD *)(a1 + 1624) + 8LL), a2, s, 1) )
    {
      if ( (v79 & 1) != 0 && (*(_BYTE *)(a1 + 125) & 1) == 0 )
      {
        v52 = *(_DWORD *)(a1 + 376);
        *(_BYTE *)(a1 + 125) = 1;
        *(_DWORD *)(a1 + 376) = v52 + 1;
        raw_spin_unlock_bh(a1 + 1684);
        if ( ipa3_ctx )
        {
          v53 = *(_QWORD *)(ipa3_ctx + 34160);
          if ( v53 )
            ipc_log_string(
              v53,
              "ipa %s:%d scheduling timer for ch %lu\n",
              "ipa3_send",
              825,
              *(_QWORD *)(*(_QWORD *)(a1 + 1624) + 8LL));
        }
        hrtimer_start_range_ns(a1 + 1688, 2000000, 0, 1);
      }
      else
      {
        ++*(_DWORD *)(a1 + 376);
        raw_spin_unlock_bh(a1 + 1684);
      }
      v48 = 0;
      *(_BYTE *)(ipa3_ctx + 31960) = 1;
      goto LABEL_104;
    }
    if ( (unsigned int)__ratelimit(&ipa3_send__rs, "ipa3_send") )
    {
      printk(&unk_3F4F70, "ipa3_send");
      v45 = ipa3_ctx;
      if ( ipa3_ctx )
        goto LABEL_81;
    }
    else
    {
      v45 = ipa3_ctx;
      if ( ipa3_ctx )
      {
LABEL_81:
        v46 = *(_QWORD *)(v45 + 34152);
        if ( v46 )
        {
          ipc_log_string(v46, "ipa %s:%d GSI xfer failed.\n", "ipa3_send", 807);
          v45 = ipa3_ctx;
        }
        v47 = *(_QWORD *)(v45 + 34160);
        if ( v47 )
          ipc_log_string(v47, "ipa %s:%d GSI xfer failed.\n", "ipa3_send", 807);
      }
    }
    v48 = -14;
    LODWORD(v10) = a2;
    goto LABEL_86;
  }
  v7 = a3;
  v8 = 0;
  v9 = 0;
  LODWORD(v10) = 0;
  v11 = 0;
  v79 = 0;
  v84 = a1;
  v85 = 104LL * a2;
  v80 = 0;
  v87 = (_QWORD *)(a1 + 1632);
  v88 = (_QWORD *)(a1 + 1664);
  v86 = 104LL * (a2 - 1);
  _ReadStatusReg(SP_EL0);
  v81 = a2;
  while ( 1 )
  {
    v12 = (_QWORD *)*v88;
    if ( (_QWORD *)*v88 != v88 )
      break;
    v15 = kmem_cache_alloc_noprof(*(_QWORD *)(ipa3_ctx + 29440), 2336);
    v7 = a3;
    if ( !v15 )
      goto LABEL_105;
LABEL_18:
    v16 = (_QWORD *)(v15 + 32);
    *(_QWORD *)(v15 + 32) = v15 + 32;
    *(_QWORD *)(v15 + 40) = v15 + 32;
    if ( !v8 )
    {
      v11 = v15;
      *(_DWORD *)(v15 + 80) = a2;
    }
    v17 = (int *)(v7 + v8);
    if ( *(_BYTE *)(v7 + v8 + 33) == 1 && !*((_QWORD *)v17 + 1) )
    {
      v82 = v10;
      if ( v15 <= 0xFFFEFFFFFFFFFFFFLL )
      {
        v33 = printk(&unk_3C0C6A, "pointer_to_tag_wa");
        v34 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v35 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v35 )
          {
            ipc_log_string(
              v35,
              "ipa %s:%d The 16 prefix is not all 1s (%pK)\n",
              "pointer_to_tag_wa",
              7412,
              (const void *)v15);
            v34 = ipa3_ctx;
          }
          v33 = *(_QWORD *)(v34 + 34160);
          if ( v33 )
            v33 = ipc_log_string(
                    v33,
                    "ipa %s:%d The 16 prefix is not all 1s (%pK)\n",
                    "pointer_to_tag_wa",
                    7412,
                    (const void *)v15);
        }
        ((void (__fastcall *)(__int64))ipa_assert)(v33);
      }
      v90 = v15 & 0xFFFFFFFFFFFFLL;
      v18 = ((__int64 (__fastcall *)(__int64, __int64 *, __int64))ipahal_construct_imm_cmd)(12, &v90, 1);
      if ( !v18 )
      {
        printk(&unk_3C6D31, "ipa_populate_tag_field");
        v61 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v62 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v62 )
          {
            ipc_log_string(v62, "ipa %s:%d Failed to construct ip_packet_tag_status\n", "ipa_populate_tag_field", 7132);
            v61 = ipa3_ctx;
          }
          v63 = *(_QWORD *)(v61 + 34160);
          if ( v63 )
            ipc_log_string(v63, "ipa %s:%d Failed to construct ip_packet_tag_status\n", "ipa_populate_tag_field", 7132);
        }
        printk(&unk_3AF6E4, "ipa3_send");
        v64 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v65 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v65 )
          {
            ipc_log_string(v65, "ipa %s:%d Failed to populate tag field\n", "ipa3_send", 713);
            v64 = ipa3_ctx;
          }
          v66 = *(_QWORD *)(v64 + 34160);
          if ( v66 )
            ipc_log_string(v66, "ipa %s:%d Failed to populate tag field\n", "ipa3_send", 713);
        }
        goto LABEL_115;
      }
      v10 = v18;
      if ( ipa3_ctx )
      {
        v19 = *(_QWORD *)(ipa3_ctx + 34160);
        if ( v19 )
          ipc_log_string(
            v19,
            "ipa %s:%d tx_pkt sent in tag: 0x%pK\n",
            "ipa_populate_tag_field",
            7139,
            (const void *)v15);
      }
      v7 = a3;
      v80 = v10;
      *((_QWORD *)v17 + 1) = v10 + 4;
      v20 = a3 + v8;
      *(_WORD *)(v20 + 36) = *(_WORD *)(v10 + 2);
      v21 = *(_WORD *)v10;
      *(_DWORD *)v20 = 3;
      *(_WORD *)(v20 + 34) = v21;
      *(_QWORD *)(v20 + 40) = ipa3_tag_destroy_imm;
      *(_QWORD *)(v20 + 48) = v10;
      LODWORD(v10) = v82;
    }
    v22 = *v17;
    *(_DWORD *)v15 = *v17;
    if ( v22 != 2 )
    {
      v26 = v10;
      v10 = v11;
      v27 = *(_QWORD *)(v7 + v8 + 8);
      *(_QWORD *)(v15 + 8) = v27;
      v28 = *((unsigned __int16 *)v17 + 17);
      *(_DWORD *)(v15 + 24) = v28;
      if ( (v17[8] & 1) != 0 )
      {
        v25 = *(_QWORD *)(v7 + v8 + 24);
        *(_BYTE *)(v15 + 96) = 1;
LABEL_54:
        v11 = v10;
        *(_QWORD *)(v15 + 16) = v25;
        LODWORD(v10) = v26;
        a1 = v84;
        goto LABEL_55;
      }
      v83 = *(const char ***)(ipa3_ctx + 34216);
      v31 = is_vmalloc_addr(v27);
      v32 = v31;
      if ( (v31 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
      {
        dma_map_single_attrs___already_done = 1;
        v36 = (const char *)dev_driver_string(v83);
        v37 = v83[14];
        if ( !v37 )
          v37 = *v83;
        _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v36, v37);
        __break(0x800u);
        if ( (v32 & 1) == 0 )
          goto LABEL_52;
LABEL_41:
        v25 = -1;
      }
      else
      {
        if ( (v31 & 1) != 0 )
          goto LABEL_41;
LABEL_52:
        v25 = dma_map_page_attrs(
                v83,
                ((unsigned __int64)((v27 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
                v27 & 0xFFF,
                v28,
                1,
                0);
      }
      v7 = a3;
      a2 = v81;
      goto LABEL_54;
    }
    v23 = v7 + v8;
    *(_QWORD *)(v15 + 8) = *(_QWORD *)(v7 + v8 + 16);
    v24 = *((unsigned __int16 *)v17 + 17);
    *(_DWORD *)(v15 + 24) = v24;
    if ( (v17[8] & 1) != 0 )
    {
      v25 = *(_QWORD *)(v23 + 24);
      *(_BYTE *)(v15 + 96) = 1;
    }
    else
    {
      v29 = *(__int64 **)(v23 + 16);
      if ( (*v29 & 1) != 0 )
        v30 = 0;
      else
        v30 = *v29;
      v25 = dma_map_page_attrs(*(_QWORD *)(ipa3_ctx + 34216), v30, *((unsigned int *)v29 + 3), v24, 1, 0);
      v7 = a3;
    }
    *(_QWORD *)(v15 + 16) = v25;
LABEL_55:
    if ( v25 == -1 )
    {
      printk(&unk_3D27BB, "ipa3_send");
      v58 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v59 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v59 )
        {
          ipc_log_string(v59, "ipa %s:%d failed to do dma map.\n", "ipa3_send", 753);
          v58 = ipa3_ctx;
        }
        v60 = *(_QWORD *)(v58 + 34160);
        if ( v60 )
          ipc_log_string(v60, "ipa %s:%d failed to do dma map.\n", "ipa3_send", 753);
      }
LABEL_115:
      kmem_cache_free(*(_QWORD *)(ipa3_ctx + 29440), v15);
      v48 = -14;
      goto LABEL_86;
    }
    *(_QWORD *)(v15 + 72) = a1;
    *(_QWORD *)(v15 + 48) = *(_QWORD *)(v7 + v8 + 40);
    *(_QWORD *)(v15 + 56) = *(_QWORD *)(v7 + v8 + 48);
    v38 = *(_DWORD *)(v7 + v8 + 56);
    *(_BYTE *)(v15 + 97) = 0;
    *(_DWORD *)(v15 + 64) = v38;
    v39 = *(_QWORD **)(a1 + 1640);
    if ( v16 == v87 || v16 == v39 || (_QWORD *)*v39 != v87 )
    {
      _list_add_valid_or_report(v15 + 32, v39);
    }
    else
    {
      *(_QWORD *)(a1 + 1640) = v16;
      *(_QWORD *)(v15 + 32) = v87;
      *(_QWORD *)(v15 + 40) = v39;
      *v39 = v16;
    }
    ++*(_DWORD *)a1;
    if ( v9 > 0x1DF )
      goto LABEL_153;
    v40 = *v17;
    *(_QWORD *)&s[v9] = *(_QWORD *)(v15 + 16);
    v41 = v40 == 3;
    if ( v9 > 0x1D7 )
      goto LABEL_153;
    v42 = v40 == 3;
    v43 = 34;
    if ( v42 )
      v43 = 36;
    *(_WORD *)&s[v9 + 8] = *(_WORD *)(v7 + v43 + v8);
    if ( v9 > 0x1D4 )
LABEL_153:
      __break(1u);
    *(_DWORD *)&s[v9 + 12] = v41;
    if ( v86 == v8 )
    {
      if ( (*(_BYTE *)(ipa3_ctx + 45392) & 1) == 0 && *(_BYTE *)(a1 + 124) == 1 && (*(_BYTE *)(a1 + 376) & 0x1F) != 0 )
      {
        v79 = 1;
      }
      else
      {
        *(_WORD *)&s[v9 + 10] |= 0x600u;
        hrtimer_try_to_cancel(a1 + 1688);
        *(_BYTE *)(a1 + 125) = 0;
      }
      if ( v9 > 0x1CF )
        goto LABEL_153;
      v7 = a3;
      *(_QWORD *)&s[v9 + 16] = v11;
    }
    else
    {
      *(_WORD *)&s[v9 + 10] |= 1u;
    }
    v8 += 104;
    LODWORD(v10) = v10 + 1;
    v9 += 24LL;
    if ( v85 == v8 )
      goto LABEL_75;
  }
  v13 = (_QWORD *)v12[1];
  if ( (_QWORD *)*v13 == v12 && (v14 = *v12, *(_QWORD **)(*v12 + 8LL) == v12) )
  {
    *(_QWORD *)(v14 + 8) = v13;
    *v13 = v14;
  }
  else
  {
    _list_del_entry_valid_or_report(*v88);
  }
  v15 = (unsigned __int64)(v12 - 4);
  *v12 = 0xDEAD000000000100LL;
  v12[1] = 0xDEAD000000000122LL;
  --*(_DWORD *)(a1 + 1680);
  v12[7] = 0;
  v12[8] = 0;
  v12[5] = 0;
  v12[6] = 0;
  v12[3] = 0;
  v12[4] = 0;
  v12[1] = 0;
  v12[2] = 0;
  *(_QWORD *)(v15 + 24) = 0;
  *v12 = 0;
  *(_QWORD *)(v15 + 8) = 0;
  *(_QWORD *)(v15 + 16) = 0;
  *(_QWORD *)v15 = 0;
  if ( v12 != (_QWORD *)&unk_20 )
    goto LABEL_18;
LABEL_105:
  printk(&unk_3D2793, "ipa3_send");
  v55 = ipa3_ctx;
  if ( !ipa3_ctx )
    goto LABEL_118;
  v56 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v56 )
  {
    ipc_log_string(v56, "ipa %s:%d failed to alloc tx wrapper\n", "ipa3_send", 698);
    v55 = ipa3_ctx;
  }
  v57 = *(_QWORD *)(v55 + 34160);
  if ( v57 )
  {
    ipc_log_string(v57, "ipa %s:%d failed to alloc tx wrapper\n", "ipa3_send", 698);
    v48 = -12;
  }
  else
  {
LABEL_118:
    v48 = -12;
  }
LABEL_86:
  kfree(v80);
  if ( (_DWORD)v10 )
  {
    v10 = (unsigned int)v10;
    do
    {
      v51 = *(_QWORD *)(v11 + 32);
      v50 = *(_QWORD **)(v11 + 40);
      v49 = v11 + 32;
      if ( *v50 == v11 + 32 && *(_QWORD *)(v51 + 8) == v49 )
      {
        *(_QWORD *)(v51 + 8) = v50;
        *v50 = v51;
      }
      else
      {
        _list_del_entry_valid_or_report(v49);
      }
      *(_QWORD *)(v11 + 32) = 0xDEAD000000000100LL;
      *(_QWORD *)(v11 + 40) = 0xDEAD000000000122LL;
      --*(_DWORD *)a1;
      if ( (*(_BYTE *)(v11 + 96) & 1) == 0 )
        dma_unmap_page_attrs(*(_QWORD *)(ipa3_ctx + 34216), *(_QWORD *)(v11 + 16), *(unsigned int *)(v11 + 24), 1, 0);
      kmem_cache_free(*(_QWORD *)(ipa3_ctx + 29440), v11);
      --v10;
      v11 = v51 - 32;
    }
    while ( v10 );
  }
  raw_spin_unlock_bh(a1 + 1684);
LABEL_104:
  _ReadStatusReg(SP_EL0);
  return v48;
}
