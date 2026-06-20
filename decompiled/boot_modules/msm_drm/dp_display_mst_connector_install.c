__int64 __fastcall dp_display_mst_connector_install(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  int *v9; // x23
  __int64 v11; // x9
  __int64 v12; // x10
  __int64 v13; // x8
  __int64 v14; // x9
  unsigned __int64 v15; // x20
  unsigned __int64 v16; // x0
  __int64 v17; // x0
  unsigned __int64 StatusReg; // x20
  __int64 v19; // x0
  unsigned __int64 v20; // x20
  __int64 v22; // x0
  __int64 v23; // x0
  int v24; // w21
  __int64 v25; // x0
  char v26[8]; // [xsp+0h] [xbp-40h] BYREF
  __int64 v27; // [xsp+8h] [xbp-38h]
  __int64 v28; // [xsp+10h] [xbp-30h]
  __int64 v29; // [xsp+18h] [xbp-28h]
  __int64 v30; // [xsp+20h] [xbp-20h]
  __int64 v31; // [xsp+28h] [xbp-18h]
  __int64 v32; // [xsp+30h] [xbp-10h]
  __int64 v33; // [xsp+38h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  *(_QWORD *)v26 = 0;
  if ( a1 && a2 )
  {
    v9 = (int *)(a1 - 1156);
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dp_display_mst_connector_install",
      3707,
      8,
      4369,
      *(_DWORD *)(a1 - 1156),
      -1059143953,
      a8,
      v26[0]);
    mutex_lock(a1 + 560);
    if ( (*(_BYTE *)(a1 + 665) & 1) != 0 )
    {
      v11 = *(_QWORD *)(a1 - 1008);
      v12 = *(_QWORD *)(a1 - 1016) + 432LL;
      *(_QWORD *)v26 = *(_QWORD *)(a1 - 1144) + 16LL;
      v27 = v11;
      v28 = *(_QWORD *)(a1 - 1000);
      v29 = v12;
      v13 = *(_QWORD *)(a1 - 992);
      v14 = *(_QWORD *)(a1 - 1032);
      v30 = a2;
      v31 = v13;
      v32 = v14;
      v15 = dp_panel_get((__int64 *)v26);
      if ( v15 >= 0xFFFFFFFFFFFFF001LL )
      {
        if ( !g_dp_display || (v23 = *(_QWORD *)(g_dp_display + 56)) == 0 )
          v23 = 0;
        ipc_log_string(
          v23,
          "[e][%-4d]failed to initialize panel, rc = %d\n",
          *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
          v15);
        printk(&unk_215270, "dp_display_mst_connector_install");
      }
      else
      {
        v16 = dp_audio_get(*(_QWORD *)(a1 - 1144), v15, *(_QWORD *)(a1 - 1016) + 368LL);
        *(_QWORD *)(v15 + 952) = v16;
        if ( v16 >= 0xFFFFFFFFFFFFF001LL )
        {
          v24 = v16;
          if ( !g_dp_display || (v25 = *(_QWORD *)(g_dp_display + 56)) == 0 )
            v25 = 0;
          ipc_log_string(
            v25,
            "[e][%-4d][mst] failed to initialize audio, rc = %d\n",
            *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
            v24);
          printk(&unk_2455C2, "dp_display_mst_connector_install");
          *(_QWORD *)(v15 + 952) = 0;
          LODWORD(v15) = v24;
        }
        else
        {
          if ( !g_dp_display || (v17 = *(_QWORD *)(g_dp_display + 56)) == 0 )
            v17 = 0;
          StatusReg = _ReadStatusReg(SP_EL0);
          ipc_log_string(
            v17,
            "[d][%-4d]dp mst connector installed. conn:%d\n",
            *(_DWORD *)(StatusReg + 1800),
            *(_DWORD *)(a2 + 64));
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(
              0,
              0,
              0,
              "[msm-dp-debug][%-4d]dp mst connector installed. conn:%d\n",
              *(_DWORD *)(StatusReg + 1800),
              *(_DWORD *)(a2 + 64));
          LODWORD(v15) = 0;
        }
      }
    }
    else
    {
      if ( !g_dp_display || (v19 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v19 = 0;
      v20 = _ReadStatusReg(SP_EL0);
      ipc_log_string(v19, "[d][%-4d]drm mst not registered\n", *(_DWORD *)(v20 + 1800));
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]drm mst not registered\n", *(_DWORD *)(v20 + 1800));
      LODWORD(v15) = -1;
    }
    mutex_unlock(a1 + 560);
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dp_display_mst_connector_install",
      3744,
      8,
      8738,
      *v9,
      v15,
      -1059143953,
      v26[0]);
  }
  else
  {
    if ( !g_dp_display || (v22 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v22 = 0;
    ipc_log_string(v22, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_display_mst_connector_install");
    LODWORD(v15) = -22;
  }
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v15;
}
