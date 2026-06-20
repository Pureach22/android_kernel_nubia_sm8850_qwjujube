__int64 __fastcall qcom_mpam_get_platform_bw_ctrl(_QWORD *a1, _DWORD *a2)
{
  __int64 v3; // x0
  _DWORD *v4; // x8
  __int64 result; // x0
  _QWORD v6[5]; // [xsp+8h] [xbp-28h] BYREF

  v6[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( ops )
  {
    v6[0] = *a1;
    memset(&v6[1], 0, 24);
    v3 = ph;
    v4 = *(_DWORD **)(ops + 8);
    if ( *(v4 - 1) != 1134762728 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, _QWORD *, __int64, __int64, __int64, __int64))v4)(
               v3,
               v6,
               0x4D50414D4558544ELL,
               3,
               8,
               4);
    if ( !(_DWORD)result )
      *a2 = v6[0];
  }
  else
  {
    result = 0xFFFFFFFFLL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
