__int64 __fastcall msm_vidc_set_bitrate(__int64 a1)
{
  __int64 result; // x0
  int v2; // [xsp+4h] [xbp-Ch]
  __int64 v3; // [xsp+8h] [xbp-8h]

  v3 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a1 + 15456) & 0x10) == 0 && (*(_WORD *)(*(_QWORD *)(a1 + 1848) + 320LL) & 1) != 0 )
  {
    result = 0;
  }
  else
  {
    v2 = *(_QWORD *)(a1 + 15440);
    result = ((__int64 (*)(void))msm_vidc_packetize_control)();
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
