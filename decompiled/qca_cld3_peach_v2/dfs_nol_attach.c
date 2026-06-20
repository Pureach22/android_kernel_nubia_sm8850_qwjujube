__int64 __fastcall dfs_nol_attach(__int64 a1)
{
  __int64 result; // x0
  int v3; // w8

  *(_DWORD *)(a1 + 14632) = 1800;
  *(_QWORD *)(a1 + 14688) = dfs_nol_elem_free_work_cb;
  result = 0;
  *(_QWORD *)(a1 + 14656) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(a1 + 14696) = a1;
  *(_QWORD *)(a1 + 14664) = a1 + 14664;
  *(_QWORD *)(a1 + 14672) = a1 + 14664;
  *(_QWORD *)(a1 + 14680) = _qdf_defer_func;
  *(_QWORD *)(a1 + 14648) = a1 + 14640;
  *(_DWORD *)(a1 + 14960) = 1;
  v3 = *(unsigned __int8 *)(a1 + 80);
  *(_QWORD *)(a1 + 14640) = 0;
  *(_DWORD *)(a1 + 14968) = 0;
  *(_QWORD *)(a1 + 14976) = 0;
  if ( v3 == 1 )
    result = dfs_mlme_nol_alloc_nol(*(_QWORD *)(a1 + 14936));
  *(_QWORD *)(a1 + 72) = result;
  return result;
}
