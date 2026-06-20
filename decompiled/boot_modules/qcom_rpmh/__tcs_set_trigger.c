__int64 __fastcall _tcs_set_trigger(__int64 a1, unsigned int a2, char a3)
{
  int *v3; // x10
  int v4; // w9
  __int64 v8; // x19
  int v9; // w23
  __int64 result; // x0
  int v11; // w9

  v3 = *(int **)(a1 + 1664);
  v4 = *(_DWORD *)(a1 + 40);
  v8 = v3[8];
  if ( !v4 )
    v4 = *v3;
  v9 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 32) + v8 + v4 * a2));
  write_tcs_reg_sync(a1, v8, a2, v9 & 0xFEFFFFFF);
  result = write_tcs_reg_sync(a1, v8, a2, v9 & 0xFEFEFFFF);
  if ( (a3 & 1) != 0 )
  {
    write_tcs_reg_sync(a1, v8, a2, 0x10000u);
    v11 = *(_DWORD *)(a1 + 40);
    if ( !v11 )
      v11 = **(_DWORD **)(a1 + 1664);
    return writel_relaxed(16842752, *(_QWORD *)(a1 + 32) + v8 + v11 * a2);
  }
  return result;
}
