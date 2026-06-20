__int64 __fastcall sde_connector_get_avail_res_info_shd(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 v4; // x21
  __int64 v5; // x8
  __int64 v7; // x1
  __int64 result; // x0
  __int64 v9; // x8
  void *v10; // x0

  if ( !a1 || !*(_QWORD *)a1 || (v3 = *(_QWORD *)(*(_QWORD *)a1 + 56LL)) == 0 )
  {
    v10 = &unk_242658;
LABEL_14:
    printk(v10, "sde_connector_get_kms");
    return printk(&unk_234896, "sde_connector_get_avail_res_info");
  }
  v4 = *(_QWORD *)(v3 + 8);
  if ( !v4 )
  {
    v10 = &unk_234896;
    goto LABEL_14;
  }
  v5 = *(_QWORD *)(a1 + 2512);
  if ( !v5 || (v7 = *(_QWORD *)(v5 + 16)) == 0 )
    v7 = *(_QWORD *)(a1 + 2272);
  result = sde_rm_get_resource_info((_QWORD *)(v4 + 2144), v7, a2);
  v9 = *(_QWORD *)(v4 + 152);
  if ( (*(_BYTE *)(v9 + 21612) & 1) != 0 && *(_DWORD *)(a1 + 2736) == 10 )
  {
    *(_DWORD *)(a2 + 8) = *(_DWORD *)(v9 + 10392);
    v9 = *(_QWORD *)(v4 + 152);
  }
  *(_DWORD *)(a2 + 24) = *(_DWORD *)(v9 + 21576);
  return result;
}
