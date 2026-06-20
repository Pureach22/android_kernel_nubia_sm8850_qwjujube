__int64 __fastcall get_tp_algo_item_id(const char *a1)
{
  char *v1; // x21
  size_t v3; // x0
  size_t v4; // x0
  size_t v5; // x0
  size_t v6; // x0
  size_t v7; // x0
  size_t v8; // x0
  size_t v9; // x0

  v1 = &ztp_algo_info_l;
  v3 = strlen(a1);
  if ( !strnstr(a1, off_498, v3) )
  {
    v1 = &byte_4A0;
    v4 = strlen(a1);
    if ( !strnstr(a1, off_4A8, v4) )
    {
      v1 = &byte_4B0;
      v5 = strlen(a1);
      if ( !strnstr(a1, off_4B8, v5) )
      {
        v1 = &byte_4C0;
        v6 = strlen(a1);
        if ( !strnstr(a1, off_4C8, v6) )
        {
          v1 = &byte_4D0;
          v7 = strlen(a1);
          if ( !strnstr(a1, off_4D8, v7) )
          {
            v1 = &byte_4E0;
            v8 = strlen(a1);
            if ( !strnstr(a1, off_4E8, v8) )
            {
              v1 = &byte_4F0;
              v9 = strlen(a1);
              if ( !strnstr(a1, off_4F8, v9) )
                return 4294967291LL;
            }
          }
        }
      }
    }
  }
  printk(unk_39C9D, "get_tp_algo_item_id", (unsigned __int8)*v1);
  return (unsigned __int8)*v1;
}
