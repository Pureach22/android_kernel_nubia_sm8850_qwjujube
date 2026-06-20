__int64 __fastcall qcom_show_pmic_model_array(__int64 a1)
{
  __int64 v1; // x8
  int v2; // w22
  __int64 v4; // x24
  int v5; // w25
  __int64 v6; // x8
  const char *v7; // x2

  v1 = *(_QWORD *)(a1 + 128);
  v2 = *(_DWORD *)(v1 + 100);
  if ( v2 )
  {
    v4 = v1 + *(unsigned int *)(v1 + 104);
    v5 = 1;
    do
    {
      v6 = *(unsigned __int16 *)(v4 + 4LL * (v5 - 1));
      if ( (unsigned int)v6 <= 0x53 && (v7 = pmic_models[v6]) != nullptr )
        seq_printf(
          a1,
          "%s %u.%u\n",
          v7,
          HIWORD(*(_DWORD *)(v4 + 4LL * v5)),
          (unsigned __int16)*(_DWORD *)(v4 + 4LL * v5));
      else
        seq_printf(a1, "unknown (%d)\n", *(unsigned __int16 *)(v4 + 4LL * (v5 - 1)));
      --v2;
      v5 += 2;
    }
    while ( v2 );
  }
  return 0;
}
