__int64 __fastcall dsi_parser_read_string(__int64 a1, char *s2, const char **a3)
{
  __int64 v3; // x21
  const char **v6; // x22
  const char *v7; // x5
  unsigned int v8; // w21

  v3 = *(unsigned int *)(a1 + 24);
  if ( (int)v3 < 1 )
    goto LABEL_8;
  v6 = *(const char ***)(a1 + 16);
  while ( !*v6 || strcmp(*v6, s2) )
  {
    --v3;
    v6 += 5;
    if ( !v3 )
      goto LABEL_8;
  }
  if ( v6 )
  {
    v7 = v6[2];
    v8 = 0;
  }
  else
  {
LABEL_8:
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s not found\n", s2);
    v7 = nullptr;
    v8 = -22;
  }
  *a3 = v7;
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s=%s\n", s2, v7);
  return v8;
}
