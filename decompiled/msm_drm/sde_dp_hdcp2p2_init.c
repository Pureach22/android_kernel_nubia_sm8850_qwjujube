__int64 __fastcall sde_dp_hdcp2p2_init(_QWORD *a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  __int64 v4; // x0
  unsigned __int64 v5; // x0
  unsigned __int64 v6; // x20
  __int64 ipc_log_context; // x0
  int v8; // w21
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 (__fastcall **v12)(); // [xsp+8h] [xbp-28h] BYREF
  void *v13; // [xsp+10h] [xbp-20h]
  __int64 v14; // [xsp+18h] [xbp-18h]
  __int64 v15; // [xsp+20h] [xbp-10h]
  __int64 v16; // [xsp+28h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0;
  v15 = 0;
  v12 = nullptr;
  v13 = nullptr;
  if ( !a1 || !a1[11] || !a1[12] || !a1[8] )
  {
    ipc_log_context = get_ipc_log_context(a1);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "sde_dp_hdcp2p2_init");
    v3 = -22;
    goto LABEL_14;
  }
  v2 = _kmalloc_cache_noprof(msleep, 3520, 488);
  v3 = v2;
  if ( !v2 )
  {
    v3 = -12;
    goto LABEL_14;
  }
  memcpy((void *)(v2 + 104), a1, 0x88u);
  *(_QWORD *)(v3 + 96) = &sde_dp_hdcp2p2_init_intr;
  *(_QWORD *)v3 = 0;
  *(_QWORD *)(v3 + 8) = 0x400000007LL;
  *(_QWORD *)(v3 + 352) = &sde_dp_hdcp2p2_init_hdcp2x_ops;
  *(_QWORD *)(v3 + 368) = 0;
  *(_QWORD *)(v3 + 384) = 0;
  *(_DWORD *)(v3 + 88) = 0;
  *(_QWORD *)(v3 + 16) = v3 + 24;
  _init_waitqueue_head(v3 + 56, "&ctrl->wait_q", &sde_dp_hdcp2p2_init___key);
  *(_DWORD *)(v3 + 80) = 0;
  *(_QWORD *)(v3 + 336) = sde_dp_hdcp2p2_init_ops;
  _mutex_init(v3 + 240, "&ctrl->mutex", &sde_dp_hdcp2p2_init___key_10);
  _mutex_init(v3 + 288, "&ctrl->msg_lock", &sde_dp_hdcp2p2_init___key_12);
  v12 = &sde_dp_hdcp2p2_init_client_ops;
  v13 = &sde_dp_hdcp2p2_init_hdcp2x_ops;
  v14 = v3;
  v15 = v3 + 344;
  v4 = sde_hdcp_2x_register(&v12);
  if ( (_DWORD)v4 )
  {
    v8 = v4;
    v9 = get_ipc_log_context(v4);
    ipc_log_string(
      v9,
      "[e][%-4d]Unable to register with HDCP 2.2 library\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_210B7C, "sde_dp_hdcp2p2_init");
LABEL_12:
    kfree(v3);
    v3 = v8;
    goto LABEL_14;
  }
  msm_hdcp_register_cb(*a1, v3, (__int64)dp_hdcp2p2_min_level_change);
  v5 = kthread_create_on_node(dp_hdcp2p2_main, v3, 0xFFFFFFFFLL, "dp_hdcp2p2");
  v6 = v5;
  if ( v5 > 0xFFFFFFFFFFFFF000LL )
  {
    *(_QWORD *)(v3 + 360) = v5;
    v10 = get_ipc_log_context(v5);
    ipc_log_string(v10, "[e][%-4d]unable to start DP hdcp2p2 thread\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_225FB9, "sde_dp_hdcp2p2_init");
    v8 = *(_DWORD *)(v3 + 360);
    *(_QWORD *)(v3 + 360) = 0;
    goto LABEL_12;
  }
  wake_up_process(v5);
  *(_QWORD *)(v3 + 360) = v6;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return v3;
}
