__int64 __fastcall sps_map_find(_DWORD *a1)
{
  int v1; // w8
  __int64 i; // x20
  __int64 mem_ptr; // x0
  __int64 v5; // x8
  _DWORD *v6; // x9
  __int64 v8; // x23
  __int64 v9; // x10
  __int64 v10; // x10
  int v11; // w10
  __int64 v12; // x10

  v1 = qword_2C210;
  if ( !(_DWORD)qword_2C210 )
    return 0xFFFFFFFFLL;
  for ( i = sps_maps; *(_DWORD *)i != *a1 || *(_DWORD *)(i + 24) != a1[6] || *(_DWORD *)(i + 48) != a1[12]; i += 88 )
  {
    if ( !--v1 )
      return 0xFFFFFFFFLL;
  }
  mem_ptr = spsi_get_mem_ptr(*(_QWORD *)(i + 56));
  if ( !mem_ptr )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_map_find__rs, "sps_map_find")) )
    {
      printk(&unk_2357E, "sps_map_find", i + 56);
    }
    if ( sps )
      ipc_log_string(
        *(_QWORD *)(sps + 272),
        "%s: sps:Cannot get virt addr for I/O buffer: %pa\n",
        "sps_map_find",
        i + 56);
    return 0xFFFFFFFFLL;
  }
  if ( *(_DWORD *)(i + 80) && *(_QWORD *)(i + 72) != 3735928559LL )
  {
    v8 = mem_ptr;
    v5 = spsi_get_mem_ptr(*(_QWORD *)(i + 72));
    mem_ptr = v8;
    v6 = a1;
    if ( v5 )
      goto LABEL_20;
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_map_find__rs_4, "sps_map_find")) )
    {
      printk(&unk_25B06, "sps_map_find", i + 72);
    }
    if ( sps )
      ipc_log_string(
        *(_QWORD *)(sps + 272),
        "%s: sps:Can't get virt addr for I/O buffer: %pa\n",
        "sps_map_find",
        i + 72);
    return 0xFFFFFFFFLL;
  }
  v5 = 0;
  v6 = a1;
LABEL_20:
  if ( *(_QWORD *)v6 != 0x7FFFFFFFFFFFFFFFLL )
    v6[4] = *(_DWORD *)(i + 16);
  if ( *((_QWORD *)v6 + 3) != 0x7FFFFFFFFFFFFFFFLL )
    v6[10] = *(_DWORD *)(i + 40);
  if ( v6[11] )
    v9 = 44;
  else
    v9 = 20;
  v6[30] = *(_DWORD *)(i + v9);
  v6[20] = *(_DWORD *)(i + 64);
  v10 = *(_QWORD *)(i + 56);
  *((_QWORD *)v6 + 7) = mem_ptr;
  *((_QWORD *)v6 + 8) = v10;
  v11 = *(_DWORD *)(i + 80);
  if ( !v11 || *(_QWORD *)(i + 72) == 3735928559LL )
    return 0;
  v6[28] = v11;
  v12 = *(_QWORD *)(i + 72);
  *((_QWORD *)v6 + 11) = v5;
  *((_QWORD *)v6 + 12) = v12;
  return 0;
}
