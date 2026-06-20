__int64 __fastcall msm_readl(__int64 a1)
{
  __int64 result; // x0
  unsigned int v3; // w20

  result = readl_15();
  if ( reglog == 1 )
  {
    v3 = result;
    printk(&unk_251F3B, a1);
    return v3;
  }
  return result;
}
