__int64 __fastcall gen8_cp_init_cmds(__int64 result, __int64 a2)
{
  *(_QWORD *)a2 = 0x800000070970001LL;
  *(_QWORD *)(a2 + 8) = 0x14B70C80007LL;
  *(_QWORD *)(a2 + 16) = 0x2000000000000003LL;
  *(_DWORD *)(a2 + 24) = 2;
  *(_DWORD *)(a2 + 28) = *(_QWORD *)(*(_QWORD *)(result + 20464) + 24LL);
  *(_DWORD *)(a2 + 32) = *(_DWORD *)(*(_QWORD *)(result + 20464) + 28LL);
  *(_DWORD *)(a2 + 36) = 0x80000000;
  return result;
}
