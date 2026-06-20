__int64 __fastcall msm_vidc_stats_handler(__int64 a1)
{
  __int64 result; // x0
  _QWORD *v2; // x19
  __int64 v3; // x1
  __int64 v4; // x2
  __int64 v5; // x3
  __int64 v6; // x4

  result = get_inst_ref(g_core, a1 - 3816);
  if ( result )
  {
    v2 = (_QWORD *)result;
    mutex_lock(result + 16);
    msm_vidc_print_stats((__int64)v2);
    schedule_stats_work(v2, v3, v4, v5, v6);
    mutex_unlock(v2 + 2);
    return put_inst(v2);
  }
  else if ( (msm_vidc_debug & 1) != 0 )
  {
    return printk(&unk_86867, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_stats_handler");
  }
  return result;
}
