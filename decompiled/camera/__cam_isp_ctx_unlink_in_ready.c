__int64 __fastcall _cam_isp_ctx_unlink_in_ready(__int64 a1)
{
  *(_QWORD *)(a1 + 216) = 0;
  *(_DWORD *)(a1 + 64) = -1;
  *(_DWORD *)(a1 + 240) = 2;
  return 0;
}
