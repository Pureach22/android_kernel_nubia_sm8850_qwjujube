__int64 __fastcall hif_select_service_to_pipe_map(__int64 a1, _QWORD *a2, int *a3)
{
  __int64 result; // x0
  void *v7; // x8
  void *v8; // x8
  int v9; // w9
  void *v10; // x8

  result = hif_get_conparam();
  if ( (_DWORD)result == 8 )
  {
    v7 = &target_service_to_ce_map_wlan_epping;
LABEL_3:
    *a2 = v7;
    *a3 = 204;
  }
  else
  {
    switch ( *(_DWORD *)(a1 + 20) )
    {
      case 7:
      case 9:
      case 0xA:
      case 0xF:
      case 0x11:
        v7 = &target_service_to_ce_map_ar900b;
        goto LABEL_3;
      case 0x14:
        *a2 = &target_service_to_ce_map_qca8074;
        *a3 = 240;
        break;
      case 0x15:
        v10 = &target_service_to_ce_map_qca6290;
        goto LABEL_30;
      case 0x16:
        result = qdf_trace_msg(61, 2, "%s: QCN7605 not supported", "hif_select_ce_map_qcn7605");
        break;
      case 0x17:
        v10 = &target_service_to_ce_map_qca6390;
        goto LABEL_30;
      case 0x18:
        v10 = &target_service_to_ce_map_qca8074_v2;
        goto LABEL_30;
      case 0x19:
        v10 = &target_service_to_ce_map_qca6018;
        goto LABEL_30;
      case 0x1A:
        v10 = &target_service_to_ce_map_qcn9000;
        goto LABEL_30;
      case 0x1B:
        *a2 = &target_service_to_ce_map_qca6490;
        *a3 = 192;
        break;
      case 0x1C:
        v10 = &target_service_to_ce_map_qca6750;
        goto LABEL_30;
      case 0x1D:
      case 0x1E:
      case 0x24:
        v10 = &target_service_to_ce_map_qca5018;
        goto LABEL_30;
      case 0x1F:
      case 0x22:
      case 0x25:
      case 0x2B:
        result = pld_is_direct_link_supported(*(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL));
        v8 = &target_service_to_ce_map_kiwi;
        if ( (result & 1) != 0 )
        {
          v8 = &target_service_to_ce_map_kiwi_direct_link;
          v9 = 216;
        }
        else
        {
          v9 = 192;
        }
        *a2 = v8;
        *a3 = v9;
        break;
      case 0x20:
        result = qdf_trace_msg(61, 2, "%s: QCN9224 not supported", "hif_select_ce_map_qcn9224");
        break;
      case 0x21:
        v10 = &target_service_to_ce_map_qca9574;
        goto LABEL_30;
      case 0x23:
      case 0x27:
        v10 = &target_service_to_ce_map_qca5332;
        goto LABEL_30;
      case 0x26:
        v10 = &target_service_to_ce_map_wcn6450;
        goto LABEL_30;
      case 0x28:
        result = pld_is_direct_link_supported(*(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL));
        v10 = &target_service_to_ce_map_wcn7750;
        if ( (result & 1) != 0 )
          v10 = &target_service_to_ce_map_wcn7750_direct_link;
        goto LABEL_30;
      case 0x29:
        v10 = &target_service_to_ce_map_qca5424;
        goto LABEL_30;
      case 0x2A:
        v10 = &target_service_to_ce_map_qcc2072;
LABEL_30:
        *a2 = v10;
        *a3 = 0;
        break;
      default:
        *a2 = &target_service_to_ce_map_wlan;
        *a3 = 216;
        break;
    }
  }
  *(_QWORD *)(a1 + 30704) = *a2;
  *(_DWORD *)(a1 + 30712) = *a3 / 0xCu;
  return result;
}
