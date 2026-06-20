__int64 __fastcall nbia_android_rvh_wakeup_success(__int64 result, __int64 a2)
{
  if ( (walt_disabled & 1) == 0 )
    return q_scp_work(result, a2);
  return result;
}
