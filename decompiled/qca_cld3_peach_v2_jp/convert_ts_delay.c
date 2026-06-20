void __fastcall convert_ts_delay(__int64 a1, __int64 a2, __int64 a3)
{
  *(_WORD *)a2 = 1067;
  *(_DWORD *)(a2 + 2) = *(_DWORD *)(a3 + 4);
}
