__int64 __fastcall cscfg_feat_description_show(__int64 a1, __int64 a2)
{
  return (int)scnprintf(a2, 4096, "%s", *(const char **)(*(_QWORD *)(a1 - 8) + 8LL));
}
