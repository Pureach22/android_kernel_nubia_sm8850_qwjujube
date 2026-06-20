__int64 __fastcall sde_debugfs_conn_cmd_rx_write(__int64 a1, unsigned __int64 a2, size_t a3, __int64 *a4)
{
  __int64 v4; // x26
  __int64 v5; // x8
  size_t v8; // x23
  __int64 v9; // x0
  __int64 result; // x0
  __int64 v11; // x24
  __int64 v12; // x20
  char *v13; // x0
  char *v14; // x22
  char *v15; // x0
  __int64 v16; // x23
  int v17; // w0
  __int64 v18; // x19
  _DWORD *v19; // x8
  __int64 v20; // x0
  __int64 v21; // x4
  int v22; // w25
  int v23; // [xsp+4h] [xbp-11Ch] BYREF
  char *stringp; // [xsp+8h] [xbp-118h] BYREF
  _QWORD v25[34]; // [xsp+10h] [xbp-110h] BYREF

  v25[32] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  v5 = *a4;
  stringp = nullptr;
  memset(v25, 0, 256);
  v23 = 0;
  if ( v5 || !v4 )
  {
    printk(&unk_277692, "_sde_debugfs_conn_cmd_rx_write");
    result = -22;
    goto LABEL_6;
  }
  if ( !*(_QWORD *)(v4 + 3080) )
  {
    printk(&unk_274240, "_sde_debugfs_conn_cmd_rx_write");
    result = -22;
    goto LABEL_6;
  }
  *(_DWORD *)(v4 + 5004) = 0;
  *(_QWORD *)(v4 + 4987) = 0;
  *(_QWORD *)(v4 + 4995) = 0;
  *(_QWORD *)(v4 + 4971) = 0;
  *(_QWORD *)(v4 + 4979) = 0;
  *(_QWORD *)(v4 + 4955) = 0;
  *(_QWORD *)(v4 + 4963) = 0;
  *(_QWORD *)(v4 + 4939) = 0;
  *(_QWORD *)(v4 + 4947) = 0;
  *(_QWORD *)(v4 + 4923) = 0;
  *(_QWORD *)(v4 + 4931) = 0;
  *(_QWORD *)(v4 + 4907) = 0;
  *(_QWORD *)(v4 + 4915) = 0;
  *(_QWORD *)(v4 + 4891) = 0;
  *(_QWORD *)(v4 + 4899) = 0;
  *(_QWORD *)(v4 + 4875) = 0;
  *(_QWORD *)(v4 + 4883) = 0;
  *(_QWORD *)(v4 + 4859) = 0;
  *(_QWORD *)(v4 + 4867) = 0;
  *(_QWORD *)(v4 + 4843) = 0;
  *(_QWORD *)(v4 + 4851) = 0;
  *(_QWORD *)(v4 + 4827) = 0;
  *(_QWORD *)(v4 + 4835) = 0;
  *(_QWORD *)(v4 + 4811) = 0;
  *(_QWORD *)(v4 + 4819) = 0;
  *(_QWORD *)(v4 + 4795) = 0;
  *(_QWORD *)(v4 + 4803) = 0;
  *(_QWORD *)(v4 + 4779) = 0;
  *(_QWORD *)(v4 + 4787) = 0;
  *(_QWORD *)(v4 + 4763) = 0;
  *(_QWORD *)(v4 + 4771) = 0;
  *(_QWORD *)(v4 + 4747) = 0;
  *(_QWORD *)(v4 + 4755) = 0;
  v8 = a3 + 1;
  v9 = _kmalloc_noprof(a3 + 1, 3520);
  if ( !v9 )
  {
    result = -12;
LABEL_6:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( a3 >> 31 )
  {
    v12 = v9;
    __break(0x800u);
    goto LABEL_39;
  }
  v11 = v9;
  _check_object_size(v9, a3, 0);
  v12 = v11;
  if ( inline_copy_from_user_4(v11, a2, a3) )
  {
LABEL_39:
    printk(&unk_2467E4, "_sde_debugfs_conn_cmd_rx_write");
    v18 = -14;
    goto LABEL_40;
  }
  if ( v8 >= a3 )
  {
    *(_BYTE *)(v11 + a3) = 0;
    if ( (_drm_debug & 4) != 0 )
      printk(&unk_25411C, v11);
    else
      printk(&unk_25784B, "_sde_debugfs_conn_cmd_rx_write");
    v13 = (char *)kstrdup(v11, 3264);
    stringp = v13;
    if ( !v13 )
    {
      v18 = -12;
LABEL_40:
      kfree(v12);
      result = v18;
      goto LABEL_6;
    }
    v14 = v13;
    v15 = strsep(&stringp, " ");
    if ( v15 )
    {
      v16 = 0;
      while ( 1 )
      {
        v17 = kstrtoint(v15, 0, &v23);
        if ( v17 )
        {
          v22 = v17;
          printk(&unk_22EA3B, "_sde_debugfs_conn_cmd_rx_write");
          goto LABEL_37;
        }
        *((_BYTE *)v25 + v16) = v23;
        if ( v16 == 255 )
          break;
        ++v16;
        v15 = strsep(&stringp, " ");
        if ( !v15 )
          goto LABEL_24;
      }
      printk(&unk_27E041, "_sde_debugfs_conn_cmd_rx_write");
    }
    else
    {
      LODWORD(v16) = 0;
LABEL_24:
      if ( LOBYTE(v25[0]) )
      {
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "command packet size in bytes: %u, rx len: %u\n", v16, LOBYTE(v25[0]));
        if ( (_DWORD)v16 )
        {
          mutex_lock(v4 + 2816);
          v19 = *(_DWORD **)(v4 + 3080);
          v20 = *(_QWORD *)(v4 + 2760);
          v21 = LOBYTE(v25[0]);
          if ( *(v19 - 1) != 20501345 )
            __break(0x8228u);
          *(_DWORD *)(v4 + 5004) = ((__int64 (__fastcall *)(__int64, char *, _QWORD, __int64, __int64, _QWORD))v19)(
                                     v20,
                                     (char *)v25 + 1,
                                     (unsigned int)(v16 - 1),
                                     v4 + 4747,
                                     v21,
                                     0);
          mutex_unlock(v4 + 2816);
          if ( *(int *)(v4 + 5004) >= 1 )
            v22 = a3;
          else
            v22 = -22;
          goto LABEL_37;
        }
      }
      else
      {
        printk(&unk_249BB6, "_sde_debugfs_conn_cmd_rx_write");
      }
    }
    v22 = -14;
LABEL_37:
    kfree(v14);
    v18 = v22;
    goto LABEL_40;
  }
  __break(1u);
  return sde_debugfs_conn_cmd_rx_open();
}
