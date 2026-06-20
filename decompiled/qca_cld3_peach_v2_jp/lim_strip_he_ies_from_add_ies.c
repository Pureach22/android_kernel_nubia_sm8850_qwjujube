__int64 __fastcall lim_strip_he_ies_from_add_ies(__int64 a1, __int64 a2)
{
  unsigned int v4; // w0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // [xsp+8h] [xbp-58h] BYREF
  __int64 v23; // [xsp+10h] [xbp-50h]
  int v24; // [xsp+18h] [xbp-48h]
  _QWORD v25[8]; // [xsp+20h] [xbp-40h] BYREF

  v25[7] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v25, 0, 56);
  LOBYTE(v24) = 0;
  v22 = 0;
  v23 = 0;
  qdf_mem_set(v25, 0x38u, 0);
  qdf_mem_set(&v22, 0x11u, 0);
  v4 = lim_strip_ie(a1, *(_QWORD *)(a2 + 7328), a2 + 7320, 255, 1, "#", 1, v25, 54, v22, v23, v24);
  if ( v4 )
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Failed to strip HE cap IE status: %d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "lim_strip_he_ies_from_add_ies",
      v4);
  result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64, __int64, const char *, __int64, __int64 *, int))lim_strip_ie)(
             a1,
             *(_QWORD *)(a2 + 7328),
             a2 + 7320,
             255,
             1,
             "$",
             1,
             &v22,
             15);
  if ( (_DWORD)result )
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: Failed to strip HE op IE status: %d",
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               "lim_strip_he_ies_from_add_ies",
               (unsigned int)result);
  _ReadStatusReg(SP_EL0);
  return result;
}
