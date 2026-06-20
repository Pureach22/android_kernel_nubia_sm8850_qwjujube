void __fastcall hal_get_srng_params(__int64 a1, __int64 a2, __int64 a3)
{
  *(_BYTE *)(a3 + 52) = *(_BYTE *)a2;
  *(_DWORD *)(a3 + 56) = *(_DWORD *)(a2 + 116);
  *(_DWORD *)(a3 + 60) = *(_DWORD *)(a2 + 44);
  *(_QWORD *)a3 = *(_QWORD *)(a2 + 8);
  *(_QWORD *)(a3 + 8) = *(_QWORD *)(a2 + 16);
  *(_DWORD *)(a3 + 16) = *(_DWORD *)(a2 + 32);
  *(_QWORD *)(a3 + 24) = *(_QWORD *)(a2 + 64);
  *(_DWORD *)(a3 + 32) = *(_DWORD *)(a2 + 72);
  *(_DWORD *)(a3 + 36) = *(_DWORD *)(a2 + 48);
  *(_DWORD *)(a3 + 40) = *(_DWORD *)(a2 + 52);
  *(_DWORD *)(a3 + 44) = *(_DWORD *)(a2 + 152);
  *(_DWORD *)(a3 + 48) = *(_DWORD *)(a2 + 76);
  *(_BYTE *)(a3 + 52) = *(_BYTE *)a2;
  *(_QWORD *)(a3 + 64) = *(_QWORD *)(a2 + 96);
  *(_QWORD *)(a3 + 72) = *(_QWORD *)(a2 + 104);
}
