__int64 __fastcall sub_6CB268(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v4; // w23

  if ( (v4 & 0x4000000) != 0 )
    JUMPOUT(0x6C3D34);
  return wmi_extract_mgmt_rx_mlo_link_removal_info(a1, a2, a3, a4);
}
