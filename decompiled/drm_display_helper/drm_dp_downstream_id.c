__int64 __fastcall drm_dp_downstream_id(_QWORD *a1, __int64 a2)
{
  return drm_dp_dpcd_read(a1, 0x503u, a2, 6);
}
