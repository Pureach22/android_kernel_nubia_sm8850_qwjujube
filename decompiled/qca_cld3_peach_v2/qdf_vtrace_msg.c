__int64 __fastcall qdf_vtrace_msg(unsigned int a1, unsigned int a2, __int64 a3, _QWORD *a4)
{
  __int64 v4; // x10
  __int64 v5; // x10
  __int64 result; // x0
  _QWORD v7[5]; // [xsp+8h] [xbp-28h] BYREF

  v7[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = a4[1];
  v7[0] = *a4;
  v7[1] = v4;
  v5 = a4[3];
  v7[2] = a4[2];
  v7[3] = v5;
  result = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, __int64, _QWORD *))qdf_trace_msg_cmn)(
             (unsigned int)qdf_pidx,
             a1,
             a2,
             a3,
             v7);
  _ReadStatusReg(SP_EL0);
  return result;
}
