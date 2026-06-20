__int64 __fastcall _acquire_regulator(_QWORD *a1)
{
  __int64 result; // x0
  unsigned int v3; // w19

  if ( *((_BYTE *)a1 + 16) != 1 )
    return 0;
  if ( (unsigned int)regulator_get_mode(*a1) == 2 )
  {
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_90310, "high", 0xFFFFFFFFLL, "codec", a1[1]);
    return 0;
  }
  result = regulator_set_mode(*a1, 2);
  if ( (_DWORD)result )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v3 = result;
      printk(&unk_8D093, "err ", 0xFFFFFFFFLL, "codec", "__acquire_regulator");
      return v3;
    }
  }
  else
  {
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_80986, "high", 0xFFFFFFFFLL, "codec", "__acquire_regulator");
    if ( (unsigned int)regulator_is_enabled(*a1) )
      return 0;
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_8AD1E, "err ", 0xFFFFFFFFLL, "codec", "__acquire_regulator");
    __break(0x800u);
    return 0;
  }
  return result;
}
