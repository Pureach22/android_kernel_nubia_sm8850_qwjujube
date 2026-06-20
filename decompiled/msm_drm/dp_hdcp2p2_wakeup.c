__int64 __fastcall dp_hdcp2p2_wakeup(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  __int64 v9; // x0
  __int64 v10; // x21
  int v11; // w9
  int v12; // w8
  _QWORD *v13; // x9
  __int64 v14; // x10
  __int64 v15; // x12
  __int64 v16; // x13
  __int64 v17; // x10
  __int64 v18; // x11
  __int64 v19; // x9
  __int64 v20; // x12
  __int64 v21; // x9
  __int64 v22; // x9
  int v23; // w8
  unsigned int v24; // w9
  unsigned int v25; // w9
  int v26; // w7
  unsigned int v27; // w10
  __int64 ipc_log_context; // x0
  void *v30; // x0
  __int64 v31; // x0
  char v32; // [xsp+0h] [xbp+0h]
  char v33; // [xsp+0h] [xbp+0h]

  v9 = sde_evtlog_log(sde_dbg_base_evtlog, "dp_hdcp2p2_wakeup", 189, 8, 4369, -1059143953, a7, a8, v32);
  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context(v9);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v30 = &unk_275B6D;
LABEL_29:
    printk(v30, "dp_hdcp2p2_wakeup");
    return 4294967274LL;
  }
  v10 = *(_QWORD *)(a1 + 8);
  if ( !v10 )
  {
    v31 = get_ipc_log_context(v9);
    ipc_log_string(v31, "[e][%-4d]invalid ctrl\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v30 = &unk_23710F;
    goto LABEL_29;
  }
  if ( !*(_QWORD *)(a1 + 40) )
    goto LABEL_14;
  mutex_lock(v10 + 288);
  v11 = **(_DWORD **)(a1 + 40);
  *(_DWORD *)(v10 + 400) = 0;
  if ( v11 )
  {
    v12 = *(_DWORD *)(*(_QWORD *)(a1 + 40) + 20LL);
    *(_DWORD *)(v10 + 400) = v12;
    if ( v11 == 1 )
      goto LABEL_11;
    v12 += *(_DWORD *)(*(_QWORD *)(a1 + 40) + 36LL);
    *(_DWORD *)(v10 + 400) = v12;
    if ( v11 == 2 )
      goto LABEL_11;
    v12 += *(_DWORD *)(*(_QWORD *)(a1 + 40) + 52LL);
    *(_DWORD *)(v10 + 400) = v12;
    if ( v11 == 3 )
      goto LABEL_11;
    v12 += *(_DWORD *)(*(_QWORD *)(a1 + 40) + 68LL);
    *(_DWORD *)(v10 + 400) = v12;
    if ( v11 == 4 )
      goto LABEL_11;
    __break(0x5512u);
  }
  v12 = 0;
LABEL_11:
  v13 = *(_QWORD **)(a1 + 40);
  v14 = v13[4];
  v15 = v13[1];
  v16 = v13[2];
  *(_QWORD *)(v10 + 432) = v13[3];
  *(_QWORD *)(v10 + 440) = v14;
  *(_QWORD *)(v10 + 416) = v15;
  *(_QWORD *)(v10 + 424) = v16;
  v18 = v13[7];
  v17 = v13[8];
  v20 = v13[5];
  v19 = v13[6];
  *(_QWORD *)(v10 + 464) = v18;
  *(_QWORD *)(v10 + 472) = v17;
  *(_QWORD *)(v10 + 448) = v20;
  *(_QWORD *)(v10 + 456) = v19;
  *(_BYTE *)(v10 + 481) = *(_BYTE *)(*(_QWORD *)(a1 + 40) + 72LL);
  *(_BYTE *)(v10 + 482) = *(_BYTE *)(a1 + 36);
  if ( v12 )
  {
    v21 = *(_QWORD *)(a1 + 16);
    *(_DWORD *)(v10 + 376) = v12;
    *(_QWORD *)(v10 + 368) = v21;
    v22 = *(_QWORD *)(a1 + 16);
    *(_DWORD *)(v10 + 392) = v12;
    *(_QWORD *)(v10 + 384) = v22;
    *(_DWORD *)(v10 + 404) = *(_DWORD *)(a1 + 28);
    *(_DWORD *)(v10 + 408) = *(_DWORD *)(a1 + 32);
  }
  mutex_unlock(v10 + 288);
LABEL_14:
  *(_BYTE *)(v10 + 483) = 0;
  v23 = *(_DWORD *)a1;
  if ( *(_DWORD *)a1 == 4 )
  {
    *(_DWORD *)(v10 + 80) = 3;
    v25 = *(_DWORD *)(v10 + 8);
    if ( *(_DWORD *)v10 - *(_DWORD *)(v10 + 4) <= v25 )
    {
      *(_DWORD *)(v10 + 4LL * (v25 & *(_DWORD *)v10) + 24) = *(_DWORD *)a1;
      __dmb(0xAu);
      ++*(_DWORD *)v10;
    }
    kthread_park(*(_QWORD *)(v10 + 360));
    goto LABEL_25;
  }
  if ( v23 == 3 )
  {
    *(_DWORD *)(v10 + 80) = 2;
    v24 = *(_DWORD *)(v10 + 8);
    if ( *(_DWORD *)v10 - *(_DWORD *)(v10 + 4) <= v24 )
    {
      *(_DWORD *)(v10 + 4LL * (v24 & *(_DWORD *)v10) + 24) = *(_DWORD *)a1;
      __dmb(0xAu);
LABEL_23:
      ++*(_DWORD *)v10;
    }
  }
  else
  {
    v27 = *(_DWORD *)(v10 + 8);
    if ( *(_DWORD *)v10 - *(_DWORD *)(v10 + 4) <= v27 )
    {
      *(_DWORD *)(v10 + 4LL * (v27 & *(_DWORD *)v10) + 24) = v23;
      __dmb(0xAu);
      goto LABEL_23;
    }
  }
  _wake_up(v10 + 56, 3, 1, 0);
LABEL_25:
  sde_evtlog_log(sde_dbg_base_evtlog, "dp_hdcp2p2_wakeup", 223, 8, 8738, *(_DWORD *)a1, -1059143953, v26, v33);
  return 0;
}
