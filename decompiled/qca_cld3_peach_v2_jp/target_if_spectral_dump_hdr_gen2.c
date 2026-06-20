__int64 __fastcall target_if_spectral_dump_hdr_gen2(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  _QWORD v19[2]; // [xsp+0h] [xbp-10h] BYREF

  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19[0] = 0;
  qdf_mem_copy((char *)v19 + 4, (const void *)a1, 4u);
  qdf_mem_copy(v19, (const void *)(a1 + 4), 4u);
  qdf_trace_msg(
    0x56u,
    8u,
    "%s: SPECTRAL : HEADER A 0x%x (%d)",
    v2,
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    "target_if_spectral_dump_hdr_gen2",
    HIDWORD(v19[0]),
    HIDWORD(v19[0]));
  qdf_trace_msg(
    0x56u,
    8u,
    "%s: SPECTRAL : HEADER B 0x%x (%d)",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "target_if_spectral_dump_hdr_gen2",
    LODWORD(v19[0]),
    LODWORD(v19[0]));
  _ReadStatusReg(SP_EL0);
  return 0;
}
