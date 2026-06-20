__int64 __fastcall battery_dbg_probe(__int64 a1)
{
  __int64 v1; // x20
  _QWORD *v3; // x0
  _QWORD *v4; // x19
  unsigned __int64 v5; // x0
  unsigned int v6; // w21
  __int64 v7; // x0
  unsigned int group; // w0
  unsigned __int64 dir; // x21
  __int64 v10; // x2
  unsigned __int64 v11; // x23
  __int64 v12; // x0
  int v13; // w0
  __int64 v14; // x2
  unsigned int v15; // w21
  __int64 v16; // x0
  int v17; // w20
  __int64 v18; // x24
  _QWORD *v19; // x27
  unsigned __int64 v20; // x22
  unsigned __int64 file; // x0
  unsigned int v22; // w21
  unsigned __int64 v23; // x0
  unsigned __int64 v24; // x0
  unsigned __int64 v25; // x0
  unsigned __int64 v26; // x0
  unsigned __int64 v27; // x0
  unsigned __int64 v29; // [xsp+8h] [xbp-48h]
  const char *v30; // [xsp+10h] [xbp-40h] BYREF
  __int64 v31; // [xsp+18h] [xbp-38h]
  _QWORD *v32; // [xsp+20h] [xbp-30h]
  __int64 (__fastcall *v33)(int, void *); // [xsp+28h] [xbp-28h]
  __int64 v34; // [xsp+30h] [xbp-20h]
  _QWORD v35[3]; // [xsp+38h] [xbp-18h] BYREF

  v1 = a1 + 16;
  v35[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33 = nullptr;
  v34 = 0;
  v31 = 0;
  v32 = nullptr;
  v3 = (_QWORD *)devm_kmalloc(a1 + 16, 4784, 3520);
  if ( !v3 )
  {
    v6 = -12;
    goto LABEL_43;
  }
  v4 = v3;
  *v3 = v1;
  LODWORD(v31) = 32781;
  v30 = "battery_debug";
  v32 = v3;
  v33 = battery_dbg_callback;
  v5 = pmic_glink_register_client(v1, &v30);
  v4[1] = v5;
  if ( v5 < 0xFFFFFFFFFFFFF001LL )
  {
    _mutex_init(v4 + 2, "&bd->lock", &battery_dbg_probe___key);
    *((_DWORD *)v4 + 16) = 0;
    _init_swait_queue_head(v4 + 9, "&x->wait", &init_completion___key);
    v7 = *v4;
    *(_QWORD *)(a1 + 168) = v4;
    v4[527] = v4 + 14;
    v4[528] = 0;
    group = sysfs_create_group(v7, &battery_dbg_group);
    if ( group )
    {
      v6 = group;
      dev_err(*v4, "Failed to create sysfs files for qbg_context: %d\n", group);
      if ( (v6 & 0x80000000) != 0 )
      {
        pmic_glink_unregister_client(v4[1]);
        goto LABEL_43;
      }
    }
    dir = debugfs_create_dir("battery_debug", 0);
    if ( dir >= 0xFFFFFFFFFFFFF001LL )
    {
      printk(&unk_76FE, "battery_dbg_add_debugfs", (unsigned int)dir);
LABEL_42:
      v6 = 0;
      goto LABEL_43;
    }
    v11 = debugfs_create_dir("votables", dir);
    v29 = dir;
    if ( v11 > 0xFFFFFFFFFFFFF000LL )
    {
      printk(&unk_7553, "battery_dbg_create_votables", v10);
      LODWORD(v20) = v11;
    }
    else
    {
      v35[0] = 0x10000800DLL;
      v35[1] = 21;
      mutex_lock(v4 + 2);
      v12 = v4[1];
      *((_DWORD *)v4 + 16) = 0;
      v13 = pmic_glink_write(v12, v35, 16);
      if ( v13 )
      {
        LODWORD(v20) = v13;
      }
      else
      {
        if ( (unsigned int)wait_for_completion_timeout(v4 + 8, 250) )
        {
          mutex_unlock(v4 + 2);
          v15 = *((_DWORD *)v4 + 1058);
          v16 = devm_kmalloc(*v4, 208LL * v15, 3520);
          v4[596] = v16;
          if ( v16 )
          {
            if ( !v15 )
            {
LABEL_36:
              v6 = 0;
              v4[526] = v29;
              goto LABEL_43;
            }
            v17 = 0;
            v18 = 0;
            v19 = v4 + 530;
            while ( 1 )
            {
              *(_QWORD *)(v4[596] + v18 + 16) = v4;
              *(_DWORD *)(v4[596] + v18 + 8) = v17;
              if ( v18 == 2704 )
                __break(0x5512u);
              v20 = debugfs_create_dir(v19, v11);
              if ( v20 > 0xFFFFFFFFFFFFF000LL )
              {
                printk(&unk_7741, "battery_dbg_create_votable", v19);
                goto LABEL_41;
              }
              *(_QWORD *)(v4[596] + v18) = v19;
              file = debugfs_create_file("active", 256, v20, v4[596] + v18, &active_fops);
              if ( file >= 0xFFFFFFFFFFFFF001LL )
              {
                v22 = file;
                goto LABEL_30;
              }
              v23 = debugfs_create_file("winvote", 256, v20, v4[596] + v18, &winvote_fops);
              if ( v23 >= 0xFFFFFFFFFFFFF001LL )
              {
                v22 = v23;
                goto LABEL_30;
              }
              v24 = debugfs_create_file("winner", 256, v20, v4[596] + v18, &winner_fops);
              if ( v24 >= 0xFFFFFFFFFFFFF001LL )
              {
                v22 = v24;
                goto LABEL_30;
              }
              v25 = debugfs_create_file("voters", 256, v20, v4[596] + v18, &voters_fops);
              if ( v25 >= 0xFFFFFFFFFFFFF001LL )
              {
                v22 = v25;
                goto LABEL_30;
              }
              v26 = debugfs_create_file("votes", 256, v20, v4[596] + v18, &votes_fops);
              if ( v26 >= 0xFFFFFFFFFFFFF001LL )
              {
                v22 = v26;
                goto LABEL_30;
              }
              v27 = debugfs_create_file("status", 256, v20, v4[596] + v18, &status_fops);
              if ( v27 >= 0xFFFFFFFFFFFFF001LL )
                break;
              v18 += 208;
              v19 = (_QWORD *)((char *)v19 + 12);
              ++v17;
              if ( 208LL * v15 == v18 )
                goto LABEL_36;
            }
            v22 = v27;
LABEL_30:
            printk(&unk_7841, "battery_dbg_create_votable", v22);
            LODWORD(v20) = v22;
          }
          else
          {
            LODWORD(v20) = -12;
          }
          goto LABEL_41;
        }
        printk(&unk_750C, "battery_dbg_write", v14);
        LODWORD(v20) = -110;
      }
      mutex_unlock(v4 + 2);
      printk(&unk_7A36, "battery_dbg_create_votables", (unsigned int)v20);
    }
LABEL_41:
    printk(&unk_7949, "battery_dbg_add_debugfs", (unsigned int)v20);
    debugfs_remove(v29);
    goto LABEL_42;
  }
  if ( (_DWORD)v5 == -517 )
  {
    v6 = -517;
  }
  else
  {
    v6 = v5;
    dev_err(*v4, "Error in registering with pmic_glink %d\n", v5);
  }
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return v6;
}
