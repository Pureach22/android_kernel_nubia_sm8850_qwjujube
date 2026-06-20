__int64 __fastcall target_if_ipa_uc_offload_control_req(__int64 a1)
{
  __int64 v1; // x8

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 2800);
    if ( v1 )
      a1 = *(_QWORD *)(v1 + 16);
    else
      a1 = 0;
  }
  return wmi_unified_ipa_offload_control_cmd(a1);
}
