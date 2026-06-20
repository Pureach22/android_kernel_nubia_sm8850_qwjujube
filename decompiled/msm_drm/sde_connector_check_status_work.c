__int64 __fastcall sde_connector_check_status_work(__int64 a1)
{
  _QWORD *v1; // x20
  __int64 v2; // x21
  _DWORD *v4; // x8
  __int64 result; // x0
  __int64 v6; // x1
  int v7; // w22
  int v8; // w6
  int v9; // w7
  unsigned int v10; // w8
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x2
  __int64 v15; // x3
  __int64 v16; // x4
  __int64 v17; // x5
  __int64 v18; // x6
  int v19; // w7
  char v20[8]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v1 = (_QWORD *)(a1 - 4408);
  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 == 4408 )
  {
    result = printk(&unk_2742B8, "sde_connector_check_status_work");
  }
  else
  {
    v2 = a1 - 1592;
    mutex_lock(a1 - 1592);
    v4 = *(_DWORD **)(a1 - 1344);
    if ( !v4 || (*(_WORD *)(*(_QWORD *)(*v1 + 8LL) + 268LL) & 0x10) != 0 || *(_DWORD *)(a1 - 1116) == 5 )
    {
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "dpms mode: %d\n", *(_DWORD *)(a1 - 1120));
      result = mutex_unlock(v2);
    }
    else
    {
      v6 = *(_QWORD *)(a1 - 1648);
      if ( *(v4 - 1) != -1195238087 )
        __break(0x8228u);
      v7 = ((__int64 (__fastcall *)(_QWORD *, __int64, _QWORD))v4)(v1, v6, 0);
      result = mutex_unlock(v2);
      if ( v7 < 1 )
      {
        if ( (*(_BYTE *)(a1 + 108) & 1) == 0 )
        {
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "_sde_connector_report_panel_dead",
            3627,
            -1,
            60333,
            -1059143953,
            v8,
            v9,
            6);
          v13 = *(_QWORD *)(a1 - 1664);
          *(_BYTE *)(a1 + 108) = 1;
          sde_encoder_display_failure_notification(v13, 0, v14, v15, v16, v17, v18, v19);
          msm_mode_object_event_notify(a1 - 4344, *v1, v20, a1 + 108);
          result = printk(&unk_2775D5, "_sde_connector_report_panel_dead");
        }
      }
      else
      {
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "esd check status success conn_id: %d enc_id: %d\n",
            *(_DWORD *)(a1 - 4344),
            *(_DWORD *)(*(_QWORD *)(a1 - 1664) + 24LL));
        v10 = *(_DWORD *)(a1 + 104);
        if ( v10 )
          v11 = v10;
        else
          v11 = 5000;
        v12 = _msecs_to_jiffies(v11);
        result = queue_delayed_work_on(32, system_wq, a1, v12);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
