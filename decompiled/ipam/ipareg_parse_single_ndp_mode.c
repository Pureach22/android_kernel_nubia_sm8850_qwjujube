void __fastcall ipareg_parse_single_ndp_mode(__int64 a1, __int64 a2, unsigned int a3)
{
  *(_QWORD *)a2 = 0;
  *(_BYTE *)a2 = a3 & 1;
  *(_DWORD *)(a2 + 4) = a3 >> 1;
}
