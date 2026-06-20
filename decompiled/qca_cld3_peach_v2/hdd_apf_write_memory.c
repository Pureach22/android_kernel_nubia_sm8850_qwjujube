__int64 __fastcall hdd_apf_write_memory(
        __int64 a1,
        _QWORD *a2,
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
  int v11; // w9
  __int64 v12; // x20
  const char *v13; // x2
  __int64 v14; // x8
  int v15; // w9
  __int64 v16; // x8
  int v17; // w9
  _WORD *v18; // x8
  unsigned __int16 v19; // w8
  unsigned int v20; // w19
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x8
  __int64 v33; // x0
  __int64 result; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w19
  __int64 v44; // [xsp+8h] [xbp-28h] BYREF
  __int64 v45; // [xsp+10h] [xbp-20h]
  __int64 v46; // [xsp+18h] [xbp-18h]
  __int64 v47; // [xsp+20h] [xbp-10h]
  __int64 v48; // [xsp+28h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 52832);
  v45 = 0;
  v46 = 0;
  v11 = *(unsigned __int8 *)(a1 + 52264);
  v12 = *(_QWORD *)(a1 + 24);
  v44 = 0;
  LOBYTE(v44) = *(_BYTE *)(v10 + 8);
  if ( v11 == 1 )
  {
    v13 = "%s: Cannot get/set when APF interpreter is enabled";
LABEL_14:
    qdf_trace_msg(0x33u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "hdd_apf_write_memory");
    goto LABEL_15;
  }
  v14 = a2[7];
  if ( !v14 )
  {
    v13 = "%s: attr program length failed";
    goto LABEL_14;
  }
  v15 = *(_DWORD *)(v14 + 4);
  v16 = a2[5];
  LODWORD(v45) = v15;
  if ( !v16 )
  {
    v13 = "%s: attr apf packet size failed";
    goto LABEL_14;
  }
  v17 = *(_DWORD *)(v16 + 4);
  v18 = (_WORD *)a2[6];
  HIDWORD(v45) = v17;
  if ( !v18 )
  {
    v13 = "%s: attr apf program failed";
    goto LABEL_14;
  }
  v19 = *v18 - 4;
  v20 = v19;
  LODWORD(v46) = v19;
  if ( !v19 )
  {
    v13 = "%s: Program attr with empty data";
    goto LABEL_14;
  }
  v23 = _qdf_mem_malloc(v19, "hdd_apf_write_memory", 387);
  v47 = v23;
  if ( !v23 )
  {
LABEL_15:
    result = 4294967274LL;
    goto LABEL_16;
  }
  nla_memcpy(v23, a2[6], v20);
  v32 = *(_QWORD *)(a1 + 24);
  HIDWORD(v44) = *(_DWORD *)(v12 + 3608);
  if ( v32 )
    v33 = *(_QWORD *)(v32 + 16);
  else
    v33 = 0;
  if ( (unsigned int)sme_apf_write_work_memory(v24, v25, v26, v27, v28, v29, v30, v31, v33, (__int64)&v44) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Unable to retrieve APF caps",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "hdd_apf_write_memory");
    v43 = -22;
  }
  else
  {
    v43 = 0;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Writing successful into APF work memory from offset 0x%X:",
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    "hdd_apf_write_memory",
    HIDWORD(v45));
  ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(51, 8, v47, (unsigned int)v46);
  if ( v47 )
    _qdf_mem_free(v47);
  result = v43;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
