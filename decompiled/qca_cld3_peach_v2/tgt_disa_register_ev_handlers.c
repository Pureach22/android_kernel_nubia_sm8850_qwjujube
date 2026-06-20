__int64 __fastcall tgt_disa_register_ev_handlers(__int64 a1)
{
  __int64 (__fastcall *v2)(_QWORD); // x8

  v2 = *(__int64 (__fastcall **)(_QWORD))(wlan_objmgr_psoc_get_comp_private_obj(a1, 0x15u) + 16);
  if ( !v2 )
    return 0;
  if ( *((_DWORD *)v2 - 1) != -770124015 )
    __break(0x8228u);
  return v2(a1);
}
