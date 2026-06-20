__int64 __fastcall ipa3_sys_setup(__int64 a1, _QWORD *a2, unsigned int *a3, unsigned int *a4, char a5)
{
  unsigned int v8; // w3
  unsigned int ep_mapping; // w0
  unsigned int v12; // w20
  __int64 v13; // x21
  __int64 v14; // x9
  unsigned int v15; // w0
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 result; // x0
  __int64 v25; // x8
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x8
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x8
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x8
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x8
  __int64 v38; // x0
  __int64 v39; // x0
  unsigned int v40; // w21
  __int64 v41; // x8
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x8
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x8
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x8
  __int64 v51; // x0
  __int64 v52; // x0
  __int64 v53; // x8
  __int64 v54; // x0
  __int64 v55; // x0
  __int64 v56; // x8
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x8
  __int64 v60; // x0
  __int64 v61; // x0

  _ReadStatusReg(SP_EL0);
  if ( !a1 || !a4 )
  {
    printk(&unk_3C3D23, "ipa3_sys_setup");
    v25 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_56;
    v26 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v26 )
    {
      ipc_log_string(v26, "ipa %s:%d NULL args\n", "ipa3_sys_setup", 6287);
      v25 = ipa3_ctx;
    }
    v27 = *(_QWORD *)(v25 + 34160);
    if ( !v27 )
      goto LABEL_56;
    ipc_log_string(v27, "ipa %s:%d NULL args\n", "ipa3_sys_setup", 6287);
    goto LABEL_44;
  }
  if ( !a2 || !a3 )
  {
    printk(&unk_3C3D23, "ipa3_sys_setup");
    v28 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_56;
    v29 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v29 )
    {
      ipc_log_string(v29, "ipa %s:%d NULL args\n", "ipa3_sys_setup", 6292);
      v28 = ipa3_ctx;
    }
    v30 = *(_QWORD *)(v28 + 34160);
    if ( !v30 )
      goto LABEL_56;
    ipc_log_string(v30, "ipa %s:%d NULL args\n", "ipa3_sys_setup", 6292);
LABEL_44:
    result = 4294967274LL;
    goto LABEL_108;
  }
  v8 = *(_DWORD *)(a1 + 192);
  if ( v8 >= 0x86 )
  {
    printk(&unk_3E0D1F, "ipa3_sys_setup");
    v31 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v32 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v32 )
      {
        ipc_log_string(v32, "ipa %s:%d bad parm client:%d\n", "ipa3_sys_setup", 6296, *(_DWORD *)(a1 + 192));
        v31 = ipa3_ctx;
      }
      v33 = *(_QWORD *)(v31 + 34160);
      if ( v33 )
      {
        ipc_log_string(v33, "ipa %s:%d bad parm client:%d\n", "ipa3_sys_setup", 6296, *(unsigned int *)(a1 + 192));
LABEL_55:
        result = 4294967274LL;
        goto LABEL_108;
      }
    }
