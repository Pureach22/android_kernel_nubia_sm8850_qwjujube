__int64 __fastcall reg_update_channel_ranges(
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
  unsigned int v10; // w19
  __int64 pdev_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x20
  __int64 v21; // x8
  _DWORD *v22; // x8
  __int64 v23; // x21
  const char *v24; // x2
  __int64 result; // x0
  _DWORD *psoc_obj; // x0
  _DWORD *v27; // x8
  _BYTE v28[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v29; // [xsp+8h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(unsigned __int8 *)(a1 + 40);
  v28[0] = 0;
  pdev_obj = reg_get_pdev_obj(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !pdev_obj )
  {
    v24 = "%s: pdev reg component is NULL";
LABEL_16:
    qdf_trace_msg(0x51u, 2u, v24, v12, v13, v14, v15, v16, v17, v18, v19, "reg_update_channel_ranges");
    result = 4;
    goto LABEL_17;
  }
  v20 = *(_QWORD *)(a1 + 80);
  if ( !v20 )
  {
    v24 = "%s: psoc is NULL";
    goto LABEL_16;
  }
  v21 = *(_QWORD *)(v20 + 2128);
  if ( !v21 )
  {
    qdf_trace_msg(0x51u, 2u, "%s: tx_ops is NULL", v12, v13, v14, v15, v16, v17, v18, v19, "reg_get_psoc_tx_ops");
    result = 16;
    goto LABEL_17;
  }
  v22 = *(_DWORD **)(v21 + 984);
  v23 = pdev_obj;
  if ( v22 )
  {
    if ( *(v22 - 1) != 13449260 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD, _BYTE *))v22)(v20, v10, v28);
  }
  else
  {
    v28[0] = v10;
  }
  psoc_obj = (_DWORD *)reg_get_psoc_obj(v20, v12, v13, v14, v15, v16, v17, v18, v19);
  if ( !psoc_obj )
  {
    v24 = "%s: psoc reg component is NULL";
    goto LABEL_16;
  }
  if ( psoc_obj[23272] == v28[0] )
  {
    v27 = psoc_obj + 23272;
  }
  else if ( psoc_obj[23284] == v28[0] )
  {
    v27 = psoc_obj + 23284;
  }
  else
  {
    if ( psoc_obj[23296] != v28[0] )
    {
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: extended capabilities not found for pdev",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "reg_update_channel_ranges");
      result = 5;
      goto LABEL_17;
    }
    v27 = psoc_obj + 23296;
  }
  result = 0;
  *(_DWORD *)(v23 + 56736) = v27[8];
  *(_DWORD *)(v23 + 56740) = v27[9];
  *(_DWORD *)(v23 + 56744) = v27[10];
  *(_DWORD *)(v23 + 56748) = v27[11];
  *(_QWORD *)(v23 + 56768) = *((_QWORD *)v27 + 3);
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
