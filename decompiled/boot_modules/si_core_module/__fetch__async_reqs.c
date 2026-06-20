void *__fastcall _fetch__async_reqs(unsigned int *a1)
{
  __int64 v2; // x0
  unsigned __int64 v3; // x1
  size_t v4; // x19
  char *v5; // x20
  __int64 v6; // x22
  unsigned __int64 v7; // x8
  char *v8; // x25
  unsigned int v9; // w26
  unsigned __int64 v10; // x0
  __int64 v11; // x6

  v2 = async_si_buffer((__int64)a1);
  v4 = v3;
  v5 = (char *)v2;
  if ( v3 >= 9 )
  {
    v6 = 0;
    v7 = v3;
    do
    {
      v8 = &v5[v6];
      if ( !*(_DWORD *)&v5[v6] )
        break;
      if ( *((_DWORD *)v8 + 1) != 0xFFFF || (global_version = *(_DWORD *)&v5[v6], v7 < 0x10) )
      {
LABEL_12:
        printk(&unk_B1B0, *a1);
        if ( v4 >= 0x60 )
          v11 = 96;
        else
          v11 = v4;
        print_hex_dump(&unk_B590, "si-core: ", 2, 16, 4, v5, v11, 1);
        return memset(v5, 0, v4);
      }
      if ( *((_DWORD *)v8 + 2) )
      {
        v9 = 0;
        do
        {
          v10 = erase_si_object(*(_DWORD *)&v8[4 * v9 + 12]);
          put_si_object(v10);
          ++v9;
        }
        while ( v9 < *((_DWORD *)v8 + 2) );
        v6 += (4LL * (int)v9 + 19) & 0xFFFFFFFFFFFFFFF8LL;
        if ( v9 == -3 )
          goto LABEL_12;
      }
      else
      {
        v6 += 16;
      }
      v7 = v4 - v6;
    }
    while ( v4 - v6 > 8 );
  }
  return memset(v5, 0, v4);
}
