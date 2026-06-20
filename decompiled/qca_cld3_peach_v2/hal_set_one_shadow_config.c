__int64 __fastcall hal_set_one_shadow_config(
        __int64 a1,
        unsigned int a2,
        int a3,
        long double a4,
        long double a5,
        long double a6,
        long double a7,
        long double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x20
  __int64 v14; // x9
  unsigned int v16; // w22
  __int64 v17; // x8
  __int64 v18; // x10
  int v19; // w10
  int v20; // w8
  const char *v21; // x2

  v11 = *(unsigned int *)(a1 + 74220);
  if ( (int)v11 > 39 )
    return 1;
  v14 = *(_QWORD *)(a1 + 74256) + 36LL * (int)a2;
  *(_DWORD *)(a1 + 74220) = v11 + 1;
  if ( *(_DWORD *)(v14 + 24) == 1 )
    v16 = *(_DWORD *)(v14 + 12) + *(unsigned __int16 *)(v14 + 18) * a3 + 4;
  else
    v16 = *(_DWORD *)(v14 + 12) + *(unsigned __int16 *)(v14 + 18) * a3;
  if ( (unsigned int)v11 >= 0x28 )
    goto LABEL_17;
  *(_DWORD *)(a1 + 4 * v11 + 74060) = v16;
  v17 = *(_QWORD *)(a1 + 74256);
  v18 = v17 + 36LL * (int)a2;
  if ( *(unsigned __int16 *)(v18 + 4) <= a3 )
  {
    qdf_trace_msg(
      0x3Fu,
      4u,
      "%s: ring_num exceeded maximum no. of supported rings",
      *(double *)&a4,
      *(double *)&a5,
      *(double *)&a6,
      *(double *)&a7,
      *(double *)&a8,
      a9,
      a10,
      a11,
      "hal_get_srng_ring_id");
  }
  else
  {
    v19 = *(_DWORD *)v18 + a3;
    if ( v19 >= 0 )
    {
      if ( (unsigned int)v19 < 0xEE )
      {
        v20 = *(_DWORD *)(v17 + 36LL * (int)a2 + 24);
        *(_QWORD *)(a1 + 312LL * (unsigned int)v19 + 216) = *(_QWORD *)(a1 + 16) + 4 * v11 + 2300;
        if ( v20 == 1 )
          v21 = "%s: tp_addr=%pK dev base addr %pK index %u";
        else
          v21 = "%s: hp_addr=%pK dev base addr %pK index %u";
        qdf_trace_msg(
          0x46u,
          8u,
          v21,
          *(double *)&a4,
          *(double *)&a5,
          *(double *)&a6,
          *(double *)&a7,
          *(double *)&a8,
          a9,
          a10,
          a11,
          "hal_update_srng_hp_tp_address");
        goto LABEL_15;
      }
LABEL_17:
      __break(0x5512u);
      return hal_construct_srng_shadow_regs(a4, a5, a6, a7, a8, -6.3382e29);
    }
  }
LABEL_15:
  qdf_trace_msg(
    0x46u,
    8u,
    "%s: target_reg %x, shadow register 0x%x shadow_index 0x%x, ring_type %d, ring num %d",
    *(double *)&a4,
    *(double *)&a5,
    *(double *)&a6,
    *(double *)&a7,
    *(double *)&a8,
    a9,
    a10,
    a11,
    "hal_set_one_shadow_config",
    v16,
    (unsigned int)(4 * v11 + 2300),
    (unsigned int)v11,
    a2,
    a3);
  return 0;
}
