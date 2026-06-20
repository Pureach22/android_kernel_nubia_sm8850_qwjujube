__int64 __fastcall dsi_display_pinctrl_toggle_te_function(__int64 a1)
{
  if ( a1 )
    return dsi_panel_pinctrl_toggle_te_function(*(_QWORD *)(a1 + 264));
  else
    return 4294967274LL;
}
