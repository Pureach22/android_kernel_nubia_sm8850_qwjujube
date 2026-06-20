__int64 __fastcall lpass_cdc_soc_codec_remove(__int64 a1)
{
  _QWORD *v2; // x20
  __int64 result; // x0
  __int64 (__fastcall *v4)(_QWORD); // x8
  __int64 (__fastcall *v5)(_QWORD); // x8
  __int64 (__fastcall *v6)(_QWORD); // x8
  __int64 (__fastcall *v7)(_QWORD); // x8
  __int64 (__fastcall *v8)(_QWORD); // x8

  v2 = *(_QWORD **)(*(_QWORD *)(a1 + 24) + 152LL);
  result = snd_event_client_deregister(*v2);
  v4 = (__int64 (__fastcall *)(_QWORD))v2[30];
  if ( v4 )
  {
    if ( *((_DWORD *)v4 - 1) != -725583242 )
      __break(0x8228u);
    result = v4(a1);
  }
  v5 = (__int64 (__fastcall *)(_QWORD))v2[44];
  if ( v5 )
  {
    if ( *((_DWORD *)v5 - 1) != -725583242 )
      __break(0x8228u);
    result = v5(a1);
  }
  v6 = (__int64 (__fastcall *)(_QWORD))v2[58];
  if ( v6 )
  {
    if ( *((_DWORD *)v6 - 1) != -725583242 )
      __break(0x8228u);
    result = v6(a1);
  }
  v7 = (__int64 (__fastcall *)(_QWORD))v2[72];
  if ( v7 )
  {
    if ( *((_DWORD *)v7 - 1) != -725583242 )
      __break(0x8228u);
    result = v7(a1);
  }
  v8 = (__int64 (__fastcall *)(_QWORD))v2[86];
  if ( v8 )
  {
    if ( *((_DWORD *)v8 - 1) != -725583242 )
      __break(0x8228u);
    return v8(a1);
  }
  return result;
}
