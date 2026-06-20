__int64 __fastcall dp_display_abort_hdcp(__int64 result, char a2)
{
  int v2; // w8
  __int64 v3; // x19
  __int64 v5; // x0
  _DWORD *v6; // x8
  __int64 v7; // x0
  _DWORD *v8; // x8

  v2 = *(_DWORD *)(result + 240);
  v3 = result;
  if ( (*(_DWORD *)(result + 312) & v2) != 0 )
  {
    v5 = *(_QWORD *)(result + 296);
    v6 = *(_DWORD **)(*(_QWORD *)(v3 + 304) + 56LL);
    if ( *(v6 - 1) != -538254584 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, _QWORD))v6)(v5, a2 & 1);
    v2 = *(_DWORD *)(v3 + 240);
  }
  if ( (*(_DWORD *)(v3 + 288) & v2) != 0 )
  {
    v7 = *(_QWORD *)(v3 + 272);
    v8 = *(_DWORD **)(*(_QWORD *)(v3 + 280) + 56LL);
    if ( *(v8 - 1) != -538254584 )
      __break(0x8228u);
    return ((__int64 (__fastcall *)(__int64, _QWORD))v8)(v7, a2 & 1);
  }
  return result;
}
