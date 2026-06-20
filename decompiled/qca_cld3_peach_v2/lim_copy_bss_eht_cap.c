__int64 __fastcall lim_copy_bss_eht_cap(
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
  __int64 result; // x0
  __int64 v11; // x20
  __int64 v12; // x22
  _QWORD *v13; // x21
  __int64 v14; // x8
  __int64 v15; // x10
  __int64 v16; // x11
  __int64 v17; // x8
  __int64 v18; // x10
  __int64 v19; // x11
  __int64 v20; // x9
  __int64 v21; // x10
  __int64 v22; // x11
  __int64 v23; // x9
  __int64 v24; // x11
  __int64 v25; // x12
  __int64 v26; // x9
  __int64 v27; // x11
  __int64 v28; // x12
  __int64 v29; // x11
  __int64 v30; // x8
  __int64 v31; // x10

  result = wlan_vdev_mlme_get_ext_hdl(*(_QWORD *)(a1 + 16), a2, a3, a4, a5, a6, a7, a8, a9);
  if ( result )
  {
    v11 = result;
    v12 = *(_QWORD *)(a1 + 8608);
    v13 = (_QWORD *)(result + 24448);
    if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a1 + 284)) )
    {
      v14 = *(_QWORD *)(v12 + 22088);
      v15 = *(_QWORD *)(v12 + 22064);
      v16 = *(_QWORD *)(v12 + 22072);
      *(_QWORD *)(v11 + 24464) = *(_QWORD *)(v12 + 22080);
      *(_QWORD *)(v11 + 24472) = v14;
      *v13 = v15;
      *(_QWORD *)(v11 + 24456) = v16;
      v17 = *(_QWORD *)(v12 + 22120);
      v18 = *(_QWORD *)(v12 + 22096);
      v19 = *(_QWORD *)(v12 + 22104);
      *(_QWORD *)(v11 + 24496) = *(_QWORD *)(v12 + 22112);
      *(_QWORD *)(v11 + 24504) = v17;
      *(_QWORD *)(v11 + 24480) = v18;
      *(_QWORD *)(v11 + 24488) = v19;
      v20 = *(_QWORD *)(v12 + 22144);
      v21 = *(_QWORD *)(v12 + 22128);
      v22 = *(_QWORD *)(v12 + 22136);
      *(_DWORD *)(v11 + 24536) = *(_DWORD *)(v12 + 22152);
      *(_QWORD *)(v11 + 24520) = v22;
      *(_QWORD *)(v11 + 24528) = v20;
      *(_QWORD *)(v11 + 24512) = v21;
    }
    else
    {
      v23 = *(_QWORD *)(v12 + 22180);
      v24 = *(_QWORD *)(v12 + 22156);
      v25 = *(_QWORD *)(v12 + 22164);
      *(_QWORD *)(v11 + 24464) = *(_QWORD *)(v12 + 22172);
      *(_QWORD *)(v11 + 24472) = v23;
      *v13 = v24;
      *(_QWORD *)(v11 + 24456) = v25;
      v26 = *(_QWORD *)(v12 + 22212);
      v27 = *(_QWORD *)(v12 + 22188);
      v28 = *(_QWORD *)(v12 + 22196);
      *(_QWORD *)(v11 + 24496) = *(_QWORD *)(v12 + 22204);
      *(_QWORD *)(v11 + 24504) = v26;
      *(_QWORD *)(v11 + 24480) = v27;
      *(_QWORD *)(v11 + 24488) = v28;
      v29 = *(_QWORD *)(v12 + 22220);
      v30 = *(_QWORD *)(v12 + 22228);
      v31 = *(_QWORD *)(v12 + 22236);
      *(_DWORD *)(v11 + 24536) = *(_DWORD *)(v12 + 22244);
      *(_QWORD *)(v11 + 24512) = v29;
      *(_QWORD *)(v11 + 24520) = v30;
      *(_QWORD *)(v11 + 24528) = v31;
    }
    lim_revise_req_eht_cap_per_mode(v11, a1);
    qdf_mem_copy((void *)(a1 + 10072), (const void *)(v11 + 24448), 0x5Cu);
    result = wlan_epcs_get_config(*(_QWORD *)(a1 + 16));
    *(_QWORD *)(a1 + 10073) = *(_QWORD *)(a1 + 10073) & 0xFFFFFFFFFFFFFFFELL | result & 1;
  }
  return result;
}
