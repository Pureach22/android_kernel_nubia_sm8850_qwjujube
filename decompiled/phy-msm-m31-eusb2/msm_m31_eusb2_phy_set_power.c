__int64 __fastcall msm_m31_eusb2_phy_set_power(__int64 a1, int a2)
{
  if ( !a2 && (*(_BYTE *)(a1 + 471) & 1) != 0 )
    return 0;
  *(_DWORD *)(a1 + 488) = a2;
  queue_work_on(32, system_wq, a1 + 496);
  return 0;
}
