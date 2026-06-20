__int64 __fastcall sde_connector_fill_modes(__int64 a1)
{
  unsigned int v2; // w20
  unsigned int v3; // w10
  _QWORD *v4; // x9
  unsigned int v5; // w11
  void (__fastcall *v6)(__int64, __int64); // x8
  __int64 v7; // x1

  if ( !a1 )
  {
    printk(&unk_26FEB0, "sde_connector_fill_modes");
    return 0;
  }
  v2 = drm_helper_probe_single_connector_modes();
  v3 = 0;
  v4 = *(_QWORD **)(a1 + 176);
  while ( v4 != (_QWORD *)(a1 + 176) )
  {
    v5 = *((unsigned __int16 *)v4 - 30);
    v4 = (_QWORD *)*v4;
    if ( v3 <= v5 )
      v3 = v5;
  }
  v6 = *(void (__fastcall **)(__int64, __int64))(a1 + 3168);
  *(_DWORD *)(a1 + 5124) = v3;
  if ( v6 )
  {
    v7 = *(_QWORD *)(a1 + 2760);
    if ( *((_DWORD *)v6 - 1) != 1212788166 )
      __break(0x8228u);
    v6(a1, v7);
  }
  if ( (unsigned int)sde_connector_set_blob_data(a1, *(_QWORD *)(a1 + 2512), 1u) )
  {
    printk(&unk_250639, "sde_connector_fill_modes");
    return 0;
  }
  return v2;
}
