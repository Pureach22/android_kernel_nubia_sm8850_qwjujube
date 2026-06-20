__int64 __fastcall qmp_dp_clks_hw_get(__int64 a1, __int64 a2)
{
  unsigned int v2; // w2

  v2 = *(_DWORD *)(a1 + 12);
  if ( v2 >= 2 )
  {
    printk(&unk_E9F3, "qmp_dp_clks_hw_get");
    return -22;
  }
  else if ( v2 )
  {
    return a2 + 424;
  }
  else
  {
    return a2 + 400;
  }
}
