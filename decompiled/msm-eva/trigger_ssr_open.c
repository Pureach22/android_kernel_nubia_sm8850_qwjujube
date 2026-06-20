__int64 __fastcall trigger_ssr_open(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  char v4; // w8

  v4 = msm_cvp_debug;
  *(_QWORD *)(a2 + 32) = *(_QWORD *)(a1 + 696);
  if ( (v4 & 4) == 0 || msm_cvp_debug_out )
    return 0;
  printk(&unk_8C057, "info", "trigger_ssr_open", a4);
  return 0;
}
