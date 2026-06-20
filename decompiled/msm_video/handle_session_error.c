__int64 __fastcall handle_session_error(__int64 a1, __int64 a2)
{
  __int64 v3; // x19

  if ( a1 && (msm_vidc_debug & 1) != 0 )
  {
    v3 = a1;
    printk(&unk_972D1, "err ", a1 + 340, "handle_session_error", *(unsigned int *)(a2 + 4));
    a1 = v3;
  }
  return msm_vidc_change_state(a1, 5u, (__int64)"handle_session_error");
}
