__int64 __fastcall msm_vidc_update_core_state(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v3; // x19
  unsigned int v4; // w8
  __int64 v6; // x20

  if ( a2 >= 4 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_8C2D3, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_get_core_state_handle");
    return (unsigned int)-22;
  }
  else
  {
    v3 = (__int64)*(&off_9DDF8 + a2);
    if ( (msm_vidc_debug & 2) != 0 )
    {
      v6 = a1;
      printk(&unk_8B843, "high", 0xFFFFFFFFLL, "codec", a3);
      a2 = *(_DWORD *)v3;
      a1 = v6;
    }
    *(_DWORD *)(a1 + 3704) = a2;
    v4 = 0;
    *(_QWORD *)(a1 + 3712) = *(_QWORD *)(v3 + 8);
  }
  return v4;
}
