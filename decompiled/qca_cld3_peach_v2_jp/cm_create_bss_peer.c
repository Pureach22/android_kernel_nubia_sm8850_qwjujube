__int64 __fastcall cm_create_bss_peer(
        _QWORD *a1,
        unsigned int *a2,
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
  __int64 v11; // x19
  __int64 v12; // x8
  _QWORD *v13; // x20
  __int64 v14; // x0
  unsigned int *v15; // x21
  const char *v16; // x2
  __int64 result; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x1
  _QWORD *v27; // x19
  __int64 v28; // x8
  __int64 v29; // x20
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  _BYTE v38[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v39; // [xsp+8h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v38[0] = 0;
  if ( !a1 )
  {
    v16 = "%s: invalid cm_ctx";
    goto LABEL_9;
  }
  if ( !a2 || (v10 = *((_QWORD *)a2 + 105)) == 0 || !*(_QWORD *)(v10 + 24) )
  {
    v16 = "%s: invalid req";
LABEL_9:
    result = qdf_trace_msg(0x68u, 2u, v16, a3, a4, a5, a6, a7, a8, a9, a10, "cm_create_bss_peer");
    goto LABEL_10;
  }
  v11 = *a1;
  v12 = *(_QWORD *)(*a1 + 152LL);
  if ( v12 )
  {
    v13 = a1;
    v14 = *(_QWORD *)(v12 + 80);
    v15 = a2;
  }
  else
  {
    v15 = a2;
    v13 = a1;
    v14 = 0;
  }
  wlan_psoc_mlme_get_11be_capab(v14, v38);
  result = mlme_cm_bss_peer_create_req(v11, *(_QWORD *)(*((_QWORD *)v15 + 105) + 24LL) + 1LL, 0, 0);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev %d cm_id 0x%x: peer create request failed %d",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "cm_create_bss_peer",
      *(unsigned __int8 *)(v11 + 104),
      *v15,
      (unsigned int)result);
    result = _qdf_mem_malloc(0xA0u, "cm_create_bss_peer", 730);
    if ( result )
    {
      v26 = *v15;
      v27 = v13;
      *(_DWORD *)(result + 52) = 16;
      *(_DWORD *)(result + 4) = v26;
      v28 = *v13;
      v29 = result;
      LOBYTE(v28) = *(_BYTE *)(v28 + 104);
      *(_DWORD *)(result + 56) = 4;
      *(_BYTE *)result = v28;
      cm_fill_bss_info_in_connect_rsp_by_cm_id(v27, v26, result);
      wlan_sm_dispatch(v27[9], 0xBu, 0xA0u, v29, v30, v31, v32, v33, v34, v35, v36, v37);
      result = _qdf_mem_free(v29);
    }
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
