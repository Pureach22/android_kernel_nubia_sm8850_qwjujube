__int64 __fastcall extract_ready_event_params_tlv(__int64 a1, __int64 a2, __int64 a3)
{
  _DWORD *v3; // x9
  int v5; // w10

  v3 = *(_DWORD **)a2;
  *(_DWORD *)a3 = *(_DWORD *)(*(_QWORD *)a2 + 36LL);
  *(_DWORD *)(a3 + 4) = v3[10];
  *(_DWORD *)(a3 + 8) = v3[11];
  *(_DWORD *)(a3 + 12) = v3[12];
  *(_DWORD *)(a3 + 16) = v3[13];
  *(_DWORD *)(a3 + 24) = v3[14];
  v5 = v3[15];
  *(_BYTE *)(a3 + 20) = 1;
  *(_DWORD *)(a3 + 28) = v5;
  *(_DWORD *)(a3 + 32) = v3[18];
  return 0;
}
