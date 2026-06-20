__int64 __fastcall glink_probe_spss_unreg(__int64 a1)
{
  __int64 result; // x0

  result = *(_QWORD *)(a1 + 48);
  if ( result )
    result = qcom_glink_spss_unregister();
  *(_QWORD *)(a1 + 48) = 0;
  return result;
}
