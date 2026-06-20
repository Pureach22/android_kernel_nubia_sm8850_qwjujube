__int64 __fastcall mlo_roam_connect_complete(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *v9; // x8
  __int64 v10; // x19
  __int64 v11; // x9
  unsigned __int8 *v12; // x9
  int v13; // w20
  __int64 v14; // x8
  char v15; // w8

  if ( !result )
    return result;
  if ( (*(_BYTE *)(result + 60) & 2) == 0 )
    return result;
  v9 = *(_QWORD **)(result + 1360);
  if ( !v9 )
    return result;
  v10 = v9[278];
  if ( !v10 )
    return result;
  v11 = *(_QWORD *)(v10 + 288);
  if ( !v11 )
    return result;
  v12 = *(unsigned __int8 **)(v11 + 144);
  if ( !v12 )
    return result;
  v13 = *v12;
  if ( v9[3] == result )
  {
    v15 = 0;
  }
  else
  {
    if ( v9[4] != result )
    {
      result = qdf_trace_msg(
                 0x8Fu,
                 2u,
                 "%s: vdev:%d not found in ml dev ctx list",
                 a2,
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 "mlo_check_connect_req_bmap",
                 *(unsigned __int8 *)(result + 168));
      LOBYTE(v14) = 0;
      goto LABEL_13;
    }
    v15 = 1;
  }
  v14 = (*(_QWORD *)v10 >> v15) & 1LL;
LABEL_13:
  if ( (v14 & 1) == 0 && v13 == 1 )
  {
    result = (__int64)wlan_cm_free_connect_resp(*(void **)(v10 + 288));
    *(_QWORD *)(v10 + 288) = 0;
  }
  return result;
}
