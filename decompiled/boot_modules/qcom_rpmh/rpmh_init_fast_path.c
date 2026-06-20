__int64 __fastcall rpmh_init_fast_path(__int64 a1, __int64 a2, int a3)
{
  unsigned int channel; // w2
  __int64 v4; // x8
  __int64 v7; // x21
  __int64 v9; // [xsp+0h] [xbp-20h] BYREF
  __int64 v10; // [xsp+8h] [xbp-18h]
  __int64 v11; // [xsp+10h] [xbp-10h]
  __int64 v12; // [xsp+18h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (rpmh_standalone & 1) != 0 )
  {
    channel = 0;
  }
  else
  {
    v4 = *(_QWORD *)(a1 + 96);
    v9 = 0;
    v10 = 0;
    v7 = *(_QWORD *)(v4 + 152);
    channel = rpmh_rsc_get_channel(v7);
    if ( (channel & 0x80000000) == 0 )
    {
      v11 = a2;
      HIDWORD(v9) = 0;
      LODWORD(v10) = a3;
      channel = rpmh_rsc_init_fast_path(v7, (__int64)&v9, channel);
    }
  }
  _ReadStatusReg(SP_EL0);
  return channel;
}
