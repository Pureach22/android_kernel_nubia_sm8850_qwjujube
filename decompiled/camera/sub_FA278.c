__int64 __fastcall sub_FA278(double a1)
{
  __int64 v1; // x30
  __int64 v2; // d8

  *(double *)(v1 + 104) = a1;
  *(_QWORD *)(v1 + 112) = v2;
  return cam_req_mgr_link_properties();
}
