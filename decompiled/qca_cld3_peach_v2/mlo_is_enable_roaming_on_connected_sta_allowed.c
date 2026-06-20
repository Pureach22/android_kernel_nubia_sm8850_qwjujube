bool __fastcall mlo_is_enable_roaming_on_connected_sta_allowed(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x8
  __int64 v3; // x8

  return (*(_BYTE *)(a1 + 60) & 2) == 0
      || (v1 = *(_QWORD *)(a1 + 1360)) == 0
      || (v2 = *(_QWORD *)(v1 + 2224)) == 0
      || (v3 = *(_QWORD *)(v2 + 288)) == 0
      || *(unsigned __int8 *)(v3 + 160) < 2u;
}
