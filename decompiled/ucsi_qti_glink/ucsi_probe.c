__int64 __fastcall ucsi_probe(__int64 a1)
{
  __int64 v1; // x20
  _QWORD *v3; // x0
  _QWORD *v4; // x19
  unsigned __int64 v5; // x0
  unsigned int v6; // w21
  unsigned int v8; // w0
  unsigned __int16 v9; // w8
  unsigned __int64 dir; // x2
  unsigned int v11; // w0
  unsigned int v12; // w20
  __int64 v13; // x0
  unsigned __int16 v14; // [xsp+Ch] [xbp-34h] BYREF
  const char *v15; // [xsp+10h] [xbp-30h] BYREF
  __int64 v16; // [xsp+18h] [xbp-28h]
  _QWORD *v17; // [xsp+20h] [xbp-20h]
  __int64 (__fastcall *v18)(); // [xsp+28h] [xbp-18h]
  __int64 (__fastcall *v19)(); // [xsp+30h] [xbp-10h]
  __int64 v20; // [xsp+38h] [xbp-8h]

  v1 = a1 + 16;
  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  v14 = 0;
  v3 = (_QWORD *)devm_kmalloc(a1 + 16, 1456, 3520);
  if ( v3 )
  {
    v4 = v3;
    v3[173] = 0xFFFFFFFE00000LL;
    v3[174] = v3 + 174;
    v3[175] = v3 + 174;
    v3[177] = 0xFFFFFFFE00000LL;
    v3[176] = ucsi_qti_setup_work;
    v3[178] = v3 + 178;
    v3[179] = v3 + 178;
    v3[180] = ucsi_qti_unregister_work;
    _mutex_init(v3 + 16, "&udev->read_lock", &ucsi_probe___key_3);
    _mutex_init(v4 + 22, "&udev->write_lock", &ucsi_probe___key_5);
    _mutex_init(v4 + 28, "&udev->state_lock", &ucsi_probe___key_7);
    *((_DWORD *)v4 + 8) = 0;
    _init_swait_queue_head(v4 + 5, "&x->wait", &init_completion___key);
    *((_DWORD *)v4 + 16) = 0;
    _init_swait_queue_head(v4 + 9, "&x->wait", &init_completion___key);
    *((_DWORD *)v4 + 24) = 0;
    _init_swait_queue_head(v4 + 13, "&x->wait", &init_completion___key);
    *((_DWORD *)v4 + 344) = 0;
    *((_DWORD *)v4 + 362) = 1;
    v15 = "ucsi";
    v17 = v4;
    v18 = ucsi_callback;
    LODWORD(v16) = 32779;
    v19 = ucsi_qti_state_cb;
    v5 = pmic_glink_register_client(v1, &v15);
    v4[2] = v5;
    if ( v5 < 0xFFFFFFFFFFFFF001LL )
    {
      v8 = ucsi_qti_read(v4, 0, &v14, 2);
      if ( (v8 & 0x80000000) != 0 )
      {
        v6 = v8;
        dev_err(v1, "Error reading version rc=%d\n", v8);
        pmic_glink_unregister_client(v4[2]);
      }
      else if ( (unsigned int)v14 - 529 > 0xFFFFFDEF )
      {
        dev_info(a1 + 16, "UCSI version: %x\n", v14);
        v9 = v14;
        *(_QWORD *)(a1 + 168) = v4;
        *((_WORD *)v4 + 680) = v9;
        *v4 = v1;
        ucsi_ipc_log = ipc_log_context_create(10, "ucsi", 0);
        if ( !ucsi_ipc_log )
          dev_warn(v1, "Error in creating ipc_log_context\n");
        dir = debugfs_create_dir("ucsi_glink", 0);
        v4[3] = dir;
        if ( dir >= 0xFFFFFFFFFFFFF001LL )
        {
          dev_err(v1, "Failed to create ucsi_glink directory: %ld\n", dir);
          v4[3] = 0;
        }
        else
        {
          debugfs_create_bool("remoteproc_timestamp_en", 384, dir, (char *)v4 + 1452);
        }
        v11 = ucsi_setup(v4);
        if ( v11 )
        {
          v12 = v11;
          debugfs_remove(v4[3]);
          ipc_log_context_destroy(ucsi_ipc_log);
          v13 = v4[2];
          ucsi_ipc_log = 0;
          pmic_glink_unregister_client(v13);
          v6 = v12;
        }
        else
        {
          v6 = 0;
        }
      }
      else
      {
        dev_err(v1, "UCSI version %x not supported\n", v14);
        pmic_glink_unregister_client(v4[2]);
        v6 = -19;
      }
    }
    else if ( (_DWORD)v5 == -517 )
    {
      v6 = -517;
    }
    else
    {
      v6 = v5;
      dev_err(v1, "Error in registering with pmic_glink rc=%d\n", v5);
    }
  }
  else
  {
    v6 = -12;
  }
  _ReadStatusReg(SP_EL0);
  return v6;
}
