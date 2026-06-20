size_t __fastcall a5xx_snapshot_cp_pfp(_QWORD *a1, _DWORD *a2, unsigned __int64 a3)
{
  __int64 v3; // x9
  size_t v5; // x2
  size_t v6; // x19

  v3 = a1[1785];
  v5 = 4LL * (int)v3;
  v6 = v5 + 8;
  if ( v5 + 8 <= a3 )
  {
    *a2 = 9;
    a2[1] = v3;
    memcpy(a2 + 2, *(const void **)(a1[1787] + 8LL), v5);
  }
  else
  {
    if ( (unsigned int)__ratelimit(&a5xx_snapshot_cp_pfp__rs, "a5xx_snapshot_cp_pfp") )
      dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "CP PFP RAM DEBUG");
    return 0;
  }
  return v6;
}
