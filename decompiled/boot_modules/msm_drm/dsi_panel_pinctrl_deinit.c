__int64 __fastcall dsi_panel_pinctrl_deinit(__int64 a1)
{
  if ( (*(_BYTE *)(a1 + 1274) & 1) == 0 )
    devm_pinctrl_put(*(_QWORD *)(a1 + 1616));
  return 0;
}
