void *__fastcall lim_update_connect_rsn_ie(__int64 a1, const void *a2, __int64 a3)
{
  char *v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7

  v5 = wlan_crypto_build_rsnie_with_pmksa(*(_QWORD *)(a1 + 16), (__int64)a2, a3);
  if ( !v5 )
    return (void *)qdf_trace_msg(
                     0x35u,
                     8u,
                     "%s: Build RSN IE failed",
                     v6,
                     v7,
                     v8,
                     v9,
                     v10,
                     v11,
                     v12,
                     v13,
                     "lim_update_connect_rsn_ie");
  **(_WORD **)(a1 + 112) = (_WORD)v5 - (_WORD)a2;
  return qdf_mem_copy((void *)(*(_QWORD *)(a1 + 112) + 2LL), a2, (unsigned __int16)((_WORD)v5 - (_WORD)a2));
}
