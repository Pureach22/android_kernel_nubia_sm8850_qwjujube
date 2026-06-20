__int64 __fastcall dcvs_tuning_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8

  v3 = *(unsigned int *)(a2 + 32);
  if ( (unsigned int)v3 < 0x11 )
    return (int)scnprintf(a3, 4096, "%d\n", *(_DWORD *)(a1 + 8 * v3 + 192));
  __break(0x5512u);
  return dcvs_tuning_store();
}
