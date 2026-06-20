__int64 __fastcall qcom_sysmon_shutdown_acked(__int64 a1)
{
  if ( a1 )
    return *(_BYTE *)(a1 + 425) & 1;
  else
    return 0;
}
