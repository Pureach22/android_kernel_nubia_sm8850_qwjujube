__int64 __fastcall extract_pdev_spectral_session_detector_info_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        unsigned __int8 a12)
{
  __int64 v12; // x8
  _DWORD *v13; // x19
  const char *v16; // x2

  if ( !a10 )
  {
    v16 = "%s: param_buf is NULL";
LABEL_9:
    qdf_trace_msg(0x31u, 2u, v16, a1, a2, a3, a4, a5, a6, a7, a8, "extract_pdev_spectral_session_detector_info_tlv");
    return 29;
  }
  if ( !a11 )
  {
    v16 = "%s: chan_info is NULL";
    goto LABEL_9;
  }
  v12 = *(_QWORD *)(a10 + 48);
  if ( !v12 )
  {
    v16 = "%s: det_info tlv is not present in the event";
    goto LABEL_9;
  }
  if ( *(_DWORD *)(a10 + 56) <= (unsigned int)a12 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: det_info index(%u) is greater than or equal to %u",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_pdev_spectral_session_detector_info_tlv");
    return 16;
  }
  else
  {
    v13 = (_DWORD *)(v12 + 16LL * a12);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: det_info_idx: %u detector_id:%u start_freq:%u end_freq:%u",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_pdev_spectral_session_detector_info_tlv");
    *(_BYTE *)a11 = v13[1];
    *(_DWORD *)(a11 + 4) = v13[2];
    *(_DWORD *)(a11 + 8) = v13[3];
    return 0;
  }
}
