__int64 __fastcall _prepare_pc(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x4
  unsigned int v4; // w19
  __int64 v5; // x20
  __int64 v6; // x4

  result = hfi_packet_sys_pc_prep(a1, *(_QWORD *)(a1 + 6464), *(_DWORD *)(a1 + 6472));
  if ( (_DWORD)result )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v4 = result;
      printk(&unk_8A092, "err ", 0xFFFFFFFFLL, "codec", v3);
      return v4;
    }
  }
  else
  {
    v5 = *(_QWORD *)(a1 + 6464);
    if ( (unsigned int)_resume(a1) || (unsigned int)venus_hfi_queue_cmd_write(a1, v5) )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_846C1, "err ", 0xFFFFFFFFLL, "codec", v6);
      return 4294967257LL;
    }
    else
    {
      _schedule_power_collapse_work(a1);
      return 0;
    }
  }
  return result;
}
