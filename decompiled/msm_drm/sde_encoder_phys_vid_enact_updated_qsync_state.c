__int64 __fastcall sde_encoder_phys_vid_enact_updated_qsync_state(__int64 *a1)
{
  __int64 v2; // x0
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x20
  __int64 v6; // x21
  unsigned int v7; // w3
  __int64 v8; // x8
  __int64 v9; // x20
  unsigned int v10; // w22
  __int64 v11; // x20
  int v12; // w7
  __int64 v13; // x8
  int v14; // w8
  __int64 v15; // x0
  void (*v16)(void); // x8
  int v17; // w4
  unsigned int v18; // w22
  __int64 v19; // x0
  _DWORD *v20; // x8
  __int64 v21; // x0
  __int64 v22; // x2
  char v23; // [xsp+0h] [xbp-20h]
  unsigned int v24; // [xsp+4h] [xbp-1Ch] BYREF
  int v25[2]; // [xsp+8h] [xbp-18h]
  int v26; // [xsp+10h] [xbp-10h]
  __int64 v27; // [xsp+18h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  *(_QWORD *)v25 = 0;
  v24 = 0;
  if ( !a1 || (v2 = *a1) == 0 )
  {
    result = printk(&unk_273B3E, "sde_encoder_phys_vid_enact_updated_qsync_state");
    goto LABEL_44;
  }
  result = sde_encoder_get_disp_op(v2);
  v4 = a1[1];
  if ( v4 )
  {
    v5 = *(_QWORD *)(v4 + 2512);
    if ( v5 )
    {
      v6 = *a1;
      if ( !*a1 || *(_BYTE *)(v6 + 751) != 1 )
      {
LABEL_9:
        if ( (*(_BYTE *)(v5 + 3240) & 8) != 0 )
          goto LABEL_44;
        goto LABEL_10;
      }
      v7 = *((unsigned __int16 *)a1 + 1178);
      if ( v7 > 2 )
      {
        if ( v7 == 4 )
        {
          v18 = result;
          v19 = a1[1];
          *((_WORD *)a1 + 1178) = 1;
LABEL_28:
          sde_connector_update_cmd(v19, 0x4000000, 0);
          goto LABEL_29;
        }
        v18 = result;
        if ( v7 == 3 )
        {
          printk(&unk_24617C, "_sde_encoder_phys_vid_arp_ctrl");
          *((_WORD *)a1 + 1178) = 1;
          hrtimer_cancel(a1 + 302);
          hrtimer_cancel(a1 + 310);
          goto LABEL_29;
        }
      }
      else
      {
        if ( v7 == 1 )
          goto LABEL_9;
        v18 = result;
        if ( v7 == 2 )
        {
          printk(&unk_26227F, "_sde_encoder_phys_vid_arp_ctrl");
          v19 = a1[1];
          *((_WORD *)a1 + 1178) = 1;
          goto LABEL_28;
        }
      }
      printk(&unk_21D16D, "_sde_encoder_phys_vid_arp_ctrl");
LABEL_29:
      result = v18;
      if ( (*(_BYTE *)(v5 + 3240) & 8) != 0 )
        goto LABEL_44;
LABEL_10:
      v8 = a1[1];
      if ( v8 && *(_BYTE *)(v8 + 4680) == 1 )
      {
        v9 = *a1;
        if ( *a1 )
        {
          v10 = result;
          if ( (((__int64 (__fastcall *)(__int64))sde_encoder_in_clone_mode)(*a1) & 1) == 0 )
          {
            v11 = *(_QWORD *)(v9 + 4960);
            if ( v11 )
            {
              sde_encoder_phys_vid_setup_panic_ctrl((__int64)a1);
              v13 = a1[1];
              if ( !v13 || !*(_DWORD *)(v13 + 4676) )
              {
                v14 = *(_DWORD *)(v11 + 8);
                v15 = a1[52];
                v26 = 0;
                v25[0] = v14;
                if ( v15 )
                {
                  if ( v10 >= 3 )
                  {
                    __break(0x5512u);
                    JUMPOUT(0xF9D28);
                  }
                  v16 = *(void (**)(void))(v15 + 8LL * v10 + 1624);
                  if ( v16 )
                  {
                    if ( *((_DWORD *)v16 - 1) != -1386749835 )
                      __break(0x8228u);
                    v16();
                  }
                }
                if ( *a1 )
                  v17 = *(_DWORD *)(*a1 + 24);
                else
                  v17 = -1;
                sde_evtlog_log(
                  sde_dbg_base_evtlog,
                  "sde_encoder_phys_vid_enact_updated_qsync_state",
                  2167,
                  -1,
                  v17,
                  v25[0],
                  -1059143953,
                  v12,
                  v23);
              }
            }
          }
        }
        if ( *(_BYTE *)(v6 + 749) == 1 )
        {
          v20 = (_DWORD *)a1[50];
          if ( v20 )
          {
            v21 = *a1;
            v22 = *(_QWORD *)(a1[1] + 2512);
            if ( *(v20 - 1) != 1659771273 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, unsigned int *, __int64, _QWORD))v20)(v21, &v24, v22, 0);
            sde_encoder_phys_vid_setup_avr((__int64)a1, v24);
          }
        }
        result = sde_encoder_phys_vid_avr_ctrl((__int64)a1);
      }
    }
  }
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return result;
}
