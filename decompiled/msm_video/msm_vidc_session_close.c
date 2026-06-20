__int64 __fastcall msm_vidc_session_close(_QWORD *a1)
{
  __int64 v1; // x21
  unsigned int v3; // w0
  __int64 v4; // x4
  unsigned int v5; // w20
  __int64 v6; // x0
  __int64 v7; // x4
  __int64 v8; // x4
  __int64 v9; // x0

  v1 = a1[40];
  v3 = venus_hfi_session_close();
  if ( v3 )
  {
    v5 = v3;
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_868C2, "err ", (char *)a1 + 340, "msm_vidc_session_close", v4);
  }
  else
  {
    if ( a1 && (msm_vidc_debug & 2) != 0 )
      printk(&unk_93C65, "high", (char *)a1 + 340, "msm_vidc_session_close", *(_QWORD *)(v1 + 4352));
    mutex_unlock(a1 + 2);
    v6 = _msecs_to_jiffies(*(unsigned int *)(v1 + 4352));
    if ( (unsigned int)wait_for_completion_timeout(a1 + 4706, v6) )
    {
      if ( a1 && (msm_vidc_debug & 2) != 0 )
        printk(&unk_81386, "high", (char *)a1 + 340, "msm_vidc_session_close", v7);
      v5 = 0;
    }
    else
    {
      if ( a1 && (msm_vidc_debug & 1) != 0 )
        printk(&unk_8FEA4, "err ", (char *)a1 + 340, "msm_vidc_session_close", v7);
      msm_vidc_inst_timeout(a1);
      v5 = -110;
    }
    mutex_lock(a1 + 2);
  }
  mutex_lock(v1 + 3856);
  v9 = a1[46];
  if ( v9 )
  {
    if ( a1 && (msm_vidc_debug & 2) != 0 )
    {
      printk(&unk_909E7, "high", (char *)a1 + 340, "msm_vidc_session_close", v8);
      v9 = a1[46];
    }
    vfree(v9);
    a1[46] = 0;
  }
  mutex_unlock(v1 + 3856);
  return v5;
}
