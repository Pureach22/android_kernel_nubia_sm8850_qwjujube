__int64 __fastcall mlo_mgr_link_switch_deinit(__int64 a1)
{
  _QWORD *v2; // x20
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x0

  if ( a1 )
  {
    v2 = *(_QWORD **)(a1 + 3880);
    v3 = v2[4];
    if ( v3 )
      _qdf_mem_free(v3);
    v4 = v2[10];
    if ( v4 )
      _qdf_mem_free(v4);
    v5 = v2[16];
    if ( v5 )
      _qdf_mem_free(v5);
  }
  _qdf_mem_free(*(_QWORD *)(a1 + 3880));
  *(_QWORD *)(a1 + 3880) = 0;
  return 0;
}
