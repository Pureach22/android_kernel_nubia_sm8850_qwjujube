__int64 __fastcall sde_crtc_set_dest_scaler(__int64 a1, __int64 a2, __int64 a3)
{
  int v6; // w7
  int v7; // w21
  __int64 v8; // x24
  int v9; // w22
  _BYTE *v10; // x21
  int v11; // w9
  __int64 v12; // x26
  __int64 v13; // x20
  __int64 v14; // x10
  int v15; // w8
  __int64 v16; // x1
  __int64 result; // x0
  void *v18; // x0
  unsigned __int64 v25; // x9
  char v26; // [xsp+0h] [xbp-390h]
  unsigned int v27; // [xsp+30h] [xbp-360h]
  int s[175]; // [xsp+3Ch] [xbp-354h] BYREF
  _QWORD v29[2]; // [xsp+2F8h] [xbp-98h] BYREF
  _BYTE v30[120]; // [xsp+308h] [xbp-88h] BYREF
  __int64 v31; // [xsp+380h] [xbp-10h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29[1] = 0;
  memset(v30, 0, sizeof(v30));
  v29[0] = 0;
  memset(s, 0, sizeof(s));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "crtc %s\n", (const char *)(a1 + 2176));
  if ( a3 )
  {
    if ( inline_copy_from_user_2((int)v29, a3, 0x88u) )
    {
      v18 = &unk_22AA43;
LABEL_25:
      printk(v18, "_sde_crtc_set_dest_scaler");
      result = 4294967274LL;
      goto LABEL_23;
    }
    v7 = v29[0];
    if ( LODWORD(v29[0]) )
    {
      if ( SLODWORD(v29[0]) > 4 )
      {
        printk(&unk_24295B, "_sde_crtc_set_dest_scaler");
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "_sde_crtc_set_dest_scaler",
          4026,
          -1,
          *(_DWORD *)(a1 + 112),
          v7,
          60333,
          -1059143953,
          v26);
        result = 4294967274LL;
        goto LABEL_23;
      }
      v27 = v29[0];
      if ( SLODWORD(v29[0]) >= 1 )
      {
        v8 = 0;
        v9 = 0;
        v10 = v30;
        while ( 1 )
        {
          if ( v8 == 2368 )
            __break(0x5512u);
          v11 = *((_DWORD *)v10 - 2);
          v12 = a2;
          v13 = a2 + v8;
          v14 = *(_QWORD *)v10;
          *(_DWORD *)(v13 + 2056) = *((_DWORD *)v10 - 1);
          v15 = *((_DWORD *)v10 + 4);
          *(_DWORD *)(v13 + 2060) = v11;
          *(_QWORD *)(v13 + 2064) = v14;
          *(_DWORD *)(v13 + 2072) = v15;
          memset(s, 0, sizeof(s));
          v16 = *((_QWORD *)v10 + 1);
          if ( v16 )
          {
            if ( inline_copy_from_user_2((int)s, v16, 0x2BCu) )
              break;
          }
          sde_set_scaler_v2(v13 + 2080, s);
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(
              0,
              0,
              0,
              "en(%d)dir(%d)de(%d) src(%dx%d) dst(%dx%d)\n",
              s[0],
              s[1],
              s[88],
              s[68],
              s[72],
              s[76],
              s[77]);
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "_sde_crtc_set_dest_scaler",
            4062,
            -1,
            *(_DWORD *)(a1 + 112),
            s[0],
            s[1],
            s[88],
            s[68]);
          a2 = v12;
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(
              0,
              0,
              0,
              "ds cfg[%d]-ndx(%d) flags(%d) lm(%dx%d) merge_mode(%d)\n",
              v9,
              *((_DWORD *)v10 - 1),
              *((_DWORD *)v10 - 2),
              *(_DWORD *)v10,
              *((_DWORD *)v10 + 1),
              *((_DWORD *)v10 + 4));
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "_sde_crtc_set_dest_scaler",
            4070,
            -1,
            *(_DWORD *)(a1 + 112),
            v9,
            *((_DWORD *)v10 - 1),
            *((_DWORD *)v10 - 2),
            *(_DWORD *)v10);
          v8 += 592;
          ++v9;
          v10 += 32;
          if ( 592LL * v27 == v8 )
            goto LABEL_19;
        }
        v18 = &unk_21D45D;
        goto LABEL_25;
      }
LABEL_19:
      *(_DWORD *)(a2 + 2044) = v27;
      _X8 = (unsigned __int64 *)(a2 + 1792);
      __asm { PRFM            #0x11, [X8] }
      do
        v25 = __ldxr(_X8);
      while ( __stxr(v25 | 1, _X8) );
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "_sde_crtc_set_dest_scaler",
        4075,
        4,
        *(_DWORD *)(a1 + 112),
        v27,
        -1059143953,
        v6,
        v26);
    }
    else if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "no ds data available\n");
    }
  }
  else if ( (_drm_debug & 4) != 0 )
  {
    _drm_dev_dbg(0, 0, 0, "ds data removed\n");
  }
  result = 0;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
