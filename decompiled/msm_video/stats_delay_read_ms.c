__int64 __fastcall stats_delay_read_ms(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  int v8; // w0
  __int64 result; // x0
  _QWORD v10[3]; // [xsp+8h] [xbp-18h] BYREF

  v10[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  memset(v10, 0, 15);
  if ( v4 )
  {
    v8 = scnprintf(v10, 15, "%llu\n", *(_QWORD *)(v4 + 4512));
    result = simple_read_from_buffer(a2, a3, a4, v10, v8);
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_83566, "err ", 0xFFFFFFFFLL, "codec", "stats_delay_read_ms");
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
