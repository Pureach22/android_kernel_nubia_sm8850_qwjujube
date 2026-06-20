__int64 __fastcall ieee80211_s1g_channel_width(_DWORD *a1)
{
  int v1; // w8

  if ( a1 && *a1 == 4 )
  {
    v1 = a1[3];
    if ( (v1 & 0x4000) != 0 )
    {
      return 8;
    }
    else if ( (v1 & 0x8000) != 0 )
    {
      return 9;
    }
    else if ( (v1 & 0x10000) != 0 )
    {
      return 10;
    }
    else if ( (v1 & 0x20000) != 0 )
    {
      return 11;
    }
    else if ( (v1 & 0x40000) != 0 )
    {
      return 12;
    }
    else
    {
      printk(&unk_B9015);
      return 8;
    }
  }
  else
  {
    __break(0x800u);
    return 0;
  }
}
