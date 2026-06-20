__int64 __fastcall ieee80211_adjust_monitor_flags(__int64 result, int a2)
{
  int v2; // w9
  _DWORD *v3; // x8
  int v4; // w11

  v2 = *(_DWORD *)(result + 2264);
  v3 = *(_DWORD **)(result + 1616);
  if ( (v2 & 2) != 0 )
  {
    v3[332] += a2;
    if ( (v2 & 4) == 0 )
    {
LABEL_3:
      if ( (v2 & 8) == 0 )
        goto LABEL_4;
      goto LABEL_8;
    }
  }
  else if ( (v2 & 4) == 0 )
  {
    goto LABEL_3;
  }
  v3[333] += a2;
  if ( (v2 & 8) == 0 )
  {
LABEL_4:
    if ( (v2 & 0x10) == 0 )
      return result;
LABEL_9:
    v3[335] += a2;
    return result;
  }
LABEL_8:
  v4 = v3[336] + a2;
  v3[334] += a2;
  v3[336] = v4;
  if ( (v2 & 0x10) != 0 )
    goto LABEL_9;
  return result;
}
