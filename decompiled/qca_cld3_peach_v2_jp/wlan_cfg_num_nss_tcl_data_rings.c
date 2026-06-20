__int64 __fastcall wlan_cfg_num_nss_tcl_data_rings(__int64 a1)
{
  if ( (*(_BYTE *)(a1 + 540) & 1) != 0 )
    return 1;
  else
    return *(unsigned int *)(a1 + 24);
}
