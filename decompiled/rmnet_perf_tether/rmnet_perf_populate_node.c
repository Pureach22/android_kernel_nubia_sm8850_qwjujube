__int64 __fastcall rmnet_perf_populate_node(__int64 result, __int64 a2)
{
  int v2; // w8
  __int64 v3; // x11
  __int64 v4; // x12
  __int64 v5; // x9
  int v6; // w8
  __int64 v7; // x10
  __int64 v8; // x8
  __int64 v9; // x8
  __int64 v10; // x9
  __int64 v11; // x10

  v2 = *(unsigned __int16 *)(a2 + 180);
  if ( v2 == 56710 )
  {
    v3 = 68;
    v4 = 6;
    v8 = *(_QWORD *)(*(_QWORD *)(a2 + 216) + *(unsigned __int16 *)(a2 + 184) + 24LL);
    *(_QWORD *)(result + 44) = *(_QWORD *)(*(_QWORD *)(a2 + 216) + *(unsigned __int16 *)(a2 + 184) + 32LL);
    *(_QWORD *)(result + 36) = v8;
    v9 = *(_QWORD *)(a2 + 216) + *(unsigned __int16 *)(a2 + 184);
    v11 = *(_QWORD *)(v9 + 8);
    v10 = *(_QWORD *)(v9 + 16);
    v6 = 11;
    *(_QWORD *)(result + 56) = v11;
    *(_QWORD *)(result + 64) = v10;
    v5 = 76;
    v7 = 72;
  }
  else
  {
    if ( v2 != 8 )
      return result;
    v3 = 44;
    v4 = 9;
    *(_DWORD *)(result + 36) = *(_DWORD *)(*(_QWORD *)(a2 + 216) + *(unsigned __int16 *)(a2 + 184) + 16LL);
    v5 = 52;
    v6 = 5;
    *(_DWORD *)(result + 40) = *(_DWORD *)(*(_QWORD *)(a2 + 216) + *(unsigned __int16 *)(a2 + 184) + 12LL);
    v7 = 48;
  }
  *(_DWORD *)(result + v3) = *(unsigned __int8 *)(*(_QWORD *)(a2 + 216) + *(unsigned __int16 *)(a2 + 184) + v4);
  *(_DWORD *)(result + v7) = *(unsigned __int16 *)(*(_QWORD *)(a2 + 216) + *(unsigned __int16 *)(a2 + 182) + 2LL);
  *(_DWORD *)(result + v5) = *(unsigned __int16 *)(*(_QWORD *)(a2 + 216) + *(unsigned __int16 *)(a2 + 182));
  *(_DWORD *)(result + 80) = v6;
  return result;
}
