__int64 __fastcall sde_connector_set_prop_dyn_transfer_time(__int64 result)
{
  __int64 (__fastcall *v1)(_QWORD); // x8
  __int64 v2; // x0

  v1 = *(__int64 (__fastcall **)(_QWORD))(result + 3224);
  if ( v1 )
  {
    v2 = *(_QWORD *)(result + 2760);
    if ( *((_DWORD *)v1 - 1) != 19073560 )
      __break(0x8228u);
    result = v1(v2);
    if ( (_DWORD)result )
      return printk(&unk_21E029, "_sde_connector_set_prop_dyn_transfer_time");
  }
  return result;
}
