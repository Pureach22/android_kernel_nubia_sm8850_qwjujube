__int64 __fastcall usb_gsi_ep_op(__int64 a1, __int64 *a2, unsigned int a3)
{
  __int64 v6; // x22
  _QWORD *v7; // x23
  const char *v8; // x5
  void *v9; // x0
  __int64 v10; // x3
  __int64 v11; // x21
  __int64 v12; // x24
  __int64 v13; // x25
  __int64 v14; // x23
  int v15; // w26
  int v16; // w8
  char v17; // w8
  int v18; // w0
  int v19; // w19
  __int64 v20; // x8
  __int64 v21; // x20
  __int64 v22; // x21
  int v23; // w9
  int v24; // w8
  __int64 v25; // x0
  __int64 v26; // x8
  __int64 v27; // x19
  __int64 v28; // x8
  __int64 v29; // x9
  int v30; // w8
  unsigned int v31; // w20
  __int64 result; // x0
  int v33; // w19
  __int64 v35; // x24
  __int64 v36; // x25
  void *v37; // x0
  __int64 v38; // x22
  char v39; // w23
  __int64 v40; // x21
  __int64 v41; // x0
  int v42; // w23
  int v43; // w26
  __int64 v44; // x0
  __int64 v45; // x4
  __int64 v46; // x0
  __int64 v47; // x21
  __int64 v48; // x0
  unsigned int v49; // w22
  _DWORD *v50; // x8
  _DWORD *v51; // x9
  __int64 v52; // x23
  _QWORD *v53; // x21
  int v54; // w22
  __int64 v55; // x5
  __int64 v56; // x19
  __int64 v57; // x21
  __int64 v58; // x22
  int v59; // w0
  __int64 v60; // x21
  __int64 v61; // x22
  int v62; // w0
  __int64 v63; // x21
  __int64 v64; // x22
  int v65; // w0
  _DWORD *v66; // x8
  __int64 v67; // x19
  __int64 v68; // x20
  int v69; // w0
  int v70; // w9
  __int64 v71; // x8
  int v72; // w10
  __int64 v73; // x9
  __int16 v74; // w10
  int v75; // w10
  __int64 v76; // x0
  __int64 v77; // x8
  int v78; // w9
  __int64 v79; // x21
  unsigned int v80; // w19
  __int64 v81; // x19
  __int64 (__fastcall *v82)(_QWORD); // x8
  __int64 v83; // x19
  __int64 v84; // x21
  __int64 v85; // x8
  __int64 v86; // x3
  __int64 v87; // x0
  int v88; // w8
  int v89; // w9
  _DWORD *v90; // x22
  char v91; // w25
  __int64 v92; // x26
  _QWORD *v93; // x24
  __int64 v94; // x2
  __int64 v95; // x0
  __int64 v96; // x21
  __int64 v97; // x0
  _DWORD *v98; // x19
  unsigned int v99; // t1
  __int64 v100; // x2
  __int64 v101; // x0
  __int64 v102; // x23
  __int64 v103; // x0
  const char *v104; // x3
  __int64 v105; // x0
  int v106; // w9
  unsigned __int64 v107; // x11
  int v108; // w9
  int v109; // w11
  unsigned __int64 v110; // [xsp+8h] [xbp-18h] BYREF
  int v111; // [xsp+10h] [xbp-10h]
  __int64 v112; // [xsp+18h] [xbp-8h]

  v112 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 152);
  v7 = *(_QWORD **)(*(_QWORD *)(*(_QWORD *)(v6 + 368) + 96LL) + 152LL);
  if ( a3 > 0xD )
    v8 = "Invalid";
  else
    v8 = gsi_op_strings[a3];
  v9 = (void *)ipc_log_string(
                 v7[157],
                 "%s: %s(%d):%s",
                 "usb_gsi_ep_op",
                 *(const char **)(a1 + 8),
                 *(unsigned __int8 *)(a1 + 170) >> 1,
                 v8);
  switch ( a3 )
  {
    case 0u:
      if ( (*(_BYTE *)(v6 + 1377) & 8) == 0 )
        goto LABEL_51;
      v11 = raw_spin_lock_irqsave(v6 + 312);
      v12 = *(_QWORD *)(a1 + 24);
      v13 = *(_QWORD *)(a1 + 32);
      v14 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 368LL) + 96LL) + 152LL);
      v15 = ((4 * *((unsigned __int8 *)a2 + 52)) | 0xF8800) - 4;
      writel(
        *(unsigned int *)(v14 + 1212),
        *(_QWORD *)(v14 + 8) + (unsigned int)(v15 + *(_DWORD *)(*(_QWORD *)(v14 + 1136) + 8LL)));
      writel(
        *(unsigned int *)(v14 + 1208),
        *(_QWORD *)(v14 + 8) + (unsigned int)(*(_DWORD *)(*(_QWORD *)(v14 + 1136) + 4LL) + v15));
      v111 = 0;
      v110 = 0;
      dwc3_msm_depcfg_params(a1, &v110);
      HIDWORD(v110) |= *((_BYTE *)a2 + 52) & 0x1F;
      dwc3_core_send_gadget_ep_cmd(a1, 1, &v110);
      v16 = *(_DWORD *)(a1 + 164);
      if ( (v16 & 1) == 0 )
      {
        dwc3_core_resize_tx_fifos(a1);
        *(_QWORD *)(a1 + 24) = v12;
        *(_QWORD *)(a1 + 32) = v13;
        v17 = *(_BYTE *)(v12 + 3) & 3;
        *(_DWORD *)(a1 + 164) |= 1u;
        *(_BYTE *)(a1 + 171) = v17;
        v18 = readl(*(_QWORD *)(v14 + 8) + 50976LL);
        writel(v18 | (unsigned int)(1LL << *(_BYTE *)(a1 + 170)), *(_QWORD *)(v14 + 8) + 50976LL);
        v16 = *(_DWORD *)(a1 + 164);
      }
      if ( (v16 & 0x4000) == 0 )
      {
        v110 = 0;
        v111 = 1;
        dwc3_core_send_gadget_ep_cmd(a1, 2, &v110);
        *(_DWORD *)(a1 + 164) |= 0x4000u;
      }
      raw_spin_unlock_irqrestore(v6 + 312, v11);
      goto LABEL_78;
    case 1u:
      if ( (*(_BYTE *)(v6 + 1377) & 8) == 0 )
        goto LABEL_51;
      v76 = raw_spin_lock_irqsave(v6 + 312);
      v77 = *(_QWORD *)(a1 + 144);
      v78 = *((unsigned __int8 *)a2 + 52);
      v79 = v76;
      LODWORD(v110) = 0;
      HIDWORD(v110) = v77;
      v111 = WORD2(v77) | (v78 << 16) | 0xA00000;
      v80 = dwc3_core_send_gadget_ep_cmd(a1, 6, &v110);
      raw_spin_unlock_irqrestore(v6 + 312, v79);
      result = v80;
      goto LABEL_79;
    case 2u:
      v52 = *(_QWORD *)(a1 + 152);
      v53 = *(_QWORD **)(*(_QWORD *)(*(_QWORD *)(v52 + 368) + 96LL) + 152LL);
      v54 = ((4 * *((unsigned __int8 *)a2 + 52)) | 0xF8800) - 4;
      writel(*(unsigned int *)(a1 + 144), v53[1] + (unsigned int)(v54 + *(_DWORD *)(v53[142] + 12LL)));
      writel(*(unsigned int *)(a1 + 148), v53[1] + (unsigned int)(*(_DWORD *)(v53[142] + 16LL) + v54));
      v55 = a2[5];
      if ( !v55 )
      {
        v55 = dma_map_resource(*(_QWORD *)(v52 + 376), *((unsigned int *)a2 + 8), 4096, 0, 0);
        a2[5] = v55;
        if ( v55 == -1 )
        {
          dev_err(*v53, "mapping error for db_reg_phs_addr_lsb\n");
          v55 = a2[5];
        }
      }
      ipc_log_string(
        v53[157],
        "%s: ep:%s dbl_addr_lsb:%x mapped_addr:%llx\n",
        "gsi_store_ringbase_dbl_info",
        *(const char **)(a1 + 8),
        *((_DWORD *)a2 + 8),
        v55);
      writel(*((unsigned int *)a2 + 11), v53[1] + (unsigned int)(*(_DWORD *)(v53[142] + 8LL) + v54));
      writel(*((unsigned int *)a2 + 10), v53[1] + (unsigned int)(*(_DWORD *)(v53[142] + 4LL) + v54));
      goto LABEL_78;
    case 3u:
      if ( (*(_BYTE *)(v6 + 1377) & 8) == 0 )
        goto LABEL_51;
      v56 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 368LL) + 96LL) + 152LL);
      v57 = *(_QWORD *)(v56 + 8);
      v58 = (unsigned int)(**(_DWORD **)(v56 + 1136) + 1017856);
      v59 = readl(v57 + v58);
      writel(v59 | 0x1000u, v57 + v58);
      readl(v57 + v58);
      v60 = *(_QWORD *)(v56 + 8);
      v61 = (unsigned int)(**(_DWORD **)(v56 + 1136) + 1017856);
      v62 = readl(v60 + v61);
      writel(v62 | 0x100000u, v60 + v61);
      readl(v60 + v61);
      v63 = *(_QWORD *)(v56 + 8);
      v64 = (unsigned int)(**(_DWORD **)(v56 + 1136) + 1017856);
      v65 = readl(v63 + v64);
      writel(v65 & 0xFFEFFFFF, v63 + v64);
      readl(v63 + v64);
      v66 = *(_DWORD **)(v56 + 1136);
      v67 = *(_QWORD *)(v56 + 8);
      v68 = (unsigned int)(*v66 + 1017856);
      v69 = readl(v67 + v68);
      writel(v69 | 1u, v67 + v68);
      readl(v67 + v68);
      goto LABEL_78;
    case 4u:
      v25 = raw_spin_lock_irqsave(v6 + 312);
      v26 = a2[2];
      v27 = v25;
      if ( (int)v26 >= 1 )
      {
        v28 = v26 & 0x7FFFFFFF;
        v29 = 12;
        do
        {
          --v28;
          *(_DWORD *)(*(_QWORD *)(a1 + 136) + v29) |= 1u;
          v29 += 16;
        }
        while ( v28 );
      }
      v30 = *(unsigned __int8 *)(a1 + 172);
      v111 = 0;
      v110 = 0;
      v31 = dwc3_core_send_gadget_ep_cmd(a1, (v30 << 16) | 7u, &v110);
      raw_spin_unlock_irqrestore(v6 + 312, v27);
      result = v31;
      goto LABEL_79;
    case 5u:
      if ( (*(_BYTE *)(v6 + 1377) & 8) == 0 )
        goto LABEL_51;
      v90 = a2 + 4;
      v91 = *(_BYTE *)(a1 + 204);
      v92 = a2[2];
      v93 = *(_QWORD **)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 368LL) + 96LL) + 152LL);
      if ( arm64_use_ng_mappings )
        v94 = 0x68000000000F13LL;
      else
        v94 = 0x68000000000713LL;
      v95 = ioremap_prot(*((unsigned int *)a2 + 8), 4, v94);
      if ( v95 )
      {
        v96 = v95;
        v99 = *((_DWORD *)a2 + 12);
        v98 = a2 + 6;
        v97 = v99;
        if ( arm64_use_ng_mappings )
          v100 = 0x68000000000F13LL;
        else
          v100 = 0x68000000000713LL;
        v101 = ioremap_prot(v97, 4, v100);
        if ( v101 )
        {
          v102 = v101;
          v103 = v93[157];
          v104 = *(const char **)(a1 + 8);
          v110 = *(_QWORD *)(a1 + 144)
               + (((unsigned __int64)((v92 << (v91 & 1) << 32) + 0x100000000LL) >> 28) & 0xFFFFFFF0);
          ipc_log_string(
            v103,
            "%s: ep:%s link TRB addr:%pad db_lsb:%pad db_msb:%pad\n",
            "gsi_ring_db",
            v104,
            &v110,
            v90,
            v98);
          writel_relaxed((unsigned int)v110, v96);
          writel_relaxed(HIDWORD(v110), v102);
          iounmap(v96);
          v105 = v102;
        }
        else
        {
          dev_err(*v93, "Failed to map GSI DBL address MSB 0x%x\n", *v98);
          v105 = v96;
        }
        iounmap(v105);
      }
      else
      {
        dev_err(*v93, "Failed to map GSI DBL address LSB 0x%x\n", *v90);
      }
      goto LABEL_78;
    case 6u:
      v83 = raw_spin_lock_irqsave(v6 + 312);
      dwc3_core_stop_active_transfer(a1);
      raw_spin_unlock_irqrestore(v6 + 312, v83);
      goto LABEL_78;
    case 7u:
      v70 = *(unsigned __int8 *)(a1 + 170);
      v71 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 368LL) + 96LL) + 152LL);
      v72 = *(_DWORD *)(v71 + 32);
      *((_BYTE *)a2 + 8) = 0;
      *((_DWORD *)a2 + 1) = v72 + 16 * v70 + 51212;
      v73 = a2[4];
      a2[3] = *(_QWORD *)(a1 + 144);
      *((_BYTE *)a2 + 2) = *(_QWORD *)(v73 + 24) >> 10;
      v74 = *(_WORD *)(v73 + 16);
      if ( (*(_BYTE *)(a1 + 204) & 1) != 0 )
      {
        *((_WORD *)a2 + 9) = 32 * v74 + 32;
        v75 = 2 * *(_DWORD *)(v73 + 16);
      }
      else
      {
        *((_WORD *)a2 + 9) = 16 * v74 + 32;
        v75 = *(_DWORD *)(v73 + 16);
      }
      result = 0;
      *(_WORD *)a2 = *(_WORD *)(a1 + 144) + 16 * v75 + 16;
      v88 = *(_DWORD *)(v71 + 32);
      v89 = *(unsigned __int8 *)(v73 + 52);
      *((_BYTE *)a2 + 16) = 0;
      *((_DWORD *)a2 + 3) = v88 + 16 * v89 + 50188;
      goto LABEL_79;
    case 8u:
      result = *(unsigned __int8 *)(a1 + 172);
      goto LABEL_79;
    case 9u:
      if ( (*(_BYTE *)(v6 + 1377) & 8) == 0 )
      {
LABEL_51:
        ipc_log_string(v7[157], "%s: No Pullup\n", "usb_gsi_ep_op");
        result = 4294967188LL;
        goto LABEL_79;
      }
      v35 = *(_QWORD *)(a1 + 152);
      v36 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v35 + 368) + 96LL) + 152LL);
      if ( *(unsigned __int8 *)(a1 + 170) >= 2u )
      {
        v37 = *(void **)(a1 + 136);
        if ( v37 )
        {
          if ( *(_QWORD *)(a1 + 144) )
          {
            memset(v37, 0, 0x1000u);
            dwc3_dbg_print(*(_QWORD *)(v36 + 1256), *(_BYTE *)(a1 + 170), "Clr_TRB", 0, (const char *)&unk_16A05);
            dev_info(*(_QWORD *)(v35 + 368), "Clr_TRB ring of %s\n", (const char *)(a1 + 184));
            dma_free_attrs(*(_QWORD *)(v35 + 376), 4096, *(_QWORD *)(a1 + 136), *(_QWORD *)(a1 + 144), 0);
            v35 = *(_QWORD *)(a1 + 152);
            *(_QWORD *)(a1 + 136) = 0;
            *(_QWORD *)(a1 + 144) = 0;
            v36 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v35 + 368) + 96LL) + 152LL);
          }
        }
      }
      v38 = a2[2];
      v39 = *(_BYTE *)(a1 + 204);
      v40 = a2[3] * v38;
      v41 = dma_alloc_attrs(*(_QWORD *)(v35 + 376), v40, a2 + 1, 3264, 0);
      *a2 = v41;
      if ( !v41 )
        goto LABEL_81;
      v42 = (_DWORD)v38 << (v39 & 1);
      v43 = v42 + 2;
      dma_get_sgtable_attrs(*(_QWORD *)(v35 + 376), a2 + 9, v41, a2[1], v40, 0);
      v44 = *(_QWORD *)(v36 + 1256);
      v45 = a2[3];
      v110 = a2[1];
      ipc_log_string(v44, "%s: TRB buffer_addr = %pad buf_len = %zu\n", "gsi_prepare_trbs", &v110, v45);
      v46 = dma_alloc_attrs(*(_QWORD *)(v35 + 376), 16LL * (v42 + 2), a1 + 144, 3264, 0);
      *(_QWORD *)(a1 + 136) = v46;
      if ( !v46 )
      {
        dma_free_attrs(*(_QWORD *)(v35 + 376), v40, *a2, a2[1], 0);
        *a2 = 0;
        sg_free_table(a2 + 9);
LABEL_81:
        result = 4294967284LL;
        goto LABEL_79;
      }
      v9 = memset(*(void **)(a1 + 136), 0, 16LL * v43);
      if ( *(unsigned __int8 *)(a1 + 170) < 0x20uLL )
      {
        v47 = *(_QWORD *)(a1 + 144);
        *(_DWORD *)(v36 + 40LL * *(unsigned __int8 *)(a1 + 170) + 1300) = v43;
        dma_get_sgtable_attrs(
          *(_QWORD *)(v35 + 376),
          a2 + 7,
          *(_QWORD *)(a1 + 136),
          *(_QWORD *)(a1 + 144),
          16LL * v43,
          0);
        if ( *((_DWORD *)a2 + 16) )
        {
          v48 = a2[7];
          v49 = 0;
          do
          {
            ++v49;
            v48 = sg_next(v48);
          }
          while ( v49 < *((_DWORD *)a2 + 16) );
        }
        v50 = *(_DWORD **)(a1 + 136);
        if ( (*(_BYTE *)(a1 + 204) & 1) != 0 )
        {
          if ( a2[2] == -1 )
          {
            v106 = 0;
          }
          else
          {
            v106 = 0;
            do
            {
              v50[3] = 2064;
              ++v106;
              v50 += 4;
            }
            while ( a2[2] + 1 > (unsigned __int64)v106 );
          }
          if ( v106 < v42 + 1 )
          {
            LODWORD(v107) = v110;
            v108 = v42 - v106 + 1;
            do
            {
              *v50 = v107;
              --v108;
              v109 = HIDWORD(v110);
              v50[3] = 2064;
              v50[1] = v109;
              v50 += 4;
              v107 = v110 + a2[3];
              v110 = v107;
            }
            while ( v108 );
          }
          result = 0;
          *v50 = v47;
          v50[1] = WORD2(v47);
          v50[1] = WORD2(v47) | (*((unsigned __int8 *)a2 + 52) << 16) | 0xA00000;
          v50[3] = 129;
        }
        else
        {
          *(_QWORD *)v50 = v47 + 16;
          v50[3] = 128;
          v51 = v50 + 4;
          if ( v42 + 1 >= 2 )
          {
            do
            {
              --v42;
              *(_QWORD *)v51 = v110;
              v51[2] = a2[3];
              v110 += a2[3];
              v51[3] = 3096;
              v51 += 4;
            }
            while ( v42 );
            v50 = v51 - 4;
          }
          *v51 = v47;
          result = 0;
          v50[5] = WORD2(v47);
          v50[5] = WORD2(v47) | (*((unsigned __int8 *)a2 + 52) << 16) | 0xA00000;
          v50[7] = 129;
        }
        goto LABEL_79;
      }
