__int64 __fastcall dp_catalog_ctrl_lane_pnswap(__int64 a1, unsigned int a2)
{
  __int64 v2; // x20
  _DWORD *v4; // x9
  int v5; // w8
  int v6; // w22
  __int64 v7; // x1
  __int64 v8; // x0
  __int64 v9; // x1
  _DWORD *v10; // x8

  v2 = a1 - 232;
  v4 = *(_DWORD **)(a1 - 104);
  v5 = (2 * a2) & 4 | a2 & 1;
  v6 = (a2 >> 1) & 4 | (a2 >> 2) & 1;
  v7 = *(_QWORD *)(a1 - 184);
  v8 = a1 - 232;
  if ( *(v4 - 1) != -626862723 )
    __break(0x8229u);
  ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v4)(v8, v7, 100, v5 | 0xAu);
  v9 = *(_QWORD *)(a1 - 176);
  v10 = *(_DWORD **)(a1 - 104);
  if ( *(v10 - 1) != -626862723 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))v10)(v2, v9, 100, v6 | 0xAu);
}
