__int64 __fastcall reg_get_max_bw_5G_for_fo(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x19
  __int64 psoc_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  _DWORD *v21; // x8
  __int64 v22; // x1
  __int64 v23; // x20
  __int64 result; // x0
  const char *v25; // x2
  const char *v26; // x3
  _BYTE v27[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+8h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 80);
  v27[0] = 0;
  psoc_obj = reg_get_psoc_obj(v10, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !psoc_obj )
  {
    v25 = "%s: soc_reg is NULL";
    v26 = "reg_get_max_bw_5G_for_fo";
    goto LABEL_11;
  }
  if ( !v10 || (v20 = *(_QWORD *)(v10 + 2128)) == 0 )
  {
    v25 = "%s: tx_ops is NULL";
    v26 = "reg_get_psoc_tx_ops";
LABEL_11:
    qdf_trace_msg(0x51u, 2u, v25, v12, v13, v14, v15, v16, v17, v18, v19, v26);
    result = 0;
    goto LABEL_12;
  }
  v21 = *(_DWORD **)(v20 + 984);
  v22 = *(unsigned __int8 *)(a1 + 40);
  if ( v21 )
  {
    v23 = psoc_obj;
    if ( *(v21 - 1) != 13449260 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, _BYTE *))v21)(v10, v22, v27);
    LODWORD(v22) = v27[0];
    psoc_obj = v23;
    if ( v27[0] < 3u )
      goto LABEL_8;
LABEL_14:
    __break(0x5512u);
  }
  v27[0] = *(_BYTE *)(a1 + 40);
  if ( (unsigned int)v22 >= 3 )
    goto LABEL_14;
LABEL_8:
  result = *(unsigned __int16 *)(psoc_obj + 30364LL * (unsigned int)v22 + 30362);
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
