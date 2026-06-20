__int64 __fastcall wlan_objmgr_set_mlo_ctx(__int64 result)
{
  *(_QWORD *)(g_umac_glb_obj + 40) = result;
  return result;
}
