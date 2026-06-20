void *__fastcall _dsp_cvp_pd_init(__int64 a1)
{
  char **v2; // x25
  unsigned int v3; // w21
  __int64 *fastrpc_node_with_handle; // x0
  int v5; // w8
  __int64 *v6; // x0
  __int64 *v7; // x20
  __int64 v8; // x0
  int v9; // w8
  unsigned __int64 v10; // x8
  __int64 v11; // x1
  __int64 v12; // x2
  const char *v13; // x3
  void *v14; // x0
  void *result; // x0
  __int64 v16; // x3
  __int64 v17; // x20
  int v18; // w8
  int *v19; // x4
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x8
  __int64 pid; // x0
  int v23; // w8
  unsigned __int64 v24; // x8
  __int64 *v25; // x20
  unsigned __int64 v26; // x8
  unsigned __int64 v27; // x8
  char v28; // w9
  __int64 *v29; // x1
  char **v30; // x24
  __int64 v31; // x3
  int v32; // w22
  int v33; // w8
  int v34; // w28
  __int64 *v35; // x8
  __int64 *v36; // x9
  unsigned __int64 v37; // x8
  __int64 v38; // x1
  __int64 v39; // x2
  void *v40; // x0
  unsigned __int64 v41; // x8
  __int64 **v42; // x10
  unsigned int v43; // w8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v45; // x8
  unsigned int v52; // w10
  unsigned __int64 v53; // x8
  unsigned int v56; // w10
  unsigned int v59; // w9
  unsigned int v62; // w10
  unsigned int v65; // w10
  unsigned int v68; // w10
  unsigned int v69; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v70; // [xsp+8h] [xbp-8h]

  v2 = off_6C000;
  v70 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_DWORD *)(a1 + 4) = 0;
  v3 = (unsigned int)off_6C7E0;
  if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
    printk(&unk_89930, "dsp", "eva_fastrpc_driver_register", (unsigned int)off_6C7E0);
  fastrpc_node_with_handle = cvp_get_fastrpc_node_with_handle(v3);
  v5 = (msm_cvp_debug_out == 0) & (BYTE1(msm_cvp_debug) >> 3);
  if ( fastrpc_node_with_handle )
  {
    if ( v5 )
    {
      v25 = fastrpc_node_with_handle;
      printk(&unk_9286C, "dsp", "eva_fastrpc_driver_register", fastrpc_node_with_handle);
      fastrpc_node_with_handle = v25;
    }
    if ( *((int *)fastrpc_node_with_handle + 7) >= 1 )
    {
      _X8 = (unsigned int *)fastrpc_node_with_handle + 7;
      __asm { PRFM            #0x11, [X8] }
      do
        v52 = __ldxr(_X8);
      while ( __stxr(v52 - 1, _X8) );
    }
    goto LABEL_9;
  }
  if ( v5 )
    printk(&unk_87C9F, "dsp", "eva_fastrpc_driver_register", v3);
  result = (void *)_kmalloc_cache_noprof(_init_swait_queue_head, 3520, 6528);
  v17 = (__int64)result;
  if ( !result )
  {
    if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
      result = (void *)printk(&unk_82B16, "dsp", "eva_fastrpc_driver_register", v16);
    goto LABEL_118;
  }
  memset(result, 0, 0x1980u);
  *(_DWORD *)(v17 + 16) = v3;
  memcpy((void *)(v17 + 32), &cvp_fastrpc_client, 0xE0u);
  *(_DWORD *)(v17 + 232) = v3;
  mutex_lock(&unk_6C630);
  if ( dword_6CF88 == 1 )
  {
    v18 = 0;
    v19 = &dword_6CF88;
    goto LABEL_61;
  }
  v19 = &dword_6CF9C;
  v18 = dword_6CF9C;
  if ( dword_6CF9C != 1 )
  {
    v19 = &dword_6CFB0;
    if ( dword_6CFB0 == 1 )
    {
      v18 = 2;
      goto LABEL_61;
    }
    v19 = &dword_6CFC4;
    if ( dword_6CFC4 == 1 )
    {
      v18 = 3;
      goto LABEL_61;
    }
    v19 = &dword_6CFD8;
    if ( dword_6CFD8 == 1 )
    {
      v18 = 4;
      goto LABEL_61;
    }
    v19 = &dword_6CFEC;
    if ( dword_6CFEC == 1 )
    {
      v18 = 5;
      goto LABEL_61;
    }
    v19 = &dword_6D000;
    if ( dword_6D000 == 1 )
    {
      v18 = 6;
      goto LABEL_61;
    }
    v19 = &dword_6D014;
    if ( dword_6D014 == 1 )
    {
      v18 = 7;
      goto LABEL_61;
    }
    mutex_unlock(&unk_6C630);
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_8D5DC, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    }
LABEL_106:
    result = (void *)kfree(v17);
LABEL_118:
    if ( (msm_cvp_debug & 1) != 0 && !*((_DWORD *)v2 + 366) )
    {
      v53 = _ReadStatusReg(SP_EL0);
      result = (void *)printk(&unk_9067B, *(unsigned int *)(v53 + 1800), *(unsigned int *)(v53 + 1804), &unk_8E7CE);
    }
    goto LABEL_53;
  }
