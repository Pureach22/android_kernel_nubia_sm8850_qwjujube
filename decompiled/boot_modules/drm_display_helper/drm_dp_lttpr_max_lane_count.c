__int64 __fastcall drm_dp_lttpr_max_lane_count(__int64 a1)
{
  return *(_BYTE *)(a1 + 4) & 0x1F;
}
