__int64 __fastcall hfi_get_hw_caps(__int64 a1)
{
  if ( a1 )
  {
    *(_DWORD *)(a1 + 56) = 0;
    *(_QWORD *)(a1 + 16) = 0x1200000012LL;
    *(_DWORD *)(a1 + 24) = 18;
    *(_QWORD *)(a1 + 32) = 0x1300000013LL;
    *(_DWORD *)(a1 + 40) = 19;
    *(_QWORD *)(a1 + 48) = 0x100000002LL;
    *(_QWORD *)(a1 + 64) = 0x3400000034LL;
    *(_DWORD *)(a1 + 72) = 52;
    *(_DWORD *)(a1 + 80) = 1;
    *(_QWORD *)(a1 + 88) = 0x3500000035LL;
    *(_DWORD *)(a1 + 96) = 53;
    *(_DWORD *)(a1 + 104) = 2;
    *(_QWORD *)(a1 + 112) = 0x3600000036LL;
    *(_DWORD *)(a1 + 120) = 54;
    *(_DWORD *)(a1 + 128) = 3;
    *(_QWORD *)(a1 + 136) = 0x3700000037LL;
    *(_DWORD *)(a1 + 144) = 55;
    *(_DWORD *)(a1 + 152) = 4;
    *(_QWORD *)(a1 + 160) = 0x3800000038LL;
    *(_DWORD *)(a1 + 168) = 56;
    return 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x40000,
      1,
      "hfi_get_hw_caps",
      910,
      "query buf is NULL");
    return 4294967274LL;
  }
}
