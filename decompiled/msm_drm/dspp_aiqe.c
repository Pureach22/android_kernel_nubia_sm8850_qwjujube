__int64 __fastcall dspp_aiqe(__int64 result)
{
  __int64 v1; // x8
  _QWORD *v2; // x19
  __int64 v3; // x8
  int v4; // w8
  __int64 v5; // x8
  __int64 v6; // x9

  if ( !result )
    return printk(&unk_26FEB0, "dspp_aiqe");
  v1 = *(_QWORD *)(result + 1504);
  v2 = (_QWORD *)result;
  if ( v1 )
  {
    v3 = *(_QWORD *)(v1 + 152);
    if ( v3 )
    {
      if ( (*(_BYTE *)(v3 + 20112) & 1) != 0 )
      {
        v4 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 72) + 48LL) + 612LL);
        if ( v4 == 0x20000 || v4 == 0x10000 )
        {
          result = reg_dmav1_init_dspp_op_v4(0x15u, result);
          if ( !(_DWORD)result )
          {
            v5 = v2[9];
            v6 = *(_QWORD *)(v5 + 48);
            if ( *(_BYTE *)(v6 + 616) == 1 )
            {
              v2[146] = reg_dmav1_setup_mdnie_v1;
              v2[149] = sde_setup_mdnie_art_v1;
              v2[170] = sde_reset_mdnie_art;
              v2[173] = sde_setup_mdnie_psr;
              v6 = *(_QWORD *)(v5 + 48);
              if ( *(_DWORD *)(v6 + 612) == 0x20000 )
              {
                v2[146] = reg_dmav1_setup_mdnie_v2;
                v6 = *(_QWORD *)(v5 + 48);
              }
            }
            if ( *(_BYTE *)(v6 + 618) == 1 )
            {
              v2[158] = sde_validate_aiqe_ssrc_data_v1;
              v2[152] = reg_dmav1_setup_aiqe_ssrc_config_v1;
              v2[155] = reg_dmav1_setup_aiqe_ssrc_data_v1;
              v6 = *(_QWORD *)(v5 + 48);
            }
            if ( *(_BYTE *)(v6 + 619) == 1 )
            {
              v2[161] = sde_setup_copr_v1;
              v2[167] = sde_read_copr_status;
              v6 = *(_QWORD *)(v5 + 48);
            }
            if ( *(_BYTE *)(v6 + 617) == 1 )
              v2[182] = sde_setup_aiqe_abc_v1;
          }
        }
      }
      else if ( (_drm_debug & 4) != 0 )
      {
        return printk(&unk_269B57, *(unsigned __int8 *)(v3 + 20112));
      }
      else
      {
        return printk(&unk_25BAC7, "dspp_aiqe");
      }
    }
  }
  return result;
}
