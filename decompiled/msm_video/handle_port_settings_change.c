__int64 __fastcall handle_port_settings_change(__int64 a1, __int64 a2)
{
  __int64 v3; // x4
  unsigned int v4; // w0
  unsigned int v5; // w20
  int v6; // w0
  __int64 v7; // x1
  __int64 v8; // x2
  __int64 v9; // x3
  __int64 v10; // x4
  __int64 v12; // x20

  if ( a1 && (msm_vidc_debug & 2) != 0 )
  {
    v12 = a2;
    printk(&unk_7FF74, "high", a1 + 340, "handle_port_settings_change", *(unsigned int *)(a2 + 16));
    a2 = v12;
  }
  v3 = *(unsigned int *)(a2 + 16);
  if ( (_DWORD)v3 != 1 )
  {
    if ( (_DWORD)v3 == 2 )
    {
      if ( a1 && (msm_vidc_debug & 2) != 0 )
        printk(&unk_8538F, "high", a1 + 340, "OUTPUT_PSC", HIWORD(*(_DWORD *)(a1 + 3328)));
      v4 = msm_vdec_output_port_settings_change();
      goto LABEL_10;
    }
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_8A307, "err ", a1 + 340, "handle_port_settings_change", v3);
    goto LABEL_22;
  }
  v6 = msm_vidc_allow_input_psc(a1);
  if ( !v6 )
  {
LABEL_22:
    v5 = -22;
    goto LABEL_23;
  }
  if ( v6 != 1 )
    return 0;
  v5 = msm_vidc_state_change_input_psc(a1);
  if ( !v5 )
  {
    if ( a1 && (msm_vidc_debug & 2) != 0 )
      printk(&unk_8538F, "high", a1 + 340, "INPUT_PSC", HIWORD(*(_DWORD *)(a1 + 3272)));
    v4 = msm_vdec_input_port_settings_change(a1, v7, v8, v9, v10);
LABEL_10:
    v5 = v4;
    if ( !v4 )
      return v5;
  }
LABEL_23:
  msm_vidc_change_state(a1, 5u, (__int64)"handle_port_settings_change");
  return v5;
}
