unsigned __int64 __fastcall a5xx_snapshot_cp_pm4(_QWORD *a1, _DWORD *a2, unsigned __int64 a3)
{
  __int64 v3; // x9
  unsigned __int64 v4; // x19

  v3 = a1[1789];
  v4 = 4 * v3 + 8;
  if ( v4 <= a3 )
  {
    *a2 = 8;
    a2[1] = v3;
    memcpy(a2 + 2, *(const void **)(a1[1791] + 8LL), 4 * v3);
  }
  else
  {
    if ( (unsigned int)__ratelimit(&a5xx_snapshot_cp_pm4__rs, "a5xx_snapshot_cp_pm4") )
      dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "CP PM4 RAM DEBUG");
    return 0;
  }
  return v4;
}
