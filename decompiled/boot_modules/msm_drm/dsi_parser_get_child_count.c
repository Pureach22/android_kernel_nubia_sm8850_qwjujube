__int64 __fastcall dsi_parser_get_child_count(__int64 a1)
{
  unsigned int v1; // w19

  if ( a1 )
  {
    v1 = *(_DWORD *)(a1 + 192);
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: node %s child count=%d\n", *(const char **)a1, v1);
  }
  else
  {
    return 0;
  }
  return v1;
}
