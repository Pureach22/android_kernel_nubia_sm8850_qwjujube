__int64 __fastcall sub_1E57B8(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  unsigned int v5; // w27

  return dsi_display_get_panel_scan_line(a1, a2, a3, a4, a5, v5 | ((_DWORD)a2 << 7));
}
