__int64 __fastcall ieee80211_get_num_supported_channels(_QWORD *a1)
{
  __int64 v1; // x9
  __int64 result; // x0
  __int64 v4; // x9
  __int64 v5; // x9
  __int64 v6; // x9
  __int64 v7; // x9
  __int64 v8; // x8

  v1 = a1[41];
  if ( v1 )
  {
    result = *(unsigned int *)(v1 + 20);
    v4 = a1[42];
    if ( !v4 )
      goto LABEL_4;
    goto LABEL_3;
  }
  result = 0;
  v4 = a1[42];
  if ( v4 )
LABEL_3:
    result = (unsigned int)(*(_DWORD *)(v4 + 20) + result);
LABEL_4:
  v5 = a1[43];
  if ( v5 )
    result = (unsigned int)(*(_DWORD *)(v5 + 20) + result);
  v6 = a1[44];
  if ( v6 )
    result = (unsigned int)(*(_DWORD *)(v6 + 20) + result);
  v7 = a1[45];
  if ( v7 )
    result = (unsigned int)(*(_DWORD *)(v7 + 20) + result);
  v8 = a1[46];
  if ( v8 )
    return (unsigned int)(*(_DWORD *)(v8 + 20) + result);
  return result;
}
