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
      *a11 += v14[89];
      a11[1] = v15 + v14[90];
      v16 = a11[3];
      a11[2] += v14[91];
      a11[3] = v16 + v14[92];
      v17 = a11[5];
      a11[4] += v14[93];
      a11[5] = v17 + v14[94];
      v18 = a11[7];
      a11[6] += v14[95];
      a11[7] = v18 + v14[96];
      v19 = a11[9];
      a11[8] += v14[97];
      a11[9] = v19 + v14[98];
      v20 = a11[11];
      a11[10] += v14[99];
      a11[11] = v20 + v14[100];
      v21 = a11[13];
      a11[12] += v14[101];
      a11[13] = v21 + v14[102];
      v22 = a11[15];
      a11[14] += v14[103];
      a11[15] = v22 + v14[104];
      v23 = a11[17];
      a11[16] += v14[105];
      a11[17] = v23 + v14[106];
      v24 = a11[19];
      a11[18] += v14[107];
      a11[19] = v24 + v14[108];
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
