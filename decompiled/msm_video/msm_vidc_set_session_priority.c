__int64 __fastcall msm_vidc_set_session_priority(__int64 a1, unsigned int a2)
{
  __int64 v2; // x10
  __int64 v3; // x8
  __int64 result; // x0
  int v5; // [xsp+4h] [xbp-Ch]
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 >= 0xC6 )
    __break(0x5512u);
  v2 = *(_QWORD *)(a1 + 33752);
  v3 = *(_QWORD *)(a1 + 168LL * a2 + 4352);
  v5 = v3;
  if ( !v2 )
    v5 = *(_DWORD *)(a1 + 33584) + v3;
  result = ((__int64 (*)(void))msm_vidc_packetize_control)();
  _ReadStatusReg(SP_EL0);
  return result;
}
