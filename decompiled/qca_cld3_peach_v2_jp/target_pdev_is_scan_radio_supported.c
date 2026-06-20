__int64 __fastcall target_pdev_is_scan_radio_supported(
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
  __int64 v10; // x8
  __int64 v11; // x19
  __int64 v12; // x9
  __int64 (__fastcall *v13)(_QWORD); // x9
  __int64 v14; // x20
  __int64 v15; // x0
  _BYTE *v16; // x21
  int v17; // w8
  __int64 result; // x0
  const char *v19; // x2
  __int64 v20; // x8
  __int64 v21; // x10
  __int64 v22; // x9
  int v23; // w9
  _BYTE *v24; // x10

  if ( !a2 )
  {
    v19 = "%s: input argument is null";
LABEL_15:
    qdf_trace_msg(0x49u, 2u, v19, a3, a4, a5, a6, a7, a8, a9, a10, "target_pdev_is_scan_radio_supported");
    return 4;
  }
  *a2 = 0;
  if ( !a1 )
  {
    v19 = "%s: pdev is null";
    goto LABEL_15;
  }
  v10 = *(_QWORD *)(a1 + 80);
  if ( !v10 )
  {
    v19 = "%s: psoc is null";
    goto LABEL_15;
  }
  v11 = *(_QWORD *)(v10 + 2800);
  if ( !v11 )
  {
    v19 = "%s: target_psoc_info is null";
    goto LABEL_15;
  }
  v12 = *(_QWORD *)(v10 + 2128);
  if ( !v12 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: tx_ops is null",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_pdev_is_scan_radio_supported");
    return 29;
  }
  v13 = *(__int64 (__fastcall **)(_QWORD))(v12 + 1736);
  if ( v13 )
  {
    v14 = a1;
    v15 = *(_QWORD *)(a1 + 80);
    v16 = a2;
    if ( *((_DWORD *)v13 - 1) != 1468042957 )
      __break(0x8229u);
    v17 = v13(v15);
    a2 = v16;
    a1 = v14;
    if ( v17 == 7 )
    {
      *v16 = 1;
      return 0;
    }
  }
  v20 = *(unsigned __int8 *)(v11 + 984);
  if ( !*(_BYTE *)(v11 + 984) )
    return 0;
  v21 = *(_QWORD *)(v11 + 4472);
  if ( !v21 )
  {
    v19 = "%s: scan radio capabilities is null";
    goto LABEL_15;
  }
  v22 = *(_QWORD *)(a1 + 1232);
  if ( !v22 )
  {
    v19 = "%s: target_pdev_info is null";
    goto LABEL_15;
  }
  v23 = *(_DWORD *)(v22 + 20);
  if ( v23 < 0 )
  {
    v19 = "%s: phy_id is invalid";
    goto LABEL_15;
  }
  v24 = (_BYTE *)(v21 + 4);
  do
  {
    if ( *((_DWORD *)v24 - 1) == v23 )
      *a2 = *v24;
    result = 0;
    --v20;
    v24 += 8;
  }
  while ( v20 );
  return result;
}
