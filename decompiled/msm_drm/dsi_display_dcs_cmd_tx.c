__int64 __fastcall dsi_display_dcs_cmd_tx(__int64 a1)
{
  if ( *(_QWORD *)(a1 + 264) )
    return dsi_panel_dcs_cmd_tx();
  else
    return 4294967274LL;
}
