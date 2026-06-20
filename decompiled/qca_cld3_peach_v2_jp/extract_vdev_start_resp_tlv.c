__int64 __fastcall extract_vdev_start_resp_tlv(
        int a1,
        _QWORD *a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _DWORD *v11; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // w8
  __int64 result; // x0

  if ( a2 && (v11 = (_DWORD *)*a2) != nullptr )
  {
    qdf_mem_set(a3, 0x2Cu, 0);
    *(_BYTE *)a3 = v11[1];
    a3[1] = v11[2];
    v21 = v11[3];
    if ( v21 == 1 )
    {
      a3[3] = 1;
    }
    else if ( v21 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Invalid start response event buffer",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "extract_vdev_start_resp_tlv");
    }
    else
    {
      a3[3] = 0;
    }
    a3[2] = v11[4];
    a3[4] = v11[5];
    a3[5] = v11[6];
    a3[6] = v11[7];
    a3[7] = v11[8];
    a3[8] = v11[9];
    a3[9] = v11[10];
    result = 0;
    if ( v11[13] )
      a3[10] = v11[14];
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid start response event buffer",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "extract_vdev_start_resp_tlv");
    return 4;
  }
  return result;
}
