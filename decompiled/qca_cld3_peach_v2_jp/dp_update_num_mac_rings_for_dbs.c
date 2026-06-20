__int64 __fastcall dp_update_num_mac_rings_for_dbs(
        __int64 a1,
        int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 (__fastcall *v11)(_QWORD); // x8
  __int64 v12; // x0
  int v13; // w5
  __int64 v14; // x4

  v11 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 8) + 40LL);
  if ( !v11 )
    goto LABEL_6;
  v12 = *(_QWORD *)(a1 + 16);
  if ( *((_DWORD *)v11 - 1) != -1548408 )
    __break(0x8228u);
  if ( (v11(v12) & 1) != 0 )
  {
    v13 = *a2;
    v14 = 1;
  }
  else
  {
LABEL_6:
    v14 = 0;
    v13 = 1;
  }
  *a2 = v13;
  return qdf_trace_msg(
           0x45u,
           5u,
           "%s: dbs_enable %d, max_mac_rings %d",
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           "dp_update_num_mac_rings_for_dbs",
           v14);
}
