__int64 __fastcall hdd_vdev_send_sta_keep_alive_interval(__int64 a1, __int64 a2, unsigned __int16 a3)
{
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  _QWORD v17[5]; // [xsp+8h] [xbp-28h] BYREF

  v17[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v17, 0, 32);
  qdf_mem_set(v17, 0x20u, 0);
  v6 = *(_QWORD *)(a2 + 16);
  v7 = *(unsigned __int8 *)(a1 + 8);
  HIDWORD(v17[0]) = a3;
  LOBYTE(v17[0]) = 1;
  result = sme_set_keep_alive(v6, v7, v17);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failure to execute Keep Alive",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "hdd_vdev_send_sta_keep_alive_interval");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
