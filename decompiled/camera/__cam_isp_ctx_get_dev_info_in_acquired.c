__int64 __fastcall _cam_isp_ctx_get_dev_info_in_acquired(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  int v3; // w11

  v2 = *(_QWORD *)(a1 + 256);
  v3 = *(_DWORD *)(a1 + 60);
  *(_QWORD *)(a2 + 260) = 0x100000004LL;
  *(_DWORD *)a2 = v3;
  *(_QWORD *)(a2 + 4) = 0x7073692D6D6163LL;
  *(_QWORD *)(a2 + 268) = 0x100000001LL;
  *(_WORD *)(a2 + 276) = 257;
  *(_BYTE *)(v2 + 45753) = 1;
  return 0;
}
