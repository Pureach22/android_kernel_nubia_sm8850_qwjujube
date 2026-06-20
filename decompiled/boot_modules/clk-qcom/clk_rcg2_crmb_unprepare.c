__int64 __fastcall clk_rcg2_crmb_unprepare(__int64 result)
{
  __int64 v1; // x19

  if ( *(_QWORD *)(result - 8) )
  {
    if ( *(_BYTE *)(*(_QWORD *)(result + 120) + 44LL) == 1 )
    {
      v1 = result;
      result = clk_rcg2_vote_bw(result, 0);
      if ( (_DWORD)result )
      {
        if ( !*(_QWORD *)(v1 + 16) )
          clk_hw_get_name(v1);
        return printk(&unk_28EA3);
      }
    }
  }
  return result;
}
