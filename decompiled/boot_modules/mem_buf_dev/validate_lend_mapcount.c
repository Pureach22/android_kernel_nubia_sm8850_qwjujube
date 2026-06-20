__int64 __fastcall validate_lend_mapcount(__int64 a1, __int64 a2)
{
  int v3; // w12
  __int64 v5; // x2
  unsigned int v6; // w23

  if ( !*(_DWORD *)(a1 + 24) )
    return 1;
  if ( !*(_DWORD *)a2 )
  {
LABEL_8:
    if ( (unsigned int)__ratelimit(&validate_lend_mapcount__rs, "validate_lend_mapcount") )
    {
      printk(&unk_133FE, "validate_lend_mapcount", v5);
      if ( *(_DWORD *)a2 )
      {
LABEL_10:
        v6 = 0;
        do
        {
          if ( (unsigned int)__ratelimit(&validate_lend_mapcount__rs_48, "validate_lend_mapcount") )
            printk(&unk_13761, "validate_lend_mapcount", *(unsigned int *)(*(_QWORD *)(a2 + 8) + 4LL * (int)v6));
          ++v6;
        }
        while ( v6 < *(_DWORD *)a2 );
      }
    }
    else if ( *(_DWORD *)a2 )
    {
      goto LABEL_10;
    }
    return 0;
  }
  v3 = 0;
  while ( *(_DWORD *)(*(_QWORD *)(a2 + 8) + 4LL * v3) != current_vmid
       || (~*(_DWORD *)(*(_QWORD *)(a2 + 16) + 4LL * v3) & 6) != 0 )
  {
    if ( *(_DWORD *)a2 == ++v3 )
      goto LABEL_8;
  }
  return 1;
}
