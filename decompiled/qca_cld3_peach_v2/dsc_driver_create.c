__int64 __fastcall dsc_driver_create(__int64 *a1)
{
  __int64 v2; // x0
  __int64 v3; // x20

  if ( !a1 )
    return 4;
  *a1 = 0;
  v2 = _qdf_mem_malloc(0x78u, "__dsc_driver_create", 48);
  if ( !v2 )
    return 2;
  *(_DWORD *)v2 = 0;
  v3 = v2;
  *(_QWORD *)(v2 + 8) = 0;
  *(_QWORD *)(v2 + 16) = v2 + 16;
  *(_QWORD *)(v2 + 24) = v2 + 16;
  *(_QWORD *)(v2 + 32) = 0;
  _dsc_trans_init((_QWORD *)(v2 + 40));
  _dsc_ops_init((_DWORD *)(v3 + 72));
  *a1 = v3;
  return 0;
}
