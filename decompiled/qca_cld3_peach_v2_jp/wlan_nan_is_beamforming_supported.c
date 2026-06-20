__int64 __fastcall wlan_nan_is_beamforming_supported(__int64 a1)
{
  return ucfg_nan_is_beamforming_supported(a1) & 1;
}
