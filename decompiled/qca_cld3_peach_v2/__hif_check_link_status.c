__int64 __fastcall _hif_check_link_status(__int64 a1)
{
  __int64 callbacks_handle; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 *v11; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  void (__fastcall *v29)(__int64, __int64); // x8
  __int64 v30; // x0
  __int16 v31; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v32; // [xsp+8h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = 0;
  callbacks_handle = hif_get_callbacks_handle(a1);
  if ( a1 )
  {
    v11 = (__int64 *)callbacks_handle;
    pld_pci_read_config_word(*(_QWORD *)(a1 + 30768), 2u, (__int64)&v31);
    if ( v31 == *(_WORD *)(a1 + 30908) )
    {
      result = 0;
    }
    else
    {
      qdf_trace_msg(
        0x3Du,
        2u,
        "%s: Invalid PCIe Config Space; PCIe link down dev_id:0x%04x",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "__hif_check_link_status");
      *(_BYTE *)(a1 + 648) = 1;
      if ( v11 && (v29 = (void (__fastcall *)(__int64, __int64))v11[1]) != nullptr )
      {
        v30 = *v11;
        if ( *((_DWORD *)v29 - 1) != -538254584 )
          __break(0x8228u);
        v29(v30, 1);
      }
      else
      {
        qdf_trace_msg(
          0x3Du,
          2u,
          "%s: Driver Global Recovery is not set",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "__hif_check_link_status");
      }
      pld_is_pci_link_down(*(_QWORD *)(a1 + 30760));
      result = 4294967283LL;
    }
  }
  else
  {
    qdf_trace_msg(
      0x3Du,
      2u,
      "%s: HIF Bus Context is Invalid",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "__hif_check_link_status");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
