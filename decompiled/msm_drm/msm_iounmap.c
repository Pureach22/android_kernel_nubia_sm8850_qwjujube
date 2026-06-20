__int64 __fastcall msm_iounmap(__int64 a1)
{
  return devm_iounmap(a1 + 16);
}
