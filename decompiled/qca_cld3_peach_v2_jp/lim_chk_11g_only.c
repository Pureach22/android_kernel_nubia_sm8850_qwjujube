__int64 __fastcall lim_chk_11g_only(
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
  unsigned int v15; // w20
  __int64 v16; // x4
  __int64 v17; // x5
  __int64 v18; // x6
  __int64 v19; // x7
  __int64 v20; // x19
  unsigned __int8 *v21; // x22

  if ( *(_DWORD *)(a3 + 88) != 1 || *(_BYTE *)(a3 + 154) != 6 || !*(_BYTE *)(a4 + 3160) )
    return 1;
  if ( a2 )
  {
    v15 = a5;
    v16 = *a2;
    v17 = a2[1];
    v18 = a2[2];
    v19 = a2[5];
    v20 = a3;
    v21 = a2;
  }
  else
  {
    v21 = nullptr;
    v15 = a5;
    v20 = a3;
    v18 = 0;
    v16 = 0;
    v17 = 0;
    v19 = 0;
  }
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: SOFTAP was in 11G only mode, rejecting legacy STA: %02x:%02x:%02x:**:**:%02x",
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    "lim_chk_11g_only",
    v16,
    v17,
    v18,
    v19);
  lim_send_assoc_rsp_mgmt_frame(a1, 10, 1, v21, v15, 0, v20, 0, a4 + 3608);
  return 0;
}
