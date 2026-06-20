__int64 __fastcall dsi_panel_pinctrl_toggle_te_function(__int64 a1)
{
  unsigned int v1; // w19
  unsigned __int64 v3; // x8
  unsigned __int64 v4; // x1
  __int64 v5; // x19
  __int64 v6; // x9
  int v8; // w0

  if ( (*(_BYTE *)(a1 + 1274) & 1) != 0 )
    return 0;
  v3 = *(_QWORD *)(a1 + 1616);
  v1 = 0;
  if ( v3 )
  {
    if ( v3 <= 0xFFFFFFFFFFFFF000LL )
    {
      v4 = *(_QWORD *)(a1 + 1648);
      v1 = 0;
      if ( v4 )
      {
        if ( v4 <= 0xFFFFFFFFFFFFF000LL )
        {
          v5 = *(_QWORD *)(a1 + 1624);
          if ( !v5 )
          {
            v6 = 1632;
            if ( *(_BYTE *)(a1 + 2024) )
              v6 = 1640;
            v5 = *(_QWORD *)(a1 + v6);
          }
          v8 = pinctrl_select_state(*(_QWORD *)(a1 + 1616), v4);
          if ( v8 )
          {
            v1 = v8;
            drm_dev_printk(
              0,
              &unk_248D72,
              "*ERROR* [msm-dsi-error]: [%s] failed to toggle TE, rc=%d",
              *(const char **)a1,
              v8);
            return v1;
          }
          usleep_range_state(1, 2, 2);
          pinctrl_select_state(*(_QWORD *)(a1 + 1616), v5);
          return 0;
        }
      }
    }
  }
  return v1;
}
