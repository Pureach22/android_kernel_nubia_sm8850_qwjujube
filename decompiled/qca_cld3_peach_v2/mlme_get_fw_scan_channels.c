__int64 __fastcall mlme_get_fw_scan_channels(
        __int64 a1,
        __int64 a2,
        _BYTE *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 ext_hdl; // x0
  int v14; // w8
  __int64 v15; // x8
  const char *v17; // x2
  __int64 v18; // x0

  if ( !a2 )
  {
    v17 = "%s: ROAM: Freq list is NULL";
LABEL_10:
    qdf_trace_msg(0x1Fu, 2u, v17, a4, a5, a6, a7, a8, a9, a10, a11, "mlme_get_fw_scan_channels");
    *a3 = 0;
    return 16;
  }
  ext_hdl = wlan_psoc_mlme_get_ext_hdl(a1);
  if ( !ext_hdl )
  {
    v17 = "%s: Failed to get MLME Obj";
    goto LABEL_10;
  }
  v14 = *(unsigned __int8 *)(ext_hdl + 2152);
  *a3 = v14;
  if ( !v14 )
    return 0;
  v15 = 0;
  while ( v15 != 102 )
  {
    *(_DWORD *)(a2 + 4 * v15) = *(_DWORD *)(ext_hdl + 2156 + 4 * v15);
    if ( ++v15 >= (unsigned __int64)*(unsigned __int8 *)(ext_hdl + 2152) )
      return 0;
  }
  __break(0x5512u);
  v18 = MEMORY[0xFFFFFFFFFA127B24]();
  return wlan_mlme_get_mac_vdev_id(v18);
}
