__int64 __fastcall geni_i3c_master_priv_xfers(__int64 a1, unsigned __int8 *a2, unsigned int a3)
{
  __int64 v6; // x22
  __int64 v7; // x19
  unsigned __int64 v8; // x20
  __int64 v9; // x24
  __int64 v10; // x26
  unsigned int mutex_lock; // w0
  int v12; // w0
  __int64 v13; // x0
  unsigned int command; // w28
  char v15; // w23
  __int64 v16; // x10
  char v17; // w8
  unsigned __int8 *v18; // x9
  int v19; // t1
  __int64 v20; // x0
  unsigned int v21; // w8
  int v22; // w9
  __int64 v23; // x2
  int v24; // w3
  __int64 v25; // x25
  int v26; // w4
  int v27; // w19
  int v28; // w8
  unsigned __int8 *v29; // x20
  __int64 v30; // x2
  int v31; // w3
  __int64 v32; // x0
  bool v33; // zf
  int v34; // w3
  __int64 v35; // x0
  unsigned __int8 *v36; // x9
  unsigned int v37; // w20
  int v38; // w5
  __int64 v39; // x4
  char v40; // w8
  __int64 v41; // x24
  unsigned int v42; // w23
  unsigned int v43; // w28
  char v44; // w10
  __int64 v45; // x0
  int v46; // w6
  __int64 v47; // x19
  const char **v48; // x26
  unsigned int v49; // w28
  __int64 v50; // x27
  char v51; // w0
  char v52; // w23
  __int64 v53; // x0
  __int64 v54; // x0
  char v55; // w8
  unsigned int v56; // w0
  __int64 v57; // x1
  int v58; // w8
  __int64 v59; // x0
  __int64 v60; // x2
  __int64 v61; // x3
  __int64 v62; // x0
  const char *v63; // x0
  const char *v64; // x2
  __int64 v65; // x19
  __int64 v66; // x0
  __int64 v67; // x0
  __int64 v68; // x2
  int v69; // w3
  __int64 v70; // x19
  __int64 v71; // x0
  __int64 v72; // x19
  __int64 v73; // x0
  __int64 v75; // x3
  __int64 v76; // x0
  unsigned __int8 *v77; // x27
  unsigned __int64 v78; // x25
  __int64 v79; // x2
  int v80; // w3
  __int64 v81; // x4
  __int64 v82; // x0
  int v83; // w9
  int v84; // w8
  __int64 v85; // x2
  int v86; // w3
  __int64 v87; // x3
  __int64 v88; // x0
  __int64 v89; // [xsp+0h] [xbp-90h]
  __int64 v90; // [xsp+10h] [xbp-80h]
  __int64 v91; // [xsp+18h] [xbp-78h]
  unsigned int v92; // [xsp+24h] [xbp-6Ch]
  unsigned __int64 v93; // [xsp+28h] [xbp-68h]
  __int64 v94; // [xsp+30h] [xbp-60h]
  __int64 v95; // [xsp+38h] [xbp-58h]
  unsigned int v96; // [xsp+44h] [xbp-4Ch]
  __int64 v97; // [xsp+48h] [xbp-48h]
  __int64 v98; // [xsp+50h] [xbp-40h]
  unsigned __int64 v99; // [xsp+58h] [xbp-38h]
  int v100; // [xsp+58h] [xbp-38h]
  unsigned __int8 *v101; // [xsp+60h] [xbp-30h]
  __int64 v102; // [xsp+68h] [xbp-28h]
  __int64 v103; // [xsp+70h] [xbp-20h] BYREF
  __int64 v104; // [xsp+78h] [xbp-18h]
  int v105; // [xsp+80h] [xbp-10h]
  __int64 v106; // [xsp+88h] [xbp-8h]

  v106 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 16);
  v7 = *(_QWORD *)(v6 + 2424);
  if ( v7 )
  {
    if ( *(_DWORD *)(v6 + 2432) )
    {
      v8 = sched_clock(a1);
      ipc_log_string(v7, "%s:start at %llu nsec(%llu usec)\n", "geni_i3c_master_priv_xfers", v8, v8 / 0x3E8);
    }
    else
    {
      v8 = 0;
    }
  }
  else
  {
    v8 = -22;
  }
  ipc_log_string(*(_QWORD *)(v6 + 2416), "Enter %s num_xfer=%d\n", "geni_i3c_master_priv_xfers", a3);
  if ( *(_QWORD *)(v6 - 104) )
    i3c_trace_log();
  v9 = a3 - 1;
  if ( (int)a3 < 1 )
  {
    command = 0;
    goto LABEL_142;
  }
  v10 = v6 - 112;
  mutex_lock = i3c_geni_runtime_get_mutex_lock(v6 - 112);
  if ( mutex_lock )
  {
    command = mutex_lock;
    ipc_log_string(
      *(_QWORD *)(v6 + 2416),
      "%s: Failed, usage_count:%d\n",
      "geni_i3c_master_priv_xfers",
      *(_DWORD *)(*(_QWORD *)(v6 - 104) + 480LL));
    v76 = *(_QWORD *)(v6 - 104);
    if ( v76 )
      dev_err(v76, "%s: Failed, usage_count:%d\n", "geni_i3c_master_priv_xfers", *(_DWORD *)(v76 + 480));
    else
      printk(&unk_142C9, "geni_i3c_master_priv_xfers", (unsigned int)dword_1E0, v75);
    if ( *(_QWORD *)(v6 - 104) )
      goto LABEL_15;
    goto LABEL_142;
  }
  v12 = readl_relaxed((unsigned int *)(*(_QWORD *)v10 + 2312LL));
  if ( (~v12 & 3) != 0 )
  {
    ipc_log_string(*(_QWORD *)(v6 + 2416), "%s:IO lines:0x%x not in good state\n", "geni_i3c_master_priv_xfers", v12);
    if ( *(_QWORD *)(v6 - 104) )
      i3c_trace_log();
  }
  *(_DWORD *)(v6 + 21172) = a3;
  v13 = qcom_geni_i3c_conf(v6 - 112, 1);
  if ( !(_DWORD)v13 )
  {
    v15 = *(_BYTE *)(a1 + 43);
    v96 = a3;
    v95 = v6 - 112;
    v93 = v8;
    v102 = a3;
    if ( *(_DWORD *)(v6 - 4) != 3 )
    {
      v99 = a3 - 1;
      v20 = *(_QWORD *)(v6 + 2416);
      if ( *((unsigned __int16 *)a2 + 1) <= 0x40u )
        v21 = 1;
      else
        v21 = 2;
      if ( *(_BYTE *)(v6 + 21541) )
        v22 = 0x2000000;
      else
        v22 = 0;
      v103 = v21;
      v105 = 0;
      v104 = (v22 | (4 * (a3 != 1))) & 0xFFFF01FF | ((v15 & 0x7F) << 9);
      ipc_log_string(
        v20,
        "%s: hold_bus:%d,use_7e:%d, num_xfers:%d,i:%d,m_param:0x%x,rnw:%d\n",
        "geni_i3c_master_fifo_dma_priv_xfers",
        a3 != 1);
      if ( *(_QWORD *)(v6 - 104) )
        i3c_trace_log();
      if ( *a2 )
      {
        v23 = *((_QWORD *)a2 + 1);
        v24 = *((unsigned __int16 *)a2 + 1);
        HIDWORD(v103) = 10;
        command = i3c_geni_execute_read_command(v6 - 112, (__int64)&v103, v23, v24);
        if ( command )
          goto LABEL_127;
      }
      else
      {
        v68 = *((_QWORD *)a2 + 1);
        v69 = *((unsigned __int16 *)a2 + 1);
        HIDWORD(v103) = 9;
        command = i3c_geni_execute_write_command(v6 - 112, (__int64)&v103, v68, v69);
        if ( command )
          goto LABEL_127;
      }
      if ( a3 != 1 )
      {
        v77 = a2 + 24;
        v78 = 1;
        do
        {
          v81 = *(unsigned __int8 *)(v6 + 21541);
          v82 = *(_QWORD *)(v6 + 2416);
          v83 = *v77;
          if ( *((unsigned __int16 *)v77 + 1) <= 0x40u )
            v84 = 1;
          else
            v84 = 2;
          LODWORD(v103) = v84;
          LODWORD(v104) = ((v15 & 0x7F) << 9) | (4 * (v78 < v99));
          LODWORD(v89) = v83;
          ipc_log_string(
            v82,
            "%s: hold_bus:%d,use_7e:%d, num_xfers:%d,i:%d,m_param:0x%x,rnw:%d\n",
            "geni_i3c_master_fifo_dma_priv_xfers",
            v78 < v99,
            v81,
            v96,
            (unsigned int)v78,
            (unsigned int)v104,
            v89);
          if ( *(_QWORD *)(v6 - 104) )
            i3c_trace_log();
          if ( *v77 )
          {
            v85 = *((_QWORD *)v77 + 1);
            v86 = *((unsigned __int16 *)v77 + 1);
            HIDWORD(v103) = 10;
            command = i3c_geni_execute_read_command(v95, (__int64)&v103, v85, v86);
            if ( command )
              goto LABEL_127;
          }
          else
          {
            v79 = *((_QWORD *)v77 + 1);
            v80 = *((unsigned __int16 *)v77 + 1);
            HIDWORD(v103) = 9;
            command = i3c_geni_execute_write_command(v95, (__int64)&v103, v79, v80);
            if ( command )
              goto LABEL_127;
          }
          ++v78;
          v77 += 24;
        }
        while ( v102 != v78 );
      }
      command = 0;
LABEL_127:
      if ( *(_BYTE *)(v6 + 21529) == 1 && (*(_BYTE *)(v6 + 21538) & 1) == 0 )
        *(_BYTE *)(v6 + 21538) = 1;
      ipc_log_string(*(_QWORD *)(v6 + 2416), "%s ret:%d\n", "geni_i3c_master_priv_xfers", command);
      if ( *(_QWORD *)(v6 - 104) )
        i3c_trace_log();
      if ( *(_BYTE *)(v6 + 21538) == 1 && *(_BYTE *)(v6 + 21529) == 1 )
      {
        ipc_log_string(
          *(_QWORD *)(v6 + 2416),
          "%s: client controls the PM, return\n",
          "i3c_geni_runtime_put_mutex_unlock");
        if ( *(_QWORD *)(v6 - 104) )
          i3c_trace_log();
      }
      else
      {
        v70 = *(_QWORD *)(v6 - 104);
        *(_QWORD *)(v70 + 520) = ktime_get_mono_fast_ns();
        _pm_runtime_suspend(*(_QWORD *)(v6 - 104), 13);
      }
      v71 = mutex_unlock(v6 + 2504);
      v72 = *(_QWORD *)(v6 + 2424);
      if ( v72 && v8 && *(_DWORD *)(v6 + 2432) )
      {
        v73 = sched_clock(v71);
        ipc_log_string(
          v72,
          "%s:took %llu nsec(%llu usec)\n",
          "geni_i3c_master_priv_xfers",
          v73 - v8,
          (v73 - v8) / 0x3E8);
      }
      *(_DWORD *)(v6 + 21172) = 0;
      goto LABEL_142;
    }
    v90 = sched_clock(v13);
    v101 = a2;
    if ( a3 < 4 || (*(_BYTE *)(v6 + 21544) & 1) != 0 )
    {
      v17 = *(_BYTE *)(v6 + 2868);
    }
    else
    {
      v16 = a3;
      v17 = 1;
      v18 = a2;
      *(_BYTE *)(v6 + 2868) = 1;
      do
      {
        v19 = *v18;
        v18 += 24;
        if ( v19 )
        {
          v17 = 0;
          *(_BYTE *)(v6 + 2868) = 0;
        }
        --v16;
      }
      while ( v16 );
    }
    gpi_update_multi_desc_flag(*(_QWORD *)(v6 + 2688), v17 & 1, *(unsigned int *)(v6 + 21172));
    *(_DWORD *)(v6 + 11832) = 0;
    v25 = 0;
    *(_QWORD *)(v6 + 2856) = 0;
    v100 = (v15 & 0x7F) << 9;
    *(_DWORD *)(v6 + 2864) = 0;
    v97 = v6 + 10040;
    v94 = v6 + 6456;
    v103 = 0;
    v104 = 0;
    v91 = v6 + 2872;
    v98 = a3 - 1;
    while ( 1 )
    {
      v26 = *(unsigned __int8 *)(v6 + 21541);
      v105 = v25;
      v27 = v100 | (4 * (v25 < v9));
      *(_DWORD *)(v6 + 21148) = 0;
      LODWORD(v104) = v27;
      if ( !v25 )
      {
        if ( (v26 & 1) != 0 )
          v28 = 0x2000000;
        else
          v28 = 0;
        v27 |= v28;
        LODWORD(v104) = v27;
      }
      v29 = &v101[24 * v25];
      ipc_log_string(
        *(_QWORD *)(v6 + 2416),
        "%s: hold_bus:%d, use_7e:%d, num_msgs:%d, i:%d, m_param:0x%x, rnw:%d\n",
        "geni_i3c_master_gsi_priv_xfers",
        v25 < v9,
        v26,
        a3,
        v25,
        v27,
        *v29);
      if ( *(_QWORD *)(v6 - 104) )
        i3c_trace_log();
      if ( *v29 )
      {
        v30 = *((_QWORD *)v29 + 1);
        v31 = *((unsigned __int16 *)v29 + 1);
        HIDWORD(v103) = 10;
        v32 = i3c_geni_execute_read_command(v10, (__int64)&v103, v30, v31);
        command = v32;
        *((_WORD *)v29 + 2) = *(_DWORD *)(v6 + 21148);
        if ( (_DWORD)v32 )
          goto LABEL_120;
        goto LABEL_105;
      }
      v33 = *(_BYTE *)(v6 + 2868) == 1;
      HIDWORD(v103) = 9;
      if ( !v33 )
      {
        v32 = i3c_geni_execute_write_command(v10, (__int64)&v103, *((_QWORD *)v29 + 1), *((unsigned __int16 *)v29 + 1));
        command = v32;
        if ( (_DWORD)v32 )
          goto LABEL_120;
        goto LABEL_105;
      }
      *(_DWORD *)(v6 + 21160) = 0;
      v34 = *(_DWORD *)(v6 + 21172);
      v35 = *(_QWORD *)(v6 + 2416);
      v36 = &v101[24 * v25];
      v37 = v25 - 448 * ((613566757 * (unsigned __int64)((unsigned int)v25 >> 6)) >> 32);
      *(_QWORD *)(v94 + 8LL * v37) = *((_QWORD *)v36 + 1);
      v38 = *((unsigned __int16 *)v36 + 1);
      *(_DWORD *)(v97 + 4LL * v37) = v38;
      ipc_log_string(v35, "%s Enter num_xfer=%d idx=%d len=%d\n", "geni_i3c_gsi_multi_write", v34, v25, v38);
      if ( *(_QWORD *)(v6 - 104) )
        i3c_trace_log();
      v40 = *(_BYTE *)(v6 + 21088);
      *(_DWORD *)(v6 - 8) = 0;
      *(_BYTE *)(v6 + 21128) = 0;
      *(_BYTE *)(v6 + 2848) = 0;
      if ( (v40 & 1) == 0 )
      {
        v32 = geni_gsi_common_request_channel(v6 + 2600);
        if ( (_DWORD)v32 )
        {
          command = v32;
          goto LABEL_120;
        }
      }
      v41 = v25 + 1;
      BYTE4(v104) = 0;
      if ( ((v25 + 1) & 0x3F) != 0 )
      {
        if ( v25 == *(_DWORD *)(v6 + 21172) - 1 )
        {
          v42 = 0;
        }
        else
        {
          v42 = 1;
          BYTE4(v104) = 1;
        }
      }
      else
      {
        v42 = 0;
      }
      if ( *(_BYTE *)(v6 + 21528) != 1 )
        break;
      v43 = v42;
      if ( v25 == *(_DWORD *)(v6 + 21172) - 1 )
      {
        v43 = 0;
        v42 = 1;
        BYTE4(v104) = 1;
        if ( !v25 )
          goto LABEL_63;
      }
      else if ( !v25 )
      {
LABEL_63:
        v44 = *(_BYTE *)(v6 + 2848);
        v45 = *(_QWORD *)(v6 + 2416);
        if ( *(_BYTE *)(v6 + 2868) )
          v46 = 3146753;
        else
          v46 = 3145729;
        *(_QWORD *)(v6 + 2736) = 0;
        *(_DWORD *)(v6 + 2744) = 0;
        *(_DWORD *)(v6 + 2748) = v46;
        *(_BYTE *)(v6 + 2848) = v44 | 1;
        ipc_log_string(
          v45,
          "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n",
          "i3c_setup_lock_tre",
          0,
          0,
          0,
          v46);
        if ( *(_QWORD *)(v6 - 104) )
          i3c_trace_log();
        if ( (*(_BYTE *)(v6 + 21129) & 1) != 0 )
          goto LABEL_75;
LABEL_74:
        i3c_setup_cfg0_tre(v10, (unsigned int)v25, 1, 1, v39);
        *(_BYTE *)(v6 + 2848) |= 2u;
        goto LABEL_75;
      }
      if ( (*(_BYTE *)(v6 + 21129) & 1) == 0 )
        goto LABEL_74;
LABEL_75:
      i3c_setup_go_tre(v10, (__int64)&v103, v25, 1, 1);
      v47 = *(unsigned int *)(v97 + 4LL * v37);
      *(_BYTE *)(v6 + 2848) |= 4u;
      if ( (unsigned int)v47 >= 9 )
      {
        v48 = *(const char ***)(v6 + 21520);
        if ( !v48 )
        {
          command = -22;
LABEL_161:
          ipc_log_string(
            *(_QWORD *)(v6 + 2416),
            "%s:geni_se_common_iommu_map_buf fail ret:%d\n",
            "geni_i3c_gsi_multi_write",
            command);
          v88 = *(_QWORD *)(v6 - 104);
          v10 = v6 - 112;
          if ( v88 )
            dev_err(v88, "%s:geni_se_common_iommu_map_buf fail ret:%d\n", "geni_i3c_gsi_multi_write", command);
          else
            printk(&unk_12A7F, "geni_i3c_gsi_multi_write", command, v87);
          v32 = *(_QWORD *)(v6 - 104);
          if ( v32 )
            i3c_trace_log();
LABEL_120:
          v65 = *(_QWORD *)(v6 + 2416);
          v66 = sched_clock(v32);
          v67 = ipc_log_string(
                  v65,
                  "%s Time took for %d xfers = %llu nsecs\n",
                  "geni_i3c_master_gsi_priv_xfers",
                  a3,
                  v66 - v90);
          if ( *(_QWORD *)(v6 - 104) )
          {
            sched_clock(v67);
            i3c_trace_log();
          }
          geni_i3c_gsi_stop_on_bus(v10);
          gpi_update_multi_desc_flag(*(_QWORD *)(v6 + 2688), 0, 0);
          v8 = v93;
          if ( *(_BYTE *)(v6 + 21528) == 1 )
            *(_BYTE *)(v6 + 21129) = 0;
          goto LABEL_127;
        }
        v92 = v43;
        v49 = v42;
        v50 = *(_QWORD *)(v94 + 8LL * v37);
        v51 = is_vmalloc_addr(v50);
        v52 = v51;
        if ( (v51 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
        {
          dma_map_single_attrs___already_done = 1;
          v63 = (const char *)dev_driver_string(v48);
          v64 = v48[14];
          if ( !v64 )
            v64 = *v48;
          _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v63, v64);
          __break(0x800u);
          if ( (v52 & 1) != 0 )
          {
LABEL_118:
            *(_QWORD *)(v91 + 8LL * v37) = -1;
LABEL_119:
            a3 = v96;
            command = -5;
            goto LABEL_161;
          }
        }
        else if ( (v51 & 1) != 0 )
        {
          goto LABEL_118;
        }
        v53 = dma_map_page_attrs(
                v48,
                ((unsigned __int64)((v50 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
                v50 & 0xFFF,
                v47,
                1,
                0);
        *(_QWORD *)(v91 + 8LL * v37) = v53;
        if ( v53 == -1 )
          goto LABEL_119;
        a3 = v96;
        v42 = v49;
        v10 = v6 - 112;
        v43 = v92;
        LODWORD(v47) = *(_DWORD *)(v97 + 4LL * v37);
      }
      if ( (_DWORD)v47 )
      {
        ((void (__fastcall *)(__int64, _QWORD, _QWORD, __int64, _QWORD, _QWORD))i3c_setup_tx_tre)(
          v10,
          (unsigned int)v25,
          v42,
          1,
          0,
          0);
        *(_BYTE *)(v6 + 2848) |= 8u;
      }
      if ( *(_BYTE *)(v6 + 21528) == 1 && v25 == *(_DWORD *)(v6 + 21172) - 1 )
      {
        v54 = *(_QWORD *)(v6 + 2416);
        v55 = *(_BYTE *)(v6 + 2848) | 0x40;
        *(_QWORD *)(v6 + 2832) = 0;
        *(_QWORD *)(v6 + 2840) = 0x31010000000000LL;
        *(_BYTE *)(v6 + 2848) = v55;
        ipc_log_string(
          v54,
          "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n",
          "i3c_setup_unlock_tre",
          0,
          0,
          0,
          3211520);
        if ( *(_QWORD *)(v6 - 104) )
          i3c_trace_log();
      }
      v56 = gsi_common_fill_tre_buf(v6 + 2600, 1);
      ++*(_DWORD *)(v6 + 2856);
      v32 = gsi_common_prep_desc_and_submit(v6 + 2600, v56, 1, v43);
      command = v32;
      if ( (v32 & 0x80000000) != 0 )
      {
        *(_DWORD *)(v6 - 8) = v32;
      }
      else
      {
        if ( (*(_BYTE *)(v6 + 21129) & 1) == 0 )
          *(_BYTE *)(v6 + 21129) = 1;
        v57 = *(unsigned int *)(v6 + 21172);
        if ( v25 != (_DWORD)v57 - 1 && *(_DWORD *)(v6 + 2856) < (unsigned int)(*(_DWORD *)(v6 + 2864) + 448) )
          goto LABEL_106;
        v58 = gsi_common_tx_tre_optimization(v6 + 2600, v57, 64, 63, *(_QWORD *)(v6 + 21520));
        v59 = *(_QWORD *)(v6 + 2416);
        if ( v58 )
        {
          ipc_log_string(
            v59,
            "%s Completed xfer->tx_idx=%d num_xfers=%d gsi_bei=%d\n",
            "geni_i3c_gsi_multi_write",
            v25,
            *(_DWORD *)(v6 + 21172),
            v42);
          if ( *(_QWORD *)(v6 - 104) )
            i3c_trace_log();
        }
        else
        {
          ipc_log_string(v59, "%s:wait_for_completion timedout\n", "geni_i3c_gsi_multi_write");
          v62 = *(_QWORD *)(v6 - 104);
          if ( v62 )
            dev_err(v62, "%s:wait_for_completion timedout\n", "geni_i3c_gsi_multi_write");
          else
            printk(&unk_127F3, "geni_i3c_gsi_multi_write", v60, v61);
          if ( *(_QWORD *)(v6 - 104) )
            i3c_trace_log();
          geni_i3c_err(v10, 9u);
          *(_DWORD *)(v6 + 2440) = 0;
        }
      }
      v32 = geni_i3c_err_prep_sg(v10);
      if ( *(_DWORD *)(v6 - 8) )
      {
        gsi_common_tre_process(v6 + 2600, *(unsigned int *)(v6 + 21172), 64, *(_QWORD *)(v6 + 21520));
        command = *(_DWORD *)(v6 - 8) == -16 ? 3 : *(_DWORD *)(v6 - 8);
        ipc_log_string(*(_QWORD *)(v6 + 2416), "%s:I3C transaction error :%d\n", "geni_i3c_gsi_multi_write");
        v32 = *(_QWORD *)(v6 - 104);
        if ( v32 )
          i3c_trace_log();
      }
      if ( command )
        goto LABEL_120;
      command = *(_DWORD *)(v6 - 8);
      if ( command )
        goto LABEL_120;
LABEL_105:
      v41 = v25 + 1;
LABEL_106:
      v25 = v41;
      v33 = v41 == v102;
      v9 = v98;
      if ( v33 )
      {
        command = 0;
        goto LABEL_120;
      }
    }
    v43 = v42;
    if ( (*(_BYTE *)(v6 + 21129) & 1) != 0 )
      goto LABEL_75;
    goto LABEL_74;
  }
  command = v13;
  ipc_log_string(*(_QWORD *)(v6 + 2416), "%s:geni i3c config failed, ret:%d\n", "geni_i3c_master_priv_xfers", v13);
  if ( *(_QWORD *)(v6 - 104) )
LABEL_15:
    i3c_trace_log();
LABEL_142:
  _ReadStatusReg(SP_EL0);
  return command;
}
