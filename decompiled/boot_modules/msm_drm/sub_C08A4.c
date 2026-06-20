__int64 sub_C08A4()
{
  __int64 v0; // x29
  __int128 v1; // q20
  __int128 v2; // q24

  *(_OWORD *)(v0 + 352) = v2;
  *(_OWORD *)(v0 + 368) = v1;
  return dsi_hfi_packetize_panel_cmd();
}
