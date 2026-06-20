bool __fastcall policy_mgr_is_pcl_weightage_required(__int64 a1)
{
  __int64 psoc_ext_obj_fl; // x0

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1, "policy_mgr_is_pcl_weightage_required", 3190);
  return !psoc_ext_obj_fl || *(_BYTE *)(psoc_ext_obj_fl + 1104) || *(unsigned __int8 *)(psoc_ext_obj_fl + 1105) == 255;
}
