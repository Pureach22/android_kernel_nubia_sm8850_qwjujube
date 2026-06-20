__int64 __fastcall ieee80211_txq_get_depth(__int64 result, _QWORD *a2, _QWORD *a3)
{
  __int64 *v3; // x10
  int v4; // w8
  int v5; // w11
  int v6; // w12

  v3 = *(__int64 **)(result - 32);
  if ( v3 != (__int64 *)(result - 32) )
  {
    v4 = 0;
    v5 = 0;
    do
    {
      v6 = *((_DWORD *)v3 + 28);
      v3 = (__int64 *)*v3;
      ++v5;
      v4 += v6;
    }
    while ( v3 != (__int64 *)(result - 32) );
    if ( !a2 )
      goto LABEL_6;
    goto LABEL_5;
  }
  v5 = 0;
  v4 = 0;
  if ( a2 )
LABEL_5:
    *a2 = (unsigned int)(*(_DWORD *)(result - 124) + v5);
LABEL_6:
  if ( a3 )
    *a3 = (unsigned int)(*(_DWORD *)(result - 128) + v4);
  return result;
}
