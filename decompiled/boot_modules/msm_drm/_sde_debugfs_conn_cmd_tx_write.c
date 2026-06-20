__int64 __fastcall sde_debugfs_conn_cmd_tx_write(__int64 a1, unsigned __int64 a2, size_t a3, __int64 *a4)
{
  __int64 v4; // x22
  __int64 v5; // x8
  __int64 v6; // x8
  __int64 v7; // x19
  size_t v10; // x24
  __int64 v11; // x21
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 (__fastcall *v14)(_QWORD); // x8
  __int64 v15; // x20
  void *v16; // x0
  char *v17; // x0
  char *v18; // x23
  char *v19; // x0
  __int64 v20; // x24
  int v21; // w0
  _DWORD *v22; // x8
  __int64 v23; // x1
  int v24; // w26
  __int64 v25; // x0
  unsigned __int64 StatusReg; // x25
  __int64 v27; // x26
  int v29; // [xsp+4h] [xbp-11Ch] BYREF
  char *stringp; // [xsp+8h] [xbp-118h] BYREF
  _QWORD v31[34]; // [xsp+10h] [xbp-110h] BYREF

  v31[32] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  v5 = *a4;
  stringp = nullptr;
  memset(v31, 0, 256);
  v29 = 0;
  if ( v5 || !v4 )
  {
    printk(&unk_277692, "_sde_debugfs_conn_cmd_tx_write");
    v15 = -22;
    goto LABEL_54;
  }
  if ( !*(_QWORD *)v4 || (v6 = *(_QWORD *)(*(_QWORD *)v4 + 56LL)) == 0 )
  {
    v16 = &unk_242658;
LABEL_25:
    printk(v16, "sde_connector_get_kms");
    printk(&unk_234896, "_sde_debugfs_conn_cmd_tx_write");
    v15 = -22;
    goto LABEL_54;
  }
  v7 = *(_QWORD *)(v6 + 8);
  if ( !v7 )
  {
    v16 = &unk_234896;
    goto LABEL_25;
  }
  if ( *(_QWORD *)(v4 + 3072) )
  {
    v10 = a3 + 1;
    v11 = _kmalloc_noprof(a3 + 1, 3520);
    if ( v11 )
    {
      while ( 1 )
      {
        v12 = *(_QWORD *)(v7 + 6384);
        if ( v12 )
        {
          mutex_lock(v12);
          v13 = *(_QWORD *)(v7 + 6384);
          if ( v13 )
          {
            v14 = *(__int64 (__fastcall **)(_QWORD))(v13 + 88);
            if ( v14 )
            {
              if ( *((_DWORD *)v14 - 1) != 1370937740 )
                __break(0x8228u);
              if ( (v14(v7) & 1) == 0 )
              {
                if ( (_drm_debug & 4) != 0 )
                  _drm_dev_dbg(0, 0, 0, "op not supported due to HW unavailablity\n");
                v15 = -95;
                goto LABEL_49;
              }
            }
          }
        }
        if ( a3 >> 31 )
          break;
        _check_object_size(v11, a3, 0);
        if ( inline_copy_from_user_4(v11, a2, a3) )
          goto LABEL_48;
        if ( v10 >= a3 )
        {
          *(_BYTE *)(v11 + a3) = 0;
          if ( (_drm_debug & 4) != 0 )
            printk(&unk_24349D, v11);
          else
            printk(&unk_262A7C, "_sde_debugfs_conn_cmd_tx_write");
          v17 = (char *)kstrdup(v11, 3264);
          stringp = v17;
          if ( !v17 )
          {
            v15 = -12;
            goto LABEL_49;
          }
          v18 = v17;
          v19 = strsep(&stringp, " ");
          if ( v19 )
          {
            v20 = 0;
            while ( 1 )
            {
              v21 = kstrtoint(v19, 0, &v29);
              if ( v21 )
              {
                v24 = v21;
                printk(&unk_22EA3B, "_sde_debugfs_conn_cmd_tx_write");
                goto LABEL_46;
              }
              *((_BYTE *)v31 + v20) = v29;
              if ( v20 == 255 )
                break;
              ++v20;
              v19 = strsep(&stringp, " ");
              if ( !v19 )
                goto LABEL_37;
            }
            printk(&unk_2776C9, "_sde_debugfs_conn_cmd_tx_write");
LABEL_45:
            v24 = -14;
          }
          else
          {
            LODWORD(v20) = 0;
LABEL_37:
            if ( (_drm_debug & 4) != 0 )
              _drm_dev_dbg(0, 0, 0, "command packet size in bytes: %u\n", v20);
            if ( !(_DWORD)v20 )
              goto LABEL_45;
            mutex_lock(v4 + 2816);
            v22 = *(_DWORD **)(v4 + 3072);
            v23 = *(_QWORD *)(v4 + 2760);
            if ( *(v22 - 1) != 1635496469 )
              __break(0x8228u);
            *(_BYTE *)(v4 + 4745) = ((unsigned int (__fastcall *)(__int64, __int64, _QWORD *, _QWORD, _QWORD))v22)(
                                      v4,
                                      v23,
                                      v31,
                                      (unsigned int)v20,
                                      0) == 0;
            mutex_unlock(v4 + 2816);
            v24 = a3;
          }
LABEL_46:
          kfree(v18);
          v15 = v24;
          goto LABEL_49;
        }
        __break(1u);
        v10 = a3 + 1;
        StatusReg = _ReadStatusReg(SP_EL0);
        v27 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &sde_debugfs_conn_cmd_tx_write__alloc_tag;
        v11 = _kmalloc_noprof(a3 + 1, 3520);
        *(_QWORD *)(StatusReg + 80) = v27;
        if ( !v11 )
          goto LABEL_53;
      }
      __break(0x800u);
LABEL_48:
      printk(&unk_2467E4, "_sde_debugfs_conn_cmd_tx_write");
      v15 = -14;
LABEL_49:
      v25 = *(_QWORD *)(v7 + 6384);
      if ( v25 )
        mutex_unlock(v25);
      kfree(v11);
    }
    else
    {
LABEL_53:
      v15 = -12;
    }
  }
  else
  {
    printk(&unk_227BF1, "_sde_debugfs_conn_cmd_tx_write");
    v15 = -22;
  }
LABEL_54:
  _ReadStatusReg(SP_EL0);
  return v15;
}
