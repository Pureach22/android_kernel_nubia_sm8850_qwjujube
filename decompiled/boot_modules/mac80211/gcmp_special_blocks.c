__int64 __fastcall gcmp_special_blocks(__int64 a1, int *a2, __int64 a3)
{
  __int64 v3; // x9
  __int16 v4; // w10
  int v5; // w10

  v3 = *(_QWORD *)(a1 + 224);
  v4 = *(_WORD *)(v3 + 14);
  LODWORD(v3) = *(_DWORD *)(v3 + 10);
  *(_WORD *)(a3 + 4) = v4;
  *(_DWORD *)a3 = v3;
  LOWORD(v3) = *((_WORD *)a2 + 2);
  v5 = *a2;
  *(_WORD *)(a3 + 13) = 0;
  *(_BYTE *)(a3 + 15) = 1;
  *(_WORD *)(a3 + 10) = v3;
  *(_DWORD *)(a3 + 6) = v5;
  return ccmp_gcmp_aad();
}
