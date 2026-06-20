__int64 __fastcall dp_nud_set_gateway_addr(
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
  __int64 comp_private_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19
  __int64 result; // x0
  __int64 v21; // [xsp+0h] [xbp-10h] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LODWORD(v21) = a2;
  WORD2(v21) = WORD2(a2);
  if ( !a1 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: vdev is null", a3, a4, a5, a6, a7, a8, a9, a10, "dp_get_vdev_priv_obj", v21, v22);
    goto LABEL_5;
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Eu);
  if ( !comp_private_obj )
  {
LABEL_5:
    result = qdf_trace_msg(
               0x45u,
               2u,
               "%s: Unable to get DP link",
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               "dp_nud_set_gateway_addr",
               v21);
    goto LABEL_6;
  }
  v19 = *(_QWORD *)(comp_private_obj + 32);
  result = (__int64)qdf_mem_copy((void *)(v19 + 3512), &v21, 6u);
  *(_BYTE *)(v19 + 3569) = 1;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
