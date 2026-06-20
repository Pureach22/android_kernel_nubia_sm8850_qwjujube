__int64 __fastcall get_rc_table_index(__int64 a1, int a2)
{
  int v2; // w8
  int v3; // w4
  __int64 i; // x9

  if ( *(_BYTE *)(a1 + 127) == 1 )
  {
    if ( (*(_BYTE *)(a1 + 128) & 1) != 0 )
    {
      v2 = 1;
    }
    else if ( *(_BYTE *)(a1 + 129) )
    {
      v2 = 2;
    }
    else
    {
      v2 = 0;
    }
    v3 = *(unsigned __int8 *)(a1 + 126);
    for ( i = 0; i != 384; i += 24 )
    {
      if ( *(_DWORD *)((char *)&sde_dsc_index_map + i + 8) == v3
        && v2 == *(_DWORD *)((char *)&sde_dsc_index_map + i)
        && *(_DWORD *)((char *)&sde_dsc_index_map + i + 12) == *(unsigned __int8 *)(a1 + 1)
        && *(_DWORD *)((char *)&sde_dsc_index_map + i + 16) == *(unsigned __int16 *)(a1 + 16) >> 4
        && (v3 != 1 || *(_DWORD *)((char *)&sde_dsc_index_map + i + 4) == a2) )
      {
        return *(unsigned int *)((char *)&sde_dsc_index_map + i + 20);
      }
    }
    if ( (_drm_debug & 4) != 0 )
      printk(&unk_2361D2, 1);
    else
      printk(&unk_2286CA, "_get_rc_table_index");
  }
  else
  {
    printk(&unk_23CE43, "_get_rc_table_index");
  }
  return 4294967274LL;
}
