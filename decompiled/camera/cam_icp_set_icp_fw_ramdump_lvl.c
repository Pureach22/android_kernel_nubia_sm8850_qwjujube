__int64 __fastcall cam_icp_set_icp_fw_ramdump_lvl(__int64 a1, unsigned __int64 a2)
{
  if ( a2 <= 1 )
    *(_DWORD *)(a1 + 44144) = a2;
  return 0;
}
