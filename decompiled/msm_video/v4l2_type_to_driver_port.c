__int64 __fastcall v4l2_type_to_driver_port(__int64 a1, unsigned int a2, __int64 a3)
{
  unsigned int v3; // w8

  v3 = a2 - 9;
  if ( a2 - 9 < 6 && ((0x33u >> v3) & 1) != 0 )
    return dword_9C0F4[v3];
  if ( !a1 || (msm_vidc_debug & 1) == 0 )
    return 4294967274LL;
  printk(&unk_86781, "err ", a1 + 340, a3, a2);
  return 4294967274LL;
}