LABEL_61:
  v28 = BYTE1(msm_cvp_debug);
  *(_DWORD *)(v17 + 24) = v18;
  *v19 = 2;
  *(_QWORD *)(v17 + 48) = v19 + 1;
  if ( (v28 & 8) != 0 && !msm_cvp_debug_out )
    printk(&unk_8ADDE, "dsp", "eva_fastrpc_driver_get_name", *(unsigned int *)(v17 + 232));
  mutex_unlock(&unk_6C630);
  *(_DWORD *)(v17 + 264) = 0;
  _init_swait_queue_head(v17 + 272, "&x->wait", &init_completion___key_1);
  mutex_lock(&unk_6CF58);
  v29 = (__int64 *)qword_6CF50;
  if ( (__int64 *)v17 == &qword_6CF48 || qword_6CF50 == v17 || *(__int64 **)qword_6CF50 != &qword_6CF48 )
    goto LABEL_112;
  v30 = off_6C000;
  qword_6CF50 = v17;
  *(_QWORD *)v17 = &qword_6CF48;
  *(_QWORD *)(v17 + 8) = v29;
  *v29 = v17;
  while ( 1 )
  {
    _mutex_init(v17 + 312, "&mlist->lock", &INIT_MSM_CVP_LIST___key_0);
    *(_QWORD *)(v17 + 296) = v17 + 296;
    *(_QWORD *)(v17 + 304) = v17 + 296;
    _mutex_init(v17 + 376, "&mlist->lock", &INIT_MSM_CVP_LIST___key_0);
    *(_QWORD *)(v17 + 360) = v17 + 360;
    *(_QWORD *)(v17 + 368) = v17 + 360;
    v2 = v30;
    if ( (msm_cvp_debug & 0x800) != 0 && !*((_DWORD *)v30 + 366) )
      printk(&unk_95E4E, "dsp", v17, v31);
    _X8 = (unsigned int *)(v17 + 28);
    __asm { PRFM            #0x11, [X8] }
    do
      v59 = __ldxr(_X8);
    while ( __stxr(v59 + 1, _X8) );
    mutex_unlock(&unk_6CF58);
    v32 = fastrpc_driver_register(v17 + 32);
    if ( !v32 )
      break;
    if ( (msm_cvp_debug & 1) == 0 || *((_DWORD *)v30 + 366) )
      goto LABEL_74;
    v41 = _ReadStatusReg(SP_EL0);
    v38 = *(unsigned int *)(v41 + 1800);
    v39 = *(unsigned int *)(v41 + 1804);
    v40 = &unk_96930;
LABEL_98:
    printk(v40, v38, v39, &unk_8E7CE);
LABEL_74:
    if ( *(int *)(v17 + 28) >= 1 )
    {
      _X8 = (unsigned int *)(v17 + 28);
      __asm { PRFM            #0x11, [X8] }
      do
        v62 = __ldxr(_X8);
      while ( __stxr(v62 - 1, _X8) );
    }
    v33 = 10;
    while ( 2 )
    {
      v34 = v33;
      mutex_lock(&unk_6CF58);
      v35 = (__int64 *)qword_6CF48;
      do
      {
        if ( v35 == &qword_6CF48 )
        {
          result = (void *)mutex_unlock(&unk_6CF58);
LABEL_87:
          if ( (msm_cvp_debug & 0x800) != 0 && !*((_DWORD *)v30 + 366) )
            result = (void *)printk(&unk_8AD9D, "dsp", "eva_fastrpc_driver_register", v17);
          goto LABEL_118;
        }
        v36 = v35;
        v35 = (__int64 *)*v35;
      }
      while ( v36 != (__int64 *)v17 );
      if ( *((_DWORD *)v36 + 7) )
      {
        mutex_unlock(&unk_6CF58);
        result = (void *)usleep_range_state(5000, 10000, 2);
        v33 = v34 - 1;
        if ( v34 )
          continue;
        if ( (msm_cvp_debug & 1) != 0 && !*((_DWORD *)v30 + 366) )
        {
          v45 = _ReadStatusReg(SP_EL0);
          result = (void *)printk(&unk_9495B, *(unsigned int *)(v45 + 1800), *(unsigned int *)(v45 + 1804), &unk_8E7CE);
        }
        __break(0x800u);
        goto LABEL_87;
      }
      break;
    }
    v42 = (__int64 **)v36[1];
    if ( *v42 == (__int64 *)v17 && v35[1] == v17 )
    {
      v35[1] = (__int64)v42;
      *v42 = v35;
    }
    else
    {
      _list_del_entry_valid_or_report(v36);
    }
    *v36 = 0xDEAD000000000100LL;
    v36[1] = 0xDEAD000000000122LL;
    mutex_unlock(&unk_6CF58);
    if ( !v32 )
      fastrpc_driver_unregister(v17 + 32);
    mutex_lock(&unk_6C630);
    v43 = *(_DWORD *)(v17 + 24);
    if ( v43 < 8 )
    {
      *((_DWORD *)&gfa_cv + 5 * v43 + 622) = 1;
      mutex_unlock(&unk_6C630);
      goto LABEL_106;
    }
    __break(0x5512u);
LABEL_112:
    v30 = v2;
    _list_add_valid_or_report(v17, v29, &qword_6CF48);
  }
  if ( !wait_for_completion_timeout(v17 + 264, 150) )
  {
    if ( (msm_cvp_debug & 1) == 0 || *((_DWORD *)v30 + 366) )
      goto LABEL_74;
    v37 = _ReadStatusReg(SP_EL0);
    v38 = *(unsigned int *)(v37 + 1800);
    v39 = *(unsigned int *)(v37 + 1804);
    v40 = &unk_9696B;
    goto LABEL_98;
  }
  if ( *(int *)(v17 + 28) >= 1 )
  {
    _X8 = (unsigned int *)(v17 + 28);
    __asm { PRFM            #0x11, [X8] }
    do
      v65 = __ldxr(_X8);
    while ( __stxr(v65 - 1, _X8) );
  }
LABEL_9:
  v6 = cvp_get_fastrpc_node_with_handle((unsigned int)off_6C7E0);
  if ( !v6 )
  {
    if ( (msm_cvp_debug & 2) != 0 && !*((_DWORD *)v2 + 366) )
    {
      v20 = _ReadStatusReg(SP_EL0);
      printk(&unk_84897, *(unsigned int *)(v20 + 1800), *(unsigned int *)(v20 + 1804), "warn");
    }
    goto LABEL_52;
  }
  v7 = v6;
  v8 = v6[32];
  if ( !v8 )
  {
    if ( (msm_cvp_debug & 2) == 0 || *((_DWORD *)v2 + 366) )
      goto LABEL_50;
    v21 = _ReadStatusReg(SP_EL0);
    v11 = *(unsigned int *)(v21 + 1800);
    v12 = *(unsigned int *)(v21 + 1804);
    v14 = &unk_973A4;
    v13 = "warn";
    goto LABEL_28;
  }
  v69 = 0;
  if ( (unsigned int)fastrpc_driver_invoke(v8, 3, &v69) )
  {
    v9 = *((_DWORD *)v2 + 366);
    if ( (msm_cvp_debug & 1) == 0 || v9 )
    {
      if ( (msm_cvp_debug & 1) != 0 )
        goto LABEL_15;
      goto LABEL_50;
    }
    v27 = _ReadStatusReg(SP_EL0);
    printk(&unk_8CB7C, *(unsigned int *)(v27 + 1800), *(unsigned int *)(v27 + 1804), &unk_8E7CE);
    v9 = *((_DWORD *)v2 + 366);
    if ( (msm_cvp_debug & 1) == 0 )
      goto LABEL_50;
LABEL_15:
    if ( !v9 )
    {
      v10 = _ReadStatusReg(SP_EL0);
      v11 = *(unsigned int *)(v10 + 1800);
      v12 = *(unsigned int *)(v10 + 1804);
      v13 = (const char *)&unk_8E7CE;
      v14 = &unk_85BF5;
LABEL_28:
      printk(v14, v11, v12, v13);
    }
LABEL_50:
    if ( *((int *)v7 + 7) >= 1 )
    {
      _X8 = (unsigned int *)v7 + 7;
      __asm { PRFM            #0x11, [X8] }
      do
        v56 = __ldxr(_X8);
      while ( __stxr(v56 - 1, _X8) );
    }
LABEL_52:
    result = (void *)((__int64 (__fastcall *)(_QWORD, _QWORD))eva_fastrpc_driver_unregister)((unsigned int)off_6C7E0, 0);
LABEL_53:
    *(_DWORD *)(a1 + 4) = -1;
  }
  else
  {
    pid = find_get_pid(v69);
    v23 = *((_DWORD *)v2 + 366);
    if ( !pid )
    {
      if ( (msm_cvp_debug & 2) == 0 || v23 )
        goto LABEL_50;
      v24 = _ReadStatusReg(SP_EL0);
      v11 = *(unsigned int *)(v24 + 1800);
      v12 = *(unsigned int *)(v24 + 1804);
      v14 = &unk_886A6;
      v13 = "warn";
      goto LABEL_28;
    }
    if ( (msm_cvp_debug & 0x800) != 0 && !v23 )
      printk(&unk_96838, "dsp", "__dsp_cvp_pd_init", pid);
    result = (void *)get_pid_task();
    if ( !result )
    {
      if ( (msm_cvp_debug & 2) != 0 && !*((_DWORD *)v2 + 366) )
      {
        v26 = _ReadStatusReg(SP_EL0);
        printk(&unk_91B32, *(unsigned int *)(v26 + 1800), *(unsigned int *)(v26 + 1804), "warn");
      }
      goto LABEL_50;
    }
    if ( *((int *)v7 + 7) >= 1 )
    {
      _X8 = (unsigned int *)v7 + 7;
      __asm { PRFM            #0x11, [X8] }
      do
        v68 = __ldxr(_X8);
      while ( __stxr(v68 - 1, _X8) );
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
