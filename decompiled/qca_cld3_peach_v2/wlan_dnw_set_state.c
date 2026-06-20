__int64 __fastcall wlan_dnw_set_state(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x4
  const char *v13; // x6
  const char *v14; // x7
  __int64 result; // x0

  v10 = *(unsigned int *)(a1 + 28);
  if ( (unsigned int)v10 > 3 )
  {
    v13 = "UNKNOWN";
    if ( a2 > 3 )
      goto LABEL_3;
LABEL_5:
    v14 = off_B2D690[a2];
    goto LABEL_6;
  }
  v13 = off_B2D690[v10];
  if ( a2 <= 3 )
    goto LABEL_5;
LABEL_3:
  v14 = "UNKNOWN";
LABEL_6:
  result = qdf_trace_msg(
             0x98u,
             8u,
             "%s: old %d new %d, %s->%s",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "wlan_dnw_set_state",
             v10,
             a2,
             v13,
             v14);
  *(_DWORD *)(a1 + 28) = a2;
  return result;
}
