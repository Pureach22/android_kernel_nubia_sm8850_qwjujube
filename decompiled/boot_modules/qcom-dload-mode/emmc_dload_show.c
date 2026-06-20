__int64 __fastcall emmc_dload_show(__int64 a1, __int64 a2, __int64 a3)
{
  _DWORD *v3; // x8

  v3 = *(_DWORD **)(a1 + 104);
  if ( v3 )
    return (int)scnprintf(a3, 4096, "%u\n", *v3 == 2);
  else
    return -19;
}
