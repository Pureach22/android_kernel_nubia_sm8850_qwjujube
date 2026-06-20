__int64 __fastcall reg_set_non_offload_country(
        __int64 a1,
        _BYTE *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x20
  unsigned int v12; // w21
  __int64 psoc_tx_ops; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _DWORD *v23; // x8
  const char *v24; // x2
  __int64 result; // x0
  __int64 psoc_obj; // x0
  __int64 v27; // x20
  __int64 pdev_obj; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  char v37; // w20
  __int16 v38; // w8
  __int64 v39; // x0
  _BYTE v40[4]; // [xsp+Ch] [xbp-14h] BYREF
  int v41; // [xsp+10h] [xbp-10h] BYREF
  __int16 v42; // [xsp+14h] [xbp-Ch]
  __int64 v43; // [xsp+18h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v42 = 0;
  v41 = 0;
  v40[0] = 0;
  if ( !a1 )
  {
    v24 = "%s: pdev is NULL";
LABEL_20:
    qdf_trace_msg(0x51u, 2u, v24, a3, a4, a5, a6, a7, a8, a9, a10, "reg_set_non_offload_country");
    result = 4;
    goto LABEL_21;
  }
  v10 = *(_QWORD *)(a1 + 80);
  v12 = *(unsigned __int8 *)(a1 + 40);
  psoc_tx_ops = reg_get_psoc_tx_ops(v10, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !psoc_tx_ops )
  {
    result = 16;
LABEL_21:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v23 = *(_DWORD **)(psoc_tx_ops + 128);
  if ( v23 )
  {
    if ( *(v23 - 1) != 13449260 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD, _BYTE *))v23)(v10, v12, v40);
  }
  else
  {
    v40[0] = v12;
  }
  psoc_obj = reg_get_psoc_obj(v10, v15, v16, v17, v18, v19, v20, v21, v22);
  if ( !psoc_obj )
  {
    v24 = "%s: psoc reg component is NULL";
    goto LABEL_20;
  }
  if ( *a2 != 48 || a2[1] != 48 )
  {
    v37 = 3;
    qdf_mem_copy(&v41, a2, 3u);
LABEL_18:
    LOBYTE(v42) = v37;
    reg_program_chan_list(a1, (unsigned __int8 *)&v41, v29, v30, v31, v32, v33, v34, v35, v36);
    result = 0;
    goto LABEL_21;
  }
  v27 = psoc_obj;
  pdev_obj = reg_get_pdev_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( pdev_obj )
  {
    v37 = 2;
    v38 = *(_WORD *)(pdev_obj + 56700);
    if ( (v38 & 0xFFF0) != 0x60 )
      v38 = 96;
    LOWORD(v41) = v38;
    goto LABEL_18;
  }
  v39 = qdf_trace_msg(
          0x51u,
          2u,
          "%s: reg component pdev priv is NULL",
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          "reg_set_non_offload_country");
  if ( v40[0] < 3uLL )
  {
    result = 4;
    *(_BYTE *)(v27 + v40[0] + 91137) = 0;
    goto LABEL_21;
  }
  __break(0x5512u);
  return reg_reset_country(v39);
}
