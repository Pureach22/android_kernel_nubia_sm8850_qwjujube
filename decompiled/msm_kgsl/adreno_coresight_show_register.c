__int64 __fastcall adreno_coresight_show_register(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x23
  __int64 v6; // x20
  unsigned int *v7; // x23
  int v8; // w21

  v3 = *(_QWORD *)(a1 + 152);
  v6 = *(_QWORD *)(v3 + 16);
  rt_mutex_lock(v6 + 11088);
  if ( *(_BYTE *)(v3 + 24) == 1 )
  {
    if ( !(unsigned int)adreno_active_count_get(v6) )
    {
      v7 = *(unsigned int **)(a2 + 32);
      v7[2] = kgsl_regmap_read(v6 + 13200, *v7);
      adreno_active_count_put(v6);
    }
    v8 = *(_DWORD *)(*(_QWORD *)(a2 + 32) + 8LL);
  }
  else
  {
    v8 = 0;
  }
  rt_mutex_unlock(v6 + 11088);
  return (int)scnprintf(a3, 4096, "0x%X\n", v8);
}
