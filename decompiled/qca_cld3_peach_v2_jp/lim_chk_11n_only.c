__int64 __fastcall lim_chk_11n_only(
        __int64 a1,
        unsigned __int8 *a2,
        __int64 a3,
        __int64 a4,
        unsigned int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  unsigned int v16; // w20
  __int64 v17; // x4
  __int64 v18; // x5
  __int64 v19; // x6
  __int64 v20; // x7
  __int64 v21; // x19
  unsigned __int8 *v22; // x22

  if ( *(_DWORD *)(a3 + 88) != 1 || *(_BYTE *)(a3 + 154) != 7 || *(_BYTE *)(a4 + 3160) )
    return 1;
  if ( a2 )
  {
    v16 = a5;
    v17 = *a2;
    v18 = a2[1];
    v19 = a2[2];
    v20 = a2[5];
    v21 = a3;
    v22 = a2;
  }
  else
  {
    v22 = nullptr;
    v16 = a5;
    v21 = a3;
    v19 = 0;
    v17 = 0;
    v18 = 0;
    v20 = 0;
  }
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: SOFTAP was in 11N only mode, rejecting legacy STA: %02x:%02x:%02x:**:**:%02x",
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    "lim_chk_11n_only",
    v17,
    v18,
    v19,
    v20);
  lim_send_assoc_rsp_mgmt_frame(a1, 10, 1, v22, v16, 0, v21, 0, a4 + 3608);
  return 0;
}
