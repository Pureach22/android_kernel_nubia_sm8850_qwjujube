__int64 __fastcall _schedule_power_collapse_work(__int64 result, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x19
  __int64 v6; // x20
  __int64 v7; // x0
  void *v8; // x0
  const char *v9; // x1

  if ( !*(_QWORD *)(result + 4288) )
  {
    if ( (msm_vidc_debug & 4) == 0 )
      return result;
    v8 = &unk_88968;
    v9 = "low ";
    return printk(v8, v9, 0xFFFFFFFFLL, "codec", a5);
  }
  v5 = result;
  v6 = *(_QWORD *)(result + 6216);
  v7 = _msecs_to_jiffies(*(unsigned int *)(result + 4304));
  result = mod_delayed_work_on(32, v6, v5 + 6112, v7);
  if ( (result & 1) == 0 )
  {
    if ( (msm_vidc_debug & 2) == 0 )
      return result;
    v8 = &unk_93489;
    v9 = "high";
    return printk(v8, v9, 0xFFFFFFFFLL, "codec", a5);
  }
  if ( (msm_vidc_debug & 4) != 0 )
    return printk(&unk_94F12, "low ", 0xFFFFFFFFLL, "codec", *(_QWORD *)(v5 + 4304));
  return result;
}
