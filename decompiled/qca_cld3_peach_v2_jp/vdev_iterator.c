__int64 __fastcall vdev_iterator(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        _DWORD *a11)
{
  __int64 result; // x0
  __int64 v13; // x8
  _DWORD *v14; // x8
  int v15; // w11
  int v16; // w11
  int v17; // w11
  int v18; // w11
  int v19; // w11
  int v20; // w11
  int v21; // w11
  int v22; // w11
  int v23; // w11
  int v24; // w11
  const char *v25; // x2

  if ( a1 && (result = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Bu)) != 0 && (v13 = *(_QWORD *)(result + 24)) != 0 )
  {
    v14 = *(_DWORD **)(v13 + 40);
    if ( v14 )
    {
      v15 = a11[1];
      *a11 += v14[61];
      a11[1] = v15 + v14[62];
      v16 = a11[3];
      a11[2] += v14[63];
      a11[3] = v16 + v14[64];
      v17 = a11[5];
      a11[4] += v14[65];
      a11[5] = v17 + v14[66];
      v18 = a11[7];
      a11[6] += v14[67];
      a11[7] = v18 + v14[68];
      v19 = a11[9];
      a11[8] += v14[69];
      a11[9] = v19 + v14[70];
      v20 = a11[11];
      a11[10] += v14[71];
      a11[11] = v20 + v14[72];
      v21 = a11[13];
      a11[12] += v14[73];
      a11[13] = v21 + v14[74];
      v22 = a11[15];
      a11[14] += v14[75];
      a11[15] = v22 + v14[76];
      v23 = a11[17];
      a11[16] += v14[77];
      a11[17] = v23 + v14[78];
      v24 = a11[19];
      a11[18] += v14[79];
      a11[19] = v24 + v14[80];
      return result;
    }
    v25 = "%s: psoc mc stats is null";
  }
  else
  {
    v25 = "%s: psoc cp stats object is null";
  }
  return qdf_trace_msg(0x62u, 2u, v25, a2, a3, a4, a5, a6, a7, a8, a9, "vdev_iterator");
}
