unsigned __int64 __fastcall dp_debug_mst_sideband_mode_write(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // x20
  size_t v6; // x22
  __int64 v7; // x0
  int v8; // w8
  int v9; // w8
  __int64 v10; // x0
  void (*v11)(void); // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 ipc_log_context; // x0
  int v15; // w3
  int v16; // w4
  unsigned __int64 StatusReg; // x21
  __int64 v19; // x0
  __int64 v20; // [xsp+8h] [xbp-18h] BYREF
  char s[8]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v22; // [xsp+18h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 32);
  v20 = 0;
  if ( v3 )
  {
    *(_QWORD *)s = 0;
    mutex_lock(v3 + 376);
    if ( a3 >= 7 )
      v6 = 7;
    else
      v6 = a3;
    _check_object_size(s, v6, 0);
    if ( inline_copy_from_user((__int64)s, a2, v6) )
    {
      a3 = -14;
    }
    else
    {
      s[v6] = 0;
      v7 = sscanf(s, "%d %u", (char *)&v20 + 4, &v20);
      if ( (_DWORD)v7 == 2 )
      {
        if ( !(_DWORD)v20 )
          LODWORD(v20) = 1;
        v8 = HIDWORD(v20);
        *(_DWORD *)(v3 + 20) = 0;
        if ( v8 )
        {
          v9 = *(_DWORD *)(v3 + 28);
          if ( (v9 & 0x10) != 0 )
          {
            v10 = *(_QWORD *)(v3 + 424);
            *(_DWORD *)(v3 + 28) = v9 & 0xFFFFFFEF;
            dp_sim_set_sim_mode(v10);
            dp_sim_update_port_num(*(_QWORD *)(v3 + 424), 0);
            if ( !*(_DWORD *)(v3 + 28) )
            {
              v11 = *(void (**)(void))(*(_QWORD *)(v3 + 128) + 88LL);
              if ( *((_DWORD *)v11 - 1) != -1759750187 )
                __break(0x8228u);
              v11();
            }
          }
        }
        else
        {
          dp_debug_enable_sim_mode(v3, 16);
        }
        dp_sim_update_port_num(*(_QWORD *)(v3 + 424), (unsigned int)v20);
        v12 = *(_QWORD *)(v3 + 424);
        s[0] = HIDWORD(v20) == 0;
        v13 = dp_sim_write_dpcd_reg(v12, s, 1, 33);
        ipc_log_context = get_ipc_log_context(v13);
        v16 = v20;
        v15 = HIDWORD(v20);
        StatusReg = _ReadStatusReg(SP_EL0);
        ipc_log_string(
          ipc_log_context,
          "[d][%-4d]mst_sideband_mode: %d port_cnt:%d\n",
          *(_DWORD *)(StatusReg + 1800),
          v15,
          v16);
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dp-debug][%-4d]mst_sideband_mode: %d port_cnt:%d\n",
            *(_DWORD *)(StatusReg + 1800),
            HIDWORD(v20),
            v20);
      }
      else
      {
        v19 = get_ipc_log_context(v7);
        ipc_log_string(v19, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
        printk(&unk_275B6D, "dp_debug_mst_sideband_mode_write");
      }
    }
    mutex_unlock(v3 + 376);
  }
  else
  {
    a3 = -19;
  }
  _ReadStatusReg(SP_EL0);
  return a3;
}
