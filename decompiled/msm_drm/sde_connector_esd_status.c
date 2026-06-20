__int64 __fastcall sde_connector_esd_status(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19
  __int64 v3; // x0
  _QWORD *v4; // x8
  _QWORD *v5; // x20
  __int64 (__fastcall *v6)(__int64, __int64, __int64); // x8
  __int64 v7; // x1
  int v8; // w20
  int v9; // w6
  int v10; // w7
  unsigned int v11; // w19
  __int64 v12; // x0
  __int64 v13; // x2
  __int64 v14; // x3
  __int64 v15; // x4
  __int64 v16; // x5
  __int64 v17; // x6
  int v18; // w7
  char v19[8]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    v1 = *(_QWORD *)(result + 2512);
    v2 = result;
    if ( v1 )
    {
      v3 = *(_QWORD *)(v1 + 8);
      if ( v3 )
      {
        if ( (unsigned int)sde_crtc_get_disp_op(v3) == 1 )
          goto LABEL_17;
      }
    }
    if ( !*(_QWORD *)(v2 + 3064) || *(_DWORD *)(v2 + 2736) != 16 )
      goto LABEL_17;
    v4 = (_QWORD *)(v2 + 2760);
    if ( *(_BYTE *)(v2 + 5128) == 1 )
      v4 = (_QWORD *)*v4;
    v5 = (_QWORD *)*v4;
    if ( !*v4 )
    {
LABEL_17:
      result = 0;
    }
    else
    {
      mutex_lock(v2 + 2816);
      if ( *(_DWORD *)(v5[33] + 1968LL) )
      {
        printk(&unk_22B34E, "sde_connector_esd_status");
        mutex_unlock(v2 + 2816);
        result = 4294967186LL;
      }
      else
      {
        v6 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v2 + 3064);
        v7 = *(_QWORD *)(v2 + 2760);
        if ( *((_DWORD *)v6 - 1) != -1195238087 )
          __break(0x8228u);
        v8 = v6(v2, v7, 1);
        mutex_unlock(v2 + 2816);
        if ( v8 <= 0 )
        {
          sde_connector_schedule_status_work(v2, 0);
          if ( (*(_BYTE *)(v2 + 4516) & 1) == 0 )
          {
            sde_evtlog_log(
              sde_dbg_base_evtlog,
              "_sde_connector_report_panel_dead",
              3627,
              -1,
              60333,
              -1059143953,
              v9,
              v10,
              6);
            v12 = *(_QWORD *)(v2 + 2744);
            *(_BYTE *)(v2 + 4516) = 1;
            sde_encoder_display_failure_notification(v12, 1, v13, v14, v15, v16, v17, v18);
            msm_mode_object_event_notify(v2 + 64, *(_QWORD *)v2, v19, v2 + 4516);
            printk(&unk_2775D5, "_sde_connector_report_panel_dead");
          }
          v11 = -110;
        }
        else
        {
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(0, 0, 0, "Successfully received TE from panel\n");
          v11 = 0;
        }
        sde_evtlog_log(sde_dbg_base_evtlog, "sde_connector_esd_status", 3703, -1, v11, -1059143953, v9, v10, v19[0]);
        result = v11;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
