__int64 __fastcall target_if_ipa_intrabss_control_req(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x0
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( a1 && (v1 = *(_QWORD *)(a1 + 2800)) != 0 && (v2 = *(_QWORD *)(v1 + 16)) != 0 )
    result = wmi_unified_vdev_set_param_send(v2);
  else
    result = 16;
  _ReadStatusReg(SP_EL0);
  return result;
}
