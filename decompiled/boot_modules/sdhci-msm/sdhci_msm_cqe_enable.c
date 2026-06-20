__int64 __fastcall sdhci_msm_cqe_enable(__int64 a1)
{
  __int64 result; // x0

  result = sdhci_cqe_enable();
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 3328) + 1003LL) & 8) != 0 )
  {
    result = qcom_ice_enable(*(_QWORD *)(a1 + 3304));
    if ( (_DWORD)result )
    {
      result = dev_warn(
                 **(_QWORD **)(a1 + 3328),
                 "Could not enable ICE err=%d, Disabling inline encryption capability.\n",
                 result);
      *(_DWORD *)(*(_QWORD *)(a1 + 3328) + 1000LL) &= ~0x8000000u;
    }
  }
  return result;
}
