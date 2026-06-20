__int64 __fastcall msm_ext_disp_device_ctl_info(__int64 a1, __int64 a2)
{
  *(_DWORD *)(a2 + 64) = 2;
  *(_DWORD *)(a2 + 72) = 2;
  return 0;
}
