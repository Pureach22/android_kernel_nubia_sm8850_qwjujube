__int64 __fastcall drm_dp_dpcd_read_link_status(_QWORD *a1, __int64 a2)
{
  return drm_dp_dpcd_read(a1, 0x202u, a2, 6);
}
