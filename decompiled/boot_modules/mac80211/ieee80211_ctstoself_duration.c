__int64 __fastcall ieee80211_ctstoself_duration(__int64 a1, __int64 a2, __int64 a3, int *a4)
{
  __int64 v4; // x14
  __int64 v5; // x9
  unsigned __int8 *v6; // x10
  int v7; // w8
  int v8; // w12
  unsigned __int64 v9; // x11
  int v10; // w10
  int v11; // w14
  __int64 result; // x0
  int v13; // w8
  unsigned int v14; // w8

  if ( (a4[1] & 7u) >= 6 )
  {
    __break(0x5512u);
    if ( (v4 & 0x40000000000000LL) != 0 )
      JUMPOUT(0xA51C0);
    return ieee80211_handle_wake_tx_queue();
  }
  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 72) + 8LL * (a4[1] & 7) + 328);
  v6 = (unsigned __int8 *)(*(_QWORD *)(v5 + 8) + 12LL * *((char *)a4 + 20));
  if ( a2 )
  {
    v7 = *(unsigned __int8 *)(a2 + 134);
    if ( *(_BYTE *)(a2 - 968) == 1 )
    {
      v8 = (*v6 >> 4) & 1;
      goto LABEL_7;
    }
  }
  else
  {
    v7 = 0;
  }
  LOBYTE(v8) = 0;
LABEL_7:
  v9 = *((unsigned __int16 *)v6 + 2);
  v10 = *a4;
  if ( (v8 & 1) != 0 || *(_DWORD *)(v5 + 16) == 1 )
  {
    result = 4 * (unsigned int)((4 * v9 + 80 * a3 + 539) / (4 * v9)) + 36;
    if ( (v10 & 4) != 0 )
      return result;
    v14 = 4 * ((4 * (int)v9 + 1339) / (unsigned int)(4 * v9)) + 36;
    return v14 + (unsigned int)result;
  }
  if ( v7 )
    v11 = 106;
  else
    v11 = 202;
  result = (unsigned int)((v9 + 80 * a3 + 319) / v9) + v11;
  if ( (v10 & 4) == 0 )
  {
    if ( v7 )
      v13 = 106;
    else
      v13 = 202;
    v14 = ((int)v9 + 1119) / (unsigned int)v9 + v13;
    return v14 + (unsigned int)result;
  }
  return result;
}
