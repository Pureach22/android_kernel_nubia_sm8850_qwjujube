__int64 __fastcall cscfg_feat_matches_show(__int64 a1, __int64 a2)
{
  int v3; // w21
  int v4; // w20

  v3 = *(_DWORD *)(*(_QWORD *)(a1 - 8) + 32LL);
  if ( (v3 & 1) == 0 )
  {
    v4 = 0;
    if ( (v3 & 2) == 0 )
      return (int)(scnprintf(a2 + v4, 4096LL - v4, "\n") + v4);
    goto LABEL_5;
  }
  v4 = scnprintf(a2, 4096, "SRC_ALL ");
  if ( (v3 & 2) != 0 )
LABEL_5:
    v4 += scnprintf(a2 + v4, 4096LL - v4, "SRC_ETMV4 ");
  return (int)(scnprintf(a2 + v4, 4096LL - v4, "\n") + v4);
}
