__int64 __fastcall geni_i3c_master_send_ccc_cmd(__int64 a1, unsigned __int8 *a2)
{
  __int64 v2; // x21
  unsigned __int8 *v4; // x23
  __int64 result; // x0
  __int64 v6; // x20
  unsigned __int64 v7; // x22
  __int64 v8; // x27
  int mutex_lock; // w0
  int v10; // w0
  unsigned int v11; // w20
  unsigned int v12; // w8
  signed int v13; // w21
  unsigned __int8 v14; // w9
  int v15; // w8
  unsigned int v16; // w8
  __int64 v17; // x9
  int v18; // w10
  int v19; // w10
  int v20; // w8
  __int64 v21; // x8
  __int64 v22; // x2
  __int64 v23; // x3
  unsigned int v24; // w0
  __int64 v25; // x20
  unsigned __int8 *v26; // x25
  _QWORD *v27; // x23
  __int64 v28; // x2
  __int64 v29; // x3
  __int64 v30; // x0
  int v31; // w10
  __int64 v32; // x2
  __int64 v33; // x3
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x8
  __int64 v37; // x10
  __int64 *v38; // x28
  int v39; // w24
  unsigned __int64 v40; // x9
  __int64 v41; // x11
  unsigned __int64 v42; // x26
  __int64 v43; // x21
  unsigned __int8 v44; // w27
  __int64 v45; // x1
  int free_addr; // w20
  char v47; // w8
  int v48; // w8
  unsigned int v49; // w9
  bool v50; // cc
  __int64 *v51; // x8
  __int64 v52; // x0
  __int64 v53; // x20
  __int64 v54; // x0
  __int64 v55; // x0
  __int64 v56; // x21
  __int64 v57; // x21
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // [xsp+10h] [xbp-70h]
  unsigned __int8 *v61; // [xsp+20h] [xbp-60h]
  unsigned __int64 v62; // [xsp+28h] [xbp-58h]
  signed int v63; // [xsp+30h] [xbp-50h]
  __int64 v64; // [xsp+48h] [xbp-38h] BYREF
  __int64 v65; // [xsp+50h] [xbp-30h]
  signed int v66; // [xsp+58h] [xbp-28h]
  __int128 v67; // [xsp+60h] [xbp-20h] BYREF
  int v68; // [xsp+70h] [xbp-10h]
  __int64 v69; // [xsp+78h] [xbp-8h]

  v2 = a1 + 20480;
  v4 = a2;
  v69 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a1 + 21542) & 1) == 0 && a2[1] == 6 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 2416), "%s: skip RSTDAA for multi_ee manager\n", "geni_i3c_master_send_ccc_cmd");
    result = *(_QWORD *)(a1 - 104);
    if ( result )
    {
      i3c_trace_log();
      result = 0;
    }
    goto LABEL_139;
  }
  v6 = *(_QWORD *)(a1 + 2424);
  if ( v6 )
  {
    if ( *(_DWORD *)(a1 + 2432) )
    {
      v7 = ((__int64 (*)(void))sched_clock)();
      ipc_log_string(v6, "%s:start at %llu nsec(%llu usec)\n", "geni_i3c_master_send_ccc_cmd", v7, v7 / 0x3E8);
      if ( (char)v4[1] < 0 )
        goto LABEL_13;
    }
    else
    {
      v7 = 0;
      if ( (char)a2[1] < 0 )
        goto LABEL_13;
    }
  }
  else
  {
    v7 = -22;
    if ( (char)a2[1] < 0 )
      goto LABEL_13;
  }
  if ( *((_DWORD *)v4 + 1) != 1 )
  {
    result = 4294967274LL;
    goto LABEL_139;
  }
