__int64 __fastcall cam_cpas_util_translate_client_paths(unsigned int *a1, __int64 a2)
{
  __int64 v2; // x9
  unsigned __int64 v3; // x8
  unsigned int *v4; // x10
  __int64 v5; // x9
  unsigned int v6; // w6

  if ( !a1 )
    return 4294967274LL;
  v2 = *a1;
  if ( !(_DWORD)v2 )
    return 0;
  v3 = 0;
  v4 = a1 + 4;
  v5 = 40 * v2;
  while ( v3 != 600 )
  {
    if ( v4[v3 / 4] <= 0xFF )
      v6 = v4[v3 / 4] & 0x1F;
    else
      v6 = v4[v3 / 4] & 0x1F | 0x20;
    v4[v3 / 4] = v6;
    if ( v6 >= 0x2A )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_util_translate_client_paths",
        1698,
        "index Invalid: %d",
        v6);
      return 4294967274LL;
    }
    v3 += 40LL;
    if ( v5 == v3 )
      return 0;
  }
  __break(0x5512u);
  return cam_cpas_util_apply_default_axi_vote(a1, a2);
}
