__int64 __fastcall temperature_threshold_show(__int64 a1, __int64 a2, __int64 a3)
{
  _DWORD *v4; // x22
  int v5; // w21
  int v6; // w21
  int v7; // w21
  int v8; // w21
  int v9; // w21
  int v10; // w21
  int v11; // w21
  int v12; // w8

  v4 = *(_DWORD **)(a1 + 152);
  v5 = scnprintf(a3, 4096, "%i ", -40000);
  v6 = scnprintf(a3 + v5, 4096LL - v5, "%d ", v4[5]) + v5;
  v7 = scnprintf(a3 + v6, 4096LL - v6, "%d ", v4[6]) + v6;
  v8 = scnprintf(a3 + v7, 4096LL - v7, "%d ", v4[7]) + v7;
  v9 = scnprintf(a3 + v8, 4096LL - v8, "%d ", v4[8]) + v8;
  v10 = scnprintf(a3 + v9, 4096LL - v9, "%d ", v4[9]) + v9;
  v11 = scnprintf(a3 + v10, 4096LL - v10, "%d ", v4[10]) + v10;
  v12 = scnprintf(a3 + v11, 4096LL - v11, "%d ", v4[11]) + v11;
  *(_BYTE *)(a3 + v12 - 1) = 10;
  return v12;
}
