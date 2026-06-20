__int64 __fastcall msm_vidc_add_capid_to_fw_list(__int64 result, unsigned int a2)
{
  __int64 v2; // x9
  __int64 v3; // x20

  v2 = result + 4056;
  do
  {
    v2 = *(_QWORD *)v2;
    if ( v2 == result + 4056 )
      return add_node_list(result + 4056);
  }
  while ( *(_DWORD *)(v2 + 16) != a2 );
  if ( result )
  {
    if ( (msm_vidc_debug & 4) != 0 )
    {
      v3 = result;
      cap_name(a2);
      printk(&unk_81060, "low ", v3 + 340, "msm_vidc_add_capid_to_fw_list", a2);
    }
    return 0;
  }
  return result;
}
