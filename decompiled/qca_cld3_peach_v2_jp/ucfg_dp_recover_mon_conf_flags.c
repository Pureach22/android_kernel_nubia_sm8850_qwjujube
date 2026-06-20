__int64 ucfg_dp_recover_mon_conf_flags()
{
  __int64 context; // x0
  __int64 v1; // x3
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x19
  __int64 v11; // x0
  __int64 v12; // x8
  _DWORD *v13; // x8
  int v14; // w9
  __int64 result; // x0
  __int64 v16; // x5
  _BYTE v17[24]; // [xsp+0h] [xbp-20h] BYREF
  __int64 v18; // [xsp+18h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = dp_get_context();
  if ( !context )
  {
    result = qdf_trace_msg(
               0x45u,
               2u,
               "%s: Failed to set flag dp_ctx NULL",
               v2,
               v3,
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               "ucfg_dp_recover_mon_conf_flags");
    goto LABEL_14;
  }
  v10 = context;
  v11 = *(_QWORD *)(context + 240);
  if ( !v11 || !*(_QWORD *)v11 )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v2, v3, v4, v5, v6, v7, v8, v9, "cdp_txrx_set_psoc_param");
LABEL_11:
    v16 = 16;
LABEL_12:
    result = qdf_trace_msg(
               0x45u,
               2u,
               "%s: Failed to set flag %d status %d",
               v2,
               v3,
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               "ucfg_dp_recover_mon_conf_flags",
               *(unsigned int *)(v10 + 3008),
               v16,
               *(_OWORD *)v17,
               *(_QWORD *)&v17[16],
               v18);
    goto LABEL_14;
  }
  v12 = *(_QWORD *)(*(_QWORD *)v11 + 8LL);
  if ( !v12 )
    goto LABEL_11;
  v13 = *(_DWORD **)(v12 + 184);
  if ( !v13 )
    goto LABEL_11;
  v14 = *(_DWORD *)(v10 + 3008);
  *(_QWORD *)&v17[1] = 0;
  *(_QWORD *)&v17[9] = 0;
  v17[0] = v14;
  *(_QWORD *)&v17[16] = 0;
  if ( *(v13 - 1) != -503247959 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, __int64, _BYTE *, __int64))v13)(v11, 27, v17, v1);
  v16 = (unsigned int)result;
  if ( (_DWORD)result )
    goto LABEL_12;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