LABEL_93:
      __break(0x5512u);
      if ( !v10 )
        JUMPOUT(0xFFFFFFFFFFFEC5ECLL);
      return msm_ep_config(v9);
    case 0xAu:
      if ( *(unsigned __int8 *)(a1 + 170) >= 0x20uLL )
        goto LABEL_93;
      v84 = *(_QWORD *)(a1 + 152);
      v85 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v84 + 368) + 96LL) + 152LL) + 40LL * *(unsigned __int8 *)(a1 + 170);
      if ( *(_DWORD *)(v85 + 1280) == 2 )
      {
        v86 = *(_QWORD *)(a1 + 144);
        if ( v86 )
        {
          dma_free_attrs(*(_QWORD *)(v84 + 376), 16LL * *(int *)(v85 + 1300), *(_QWORD *)(a1 + 136), v86, 0);
          *(_QWORD *)(a1 + 136) = 0;
          *(_QWORD *)(a1 + 144) = 0;
        }
        sg_free_table(a2 + 7);
        dma_free_attrs(*(_QWORD *)(v84 + 376), a2[2] * a2[3], *a2, a2[1], 0);
        *a2 = 0;
        sg_free_table(a2 + 9);
      }
      if ( !*(_QWORD *)(a1 + 136) )
      {
        v87 = dma_alloc_attrs(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 376LL), 4096, a1 + 144, 3264, 0);
        *(_QWORD *)(a1 + 136) = v87;
        if ( !v87 )
          dev_err(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 368LL), "failed to allocate trb pool for %s\n", a1 + 184);
      }
      goto LABEL_78;
    case 0xBu:
      v19 = *(unsigned __int8 *)a2;
      v20 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 368LL) + 96LL) + 152LL);
      v21 = *(_QWORD *)(v20 + 8);
      v22 = (unsigned int)(**(_DWORD **)(v20 + 1136) + 1017856);
      v23 = readl(v21 + v22) & 0xFFFFFFFD;
      if ( v19 )
        v24 = 2;
      else
        v24 = 0;
      writel(v23 | (unsigned int)v24, v21 + v22);
      readl(v21 + v22);
      goto LABEL_78;
    case 0xCu:
      v33 = -1501;
      break;
    case 0xDu:
      v81 = raw_spin_lock_irqsave(v6 + 312);
      dwc3_core_stop_active_transfer(a1);
      raw_spin_unlock_irqrestore(v6 + 312, v81);
      v82 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 16) + 8LL);
      if ( *((_DWORD *)v82 - 1) != 860141900 )
        __break(0x8228u);
      result = v82(a1);
      goto LABEL_79;
    default:
      dev_err(*v7, "%s: Invalid opcode GSI EP\n", "usb_gsi_ep_op");
      goto LABEL_78;
  }
  do
  {
    if ( (readl(v7[1] + (unsigned int)(*(_DWORD *)(v7[142] + 20LL) + 1017856)) & 0x8000) == 0 )
    {
      result = 1;
      goto LABEL_79;
    }
  }
  while ( !__CFADD__(v33++, 1) );
  dev_err(*v7, "Unable to suspend GSI ch. WR_CTRL_STATE != 0\n");
LABEL_78:
  result = 0;
LABEL_79:
  _ReadStatusReg(SP_EL0);
  return result;
}
