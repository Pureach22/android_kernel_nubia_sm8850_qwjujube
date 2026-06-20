__int64 __fastcall sub_500138(__int64 a1, __int64 a2)
{
  __asm { STGP            X30, X5, [X22,#-0xC] }
  return dp_update_pdev_ingress_stats(a1, a2);
}
