__int64 __fastcall sps_map_init(__int64 a1, int a2)
{
  __int64 v2; // x2
  _QWORD *v3; // x9

  sps_maps = 0;
  qword_2C210 = 0;
  if ( !a1 )
    return 0;
  v2 = 0;
  sps_maps = a1;
  v3 = (_QWORD *)(a1 + 8);
  HIDWORD(qword_2C210) = a2;
  while ( *((_DWORD *)v3 - 2) != -559038737 || *v3 != 3735928559LL )
  {
    v2 = (unsigned int)(v2 + 1);
    v3 += 11;
    LODWORD(qword_2C210) = v2;
  }
  if ( (unsigned __int8)logging_option >= 2u && (unsigned __int8)debug_level_option >= 4u )
  {
    if ( print_limit_option )
    {
      if ( !(unsigned int)__ratelimit(&sps_map_init__rs, "sps_map_init") )
        goto LABEL_7;
      v2 = (unsigned int)qword_2C210;
    }
    printk(&unk_283C5, "sps_map_init", v2);
  }
LABEL_7:
  if ( sps && !*(_DWORD *)(sps + 288) )
    ipc_log_string(*(_QWORD *)(sps + 248), "%s: sps: %d mappings\n", "sps_map_init", qword_2C210);
  return 0;
}
