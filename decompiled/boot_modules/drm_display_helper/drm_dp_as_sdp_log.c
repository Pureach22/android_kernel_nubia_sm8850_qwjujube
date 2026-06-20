__int64 __fastcall drm_dp_as_sdp_log(__int64 a1, __int64 a2)
{
  drm_printf(a1, "DP SDP: AS_SDP, revision %u, length %u\n", *(unsigned __int8 *)(a2 + 1), *(unsigned __int8 *)(a2 + 2));
  drm_printf(a1, "    vtotal: %d\n", *(_DWORD *)(a2 + 4));
  drm_printf(a1, "    target_rr: %d\n", *(_DWORD *)(a2 + 8));
  drm_printf(a1, "    duration_incr_ms: %d\n", *(_DWORD *)(a2 + 12));
  drm_printf(a1, "    duration_decr_ms: %d\n", *(_DWORD *)(a2 + 16));
  return drm_printf(a1, "    operation_mode: %d\n", *(_DWORD *)(a2 + 24));
}
