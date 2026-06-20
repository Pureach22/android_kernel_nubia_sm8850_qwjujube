__int64 __fastcall init_deinit_populate_twt_cap_ext2(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int twt_cap_service_ready_ext2; // w0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w19
  __int64 result; // x0
  __int64 v15; // x8
  unsigned __int64 v16; // t2
  int v17; // w11
  _QWORD v18[3]; // [xsp+8h] [xbp-18h] BYREF

  v18[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v18, 0, 12);
  twt_cap_service_ready_ext2 = wmi_extract_twt_cap_service_ready_ext2(a2, a3, v18);
  if ( twt_cap_service_ready_ext2 )
  {
    v13 = twt_cap_service_ready_ext2;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Extraction of twt capability failed",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "init_deinit_populate_twt_cap_ext2");
    twt_cap_service_ready_ext2 = v13;
  }
  else if ( a1 )
  {
    v15 = *(_QWORD *)(a1 + 2800);
    if ( v15 )
    {
      HIDWORD(v16) = *(_DWORD *)((char *)v18 + 2);
      LODWORD(v16) = *(_DWORD *)((char *)v18 + 2);
      v17 = __PAIR64__(*(unsigned int *)((char *)v18 + 6), *(unsigned int *)((char *)v18 + 6)) >> 16;
      *(_BYTE *)(v15 + 994) = *(_BYTE *)(v15 + 994) & 0xFE | v18[0] & 1;
      *(_DWORD *)(v15 + 1060) = v16 >> 16;
      *(_DWORD *)(v15 + 1064) = v17;
    }
  }
  result = qdf_status_to_os_return(twt_cap_service_ready_ext2);
  _ReadStatusReg(SP_EL0);
  return result;
}
