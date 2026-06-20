__int64 __fastcall dsi_parser_free_mem(__int64 result, __int64 a2)
{
  __int64 v3; // x20
  char *v4; // x0
  __int64 v5; // x22
  __int64 v6; // x23
  __int64 v7; // x24
  __int64 v8; // x21

  if ( a2 )
  {
    v3 = result;
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: node=%s, prop_count=%d\n", *(const char **)a2, *(_DWORD *)(a2 + 24));
    if ( *(int *)(a2 + 24) >= 1 )
    {
      v5 = 0;
      v6 = 0;
      do
      {
        v7 = *(_QWORD *)(a2 + 16);
        if ( v7 + v5 )
        {
          _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: deleting prop=%s\n", *(const char **)(v7 + v5));
          if ( *(_QWORD *)(v7 + v5 + 24) )
            v4 = (char *)devm_kfree(v3);
          if ( *(_QWORD *)(v7 + v5 + 8) )
            v4 = (char *)devm_kfree(v3);
          if ( (unsigned int)(*(_DWORD *)(v7 + v5 + 32) - 2) <= 2 && *(_QWORD *)(v7 + v5 + 16) )
            v4 = (char *)devm_kfree(v3);
        }
        ++v6;
        v5 += 40;
      }
      while ( v6 < *(int *)(a2 + 24) );
    }
    if ( *(_QWORD *)(a2 + 16) )
      v4 = (char *)devm_kfree(v3);
    if ( *(int *)(a2 + 192) < 1 )
    {
      return devm_kfree(v3);
    }
    else
    {
      v8 = 0;
      while ( v8 != 20 )
      {
        v4 = (char *)dsi_parser_free_mem(v3, *(_QWORD *)(a2 + 32 + 8 * v8++));
        if ( v8 >= *(int *)(a2 + 192) )
          return devm_kfree(v3);
      }
      __break(0x5512u);
      return dsi_parser_count(v4);
    }
  }
  return result;
}
