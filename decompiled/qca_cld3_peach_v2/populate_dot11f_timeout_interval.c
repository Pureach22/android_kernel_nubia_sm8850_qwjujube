void __fastcall populate_dot11f_timeout_interval(__int64 a1, __int64 a2, char a3, int a4)
{
  *(_BYTE *)(a2 + 1) = a3;
  *(_BYTE *)a2 = 1;
  *(_DWORD *)(a2 + 4) = a4;
}
