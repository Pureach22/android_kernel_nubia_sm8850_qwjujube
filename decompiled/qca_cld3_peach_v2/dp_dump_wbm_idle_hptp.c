__int64 __fastcall dp_dump_wbm_idle_hptp(
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
  void (*v10)(void); // x8
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  const char *v20; // x2
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v20 = "%s: soc is NULL";
LABEL_10:
    result = qdf_trace_msg(0x45u, 2u, v20, a3, a4, a5, a6, a7, a8, a9, a10, "dp_dump_wbm_idle_hptp", 0, v21);
    goto LABEL_11;
  }
  if ( !a2 )
  {
    v20 = "%s: pdev is NULL";
    goto LABEL_10;
  }
  if ( *(_QWORD *)(a2 + 8) == -1960 )
  {
    v20 = "%s: wbm_idle_link_ring srng is NULL";
    goto LABEL_10;
  }
  v10 = *(void (**)(void))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 24LL);
  if ( *((_DWORD *)v10 - 1) != 1884881292 )
    __break(0x8228u);
  v10();
  result = qdf_trace_msg(
             0x45u,
             8u,
             "%s: WBM_IDLE_LINK: HW hp: %d, HW tp: %d",
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             "dp_dump_wbm_idle_hptp",
             0,
             0);
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
