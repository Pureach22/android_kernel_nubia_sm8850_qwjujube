__int64 __fastcall a5xx_preemption_pre_ibsubmit(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x9
  int v6; // w10
  _BOOL4 v7; // w10
  int v8; // w11

  v4 = *(_QWORD *)(*(_QWORD *)(a2 + 184) + 24LL);
  if ( (*(_QWORD *)(a1 + 14240) & 0x200) == 0 )
    return 0;
  if ( !a3 || (v6 = *(_DWORD *)(a3 + 200), (v6 & 0x20000) != 0) )
  {
    v7 = 0;
    v8 = 0;
  }
  else
  {
    v7 = (v6 & 0xE000000) == 0x4000000;
    v8 = 2 * v7;
  }
  *(_DWORD *)a4 = 1894318081;
  *(_DWORD *)(a4 + 4) = v8;
  *(_DWORD *)(a4 + 8) = 1893662721;
  *(_QWORD *)(a4 + 12) = 0x48083E0100000000LL;
  *(_DWORD *)(a4 + 28) = HIDWORD(v4);
  *(_DWORD *)(a4 + 32) = 1893662721;
  *(_DWORD *)(a4 + 20) = v4;
  *(_DWORD *)(a4 + 24) = 1074282241;
  *(_DWORD *)(a4 + 44) = v7;
  *(_DWORD *)(a4 + 48) = 1880883201;
  *(_DWORD *)(a4 + 36) = 1;
  *(_DWORD *)(a4 + 40) = 1894383617;
  *(_DWORD *)(a4 + 52) = 2;
  return 14;
}
