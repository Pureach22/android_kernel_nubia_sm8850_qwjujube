__int64 __fastcall sde_encoder_phys_cmd_enable(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19
  int v3; // w4
  void *v4; // x0

  if ( result && (v1 = *(_QWORD *)(result + 496), v2 = result, v1) )
  {
    if ( (_drm_debug & 4) != 0 )
    {
      if ( *(_QWORD *)result )
        v3 = *(_DWORD *)(*(_QWORD *)result + 24LL);
      else
        v3 = -1;
      result = _drm_dev_dbg(
                 0,
                 0,
                 0,
                 "enc%d intf%d pp %d\n",
                 v3,
                 *(_DWORD *)(result + 672) - 1,
                 *(_DWORD *)(v1 + 32) - 1);
    }
    if ( *(_DWORD *)(v2 + 832) != 4 )
    {
      result = sde_encoder_phys_cmd_enable_helper(v2);
      *(_DWORD *)(v2 + 832) = 4;
      return result;
    }
    if ( (*(_BYTE *)(v2 + 2289) & 1) != 0 )
      return result;
    v4 = &unk_25E8D6;
  }
  else
  {
    v4 = &unk_2385CA;
  }
  return printk(v4, "sde_encoder_phys_cmd_enable");
}