LABEL_56:
    result = 4294967274LL;
    goto LABEL_108;
  }
  ep_mapping = ipa_get_ep_mapping(v8);
  if ( ep_mapping == -1 )
  {
    printk(&unk_3F7E13, "ipa3_sys_setup");
    v34 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v35 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v35 )
      {
        ipc_log_string(v35, "ipa %s:%d Invalid client :%d\n", "ipa3_sys_setup", 6302, *(_DWORD *)(a1 + 192));
        v34 = ipa3_ctx;
      }
      v36 = *(_QWORD *)(v34 + 34160);
      if ( v36 )
      {
        ipc_log_string(v36, "ipa %s:%d Invalid client :%d\n", "ipa3_sys_setup", 6302, *(unsigned int *)(a1 + 192));
        goto LABEL_55;
      }
    }
    goto LABEL_56;
  }
  v12 = ep_mapping;
  if ( ep_mapping >= 0x25 )
    goto LABEL_109;
  v13 = ipa3_ctx + 480LL * (int)ep_mapping + 168;
  ipa3_inc_client_enable_clks();
  if ( *(_DWORD *)v13 == 1 )
  {
    if ( *(_DWORD *)(a1 + 192) == 34 )
    {
      if ( (unsigned int)ipa3_cfg_ep_hdr(v12, a1 + 12) )
      {
        printk(&unk_3C3D58, "ipa3_sys_setup");
        v53 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v54 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v54 )
          {
            ipc_log_string(v54, "ipa %s:%d fail to configure hdr prop of EP %d\n", "ipa3_sys_setup", 6317, v12);
            v53 = ipa3_ctx;
          }
          v55 = *(_QWORD *)(v53 + 34160);
          if ( v55 )
            ipc_log_string(v55, "ipa %s:%d fail to configure hdr prop of EP %d\n", "ipa3_sys_setup", 6317, v12);
        }
      }
      else if ( (unsigned int)ipa3_cfg_ep_hdr_ext(v12, a1 + 48) )
      {
        printk(&unk_3C3D89, "ipa3_sys_setup");
        v56 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v57 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v57 )
          {
            ipc_log_string(v57, "ipa %s:%d fail config hdr_ext prop of EP %d\n", "ipa3_sys_setup", 6324, v12);
            v56 = ipa3_ctx;
          }
          v58 = *(_QWORD *)(v56 + 34160);
          if ( v58 )
            ipc_log_string(v58, "ipa %s:%d fail config hdr_ext prop of EP %d\n", "ipa3_sys_setup", 6324, v12);
        }
      }
      else
      {
        if ( !(unsigned int)ipa3_cfg_ep_cfg(v12, a1 + 148) )
        {
          printk(&unk_3CF7E1, "ipa3_sys_setup");
          v37 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v38 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v38 )
            {
              ipc_log_string(
                v38,
                "ipa %s:%d client %d (ep: %d) overlay ok sys=%pK\n",
                "ipa3_sys_setup",
                6336,
                *(_DWORD *)(a1 + 192),
                v12,
                *(const void **)(v13 + 472));
              v37 = ipa3_ctx;
            }
            v39 = *(_QWORD *)(v37 + 34160);
            if ( v39 )
              ipc_log_string(
                v39,
                "ipa %s:%d client %d (ep: %d) overlay ok sys=%pK\n",
                "ipa3_sys_setup",
                6336,
                *(_DWORD *)(a1 + 192),
                v12,
                *(const void **)(v13 + 472));
          }
          *(_QWORD *)(v13 + 376) = *(_QWORD *)(a1 + 208);
          *(_QWORD *)(v13 + 368) = *(_QWORD *)(a1 + 200);
          *a4 = v12;
          if ( (*(_BYTE *)(v13 + 405) & 1) == 0 )
          {
            ipa3_dec_client_disable_clks();
            result = 0;
            goto LABEL_108;
          }
          goto LABEL_33;
        }
        printk(&unk_3E6300, "ipa3_sys_setup");
        v59 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v60 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v60 )
          {
            ipc_log_string(v60, "ipa %s:%d fail to configure cfg prop of EP %d\n", "ipa3_sys_setup", 6331, v12);
            v59 = ipa3_ctx;
          }
          v61 = *(_QWORD *)(v59 + 34160);
          if ( v61 )
            ipc_log_string(v61, "ipa %s:%d fail to configure cfg prop of EP %d\n", "ipa3_sys_setup", 6331, v12);
        }
      }
      v40 = -14;
    }
    else
    {
      printk(&unk_3D2819, "ipa3_sys_setup");
      v44 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v45 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v45 )
        {
          ipc_log_string(v45, "ipa %s:%d EP %d already allocated\n", "ipa3_sys_setup", 6311, v12);
          v44 = ipa3_ctx;
        }
        v46 = *(_QWORD *)(v44 + 34160);
        if ( v46 )
          ipc_log_string(v46, "ipa %s:%d EP %d already allocated\n", "ipa3_sys_setup", 6311, v12);
      }
      v40 = -22;
    }
