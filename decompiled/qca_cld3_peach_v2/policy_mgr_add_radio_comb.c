unsigned int *__fastcall policy_mgr_add_radio_comb(
        unsigned int *result,
        unsigned __int8 *a2,
        int a3,
        int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        __int64 a13,
        int a14,
        int a15,
        int a16,
        __int64 a17)
{
  __int64 v17; // x4
  unsigned int *v18; // x19
  __int64 v20; // x10
  __int64 v21; // x8
  int v22; // [xsp+0h] [xbp-10h]
  int v23; // [xsp+8h] [xbp-8h]

  v17 = result[382];
  v18 = result;
  if ( (_DWORD)v17 )
  {
    v20 = 0;
    while ( v20 != 34 )
    {
      if ( *(_DWORD *)a2 == result[v20 + 383]
        && a2[4] == LOBYTE(result[v20 + 384])
        && a2[5] == BYTE1(result[v20 + 384])
        && a2[6] == BYTE2(result[v20 + 384])
        && a2[7] == HIBYTE(result[v20 + 384]) )
      {
        return result;
      }
      v20 += 2;
      if ( 2 * v17 == v20 )
      {
        if ( (_DWORD)v17 != 16 )
          goto LABEL_13;
        return (unsigned int *)qdf_trace_msg(
                                 0x4Fu,
                                 2u,
                                 "%s: radio combination overflow %d",
                                 a5,
                                 a6,
                                 a7,
                                 a8,
                                 a9,
                                 a10,
                                 a11,
                                 a12,
                                 "policy_mgr_add_radio_comb");
      }
    }
    goto LABEL_16;
  }
LABEL_13:
  v22 = a2[5];
  v23 = a2[7];
  LODWORD(result) = qdf_trace_msg(
                      0x4Fu,
                      8u,
                      "%s: radio %d: mode %d mac0 (0x%x, 0x%x), mac1 (0x%x 0x%x)",
                      a5,
                      a6,
                      a7,
                      a8,
                      a9,
                      a10,
                      a11,
                      a12,
                      "policy_mgr_add_radio_comb",
                      v22,
                      v23);
  v21 = v18[382];
  if ( (unsigned int)v21 > 0x10 )
  {
LABEL_16:
    __break(0x5512u);
    return (unsigned int *)policy_mgr_mlo_sta_set_link_by_linkid((int)result, (int)a2, a3, a4, v17, a14, a15, a16, a17);
  }
  result = (unsigned int *)qdf_mem_copy(&v18[2 * v21 + 383], a2, 8u);
  ++v18[382];
  return result;
}
