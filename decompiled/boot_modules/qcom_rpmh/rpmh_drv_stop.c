__int64 __fastcall rpmh_drv_stop(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x1
  __int64 v3; // x2
  __int64 v4; // x3
  __int64 v5; // x4
  __int64 v6; // x5

  if ( (rpmh_standalone & 1) == 0 )
  {
    v1 = *(_QWORD *)(a1 + 152);
    if ( (unsigned int)rpmh_rsc_drv_enable(v1, 0) )
    {
      rpmh_rsc_debug_channel_busy(v1, v2, v3, v4, v5, v6);
      __break(0x800u);
      JUMPOUT(0xD438);
    }
  }
  return 0;
}
