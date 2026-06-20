__int64 __fastcall qcom_mpam_get_cache_partition(__int64 *a1, _QWORD *a2)
{
  __int64 v2; // x9
  __int64 v4; // x0
  __int64 (__fastcall *v5)(__int64, __int64 *, __int64, __int64, __int64, __int64); // x8
  __int64 result; // x0
  __int64 v7; // x9
  __int64 v8; // [xsp+8h] [xbp-28h] BYREF
  __int64 v9; // [xsp+10h] [xbp-20h]
  __int64 v10; // [xsp+18h] [xbp-18h]
  __int64 v11; // [xsp+20h] [xbp-10h]
  __int64 v12; // [xsp+28h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( ops )
  {
    v2 = *a1;
    v10 = 0;
    v11 = 0;
    v8 = v2;
    v9 = 0;
    v4 = ph;
    v5 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64, __int64, __int64, __int64))(ops + 8);
    if ( *((_DWORD *)v5 - 1) != 1134762728 )
      __break(0x8228u);
    result = v5(v4, &v8, 0x4D50414D4558544ELL, 2, 8, 16);
    if ( !(_DWORD)result )
    {
      v7 = v9;
      *a2 = v8;
      a2[1] = v7;
    }
  }
  else
  {
    result = 0xFFFFFFFFLL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
