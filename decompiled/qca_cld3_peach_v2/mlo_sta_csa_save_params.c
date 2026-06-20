__int64 __fastcall mlo_sta_csa_save_params(
        __int64 a1,
        unsigned __int8 a2,
        const void *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned __int8 *v22; // x8
  char *v23; // x0
  int v24; // w9
  unsigned int v25; // w20
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x4
  __int64 v35; // x5
  const char *v36; // x2
  __int64 v37; // x6
  __int64 v38; // x7
  unsigned int v39; // w8
  char *v40; // x22
  int v42; // [xsp+0h] [xbp-10h]

  if ( a1 )
  {
    qdf_mutex_acquire(a1 + 1656);
    v22 = *(unsigned __int8 **)(a1 + 2224);
    if ( !v22 )
    {
      qdf_trace_msg(0x8Fu, 2u, "%s: invalid sta_ctx", v14, v15, v16, v17, v18, v19, v20, v21, "mlo_sta_csa_save_params");
      v25 = 4;
LABEL_20:
      qdf_mutex_release(a1 + 1656);
      return v25;
    }
    v23 = (char *)(v22 + 200);
    if ( (v22[239] & 1) != 0 || v22[237] == 1 )
    {
      if ( v22[236] == a2 )
      {
LABEL_14:
        qdf_mem_copy(v23, a3, 0x24u);
        v34 = *(unsigned __int8 *)(a1 + 17);
        v35 = *(unsigned __int8 *)(a1 + 18);
        v36 = "%s: mld mac %02x:%02x:%02x:**:**:%02x link id %d update csa";
        v37 = *(unsigned __int8 *)(a1 + 19);
        v38 = *(unsigned __int8 *)(a1 + 22);
        v42 = a2;
LABEL_19:
        qdf_trace_msg(
          0x8Fu,
          8u,
          v36,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "mlo_sta_csa_save_params",
          v34,
          v35,
          v37,
          v38,
          v42);
        v25 = 0;
        goto LABEL_20;
      }
      v24 = 0;
      if ( (v22[279] & 1) != 0 )
        goto LABEL_12;
    }
    else
    {
      v24 = 1;
      if ( (v22[279] & 1) != 0 )
        goto LABEL_12;
    }
    if ( (v22[277] & 1) == 0 )
    {
      v39 = v24 ^ 1;
      goto LABEL_18;
    }
LABEL_12:
    if ( v22[276] == a2 )
    {
      v23 = (char *)(v22 + 240);
      goto LABEL_14;
    }
    if ( (v24 & 1) == 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: no free buffer of csa param for link %d in sta_ctx",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "mlo_sta_csa_save_params",
        a2);
      v25 = 4;
      goto LABEL_20;
    }
    v39 = 0;
LABEL_18:
    v40 = &v23[40 * v39];
    qdf_mem_copy(v40, a3, 0x24u);
    v40[36] = a2;
    v36 = "%s: mld mac %02x:%02x:%02x:**:**:%02x link id %d RX csa";
    v40[39] = 1;
    v34 = *(unsigned __int8 *)(a1 + 17);
    v35 = *(unsigned __int8 *)(a1 + 18);
    v37 = *(unsigned __int8 *)(a1 + 19);
    v38 = *(unsigned __int8 *)(a1 + 22);
    v42 = a2;
    goto LABEL_19;
  }
  qdf_trace_msg(0x8Fu, 2u, "%s: invalid mlo_dev_ctx", a4, a5, a6, a7, a8, a9, a10, a11, "mlo_sta_csa_save_params");
  return 4;
}