LABEL_13:
  v8 = a1 - 112;
  mutex_lock = i3c_geni_runtime_get_mutex_lock(a1 - 112);
  if ( mutex_lock )
  {
    v11 = mutex_lock;
    ipc_log_string(
      *(_QWORD *)(a1 + 2416),
      "%s: Failed:%d, usage_count:%d\n",
      "geni_i3c_master_send_ccc_cmd",
      mutex_lock,
      *(_DWORD *)(*(_QWORD *)(a1 - 104) + 480LL));
    v59 = *(_QWORD *)(a1 - 104);
    if ( v59 )
      dev_err(v59, "%s: Failed:%d, usage_count:%d\n", "geni_i3c_master_send_ccc_cmd", v11, *(_DWORD *)(v59 + 480));
    else
      printk(&unk_137C1, "geni_i3c_master_send_ccc_cmd", v11, (unsigned int)dword_1E0);
    if ( !*(_QWORD *)(a1 - 104) )
      goto LABEL_138;
    goto LABEL_137;
  }
  v10 = qcom_geni_i3c_conf(a1 - 112, 0);
  if ( v10 )
  {
    v11 = v10;
    ipc_log_string(*(_QWORD *)(a1 + 2416), "%s:geni i3c config failed, ret:%d\n", "geni_i3c_master_send_ccc_cmd", v10);
    if ( !*(_QWORD *)(a1 - 104) )
      goto LABEL_138;
LABEL_137:
    i3c_trace_log();
LABEL_138:
    result = v11;
    goto LABEL_139;
  }
  v12 = *((_DWORD *)v4 + 1);
  *(_DWORD *)(v2 + 692) = v12;
  if ( !v12 )
  {
    v11 = 0;
    goto LABEL_122;
  }
  v60 = v2;
  v13 = 0;
  _ReadStatusReg(SP_EL0);
  v61 = v4;
  while ( 2 )
  {
    if ( v13 >= v12 - 1 )
    {
      v14 = v4[1];
      v66 = 0;
      v64 = 1;
      v65 = 0;
      if ( v14 == 7 )
      {
        v66 = v13;
        v16 = 17235972;
        LODWORD(v65) = 17235972;
        goto LABEL_29;
      }
      v15 = 0;
    }
    else
    {
      v14 = v4[1];
      v15 = 4;
      v64 = 1;
      v65 = 0;
    }
    v66 = v13;
    v16 = v15 & 0xFF00FFFF | (v14 << 16) | 0x1000000;
    LODWORD(v65) = v16;
    if ( (v14 & 0x80) == 0 )
    {
LABEL_29:
      v17 = *((_QWORD *)v4 + 1);
      if ( *(_WORD *)(v17 + 24LL * v13 + 8) )
        v18 = 16;
      else
        v18 = 14;
      HIDWORD(v64) = v18;
      if ( v13 )
        goto LABEL_40;
      goto LABEL_33;
    }
    v17 = *((_QWORD *)v4 + 1);
    v16 |= (*(_BYTE *)(v17 + 24LL * v13) & 0x7F) << 9;
    v19 = *v4;
    LODWORD(v65) = v16;
    if ( v19 )
    {
      if ( v13 )
      {
        v20 = 10;
LABEL_39:
        HIDWORD(v64) = v20;
        goto LABEL_40;
      }
      HIDWORD(v64) = 18;
    }
    else
    {
      if ( v13 )
      {
        v20 = 9;
        goto LABEL_39;
      }
      if ( *(_WORD *)(v17 + 8) )
        v31 = 17;
      else
        v31 = 13;
      HIDWORD(v64) = v31;
    }
LABEL_33:
    LODWORD(v65) = v16 | 0x2000000;
LABEL_40:
    v21 = v17 + 24LL * v13;
    v22 = *(_QWORD *)(v21 + 16);
    v23 = *(unsigned __int16 *)(v21 + 8);
    if ( *v4 )
    {
      v24 = i3c_geni_execute_read_command(v8, &v64, v22, v23);
      if ( v24 )
        goto LABEL_119;
    }
    else
    {
      v24 = i3c_geni_execute_write_command(v8, &v64, v22, v23);
      if ( v24 )
      {
LABEL_119:
        v11 = v24;
        goto LABEL_121;
      }
    }
    if ( v4[1] != 7 )
      goto LABEL_22;
    v25 = *(_QWORD *)(a1 + 2424);
    if ( v25 )
    {
      if ( *(_DWORD *)(a1 + 2432) )
      {
        v62 = ((__int64 (*)(void))sched_clock)();
        ipc_log_string(v25, "%s:start at %llu nsec(%llu usec)\n", "geni_i3c_perform_daa", v62, v62 / 0x3E8);
      }
      else
      {
        v62 = 0;
      }
    }
    else
    {
      v62 = -22;
    }
    v26 = (unsigned __int8 *)_kmalloc_cache_noprof(sched_clock, 257, 8);
    if ( !v26 )
    {
      ipc_log_string(*(_QWORD *)(a1 + 2416), "%s: rx no memory\n", "geni_i3c_perform_daa");
      v34 = *(_QWORD *)(a1 - 104);
      if ( v34 )
        dev_err(v34, "%s: rx no memory\n", "geni_i3c_perform_daa");
      else
        printk(&unk_125ED, "geni_i3c_perform_daa", v32, v33);
      if ( !*(_QWORD *)(a1 - 104) )
        goto LABEL_22;
LABEL_21:
      i3c_trace_log();
      goto LABEL_22;
    }
    v63 = v13;
    v27 = (_QWORD *)_kmalloc_cache_noprof(sched_clock, 257, 8);
    if ( !v27 )
    {
      kfree(v26);
      ipc_log_string(*(_QWORD *)(a1 + 2416), "%s: tx no memory\n", "geni_i3c_perform_daa");
      v30 = *(_QWORD *)(a1 - 104);
      if ( v30 )
        dev_err(v30, "%s: tx no memory\n", "geni_i3c_perform_daa");
      else
        printk(&unk_149C2, "geni_i3c_perform_daa", v28, v29);
      v4 = v61;
      if ( !*(_QWORD *)(a1 - 104) )
        goto LABEL_22;
      goto LABEL_21;
    }
    do
    {
      v35 = *(_QWORD *)(a1 + 2416);
      v68 = 0;
      v67 = 1u;
      ipc_log_string(v35, "i3c entdaa read\n");
      if ( *(_QWORD *)(a1 - 104) )
        i3c_trace_log();
      *(_QWORD *)v26 = 0;
      *v27 = 0;
      *(_QWORD *)((char *)&v67 + 4) = 0x300010400000002LL;
      if ( (unsigned int)i3c_geni_execute_read_command(v8, &v67, v26, 8) )
        break;
      v36 = *v26;
      v37 = v26[1];
      v38 = (__int64 *)(a1 + 2176);
      v39 = v37 | ((_DWORD)v36 << 8);
      v40 = (v36 << 40)
          | (v37 << 32)
          | ((unsigned __int64)v26[2] << 24)
          | ((unsigned __int64)v26[3] << 16)
          | ((unsigned __int64)v26[4] << 8);
      v41 = v26[5];
      v42 = v40 | v41;
      while ( 1 )
      {
        v38 = (__int64 *)*v38;
        if ( v38 == (__int64 *)(a1 + 2176) )
          break;
        if ( v42 == v38[3] )
        {
          ipc_log_string(*(_QWORD *)(a1 + 2416), "PID %llu matched with boardinfo\n", v40 | v41);
          if ( *(_QWORD *)(a1 - 104) )
            i3c_trace_log();
          break;
        }
      }
      if ( !v38 )
      {
        ipc_log_string(*(_QWORD *)(a1 + 2416), "Invalid i3cboardinfo\n");
        if ( !*(_QWORD *)(a1 - 104) )
          break;
LABEL_114:
        i3c_trace_log();
        break;
      }
      v43 = v8;
      if ( (unsigned int)*((unsigned __int8 *)v38 + 16) - 1 >= 0x7E )
        v44 = 0;
      else
        v44 = *((_BYTE *)v38 + 16);
      if ( v44 <= 8u )
        v45 = 8;
      else
        v45 = v44;
      free_addr = i3c_master_get_free_addr(a1, v45);
      if ( free_addr < 0 )
      {
        ipc_log_string(
          *(_QWORD *)(a1 + 2416),
          "error:%d during get_free_addr, pid:%llu, mid:0x%x\n",
          free_addr,
          v42,
          v39);
        v8 = v43;
        if ( !*(_QWORD *)(a1 - 104) )
          break;
        goto LABEL_114;
      }
      if ( free_addr == v44 )
      {
        ipc_log_string(
          *(_QWORD *)(a1 + 2416),
          "assign requested addr:0x%x for pid:%llu, mid:0x%x\n",
          free_addr,
          v42,
          v39);
        if ( *(_QWORD *)(a1 - 104) )
          i3c_trace_log();
        v47 = 0;
        v8 = v43;
        if ( *((_BYTE *)v38 + 16) )
          goto LABEL_89;
      }
      else if ( v44 )
      {
        v8 = v43;
        v51 = (__int64 *)(a1 + 2312);
        do
        {
          v51 = (__int64 *)*v51;
          if ( v51 == (__int64 *)(a1 + 2312) )
          {
            ipc_log_string(*(_QWORD *)(a1 + 2416), "new dev: assigning addr:0x%x for pid:%llu\n", free_addr, v42);
            if ( !*(_QWORD *)(a1 - 104) )
              goto LABEL_109;
            goto LABEL_108;
          }
        }
        while ( v51[4] != v42 );
        LOBYTE(free_addr) = *((_BYTE *)v51 + 43);
        ipc_log_string(
          *(_QWORD *)(a1 + 2416),
          "assigning requested addr:0x%x for pid:%llu\n",
          (unsigned __int8)free_addr,
          v42);
        if ( *(_QWORD *)(a1 - 104) )
          i3c_trace_log();
        v47 = 1;
        if ( *((_BYTE *)v38 + 16) )
          goto LABEL_89;
      }
      else
      {
        ipc_log_string(*(_QWORD *)(a1 + 2416), "assigning addr:0x%x for pid:%llu\n", free_addr, v42);
        v8 = v43;
        if ( *(_QWORD *)(a1 - 104) )
LABEL_108:
          i3c_trace_log();
LABEL_109:
        v47 = 0;
        if ( *((_BYTE *)v38 + 16) )
          goto LABEL_89;
      }
      *((_BYTE *)v38 + 16) = free_addr;
LABEL_89:
      if ( (free_addr & 0x80u) != 0 )
        v47 = 1;
      if ( (v47 & 1) == 0 )
        *(_QWORD *)(a1 + 21176 + 8LL * ((unsigned __int8)free_addr >> 6)) |= 1LL << free_addr;
      *(_BYTE *)v27 = 2 * free_addr;
      _sw_hweight8(free_addr & 0x7F);
      v48 = free_addr & 1;
      if ( (_BYTE)free_addr )
      {
        v49 = (unsigned __int8)free_addr;
        do
        {
          v50 = v49 > 1;
          v48 ^= (v49 >> 1) & 1;
          v49 >>= 1;
        }
        while ( v50 );
      }
      *(_BYTE *)v27 = (v48 | (2 * free_addr)) ^ 1;
      *(_QWORD *)((char *)&v67 + 4) = 0x500000400000001LL;
    }
    while ( !(unsigned int)i3c_geni_execute_write_command(v8, &v67, v27, 1) );
    kfree(v27);
    v52 = kfree(v26);
    v53 = *(_QWORD *)(a1 + 2424);
    v4 = v61;
    v13 = v63;
    if ( v53 && v62 && *(_DWORD *)(a1 + 2432) )
    {
      v54 = sched_clock(v52);
      ipc_log_string(v53, "%s:took %llu nsec(%llu usec)\n", "geni_i3c_perform_daa", v54 - v62, (v54 - v62) / 0x3E8);
    }
LABEL_22:
    v12 = *((_DWORD *)v4 + 1);
    if ( ++v13 < v12 )
      continue;
    break;
  }
  v11 = 0;
