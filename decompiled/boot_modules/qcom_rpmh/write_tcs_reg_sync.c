__int64 __fastcall write_tcs_reg_sync(__int64 a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
  int v4; // w9
  int v9; // w24
  int v10; // w8
  __int64 result; // x0

  v4 = *(_DWORD *)(a1 + 40);
  if ( !v4 )
    v4 = **(_DWORD **)(a1 + 1664);
  writel(a4, *(_QWORD *)(a1 + 32) + (int)a2 + v4 * a3);
  v9 = 1000000;
  while ( 1 )
  {
    v10 = *(_DWORD *)(a1 + 40);
    if ( !v10 )
      v10 = **(_DWORD **)(a1 + 1664);
    result = readl(*(_QWORD *)(a1 + 32) + (int)a2 + v10 * a3);
    if ( (_DWORD)result == a4 )
      break;
    _const_udelay(4295);
    if ( !--v9 )
      return printk(&unk_D944, "qcom_rpmh", a1, a4, a3, a2);
  }
  return result;
}
