__int64 __fastcall cam_unreserve_icp_fw(__int64 a1)
{
  return iounmap(*(_QWORD *)(a1 + 8));
}
