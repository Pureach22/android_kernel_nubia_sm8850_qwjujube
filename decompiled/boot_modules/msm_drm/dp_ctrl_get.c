__int64 __fastcall dp_ctrl_get(__int64 *a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x22
  __int64 v5; // x8
  __int64 v6; // x10
  __int64 v8; // x11
  __int64 v9; // x12
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // x9
  __int64 v13; // x10
  __int64 ipc_log_context; // x0

  v2 = *a1;
  if ( v2 && a1[1] && a1[2] && a1[3] && a1[6] )
  {
    v3 = devm_kmalloc(v2, 304, 3520);
    if ( v3 )
    {
      *(_DWORD *)(v3 + 192) = 0;
      v4 = v3;
      _init_swait_queue_head(v3 + 200, "&x->wait", &init_completion___key_2);
      *(_DWORD *)(v4 + 224) = 0;
      _init_swait_queue_head(v4 + 232, "&x->wait", &init_completion___key_2);
      v5 = a1[1];
      v6 = a1[2];
      v8 = a1[3];
      v9 = *a1;
      *(_WORD *)(v4 + 258) = 0;
      *(_QWORD *)(v4 + 136) = v6;
      *(_QWORD *)(v4 + 144) = v5;
      v10 = a1[4];
      v11 = a1[5];
      *(_QWORD *)(v4 + 152) = v8;
      *(_QWORD *)(v4 + 160) = v11;
      v12 = a1[6];
      v13 = a1[7];
      *(_QWORD *)(v4 + 168) = v10;
      *(_QWORD *)(v4 + 176) = v12;
      *(_QWORD *)(v4 + 184) = v13;
      *(_QWORD *)v4 = dp_ctrl_host_init;
      *(_QWORD *)(v4 + 8) = dp_ctrl_host_deinit;
      *(_QWORD *)(v4 + 16) = dp_ctrl_on;
      *(_QWORD *)(v4 + 24) = dp_ctrl_off;
      *(_QWORD *)(v4 + 32) = dp_ctrl_abort;
      *(_QWORD *)(v4 + 40) = dp_ctrl_isr;
      *(_QWORD *)(v4 + 56) = dp_ctrl_process_phy_test_request;
      *(_QWORD *)(v4 + 64) = dp_ctrl_link_maintenance;
      *(_QWORD *)(v4 + 72) = dp_ctrl_stream_on;
      *(_QWORD *)(v4 + 80) = dp_ctrl_stream_off;
      *(_QWORD *)(v4 + 88) = dp_ctrl_stream_pre_off;
      *(_QWORD *)(v4 + 96) = dp_ctrl_set_mst_channel_info;
      *(_QWORD *)(v4 + 104) = dp_ctrl_set_sim_mode;
      *(_QWORD *)(v4 + 112) = dp_ctrl_setup_misr;
      *(_QWORD *)(v4 + 120) = dp_ctrl_read_misr;
      *(_QWORD *)(v4 + 128) = v9;
      return v4;
    }
    else
    {
      return -12;
    }
  }
  else
  {
    ipc_log_context = get_ipc_log_context(v2);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_ctrl_get");
    return -22;
  }
}
