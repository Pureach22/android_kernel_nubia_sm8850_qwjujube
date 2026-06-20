__int64 __fastcall wlan_dcs_switch_chan(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 v3; // x8
  __int64 v4; // x8
  __int64 comp_private_obj; // x0
  _DWORD *v9; // x8

  v3 = *(_QWORD *)(a1 + 216);
  if ( !v3 )
    return 4;
  v4 = *(_QWORD *)(v3 + 80);
  if ( !v4 )
    return 4;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v4, 0x24u);
  if ( !comp_private_obj )
    return 4;
  v9 = *(_DWORD **)(comp_private_obj + 1168);
  if ( !v9 )
    return 11;
  if ( *(v9 - 1) != 1670170395 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v9)(a1, a2, a3);
}
