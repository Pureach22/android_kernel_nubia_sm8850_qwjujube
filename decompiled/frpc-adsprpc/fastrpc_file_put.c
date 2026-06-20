unsigned int *__fastcall fastrpc_file_put(__int64 *a1, char a2)
{
  unsigned int *result; // x0
  unsigned int v4; // w8
  unsigned int v10; // w10
  __int64 v11; // x20
  __int64 v12; // x21
  __int64 v13; // x9
  __int64 *v14; // x21
  __int64 v15; // x8
  __int64 *v16; // x27
  __int64 *v17; // x28
  __int64 *v18; // x23
  __int64 **v19; // x8
  __int64 *v20; // x26
  __int64 v21; // x8
  _DWORD *v22; // x8
  __int64 v23; // x0
  __int64 **v24; // x22
  __int64 *v25; // x23
  __int64 v26; // x9
  int v27; // w0
  int v28; // w8
  __int64 v29; // x0
  int v30; // w22
  __int64 v31; // x0
  __int64 **v32; // x8
  __int64 v33; // x9
  __int64 *v34; // x10
  unsigned int *v35; // x22
  __int64 v36; // x21
  int v37; // w8
  __int64 v38; // x1
  _QWORD *i; // x9
  unsigned int v40; // w8
  unsigned int v41; // w21
  __int64 v42; // x22
  __int64 v43; // x21
  __int64 v44; // x21
  __int64 v45; // x0
  int v46; // w8
  int v47; // w8
  __int64 v48; // x21
  __int64 v49; // x0
  int v50; // w8
  int v51; // w8
  __int64 v52; // x21
  __int64 v53; // x0
  int v54; // w8
  int v55; // w8
  __int64 v56; // x21
  __int64 v57; // x19
  int v58; // w8
  int v60; // w8
  unsigned int v63; // w9
  __int64 v64; // x0
  int v65; // [xsp+Ch] [xbp-A4h] BYREF
  _QWORD v66[15]; // [xsp+10h] [xbp-A0h] BYREF
  _QWORD v67[5]; // [xsp+88h] [xbp-28h] BYREF

  result = (unsigned int *)(a1 + 83);
  v67[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a2 & 1) != 0 )
  {
    v4 = *result;
    if ( *result + 1 >= 2 )
    {
      if ( v4 != 1 )
      {
        while ( v4 != 1 )
        {
          __asm { PRFM            #0x11, [X0] }
          do
            v10 = __ldxr(result);
          while ( v10 == v4 && __stlxr(v4 - 1, result) );
          _ZF = v10 == v4;
          v4 = v10;
          if ( _ZF )
            goto LABEL_95;
        }
      }
      result = (unsigned int *)queue_work_on(32, system_wq, a1 + 84);
    }
    goto LABEL_95;
  }
  __asm { PRFM            #0x11, [X0] }
  do
    v60 = __ldxr(result);
  while ( __stlxr(v60 - 1, result) );
  if ( v60 != 1 )
  {
    if ( v60 <= 0 )
      result = (unsigned int *)refcount_warn_saturate();
    goto LABEL_95;
  }
  __dmb(9u);
  if ( !a1 )
  {
    v14 = (__int64 *)loc_FAF8;
    if ( !loc_FAF8 )
    {
LABEL_95:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    v11 = 0;
LABEL_85:
    fastrpc_free_user(v14);
    result = (unsigned int *)kfree(v14);
    if ( a1 )
    {
      v57 = raw_spin_lock_irqsave(v11 + 51600);
      v58 = *(_DWORD *)(v11 + 64180) - 1;
      *(_DWORD *)(v11 + 64180) = v58;
      if ( !v58 )
        _wake_up(v11 + 64216, 1, 1, 0);
      raw_spin_unlock_irqrestore(v11 + 51600, v57);
      result = (unsigned int *)fastrpc_channel_ctx_put(v11);
    }
    else
    {
      *(_QWORD *)(v11 + 64248) = 0;
    }
    goto LABEL_95;
  }
  v11 = a1[16];
  v12 = raw_spin_lock_irqsave(&g_frpc);
  v13 = raw_spin_lock_irqsave(v11 + 51600);
  if ( *(_DWORD *)(v11 + 64136) )
  {
    raw_spin_unlock_irqrestore(v11 + 51600, v13);
    raw_spin_unlock_irqrestore(&g_frpc, v12);
    wait_for_completion(v11 + 64184);
    v12 = raw_spin_lock_irqsave(&g_frpc);
    v13 = raw_spin_lock_irqsave(v11 + 51600);
  }
  else
  {
    ++*(_DWORD *)(v11 + 64180);
  }
  v15 = a1[26];
  if ( v15 )
  {
    *(_BYTE *)(v15 + 944) = 1;
    *(_QWORD *)(a1[26] + 936) = 0;
  }
  v16 = a1 + 12;
  v17 = (__int64 *)a1[12];
  *((_DWORD *)a1 + 157) = 3;
  if ( v17 != a1 + 12 )
  {
    v18 = v17;
    do
    {
      v20 = (__int64 *)*v18;
      v19 = (__int64 **)v18[1];
      if ( *v19 == v18 && (__int64 *)v20[1] == v18 )
      {
        v20[1] = (__int64)v19;
        *v19 = v20;
      }
      else
      {
        _list_del_entry_valid_or_report(v18);
      }
      v21 = v18[27];
      *v18 = 0xDEAD000000000100LL;
      v18[1] = 0xDEAD000000000122LL;
      if ( v21 )
      {
        raw_spin_unlock_irqrestore(v11 + 51600, v13);
        raw_spin_unlock_irqrestore(&g_frpc, v12);
        v22 = (_DWORD *)v18[27];
        v23 = a1[26];
        if ( *(v22 - 1) != -1638634471 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD))v22)(v23, 0);
        v12 = raw_spin_lock_irqsave(&g_frpc);
        v13 = raw_spin_lock_irqsave(v11 + 51600);
      }
      v18 = v20;
    }
    while ( v20 != v16 );
  }
  raw_spin_unlock_irqrestore(v11 + 51600, v13);
  raw_spin_unlock_irqrestore(&g_frpc, v12);
  raw_spin_lock(a1 + 40);
  v24 = (__int64 **)a1[14];
  if ( v24 != (__int64 **)(a1 + 14) )
  {
    do
    {
      v25 = *v24;
      raw_spin_unlock(a1 + 40);
      fastrpc_multidomain_ctx_cleanup(a1, 1, v24[9]);
      raw_spin_lock(a1 + 40);
      v24 = (__int64 **)v25;
    }
    while ( v25 != a1 + 14 );
  }
  raw_spin_unlock(a1 + 40);
  if ( v17 == v16 )
    kfree(a1[26]);
  v26 = a1[23];
  if ( v26 )
    *(_DWORD *)(v26 + 44) = 0;
  v65 = *((_DWORD *)a1 + 61);
  v67[0] = &v65;
  v67[1] = 4;
  v67[2] = 0xFFFFFFFFLL;
  v66[0] = 0x101000000000001LL;
  v66[1] = v67;
  memset(&v66[2], 0, 104);
  v27 = fastrpc_internal_invoke(a1, 2, v66);
  if ( v27 == -5 )
  {
    if ( !*(_DWORD *)(v11 + 64136) && (fastrpc_is_device_crashing(v11) & 1) != 0 )
    {
      printk(
        &unk_2605E,
        "fastrpc_user_obj_free",
        _ReadStatusReg(SP_EL0) + 2320,
        4294967291LL,
        *((unsigned int *)a1 + 62),
        *((unsigned int *)a1 + 61));
      wait_for_completion(v11 + 64264);
    }
    goto LABEL_44;
  }
  if ( v27 != -110 )
  {
LABEL_44:
    *((_DWORD *)a1 + 157) = 4;
    v28 = *((_DWORD *)a1 + 67);
    if ( v28 == 9 || v28 == 7 )
      fastrpc_sysfs_notify_pids(*(_QWORD *)(v11 + 24));
    v29 = raw_spin_lock_irqsave(v11 + 51600);
    v30 = *((unsigned __int8 *)a1 + 307);
    raw_spin_unlock_irqrestore(v11 + 51600, v29);
    if ( v30 == 1 )
      wait_for_completion(a1 + 59);
    v31 = raw_spin_lock_irqsave(v11 + 51600);
    v32 = (__int64 **)a1[1];
    v33 = v31;
    if ( *v32 == a1 && (v34 = (__int64 *)*a1, *(__int64 **)(*a1 + 8) == a1) )
    {
      v34[1] = (__int64)v32;
      *v32 = v34;
    }
    else
    {
      _list_del_entry_valid_or_report(a1);
    }
    *a1 = 0xDEAD000000000100LL;
    a1[1] = 0xDEAD000000000122LL;
    v35 = (unsigned int *)(v11 + 52696);
    raw_spin_unlock_irqrestore(v11 + 51600, v33);
    v36 = raw_spin_lock_irqsave(a1 + 72);
    _X8 = (unsigned int *)(a1 + 68);
    __asm { PRFM            #0x11, [X8] }
    do
      v63 = __ldxr(_X8);
    while ( __stxr(v63 + 1, _X8) );
    _wake_up(a1 + 69, 1, 1, 0);
    raw_spin_unlock_irqrestore(a1 + 72, v36);
    v37 = *((_DWORD *)a1 + 61);
    if ( v37 != -1 )
      ida_free(v11 + 51632, (unsigned int)(v37 - 1000 * *(_DWORD *)v11));
    *((_BYTE *)a1 + 307) = 0;
    v38 = raw_spin_lock_irqsave(v11 + 51600);
    for ( i = *(_QWORD **)(v11 + 52744); i != (_QWORD *)(v11 + 52744); i = (_QWORD *)*i )
    {
      if ( (__int64 *)i[2] == a1 )
        i[2] = 0;
    }
    raw_spin_unlock_irqrestore(v11 + 51600, v38);
    if ( *((_DWORD *)a1 + 74) )
    {
      if ( a1[67] )
      {
        v40 = *v35;
        if ( *v35 )
        {
          v41 = 0;
          do
          {
            if ( *(_QWORD *)(a1[67] + 80LL * (int)v41 + 72) )
            {
              dev_pm_qos_remove_request();
              v40 = *v35;
            }
            ++v41;
          }
          while ( v41 < v40 );
        }
      }
    }
    kfree(a1[67]);
    if ( *((_DWORD *)a1 + 75) )
    {
      v42 = a1[16];
      v43 = *(_QWORD *)(v42 + 64048);
      mutex_lock(v42 + 64056);
      if ( v43 )
        _pm_relax(v43);
      mutex_unlock(v42 + 64056);
    }
    v44 = a1[17];
    if ( v44 )
    {
      v45 = raw_spin_lock_irqsave(v11 + 51600);
      v46 = *(_DWORD *)(v44 + 1020);
      _VF = __OFSUB__(v46, 1);
      v47 = v46 - 1;
      if ( v47 < 0 == _VF )
        *(_DWORD *)(v44 + 1020) = v47;
      raw_spin_unlock_irqrestore(v11 + 51600, v45);
    }
    v48 = a1[18];
    if ( v48 )
    {
      v49 = raw_spin_lock_irqsave(v11 + 51600);
      v50 = *(_DWORD *)(v48 + 1020);
      _VF = __OFSUB__(v50, 1);
      v51 = v50 - 1;
      if ( v51 < 0 == _VF )
        *(_DWORD *)(v48 + 1020) = v51;
      raw_spin_unlock_irqrestore(v11 + 51600, v49);
    }
    v52 = a1[19];
    if ( v52 )
    {
      v53 = raw_spin_lock_irqsave(v11 + 51600);
      v54 = *(_DWORD *)(v52 + 1020);
      _VF = __OFSUB__(v54, 1);
      v55 = v54 - 1;
      if ( v55 < 0 == _VF )
        *(_DWORD *)(v52 + 1020) = v55;
      raw_spin_unlock_irqrestore(v11 + 51600, v53);
    }
    v56 = raw_spin_lock_irqsave((char *)a1 + 324);
    kfree(a1[63]);
    kfree(a1[64]);
    kfree(a1[65]);
    kfree(a1[66]);
    raw_spin_unlock_irqrestore((char *)a1 + 324, v56);
    debugfs_remove(a1[28]);
    if ( byte_27530 == 1 )
      fastrpc_unreserve_dma_heap(a1[80]);
    v14 = a1;
    goto LABEL_85;
  }
  v64 = printk(
          &unk_26651,
          "fastrpc_user_obj_free",
          4294967186LL,
          _ReadStatusReg(SP_EL0) + 2320,
          *((unsigned int *)a1 + 62),
          *((unsigned int *)a1 + 61));
  __break(0x800u);
  return (unsigned int *)kref_put(v64);
}
