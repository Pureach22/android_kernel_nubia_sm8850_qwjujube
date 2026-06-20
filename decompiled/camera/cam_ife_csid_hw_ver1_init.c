__int64 __fastcall cam_ife_csid_hw_ver1_init(_DWORD *a1, const char *a2, char a3)
{
  const char *v4; // x22
  const char *v5; // x23
  unsigned __int64 v6; // x21
  __int64 v7; // x0
  __int64 v9; // x20
  char v10; // w8
  __int64 v11; // x8
  __int64 v12; // x8
  unsigned int inited; // w0
  __int64 v14; // x26
  _DWORD *v15; // x8
  __int64 v16; // x21
  __int64 v17; // x0
  const char *v18; // x21
  __int64 v19; // x0
  int v20; // w6
  unsigned int v21; // w19
  const char *v22; // x5
  __int64 v23; // x6
  __int64 v24; // x4
  __int64 v25; // x27
  __int64 v26; // x0
  __int64 v27; // x9
  const char *v28; // x5
  __int64 v29; // x6
  __int64 v30; // x4
  __int64 v31; // x27
  const char *v32; // x24
  __int64 v33; // x0
  __int64 v34; // x8
  unsigned int v35; // w0
  int v36; // w6
  unsigned int v37; // w19
  __int64 v38; // x10
  __int64 v39; // x9
  __int64 v40; // x8
  __int64 v41; // x0
  _QWORD *v42; // x1
  unsigned __int64 StatusReg; // x24
  __int64 v44; // x25
  __int64 v45; // x6
  const char *v46; // x5
  __int64 v47; // x4

  v4 = a2;
  if ( !a1 || !a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_hw_ver1_init",
      4752,
      "Invalid parameters intf: %pK hw_info: %pK",
      a1,
      a2);
    return 4294967274LL;
  }
  v5 = *((const char **)a1 + 14);
  LOBYTE(v6) = a3;
  if ( mem_trace_en == 1 )
    v7 = cam_mem_trace_alloc(28408, 0xCC0u, 0, "cam_ife_csid_hw_ver1_init", 0x1296u);
  else
    v7 = _kvmalloc_node_noprof(28408, 0, 3520, 0xFFFFFFFFLL);
  v9 = v7;
  if ( !v7 )
  {
LABEL_58:
    v45 = (unsigned int)a1[1];
    v46 = "Csid core %d hw allocation fails";
    v47 = 4762;
    goto LABEL_62;
  }
  while ( 1 )
  {
    *(_QWORD *)v9 = a1;
    *(_QWORD *)(v9 + 8) = v5;
    v10 = debug_mdl;
    *(_QWORD *)(v9 + 16) = v4;
    *((_QWORD *)v5 + 460) = v9;
    if ( (v10 & 8) != 0 && !debug_priority )
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v10 & 8,
        4,
        "cam_ife_csid_hw_ver1_init",
        4773,
        "type %d index %d",
        *a1,
        a1[1]);
    v11 = *(_QWORD *)(v9 + 8);
    *(_BYTE *)(v9 + 28312) = 0;
    *(_DWORD *)(v11 + 92) = 0;
    _mutex_init(*(_QWORD *)(v9 + 8), "&ife_csid_hw->hw_info->hw_mutex", &cam_ife_csid_hw_ver1_init___key);
    v4 = "&x->wait";
    *(_DWORD *)(*(_QWORD *)(v9 + 8) + 48LL) = 0;
    v12 = *(_QWORD *)(v9 + 8);
    *(_DWORD *)(v9 + 28396) = 0;
    *(_DWORD *)(v12 + 56) = 0;
    _init_swait_queue_head(v12 + 64, "&x->wait", &init_completion___key_4);
    *(_DWORD *)(v9 + 26504) = 0;
    _init_swait_queue_head(v9 + 26512, "&x->wait", &init_completion___key_4);
    *(_DWORD *)(v9 + 26536) = 0;
    _init_swait_queue_head(v9 + 26544, "&x->wait", &init_completion___key_4);
    *(_DWORD *)(v9 + 26568) = 0;
    _init_swait_queue_head(v9 + 26576, "&x->wait", &init_completion___key_4);
    *(_DWORD *)(v9 + 26600) = 0;
    _init_swait_queue_head(v9 + 26608, "&x->wait", &init_completion___key_4);
    *(_DWORD *)(v9 + 26632) = 0;
    _init_swait_queue_head(v9 + 26640, "&x->wait", &init_completion___key_4);
    *(_DWORD *)(v9 + 26664) = 0;
    _init_swait_queue_head(v9 + 26672, "&x->wait", &init_completion___key_4);
    *(_DWORD *)(v9 + 26696) = 0;
    _init_swait_queue_head(v9 + 26704, "&x->wait", &init_completion___key_4);
    *(_DWORD *)(v9 + 26728) = 0;
    _init_swait_queue_head(v9 + 26736, "&x->wait", &init_completion___key_4);
    *(_DWORD *)(v9 + 26760) = 0;
    _init_swait_queue_head(v9 + 26768, "&x->wait", &init_completion___key_4);
    *(_DWORD *)(v9 + 26792) = 0;
    _init_swait_queue_head(v9 + 26800, "&x->wait", &init_completion___key_4);
    *(_DWORD *)(v9 + 26824) = 0;
    _init_swait_queue_head(v9 + 26832, "&x->wait", &init_completion___key_4);
    *(_DWORD *)(v9 + 26856) = 0;
    _init_swait_queue_head(v9 + 26864, "&x->wait", &init_completion___key_4);
    *(_DWORD *)(v9 + 26888) = 0;
    _init_swait_queue_head(v9 + 26896, "&x->wait", &init_completion___key_4);
    *(_DWORD *)(v9 + 26920) = 0;
    _init_swait_queue_head(v9 + 26928, "&x->wait", &init_completion___key_4);
    *(_DWORD *)(v9 + 26952) = 0;
    _init_swait_queue_head(v9 + 26960, "&x->wait", &init_completion___key_4);
    *(_DWORD *)(v9 + 26984) = 0;
    _init_swait_queue_head(v9 + 26992, "&x->wait", &init_completion___key_4);
    inited = cam_ife_csid_init_soc_resources(*(_QWORD *)(v9 + 8) + 96LL, (__int64)&cam_ife_csid_irq, 0, v9, v6 & 1);
    if ( (inited & 0x80000000) != 0 )
    {
      v20 = a1[1];
      v21 = inited;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_hw_ver1_init",
        4789,
        "CSID:%d Failed to init_soc",
        v20);
      return v21;
    }
    if ( (((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD))cam_cpas_is_feature_supported)(0, 0, 0) & 1) != 0 )
      *(_BYTE *)(v9 + 28313) = 1;
    *(_QWORD *)(*(_QWORD *)v9 + 8LL) = cam_ife_csid_ver1_get_hw_caps;
    *(_QWORD *)(*(_QWORD *)v9 + 16LL) = cam_ife_csid_ver1_init_hw;
    *(_QWORD *)(*(_QWORD *)v9 + 24LL) = cam_ife_csid_ver1_deinit_hw;
    *(_QWORD *)(*(_QWORD *)v9 + 32LL) = cam_ife_csid_ver1_reset;
    *(_QWORD *)(*(_QWORD *)v9 + 40LL) = &cam_ife_csid_ver1_reserve;
    *(_QWORD *)(*(_QWORD *)v9 + 48LL) = cam_ife_csid_ver1_release;
    *(_QWORD *)(*(_QWORD *)v9 + 56LL) = cam_ife_csid_ver1_start;
    *(_QWORD *)(*(_QWORD *)v9 + 64LL) = cam_ife_csid_ver1_stop;
    *(_QWORD *)(*(_QWORD *)v9 + 72LL) = cam_ife_csid_ver1_read;
    *(_QWORD *)(*(_QWORD *)v9 + 80LL) = cam_ife_csid_ver1_write;
    *(_QWORD *)(*(_QWORD *)v9 + 88LL) = cam_ife_csid_ver1_process_cmd;
    v14 = **(_QWORD **)(v9 + 16);
    v15 = *(_DWORD **)(v14 + 96);
    if ( v15[39] )
    {
      v16 = *(_QWORD *)v9;
      if ( mem_trace_en == 1 )
      {
        v17 = cam_mem_trace_alloc(68, 0xCC0u, 0, "cam_ife_ver1_hw_alloc_res", 0x1222u);
        if ( !v17 )
          goto LABEL_24;
      }
      else
      {
        v17 = _kvmalloc_node_noprof(68, 0, 3520, 0xFFFFFFFFLL);
        if ( !v17 )
        {
LABEL_24:
          v22 = "CSID: %d IPP res init fail";
          v23 = *(unsigned int *)(*(_QWORD *)v9 + 4LL);
          v24 = 4677;
          goto LABEL_60;
        }
      }
      *(_QWORD *)(v9 + 872) = v17;
      *(_QWORD *)(v9 + 848) = 0x500000003LL;
      *(_DWORD *)(v9 + 856) = 1;
      *(_QWORD *)(v9 + 864) = v16;
      scnprintf(v9 + 976, 16, "IPP");
      v15 = *(_DWORD **)(v14 + 96);
    }
    if ( v15[40] )
      break;
