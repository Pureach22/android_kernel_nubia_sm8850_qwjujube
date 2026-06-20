__int64 __fastcall drm_dp_mst_connector_late_register(__int64 a1, __int64 a2)
{
  __int64 v4; // x8
  __int64 v5; // x1

  v4 = *(_QWORD *)(*(_QWORD *)(a2 + 1632) + 104LL);
  if ( v4 )
    v5 = *(_QWORD *)(v4 + 8);
  else
    v5 = 0;
  _drm_dev_dbg(0, v5, 2, "registering %s remote bus for %s\n", *(const char **)(a2 + 48), **(const char ***)(a1 + 8));
  *(_QWORD *)(a2 + 1296) = *(_QWORD *)(a1 + 8);
  return 0;
}
