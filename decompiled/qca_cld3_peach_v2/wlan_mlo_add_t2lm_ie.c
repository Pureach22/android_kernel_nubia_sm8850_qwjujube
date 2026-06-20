char *__fastcall wlan_mlo_add_t2lm_ie(
        char *result,
        unsigned int *a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w9
  const char *v12; // x2
  __int64 v13; // x19
  unsigned int *v14; // x20
  unsigned int *v15; // x20
  unsigned int *v16; // x1
  unsigned int v17; // t1

  if ( !result )
  {
    v12 = "%s: frm is null";
    goto LABEL_11;
  }
  if ( !a2 )
  {
    v12 = "%s: t2lm is null";
    goto LABEL_11;
  }
  v11 = a2[2];
  if ( (!v11 || a2[15] == 1) && a2[28] == 2 )
  {
    v12 = "%s: Both DL/UL and BIDI T2LM IEs should not be present at the same time";
LABEL_11:
    qdf_trace_msg(0x99u, 2u, v12, a4, a5, a6, a7, a8, a9, a10, a11, "wlan_mlo_add_t2lm_ie");
    return nullptr;
  }
  if ( v11 == 4 )
  {
    v13 = a3;
  }
  else
  {
    v14 = a2;
    v13 = a3;
    result = wlan_mlo_add_t2lm_info_ie((__int64)result, a2 + 2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
    a2 = v14;
  }
  if ( a2[15] != 4 )
  {
    v15 = a2;
    result = wlan_mlo_add_t2lm_info_ie((__int64)result, a2 + 15, v13, a4, a5, a6, a7, a8, a9, a10, a11);
    a2 = v15;
  }
  v17 = a2[28];
  v16 = a2 + 28;
  if ( v17 != 4 )
    return wlan_mlo_add_t2lm_info_ie((__int64)result, v16, v13, a4, a5, a6, a7, a8, a9, a10, a11);
  return result;
}
