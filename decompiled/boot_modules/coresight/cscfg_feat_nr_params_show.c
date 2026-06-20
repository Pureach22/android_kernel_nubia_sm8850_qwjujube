__int64 __fastcall cscfg_feat_nr_params_show(__int64 a1, __int64 a2)
{
  return (int)scnprintf(a2, 4096, "%d\n", *(_DWORD *)(*(_QWORD *)(a1 - 8) + 36LL));
}
