__int64 __fastcall rpmh_update_fast_path(__int64 a1, __int64 a2, int a3, unsigned int a4)
{
  unsigned int v4; // w3
  __int64 v5; // x8
  __int64 v9; // x22
  unsigned int channel; // w0
  __int64 v12; // [xsp+0h] [xbp-20h] BYREF
  __int64 v13; // [xsp+8h] [xbp-18h]
  __int64 v14; // [xsp+10h] [xbp-10h]
  __int64 v15; // [xsp+18h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (rpmh_standalone & 1) != 0 )
  {
    v4 = 0;
  }
  else
  {
    v5 = *(_QWORD *)(a1 + 96);
    v12 = 0;
    v13 = 0;
    v9 = *(_QWORD *)(v5 + 152);
    channel = rpmh_rsc_get_channel(v9);
    v4 = channel;
    if ( (channel & 0x80000000) == 0 )
    {
      v14 = a2;
      HIDWORD(v12) = 0;
      LODWORD(v13) = a3;
      v4 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD, _QWORD))rpmh_rsc_update_fast_path)(
             v9,
             &v12,
             a4,
             channel);
    }
  }
  _ReadStatusReg(SP_EL0);
  return v4;
}
