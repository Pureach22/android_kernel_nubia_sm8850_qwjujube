__int64 __fastcall dp_set_pdev_param(
        __int64 a1,
        char a2,
        int a3,
        _BYTE *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x8
  __int64 result; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  void (*v16)(void); // x8
  __int64 v17; // x8
  __int64 v18; // x9
  __int64 v19; // x9
  void (__fastcall *v20)(__int64, __int64); // x9
  __int64 v21; // x1
  __int64 v22; // x9
  __int64 v23; // x9
  __int64 (__fastcall *v24)(__int64, __int64); // x9
  __int64 v25; // x1
  __int64 v26; // x9
  __int64 v27; // x9
  _DWORD *v28; // x9
  __int64 v29; // x1
  __int64 v30; // x9
  __int64 v31; // x9
  void (__fastcall *v32)(__int64, __int64); // x9
  __int64 v33; // x1
  __int64 v34; // x9
  __int64 v35; // x9
  __int64 v36; // x9
  __int64 v37; // x9
  __int64 v38; // x9
  void (__fastcall *v39)(_QWORD); // x9
  const char *v40; // x2
  const char *v41; // x3
  const char *v42; // x2
  const char *v43; // x3

  if ( a2 )
    return 16;
  v12 = *(_QWORD *)(a1 + 72);
  if ( !v12 )
    return 16;
  result = 4;
  switch ( a3 )
  {
    case 0:
      v22 = *(_QWORD *)(*(_QWORD *)(v12 + 8) + 20056LL);
      if ( !v22 )
        return 16;
      v23 = *(_QWORD *)(v22 + 416);
      if ( !v23 )
        goto LABEL_58;
      v24 = *(__int64 (__fastcall **)(__int64, __int64))(v23 + 192);
      if ( !v24 )
        goto LABEL_58;
      v25 = *(unsigned int *)a4;
      goto LABEL_46;
    case 1:
      return 16;
    case 2:
      result = 0;
      *(_BYTE *)(v12 + 95064) = *a4;
      return result;
    case 7:
      result = 0;
      *(_BYTE *)(v12 + 95041) = *a4;
      return result;
    case 8:
      result = 0;
      *(_QWORD *)(v12 + 8000) += *(unsigned int *)a4;
      return result;
    case 9:
      result = 0;
      *(_QWORD *)(v12 + 8008) += *(unsigned int *)a4;
      return result;
    case 11:
      v26 = *(_QWORD *)(*(_QWORD *)(v12 + 8) + 20056LL);
      if ( !v26 )
      {
        v40 = "%s: monitor soc is NULL";
        goto LABEL_66;
      }
      v27 = *(_QWORD *)(v26 + 416);
      if ( !v27 || (v28 = *(_DWORD **)(v27 + 408)) == nullptr )
      {
        v40 = "%s: callback not registered";
LABEL_66:
        v41 = "dp_monitor_config_enh_tx_capture";
        goto LABEL_67;
      }
      v29 = (unsigned __int8)*a4;
      if ( *(v28 - 1) != -1460143776 )
        __break(0x8229u);
      return ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v28)(v12, v29, 0);
    case 12:
      result = 0;
      *(_BYTE *)(v12 + 95016) = *a4;
      return result;
    case 13:
      result = 0;
      *(_BYTE *)(v12 + 95017) = *a4;
      return result;
    case 14:
      v34 = *(_QWORD *)(*(_QWORD *)(v12 + 8) + 20056LL);
      if ( !v34 )
        return 16;
      v35 = *(_QWORD *)(v34 + 416);
      if ( v35 )
      {
        v24 = *(__int64 (__fastcall **)(__int64, __int64))(v35 + 192);
        if ( v24 )
        {
          v25 = (unsigned __int8)*a4;
LABEL_46:
          if ( *((_DWORD *)v24 - 1) != -80820815 )
            __break(0x8229u);
          return v24(v12, v25);
        }
      }
LABEL_58:
      v40 = "%s: callback not registered";
      v41 = "dp_monitor_config_debug_sniffer";
LABEL_67:
      qdf_trace_msg(0x92u, 8u, v40, a5, a6, a7, a8, a9, a10, a11, a12, v41);
      return 16;
    case 15:
      result = 0;
      *(_WORD *)(v12 + 95062) = *(_WORD *)a4;
      return result;
    case 16:
      result = 0;
      *(_BYTE *)(v12 + 95043) = *a4;
      return result;
    case 18:
      v14 = *(_QWORD *)(v12 + 8);
      v15 = *(_QWORD *)(v14 + 1128);
      *(_BYTE *)(v14 + 18681) = *a4;
      v16 = *(void (**)(void))(*(_QWORD *)(v15 + 74392) + 480LL);
      if ( *((_DWORD *)v16 - 1) != -665728143 )
        __break(0x8228u);
      v16();
      return 0;
    case 20:
    case 25:
    case 27:
    case 30:
      return 0;
    case 24:
      v30 = *(_QWORD *)(*(_QWORD *)(v12 + 8) + 20056LL);
      if ( v30 )
      {
        v31 = *(_QWORD *)(v30 + 416);
        if ( v31 )
        {
          v32 = *(void (__fastcall **)(__int64, __int64))(v31 + 424);
          if ( v32 )
          {
            v33 = (unsigned __int8)*a4;
            if ( *((_DWORD *)v32 - 1) != -1368103451 )
              __break(0x8229u);
            v32(v12, v33);
            return 0;
          }
        }
        v42 = "%s: callback not registered";
      }
      else
      {
        v42 = "%s: monitor soc is NULL";
      }
      v43 = "dp_monitor_set_bsscolor";
      goto LABEL_74;
    case 26:
      v36 = *(_QWORD *)(v12 + 95560);
      if ( v36 )
        *(_BYTE *)(v36 + 39273) = *a4;
      v37 = *(_QWORD *)(*(_QWORD *)(v12 + 8) + 20056LL);
      if ( v37 )
      {
        v38 = *(_QWORD *)(v37 + 416);
        if ( v38 )
        {
          v39 = *(void (__fastcall **)(_QWORD))(v38 + 464);
          if ( v39 )
          {
            if ( *((_DWORD *)v39 - 1) != -1116635294 )
              __break(0x8229u);
            v39(v12);
            return 0;
          }
        }
        v42 = "%s: callback not registered";
      }
      else
      {
        v42 = "%s: monitor soc is NULL";
      }
      v43 = "dp_monitor_vdev_set_monitor_mode_buf_rings";
      goto LABEL_74;
    case 28:
      result = 0;
      *(_BYTE *)(v12 + 17) = *(_BYTE *)(v12 + 17) & 0xFE | *a4;
      return result;
    case 29:
      result = 0;
      *(_BYTE *)(v12 + 95568) = *a4;
      return result;
    case 31:
      wlan_cfg_set_rx_dma_buf_ring_size(*(_QWORD *)(v12 + 288), *(unsigned int *)a4);
      return 0;
    case 33:
      v18 = *(_QWORD *)(*(_QWORD *)(v12 + 8) + 20056LL);
      if ( v18 )
      {
        v19 = *(_QWORD *)(v18 + 416);
        if ( v19 )
        {
          v20 = *(void (__fastcall **)(__int64, __int64))(v19 + 1056);
          if ( v20 )
          {
            v21 = (unsigned __int8)*a4;
            if ( *((_DWORD *)v20 - 1) != 658501459 )
              __break(0x8229u);
            v20(v12, v21);
            return 0;
          }
        }
        v42 = "%s: callback not registered";
      }
      else
      {
        v42 = "%s: mon soc is NULL";
      }
      v43 = "dp_mon_config_mon_fcs_cap";
LABEL_74:
      qdf_trace_msg(0x92u, 8u, v42, a5, a6, a7, a8, a9, a10, a11, a12, v43);
      return 0;
    case 34:
      v17 = *(_QWORD *)(v12 + 95560);
      if ( !v17 )
        return 0;
      *(_BYTE *)(v17 + 39320) = *a4;
      return 0;
    default:
      return result;
  }
}
