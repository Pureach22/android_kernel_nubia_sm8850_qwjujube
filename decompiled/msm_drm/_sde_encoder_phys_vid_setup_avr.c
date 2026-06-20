__int64 __fastcall sde_encoder_phys_vid_setup_avr(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  __int64 v5; // x22
  unsigned int v6; // w0
  __int64 v7; // x8
  int v8; // w20
  unsigned int **v9; // x9
  unsigned int v10; // w10
  __int64 v11; // x0
  __int64 (*v12)(void); // x8
  int v13; // w22
  int v14; // w4
  __int64 v15; // x8
  int v16; // w5
  int v17; // w4

  _ReadStatusReg(SP_EL0);
  result = sde_encoder_get_disp_op(*(_QWORD *)a1);
  if ( (unsigned int)result >= 3 )
    __break(0x5512u);
  v5 = (unsigned int)result;
  if ( *(_QWORD *)(*(_QWORD *)(a1 + 424) + 8LL * (unsigned int)result + 680) )
  {
    v6 = drm_mode_vrefresh(a1 + 520);
    if ( !v6 )
    {
      result = printk(&unk_268FCD, "_sde_encoder_phys_vid_setup_avr");
      goto LABEL_28;
    }
    v7 = *(_QWORD *)(a1 + 8);
    v8 = v6;
    if ( v7 )
    {
      if ( *(_BYTE *)(v7 + 4713) == 1 )
      {
        v9 = *(unsigned int ***)(v7 + 4704);
        if ( v9 )
        {
          if ( *v9 )
          {
            v10 = **v9;
            if ( v10 )
            {
              if ( *(_DWORD *)(v7 + 4688) >= v10 || *((_BYTE *)v9 + 28) == 1 )
                a2 = v10 / 0x3E8;
            }
          }
        }
      }
    }
    if ( a2 > v6 )
    {
      result = printk(&unk_2770A9, "_sde_encoder_phys_vid_setup_avr");
      goto LABEL_28;
    }
    v11 = *(_QWORD *)(a1 + 424);
    *(_DWORD *)(a1 + 2300) = *(unsigned __int16 *)(a1 + 540) % a2 * v8 / a2 + *(unsigned __int16 *)(a1 + 540) / a2 * v8;
    v12 = *(__int64 (**)(void))(v11 + 8 * v5 + 680);
    if ( *((_DWORD *)v12 - 1) != 1970287698 )
      __break(0x8228u);
    v13 = v12();
    if ( v13 )
      printk(&unk_242CE6, "_sde_encoder_phys_vid_setup_avr");
    if ( (_drm_debug & 4) == 0 )
      goto LABEL_24;
    if ( *(_QWORD *)a1 )
    {
      v14 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
      v15 = *(_QWORD *)(a1 + 424);
      if ( v15 )
      {
LABEL_20:
        v16 = *(_DWORD *)(v15 + 32) - 1;
LABEL_23:
        _drm_dev_dbg(0, 0, 0, "enc%d intf%d configure AVR, default_fps =%d,qsync_min_fps=%d\n", v14, v16, v8, a2);
LABEL_24:
        if ( *(_QWORD *)a1 )
          v17 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
        else
          v17 = -1;
        result = sde_evtlog_log(sde_dbg_base_evtlog, "_sde_encoder_phys_vid_setup_avr", 443, -1, v17, v8, a2, v13, 239);
        goto LABEL_28;
      }
    }
    else
    {
      v14 = -1;
      v15 = *(_QWORD *)(a1 + 424);
      if ( v15 )
        goto LABEL_20;
    }
    v16 = -1;
    goto LABEL_23;
  }
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
