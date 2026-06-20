__int64 __fastcall _cam_isp_ctx_unlink_in_acquired(__int64 a1)
{
  _DWORD *v1; // x9

  v1 = *(_DWORD **)(a1 + 256);
  *(_QWORD *)(a1 + 216) = 0;
  *(_DWORD *)(a1 + 64) = -1;
  v1 += 11264;
  v1[136] = -1;
  v1[158] = 0;
  v1[159] = 0;
  return 0;
}
