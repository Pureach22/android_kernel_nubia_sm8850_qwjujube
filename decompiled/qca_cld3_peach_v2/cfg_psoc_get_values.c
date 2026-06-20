__int64 __fastcall cfg_psoc_get_values(__int64 a1)
{
  return *(_QWORD *)wlan_objmgr_psoc_get_comp_private_obj(a1, 7) + 28LL;
}
