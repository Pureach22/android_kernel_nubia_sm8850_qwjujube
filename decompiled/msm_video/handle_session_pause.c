__int64 __fastcall handle_session_pause(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  if ( !a1 || (*(_DWORD *)(a2 + 8) & 1) == 0 || (msm_vidc_debug & 2) == 0 )
    return 0;
  printk(&unk_80624, "high", a1 + 340, "handle_session_pause", a5);
  return 0;
}
