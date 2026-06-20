__int64 __fastcall sps_read_logging_option(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v7; // w0
  __int64 result; // x0
  _QWORD v9[11]; // [xsp+8h] [xbp-58h] BYREF

  v9[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v9, 0, 80);
  v7 = scnprintf(v9, 80, "%d\n", (unsigned __int8)logging_option);
  result = simple_read_from_buffer(a2, a3, a4, v9, v7);
  _ReadStatusReg(SP_EL0);
  return result;
}
