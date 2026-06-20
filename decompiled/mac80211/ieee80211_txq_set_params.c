__int64 __fastcall ieee80211_txq_set_params(__int64 result)
{
  _DWORD *v1; // x8
  int v2; // w9
  int v3; // w9
  int v4; // w9

  v1 = *(_DWORD **)(result + 72);
  v2 = v1[351];
  if ( v2 )
  {
    *(_DWORD *)(result + 248) = v2;
    v3 = v1[352];
    if ( v3 )
      goto LABEL_3;
LABEL_6:
    v1[352] = *(_DWORD *)(result + 252);
    v1 = *(_DWORD **)(result + 72);
    v4 = v1[353];
    if ( v4 )
      goto LABEL_4;
    goto LABEL_7;
  }
  v1[351] = *(_DWORD *)(result + 248);
  v1 = *(_DWORD **)(result + 72);
  v3 = v1[352];
  if ( !v3 )
    goto LABEL_6;
LABEL_3:
  *(_DWORD *)(result + 252) = v3;
  v4 = v1[353];
  if ( v4 )
  {
LABEL_4:
    *(_DWORD *)(result + 260) = v4;
    return result;
  }
LABEL_7:
  v1[353] = *(_DWORD *)(result + 260);
  return result;
}
