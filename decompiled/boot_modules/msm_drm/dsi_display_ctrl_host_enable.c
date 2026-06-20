__int64 __fastcall dsi_display_ctrl_host_enable(__int64 a1)
{
  char v2; // w21
  __int64 v3; // x24
  _QWORD *v4; // x23
  int v5; // w0
  unsigned int v6; // w20
  unsigned int v7; // w8
  __int64 v8; // x0

  if ( a1 )
  {
    if ( (*(_BYTE *)(a1 + 64) & 1) != 0 )
      v2 = 1;
    else
      v2 = *(_BYTE *)(a1 + 1641);
  }
  else
  {
    v2 = 0;
  }
  v3 = *(unsigned int *)(a1 + 840);
  if ( (unsigned int)v3 < 3 )
  {
    v4 = (_QWORD *)(a1 + 168);
    v5 = ((__int64 (__fastcall *)(_QWORD, __int64, _QWORD))dsi_ctrl_set_host_engine_state)(
           *(_QWORD *)(a1 + 168 + 48 * v3),
           1,
           v2 & 1);
    if ( v5 )
    {
      v6 = v5;
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s]enable host engine failed, skip_op:%d rc:%d\n",
        *(const char **)(a1 + 32),
        v2 & 1,
        v5);
      return v6;
    }
    v7 = *(_DWORD *)(a1 + 160);
    if ( v7 )
    {
      if ( (_DWORD)v3 && *v4 )
      {
        v6 = ((__int64 (__fastcall *)(_QWORD, __int64, _QWORD))dsi_ctrl_set_host_engine_state)(*v4, 1, v2 & 1);
        if ( v6 )
        {
LABEL_18:
          drm_dev_printk(
            0,
            &unk_248D72,
            "*ERROR* [msm-dsi-error]: [%s] enable host engine failed, skip_op:%d rc:%d\n",
            *(const char **)(a1 + 32),
            v2 & 1,
            v6);
          ((void (__fastcall *)(_QWORD, _QWORD, _QWORD))dsi_ctrl_set_host_engine_state)(v4[6 * v3], 0, v2 & 1);
          return v6;
        }
        v7 = *(_DWORD *)(a1 + 160);
      }
      if ( v7 >= 2 )
      {
        v6 = 0;
        if ( (_DWORD)v3 == 1 )
          return v6;
        v8 = *(_QWORD *)(a1 + 216);
        if ( !v8 )
          return v6;
        v6 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))dsi_ctrl_set_host_engine_state)(v8, 1, v2 & 1);
        if ( !v6 )
          return v6;
        goto LABEL_18;
      }
    }
    return 0;
  }
  __break(0x5512u);
  return dsi_display_ctrl_host_disable(a1);
}
