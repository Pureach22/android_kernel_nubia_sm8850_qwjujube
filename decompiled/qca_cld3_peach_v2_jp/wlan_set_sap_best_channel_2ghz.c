__int64 __fastcall wlan_set_sap_best_channel_2ghz(
        __int64 a1,
        unsigned int **a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 ext_hdl; // x0
  __int64 v13; // x19
  unsigned int v14; // w21
  __int64 v15; // x22
  unsigned int *v16; // x23
  unsigned __int64 v17; // x24
  int v18; // w25
  unsigned int v19; // w26
  const char *v20; // x2

  if ( !a2 )
  {
    v20 = "%s: Invalid channel list";
LABEL_17:
    qdf_trace_msg(0x68u, 2u, v20, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_set_sap_best_channel_2ghz");
    return 4;
  }
  if ( *(_DWORD *)(a1 + 16) != 1 )
    return 4;
  ext_hdl = wlan_vdev_mlme_get_ext_hdl(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !ext_hdl )
  {
    v20 = "%s: vdev legacy private object is NULL";
    goto LABEL_17;
  }
  v13 = ext_hdl;
  v14 = *(unsigned __int8 *)(a1 + 104);
  v15 = ext_hdl + 24540;
  v16 = *a2;
  qdf_mem_set((void *)(ext_hdl + 24540), 0x38u, 0);
  if ( *((_BYTE *)a2 + 8) )
  {
    v17 = 0;
    v18 = 0;
    do
    {
      if ( wlan_reg_is_24ghz_ch_freq(*v16) && (wlan_sap_is_ch_non_overlap(v14, *v16) & 1) != 0 )
      {
        v19 = v16[3];
        if ( v19 < (unsigned int)wlan_sap_get_acs_weight_adjustable(0) && *((_BYTE *)v16 + 20) == 1 )
          *(_DWORD *)(v15 + 4 * v17++) = *v16;
      }
      if ( ++v18 >= (unsigned int)*((unsigned __int8 *)a2 + 8) )
        break;
      v16 += 6;
    }
    while ( v17 < 0xD );
  }
  else
  {
    LOBYTE(v17) = 0;
  }
  *(_BYTE *)(v13 + 24592) = v17;
  return 0;
}
