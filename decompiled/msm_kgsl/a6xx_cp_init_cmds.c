__int64 __fastcall a6xx_cp_init_cmds(__int64 result, __int64 a2)
{
  __int64 v2; // x8

  *(_QWORD *)a2 = 0x16F70C8800ALL;
  *(_QWORD *)(a2 + 8) = 0x2000000000000003LL;
  *(_QWORD *)(a2 + 16) = 0;
  *(_QWORD *)(a2 + 24) = 0x200000000LL;
  v2 = *(_QWORD *)(*(_QWORD *)(result + 20464) + 24LL);
  *(_DWORD *)(a2 + 40) = 0;
  *(_QWORD *)(a2 + 32) = v2;
  return result;
}
