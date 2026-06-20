__int64 __fastcall of_clk_rpmh_hw_get(__int64 a1, _QWORD *a2)
{
  unsigned __int64 v2; // x2

  v2 = *(unsigned int *)(a1 + 12);
  if ( a2[1] <= v2 )
  {
    printk(&unk_D394, "of_clk_rpmh_hw_get");
    return -22;
  }
  else if ( *(_QWORD *)(*a2 + 8 * v2) )
  {
    return *(_QWORD *)(*a2 + 8 * v2);
  }
  else
  {
    return -2;
  }
}
