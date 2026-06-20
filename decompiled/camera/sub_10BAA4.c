__int64 __fastcall sub_10BAA4(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, int a6)
{
  int v6; // w12
  __int64 v7; // x24

  *(_DWORD *)(v7 + 224) = v6;
  *(_DWORD *)(v7 + 228) = a6;
  return cam_req_mgr_workq_destroy(a1);
}
