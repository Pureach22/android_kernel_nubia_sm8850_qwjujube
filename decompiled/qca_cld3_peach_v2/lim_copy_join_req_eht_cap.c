char *__fastcall lim_copy_join_req_eht_cap(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  char *result; // x0
  __int64 v11; // x20
  __int64 v12; // x22
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD *v21; // x21
  __int64 v22; // x8
  __int64 v23; // x10
  __int64 v24; // x11
  __int64 v25; // x8
  __int64 v26; // x10
  __int64 v27; // x11
  __int64 v28; // x9
  __int64 v29; // x10
  __int64 v30; // x11
  __int64 v31; // x9
  __int64 v32; // x11
  __int64 v33; // x12
  __int64 v34; // x9
  __int64 v35; // x11
  __int64 v36; // x12
  __int64 v37; // x11
  __int64 v38; // x8
  __int64 v39; // x10

  result = (char *)wlan_vdev_mlme_get_ext_hdl(*(_QWORD *)(a1 + 16), a2, a3, a4, a5, a6, a7, a8, a9);
  if ( result )
  {
    v11 = (__int64)result;
    v12 = *(_QWORD *)(a1 + 8608);
    v21 = result + 24448;
    if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a1 + 284)) )
    {
      v22 = *(_QWORD *)(v12 + 22088);
      v23 = *(_QWORD *)(v12 + 22064);
      v24 = *(_QWORD *)(v12 + 22072);
      *(_QWORD *)(v11 + 24464) = *(_QWORD *)(v12 + 22080);
      *(_QWORD *)(v11 + 24472) = v22;
      *v21 = v23;
      *(_QWORD *)(v11 + 24456) = v24;
      v25 = *(_QWORD *)(v12 + 22120);
      v26 = *(_QWORD *)(v12 + 22096);
      v27 = *(_QWORD *)(v12 + 22104);
      *(_QWORD *)(v11 + 24496) = *(_QWORD *)(v12 + 22112);
      *(_QWORD *)(v11 + 24504) = v25;
      *(_QWORD *)(v11 + 24480) = v26;
      *(_QWORD *)(v11 + 24488) = v27;
      v28 = *(_QWORD *)(v12 + 22144);
      v29 = *(_QWORD *)(v12 + 22128);
      v30 = *(_QWORD *)(v12 + 22136);
      *(_DWORD *)(v11 + 24536) = *(_DWORD *)(v12 + 22152);
      *(_QWORD *)(v11 + 24520) = v30;
      *(_QWORD *)(v11 + 24528) = v28;
      *(_QWORD *)(v11 + 24512) = v29;
    }
    else
    {
      v31 = *(_QWORD *)(v12 + 22180);
      v32 = *(_QWORD *)(v12 + 22156);
      v33 = *(_QWORD *)(v12 + 22164);
      *(_QWORD *)(v11 + 24464) = *(_QWORD *)(v12 + 22172);
      *(_QWORD *)(v11 + 24472) = v31;
      *v21 = v32;
      *(_QWORD *)(v11 + 24456) = v33;
      v34 = *(_QWORD *)(v12 + 22212);
      v35 = *(_QWORD *)(v12 + 22188);
      v36 = *(_QWORD *)(v12 + 22196);
      *(_QWORD *)(v11 + 24496) = *(_QWORD *)(v12 + 22204);
      *(_QWORD *)(v11 + 24504) = v34;
      *(_QWORD *)(v11 + 24480) = v35;
      *(_QWORD *)(v11 + 24488) = v36;
      v37 = *(_QWORD *)(v12 + 22220);
      v38 = *(_QWORD *)(v12 + 22228);
      v39 = *(_QWORD *)(v12 + 22236);
      *(_DWORD *)(v11 + 24536) = *(_DWORD *)(v12 + 22244);
      *(_QWORD *)(v11 + 24512) = v37;
      *(_QWORD *)(v11 + 24520) = v38;
      *(_QWORD *)(v11 + 24528) = v39;
    }
    lim_revise_req_eht_cap_per_mode(v11, a1, v13, v14, v15, v16, v17, v18, v19, v20);
    return (char *)qdf_mem_copy((void *)(a1 + 10072), (const void *)(v11 + 24448), 0x5Cu);
  }
  return result;
}
