__int64 __fastcall dsi_display_config_ctrl_for_cont_splash(__int64 a1)
{
  __int64 v1; // x8
  int v2; // w8
  __int64 result; // x0
  __int64 v5; // x3
  const char *v6; // x2
  unsigned int v8; // w19

  if ( !a1 || (v1 = *(_QWORD *)(a1 + 264)) == 0 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
    return 4294967274LL;
  }
  if ( !*(_QWORD *)(v1 + 1424) )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: no valid mode set for the display\n");
    return 4294967274LL;
  }
  v2 = *(_DWORD *)(a1 + 888);
  if ( v2 != 2 )
  {
    if ( v2 == 1 )
    {
      result = ((__int64 (*)(void))dsi_display_vid_engine_enable)();
      if ( (_DWORD)result )
      {
        v5 = *(_QWORD *)(a1 + 32);
        v6 = "*ERROR* [msm-dsi-error]: [%s]failed to enable DSI video engine, rc=%d\n";
LABEL_14:
        v8 = result;
        drm_dev_printk(0, &unk_248D72, v6, v5, (unsigned int)result);
        return v8;
      }
      return result;
    }
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] Invalid configuration\n", *(const char **)(a1 + 32));
    return 4294967274LL;
  }
  result = dsi_display_cmd_engine_enable(a1);
  if ( (_DWORD)result )
  {
    v5 = *(_QWORD *)(a1 + 32);
    v6 = "*ERROR* [msm-dsi-error]: [%s]failed to enable DSI cmd engine, rc=%d\n";
    goto LABEL_14;
  }
  return result;
}
