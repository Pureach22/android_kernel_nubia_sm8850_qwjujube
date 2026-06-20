__int64 __fastcall venus_hfi_reset_queue_header(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x9
  __int64 v4; // x9
  __int64 v5; // x9
  __int64 v6; // x9
  int v7; // w11
  _DWORD *v8; // x9
  int v9; // w10

  v1 = a1;
  v2 = *(_QWORD *)(a1 + 5656);
  *(_DWORD *)v2 = 1;
  *(_QWORD *)(v2 + 8) = 0x3200001010000LL;
  *(_DWORD *)(v2 + 16) = 0;
  *(_QWORD *)(v2 + 24) = 0x100000001LL;
  *(_DWORD *)(v2 + 32) = 1;
  *(_QWORD *)(v2 + 36) = 0;
  *(_QWORD *)(v2 + 44) = 0;
  *(_DWORD *)(v2 + 52) = 0;
  v4 = *(_QWORD *)(v1 + 5808);
  *(_DWORD *)v4 = 1;
  *(_QWORD *)(v4 + 8) = 0x3200001010000LL;
  *(_DWORD *)(v4 + 16) = 0;
  *(_QWORD *)(v4 + 24) = 0x100000001LL;
  *(_DWORD *)(v4 + 32) = 1;
  *(_QWORD *)(v4 + 36) = 0;
  *(_QWORD *)(v4 + 44) = 0;
  *(_DWORD *)(v4 + 52) = 0;
  v5 = *(_QWORD *)(v1 + 5960);
  *(_QWORD *)(v5 + 8) = 0x3200001010000LL;
  *(_DWORD *)v5 = 1;
  *(_DWORD *)(v5 + 16) = 0;
  *(_QWORD *)(v5 + 24) = 0x100000001LL;
  *(_DWORD *)(v5 + 32) = 1;
  *(_QWORD *)(v5 + 36) = 0;
  *(_QWORD *)(v5 + 44) = 0;
  *(_DWORD *)(v5 + 52) = 0;
  *(_DWORD *)(*(_QWORD *)(v1 + 5656) + 4LL) = *(_DWORD *)(v1 + 5664);
  v6 = *(_QWORD *)(v1 + 5808);
  v7 = *(_DWORD *)(v6 + 8) | 1;
  *(_DWORD *)(v6 + 4) = *(_DWORD *)(v1 + 5816);
  *(_DWORD *)(v6 + 8) = v7;
  v8 = *(_DWORD **)(v1 + 5960);
  LODWORD(v1) = *(_DWORD *)(v1 + 5968);
  v9 = v8[2];
  v8[8] = 0;
  v8[1] = v1;
  v8[2] = v9 | 2;
  return 0;
}
