__int64 __fastcall i3c_geni_execute_read_command(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  int v4; // w9
  __int64 v7; // x24
  __int64 result; // x0
  int v9; // w8
  __int64 v10; // x0
  int v11; // w6
  __int64 v12; // x21
  const char **v13; // x22
  __int64 v14; // x23
  char v15; // w0
  __int64 v16; // x0
  int v17; // w8
  __int64 v18; // x3
  __int64 v19; // x0
  bool v20; // zf
  __int64 v21; // x0
  char v22; // w8
  unsigned int v23; // w0
  int v24; // w0
  unsigned int v25; // w0
  const char *v26; // x2
  unsigned int v27; // w0
  unsigned int v28; // w20
  unsigned int v29; // w3
  unsigned int v30; // w20
  unsigned int v31; // w20
  __int64 v32; // x2
  __int64 v33; // x3
  __int64 v34; // x0
  const char *v35; // x0
  const char *v36; // x2
  __int64 v37; // x3
  __int64 v38; // x0
  char v39; // [xsp+1Ch] [xbp+1Ch]

  v4 = *(_DWORD *)(a1 + 108);
  v7 = a1 + 21200;
  *(_QWORD *)(a1 + 21264) = a3;
  *(_DWORD *)(a1 + 21272) = 1;
  *(_DWORD *)(a1 + 21276) = a4;
  if ( v4 != 3 )
    return geni_i3c_fifo_dma_xfer(a1, a2);
  if ( (*(_BYTE *)v7 & 1) != 0 || (result = geni_gsi_common_request_channel(a1 + 2712), !(_DWORD)result) )
  {
    v9 = *(unsigned __int8 *)(v7 + 440);
    *(_DWORD *)(a1 + 104) = 0;
    *(_BYTE *)(v7 + 40) = 0;
    *(_BYTE *)(a1 + 2960) = 0;
    *(_BYTE *)(a1 + 12184) = 0;
    *(_DWORD *)(a1 + 2552) = 0;
    if ( v9 == 1 && !*(_DWORD *)(a2 + 16) )
    {
      v10 = *(_QWORD *)(a1 + 2528);
      v11 = *(_BYTE *)(a1 + 2980) ? 3146753 : 3145729;
      *(_QWORD *)(a1 + 2848) = 0;
      *(_DWORD *)(a1 + 2856) = 0;
      *(_DWORD *)(a1 + 2860) = v11;
      *(_BYTE *)(a1 + 2960) = 1;
      ipc_log_string(
        v10,
        "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n",
        "i3c_setup_lock_tre",
        0,
        0,
        0);
      if ( *(_QWORD *)(a1 + 8) )
        i3c_trace_log();
    }
    if ( (*(_BYTE *)(v7 + 41) & 1) == 0 )
    {
      i3c_setup_cfg0_tre(a1, 0, 0, 0);
      *(_BYTE *)(a1 + 2960) |= 2u;
    }
    i3c_setup_go_tre(a1, a2, *(unsigned int *)(a2 + 16), 0, 0);
    v12 = *(int *)(v7 + 76);
    *(_BYTE *)(a1 + 2960) |= 4u;
    if ( !(_DWORD)v12 )
    {
      v18 = *(_QWORD *)(a1 + 21232);
      v17 = 0;
      goto LABEL_22;
    }
    v13 = *(const char ***)(a1 + 21632);
    if ( !v13 )
    {
      v31 = -22;
LABEL_64:
      ipc_log_string(
        *(_QWORD *)(a1 + 2528),
        "%s:geni_se_common_iommu_map_buf failed ret:%d\n",
        "geni_i3c_gsi_read",
        v31);
      v38 = *(_QWORD *)(a1 + 8);
      if ( v38 )
        dev_err(v38, "%s:geni_se_common_iommu_map_buf failed ret:%d\n", "geni_i3c_gsi_read", v31);
      else
        printk(&unk_12C8C, "geni_i3c_gsi_read", v31, v37);
      if ( *(_QWORD *)(a1 + 8) )
        i3c_trace_log();
      return v31;
    }
    v14 = *(_QWORD *)(a1 + 21264);
    v15 = is_vmalloc_addr(v14);
    if ( (v15 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
    {
      v39 = v15;
      dma_map_single_attrs___already_done = 1;
      v35 = (const char *)dev_driver_string(v13);
      v36 = v13[14];
      if ( !v36 )
        v36 = *v13;
      _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v35, v36);
      __break(0x800u);
      if ( (v39 & 1) == 0 )
      {
LABEL_18:
        v16 = dma_map_page_attrs(
                v13,
                ((unsigned __int64)((v14 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
                v14 & 0xFFF,
                v12,
                2,
                0);
        *(_QWORD *)(a1 + 21232) = v16;
        if ( v16 != -1 )
        {
          v17 = *(_DWORD *)(v7 + 76);
          v18 = v16;
LABEL_22:
          v19 = *(_QWORD *)(a1 + 2528);
          *(_DWORD *)(a1 + 12120) = v18;
          *(_DWORD *)(a1 + 12128) = v17 & 0xFFFFFF;
          *(_DWORD *)(a1 + 12124) = HIDWORD(v18);
          *(_DWORD *)(a1 + 12132) = 1049088;
          ipc_log_string(
            v19,
            "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n",
            "i3c_setup_rx_tre",
            v18,
            HIDWORD(v18),
            v17 & 0xFFFFFF,
            1049088);
          if ( *(_QWORD *)(a1 + 8) )
            i3c_trace_log();
          v20 = *(_BYTE *)(v7 + 440) == 1;
          *(_BYTE *)(a1 + 12184) |= 8u;
          if ( v20 && *(_DWORD *)(a2 + 16) == *(_DWORD *)(v7 + 84) - 1 )
          {
            v21 = *(_QWORD *)(a1 + 2528);
            v22 = *(_BYTE *)(a1 + 2960) | 0x40;
            *(_QWORD *)(a1 + 2944) = 0;
            *(_QWORD *)(a1 + 2952) = 0x31010000000000LL;
            *(_BYTE *)(a1 + 2960) = v22;
            ipc_log_string(
              v21,
              "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n",
              "i3c_setup_unlock_tre",
              0,
              0,
              0,
              3211520);
            if ( *(_QWORD *)(a1 + 8) )
              i3c_trace_log();
          }
          v23 = gsi_common_fill_tre_buf(a1 + 2712, 0);
          v24 = gsi_common_prep_desc_and_submit(a1 + 2712, v23, 0, 0);
          if ( v24 < 0
            || (v25 = gsi_common_fill_tre_buf(a1 + 2712, 1),
                v24 = gsi_common_prep_desc_and_submit(a1 + 2712, v25, 1, 0),
                v24 < 0) )
          {
            *(_DWORD *)(a1 + 104) = v24;
          }
          else if ( (unsigned int)wait_for_completion_timeout(a1 + 2552, &print_fmt_i3c_log_info[2], v26) )
          {
            if ( (*(_BYTE *)(v7 + 41) & 1) == 0 )
              *(_BYTE *)(v7 + 41) = 1;
          }
          else
          {
            ipc_log_string(*(_QWORD *)(a1 + 2528), "%s:wait_for_completion timed out\n", "geni_i3c_gsi_read");
            v34 = *(_QWORD *)(a1 + 8);
            if ( v34 )
              dev_err(v34, "%s:wait_for_completion timed out\n", "geni_i3c_gsi_read");
            else
              printk(&unk_14E9D, "geni_i3c_gsi_read", v32, v33);
            if ( *(_QWORD *)(a1 + 8) )
              i3c_trace_log();
            geni_i3c_err(a1, 9);
            *(_QWORD *)(a1 + 21264) = 0;
            *(_DWORD *)(v7 + 80) = 0;
            *(_DWORD *)(v7 + 72) = 0;
            *(_DWORD *)(a1 + 2552) = 0;
          }
          v27 = geni_i3c_err_prep_sg(a1);
          if ( *(_DWORD *)(v7 + 76) && *(_QWORD *)(a1 + 21232) != -1 )
          {
            v28 = v27;
            dma_unmap_page_attrs(*(_QWORD *)(a1 + 21632));
            v27 = v28;
          }
          v29 = *(_DWORD *)(a1 + 104);
          if ( v29 )
          {
            *(_DWORD *)(v7 + 76) = 0;
            if ( v29 == -61 )
            {
              v29 = 0;
              v30 = 0;
              *(_DWORD *)(a1 + 104) = 0;
            }
            else
            {
              *(_DWORD *)(v7 + 60) = 0;
              if ( v29 == -16 )
                v30 = 3;
              else
                v30 = v29;
            }
            ipc_log_string(*(_QWORD *)(a1 + 2528), "%s:I3C transaction error:%d\n", "geni_i3c_gsi_read", v29);
            if ( *(_QWORD *)(a1 + 8) )
              i3c_trace_log();
          }
          else
          {
            v30 = v27;
            *(_DWORD *)(v7 + 60) = *(_DWORD *)(v7 + 76);
          }
          ipc_log_string(*(_QWORD *)(a1 + 2528), "%s:xfer_len :%d\n", "geni_i3c_gsi_read", *(_DWORD *)(v7 + 60));
          if ( *(_QWORD *)(a1 + 8) )
            i3c_trace_log();
          result = v30;
          if ( !v30 )
            return *(unsigned int *)(a1 + 104);
          return result;
        }
        goto LABEL_63;
      }
    }
    else if ( (v15 & 1) == 0 )
    {
      goto LABEL_18;
    }
    *(_QWORD *)(a1 + 21232) = -1;
LABEL_63:
    v31 = -5;
    goto LABEL_64;
  }
  return result;
}
