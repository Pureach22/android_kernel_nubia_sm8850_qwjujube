__int64 __fastcall ieee80211_process_rx_twt_action(_QWORD *a1)
{
  __int64 v1; // x8
  __int64 v2; // x9
  unsigned __int8 *v3; // x8
  int v4; // w10
  unsigned __int64 v5; // x9

  v1 = a1[3];
  if ( *(_DWORD *)(v1 + 4720) == 3
    && *(_QWORD *)(*(_QWORD *)(a1[2] + 464LL) + 888LL)
    && *(_BYTE *)(v1 + 4850) == 1
    && a1[5] )
  {
    v2 = a1[1];
    v3 = *(unsigned __int8 **)(v2 + 224);
    v4 = v3[25];
    if ( v4 == 7 )
    {
      if ( *(_DWORD *)(v2 + 112) > 0x1Au )
        return 1;
    }
    else if ( v4 == 6 )
    {
      v5 = *(unsigned int *)(v2 + 112);
      if ( (unsigned int)v5 >= 0x20 && v3[27] == 216 && (unsigned __int64)v3[28] + 29 <= v5 )
        return 1;
    }
  }
  return 0;
}
