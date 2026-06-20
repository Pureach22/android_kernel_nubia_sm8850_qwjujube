__int64 __fastcall a6xx_gmu_first_boot(__int64 a1)
{
  unsigned __int8 *v2; // x20
  unsigned __int64 v3; // x8
  int v4; // w3
  int v5; // w0
  __int64 v6; // x8
  int v7; // w0
  __int64 result; // x0
  int v9; // w0
  int fw; // w0
  __int64 v11; // x21
  unsigned int v12; // w8
  unsigned int pdc_ucode; // w0
  unsigned int v14; // w22
  __int64 v15; // x2
  __int64 v16; // x23
  unsigned int v18; // w0
  unsigned int v19; // w22
  unsigned __int64 StatusReg; // x22
  __int64 v21; // x23
  int v22; // w21
  unsigned int v23; // w21
  unsigned __int64 v29; // x8
  _QWORD v30[2]; // [xsp+0h] [xbp-40h] BYREF
  _QWORD v31[4]; // [xsp+10h] [xbp-30h] BYREF
  int v32; // [xsp+30h] [xbp-10h]
  __int64 v33; // [xsp+38h] [xbp-8h]

  v2 = (unsigned __int8 *)(a1 + 20433);
  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  kgsl_pwrctrl_request_state(a1, 32);
  v3 = *(_QWORD *)(a1 - 384);
  if ( v3 )
  {
    if ( v3 <= 0xFFFFFFFFFFFFF000LL )
    {
      v4 = *v2;
      v30[0] = 0;
      memset(v31, 0, sizeof(v31));
      v32 = 0;
      v5 = scnprintf(v31, 36, "{class: gpu, res: acd, val: %d}", v4);
      v6 = *(_QWORD *)(a1 - 384);
      v30[1] = v31;
      v30[0] = (v5 & 0xFFFFFFFC) + 4;
      v7 = mbox_send_message(v6, v30);
      if ( v7 < 0 )
        dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "AOP mbox send message failed: %d\n", v7);
    }
  }
  result = ((__int64 (__fastcall *)(__int64))kgsl_pwrctrl_enable_cx_gdsc)(a1);
  if ( !(_DWORD)result )
  {
    v9 = gmu_core_enable_clks(a1, 0);
    if ( v9 )
    {
LABEL_28:
      v23 = v9;
      if ( *(_QWORD *)(a1 + 9024) && (v2[224] & 2) != 0 )
      {
        __break(0x800u);
        if ( *(_QWORD *)(a1 + 9000) )
        {
LABEL_31:
          if ( (v2[224] & 2) != 0 )
            regulator_set_mode();
        }
      }
      else if ( *(_QWORD *)(a1 + 9000) )
      {
        goto LABEL_31;
      }
      kgsl_pwrctrl_disable_cx_gdsc(a1);
      if ( *(_QWORD *)(a1 + 9000) && (v2[224] & 2) != 0 )
        regulator_set_mode();
      gmu_core_rdpm_cx_freq_update(a1, 0);
      result = v23;
      goto LABEL_37;
    }
    fw = a6xx_gmu_load_fw(a1);
    if ( !fw )
    {
      v11 = a1 - 360;
      if ( *(_QWORD *)(a1 - 360) )
      {
        while ( 1 )
        {
          a6xx_gmu_register_config(a1);
          a6xx_gmu_version_info(a1);
          a6xx_gmu_irq_enable(a1);
          v12 = *(_DWORD *)(a1 + 10052);
          if ( v12 < 0x20 )
            break;
          __break(0x5512u);
          StatusReg = _ReadStatusReg(SP_EL0);
          v21 = *(_QWORD *)(StatusReg + 80);
          *(_QWORD *)(StatusReg + 80) = &a6xx_gmu_itcm_shadow__alloc_tag;
          v15 = vzalloc_noprof(*(unsigned int *)(*(_QWORD *)(a1 + 8224) + 4LL));
          *(_QWORD *)(StatusReg + 80) = v21;
          *(_QWORD *)v11 = v15;
          if ( !v15 )
            goto LABEL_26;
LABEL_15:
          if ( *(_DWORD *)(*(_QWORD *)(a1 + 8224) + 4LL) >= 4u )
          {
            LODWORD(v11) = 0;
            do
            {
              v16 = v15 + 4;
              gmu_core_regread(a1, (unsigned int)(v11 + 111616), v15);
              v11 = (unsigned int)(v11 + 1);
              v15 = v16;
            }
            while ( (unsigned int)v11 < *(_DWORD *)(*(_QWORD *)(a1 + 8224) + 4LL) >> 2 );
          }
        }
        icc_set_bw(
          *(_QWORD *)(a1 + 10456),
          0,
          *(unsigned int *)(*(_QWORD *)(a1 + 10392) + 4LL * *(int *)(a1 + 28LL * v12 + 9152)));
        *(_DWORD *)(v2 + 4015) = 0;
        __dmb(0xAu);
        pdc_ucode = a6xx_gmu_device_start(a1);
        if ( pdc_ucode )
          goto LABEL_11;
        _X22 = (unsigned __int64 *)(a1 - 352);
        if ( (*(_QWORD *)(a1 - 352) & 0x20) != 0 )
        {
          if ( (v2[223] & 0x20) == 0 )
            goto LABEL_42;
        }
        else
        {
          pdc_ucode = a6xx_load_pdc_ucode(a1);
          if ( pdc_ucode )
          {
LABEL_11:
            v14 = pdc_ucode;
            a6xx_gmu_irq_disable(a1);
            if ( *(_BYTE *)(a1 + 13192) == 1 )
            {
              a6xx_gmu_suspend(a1, 0);
              result = v14;
              goto LABEL_37;
            }
            fw = v14;
            goto LABEL_27;
          }
          a6xx_load_rsc_ucode(a1);
          __asm { PRFM            #0x11, [X22] }
          do
            v29 = __ldxr(_X22);
          while ( __stxr(v29 | 0x20, _X22) );
          if ( (v2[223] & 0x20) == 0 )
            goto LABEL_42;
        }
        v18 = a6xx_gmu_gfx_rail_on(a1);
        if ( v18 )
        {
          v19 = v18;
          a6xx_gmu_oob_clear(a1, 6u);
          pdc_ucode = v19;
          goto LABEL_11;
        }
LABEL_42:
        if ( *(_DWORD *)(a1 - 448) || (pdc_ucode = a6xx_gmu_sptprac_enable(a1)) == 0 )
        {
          pdc_ucode = a6xx_gmu_hfi_start(a1);
          if ( !pdc_ucode )
          {
            pdc_ucode = ((__int64 (__fastcall *)(__int64))a6xx_hfi_start)(a1);
            if ( !pdc_ucode )
            {
              icc_set_bw(*(_QWORD *)(a1 + 10456), 0, 0);
              *(_BYTE *)(a1 + 13192) = 0;
              kgsl_pwrctrl_set_state(a1, 32);
              result = 0;
              goto LABEL_37;
            }
          }
        }
        goto LABEL_11;
      }
      v15 = vzalloc_noprof(*(unsigned int *)(*(_QWORD *)(a1 + 8224) + 4LL));
      *(_QWORD *)v11 = v15;
      if ( v15 )
        goto LABEL_15;
LABEL_26:
      fw = -12;
    }
LABEL_27:
    v22 = fw;
    gmu_core_disable_clks(a1);
    v9 = v22;
    goto LABEL_28;
  }
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return result;
}