LABEL_27:
    if ( v15[38] )
    {
      v25 = 0;
      v6 = 0;
      v5 = "RDI_%d";
      _ReadStatusReg(SP_EL0);
      while ( v6 != 13 )
      {
        v4 = *(const char **)v9;
        if ( mem_trace_en == 1 )
        {
          v26 = cam_mem_trace_alloc(68, 0xCC0u, 0, "cam_ife_ver1_hw_alloc_res", 0x1222u);
          if ( !v26 )
            goto LABEL_36;
        }
        else
        {
          v26 = _kvmalloc_node_noprof(68, 0, 3520, 0xFFFFFFFFLL);
          if ( !v26 )
          {
LABEL_36:
            v28 = "CSID: %d RDI[%d] res init fail";
            v29 = *(unsigned int *)(*(_QWORD *)v9 + 4LL);
            v30 = 4711;
LABEL_47:
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
              3,
              8,
              1,
              "cam_ife_csid_ver1_hw_init_path_res",
              v30,
              v28,
              v29,
              (unsigned int)v6);
            goto LABEL_61;
          }
        }
        v27 = v9 + v25;
        *(_QWORD *)(v27 + 104) = v4;
        *(_QWORD *)(v27 + 112) = v26;
        *(_DWORD *)(v9 + v25 + 88) = 3;
        *(_DWORD *)(v27 + 92) = v6;
        *(_DWORD *)(v27 + 96) = 1;
        scnprintf(v9 + v25 + 216, 16, "RDI_%d", v6);
        v15 = *(_DWORD **)(v14 + 96);
        ++v6;
        v25 += 152;
        if ( v6 >= (unsigned int)v15[38] )
          goto LABEL_37;
      }
    }
    else
    {
LABEL_37:
      if ( !v15[37] )
      {
LABEL_48:
        v35 = cam_tasklet_init((_QWORD *)(v9 + 24), v9, a1[1]);
        if ( v35 )
        {
          v36 = a1[1];
          v37 = v35;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_ife_csid_hw_ver1_init",
            4824,
            "CSID[%d] init tasklet failed",
            v36);
          ((void (__fastcall *)(__int64))cam_ife_csid_ver1_free_res)(v9);
          return v37;
        }
        else
        {
          v38 = 0;
          v39 = v9 + 1912;
          *(_QWORD *)(v9 + 1912) = v9 + 1912;
          *(_QWORD *)(v9 + 1920) = v9 + 1912;
          do
          {
            v40 = v9 + v38;
            v41 = v40 + 1928;
            *(_QWORD *)(v40 + 1928) = v40 + 1928;
            *(_QWORD *)(v40 + 1936) = v40 + 1928;
            v42 = *(_QWORD **)(v9 + 1920);
            if ( (_QWORD *)(v9 + v38 + 1928) == v42 || *v42 != v39 )
            {
              _list_add_valid_or_report(v41);
            }
            else
            {
              *(_QWORD *)(v9 + 1920) = v41;
              *(_QWORD *)(v40 + 1928) = v39;
              *(_QWORD *)(v40 + 1936) = v42;
              *v42 = v41;
            }
            v38 += 96;
          }
          while ( v38 != 24576 );
          *(_DWORD *)(v9 + 28332) = 0;
          *(_DWORD *)(v9 + 48) = 0;
          return 0;
        }
      }
      v31 = 0;
      v6 = 0;
      v4 = (_BYTE *)(&_ksymtab_cam_cci_dump_registers + 1);
      v5 = "UDI_%d";
      _ReadStatusReg(SP_EL0);
      while ( v6 != 6 )
      {
        v32 = *(const char **)v9;
        if ( mem_trace_en == 1 )
        {
          v33 = cam_mem_trace_alloc(68, 0xCC0u, 0, "cam_ife_ver1_hw_alloc_res", 0x1222u);
          if ( !v33 )
            goto LABEL_46;
        }
        else
        {
          v33 = _kvmalloc_node_noprof(68, 0, 3520, 0xFFFFFFFFLL);
          if ( !v33 )
          {
LABEL_46:
            v28 = "CSID: %d UDI[%d] res init fail";
            v29 = *(unsigned int *)(*(_QWORD *)v9 + 4LL);
            v30 = 4728;
            goto LABEL_47;
          }
        }
        v34 = v9 + v31;
        *(_QWORD *)(v34 + 1176) = v33;
        *(_DWORD *)(v34 + 1156) = v6 + 7;
        *(_DWORD *)(v9 + v31 + 1152) = 3;
        *(_DWORD *)(v34 + 1160) = 1;
        *(_QWORD *)(v34 + 1168) = v32;
        scnprintf(v9 + v31 + 1280, 16, "UDI_%d", v6++);
        v31 += 152;
        if ( v6 >= *(unsigned int *)(*(_QWORD *)(v14 + 96) + 148LL) )
          goto LABEL_48;
      }
    }
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v44 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_ife_csid_hw_ver1_init__alloc_tag;
    v9 = _kvmalloc_node_noprof(28408, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v44;
    if ( !v9 )
      goto LABEL_58;
  }
  v18 = *(const char **)v9;
  if ( mem_trace_en == 1 )
  {
    v19 = cam_mem_trace_alloc(68, 0xCC0u, 0, "cam_ife_ver1_hw_alloc_res", 0x1222u);
    if ( !v19 )
      goto LABEL_59;
    goto LABEL_26;
  }
  v19 = _kvmalloc_node_noprof(68, 0, 3520, 0xFFFFFFFFLL);
  if ( v19 )
  {
LABEL_26:
    *(_QWORD *)(v9 + 1024) = v19;
    *(_QWORD *)(v9 + 1000) = 0x600000003LL;
    *(_DWORD *)(v9 + 1008) = 1;
    *(_QWORD *)(v9 + 1016) = v18;
    scnprintf(v9 + 1128, 16, "PPP");
    v15 = *(_DWORD **)(v14 + 96);
    goto LABEL_27;
  }
LABEL_59:
  v22 = "CSID: %d PPP res init fail";
  v23 = *(unsigned int *)(*(_QWORD *)v9 + 4LL);
  v24 = 4693;
LABEL_60:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
    3,
    8,
    1,
    "cam_ife_csid_ver1_hw_init_path_res",
    v24,
    v22,
    v23);
LABEL_61:
  ((void (__fastcall *)(__int64))cam_ife_csid_ver1_free_res)(v9);
  v45 = (unsigned int)a1[1];
  v46 = "CSID[%d] Probe Init failed";
  v47 = 4816;
LABEL_62:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
    3,
    8,
    1,
    "cam_ife_csid_hw_ver1_init",
    v47,
    v46,
    v45);
  return 4294967284LL;
}
