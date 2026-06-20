__int64 __fastcall cscfg_cfg_values_show(__int64 a1, __int64 a2)
{
  __int64 v2; // x23
  __int64 v4; // x24
  __int64 v5; // x22
  int v6; // w25
  __int64 named_feat_desc; // x0
  __int64 v8; // x21
  __int64 v9; // x28
  __int64 v10; // x27
  int v11; // w0

  v2 = *(_QWORD *)(a1 - 8);
  if ( !*(_DWORD *)(v2 + 48) )
    return 0;
  if ( *(int *)(v2 + 32) < 1 )
  {
    v5 = 0;
  }
  else
  {
    v4 = 0;
    v5 = 0;
    v6 = *(_DWORD *)(v2 + 52) * (*(_DWORD *)(a1 - 16) - 1);
    do
    {
      named_feat_desc = cscfg_get_named_feat_desc(*(_QWORD *)(*(_QWORD *)(v2 + 40) + 8 * v4));
      if ( *(int *)(named_feat_desc + 36) >= 1 )
      {
        v8 = named_feat_desc;
        v9 = 0;
        v10 = 0;
        do
        {
          v11 = scnprintf(
                  a2 + v5,
                  4096 - v5,
                  "%s.%s = 0x%llx ",
                  *(const char **)v8,
                  *(const char **)(*(_QWORD *)(v8 + 40) + v9),
                  *(_QWORD *)(*(_QWORD *)(v2 + 56) + 8LL * (v6 + (int)v10++)));
          v5 += v11;
          v9 += 16;
        }
        while ( v10 < *(int *)(v8 + 36) );
        v6 += v10;
      }
      ++v4;
    }
    while ( v4 < *(int *)(v2 + 32) );
  }
  return v5 + (int)scnprintf(a2 + v5, 4096 - v5, "\n");
}
