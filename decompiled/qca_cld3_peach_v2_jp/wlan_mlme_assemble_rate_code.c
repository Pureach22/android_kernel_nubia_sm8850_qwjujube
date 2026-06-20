__int64 __fastcall wlan_mlme_assemble_rate_code(unsigned __int8 a1, unsigned __int8 a2, unsigned __int8 a3)
{
  if ( (wma_get_fw_wlan_feat_caps(13) & 1) != 0 )
    return (a1 << 8) | (32 * a2) | a3 | 0x10000000u;
  else
    return (16 * a2) | (a1 << 6) | (unsigned int)a3;
}
