__int64 __fastcall gsi_rndis_class_id_show(__int64 a1, __int64 a2)
{
  return (int)scnprintf(a2, 4096, "%d\n", *(_DWORD *)(*(_QWORD *)(a1 + 176) + 280LL));
}
