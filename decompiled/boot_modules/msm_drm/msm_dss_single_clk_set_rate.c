__int64 __fastcall msm_dss_single_clk_set_rate(__int64 a1, __int64 a2)
{
  __int64 v2; // x30
  __int64 v4; // x20
  __int64 result; // x0
  unsigned __int64 v6; // x8
  unsigned int v7; // w19

  if ( !a1 )
  {
    printk(&unk_25B6E9, a2);
    return 4294967274LL;
  }
  v4 = v2;
  result = strcmp((const char *)(a1 + 8), "branch_clk");
  if ( (_DWORD)result )
  {
    result = *(unsigned int *)(a1 + 40);
    if ( (_DWORD)result )
    {
      if ( (_DWORD)result == 2 )
      {
        v6 = *(_QWORD *)(a1 + 88);
        if ( v6 )
        {
          if ( *(_QWORD *)(a1 + 48) <= v6 )
          {
            *(_QWORD *)(a1 + 88) = 0;
            _wake_up(a1 + 96, 3, 0, 0);
          }
        }
        return 0;
      }
      if ( *(_DWORD *)(a1 + 68) )
        return 0;
      result = clk_set_rate(*(_QWORD *)a1, *(_QWORD *)(a1 + 48));
      if ( (_DWORD)result )
      {
        v7 = result;
        printk(&unk_2708ED, v4);
        return v7;
      }
    }
  }
  return result;
}
