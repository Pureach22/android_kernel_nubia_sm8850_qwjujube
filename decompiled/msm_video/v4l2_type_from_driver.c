__int64 __fastcall v4l2_type_from_driver(int a1, __int64 a2)
{
  if ( (unsigned int)(a1 - 1) < 4 )
    return dword_9E6FC[a1 - 1];
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_811DF, "err ", 0xFFFFFFFFLL, "codec", a2);
  return 0;
}
