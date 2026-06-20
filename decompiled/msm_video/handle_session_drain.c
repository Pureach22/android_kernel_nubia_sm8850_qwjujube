__int64 __fastcall handle_session_drain(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v6; // x19

  if ( a1 && (*(_DWORD *)(a2 + 8) & 1) != 0 && (msm_vidc_debug & 2) != 0 )
  {
    v6 = a1;
    printk(&unk_80624, "high", a1 + 340, "handle_session_drain", a5);
    a1 = v6;
  }
  return msm_vidc_process_drain_done(a1);
}
