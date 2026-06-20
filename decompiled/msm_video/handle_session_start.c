__int64 __fastcall handle_session_start(__int64 a1, __int64 a2)
{
  if ( !a1 || (*(_DWORD *)(a2 + 8) & 1) == 0 || (msm_vidc_debug & 2) == 0 )
    return 0;
  printk(&unk_929C6, "high", a1 + 340, "handle_session_start", *(unsigned int *)(a2 + 16));
  return 0;
}
