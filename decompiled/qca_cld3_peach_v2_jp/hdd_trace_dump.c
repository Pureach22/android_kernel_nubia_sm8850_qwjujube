__int64 __fastcall hdd_trace_dump(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10,
        unsigned __int16 a11)
{
  unsigned int v11; // w8
  __int64 v12; // x19
  unsigned int v14; // w20
  const char *e_roam_cmd_status_str; // x8
  const char *v17; // x7
  __int64 v18; // x3
  __int64 v19; // x5
  int v21; // [xsp+8h] [xbp-8h]

  v11 = *((unsigned __int16 *)a10 + 14);
  v12 = *a10;
  v14 = *((unsigned __int16 *)a10 + 15);
  if ( v11 == 74 )
  {
    e_roam_cmd_status_str = (const char *)get_e_roam_cmd_status_str(*((unsigned int *)a10 + 8));
    v17 = "RX SME MSG:";
    v21 = *((_DWORD *)a10 + 8);
    v18 = a11;
    v19 = (__int64)(a10 + 1);
  }
  else
  {
    if ( v11 > 0x49 )
      e_roam_cmd_status_str = "UNKNOWN";
    else
      e_roam_cmd_status_str = off_A08E78[*((unsigned __int16 *)a10 + 14)];
    v17 = "HDD Event:";
    v18 = a11;
    v19 = (__int64)(a10 + 1);
    v21 = *((_DWORD *)a10 + 8);
  }
  return qdf_trace_msg(
           0x33u,
           8u,
           "%04d %012llu %s S%d %-14s %-30s(0x%x)",
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           v18,
           v12,
           v19,
           v14,
           v17,
           e_roam_cmd_status_str,
           v21);
}
