__int64 __fastcall wlan_mlme_get_cfg_str(
        void *a1,
        __int64 a2,
        size_t *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  size_t v12; // x4
  size_t v13; // x2

  v12 = *a3;
  v13 = *(_QWORD *)(a2 + 8);
  if ( v12 >= v13 )
  {
    *a3 = v13;
    qdf_mem_copy(a1, (const void *)(a2 + 16), v13);
    return 0;
  }
  else
  {
    qdf_trace_msg(0x1Fu, 2u, "%s: Invalid len %zd", a4, a5, a6, a7, a8, a9, a10, a11, "wlan_mlme_get_cfg_str");
    return 4;
  }
}
