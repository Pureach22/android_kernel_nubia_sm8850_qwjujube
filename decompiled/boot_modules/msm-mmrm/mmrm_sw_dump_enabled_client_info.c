__int64 __fastcall mmrm_sw_dump_enabled_client_info(__int64 result)
{
  unsigned __int64 v1; // x8
  __int64 v2; // x19
  unsigned __int64 v3; // x25
  __int64 v4; // x26
  __int64 v5; // x9

  v1 = *(unsigned int *)(result + 16);
  v2 = result;
  if ( !(_DWORD)v1 )
    goto LABEL_10;
  v3 = 0;
  v4 = 684;
  while ( 1 )
  {
    v5 = *(_QWORD *)(v2 + 8);
    if ( !*(_QWORD *)(v5 + v4 - 20) || (~msm_mmrm_debug & 0x10001) != 0 )
      goto LABEL_4;
    if ( *(_DWORD *)(v5 + v4 - 12) >= 9u || *(_DWORD *)(v2 + 76) > 8u )
      break;
    result = printk(&unk_DF54, "err ", "mmrm_sw_dump_enabled_client_info");
    v1 = *(unsigned int *)(v2 + 16);
LABEL_4:
    ++v3;
    v4 += 720;
    if ( v3 >= v1 )
      goto LABEL_10;
  }
  __break(0x5512u);
LABEL_10:
  if ( (~msm_mmrm_debug & 0x10001) == 0 )
    return printk(&unk_C7A4, "err ", "mmrm_sw_dump_enabled_client_info");
  return result;
}
