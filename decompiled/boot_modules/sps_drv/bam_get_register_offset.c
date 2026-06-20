__int64 __fastcall bam_get_register_offset(__int64 a1, unsigned int a2, int a3)
{
  unsigned int v4; // w10
  int v5; // w9
  int v6; // w11

  if ( (unsigned int)bam_type >= 4 )
  {
    __break(0x5512u);
    goto LABEL_43;
  }
  if ( a1 == 216 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&bam_get_register_offset__rs, "bam_get_register_offset")) )
    {
      printk(&unk_27124, "bam_get_register_offset", 216);
    }
    if ( sps )
    {
      ipc_log_string(
        *(_QWORD *)(sps + 272),
        "%s: Failed to get dev for base addr 0x%pK\n",
        "bam_get_register_offset",
        &_ksymtab_sps_get_free_count);
      return 0xFFFFFFFFLL;
    }
    return 0xFFFFFFFFLL;
  }
  v4 = a2 & 0xFFFFFFFC;
  if ( a2 <= 0x17 )
    v5 = 0;
  else
    v5 = -1;
  if ( bam_type == 2 )
    v6 = 4096;
  else
    v6 = 128;
  if ( v4 == 24 )
    v5 = v6;
  if ( a2 - 28 <= 0x1D )
  {
    if ( bam_type )
    {
      v5 = 4096;
    }
    else if ( a2 <= 0x25 )
    {
      v5 = 128;
    }
    else
    {
      v5 = 64;
    }
    goto LABEL_36;
  }
  if ( a2 != 58 )
  {
    if ( a2 < 0x18 || v4 == 24 )
      goto LABEL_36;
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&bam_get_register_offset__rs_311, "bam_get_register_offset")) )
    {
      printk(&unk_26EF9, "bam_get_register_offset", a2);
    }
    ipc_log_string(*(_QWORD *)(a1 + 336), "%s: Failed to find register offset for %d\n", "bam_get_register_offset", a2);
    return 0xFFFFFFFFLL;
  }
  if ( bam_type == 2 )
    v5 = 4;
  else
    v5 = 4096;
  if ( !bam_type )
    v5 = 128;
LABEL_36:
  if ( 236LL * (unsigned int)bam_type + 4 * (unsigned __int64)a2 <= 0x2C3 )
    return (unsigned int)(bam_regmap[59 * bam_type + a2] + v5 * a3);
LABEL_43:
  __break(1u);
  return bam_pipe_exit();
}
