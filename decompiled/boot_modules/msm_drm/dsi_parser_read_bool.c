__int64 __fastcall dsi_parser_read_bool(__int64 a1, char *s2)
{
  __int64 v2; // x21
  const char **v4; // x22
  const char *v5; // x20

  v2 = *(unsigned int *)(a1 + 24);
  if ( (int)v2 < 1 )
  {
    LODWORD(v2) = 0;
    v5 = "not set";
  }
  else
  {
    v4 = *(const char ***)(a1 + 16);
    v5 = "not set";
    while ( !*v4 || strcmp(*v4, s2) )
    {
      --v2;
      v4 += 5;
      if ( !v2 )
        goto LABEL_10;
    }
    LODWORD(v2) = v4 != nullptr;
    if ( v4 )
      v5 = (const char *)&unk_214726;
  }
LABEL_10:
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s=%s\n", s2, v5);
  return (unsigned int)v2;
}
