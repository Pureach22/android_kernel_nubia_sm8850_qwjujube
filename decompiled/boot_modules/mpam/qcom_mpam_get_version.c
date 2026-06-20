__int64 __fastcall qcom_mpam_get_version(__int64 a1)
{
  _DWORD *v2; // x8
  __int64 v3; // x0

  if ( !ops )
    return 0xFFFFFFFFLL;
  v2 = *(_DWORD **)(ops + 8);
  v3 = ph;
  if ( *(v2 - 1) != 1134762728 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64, _QWORD, __int64))v2)(
           v3,
           a1,
           0x4D50414D4558544ELL,
           1,
           0,
           4);
}
