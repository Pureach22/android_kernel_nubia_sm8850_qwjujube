__int64 __fastcall dwc3_core_resize_tx_fifos(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x8
  int v3; // w9
  bool v4; // zf
  __int64 v5; // x21
  int v7; // w8
  int v8; // w19
  unsigned int v9; // w9
  __int64 v10; // x22
  unsigned int v11; // w9
  int v12; // w8
  int v13; // w10
  int v14; // w10
  int v15; // w23
  int v16; // w0
  int v17; // w9
  int v18; // w8
  int v19; // w2
  unsigned int v20; // w8
  int v21; // w9

  v1 = *(_QWORD *)(result + 152);
  if ( (*(_BYTE *)(v1 + 1377) & 4) != 0 )
  {
    v2 = *(_QWORD *)(result + 24);
    if ( *(char *)(v2 + 2) < 0 && *(unsigned __int8 *)(result + 170) >= 2u )
    {
      v3 = *(_BYTE *)(v2 + 3) & 3;
      v4 = v3 != 2 || (*(_BYTE *)(result + 62) & 0x78) == 0;
      v5 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v1 + 368) + 96LL) + 152LL);
      if ( !v4 || v3 == 1 )
        v7 = 3;
      else
        v7 = 1;
      if ( (*(_BYTE *)(result + 62) & 0x7Cu) >= 0x19 && v3 == 2 && *(_DWORD *)(v1 + 1248) == 13105 )
        v7 = *(unsigned __int8 *)(v1 + 1360);
      v8 = *(unsigned __int16 *)(v1 + 1308);
      v9 = *(unsigned __int8 *)(v1 + 1281);
      v10 = result;
      if ( *(_DWORD *)(v1 + 1248) == 13106 )
        v9 |= *(_DWORD *)(v1 + 1304) & 0x300;
      v11 = ((v9 >> 3) | 0x400) / (v9 >> 3);
      v12 = v7 - 1 + (v7 - 1) * v11;
      v13 = v8 - *(_DWORD *)(v1 + 1392) + (*(_DWORD *)(v1 + 1388) - *(_DWORD *)(v1 + 1396)) * (-2 - v11);
      v14 = v13 & ~(v13 >> 31);
      if ( v14 < v12 )
        v12 = v14;
      v15 = v11 + v12 + 2;
      v16 = readl(*(_QWORD *)(v5 + 8) + 49920LL);
      v17 = *(_DWORD *)(v1 + 1392);
      if ( *(_DWORD *)(v1 + 1248) == 21811 )
        v18 = (unsigned __int16)v15;
      else
        v18 = v15 & 0x7FFF;
      v19 = v18 + v17;
      v20 = (v16 & 0xFFFF0000) + (v17 << 16);
      *(_DWORD *)(v1 + 1392) = v19;
      if ( v19 >= v8 )
      {
        result = dev_err(
                   *(_QWORD *)(v1 + 368),
                   "Fifosize(%d) > RAM size(%d) %s depth:%d\n",
                   v19,
                   v8,
                   *(const char **)(v10 + 8),
                   v15 | v20);
        if ( *(_DWORD *)(v1 + 1248) == 21811 )
          v21 = (unsigned __int16)v15;
        else
          v21 = v15 & 0x7FFF;
        *(_DWORD *)(v1 + 1392) -= v21;
      }
      else
      {
        result = writel(v15 | v20, *(_QWORD *)(v5 + 8) + ((2 * *(unsigned __int8 *)(v10 + 170)) & 0x1FC) + 49920LL);
        ++*(_DWORD *)(v1 + 1396);
      }
    }
  }
  return result;
}
