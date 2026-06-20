__int64 __fastcall clk_rcg2_crmb_prepare(__int64 a1)
{
  if ( *(_QWORD *)(a1 - 8) && *(_BYTE *)(*(_QWORD *)(a1 + 120) + 44LL) == 1 )
    return clk_rcg2_vote_bw(a1, *(_QWORD *)(a1 - 24));
  else
    return 0;
}
