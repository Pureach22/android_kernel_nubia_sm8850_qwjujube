__int64 __fastcall tgt_set_interop_issues_ap_req(__int64 a1, __int64 a2)
{
  __int64 comp_private_obj; // x0
  __int64 (__fastcall *v5)(__int64, __int64); // x8

  if ( !a1 )
    return 29;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Fu);
  if ( !comp_private_obj )
    return 29;
  v5 = *(__int64 (__fastcall **)(__int64, __int64))(comp_private_obj + 32);
  if ( !v5 )
    return 29;
  if ( *((_DWORD *)v5 - 1) != -556254236 )
    __break(0x8228u);
  return v5(a1, a2);
}
