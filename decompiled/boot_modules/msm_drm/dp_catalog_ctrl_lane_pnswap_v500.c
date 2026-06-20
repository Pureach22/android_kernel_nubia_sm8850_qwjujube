__int64 __fastcall dp_catalog_ctrl_lane_pnswap_v500(__int64 a1, unsigned int a2)
{
  _QWORD *v2; // x20
  unsigned int v3; // w19
  __int64 v4; // x3
  __int64 v5; // x0
  void (__fastcall *v6)(__int64, __int64, __int64, __int64); // x9
  __int64 v7; // x1
  __int64 v8; // x0
  __int64 v9; // x1
  _DWORD *v10; // x8

  v2 = *(_QWORD **)(a1 + 1104);
  v3 = (a2 >> 2) & 3;
  v4 = a2 & 3;
  v5 = v2[4];
  v6 = (void (__fastcall *)(__int64, __int64, __int64, __int64))v2[1];
  v7 = *(_QWORD *)(v2[3] + 40LL);
  if ( *((_DWORD *)v6 - 1) != 621108289 )
    __break(0x8229u);
  v6(v5, v7, 92, v4);
  v8 = v2[4];
  v9 = *(_QWORD *)(v2[3] + 48LL);
  v10 = (_DWORD *)v2[1];
  if ( *(v10 - 1) != 621108289 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))v10)(v8, v9, 92, v3);
}
