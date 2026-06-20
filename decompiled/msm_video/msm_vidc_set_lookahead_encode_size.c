__int64 __fastcall msm_vidc_set_lookahead_encode_size(__int64 a1)
{
  __int64 result; // x0
  int v2; // [xsp+4h] [xbp-Ch]
  __int64 v3; // [xsp+8h] [xbp-8h]

  v3 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)(a1 + 35936) )
  {
    v2 = *(_QWORD *)(a1 + 36104);
    result = ((__int64 (*)(void))msm_vidc_packetize_control)();
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
