__int64 __fastcall aggregated_max_gpuclk_show(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w8

  v3 = *(_DWORD *)(a1 - 12600);
  if ( v3 < 0x20 )
    return (int)scnprintf(a3, 4096, "%d\n", *(_DWORD *)(a1 + 28LL * v3 - 14520));
  __break(0x5512u);
  return dcvs_tunables_default_show();
}
