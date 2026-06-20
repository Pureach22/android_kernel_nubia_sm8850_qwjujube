__int64 __fastcall sdhci_msm_writeb(__int64 a1, unsigned int a2, int a3)
{
  unsigned int v6; // w0
  __int64 v7; // x1
  unsigned int v8; // w20
  __int64 result; // x0

  v6 = _sdhci_msm_check_write(a1, (unsigned __int8)a2);
  v7 = *(_QWORD *)(a1 + 24) + a3;
  v8 = v6;
  result = writeb_relaxed(a2, v7);
  if ( v8 )
    return sdhci_msm_check_power_status(a1, v8);
  return result;
}
