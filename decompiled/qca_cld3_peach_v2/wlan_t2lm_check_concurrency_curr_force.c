__int64 __fastcall wlan_t2lm_check_concurrency_curr_force(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x20
  __int64 v12; // x21
  __int64 v13; // x19
  unsigned int v14; // w0
  unsigned int v15; // w19
  __int64 v16; // x21
  __int64 v17; // x19
  unsigned int v18; // w0
  const char *v19; // x2

  v10 = *(_QWORD *)(a1 + 216);
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 80)) == 0 )
  {
    v15 = 29;
    v19 = "%s: psoc null";
LABEL_14:
    qdf_trace_msg(0x99u, 2u, v19, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_t2lm_check_concurrency_curr_force");
    return v15;
  }
  if ( !a2 )
  {
    v15 = 29;
    v19 = "%s: t2lm neg ptr is null";
    goto LABEL_14;
  }
  if ( a2 != -8 && *(_DWORD *)(a2 + 8) != 4 )
  {
    v12 = a1;
    v13 = a2;
    v14 = ml_nlink_pre_t2lm_request(v11, *(unsigned __int8 *)(a1 + 168), *(unsigned __int16 *)(a2 + 24));
    a2 = v13;
    v15 = v14;
    a1 = v12;
    if ( v15 )
      goto LABEL_18;
  }
  if ( a2 != -60 && *(_DWORD *)(a2 + 60) != 4 )
  {
    v16 = a1;
    v17 = a2;
    v18 = ml_nlink_pre_t2lm_request(v11, *(unsigned __int8 *)(a1 + 168), *(unsigned __int16 *)(a2 + 76));
    a2 = v17;
    v15 = v18;
    a1 = v16;
    if ( v15 )
    {
LABEL_18:
      v19 = "%s: link tid & force inactive link match";
      goto LABEL_14;
    }
  }
  if ( a2 != -112 && *(_DWORD *)(a2 + 112) != 4 )
  {
    v15 = ml_nlink_pre_t2lm_request(v11, *(unsigned __int8 *)(a1 + 168), *(unsigned __int16 *)(a2 + 128));
    if ( !v15 )
      return v15;
    goto LABEL_18;
  }
  return 0;
}
