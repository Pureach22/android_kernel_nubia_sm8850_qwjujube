const char **__fastcall dsi_parser_get_child_by_name(__int64 a1, char *s2)
{
  int v3; // w8
  __int64 v4; // x21
  __int64 v5; // x23
  __int64 v6; // x22
  const char **v7; // x20
  const char *v8; // x5

  if ( a1 && (v3 = *(_DWORD *)(a1 + 192)) != 0 )
  {
    v4 = 0;
    v5 = a1 + 32;
    if ( v3 <= 1 )
      v3 = 1;
    v6 = 8LL * (unsigned int)v3;
    while ( 1 )
    {
      if ( v4 == 160 )
      {
        __break(0x5512u);
        JUMPOUT(0x202368);
      }
      v7 = *(const char ***)(v5 + v4);
      if ( !v7 || !strcmp(*v7, s2) )
        break;
      v4 += 8;
      if ( v6 == v4 )
        goto LABEL_10;
    }
  }
  else
  {
LABEL_10:
    v7 = nullptr;
  }
  if ( v7 )
    v8 = "found";
  else
    v8 = "not found";
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: %s\n", s2, v8);
  return v7;
}
