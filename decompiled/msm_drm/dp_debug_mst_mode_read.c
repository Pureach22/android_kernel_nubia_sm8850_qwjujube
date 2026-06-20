__int64 __fastcall dp_debug_mst_mode_read(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x8
  __int64 v8; // x9
  __int64 v9; // x8
  int v10; // w0
  __int64 result; // x0
  _QWORD v12[9]; // [xsp+8h] [xbp-48h] BYREF

  v12[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 32);
  v8 = *(_QWORD *)(v7 + 344);
  v9 = *(_QWORD *)(v7 + 120);
  memset(v12, 0, 64);
  v10 = scnprintf(
          v12,
          64,
          "mst_mode = %d, mst_state = %d\n",
          *(unsigned __int8 *)(v8 + 724),
          *(unsigned __int8 *)(v9 + 971));
  result = simple_read_from_buffer(a2, a3, a4, v12, v10);
  _ReadStatusReg(SP_EL0);
  return result;
}