LABEL_107:
    ipa3_dec_client_disable_clks();
    result = v40;
    goto LABEL_108;
  }
  memset((void *)v13, 0, 0x1D8u);
  *(_DWORD *)v13 = 1;
  *(_DWORD *)(v13 + 4) = *(_DWORD *)(a1 + 192);
  *(_QWORD *)(v13 + 376) = *(_QWORD *)(a1 + 208);
  v14 = *(_QWORD *)(a1 + 200);
  *(_BYTE *)(v13 + 405) = 1;
  *(_QWORD *)(v13 + 368) = v14;
  if ( (a5 & 1) != 0 )
  {
    *(_BYTE *)(v13 + 352) = 1;
    *(_BYTE *)(v13 + 353) = v12;
  }
  v15 = ipa3_enable_data_path(v12);
  if ( v15 )
  {
    v40 = v15;
    printk(&unk_3B48C2, "ipa3_sys_setup");
    v41 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v42 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v42 )
      {
        ipc_log_string(v42, "ipa %s:%d enable data path failed res=%d clnt=%d.\n", "ipa3_sys_setup", 6362, v40, v12);
        v41 = ipa3_ctx;
      }
      v43 = *(_QWORD *)(v41 + 34160);
      if ( v43 )
        ipc_log_string(v43, "ipa %s:%d enable data path failed res=%d clnt=%d.\n", "ipa3_sys_setup", 6362, v40, v12);
    }
    goto LABEL_107;
  }
  if ( (*(_BYTE *)(v13 + 404) & 1) != 0 )
  {
    v16 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v17 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v17 )
      {
        ipc_log_string(v17, "ipa %s:%d skipping ep configuration\n", "ipa3_sys_setup", 6377);
        v16 = ipa3_ctx;
      }
      v18 = *(_QWORD *)(v16 + 34160);
      if ( v18 )
        ipc_log_string(v18, "ipa %s:%d skipping ep configuration\n", "ipa3_sys_setup", 6377);
    }
    goto LABEL_25;
  }
  if ( (unsigned int)ipa3_cfg_ep(v12, a1) )
  {
    printk(&unk_3D5322, "ipa3_sys_setup");
    v47 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v48 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v48 )
      {
        ipc_log_string(v48, "ipa %s:%d fail to configure EP.\n", "ipa3_sys_setup", 6368);
        v47 = ipa3_ctx;
      }
      v49 = *(_QWORD *)(v47 + 34160);
      if ( v49 )
      {
        ipc_log_string(v49, "ipa %s:%d fail to configure EP.\n", "ipa3_sys_setup", 6368);
LABEL_89:
        v40 = 0;
        goto LABEL_107;
      }
    }
LABEL_90:
    v40 = 0;
    goto LABEL_107;
  }
  if ( (unsigned int)ipa3_cfg_ep_status(v12, v13 + 352) )
  {
    printk(&unk_3A6426, "ipa3_sys_setup");
    v50 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v51 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v51 )
      {
        ipc_log_string(v51, "ipa %s:%d fail to configure status of EP.\n", "ipa3_sys_setup", 6372);
        v50 = ipa3_ctx;
      }
      v52 = *(_QWORD *)(v50 + 34160);
      if ( v52 )
      {
        ipc_log_string(v52, "ipa %s:%d fail to configure status of EP.\n", "ipa3_sys_setup", 6372);
        goto LABEL_89;
      }
    }
    goto LABEL_90;
  }
  v19 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v20 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v20 )
    {
      ipc_log_string(v20, "ipa %s:%d ep configuration successful\n", "ipa3_sys_setup", 6375);
      v19 = ipa3_ctx;
    }
    v21 = *(_QWORD *)(v19 + 34160);
    if ( v21 )
      ipc_log_string(v21, "ipa %s:%d ep configuration successful\n", "ipa3_sys_setup", 6375);
  }
LABEL_25:
  *a4 = v12;
  *a3 = v12;
  *a2 = *(_QWORD *)(ipa3_ctx + 43296);
  if ( (*(_BYTE *)(v13 + 405) & 1) == 0 )
    ipa3_dec_client_disable_clks();
  if ( v12 == 36 )
LABEL_109:
    __break(0x5512u);
  *(_BYTE *)(ipa3_ctx + (int)v12 + 17448) = *(_BYTE *)(v13 + 404);
  v22 = ipa3_ctx;
  if ( !ipa3_ctx )
  {
LABEL_33:
    result = 0;
    goto LABEL_108;
  }
  v23 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v23 )
  {
    ipc_log_string(
      v23,
      "ipa %s:%d client %d (ep: %d) connected sys=%pK\n",
      "ipa3_sys_setup",
      6390,
      *(_DWORD *)(a1 + 192),
      v12,
      *(const void **)(v13 + 472));
    v22 = ipa3_ctx;
  }
  result = *(_QWORD *)(v22 + 34160);
  if ( result )
  {
    ipc_log_string(
      result,
      "ipa %s:%d client %d (ep: %d) connected sys=%pK\n",
      "ipa3_sys_setup",
      6390,
      *(_DWORD *)(a1 + 192),
      v12,
      *(const void **)(v13 + 472));
    goto LABEL_33;
  }
LABEL_108:
  _ReadStatusReg(SP_EL0);
  return result;
}
