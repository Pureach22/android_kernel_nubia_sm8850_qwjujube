__int64 __fastcall clk_rcg2_crmb_set_rate(__int64 a1, unsigned __int64 a2)
{
  __int64 v2; // x21
  __int64 result; // x0
  unsigned int v6; // w20

  v2 = *(_QWORD *)(a1 + 120);
  *(_QWORD *)(a1 - 24) = a2;
  if ( (clk_hw_is_prepared(a1) & 1) == 0 )
    return 0;
  if ( !*(_QWORD *)(a1 - 8) || *(_BYTE *)(v2 + 44) != 1 )
    return 4294967274LL;
  result = clk_rcg2_vote_bw(a1, a2);
  if ( (_DWORD)result )
  {
    v6 = result;
    if ( !*(_QWORD *)(a1 + 16) )
      clk_hw_get_name(a1);
    printk(&unk_28EA3);
    return v6;
  }
  return result;
}
