__int64 __fastcall wcd9378_soc_codec_remove(__int64 a1)
{
  __int64 v1; // x0
  _QWORD *v2; // x19
  _DWORD *v3; // x8
  __int64 v4; // x0

  v1 = *(_QWORD *)(a1 + 24);
  v2 = *(_QWORD **)(v1 + 152);
  if ( !v2 )
    return dev_err(v1, "%s: wcd9378 is already NULL\n", "wcd9378_soc_codec_remove");
  v3 = (_DWORD *)v2[405];
  if ( v3 )
  {
    v4 = v2[403];
    if ( *(v3 - 1) != -875060373 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD *, _QWORD))v3)(v4, v2 + 400, 0);
  }
  return sdca_devices_debugfs_dentry_remove(v2[43]);
}
