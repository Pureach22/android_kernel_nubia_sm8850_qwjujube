__int64 __fastcall i3c_geni_execute_write_command(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  int v4; // w8
  __int64 v7; // x25
  __int64 result; // x0
  int v9; // w8
  size_t v10; // x22
  unsigned int v11; // w26
  char *v12; // x21
  __int64 v13; // x0
  const char **v14; // x23
  unsigned __int64 v15; // x24
  char v16; // w0
  __int64 v17; // x0
  char *v18; // x23
  int v19; // w2
  __int64 v20; // x0
  unsigned int v21; // w8
  int v22; // w9
  __int64 v23; // x9
  __int64 v24; // x10
  __int64 v25; // x11
  char v26; // w10
  __int64 v27; // x0
  int v28; // w6
  __int64 v29; // x21
  const char **v30; // x22
  __int64 v31; // x23
  char v32; // w0
  __int64 v33; // x0
  int v34; // w8
  __int64 v35; // x9
  int v36; // w9
  bool v37; // zf
  __int64 v38; // x9
  _BOOL8 v39; // x5
  int v40; // w9
  bool v41; // zf
  __int64 v42; // x9
  _BOOL8 v43; // x5
  int v44; // w9
  __int64 v45; // x0
  char v46; // w8
  unsigned int v47; // w0
  int v48; // w0
  const char *v49; // x2
  unsigned int v50; // w20
  unsigned int v51; // w3
  __int64 v52; // x0
  unsigned int v53; // w20
  __int64 v54; // x2
  __int64 v55; // x3
  __int64 v56; // x0
  __int64 v57; // x1
  __int64 v58; // x2
  __int64 v59; // x3
  __int64 v60; // x0
  unsigned int v61; // w20
  char v62; // w24
  const char *v63; // x0
  const char *v64; // x2
  __int64 v65; // x3
  __int64 v66; // x0
  const char *v67; // x0
  const char *v68; // x2
  __int64 v69; // x3
  __int64 v70; // x0
  char v71; // [xsp+1Ch] [xbp+1Ch]

  v4 = *(_DWORD *)(a1 + 108);
  v7 = a1 + 20480;
  *(_QWORD *)(a1 + 21264) = a3;
  *(_DWORD *)(a1 + 21272) = 0;
  *(_DWORD *)(a1 + 21276) = a4;
  if ( v4 != 3 )
    return geni_i3c_fifo_dma_xfer(a1, a2);
  if ( (*(_BYTE *)(a1 + 21200) & 1) == 0 )
  {
    result = geni_gsi_common_request_channel(a1 + 2712);
    if ( (_DWORD)result )
      return result;
  }
  v9 = *(unsigned __int8 *)(v7 + 1176);
  *(_DWORD *)(a1 + 104) = 0;
  *(_BYTE *)(v7 + 760) = 0;
  *(_BYTE *)(a1 + 2960) = 0;
  *(_BYTE *)(v7 + 1244) = 0;
  *(_DWORD *)(v7 + 1240) = 0;
  *(_DWORD *)(a1 + 2552) = 0;
  if ( v9 == 1 )
  {
    v10 = *(unsigned int *)(v7 + 796);
    v11 = *(_DWORD *)(v7 + 796) & 0xF;
    if ( (v10 & 0xF) != 0 )
    {
      v12 = *(char **)(a1 + 21264);
      *(_DWORD *)(v7 + 1212) = 0;
      *(_QWORD *)(v7 + 1180) = 0;
      *(_QWORD *)(v7 + 1188) = 0;
      *(_QWORD *)(v7 + 1196) = 0;
      *(_QWORD *)(v7 + 1204) = 0;
      if ( (int)v10 < 16 || ((unsigned __int8)v12 & 0xF) == 0 )
      {
        ipc_log_string(*(_QWORD *)(a1 + 2528), "using client buffer\n");
        if ( *(_QWORD *)(a1 + 8) )
          i3c_trace_log();
LABEL_22:
        if ( (int)v10 > 0x2000 && (*(_BYTE *)(v7 + 1244) & 1) != 0 )
        {
          v19 = -22;
LABEL_25:
          v20 = *(_QWORD *)(a1 + 2528);
          *(_DWORD *)(v7 + 1240) = v19;
          ipc_log_string(v20, "split tx dma tre failed ret:%d\n", v19);
          if ( *(_QWORD *)(a1 + 8) )
            i3c_trace_log();
          return *(unsigned int *)(v7 + 1240);
        }
        if ( (unsigned int)v10 > 0xF )
        {
          v23 = (unsigned int)v10 & 0xFFFFFFF0;
          *(_QWORD *)(a1 + 21672) = v12;
          if ( v11 >= 8 )
            v21 = 8;
          else
            v21 = v10 & 0xF;
          v12 += v23;
          *(_DWORD *)(v7 + 1180) = v23;
          *(_DWORD *)(v7 + 1184) = v21;
          *(_QWORD *)(a1 + 21680) = v12;
          if ( v11 < 9 )
          {
            v22 = 2;
            goto LABEL_42;
          }
          v22 = 3;
          v24 = 21688;
          v25 = 21668;
          LODWORD(v10) = v10 & 0xF;
        }
        else
        {
          *(_QWORD *)(a1 + 21672) = v12;
          if ( (unsigned int)v10 >= 8 )
            v21 = 8;
          else
            v21 = v10;
          *(_DWORD *)(v7 + 1180) = v21;
          if ( (unsigned int)v10 < 9 )
          {
            v22 = 1;
LABEL_42:
            *(_DWORD *)(v7 + 1240) = v22;
            goto LABEL_43;
          }
          v22 = 2;
          v24 = 21680;
          v25 = 21664;
        }
        *(_DWORD *)(a1 + v25) = v10 - 8;
        *(_QWORD *)(a1 + v24) = &v12[v21];
        goto LABEL_42;
      }
      if ( *(_QWORD *)(a1 + 21696) )
      {
LABEL_18:
        v18 = *(char **)(a1 + 21704);
        memcpy(v18, v12, v10);
        v12 = v18;
        goto LABEL_22;
      }
      v13 = devm_kmalloc(*(_QWORD *)(a1 + 8), 8208, 3520);
      *(_QWORD *)(a1 + 21696) = v13;
      if ( !v13 )
      {
        ipc_log_string(*(_QWORD *)(a1 + 2528), "split buf allocation failed\n");
        v60 = *(_QWORD *)(a1 + 8);
        if ( v60 )
          dev_err(v60, "split buf allocation failed\n");
        else
          printk(&unk_1441F, v57, v58, v59);
        if ( *(_QWORD *)(a1 + 8) )
          i3c_trace_log();
        v19 = -12;
        goto LABEL_25;
      }
      v14 = *(const char ***)(a1 + 21632);
      if ( (v13 & 0xF) != 0 )
        v15 = (v13 + 15) & 0xFFFFFFFFFFFFFFF0LL;
      else
        v15 = v13;
      *(_QWORD *)(a1 + 21704) = v15;
      if ( !v14 )
      {
        v61 = -22;
LABEL_122:
        ipc_log_string(
          *(_QWORD *)(a1 + 2528),
          "%s:geni_se_common_iommu_map_buf failed ret:%d\n",
          "geni_i3c_alloc_aligned_dma_buffers",
          v61);
        v70 = *(_QWORD *)(a1 + 8);
        if ( v70 )
          dev_err(v70, "%s:geni_se_common_iommu_map_buf failed ret:%d\n", "geni_i3c_alloc_aligned_dma_buffers", v61);
        else
          printk(&unk_12C8C, "geni_i3c_alloc_aligned_dma_buffers", v61, v69);
        if ( *(_QWORD *)(a1 + 8) )
          i3c_trace_log();
        v19 = v61;
        goto LABEL_25;
      }
      v16 = is_vmalloc_addr(v15);
      if ( (v16 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
      {
        v71 = v16;
        dma_map_single_attrs___already_done = 1;
        v67 = (const char *)dev_driver_string(v14);
        v68 = v14[14];
        if ( !v68 )
          v68 = *v14;
        _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v67, v68);
        __break(0x800u);
        if ( (v71 & 1) == 0 )
        {
LABEL_17:
          v17 = dma_map_page_attrs(
                  v14,
                  ((unsigned __int64)(((__int64)(v15 << 8) >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
                  v15 & 0xFF0,
                  0x2000,
                  1,
                  0);
          *(_QWORD *)(a1 + 21712) = v17;
          if ( v17 != -1 )
            goto LABEL_18;
          goto LABEL_121;
        }
      }
      else if ( (v16 & 1) == 0 )
      {
        goto LABEL_17;
      }
      *(_QWORD *)(a1 + 21712) = -1;
LABEL_121:
      v61 = -5;
      goto LABEL_122;
    }
  }
LABEL_43:
  if ( *(_BYTE *)(v7 + 1160) == 1 && !*(_DWORD *)(a2 + 16) )
  {
    v26 = *(_BYTE *)(a1 + 2960);
    v27 = *(_QWORD *)(a1 + 2528);
    v28 = *(_BYTE *)(a1 + 2980) ? 3146753 : 3145729;
    *(_QWORD *)(a1 + 2848) = 0;
    *(_DWORD *)(a1 + 2856) = 0;
    *(_DWORD *)(a1 + 2860) = v28;
    *(_BYTE *)(a1 + 2960) = v26 | 1;
    ipc_log_string(v27, "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n", "i3c_setup_lock_tre", 0, 0, 0);
    if ( *(_QWORD *)(a1 + 8) )
      i3c_trace_log();
  }
  if ( (*(_BYTE *)(v7 + 761) & 1) == 0 )
  {
    i3c_setup_cfg0_tre(a1, 0, 0, 0);
    *(_BYTE *)(a1 + 2960) |= 2u;
  }
  i3c_setup_go_tre(a1, a2, *(unsigned int *)(a2 + 16), 0, 0);
  v29 = *(int *)(v7 + 796);
  *(_BYTE *)(a1 + 2960) |= 4u;
  if ( !(_DWORD)v29 )
    goto LABEL_72;
  if ( (*(_BYTE *)(v7 + 1244) & 1) == 0 )
  {
    v30 = *(const char ***)(a1 + 21632);
    if ( !v30 )
    {
      v53 = -22;
      goto LABEL_112;
    }
    v31 = *(_QWORD *)(a1 + 21264);
    v32 = is_vmalloc_addr(v31);
    if ( (v32 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
    {
      v62 = v32;
      dma_map_single_attrs___already_done = 1;
      v63 = (const char *)dev_driver_string(v30);
      v64 = v30[14];
      if ( !v64 )
        v64 = *v30;
      _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v63, v64);
      __break(0x800u);
      if ( (v62 & 1) == 0 )
      {
LABEL_58:
        v33 = dma_map_page_attrs(
                v30,
                ((unsigned __int64)((v31 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
                v31 & 0xFFF,
                v29,
                1,
                0);
        *(_QWORD *)(a1 + 2984) = v33;
        if ( v33 != -1 )
          goto LABEL_59;
        goto LABEL_111;
      }
    }
    else if ( (v32 & 1) == 0 )
    {
      goto LABEL_58;
    }
    *(_QWORD *)(a1 + 2984) = -1;
LABEL_111:
    v53 = -5;
LABEL_112:
    ipc_log_string(*(_QWORD *)(a1 + 2528), "%s:geni_se_common_iommu_map_buf failed ret:%d\n", "geni_i3c_gsi_write", v53);
    v66 = *(_QWORD *)(a1 + 8);
    if ( v66 )
      dev_err(v66, "%s:geni_se_common_iommu_map_buf failed ret:%d\n", "geni_i3c_gsi_write", v53);
    else
      printk(&unk_12C8C, "geni_i3c_gsi_write", v53, v65);
    if ( !*(_QWORD *)(a1 + 8) )
      return v53;
LABEL_90:
    i3c_trace_log();
    return v53;
  }
LABEL_59:
  if ( *(_BYTE *)(v7 + 1176) != 1 )
  {
LABEL_71:
    ((void (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))i3c_setup_tx_tre)(a1, 0, 0, 0, 0, 0);
    *(_BYTE *)(a1 + 2960) |= 8u;
    goto LABEL_72;
  }
  v34 = *(_DWORD *)(v7 + 1240);
  if ( v34 >= 1 )
  {
    v35 = *(_QWORD *)(a1 + 21672);
    *(_DWORD *)(v7 + 796) = *(_DWORD *)(v7 + 1180);
    *(_QWORD *)(a1 + 21264) = v35;
    ((void (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, bool))i3c_setup_tx_tre)(a1, 0, 0, 0, 0, v34 != 1);
    v36 = *(_DWORD *)(v7 + 1240);
    v37 = v36 == 2;
    *(_BYTE *)(a1 + 2960) |= 8u;
    if ( v36 >= 2 )
    {
      v38 = *(_QWORD *)(a1 + 21680);
      v39 = !v37;
      *(_DWORD *)(v7 + 796) = *(_DWORD *)(v7 + 1184);
      *(_QWORD *)(a1 + 21264) = v38;
      ((void (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, __int64, _BOOL8))i3c_setup_tx_tre)(a1, 0, 0, 0, 1, v39);
      v40 = *(_DWORD *)(v7 + 1240);
      v41 = v40 == 3;
      *(_BYTE *)(a1 + 2960) |= 0x10u;
      if ( v40 >= 3 )
      {
        v42 = *(_QWORD *)(a1 + 21688);
        v43 = !v41;
        *(_DWORD *)(v7 + 796) = *(_DWORD *)(v7 + 1188);
        *(_QWORD *)(a1 + 21264) = v42;
        ((void (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, __int64, _BOOL8))i3c_setup_tx_tre)(a1, 0, 0, 0, 2, v43);
        v44 = *(_DWORD *)(v7 + 1240);
        *(_BYTE *)(a1 + 2960) |= 0x20u;
        if ( v44 > 3 )
        {
          __break(0x5512u);
          goto LABEL_71;
        }
      }
    }
  }
LABEL_72:
  if ( *(_BYTE *)(v7 + 1160) == 1 && *(_DWORD *)(a2 + 16) == *(_DWORD *)(v7 + 804) - 1 )
  {
    v45 = *(_QWORD *)(a1 + 2528);
    v46 = *(_BYTE *)(a1 + 2960) | 0x40;
    *(_QWORD *)(a1 + 2944) = 0;
    *(_QWORD *)(a1 + 2952) = 0x31010000000000LL;
    *(_BYTE *)(a1 + 2960) = v46;
    ipc_log_string(
      v45,
      "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n",
      "i3c_setup_unlock_tre",
      0,
      0,
      0,
      3211520);
    if ( *(_QWORD *)(a1 + 8) )
      i3c_trace_log();
  }
  v47 = gsi_common_fill_tre_buf(a1 + 2712, 1);
  v48 = gsi_common_prep_desc_and_submit(a1 + 2712, v47, 1, 0);
  if ( v48 < 0 )
  {
    *(_DWORD *)(a1 + 104) = v48;
  }
  else if ( (unsigned int)wait_for_completion_timeout(a1 + 2552, &print_fmt_i3c_log_info[2], v49) )
  {
    if ( (*(_BYTE *)(v7 + 761) & 1) == 0 )
      *(_BYTE *)(v7 + 761) = 1;
  }
  else
  {
    ipc_log_string(*(_QWORD *)(a1 + 2528), "%s:wait_for_completion timed out\n", "geni_i3c_gsi_write");
    v56 = *(_QWORD *)(a1 + 8);
    if ( v56 )
      dev_err(v56, "%s:wait_for_completion timed out\n", "geni_i3c_gsi_write");
    else
      printk(&unk_14E9D, "geni_i3c_gsi_write", v54, v55);
    if ( *(_QWORD *)(a1 + 8) )
      i3c_trace_log();
    geni_i3c_err(a1, 9);
    *(_QWORD *)(a1 + 21264) = 0;
    *(_DWORD *)(v7 + 800) = 0;
    *(_DWORD *)(v7 + 792) = 0;
    *(_DWORD *)(a1 + 2552) = 0;
  }
  result = geni_i3c_err_prep_sg(a1);
  if ( *(_DWORD *)(v7 + 796) && (*(_BYTE *)(v7 + 1244) & 1) == 0 && *(_QWORD *)(a1 + 2984) != -1 )
  {
    v50 = result;
    dma_unmap_page_attrs(*(_QWORD *)(a1 + 21632));
    result = v50;
  }
  v51 = *(_DWORD *)(a1 + 104);
  if ( v51 )
  {
    v52 = *(_QWORD *)(a1 + 2528);
    *(_DWORD *)(v7 + 796) = 0;
    if ( v51 == -16 )
      v53 = 3;
    else
      v53 = v51;
    ipc_log_string(v52, "%s:I3C transaction error :%d\n", "geni_i3c_gsi_write");
    if ( !*(_QWORD *)(a1 + 8) )
      return v53;
    goto LABEL_90;
  }
  return result;
}
