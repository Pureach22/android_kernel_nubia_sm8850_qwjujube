__int64 __fastcall qcom_ice_enable(__int64 a1)
{
  int v2; // w0
  int v3; // w20
  __int64 v4; // x0
  int v5; // w0
  __int64 v6; // x1
  __int64 v7; // x0
  __int64 result; // x0

  v2 = readl(*(_QWORD *)(a1 + 8) + 4096LL);
  writel(v2 | 0x7000u, *(_QWORD *)(a1 + 8) + 4096LL);
  v3 = readl(*(_QWORD *)(a1 + 8) + 4096LL);
  _const_udelay(21475);
  writel(v3 | 0xD807100u, *(_QWORD *)(a1 + 8) + 4096LL);
  _const_udelay(21475);
  if ( *(_BYTE *)(a1 + 33) == 1 )
  {
    v4 = *(_QWORD *)(a1 + 8);
    if ( *(unsigned __int8 *)(a1 + 32) < 2u )
    {
      v6 = v4 + 36864;
      v7 = 7;
    }
    else
    {
      v5 = readl(v4);
      v6 = *(_QWORD *)(a1 + 8);
      v7 = v5 & 0xFFFFFFFE;
    }
    writel(v7, v6);
  }
  result = qcom_ice_wait_bist_status(a1);
  if ( !(_DWORD)result )
  {
    qcom_ice_hwkm_init(a1);
    return 0;
  }
  return result;
}
