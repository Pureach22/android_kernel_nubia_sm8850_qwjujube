// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_13F5E4(__int64 a1, __int64 a2, __int64 a3, const char *a4)
{
  __int64 v4; // x25

  if ( (v4 & 0x40000000000000LL) != 0 )
    return _drm_dev_dbg(0, 0, 0, a4);
  else
    return sde_mini_dump_add_va_region(a1, a2, a3);
}
