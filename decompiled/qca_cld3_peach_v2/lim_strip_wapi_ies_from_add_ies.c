__int64 __fastcall lim_strip_wapi_ies_from_add_ies(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _QWORD v13[33]; // [xsp+8h] [xbp-108h] BYREF

  v13[32] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v13, 0, 255);
  qdf_mem_set(v13, 0xFFu, 0);
  result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64, __int64, _QWORD, _QWORD, _QWORD *, int))lim_strip_ie)(
             a1,
             *(_QWORD *)(a2 + 7328),
             a2 + 7320,
             68,
             1,
             0,
             0,
             v13,
             253);
  if ( (_DWORD)result )
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: Failed to strip WAPI IE status: %d",
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               "lim_strip_wapi_ies_from_add_ies",
               (unsigned int)result);
  _ReadStatusReg(SP_EL0);
  return result;
}
