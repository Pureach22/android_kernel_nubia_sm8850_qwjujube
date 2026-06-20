__int64 __fastcall sub_1AA2E8(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v4; // s27

  *(_DWORD *)(a4 + 52) = v4;
  *(_DWORD *)(a4 + 56) = v4;
  return target_if_vdev_mgr_create_send(a1, a2, a3, a4 + 52);
}
