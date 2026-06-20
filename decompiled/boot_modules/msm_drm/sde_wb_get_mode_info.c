__int64 __fastcall sde_wb_get_mode_info(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  unsigned int v6; // w8
  unsigned int v7; // w9
  bool v8; // cc
  int v9; // w8
  __int64 result; // x0

  if ( a2 && a4 && a6 && a5 && (v6 = *(_DWORD *)(a6 + 24)) != 0 )
  {
    v7 = *(unsigned __int16 *)(a2 + 4);
    v8 = v6 > v7;
    if ( v6 > v7 )
      v9 = 1;
    else
      v9 = 2;
    *(_QWORD *)(a4 + 40) = 0x100000000LL;
    *(_DWORD *)(a4 + 36) = v9;
    if ( !v8 && (*(_WORD *)(a2 + 4) & 3) != 0 )
    {
      printk(&unk_22BC18, "sde_wb_get_mode_info");
      return 4294967274LL;
    }
    else
    {
      result = 0;
      *(_BYTE *)(a4 + 776) = 0;
      *(_QWORD *)(a4 + 60) = 0x6400000000LL;
    }
  }
  else
  {
    printk(&unk_2579ED, "sde_wb_get_mode_info");
    return 4294967274LL;
  }
  return result;
}
