__int64 __fastcall current_governor_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x20
  int v5; // w8
  int v6; // w20
  int v8; // w0
  int v9; // w8

  v3 = *(_QWORD *)(a1 + 152);
  v5 = *(_DWORD *)(v3 + 272);
  if ( !v5 )
  {
    v8 = scnprintf(a3, 4096, "%s\n", "FREQ_MON_GOV");
    v9 = *(_DWORD *)(v3 + 272);
    v6 = v8;
    if ( v9 != 1 )
      return v6;
    goto LABEL_3;
  }
  v6 = 0;
  if ( v5 == 1 )
LABEL_3:
    v6 += scnprintf(a3 + v6, 4096LL - v6, "%s\n", "BW_MON_RATIO_GOV");
  return v6;
}