LABEL_121:
  v2 = v60;
LABEL_122:
  v55 = *(_QWORD *)(a1 + 2416);
  *(_DWORD *)(v2 + 692) = 0;
  ipc_log_string(v55, "i3c ccc: txn ret:%d\n", v11);
  if ( *(_QWORD *)(a1 - 104) )
    i3c_trace_log();
  if ( *(_BYTE *)(v2 + 1058) == 1 && *(_BYTE *)(v2 + 1049) == 1 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 2416), "%s: client controls the PM, return\n", "i3c_geni_runtime_put_mutex_unlock");
    if ( *(_QWORD *)(a1 - 104) )
      i3c_trace_log();
  }
  else
  {
    v56 = *(_QWORD *)(a1 - 104);
    *(_QWORD *)(v56 + 520) = ktime_get_mono_fast_ns();
    _pm_runtime_suspend(*(_QWORD *)(a1 - 104), 13);
  }
  mutex_unlock(a1 + 2504);
  v57 = *(_QWORD *)(a1 + 2424);
  if ( !v57 )
    goto LABEL_138;
  result = v11;
  if ( v7 && *(_DWORD *)(a1 + 2432) )
  {
    v58 = sched_clock(v11);
    ipc_log_string(v57, "%s:took %llu nsec(%llu usec)\n", "geni_i3c_master_send_ccc_cmd", v58 - v7, (v58 - v7) / 0x3E8);
    goto LABEL_138;
  }
LABEL_139:
  _ReadStatusReg(SP_EL0);
  return result;
}
