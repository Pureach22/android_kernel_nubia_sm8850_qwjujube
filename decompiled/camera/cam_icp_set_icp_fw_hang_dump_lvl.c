__int64 __fastcall cam_icp_set_icp_fw_hang_dump_lvl(__int64 a1, unsigned __int64 a2)
{
  if ( a2 <= 2 )
    *(_QWORD *)(a1 + 44136) = a2;
  return 0;
}
