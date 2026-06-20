__int64 __fastcall dsi_display_cmd_engine_enable(__int64 a1)
{
  __int64 v1; // x24
  _QWORD *v2; // x23
  unsigned int v4; // w19
  int v5; // w0
  unsigned int v6; // w21
  unsigned int v7; // w8
  __int64 v8; // x0

  v1 = *(unsigned int *)(a1 + 840);
  if ( (unsigned int)v1 < 3 )
  {
    v2 = (_QWORD *)(a1 + 168);
    v4 = *(unsigned __int8 *)(a1 + 1641);
    mutex_lock(*(_QWORD *)(a1 + 168 + 48 * v1) + 32LL);
    v5 = ((__int64 (__fastcall *)(_QWORD, __int64, _QWORD))dsi_ctrl_set_cmd_engine_state)(v2[6 * v1], 1, v4);
    if ( v5 )
    {
      v6 = v5;
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] enable mcmd engine failed, skip_op:%d rc:%d\n",
        *(const char **)(a1 + 32),
        v4,
        v5);
LABEL_15:
      mutex_unlock(v2[6 * v1] + 32LL);
      return v6;
    }
    v7 = *(_DWORD *)(a1 + 160);
    if ( v7 )
    {
      if ( (_DWORD)v1 && *v2 )
      {
        v6 = ((__int64 (__fastcall *)(_QWORD, __int64, _QWORD))dsi_ctrl_set_cmd_engine_state)(*v2, 1, v4);
        if ( v6 )
        {
LABEL_13:
          drm_dev_printk(
            0,
            &unk_248D72,
            "*ERROR* [msm-dsi-error]: [%s] enable cmd engine failed, skip_op:%d rc:%d\n",
            *(const char **)(a1 + 32),
            v4,
            v6);
          ((void (__fastcall *)(_QWORD, _QWORD, _QWORD))dsi_ctrl_set_cmd_engine_state)(v2[6 * v1], 0, v4);
          goto LABEL_15;
        }
        v7 = *(_DWORD *)(a1 + 160);
      }
      if ( v7 >= 2 )
      {
        v6 = 0;
        if ( (_DWORD)v1 == 1 )
          goto LABEL_15;
        v8 = *(_QWORD *)(a1 + 216);
        if ( !v8 )
          goto LABEL_15;
        v6 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))dsi_ctrl_set_cmd_engine_state)(v8, 1, v4);
        if ( !v6 )
          goto LABEL_15;
        goto LABEL_13;
      }
    }
    v6 = 0;
    goto LABEL_15;
  }
  __break(0x5512u);
  return dsi_host_alloc_cmd_tx_buffer(a1);
}
