__int64 __fastcall cds_set_log_completion(unsigned int a1, unsigned int a2, __int64 a3, __int64 a4)
{
  char v4; // w22
  unsigned int v5; // w19
  __int64 v6; // x23
  unsigned int v9; // w22
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7

  v4 = a4;
  v5 = a3;
  v6 = gp_cds_context;
  if ( gp_cds_context || (printk(&unk_A3062F, "cds_get_global_context", a3, a4), (v6 = gp_cds_context) != 0) )
  {
    qdf_spinlock_acquire(v6 + 128);
    v9 = v4 & 1;
    *(_DWORD *)(v6 + 108) = a1;
    *(_DWORD *)(v6 + 112) = a2;
    *(_DWORD *)(v6 + 116) = v5;
    *(_BYTE *)(v6 + 121) = v9;
    *(_BYTE *)(v6 + 120) = 1;
    qdf_spinlock_release(v6 + 128);
    qdf_trace_msg(
      0x38u,
      8u,
      "%s: is_fatal %d indicator %d reason_code %d recovery needed %d",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "cds_set_log_completion",
      a1,
      a2,
      v5,
      v9);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: cds context is Invalid",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "cds_set_log_completion");
    return 16;
  }
}
