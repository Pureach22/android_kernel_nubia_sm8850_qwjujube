__int64 __fastcall dsi_display_ctrl_host_disable(__int64 a1)
{
  __int64 v1; // x19
  char v2; // w21
  unsigned int v3; // w8
  __int64 v4; // x9
  __int64 v5; // x9
  bool v6; // w8
  unsigned int v7; // w22
  _QWORD *v8; // x20
  __int64 v9; // x10
  __int64 v10; // x0
  int v11; // w0
  __int64 v12; // x0
  int v13; // w0
  unsigned int updated; // w20

  v1 = a1;
  if ( a1 )
  {
    if ( (*(_BYTE *)(a1 + 64) & 1) != 0 )
    {
      v2 = 1;
      v3 = *(_DWORD *)(a1 + 160);
      if ( !v3 )
        goto LABEL_15;
    }
    else
    {
      v2 = *(_BYTE *)(a1 + 1641);
      v3 = *(_DWORD *)(a1 + 160);
      if ( !v3 )
      {
LABEL_15:
        v6 = 1;
        goto LABEL_16;
      }
    }
  }
  else
  {
    v2 = 0;
    v3 = 2747831;
  }
  v4 = *(_QWORD *)(a1 + 168);
  if ( v4 && *(_BYTE *)(v4 + 2848) == 1 )
  {
    _flush_workqueue(*(_QWORD *)(a1 + 1624));
    a1 = cancel_work_sync(*(_QWORD *)(v1 + 168) + 2808LL);
    *(_BYTE *)(*(_QWORD *)(v1 + 168) + 2848LL) = 0;
    v3 = *(_DWORD *)(v1 + 160);
  }
  if ( v3 >= 2 )
  {
    v5 = *(_QWORD *)(v1 + 216);
    if ( v5 )
    {
      if ( *(_BYTE *)(v5 + 2848) == 1 )
      {
        _flush_workqueue(*(_QWORD *)(v1 + 1624));
        a1 = cancel_work_sync(*(_QWORD *)(v1 + 216) + 2808LL);
        *(_BYTE *)(*(_QWORD *)(v1 + 216) + 2848LL) = 0;
        v3 = *(_DWORD *)(v1 + 160);
      }
    }
  }
  v6 = v3 == 0;
LABEL_16:
  v7 = *(_DWORD *)(v1 + 840);
  if ( v7 <= 2 )
  {
    v8 = (_QWORD *)(v1 + 168 + 48LL * v7);
    if ( *(_BYTE *)(*(_QWORD *)(v1 + 264) + 1962LL) != 1 )
      goto LABEL_20;
    v9 = *(unsigned int *)(*v8 + 1608LL);
    if ( (unsigned int)v9 <= 2 )
    {
      if ( !*(_QWORD *)(v8[3] + 8 * v9 + 512) )
      {
        if ( v6 )
        {
          return 0;
        }
        else
        {
          updated = dsi_ctrl_update_host_state(*(_QWORD *)(v1 + 168), 3, 0);
          if ( updated )
            _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: host state update failed %d\n", updated);
          if ( *(_DWORD *)(v1 + 160) >= 2u )
          {
            updated = dsi_ctrl_update_host_state(*(_QWORD *)(v1 + 216), 3, 0);
            if ( updated )
              _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: host state update failed %d\n", updated);
          }
        }
        return updated;
      }
LABEL_20:
      if ( !v6 )
      {
        if ( v7 )
        {
          v10 = *(_QWORD *)(v1 + 168);
          if ( v10 )
          {
            v11 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))dsi_ctrl_set_host_engine_state)(v10, 0, v2 & 1);
            if ( v11 )
              drm_dev_printk(
                0,
                &unk_248D72,
                "*ERROR* [msm-dsi-error]: [%s] disable host engine failed, skip_op:%d rc:%d\n",
                *(const char **)(v1 + 32),
                v2 & 1,
                v11);
          }
        }
        if ( *(_DWORD *)(v1 + 160) >= 2u && v7 != 1 )
        {
          v12 = *(_QWORD *)(v1 + 216);
          if ( v12 )
          {
            v13 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))dsi_ctrl_set_host_engine_state)(v12, 0, v2 & 1);
            if ( v13 )
              drm_dev_printk(
                0,
                &unk_248D72,
                "*ERROR* [msm-dsi-error]: [%s] disable host engine failed, skip_op:%d rc:%d\n",
                *(const char **)(v1 + 32),
                v2 & 1,
                v13);
          }
        }
      }
      updated = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD))dsi_ctrl_set_host_engine_state)(*v8, 0, v2 & 1);
      if ( updated )
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: [%s] disable mhost engine failed, skip_op:%d rc:%d\n",
          *(const char **)(v1 + 32),
          v2 & 1,
          updated);
      return updated;
    }
  }
  __break(0x5512u);
  return dsi_display_ctrl_deinit(a1);
}
