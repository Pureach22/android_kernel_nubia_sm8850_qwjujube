__int64 __fastcall _strict_check(__int64 a1, __int64 a2)
{
  if ( (mutex_is_locked(a1 + 3856) & 1) != 0 )
    return 0;
  __break(0x800u);
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_94E60, "err ", 0xFFFFFFFFLL, "codec", a2);
  return 4294967274LL;
}
