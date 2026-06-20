__int64 __fastcall ucfg_fwol_configure_vdev_params(__int64 a1, __int64 a2)
{
  __int64 v2; // x29
  __int64 v3; // x30
  unsigned __int8 v4; // w19
  __int64 psoc_obj; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v16; // [xsp+8h] [xbp-18h]

  if ( *(_DWORD *)(a2 + 16) != 1 )
    return 0;
  v16 = v3;
  v4 = *(_BYTE *)(a2 + 168);
  psoc_obj = fwol_get_psoc_obj(a1);
  if ( psoc_obj )
    return fwol_set_sap_sho(a1, v4, *(_DWORD *)(psoc_obj + 1312));
  qdf_trace_msg(
    0x66u,
    2u,
    "%s: Failed to get FWOL obj",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "ucfg_fwol_get_sap_sho",
    v2,
    v16);
  return 16;
}
