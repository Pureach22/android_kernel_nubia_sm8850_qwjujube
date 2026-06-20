__int64 __fastcall msm_cvp_scale_clocks(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int v4; // w1
  unsigned int v6; // w19
  __int64 v7; // x20

  v4 = *(_DWORD *)(a1 + 24);
  if ( !v4 )
    v4 = **(_DWORD **)(*(_QWORD *)(a1 + 2208) + 160LL);
  if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
  {
    v6 = v4;
    v7 = a1;
    printk(&unk_8EDB6, &unk_8DA84, "msm_cvp_scale_clocks", v4);
    v4 = v6;
    a1 = v7;
  }
  return msm_cvp_set_clocks_impl(a1, v4, a3, a4);
}
