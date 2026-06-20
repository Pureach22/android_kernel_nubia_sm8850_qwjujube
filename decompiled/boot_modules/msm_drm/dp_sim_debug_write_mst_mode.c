__int64 __fastcall dp_sim_debug_write_mst_mode(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  _QWORD *v3; // x26
  size_t v5; // x20
  unsigned int v6; // w27
  __int64 result; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  int v11; // w3
  int v12; // w4
  unsigned __int64 StatusReg; // x19
  unsigned __int64 v14; // x19
  unsigned int updated; // w20
  __int64 v16; // x28
  __int64 v17; // x0
  __int64 v18; // x24
  __int64 v19; // x8
  __int64 v20; // x24
  void *v21; // x0
  size_t v22; // x2
  __int64 v23; // x24
  void *v24; // x25
  __int64 v25; // x0
  __int64 ipc_log_context; // x0
  __int64 v27; // [xsp+0h] [xbp-20h] BYREF
  char s[8]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v29; // [xsp+10h] [xbp-10h]
  __int64 v30; // [xsp+18h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD **)(a1 + 32);
  v27 = 0;
  if ( v3 )
  {
    if ( a3 >= 7 )
      v5 = 7;
    else
      v5 = a3;
    v6 = a3;
    *(_QWORD *)s = 0;
    v29 = 0;
    _check_object_size(s, v5, 0);
    if ( inline_copy_from_user_0((__int64)s, a2, v5) )
    {
      result = -14;
    }
    else
    {
      s[v5] = 0;
      v8 = sscanf(s, "%d %u", (char *)&v27 + 4, &v27);
      if ( (_DWORD)v8 == 2 )
      {
        if ( (unsigned int)v27 >= 8 )
        {
          ipc_log_context = get_ipc_log_context(v8);
          ipc_log_string(
            ipc_log_context,
            "[e][%-4d]port cnt:%d exceeding max:%d\n",
            *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
            v27,
            8);
          printk(&unk_26F4EC, "dp_sim_debug_write_mst_mode");
          result = -22;
        }
        else
        {
          v9 = mutex_lock(v3 + 11);
          if ( !(_DWORD)v27 )
            LODWORD(v27) = 1;
          *((_BYTE *)v3 + 2285) = HIDWORD(v27) == 0;
          v10 = get_ipc_log_context(v9);
          v12 = v27;
          v11 = HIDWORD(v27);
          StatusReg = _ReadStatusReg(SP_EL0);
          ipc_log_string(v10, "[d][%-4d]mst_sideband_mode: %d port_cnt:%d\n", *(_DWORD *)(StatusReg + 1800), v11, v12);
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(
              0,
              0,
              0,
              "[msm-dp-debug][%-4d]mst_sideband_mode: %d port_cnt:%d\n",
              *(_DWORD *)(StatusReg + 1800),
              HIDWORD(v27),
              v27);
          v14 = *((unsigned int *)v3 + 564);
          updated = dp_sim_update_port_num((__int64)(v3 + 1), v27);
          if ( !updated )
          {
            *((_BYTE *)v3 + 193) = *((_BYTE *)v3 + 2285);
            if ( (unsigned int)v14 >= (unsigned int)v27 )
            {
LABEL_23:
              updated = v6;
              goto LABEL_24;
            }
            v16 = 48 * v14;
            while ( 1 )
            {
              v17 = devm_kmalloc(*v3, 16, 3520);
              if ( v17 )
              {
                v18 = v17;
                *(_DWORD *)(v17 + 8) = v14;
                *(_QWORD *)v17 = v3;
                scnprintf(s, 16, "edid-%d", v14);
                debugfs_create_file(s, 292, v3[19], v18, &sim_edid_fops);
                scnprintf(s, 16, "hpd-%d", v14);
                debugfs_create_file(s, 292, v3[19], v18, &sim_mst_hpd_fops);
                v19 = v3[281];
                v20 = *(unsigned int *)(v19 + 40);
                if ( (_DWORD)v20 )
                {
                  v21 = (void *)devm_kmalloc(*v3, *(unsigned int *)(v19 + 40), 3520);
                  if ( !v21 )
                  {
                    updated = -12;
                    break;
                  }
                  v22 = *(unsigned int *)(v3[281] + 40LL);
                  if ( (unsigned int)v20 < (unsigned int)v22 )
                  {
                    _fortify_panic(17, v20, v22);
                    JUMPOUT(0x82DB0);
                  }
                  v23 = v3[281];
                  v24 = v21;
                  memcpy(v21, *(const void **)(v23 + 32), v22);
                  *(_QWORD *)(v23 + v16 + 32) = v24;
                  *(_DWORD *)(v3[281] + v16 + 40) = *(_DWORD *)(v3[281] + 40LL);
                }
              }
              ++v14;
              v16 += 48;
              if ( v14 >= (unsigned int)v27 )
                goto LABEL_23;
            }
          }
LABEL_24:
          mutex_unlock(v3 + 11);
          result = updated;
        }
      }
      else
      {
        v25 = get_ipc_log_context(v8);
        ipc_log_string(v25, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
        printk(&unk_275B6D, "dp_sim_debug_write_mst_mode");
        result = -22;
      }
    }
  }
  else
  {
    result = -19;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
