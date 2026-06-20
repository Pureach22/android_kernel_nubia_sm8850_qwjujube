__int64 __fastcall drm_dp_mst_connector_early_unregister(__int64 a1, __int64 a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(*(_QWORD *)(a2 + 1632) + 104LL);
  if ( v2 )
    v2 = *(_QWORD *)(v2 + 8);
  return _drm_dev_dbg(
           0,
           v2,
           2,
           "unregistering %s remote bus for %s\n",
           *(const char **)(a2 + 48),
           **(const char ***)(a1 + 8));
}
