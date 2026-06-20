__int64 __fastcall _watchdog_iris4(__int64 a1, char a2)
{
  if ( (a2 & 8) == 0 )
    return 0;
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_8A525, "err ", 0xFFFFFFFFLL, "codec", "__watchdog_iris4");
  return 1;
}
