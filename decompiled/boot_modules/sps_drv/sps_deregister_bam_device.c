__int64 __fastcall sps_deregister_bam_device(_QWORD *a1, __int64 a2, __int64 a3)
{
  _QWORD *v3; // x0
  __int64 v4; // x2
  _QWORD *v5; // x19
  _QWORD *v6; // x8
  __int64 v7; // x9

  if ( !a1 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_deregister_bam_device__rs, "sps_deregister_bam_device")) )
    {
      printk(&unk_292C5, "sps_deregister_bam_device", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: device handle should not be 0\n", "sps_deregister_bam_device");
    return 0xFFFFFFFFLL;
  }
  v3 = sps_h2bam(a1);
  if ( !v3 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_deregister_bam_device__rs_207, "sps_deregister_bam_device")) )
    {
      printk(&unk_266E7, "sps_deregister_bam_device", v4);
    }
    if ( sps )
      ipc_log_string(
        *(_QWORD *)(sps + 272),
        "%s: sps: did not find a BAM for this handle\n",
        "sps_deregister_bam_device");
    return 0xFFFFFFFFLL;
  }
  v5 = v3;
  if ( (unsigned __int8)logging_option >= 2u
    && debug_level_option
    && (!print_limit_option || (unsigned int)__ratelimit(
                                               &sps_deregister_bam_device__rs_210,
                                               "sps_deregister_bam_device")) )
  {
    printk(&unk_293C4, "sps_deregister_bam_device", v5 + 3);
  }
  if ( sps && *(_DWORD *)(sps + 288) <= 3u )
    ipc_log_string(
      *(_QWORD *)(sps + 272),
      "%s: sps: SPS deregister BAM: phys %pa\n",
      "sps_deregister_bam_device",
      v5 + 3);
  if ( (*((_BYTE *)v5 + 17) & 1) != 0 )
  {
    kfree(v5[72]);
    kfree(v5[73]);
    kfree(v5[74]);
    kfree(v5[75]);
    kfree(v5[76]);
    kfree(v5[77]);
    kfree(v5[78]);
    kfree(v5[79]);
    kfree(v5[80]);
    kfree(v5[81]);
    kfree(v5[82]);
    kfree(v5[83]);
    kfree(v5[84]);
    kfree(v5[85]);
    kfree(v5[86]);
    kfree(v5[87]);
    kfree(v5[88]);
    kfree(v5[89]);
    kfree(v5[90]);
    kfree(v5[91]);
    kfree(v5[92]);
    kfree(v5[93]);
    kfree(v5[94]);
    kfree(v5[95]);
    kfree(v5[96]);
    kfree(v5[97]);
    kfree(v5[98]);
    kfree(v5[99]);
    kfree(v5[100]);
    kfree(v5[101]);
    kfree(v5[102]);
  }
  mutex_lock(sps + 112);
  v6 = (_QWORD *)v5[1];
  if ( (_QWORD *)*v6 == v5 && (v7 = *v5, *(_QWORD **)(*v5 + 8LL) == v5) )
  {
    *(_QWORD *)(v7 + 8) = v6;
    *v6 = v7;
  }
  else
  {
    _list_del_entry_valid_or_report(v5);
  }
  *v5 = 0xDEAD000000000100LL;
  v5[1] = 0xDEAD000000000122LL;
  mutex_unlock(sps + 112);
  mutex_lock(v5 + 21);
  sps_bam_device_de_init(v5);
  mutex_unlock(v5 + 21);
  ipc_log_context_destroy(v5[66]);
  ipc_log_context_destroy(v5[67]);
  ipc_log_context_destroy(v5[68]);
  ipc_log_context_destroy(v5[69]);
  ipc_log_context_destroy(v5[70]);
  if ( *((_DWORD *)v5 + 10) )
    iounmap(v5[4]);
  kfree(v5);
  return 0;
}
