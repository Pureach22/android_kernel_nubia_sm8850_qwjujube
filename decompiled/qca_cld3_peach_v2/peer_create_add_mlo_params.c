__int64 __fastcall peer_create_add_mlo_params(__int64 a1, __int64 a2)
{
  int v3; // w9

  *(_DWORD *)(a1 + 8) = 0;
  *(_QWORD *)a1 = 0x3D5000400120008LL;
  v3 = *(unsigned __int8 *)(a2 + 16);
  *(_DWORD *)(a1 + 8) = v3;
  *(_DWORD *)(a1 + 8) = v3 | (*(unsigned __int8 *)(a2 + 17) << 10);
  return a1 + 12;
}
