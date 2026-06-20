__int64 __fastcall gen7_cp_init_cmds(__int64 result, __int64 a2)
{
  int v2; // w9
  int v3; // w8

  *(_QWORD *)a2 = 0x800000070970001LL;
  v2 = *(unsigned __int8 *)(result + 20441);
  *(_QWORD *)(a2 + 16) = 0x2000000000000003LL;
  *(_DWORD *)(a2 + 24) = 2;
  if ( v2 )
    v3 = 331;
  else
    v3 = 2379;
  *(_DWORD *)(a2 + 8) = 1892155399;
  *(_DWORD *)(a2 + 12) = v3;
  *(_DWORD *)(a2 + 28) = *(_QWORD *)(*(_QWORD *)(result + 20464) + 24LL);
  *(_DWORD *)(a2 + 32) = *(_DWORD *)(*(_QWORD *)(result + 20464) + 28LL);
  *(_DWORD *)(a2 + 36) = 0x80000000;
  return result;
}
