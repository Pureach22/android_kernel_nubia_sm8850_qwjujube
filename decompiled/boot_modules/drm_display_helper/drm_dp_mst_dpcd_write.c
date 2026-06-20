__int64 __fastcall drm_dp_mst_dpcd_write(__int64 a1, unsigned int a2, __int64 a3, __int64 a4)
{
  return (int)drm_dp_send_dpcd_write(*(_QWORD *)(a1 + 1584), a1 - 48, a2, a4, a3);
}
