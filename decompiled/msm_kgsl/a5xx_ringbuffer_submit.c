unsigned __int64 __fastcall a5xx_ringbuffer_submit(_DWORD *a1, _QWORD *a2, char a3)
{
  _DWORD *v6; // x22
  unsigned __int64 result; // x0
  __int64 v8; // x20

  v6 = &a1[-330 * a1[7]];
  adreno_get_submit_time(v6 - 3588, a1, a2);
  adreno_profile_submit_time(a2);
  if ( (a3 & 1) != 0 )
  {
    result = adreno_ringbuffer_allocspace(a1, 3);
    if ( result >= 0xFFFFFFFFFFFFF001LL )
      return result;
    *(_DWORD *)result = 1885470722;
    *(_QWORD *)(result + 4) = *(_QWORD *)(*((_QWORD *)v6 - 1788) + 24LL) + 32LL * (int)a1[7];
  }
  v8 = raw_spin_lock_irqsave(a1 + 323);
  if ( !v6[1534] && *((_DWORD **)v6 + 661) == a1 )
    kgsl_regmap_write(v6 - 288, (unsigned int)a1[4]);
  a1[5] = a1[4];
  raw_spin_unlock_irqrestore(a1 + 323, v8);
  return 0;
}
