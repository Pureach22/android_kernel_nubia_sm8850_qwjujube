bool __fastcall wlan_is_channel_present_in_list(int *a1, unsigned int a2, int a3)
{
  _BOOL4 v3; // w8
  __int64 v4; // x8
  __int64 v5; // x9
  int v6; // t1

  v3 = 0;
  if ( a1 && a2 )
  {
    if ( a2 >= 0x64 )
      v4 = 100;
    else
      v4 = a2;
    v5 = v4 - 1;
    do
    {
      v6 = *a1++;
      v3 = v6 == a3;
      if ( v6 == a3 )
        break;
    }
    while ( v5-- );
  }
  return v3;
}
