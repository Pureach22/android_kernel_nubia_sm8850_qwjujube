__int64 __fastcall sde_crtc_setup_lm_bounds(__int64 a1, __int64 a2)
{
  __int64 v4; // x25
  unsigned __int64 v5; // x21
  __int64 v6; // x26
  int v7; // w3
  __int64 v8; // x8
  int v9; // w8
  int v10; // w9
  __int16 v11; // w10
  __int16 v12; // w11
  __int16 v13; // w9
  _WORD *v14; // x11
  __int16 v15; // w10
  _WORD *v16; // x11
  __int16 v17; // w10
  __int16 v18; // w12
  unsigned __int16 *v19; // x22
  __int64 v20; // x8
  __int64 result; // x0
  _QWORD v22[2]; // [xsp+20h] [xbp-10h] BYREF

  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v22[0] = 0;
    sde_crtc_get_mixer_resolution((_QWORD *)a1, a2, a2 + 24, (_DWORD *)v22 + 1, v22);
    if ( *(_DWORD *)(a1 + 2192) )
    {
      v4 = 0;
      v5 = 0;
      v6 = a1 + 2200;
      while ( 1 )
      {
        if ( v4 == 72 )
LABEL_25:
          __break(0x5512u);
        if ( *(_BYTE *)(a2 + 6921) != 1 )
          break;
        v7 = *(_DWORD *)(*(_QWORD *)v6 + 32LL) - 1;
        if ( v7 < 8 )
        {
          if ( (unsigned int)v7 > 7 )
            goto LABEL_25;
          v8 = a2 + 6924 + 20LL * (unsigned int)v7;
          v10 = *(_DWORD *)(v8 + 4);
          v9 = *(_DWORD *)(v8 + 8);
          if ( v4 )
          {
            if ( v4 == 64 )
              goto LABEL_25;
            v11 = *(_WORD *)(a2 + v4 + 484);
            v12 = *(_WORD *)(a2 + v4 + 488);
          }
          else
          {
            v12 = 0;
            v11 = 0;
          }
          v15 = v11 + v12;
          v16 = (_WORD *)(a2 + v4);
          v16[246] = v15;
          v17 = v22[0];
          v18 = WORD2(v22[0]);
          v16[247] = 0;
          if ( !v10 )
            LOWORD(v10) = v18;
          v16[248] = v10;
          if ( !v9 )
            LOWORD(v9) = v17;
LABEL_20:
          *(_WORD *)(a2 + v4 + 498) = v9;
          v19 = (unsigned __int16 *)(a2 + v4 + 556);
          v20 = *(_QWORD *)(a2 + v4 + 492);
          *(_QWORD *)v19 = v20;
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "_sde_crtc_setup_lm_bounds",
            4935,
            4,
            *(_DWORD *)(a1 + 112),
            v5,
            (unsigned __int16)v20,
            WORD1(v20),
            SBYTE4(v20));
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(
              0,
              0,
              0,
              "%s: lm%d bnd&roi (%d,%d,%d,%d)\n",
              (const char *)(a1 + 2176),
              v5,
              *v19,
              *(unsigned __int16 *)(a2 + v4 + 558),
              *(unsigned __int16 *)(a2 + v4 + 560),
              *(unsigned __int16 *)(a2 + v4 + 562));
          goto LABEL_5;
        }
        printk(&unk_2429E3, "_sde_crtc_setup_lm_bounds");
LABEL_5:
        ++v5;
        v4 += 8;
        v6 += 48;
        if ( v5 >= *(unsigned int *)(a1 + 2192) )
          goto LABEL_22;
      }
      if ( v4 == 64 )
        goto LABEL_25;
      LOWORD(v9) = v22[0];
      v13 = WORD2(v22[0]);
      v14 = (_WORD *)(a2 + v4);
      v14[247] = 0;
      v14[248] = v13;
      v14[246] = v13 * v5;
      goto LABEL_20;
    }
LABEL_22:
    result = drm_mode_debug_printmodeline(a2 + 24);
  }
  else
  {
    result = printk(&unk_211DA1, "_sde_crtc_setup_lm_bounds");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
