__int64 __fastcall wlan_dp_stc_stop_flow_tracking(__int64 result, __int64 a2)
{
  int v2; // w8

  v2 = *(_DWORD *)(a2 + 16);
  if ( (v2 & 1) == 0 )
  {
    if ( (v2 & 2) == 0 )
      return result;
LABEL_5:
    *(_BYTE *)(**(_QWORD **)(*(_QWORD *)result + 1480LL) + 336LL * *(unsigned __int8 *)(a2 + 34) + 321) = 0;
    return result;
  }
  *(_BYTE *)(*(_QWORD *)(*(_QWORD *)result + 2952LL) + 192LL * *(unsigned __int8 *)(a2 + 32) + 161) = 0;
  if ( (*(_DWORD *)(a2 + 16) & 2) != 0 )
    goto LABEL_5;
  return result;
}
