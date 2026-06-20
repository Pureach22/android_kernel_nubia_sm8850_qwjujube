__int64 __fastcall sps_bam_lock(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v5; // x20

  v3 = *(_QWORD *)(a1 + 24);
  if ( !v3 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_bam_lock__rs, "sps_bam_lock")) )
    {
      printk(&unk_29A50, "sps_bam_lock", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: Connection is not in connected state\n", "sps_bam_lock");
    return 0;
  }
  *(_QWORD *)(v3 + 240) = raw_spin_lock_irqsave(v3 + 232);
  v5 = *(unsigned int *)(a1 + 188);
  if ( (unsigned int)v5 >= *(_DWORD *)(v3 + 48) )
  {
LABEL_5:
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_bam_lock__rs_259, "sps_bam_lock")) )
    {
      printk(&unk_261F7, "sps_bam_lock", v3 + 24);
    }
    ipc_log_string(
      *(_QWORD *)(v3 + 552),
      "%s: sps:Client not owner of BAM %pa pipe: %d (max %d)\n",
      "sps_bam_lock",
      (const void *)(v3 + 24),
      v5,
      *(_DWORD *)(v3 + 48));
    raw_spin_unlock_irqrestore(v3 + 232, *(_QWORD *)(v3 + 240));
    return 0;
  }
  if ( (unsigned int)v5 < 0x1F )
  {
    if ( *(_QWORD *)(v3 + 8 * v5 + 256) == a1 )
      return v3;
    goto LABEL_5;
  }
  __break(0x5512u);
  return sps_flow_on();
}
