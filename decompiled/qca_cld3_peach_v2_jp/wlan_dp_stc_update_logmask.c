__int64 __fastcall wlan_dp_stc_update_logmask(__int64 result, int a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(result + 2936);
  if ( v2 )
    *(_DWORD *)(v2 + 148) = a2;
  return result;
}
