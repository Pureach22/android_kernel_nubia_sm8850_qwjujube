__int64 __fastcall btpower_register_slimdev(__int64 a1)
{
  if ( a1 && pwr_data )
  {
    *(_QWORD *)(pwr_data + 48) = a1;
    return 0;
  }
  else
  {
    printk(&unk_11AFA, "btpower_register_slimdev");
    return 4294967274LL;
  }
}
