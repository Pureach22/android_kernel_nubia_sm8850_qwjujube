__int64 __fastcall handle_system_property(__int64 a1, _DWORD *a2)
{
  __int64 result; // x0
  __int64 i; // x8
  char v4; // w11

  if ( a2[1] != 50331649 )
  {
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_8BA15, "high", 0xFFFFFFFFLL, "codec", "handle_system_property");
    return 0;
  }
  if ( (unsigned int)(*a2 - 32) <= 0x7E )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_8BA52, "err ", 0xFFFFFFFFLL, "codec", "handle_image_version_property");
    return 4294967274LL;
  }
  for ( i = 0; i != 127; ++i )
  {
    v4 = *((_BYTE *)a2 + i + 32);
    if ( !v4 )
      v4 = 32;
    *(_BYTE *)(a1 + 3576 + i) = v4;
  }
  *(_BYTE *)(a1 + 3703) = 0;
  result = 0;
  if ( (msm_vidc_debug & 2) != 0 )
  {
    printk(&unk_8C585, "high", 0xFFFFFFFFLL, "codec", "handle_image_version_property");
    return 0;
  }
  return result;
}
