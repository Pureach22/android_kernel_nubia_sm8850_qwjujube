__int64 __fastcall dp_switch_event(__int64 a1, int a2)
{
  if ( dp_switch )
  {
    if ( a2 )
    {
      if ( a2 == 1 )
        *(_BYTE *)(dp_switch + 16) = 1;
    }
    else
    {
      *(_BYTE *)(dp_switch + 16) = 0;
    }
    printk(&unk_25DEFB, "dp_switch_event");
    return 0;
  }
  else
  {
    printk(&unk_2619B0, "dp_switch_event");
    return 4294967274LL;
  }
}
