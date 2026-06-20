__int64 __fastcall wlan_sr_setup_req(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x8
  __int64 (__fastcall *v4)(_QWORD); // x8

  v2 = *(_QWORD *)(a2 + 80);
  if ( !v2 )
    return 16;
  v3 = *(_QWORD *)(v2 + 2128);
  if ( !v3 )
    return 16;
  v4 = *(__int64 (__fastcall **)(_QWORD))(v3 + 2208);
  if ( !v4 )
    return 16;
  if ( *((_DWORD *)v4 - 1) != -1476975011 )
    __break(0x8228u);
  return v4(a1);
}
