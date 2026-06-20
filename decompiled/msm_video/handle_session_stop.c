__int64 __fastcall handle_session_stop(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  int v5; // w8
  __int64 v6; // x4
  __int64 v8; // x19
  __int64 v9; // x20

  if ( a1 && (*(_DWORD *)(a2 + 8) & 1) != 0 && (msm_vidc_debug & 2) != 0 )
  {
    v8 = a1;
    v9 = a2;
    printk(&unk_929C6, "high", a1 + 340, "handle_session_stop", *(unsigned int *)(a2 + 16));
    a2 = v9;
    a1 = v8;
  }
  v5 = *(_DWORD *)(a1 + 308);
  if ( v5 == 2 )
  {
    v6 = *(unsigned int *)(a2 + 16);
    if ( (_DWORD)v6 == 2 )
      return msm_vidc_process_stop_done(a1, 1u);
    if ( (_DWORD)v6 != 1 )
      goto LABEL_17;
    return msm_vidc_process_stop_done(a1, 0);
  }
  if ( v5 != 1 )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_8DDBA, "err ", a1 + 340, "handle_session_stop", a5);
    return 4294967274LL;
  }
  v6 = *(unsigned int *)(a2 + 16);
  if ( (_DWORD)v6 == 2 )
    return msm_vidc_process_stop_done(a1, 0);
  if ( (_DWORD)v6 == 1 )
    return msm_vidc_process_stop_done(a1, 1u);
LABEL_17:
  if ( a1 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_833BC, "err ", a1 + 340, "handle_session_stop", v6);
  }
  return 4294967274LL;
}
