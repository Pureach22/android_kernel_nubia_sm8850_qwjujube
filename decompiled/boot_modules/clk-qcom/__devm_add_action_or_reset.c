__int64 __fastcall _devm_add_action_or_reset(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  unsigned int v4; // w20

  result = _devm_add_action(a1, qcom_cc_gdsc_unregister, a2, "qcom_cc_gdsc_unregister");
  if ( (_DWORD)result )
  {
    v4 = result;
    gdsc_unregister(a2);
    return v4;
  }
  return result;
}
