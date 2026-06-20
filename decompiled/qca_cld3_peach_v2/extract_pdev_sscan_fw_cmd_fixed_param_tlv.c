__int64 __fastcall extract_pdev_sscan_fw_cmd_fixed_param_tlv(
        __int64 a1,
        __int64 *a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x19
  __int64 (*v14)(void); // x9
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  const char *v24; // x2

  if ( !a1 )
  {
    v24 = "%s: WMI handle is null";
LABEL_11:
    qdf_trace_msg(0x31u, 2u, v24, a4, a5, a6, a7, a8, a9, a10, a11, "extract_pdev_sscan_fw_cmd_fixed_param_tlv");
    return 4;
  }
  if ( !a3 )
  {
    v24 = "%s: Spectral startscan response params is null";
    goto LABEL_11;
  }
  if ( !a2 )
  {
    v24 = "%s: WMI_PDEV_SSCAN_FW_PARAM event is null";
    goto LABEL_11;
  }
  v11 = *a2;
  if ( !*a2 )
    return 4;
  v14 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 3728LL);
  if ( *((_DWORD *)v14 - 1) != -2112860426 )
    __break(0x8229u);
  *(_DWORD *)a3 = v14();
  *(_DWORD *)(a3 + 4) = *(_DWORD *)(v11 + 8);
  *(_BYTE *)(a3 + 8) = *((_DWORD *)a2 + 6);
  *(_BYTE *)(a3 + 9) = *((_DWORD *)a2 + 14);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: pdev id:%u smode:%u num_fft_bin_index:%u num_det_info:%u",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "extract_pdev_sscan_fw_cmd_fixed_param_tlv",
    *(unsigned int *)(v11 + 4),
    *(unsigned int *)(v11 + 8),
    *((unsigned int *)a2 + 6),
    *((unsigned int *)a2 + 14));
  return 0;
}
