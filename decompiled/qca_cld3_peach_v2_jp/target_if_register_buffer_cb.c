void *__fastcall target_if_register_buffer_cb(
        __int64 a1,
        const void *a2,
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
  __int64 v11; // x8
  __int64 (*v12)(void); // x8
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x19
  void *result; // x0
  __int64 v25; // x8
  const char *v26; // x2

  if ( !a1 )
  {
    v26 = "%s: pdev is null";
LABEL_12:
    qdf_trace_msg(0x56u, 2u, v26, a3, a4, a5, a6, a7, a8, a9, a10, "get_target_if_spectral_handle_from_pdev");
    return (void *)qdf_trace_msg(
                     0x56u,
                     2u,
                     "%s: SPECTRAL : Module doesn't exist",
                     v15,
                     v16,
                     v17,
                     v18,
                     v19,
                     v20,
                     v21,
                     v22,
                     "target_if_register_buffer_cb");
  }
  v10 = *(_QWORD *)(a1 + 80);
  if ( !v10 )
  {
    v26 = "%s: psoc is null";
    goto LABEL_12;
  }
  v11 = *(_QWORD *)(v10 + 2136);
  if ( !v11 )
  {
    v26 = "%s: rx_ops is null";
    goto LABEL_12;
  }
  v12 = *(__int64 (**)(void))(v11 + 256);
  if ( *((_DWORD *)v12 - 1) != 1565325861 )
    __break(0x8228u);
  v14 = v12();
  if ( !v14 )
    return (void *)qdf_trace_msg(
                     0x56u,
                     2u,
                     "%s: SPECTRAL : Module doesn't exist",
                     v15,
                     v16,
                     v17,
                     v18,
                     v19,
                     v20,
                     v21,
                     v22,
                     "target_if_register_buffer_cb");
  v23 = v14;
  result = qdf_mem_copy((void *)(v14 + 1264), a2, 0x40u);
  if ( *(_BYTE *)(v23 + 1328) == 1 )
    v25 = *(_QWORD *)(v23 + 1272);
  else
    v25 = *(_QWORD *)(v23 + 1280);
  *(_QWORD *)(v23 + 1336) = v25;
  return result;
}
