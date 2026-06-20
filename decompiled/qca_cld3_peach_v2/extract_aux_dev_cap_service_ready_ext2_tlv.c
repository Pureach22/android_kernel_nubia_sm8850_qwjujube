__int64 __fastcall extract_aux_dev_cap_service_ready_ext2_tlv(
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
        unsigned __int8 a11,
        _DWORD *a12)
{
  unsigned int v12; // w9
  __int64 v13; // x8
  _DWORD *v14; // x8
  int v15; // w9

  v12 = *(_DWORD *)(a10 + 232);
  if ( v12 )
  {
    v13 = *(_QWORD *)(a10 + 224);
    if ( v13 )
    {
      if ( v12 > a11 )
      {
        v14 = (_DWORD *)(v13 + 24LL * a11);
        *a12 = v14[1];
        a12[1] = v14[2];
        a12[2] = v14[3];
        a12[3] = v14[4];
        v15 = v14[5];
        a12[4] = v15;
        qdf_trace_msg(
          0x31u,
          4u,
          "%s: idx %u aux_index %u, hw_mode_id %u, supported_modes_bitmap 0x%x, listen_pdev_id_map 0x%x, emlsr_pdev_id_map 0x%x",
          a1,
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          "extract_aux_dev_cap_service_ready_ext2_tlv",
          v14[4],
          v15);
        return 0;
      }
    }
    else
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: aux_dev_caps is NULL",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_aux_dev_cap_service_ready_ext2_tlv");
    }
  }
  return 4;
}
