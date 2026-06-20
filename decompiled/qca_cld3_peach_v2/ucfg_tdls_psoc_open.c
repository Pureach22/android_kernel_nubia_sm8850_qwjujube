__int64 __fastcall ucfg_tdls_psoc_open(
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
  __int64 comp_private_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x20
  __int64 v20; // x19
  __int64 values; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  int v30; // w11
  int v31; // w9
  int v32; // w12
  int v33; // w10
  int v34; // w10
  int v35; // w11
  int v36; // w9
  int v37; // w10
  int v38; // w9
  int v39; // w8
  __int64 result; // x0
  char is_drv_supported; // w8

  qdf_trace_msg(0, 8u, "%s: tdls psoc open", a2, a3, a4, a5, a6, a7, a8, a9, "ucfg_tdls_psoc_open");
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xAu);
  if ( comp_private_obj )
  {
    v19 = *(_QWORD *)comp_private_obj;
    v20 = comp_private_obj;
    if ( *(_QWORD *)comp_private_obj )
    {
      *(_DWORD *)(comp_private_obj + 104) = *(_DWORD *)(cfg_psoc_get_values(*(_QWORD *)comp_private_obj) + 10656);
      *(_DWORD *)(v20 + 108) = *(_DWORD *)(cfg_psoc_get_values(v19) + 10660);
      *(_DWORD *)(v20 + 112) = *(_DWORD *)(cfg_psoc_get_values(v19) + 10640);
      *(_DWORD *)(v20 + 116) = *(_DWORD *)(cfg_psoc_get_values(v19) + 10664);
      *(_DWORD *)(v20 + 120) = *(_DWORD *)(cfg_psoc_get_values(v19) + 10672);
      *(_DWORD *)(v20 + 124) = *(_DWORD *)(cfg_psoc_get_values(v19) + 10676);
      *(_DWORD *)(v20 + 128) = *(_DWORD *)(cfg_psoc_get_values(v19) + 10680);
      *(_DWORD *)(v20 + 132) = *(_DWORD *)(cfg_psoc_get_values(v19) + 10684);
      *(_DWORD *)(v20 + 136) = *(_DWORD *)(cfg_psoc_get_values(v19) + 10688);
      *(_DWORD *)(v20 + 140) = *(_DWORD *)(cfg_psoc_get_values(v19) + 10628);
      *(_DWORD *)(v20 + 144) = *(_DWORD *)(cfg_psoc_get_values(v19) + 10636);
      *(_DWORD *)(v20 + 148) = *(_DWORD *)(cfg_psoc_get_values(v19) + 10704);
      *(_DWORD *)(v20 + 152) = *(_DWORD *)(cfg_psoc_get_values(v19) + 10708);
      *(_DWORD *)(v20 + 160) = *(_DWORD *)(cfg_psoc_get_values(v19) + 10692);
      *(_DWORD *)(v20 + 164) = *(_DWORD *)(cfg_psoc_get_values(v19) + 10696);
      *(_DWORD *)(v20 + 168) = *(_DWORD *)(cfg_psoc_get_values(v19) + 10700);
      *(_DWORD *)(v20 + 172) = *(_DWORD *)(cfg_psoc_get_values(v19) + 10720);
      *(_DWORD *)(v20 + 176) = *(_DWORD *)(cfg_psoc_get_values(v19) + 10724);
      *(_DWORD *)(v20 + 180) = *(_DWORD *)(cfg_psoc_get_values(v19) + 10424);
      *(_BYTE *)(v20 + 189) = *(_BYTE *)(cfg_psoc_get_values(v19) + 10716);
      *(_BYTE *)(v20 + 187) = *(_BYTE *)(cfg_psoc_get_values(v19) + 10644);
      *(_BYTE *)(v20 + 186) = *(_BYTE *)(cfg_psoc_get_values(v19) + 10632);
      *(_BYTE *)(v20 + 192) = *(_BYTE *)(cfg_psoc_get_values(v19) + 10717);
      *(_BYTE *)(v20 + 194) = *(_DWORD *)(cfg_psoc_get_values(v19) + 10648);
      *(_BYTE *)(v20 + 191) = *(_BYTE *)(cfg_psoc_get_values(v19) + 10652);
      *(_BYTE *)(v20 + 190) = *(_DWORD *)(cfg_psoc_get_values(v19) + 10712);
      values = cfg_psoc_get_values(v19);
      if ( *(_BYTE *)(v20 + 189) )
        v30 = 2;
      else
        v30 = 0;
      v31 = v30 | *(unsigned __int8 *)(v20 + 187);
      if ( *(_BYTE *)(v20 + 186) )
        v32 = 4;
      else
        v32 = 0;
      if ( *(_BYTE *)(v20 + 193) )
        v33 = 8;
      else
        v33 = 0;
      v34 = v32 | v33;
      if ( *(_BYTE *)(v20 + 192) )
        v35 = 16;
      else
        v35 = 0;
      v36 = v31 | v34 | v35;
      v37 = (*(_BYTE *)(v20 + 190) & 3) << 7;
      v38 = v36 | (32 * (*(_BYTE *)(v20 + 194) != 0));
      if ( *(_BYTE *)(v20 + 191) )
        v39 = 64;
      else
        v39 = 0;
      *(_WORD *)(v20 + 200) = *(_DWORD *)(values + 10668);
      *(_DWORD *)(v20 + 156) = v38 | v39 | v37;
    }
    else
    {
      qdf_trace_msg(0, 2u, "%s: invalid psoc object", v11, v12, v13, v14, v15, v16, v17, v18, "tdls_object_init_params");
    }
    *(_WORD *)(v20 + 202) = 0;
    *(_QWORD *)(v20 + 212) = 0;
    *(_DWORD *)(v20 + 220) = 0;
    *(_BYTE *)(v20 + 633) = 1;
    *(_DWORD *)(v20 + 352) = 0;
    *(_QWORD *)(v20 + 360) = 0;
    *(_BYTE *)(v20 + 368) = 0;
    is_drv_supported = qdf_is_drv_supported(v22, v23, v24, v25, v26, v27, v28, v29);
    result = 0;
    *(_BYTE *)(v20 + 369) = is_drv_supported & 1;
    if ( (is_drv_supported & 1) == 0 )
    {
      _qdf_wake_lock_create((_QWORD *)(v20 + 376), (__int64)"wlan_tdls");
      _qdf_runtime_lock_init((__int64 *)(v20 + 576), "&soc_obj->runtime_lock");
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0,
      2u,
      "%s: Failed to get tdls psoc component",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "ucfg_tdls_psoc_open");
    return 16;
  }
  return result;
}
