void __fastcall mlo_link_set_active_resp_vdev_handler(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  __int64 v11; // x8
  __int64 v14; // x0
  __int64 active_cmd; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  void (__fastcall *v24)(__int64, __int64, __int64); // x8
  __int64 v25; // x1
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  _QWORD v34[5]; // [xsp+8h] [xbp-28h] BYREF

  v34[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a11 + 4) & 1) == 0 )
  {
    v11 = *(_QWORD *)(a10 + 216);
    v14 = v11 ? *(_QWORD *)(v11 + 80) : 0LL;
    active_cmd = wlan_serialization_get_active_cmd(
                   v14,
                   *(unsigned __int8 *)(a10 + 168),
                   0x1Du,
                   a1,
                   a2,
                   a3,
                   a4,
                   a5,
                   a6,
                   a7,
                   a8);
    if ( active_cmd )
    {
      v24 = *(void (__fastcall **)(__int64, __int64, __int64))(active_cmd + 8);
      if ( v24 )
      {
        v25 = *(_QWORD *)(active_cmd + 24);
        if ( *((_DWORD *)v24 - 1) != 662908326 )
          __break(0x8228u);
        v24(a10, v25, a11);
      }
      v34[0] = 0x1D00000028LL;
      v34[1] = 0;
      v34[2] = a10;
      v34[3] = 0;
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: release serialization command",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "mlo_release_ser_link_set_active_cmd");
      wlan_serialization_remove_cmd((unsigned int *)v34, v26, v27, v28, v29, v30, v31, v32, v33);
      *(_BYTE *)(a11 + 4) = 1;
    }
  }
  _ReadStatusReg(SP_EL0);
}
