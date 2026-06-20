__int64 __fastcall hif_ce_prepare_config(__int64 a1)
{
  int conparam; // w21
  __int64 target_info_handle; // x20
  unsigned int v4; // w8
  __int64 (*v5)(void); // x8
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 result; // x0
  unsigned int v9; // w9
  void *v10; // x8
  bool v11; // zf
  void *v12; // x10
  void *v13; // x9
  int v14; // w9
  void *v15; // x8
  void *v16; // x8
  void *v17; // x8
  void *v18; // x8
  void *v19; // x8
  void *v20; // x8
  int v21; // w9
  int v22; // w8
  int v23; // [xsp+Ch] [xbp-14h] BYREF
  int v24; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v25; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+18h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  conparam = hif_get_conparam(a1);
  target_info_handle = hif_get_target_info_handle(a1);
  v25 = 0;
  v23 = 0;
  v24 = 0;
  ce_service_srng_init();
  v4 = *(_DWORD *)(hif_get_target_info_handle(a1) + 4);
  if ( v4 > 0x2B || ((1LL << v4) & 0xFBFFFB00000LL) == 0 )
  {
    v5 = (__int64 (*)(void))ce_attach_register[0];
    if ( ce_attach_register[0] )
      goto LABEL_4;
LABEL_8:
    v6 = 0;
    goto LABEL_9;
  }
  v5 = (__int64 (*)(void))off_75CB20;
  if ( !off_75CB20 )
    goto LABEL_8;
LABEL_4:
  if ( *((_DWORD *)v5 - 1) != -1579918852 )
    __break(0x8228u);
  v6 = v5();
LABEL_9:
  v7 = *(_QWORD *)(a1 + 576);
  *(_QWORD *)(a1 + 30696) = v6;
  result = pld_get_user_msi_assignment(*(_QWORD *)(v7 + 40), "CE", &v25, &v24, &v23);
  v9 = v25;
  *(_DWORD *)(a1 + 656) = *(_DWORD *)(*(_QWORD *)(a1 + 632) + 220LL);
  if ( v9 >= 0xE )
    __break(0x5512u);
  *(_BYTE *)(a1 + 587) = 0;
  *(_QWORD *)(a1 + 664) = (char *)&ce_int_context + 12 * v9;
  if ( conparam == 8 )
  {
    *(_QWORD *)(a1 + 27400) = &host_ce_config_wlan_epping_irq;
    *(_QWORD *)(a1 + 27392) = &target_ce_config_wlan_epping;
    *(_DWORD *)(a1 + 27408) = 288;
    *(_DWORD *)(a1 + 656) = 12;
    target_shadow_reg_cfg = &target_shadow_reg_cfg_epping;
  }
  else
  {
    switch ( *(_DWORD *)(target_info_handle + 4) )
    {
      case 7:
      case 0xA:
        if ( *(_DWORD *)(a1 + 2568) == 1 )
          v16 = &host_lowdesc_ce_cfg_wlan_ar9888;
        else
          v16 = &host_ce_config_wlan_ar9888;
        *(_QWORD *)(a1 + 27392) = &target_ce_config_wlan_ar9888;
        *(_QWORD *)(a1 + 27400) = v16;
        *(_DWORD *)(a1 + 27408) = 168;
        break;
      case 9:
      case 0xF:
      case 0x11:
        v14 = *(_DWORD *)(a1 + 2568);
        v15 = &host_ce_config_wlan_ar900b;
        if ( v14 == 1 )
          v15 = &host_lowdesc_ce_cfg_wlan_ar900b;
        if ( v14 == 2 )
          v15 = &host_lowdesc_ce_cfg_wlan_ar900b_nopktlog;
        *(_QWORD *)(a1 + 27392) = &target_ce_config_wlan_ar900b;
        *(_QWORD *)(a1 + 27400) = v15;
        *(_DWORD *)(a1 + 27408) = 216;
        break;
      case 0x13:
        if ( *(_DWORD *)(a1 + 2568) == 2 )
        {
          *(_QWORD *)(a1 + 27400) = &host_lowdesc_ce_config_wlan_adrastea_nopktlog;
          *(_QWORD *)(a1 + 27392) = &target_lowdesc_ce_config_wlan_adrastea_nopktlog;
        }
        else
        {
          *(_QWORD *)(a1 + 27400) = &host_ce_config_wlan_adrastea;
          *(_QWORD *)(a1 + 27392) = &target_ce_config_wlan_adrastea;
        }
        goto LABEL_42;
      case 0x14:
      case 0x18:
      case 0x19:
        if ( *(_DWORD *)(a1 + 72) )
        {
          *(_QWORD *)(a1 + 27400) = &host_ce_config_wlan_qca8074;
          *(_QWORD *)(a1 + 27392) = &target_ce_config_wlan_qca8074;
        }
        else
        {
          *(_QWORD *)(a1 + 27400) = &host_ce_config_wlan_qca8074_pci;
          *(_QWORD *)(a1 + 27392) = &target_ce_config_wlan_qca8074_pci;
        }
        goto LABEL_42;
      case 0x15:
        *(_QWORD *)(a1 + 27400) = &host_ce_config_wlan_qca6290;
        v17 = &target_ce_config_wlan_qca6290;
        goto LABEL_54;
      case 0x16:
        result = qdf_trace_msg(61, 2, "%s: QCN7605 not supported", "hif_set_ce_config_qcn7605");
        break;
      case 0x17:
        *(_QWORD *)(a1 + 27400) = &host_ce_config_wlan_qca6390;
        v17 = &target_ce_config_wlan_qca6390;
        goto LABEL_54;
      case 0x1A:
        *(_QWORD *)(a1 + 27400) = &host_ce_config_wlan_qcn9000;
        v20 = &target_ce_config_wlan_qcn9000;
        goto LABEL_57;
      case 0x1B:
        *(_QWORD *)(a1 + 27400) = &host_ce_config_wlan_qca6490;
        v17 = &target_ce_config_wlan_qca6490;
        goto LABEL_54;
      case 0x1C:
        *(_QWORD *)(a1 + 27400) = &host_ce_config_wlan_qca6750;
        v17 = &target_ce_config_wlan_qca6750;
        goto LABEL_54;
      case 0x1D:
        *(_QWORD *)(a1 + 27400) = &host_ce_config_wlan_qca5018;
        *(_QWORD *)(a1 + 27392) = &target_ce_config_wlan_qca5018;
        *(_DWORD *)(a1 + 27408) = 216;
        *(_DWORD *)(a1 + 656) = 6;
        break;
      case 0x1E:
        *(_QWORD *)(a1 + 27400) = &host_ce_config_wlan_qcn6122;
        v20 = &target_ce_config_wlan_qcn6122;
        goto LABEL_57;
      case 0x1F:
      case 0x22:
      case 0x25:
      case 0x2B:
        result = pld_is_direct_link_supported(*(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL));
        v10 = &host_ce_config_wlan_kiwi;
        v11 = (result & 1) == 0;
        v12 = &target_ce_config_wlan_kiwi;
        if ( (result & 1) != 0 )
          v10 = &host_ce_config_wlan_kiwi_direct_link;
        v13 = &target_ce_config_wlan_kiwi_direct_link;
        goto LABEL_16;
      case 0x20:
        result = qdf_trace_msg(61, 2, "%s: QCN9224 not supported", "hif_set_ce_config_qcn9224");
        break;
      case 0x21:
        *(_QWORD *)(a1 + 27400) = &host_ce_config_wlan_qca9574;
        v18 = &target_ce_config_wlan_qca9574;
        goto LABEL_41;
      case 0x23:
        *(_QWORD *)(a1 + 27400) = &host_ce_config_wlan_qca5332;
        *(_QWORD *)(a1 + 27392) = &target_ce_config_wlan_qca5332;
        *(_DWORD *)(a1 + 27408) = 288;
        *(_DWORD *)(a1 + 656) = 12;
        break;
      case 0x24:
        *(_QWORD *)(a1 + 27400) = &host_ce_config_wlan_qcn9160;
        v20 = &target_ce_config_wlan_qcn9160;
LABEL_57:
        *(_QWORD *)(a1 + 27392) = v20;
        *(_DWORD *)(a1 + 27408) = 216;
        v22 = 6;
        goto LABEL_63;
      case 0x26:
        *(_QWORD *)(a1 + 27400) = &host_ce_config_wlan_wcn6450;
        v18 = &target_ce_config_wlan_wcn6450;
LABEL_41:
        *(_QWORD *)(a1 + 27392) = v18;
LABEL_42:
        v21 = 288;
        goto LABEL_43;
      case 0x27:
        *(_QWORD *)(a1 + 27400) = &host_ce_config_wlan_qcn6432;
        v19 = &target_ce_config_wlan_qcn6432;
        goto LABEL_62;
      case 0x28:
        result = pld_is_direct_link_supported(*(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL));
        v10 = &host_ce_config_wlan_wcn7750;
        v11 = (result & 1) == 0;
        v12 = &target_ce_config_wlan_wcn7750;
        if ( (result & 1) != 0 )
          v10 = &host_ce_config_wlan_wcn7750_direct_link;
        v13 = &target_ce_config_wlan_wcn7750_direct_link;
LABEL_16:
        if ( v11 )
          v13 = v12;
        *(_QWORD *)(a1 + 27400) = v10;
        *(_QWORD *)(a1 + 27392) = v13;
        goto LABEL_55;
      case 0x29:
        *(_QWORD *)(a1 + 27400) = &host_ce_config_wlan_qca5424;
        v19 = &target_ce_config_wlan_qca5424;
LABEL_62:
        *(_QWORD *)(a1 + 27392) = v19;
        *(_DWORD *)(a1 + 27408) = 288;
        v22 = 12;
LABEL_63:
        *(_DWORD *)(a1 + 656) = v22;
        *(_BYTE *)(a1 + 3951) = 1;
        break;
      case 0x2A:
        *(_QWORD *)(a1 + 27400) = &host_ce_config_wlan_qcc2072;
        v17 = &target_ce_config_wlan_qcc2072;
LABEL_54:
        *(_QWORD *)(a1 + 27392) = v17;
LABEL_55:
        *(_DWORD *)(a1 + 27408) = 216;
        *(_DWORD *)(a1 + 656) = 9;
        break;
      default:
        v21 = 216;
        *(_QWORD *)(a1 + 27400) = &host_ce_config_wlan;
        *(_QWORD *)(a1 + 27392) = &target_ce_config_wlan;
LABEL_43:
        *(_DWORD *)(a1 + 27408) = v21;
        break;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
