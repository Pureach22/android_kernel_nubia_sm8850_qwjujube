__int64 __fastcall sub_36EBF8(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8)
{
  __int64 v8; // x19
  __int64 v9; // x20
  __int64 v10; // x21
  __int64 v11; // x23
  __int64 v12; // x4
  int v13; // w24
  char v14; // w8
  __int64 v15; // x0

  v12 = *(unsigned int *)(v10 + 8);
  if ( (unsigned int)v12 > 7 )
  {
    v13 = 1;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: ts_info.up (%d) larger than max value (%d), use default ac_type (%d)",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "hdd_wmm_addts");
  }
  else
  {
    v13 = hdd_wmm_up_to_ac_map[v12];
  }
  *(_DWORD *)(v8 + 32) = v13;
  *(_QWORD *)(v8 + 24) = v9;
  *(_DWORD *)(v8 + 20) = 0;
  v14 = *(_BYTE *)(v10 + 20);
  strcpy((char *)(v8 + 72), "XMMW");
  *(_BYTE *)(v8 + 77) = v14;
  qdf_trace_msg(0x33u, 8u, "%s: Setting up QoS, context %pK", a1, a2, a3, a4, a5, a6, a7, a8, "hdd_wmm_addts", v8);
  v15 = mutex_lock(v9 + 1832);
  if ( *(_QWORD *)(*(_QWORD *)(v9 + 1816) + 8LL) != v11 || v8 == v11 )
    JUMPOUT(0x36F058);
  return sub_36ECB0(v15);
}
