__int64 __fastcall drm_dp_mst_get_edid(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v4; // x0
  __int64 v5; // x20

  v3 = drm_dp_mst_edid_read(a1, a2, a3);
  v4 = drm_edid_raw(v3);
  v5 = drm_edid_duplicate(v4);
  drm_edid_free(v3);
  return v5;
}
