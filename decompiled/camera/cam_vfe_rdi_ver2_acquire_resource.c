__int64 __fastcall cam_vfe_rdi_ver2_acquire_resource(__int64 a1, __int64 a2)
{
  __int64 v2; // x10

  v2 = *(_QWORD *)(a1 + 24);
  *(_QWORD *)(v2 + 64) = *(_QWORD *)(a2 + 24);
  *(_QWORD *)(v2 + 72) = *(_QWORD *)(a2 + 16);
  *(_DWORD *)(v2 + 22644) = *(_DWORD *)(a2 + 80);
  *(_BYTE *)(a1 + 144) = 0;
  return 0;
}
