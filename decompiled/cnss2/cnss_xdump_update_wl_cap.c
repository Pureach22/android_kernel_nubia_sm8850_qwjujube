__int64 __fastcall cnss_xdump_update_wl_cap(__int64 a1, char a2, char a3)
{
  int v3; // w19
  unsigned int v5; // w8

  v3 = *(_DWORD *)(a1 + 6600);
  v5 = *(unsigned __int8 *)(a1 + 7953);
  if ( (v5 & 1) != 0 && ((v5 >> 1) & 1) == a2 && ((v5 >> 2) & 1) == a3 )
    return 0;
  *(_BYTE *)(a1 + 7953) = (4 * (a3 & 1)) | (2 * (a2 & 1)) | v5 & 0xF8 | 1;
  cnss_xdump_update_config(a1);
  return cnss_genl_send_xdump_wlan_arrival((*(_BYTE *)(a1 + 7953) & 2) != 0, (*(_BYTE *)(a1 + 7953) & 4) != 0, 0, v3);
}
