__int64 __fastcall btpower_process_access_req(int a1, int a2)
{
  int v4; // w0

  printk(&unk_12A19, "btpower_process_access_req");
  if ( a1 == 49124 && a2 == 1 )
  {
    v4 = 6;
  }
  else if ( a1 == 49124 && a2 == 2 )
  {
    v4 = 8;
  }
  else if ( a1 == 49125 && a2 == 1 )
  {
    v4 = 7;
  }
  else
  {
    if ( a1 != 49125 || a2 != 2 )
    {
      printk(&unk_11414, "btpower_process_access_req");
      return 0xFFFFFFFFLL;
    }
    v4 = 9;
  }
  return schedule_client_voting(v4);
}
