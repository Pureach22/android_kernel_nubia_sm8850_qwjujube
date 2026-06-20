__int64 __fastcall target_if_set_reg_cc_ext_supp(__int64 result, __int64 a2)
{
  __int64 v2; // x19

  if ( result )
  {
    v2 = result;
    result = target_if_reg_is_reg_cc_ext_event_host_supported(a2);
    *(_BYTE *)(v2 + 360) = result & 1;
  }
  return result;
}
