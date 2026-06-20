__int64 __fastcall qdf_dp_trace_credit_record(__int64 result, int a2, int a3, int a4, int a5, int a6)
{
  _DWORD v6[6]; // [xsp+0h] [xbp-20h] BYREF
  __int64 v7; // [xsp+18h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( byte_7F7658 == 1 && (unsigned int)(unsigned __int8)byte_7F7656 - 1 <= 3 && (dword_7F764C & 0x80) != 0 )
  {
    v6[0] = result;
    v6[1] = a2;
    v6[2] = a3;
    v6[3] = a4;
    v6[4] = a5;
    v6[5] = a6;
    result = ((__int64 (__fastcall *)(__int64, __int64, _DWORD *, __int64, _QWORD, _QWORD, _QWORD))qdf_dp_add_record)(
               12,
               255,
               v6,
               24,
               0,
               0,
               0);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
