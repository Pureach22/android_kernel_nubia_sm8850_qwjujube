__int64 __fastcall qcom_cc_clk_hw_get(__int64 a1, _QWORD *a2)
{
  unsigned __int64 v2; // x2
  __int64 result; // x0

  v2 = *(unsigned int *)(a1 + 12);
  if ( a2[18] <= v2 || (result = *(_QWORD *)(a2[17] + 8 * v2)) == 0 )
  {
    if ( a2[16] <= v2 )
    {
      printk(&unk_28327);
      return -22;
    }
    else
    {
      return *(_QWORD *)(a2[15] + 8 * v2);
    }
  }
  return result;
}
