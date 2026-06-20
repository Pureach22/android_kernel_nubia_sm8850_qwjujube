__int64 __fastcall ucfg_dp_set_mon_conf_flags(__int64 a1, unsigned int a2)
{
  __int64 context; // x0
  __int64 v4; // x3
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x8
  _DWORD *v16; // x8
  __int64 result; // x0
  __int64 v18; // x5
  const char *v19; // x2
  unsigned int v20; // w1
  _BYTE v21[24]; // [xsp+0h] [xbp-20h] BYREF
  __int64 v22; // [xsp+18h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = dp_get_context();
  if ( !context )
  {
    v19 = "%s: Failed to set flag %d, dp_ctx NULL";
    v20 = 2;
LABEL_12:
    result = qdf_trace_msg(0x45u, v20, v19, v5, v6, v7, v8, v9, v10, v11, v12, "ucfg_dp_set_mon_conf_flags", a2);
    goto LABEL_16;
  }
  v13 = context;
  v14 = *(_QWORD *)(context + 240);
  *(_DWORD *)(v13 + 3008) = a2;
  if ( !v14 )
  {
    v19 = "%s: Failed to set flag %d, cdp_soc NULL";
    v20 = 5;
    goto LABEL_12;
  }
  if ( !*(_QWORD *)v14 )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v5, v6, v7, v8, v9, v10, v11, v12, "cdp_txrx_set_psoc_param");
LABEL_14:
    v18 = 16;
LABEL_15:
    result = qdf_trace_msg(
               0x45u,
               2u,
               "%s: Failed to set flag %d status %d",
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               "ucfg_dp_set_mon_conf_flags",
               a2,
               v18,
               *(_OWORD *)v21,
               *(_QWORD *)&v21[16],
               v22);
    goto LABEL_16;
  }
  v15 = *(_QWORD *)(*(_QWORD *)v14 + 8LL);
  if ( !v15 )
    goto LABEL_14;
  v16 = *(_DWORD **)(v15 + 184);
  if ( !v16 )
    goto LABEL_14;
  v21[0] = a2;
  *(_QWORD *)&v21[1] = 0;
  *(_QWORD *)&v21[9] = 0;
  *(_QWORD *)&v21[16] = 0;
  if ( *(v16 - 1) != -503247959 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, __int64, _BYTE *, __int64))v16)(v14, 27, v21, v4);
  v18 = (unsigned int)result;
  if ( (_DWORD)result )
    goto LABEL_15;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
