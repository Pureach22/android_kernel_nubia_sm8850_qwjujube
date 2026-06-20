__int64 __fastcall dsi_display_set_clk_state(__int64 a1, __int64 a2, __int64 a3)
{
  if ( !a1 )
    goto LABEL_6;
  if ( *(_DWORD *)(*(_QWORD *)(a1 + 168) + 1608LL) == 1 )
    return 0;
  a1 = *(_QWORD *)(a1 + 1328);
  if ( a1 )
    return dsi_display_clk_ctrl(a1, a2, a3);
LABEL_6:
  drm_dev_printk(a1, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid arg\n");
  return 4294967274LL;
}
