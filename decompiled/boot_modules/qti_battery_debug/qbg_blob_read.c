__int64 __fastcall qbg_blob_read(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x8
  __int64 result; // x0
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a2 + 152);
  v8[0] = a5;
  result = memory_read_from_buffer(a4, a6, v8, *(_QWORD *)(v6 + 4216), *(_QWORD *)(v6 + 4224));
  _ReadStatusReg(SP_EL0);
  return result;
}
