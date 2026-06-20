__int64 __fastcall btpower_handle_client_request(int a1, unsigned int a2)
{
  _DWORD *v4; // x8
  __int64 result; // x0

  printk(&unk_1306C, "btpower_handle_client_request");
  if ( a1 == 49069 )
  {
    if ( a2 < 3 )
    {
      v4 = &unk_10CF8;
      return schedule_client_voting(v4[a2]);
    }
    return 0xFFFFFFFFLL;
  }
  else
  {
    result = 0xFFFFFFFFLL;
    if ( a1 == 49121 && a2 <= 2 )
    {
      v4 = &unk_10D04;
      return schedule_client_voting(v4[a2]);
    }
  }
  return result;
}
