__int64 __fastcall hfi_core_dbg_test_packet(__int64 a1, __int64 a2, size_t a3, __int64 a4)
{
  __int64 v4; // x30
  __int64 v5; // x19
  __int64 v7; // x2
  __int64 v8; // x3
  __int64 v9; // x4
  __int64 v10; // x23
  __int64 *client_node; // x0
  unsigned __int64 v12; // x8
  __int64 v13; // x27
  __int64 v14; // x2
  __int64 v15; // x3
  __int64 v16; // x4
  __int64 v17; // x25
  __int64 v18; // x2
  __int64 v19; // x3
  int v20; // w8
  __int64 v21; // x9
  int v22; // w8
  int v23; // w9
  int v24; // w0
  __int64 v25; // x2
  __int64 v26; // x3
  __int64 v27; // x9
  bool v28; // zf
  __int64 v29; // x19
  int v30; // w8
  __int64 v31; // x4
  _DWORD *v32; // x25
  __int64 v33; // x8
  unsigned __int64 v34; // x8
  int full_packet; // w0
  int appended; // w0
  int v37; // w0
  void *v38; // x0
  __int64 v39; // x2
  __int64 v40; // x3
  int v41; // w8
  __int64 v42; // x3
  __int64 v43; // x4
  int v44; // w0
  __int64 v45; // x3
  __int64 result; // x0
  __int64 v47; // x30
  void *v48; // x0
  __int64 v49; // x2
  __int64 v50; // x23
  __int64 v51; // x19
  __int64 v52; // x20
  __int64 v53; // x30
  int v54; // w25
  void *v55; // x0
  __int64 v56; // x2
  int v57; // w22
  void *v58; // x0
  __int64 v59; // x2
  __int64 v60; // x24
  unsigned __int64 StatusReg; // x19
  __int64 (__fastcall *v62)(_QWORD, _QWORD, _QWORD); // x0
  __int64 v63; // x20
  __int64 v64; // [xsp+10h] [xbp-80h]
  size_t v65; // [xsp+18h] [xbp-78h]
  _QWORD *v66; // [xsp+20h] [xbp-70h]
  __int64 v67; // [xsp+30h] [xbp-60h]
  _QWORD v68[3]; // [xsp+40h] [xbp-50h] BYREF
  void *v69; // [xsp+58h] [xbp-38h]
  __int64 v70; // [xsp+60h] [xbp-30h] BYREF
  __int64 v71; // [xsp+68h] [xbp-28h]
  __int64 v72; // [xsp+70h] [xbp-20h] BYREF
  __int64 v73; // [xsp+78h] [xbp-18h]
  __int64 v74[2]; // [xsp+80h] [xbp-10h] BYREF

  v5 = v4;
  v74[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v72 = 0;
  v73 = 0;
  v70 = 0;
  v71 = 0;
  v69 = nullptr;
  memset(v68, 0, sizeof(v68));
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    v50 = v4;
    v51 = a1;
    v52 = a2;
    printk(&unk_1E83A, "hfi_core_dbg_test_packet", 2546, a4);
    a1 = v51;
    v5 = v50;
    a2 = v52;
  }
  v74[0] = 0;
  LODWORD(v10) = get_debugfs_input_client(a1, a2, a3, v74);
  if ( (v10 & 0x80000000) != 0 || !v74[0] || !*(__int64 (__fastcall **)())((char *)get_param_func + v74[0]) )
  {
    v47 = v5;
    v48 = &unk_1F01E;
    v49 = 2553;
LABEL_120:
    printk(v48, "hfi_core_dbg_test_packet", v49, v47);
    goto LABEL_121;
  }
  client_node = get_client_node(v74[0], v10, v7, v8, v9);
  if ( !client_node || (v12 = client_node[2], v13 = (__int64)client_node, !v12) || v12 >= 0xFFFFFFFFFFFFF001LL )
  {
    v47 = v5;
    v48 = &unk_1CA45;
    v49 = 2559;
    goto LABEL_120;
  }
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    printk(&unk_1931E, "hfi_core_dbg_test_packet", 2564, (unsigned int)v10);
  v17 = _kmalloc_cache_noprof(devm_free_irq, 3520, 40);
  if ( !v17 )
  {
LABEL_119:
    v47 = v5;
    v48 = &unk_19B17;
    v49 = 2576;
    goto LABEL_120;
  }
  while ( 1 )
  {
    *(_DWORD *)(v17 + 24) = 1;
    if ( (unsigned int)hfi_core_cmds_tx_buf_get(*(unsigned int **)(v13 + 16), v17, v14, v15, v16)
      || !*(_QWORD *)v17
      || !*(_QWORD *)(v17 + 16) )
    {
      printk(&unk_1D215, "hfi_core_dbg_test_packet", 2585, v5);
      goto LABEL_121;
    }
    v20 = msm_hfi_core_debug_level;
    *(_QWORD *)(v13 + 48) = v17;
    if ( (~v20 & 0x10001) == 0 )
    {
      printk(&unk_1E6B4, "hfi_core_dbg_test_packet", 2593, (unsigned int)v10);
      v17 = *(_QWORD *)(v13 + 48);
    }
    v21 = *(_QWORD *)(v17 + 16);
    v72 = *(_QWORD *)v17;
    LODWORD(v73) = v21;
    if ( msm_hfi_packet_cmd_id > 50331648 )
    {
      if ( (unsigned int)(msm_hfi_packet_cmd_id - 50331649) < 3 )
      {
LABEL_24:
        v22 = 1;
        v23 = 3;
        goto LABEL_25;
      }
LABEL_114:
      printk(&unk_1B997, "fill_header", 2111, v5);
      v58 = &unk_1D805;
      v59 = 2600;
LABEL_117:
      printk(v58, "hfi_core_dbg_test_packet", v59, v5);
LABEL_121:
      result = -22;
      goto LABEL_122;
    }
    if ( (unsigned int)(msm_hfi_packet_cmd_id - 33554433) <= 9 && ((1 << (msm_hfi_packet_cmd_id - 1)) & 0x205) != 0 )
      goto LABEL_24;
    if ( msm_hfi_packet_cmd_id == -16777214 )
    {
      v22 = 16;
      v23 = 4;
    }
    else
    {
      if ( msm_hfi_packet_cmd_id != 16777217 )
        goto LABEL_114;
      v22 = 1;
      v23 = 2;
    }
LABEL_25:
    HIDWORD(v70) = v23;
    LODWORD(v71) = 0;
    HIDWORD(v71) = v22;
    v24 = hfi_create_header(&v72, &v70, v18, v19, (unsigned int)msm_hfi_packet_cmd_id);
    if ( v24 )
      break;
    v66 = (_QWORD *)(v13 + 48);
    v27 = 3;
    v64 = v5;
    v65 = a3;
    LODWORD(v68[0]) = msm_hfi_packet_cmd_id;
    if ( msm_hfi_packet_cmd_id != 50331649 )
      v27 = 1;
    v28 = msm_hfi_packet_cmd_id == 33554433;
    _ReadStatusReg(SP_EL0);
    v67 = v13;
    v29 = 0;
    a3 = 33554441;
    if ( v28 )
      v10 = 2;
    else
      v10 = v27;
    while ( 1 )
    {
      if ( v29 )
      {
        if ( msm_hfi_packet_cmd_id == 33554433 )
        {
          if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
            printk(&unk_1B2EA, "hfi_core_dbg_test_packet", 2626, v26);
          v30 = 33554435;
          v69 = nullptr;
          memset(v68, 0, sizeof(v68));
          goto LABEL_39;
        }
        if ( msm_hfi_packet_cmd_id == 50331649 )
          break;
      }
LABEL_40:
      v31 = LODWORD(v68[0]);
      if ( (~msm_hfi_core_debug_level & 0x10001) != 0
        || (printk(&unk_1B96A, "hfi_core_dbg_test_packet", 2634, LODWORD(v68[0])),
            v31 = LODWORD(v68[0]),
            (~msm_hfi_core_debug_level & 0x10001) != 0) )
      {
        if ( (int)v31 <= 33554441 )
          goto LABEL_42;
      }
      else
      {
        printk(&unk_1D83E, "fill_packet", 2183, LODWORD(v68[0]));
        v31 = LODWORD(v68[0]);
        if ( SLODWORD(v68[0]) <= 33554441 )
        {
LABEL_42:
          if ( (int)v31 > 0x2000000 )
          {
            if ( (_DWORD)v31 == 33554433 )
            {
              v13 = 6;
            }
            else
            {
              if ( (_DWORD)v31 != 33554435 )
                goto LABEL_115;
              v13 = 7;
            }
          }
          else if ( (_DWORD)v31 == -16777214 )
          {
            v13 = 0;
          }
          else
          {
            if ( (_DWORD)v31 != 16777217 )
              goto LABEL_115;
            v13 = 1;
          }
          goto LABEL_62;
        }
      }
      if ( (int)v31 > 50331649 )
      {
        if ( (_DWORD)v31 == 50331650 )
        {
          v13 = 3;
        }
        else
        {
          if ( (_DWORD)v31 != 50331651 )
          {
LABEL_115:
            v38 = &unk_1B997;
            v39 = 2193;
            v5 = v64;
            v40 = v64;
            goto LABEL_116;
          }
          v13 = 4;
        }
      }
      else if ( (_DWORD)v31 == 33554442 )
      {
        v13 = 5;
      }
      else
      {
        if ( (_DWORD)v31 != 50331649 )
          goto LABEL_115;
        v13 = 2;
      }
LABEL_62:
      if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
        printk(&unk_1D4D0, "fill_packet", 2197, (unsigned int)v13);
      *(_QWORD *)((char *)v68 + 4) = 0x300000000LL;
      if ( (int)v13 > 3 )
      {
        if ( (int)v13 > 5 )
        {
          if ( (_DWORD)v13 == 6 )
          {
            HIDWORD(v68[2]) = 0;
            v69 = nullptr;
            *(_QWORD *)((char *)&v68[1] + 4) = 0x200000006LL;
            if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
              printk(&unk_1E717, "fill_packet", 2270, LODWORD(v68[0]));
          }
          else
          {
            *(_QWORD *)((char *)&v68[1] + 4) = 0x100000006LL;
            HIDWORD(v68[2]) = 4;
            v69 = &fill_packet_frame_trigger_payload;
            if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
              printk(&unk_19F4F, "fill_packet", 2282, LODWORD(v68[0]));
          }
          goto LABEL_88;
        }
        if ( (_DWORD)v13 == 4 )
        {
          v33 = 4;
          goto LABEL_84;
        }
        *(_QWORD *)((char *)&v68[1] + 4) = 0x200000005LL;
        HIDWORD(v68[2]) = 76;
        v69 = &fill_packet_mode_info_payload;
      }
      else
      {
        if ( (int)v13 > 1 )
        {
          if ( (_DWORD)v13 == 2 )
          {
            v34 = 0x200000002LL;
          }
          else
          {
            v33 = 3;
LABEL_84:
            v34 = v33 & 0xFFFF0000FFFFFFFFLL | 0x200000000LL;
          }
          *(_QWORD *)((char *)&v68[1] + 4) = v34;
          HIDWORD(v68[2]) = 0;
          v69 = nullptr;
          goto LABEL_88;
        }
        if ( (_DWORD)v13 )
        {
          HIDWORD(v68[1]) = 1;
          v68[2] = 0;
          v69 = nullptr;
        }
        else
        {
          *(_QWORD *)((char *)&v68[1] + 4) = 0x100000010LL;
          HIDWORD(v68[2]) = 4;
          if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
            printk(&unk_1E83A, "allocate_payload", 2072, v26);
          v32 = (_DWORD *)_kmalloc_cache_noprof(mbox_free_channel, 3520, 4);
          if ( !v32 )
          {
            v5 = v64;
            printk(&unk_1A9DC, "allocate_payload", 2077, v64);
            v38 = &unk_1E9D7;
            v39 = 2209;
            v40 = v64;
LABEL_116:
            printk(v38, "fill_packet", v39, v40);
            v58 = &unk_1D263;
            v59 = 2637;
            goto LABEL_117;
          }
          if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
            printk(&unk_1C28B, "allocate_payload", 2081, v26);
          v69 = v32;
          *v32 = 9680;
        }
      }
LABEL_88:
      full_packet = hfi_create_full_packet((__int64)&v72, (__int64)v68, v25, v26, v31);
      if ( full_packet )
      {
        v53 = v64;
        v54 = full_packet;
        v55 = &unk_19261;
        v56 = 2642;
        goto LABEL_112;
      }
      appended = append_kv_pairs_if_needed((__int64)&v72, v68);
      if ( appended )
      {
        v53 = v64;
        v54 = appended;
        v55 = &unk_1CADB;
        v56 = 2648;
        goto LABEL_112;
      }
      v37 = append_kv_pairs_if_needed_commit((__int64)&v72, (int *)v68);
      if ( v37 )
      {
        v53 = v64;
        v54 = v37;
        v55 = &unk_1E993;
        v56 = 2654;
        goto LABEL_112;
      }
      if ( v10 == ++v29 )
      {
        v41 = msm_hfi_core_debug_level;
        if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
        {
          printk(&unk_1C561, "hfi_core_dbg_test_packet", 2661, HIDWORD(v70));
          v41 = msm_hfi_core_debug_level;
        }
        if ( (~v41 & 0x10001) == 0 )
          printk(&unk_1A9AB, "hfi_core_dbg_test_packet", 2662, v26);
        dump_buffer();
        if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
          printk(&unk_1F6DD, "hfi_core_dbg_test_packet", 2664, v42);
        v44 = hfi_core_cmds_tx_buf_send(*(unsigned int **)(v67 + 16), v66, 1u, 1, v43);
        if ( v44 )
        {
          v57 = v44;
          printk(&unk_1D7AC, "hfi_core_dbg_test_packet", 2672, v64);
          result = v57;
        }
        else
        {
          if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
            printk(&unk_1C28B, "hfi_core_dbg_test_packet", 2676, v45);
          result = v65;
        }
        goto LABEL_122;
      }
    }
    v69 = nullptr;
    memset(v68, 0, sizeof(v68));
    if ( ((v29 - 1) & 0x3FFFFFFFFFFFFFFELL) == 0 )
    {
      v30 = panel_init_add_packets[v29 - 1];
LABEL_39:
      LODWORD(v68[0]) = v30;
      goto LABEL_40;
    }
    __break(1u);
    v60 = v29;
    StatusReg = _ReadStatusReg(SP_EL0);
    v62 = devm_free_irq;
    v63 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &hfi_core_dbg_test_packet__alloc_tag;
    v17 = _kmalloc_cache_noprof(v62, 3520, 40);
    *(_QWORD *)(StatusReg + 80) = v63;
    v5 = v60;
    if ( !v17 )
      goto LABEL_119;
  }
  v53 = v5;
  v54 = v24;
  v55 = &unk_19261;
  v56 = 2605;
LABEL_112:
  printk(v55, "hfi_core_dbg_test_packet", v56, v53);
  result = v54;
LABEL_122:
  _ReadStatusReg(SP_EL0);
  return result;
}
