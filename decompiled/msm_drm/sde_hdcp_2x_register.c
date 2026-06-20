__int64 __fastcall sde_hdcp_2x_register(__int64 *a1)
{
  __int64 v1; // x8
  _QWORD *v3; // x0
  _QWORD *v4; // x20
  __int64 v5; // x9
  unsigned __int64 v6; // x0
  unsigned __int64 v7; // x19
  void *v9; // x0
  unsigned int v10; // w19

  if ( !a1 )
  {
    v9 = &unk_252102;
LABEL_12:
    printk(v9, "sde_hdcp_2x_register");
    return 4294967274LL;
  }
  v1 = a1[1];
  if ( !v1 )
  {
    v9 = &unk_23A73E;
    goto LABEL_12;
  }
  if ( !*a1 )
  {
    v9 = &unk_25CE9C;
    goto LABEL_12;
  }
  if ( !a1[3] )
  {
    v9 = &unk_22CD4D;
    goto LABEL_12;
  }
  *(_QWORD *)(v1 + 8) = sde_hdcp_2x_client_feature_supported;
  *(_QWORD *)a1[1] = sde_hdcp_2x_wakeup;
  *(_QWORD *)(a1[1] + 16) = sde_hdcp_2x_force_encryption;
  v3 = (_QWORD *)_kmalloc_cache_noprof(drm_dp_dpcd_read, 3520, 256);
  v4 = v3;
  if ( !v3 )
    return 4294967284LL;
  v3[24] = v3 + 24;
  v3[25] = v3 + 24;
  v5 = *a1;
  v3[18] = a1[2];
  v3[20] = v5;
  *v3 = 0;
  v3[1] = 0x400000007LL;
  v3[2] = v3 + 3;
  _init_waitqueue_head(v3 + 7, "&hdcp->wait_q", &sde_hdcp_2x_register___key);
  *((_DWORD *)v4 + 44) = 1;
  *((_DWORD *)v4 + 33) = 0;
  *((_DWORD *)v4 + 56) = 0;
  _init_swait_queue_head(v4 + 29, "&x->wait", &init_completion___key_0);
  *(_QWORD *)a1[3] = v4;
  v6 = kthread_create_on_node(sde_hdcp_2x_main, v4, 0xFFFFFFFFLL, "hdcp_2x");
  v7 = v6;
  if ( v6 >= 0xFFFFFFFFFFFFF001LL )
  {
    v4[27] = v6;
    printk(&unk_226054, "sde_hdcp_2x_register");
    v10 = *((_DWORD *)v4 + 54);
    v4[27] = 0;
    kfree(v4);
    return v10;
  }
  else
  {
    wake_up_process(v6);
    v4[27] = v7;
    *((_BYTE *)v4 + 138) = 0;
    return 0;
  }
}
