__int64 __fastcall reg_propagate_mas_chan_list_and_fill_legacy_list(__int64 a1, __int64 a2, int a3)
{
  __int64 psoc_tx_ops; // x0
  __int64 v6; // x21
  __int64 pdev_obj; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x22
  void (__fastcall *v17)(__int64, __int64); // x8
  __int64 result; // x0
  int v19; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = a3;
  psoc_tx_ops = reg_get_psoc_tx_ops(a1);
  if ( !psoc_tx_ops )
    goto LABEL_9;
  v6 = psoc_tx_ops;
  pdev_obj = reg_get_pdev_obj(a2);
  if ( !pdev_obj )
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: reg pdev priv obj is NULL",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "reg_propagate_mas_chan_list_and_fill_legacy_list");
LABEL_9:
    result = 16;
    goto LABEL_10;
  }
  v16 = pdev_obj;
  reg_propagate_mas_chan_list_to_pdev(a1, a2, &v19);
  v17 = *(void (__fastcall **)(__int64, __int64))(v6 + 48);
  if ( v17 )
  {
    if ( *((_DWORD *)v17 - 1) != -145496263 )
      __break(0x8228u);
    v17(a2, v16);
  }
  result = 0;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
