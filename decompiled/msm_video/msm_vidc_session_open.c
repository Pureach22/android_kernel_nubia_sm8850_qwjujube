__int64 __fastcall msm_vidc_session_open(__int64 a1)
{
  __int64 v2; // x4
  __int64 v3; // x20
  __int64 v4; // x21
  __int64 v5; // x4
  unsigned int v6; // w20

  v3 = vzalloc_noprof(4096);
  if ( v3 )
  {
    v4 = *(_QWORD *)(a1 + 320);
    mutex_lock(v4 + 3856);
    *(_QWORD *)(a1 + 368) = v3;
    *(_DWORD *)(a1 + 376) = 4096;
    v6 = venus_hfi_session_open_locked(a1);
    if ( v6 )
    {
      if ( a1 && (msm_vidc_debug & 1) != 0 )
        printk(&unk_89031, "err ", a1 + 340, "msm_vidc_session_open", v5);
      vfree(*(_QWORD *)(a1 + 368));
      *(_QWORD *)(a1 + 368) = 0;
    }
    mutex_unlock(v4 + 3856);
  }
  else
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_92E2A, "err ", a1 + 340, "msm_vidc_session_open", v2);
    return (unsigned int)-12;
  }
  return v6;
}
