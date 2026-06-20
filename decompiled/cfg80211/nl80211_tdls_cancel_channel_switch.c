__int64 __fastcall nl80211_tdls_cancel_channel_switch(__int64 a1, _QWORD *a2)
{
  _BYTE *v2; // x19
  int v3; // w9
  void (__fastcall *v4)(_QWORD); // x9

  v2 = (_BYTE *)a2[6];
  if ( !*(_QWORD *)(*(_QWORD *)v2 + 768LL) )
    return 4294967201LL;
  if ( !*(_QWORD *)(*(_QWORD *)v2 + 776LL) )
    return 4294967201LL;
  if ( (v2[1103] & 0x10) == 0 )
    return 4294967201LL;
  v3 = *(_DWORD *)(*(_QWORD *)(a2[7] + 992LL) + 8LL);
  if ( v3 != 8 && v3 != 2 )
    return 4294967201LL;
  if ( !*(_QWORD *)(a2[4] + 48LL) )
    return 4294967274LL;
  v4 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)v2 + 776LL);
  if ( *((_DWORD *)v4 - 1) != 1600455713 )
    __break(0x8229u);
  v4(v2 + 992);
  return 0;
}
