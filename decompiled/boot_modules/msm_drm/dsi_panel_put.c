__int64 __fastcall dsi_panel_put(_QWORD *a1)
{
  drm_panel_remove(a1 + 136);
  kfree(a1[225]);
  kfree(a1[224]);
  kfree(a1[223]);
  kfree(a1[222]);
  kfree(a1[221]);
  kfree(a1[218]);
  kfree(a1[251]);
  return kfree(a1);
}
