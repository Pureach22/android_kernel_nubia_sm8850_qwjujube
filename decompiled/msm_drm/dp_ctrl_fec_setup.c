__int64 __fastcall dp_ctrl_fec_setup(__int64 result)
{
  int v1; // w8
  __int64 v2; // x19
  char v3; // w22
  void (*v4)(void); // x8
  int v5; // w7
  void (*v6)(void); // x8
  int v7; // w20
  void (*v8)(void); // x8
  __int64 v9; // x0
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x21
  __int64 v12; // x0
  char v13; // [xsp+0h] [xbp-10h]
  _BYTE v14[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(unsigned __int8 *)(result + 259);
  v14[0] = 0;
  if ( v1 == 1 )
  {
    v2 = result;
    if ( *(_DWORD *)(result + 276) <= 1u )
    {
      v3 = 1;
      v4 = *(void (**)(void))(*(_QWORD *)(result + 176) + 240LL);
      if ( *((_DWORD *)v4 - 1) != 289804815 )
        __break(0x8228u);
      v4();
      usleep_range_state(900, 1000, 2);
      drm_dp_dpcd_read(*(_QWORD *)(*(_QWORD *)(v2 + 136) + 24LL), 640, v14, 1);
      if ( (v14[0] & 1) != 0 )
      {
        v7 = 0;
      }
      else
      {
        v6 = *(void (**)(void))(*(_QWORD *)(v2 + 176) + 240LL);
        if ( *((_DWORD *)v6 - 1) != 289804815 )
          __break(0x8228u);
        v6();
        usleep_range_state(900, 1000, 2);
        v7 = 1;
        drm_dp_dpcd_read(*(_QWORD *)(*(_QWORD *)(v2 + 136) + 24LL), 640, v14, 1);
        if ( (v14[0] & 1) != 0 )
        {
          v3 = 1;
        }
        else
        {
          v8 = *(void (**)(void))(*(_QWORD *)(v2 + 176) + 240LL);
          if ( *((_DWORD *)v8 - 1) != 289804815 )
            __break(0x8228u);
          v8();
          usleep_range_state(900, 1000, 2);
          drm_dp_dpcd_read(*(_QWORD *)(*(_QWORD *)(v2 + 136) + 24LL), 640, v14, 1);
          v3 = v14[0] & 1;
          if ( (v14[0] & 1) != 0 )
            v7 = 2;
          else
            v7 = 3;
        }
      }
      v9 = sde_evtlog_log(sde_dbg_base_evtlog, "dp_ctrl_fec_setup", 943, 8, v7, v3 & 1, -1059143953, v5, v13);
      ipc_log_context = get_ipc_log_context(v9);
      StatusReg = _ReadStatusReg(SP_EL0);
      result = ipc_log_string(
                 ipc_log_context,
                 "[d][%-4d]retries %d, fec_en_detected %d\n",
                 *(_DWORD *)(StatusReg + 1800),
                 v7,
                 v3 & 1);
      if ( (_drm_debug & 4) != 0 )
        result = _drm_dev_dbg(
                   0,
                   0,
                   0,
                   "[msm-dp-debug][%-4d]retries %d, fec_en_detected %d\n",
                   *(_DWORD *)(StatusReg + 1800),
                   v7,
                   v3 & 1);
      if ( (v3 & 1) == 0 )
      {
        v12 = get_ipc_log_context(result);
        ipc_log_string(v12, "[w][%-4d]failed to enable sink fec\n", *(_DWORD *)(StatusReg + 1800));
        result = printk(&unk_223420, "dp_ctrl_fec_setup");
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
