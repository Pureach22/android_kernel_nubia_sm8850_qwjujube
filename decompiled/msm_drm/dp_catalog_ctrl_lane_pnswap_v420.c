__int64 __fastcall dp_catalog_ctrl_lane_pnswap_v420(__int64 a1, unsigned int a2)
{
  _QWORD *v2; // x19
  __int64 v3; // x0
  int v4; // w20
  int v5; // w8
  __int64 v6; // x1
  _DWORD *v7; // x9
  __int64 v8; // x0
  __int64 v9; // x1
  _DWORD *v10; // x8

  v2 = *(_QWORD **)(a1 + 1104);
  v3 = v2[4];
  v4 = (a2 >> 1) & 4 | (a2 >> 2) & 1;
  v5 = (2 * a2) & 4 | a2 & 1;
  v6 = *(_QWORD *)(v2[3] + 40LL);
  v7 = (_DWORD *)v2[1];
  if ( *(v7 - 1) != 621108289 )
    __break(0x8229u);
  ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v7)(v3, v6, 92, v5 | 0xAu);
  v8 = v2[4];
  v9 = *(_QWORD *)(v2[3] + 48LL);
  v10 = (_DWORD *)v2[1];
  if ( *(v10 - 1) != 621108289 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))v10)(v8, v9, 92, v4 | 0xAu);
}
