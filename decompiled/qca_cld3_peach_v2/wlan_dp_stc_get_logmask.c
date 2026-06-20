__int64 __fastcall wlan_dp_stc_get_logmask(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(a1 + 2936);
  if ( v1 )
    return *(unsigned int *)(v1 + 148);
  else
    return 0;
}
