__int64 __fastcall v4l2_type_to_driver(int a1, __int64 a2)
{
  int v2; // w8

  v2 = a1 - 9;
  if ( (unsigned int)(a1 - 9) < 6 && ((0x33u >> v2) & 1) != 0 )
    return dword_9C0DC[v2];
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_93B5F, "err ", 0xFFFFFFFFLL, "codec", a2);
  return 0;
}
