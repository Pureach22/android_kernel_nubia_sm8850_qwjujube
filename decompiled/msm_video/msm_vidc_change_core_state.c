__int64 __fastcall msm_vidc_change_core_state(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 result; // x0
  unsigned int v7; // w20
  int v8; // w0

  result = _strict_check(a1, a3);
  if ( (_DWORD)result )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v7 = result;
      printk(&unk_955EF, "err ", 0xFFFFFFFFLL, "codec", a3);
      return v7;
    }
    return result;
  }
  if ( *(_DWORD *)(a1 + 3704) == a2 )
    return 0;
  v8 = msm_vidc_allow_core_state_change(a1, a2);
  if ( v8 )
  {
    if ( v8 != 4 )
      return msm_vidc_update_core_state(a1, a2, a3);
    if ( (msm_vidc_debug & 2) != 0 )
    {
      allow_name(4u);
      printk(&unk_87573, "high", 0xFFFFFFFFLL, "codec", a3);
      return 0;
    }
    return 0;
  }
  if ( (msm_vidc_debug & 1) != 0 )
  {
    allow_name(0);
    printk(&unk_87573, "err ", 0xFFFFFFFFLL, "codec", a3);
  }
  return 4294967274LL;
}
