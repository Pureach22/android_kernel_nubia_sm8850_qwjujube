__int64 __fastcall _cam_isp_ctx_stop_dev_in_activated(__int64 a1, __int64 a2)
{
  __int64 v3; // x20

  v3 = *(_QWORD *)(a1 + 256) + 45056LL;
  _cam_isp_ctx_stop_dev_in_activated_unlock(a1, a2);
  *(_BYTE *)(v3 + 685) = 0;
  *(_DWORD *)(v3 + 700) = 0;
  *(_DWORD *)(a1 + 240) = 2;
  return 0;
}
