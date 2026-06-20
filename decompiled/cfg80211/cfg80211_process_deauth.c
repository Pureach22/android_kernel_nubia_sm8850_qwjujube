__int64 __fastcall cfg80211_process_deauth(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  __int64 v5; // x1
  unsigned int v7; // w20
  int v8; // w22
  int *v9; // x10
  int v10; // w24
  int v11; // w23
  int v12; // w25
  __int64 result; // x0

  if ( !*(_QWORD *)a1 )
  {
    __break(0x800u);
    JUMPOUT(0x43264);
  }
  v5 = *(_QWORD *)(a1 + 32);
  v7 = *(unsigned __int16 *)(a2 + 24);
  v8 = *(_DWORD *)(a2 + 10);
  v9 = *(int **)(v5 + 1008);
  v10 = *(unsigned __int16 *)(a2 + 14);
  v11 = *v9;
  v12 = *((unsigned __int16 *)v9 + 2);
  result = nl80211_send_deauth(*(_QWORD *)a1 - 992LL, v5, a2, a3, a4 & 1, 3264);
  if ( (*(_BYTE *)(a1 + 164) & 1) != 0
    && !(*(_DWORD *)(a2 + 16) ^ *(_DWORD *)(a1 + 280) | *(unsigned __int16 *)(a2 + 20) ^ *(unsigned __int16 *)(a1 + 284)) )
  {
    _cfg80211_disconnected(*(_QWORD *)(a1 + 32), 0, 0, v7, (v11 ^ v8 | v12 ^ v10) != 0);
    return cfg80211_sme_deauth(a1);
  }
  return result;
}
