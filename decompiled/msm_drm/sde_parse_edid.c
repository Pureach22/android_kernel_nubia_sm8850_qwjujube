void __fastcall sde_parse_edid(__int64 *a1)
{
  void *v1; // x0
  __int64 v2; // x8
  unsigned int v4; // w9
  int v5; // w8
  long double v6; // q0
  __int64 v7; // x8
  __int64 v8; // x9
  _BYTE *v9; // x20
  int v10; // w8
  unsigned int v11; // w25
  int v12; // w27
  unsigned int v13; // w22
  __int64 block; // x0
  __int64 v15; // x1
  __int64 v16; // x2
  __int64 v17; // x7
  __int64 v18; // x21
  int v19; // w23
  __int64 v20; // x8
  __int64 v21; // x9
  __int64 v22; // x8
  _BYTE *v23; // x0
  __int64 v24; // x0
  double v25; // d0
  unsigned __int8 *v26; // x0
  __int16 v27; // t1
  char v28; // w10
  int v29; // w4
  const char *v30; // x9
  const char *v31; // x11
  const char *v32; // x5
  const char *v33; // x6
  const char *v34; // x7
  const char *v35; // x8
  const char *v36; // x10
  _BYTE v37[4]; // [xsp+20h] [xbp-10h] BYREF
  _BYTE v38[4]; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v39; // [xsp+28h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v2 = *a1;
    if ( !*a1 )
    {
      v1 = &unk_21318A;
      goto LABEL_5;
    }
    if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "%s +", "sde_edid_extract_vendor_id");
      v2 = *a1;
    }
    v4 = *(unsigned __int8 *)(v2 + 8);
    v5 = *(unsigned __int8 *)(v2 + 9);
    *((_BYTE *)a1 + 180) = 0;
    *((_BYTE *)a1 + 179) = v5 & 0x1F | 0x40;
    *((_BYTE *)a1 + 177) = (v4 >> 2) & 0x1F | 0x40;
    *((_BYTE *)a1 + 178) = ((v5 | (v4 << 8)) >> 5) & 0x1F | 0x40;
    if ( (_drm_debug & 4) != 0 )
    {
      printk(&unk_262DCA, "sde_edid_extract_vendor_id");
      if ( (_drm_debug & 4) != 0 )
      {
LABEL_11:
        *(double *)&v6 = _drm_dev_dbg(0, 0, 0, "%s -", "sde_edid_extract_vendor_id");
        v37[0] = 0;
        if ( (_drm_debug & 4) != 0 )
          *(double *)&v6 = _drm_dev_dbg(0, 0, 0, "%s +", "_sde_edid_extract_audio_data_blocks");
        v7 = *a1;
        if ( !*a1 )
          goto LABEL_35;
LABEL_17:
        v8 = *(unsigned __int8 *)(v7 + 126);
        if ( *(_BYTE *)(v7 + 126) )
        {
          v9 = (_BYTE *)(v7 + 128);
          v10 = v7 + 127;
          while ( *v9 != 2 )
          {
            --v8;
            v9 += 128;
            v10 += 128;
            if ( !v8 )
              goto LABEL_35;
          }
          if ( v8 && v9 )
          {
            v11 = 0;
            v12 = -v10;
            v13 = 4;
            *(__int64 *)((char *)a1 + 11) = 0;
            *((_DWORD *)a1 + 41) = 0;
            *(__int64 *)((char *)a1 + 19) = 0;
            *(__int64 *)((char *)a1 + 27) = 0;
            *(__int64 *)((char *)a1 + 35) = 0;
            *(__int64 *)((char *)a1 + 43) = 0;
            *(__int64 *)((char *)a1 + 51) = 0;
            *(__int64 *)((char *)a1 + 59) = 0;
            *(__int64 *)((char *)a1 + 67) = 0;
            *(__int64 *)((char *)a1 + 75) = 0;
            *(__int64 *)((char *)a1 + 83) = 0;
            *(__int64 *)((char *)a1 + 91) = 0;
            *(__int64 *)((char *)a1 + 99) = 0;
            *(__int64 *)((char *)a1 + 107) = 0;
            *(__int64 *)((char *)a1 + 115) = 0;
            *(__int64 *)((char *)a1 + 123) = 0;
            *(__int64 *)((char *)a1 + 131) = 0;
            *(__int64 *)((char *)a1 + 139) = 0;
            *(__int64 *)((char *)a1 + 147) = 0;
            *(__int64 *)((char *)a1 + 153) = 0;
            while ( 1 )
            {
              while ( 1 )
              {
                v37[0] = 0;
                block = sde_edid_find_block(v9, v13, 1, v37, v6);
                v18 = block;
                if ( !block )
                  break;
                v19 = v37[0];
                if ( v37[0] > 0x1Eu || v11 >= 5 )
                  break;
                if ( *((_DWORD *)a1 + 41) >= 0x97u || (v20 = *((unsigned int *)a1 + 41), (unsigned int)v20 > 0x96) )
                {
                  __break(0x5512u);
                  sde_get_edid(v17 - 2LL * (unsigned __int16)v12, v15, v16);
                  return;
                }
                memcpy((char *)a1 + v20 + 11, (const void *)(block + 1), v37[0]);
                ++v11;
                v13 = v12 + v19 + v18;
                *((_DWORD *)a1 + 41) += v19;
                if ( !v18 )
                {
LABEL_33:
                  if ( (_drm_debug & 4) != 0 )
                    *(double *)&v6 = _drm_dev_dbg(0, 0, 0, "%s -", "_sde_edid_extract_audio_data_blocks");
                  goto LABEL_37;
                }
              }
              if ( !*((_DWORD *)a1 + 41) )
                break;
              if ( !block )
                goto LABEL_33;
            }
            if ( (_drm_debug & 4) != 0 )
              *(double *)&v6 = _drm_dev_dbg(0, 0, 0, "No/Invalid Audio Data Block\n", *(double *)&v6);
            goto LABEL_37;
          }
        }
LABEL_35:
        if ( (_drm_debug & 4) != 0 )
          *(double *)&v6 = _drm_dev_dbg(0, 0, 0, "CEA extension not found\n", *(double *)&v6);
LABEL_37:
        v38[0] = 0;
        if ( (_drm_debug & 4) != 0 )
          *(double *)&v6 = _drm_dev_dbg(0, 0, 0, "%s +", "_sde_edid_extract_speaker_allocation_data");
        v21 = *a1;
        if ( !*a1 )
          goto LABEL_70;
        v22 = *(unsigned __int8 *)(v21 + 126);
        if ( !*(_BYTE *)(v21 + 126) )
          goto LABEL_70;
        v23 = (_BYTE *)(v21 + 128);
        while ( *v23 != 2 )
        {
          --v22;
          v23 += 128;
          if ( !v22 )
            goto LABEL_70;
        }
        if ( v22 && v23 )
        {
          v24 = sde_edid_find_block(v23, 4, 4, v38, v6);
          if ( v24 && v38[0] == 3 )
          {
            v27 = *(_WORD *)(v24 + 1);
            v26 = (unsigned __int8 *)(v24 + 1);
            v28 = _drm_debug;
            *((_BYTE *)a1 + 170) = v26[2];
            *((_WORD *)a1 + 84) = v27;
            *((_DWORD *)a1 + 43) = 3;
            if ( (v28 & 4) != 0 )
            {
              v29 = *v26;
              v30 = (const char *)&unk_229BD3;
              v31 = "FLC/FRC,";
              if ( (v29 & 1) != 0 )
                v32 = "FL/FR,";
              else
                v32 = (const char *)&unk_229BD3;
              if ( (v29 & 2) != 0 )
                v33 = "LFE,";
              else
                v33 = (const char *)&unk_229BD3;
              if ( (v29 & 4) != 0 )
                v34 = "FC,";
              else
                v34 = (const char *)&unk_229BD3;
              if ( (v29 & 8) != 0 )
                v35 = "RL/RR,";
              else
                v35 = (const char *)&unk_229BD3;
              v36 = "RC,";
              if ( (v29 & 0x10) == 0 )
                v36 = (const char *)&unk_229BD3;
              if ( (v29 & 0x20) == 0 )
                v31 = (const char *)&unk_229BD3;
              if ( (v29 & 0x40) != 0 )
                v30 = "RLC/RRC,";
              _drm_dev_dbg(
                0,
                0,
                0,
                "speaker alloc data SP byte = %08x %s%s%s%s%s%s%s\n",
                v29,
                v32,
                v33,
                v34,
                v35,
                v36,
                v31,
                v30);
              if ( (_drm_debug & 4) != 0 )
                _drm_dev_dbg(0, 0, 0, "%s -", "_sde_edid_extract_speaker_allocation_data");
            }
          }
          else if ( (_drm_debug & 4) != 0 )
          {
            _drm_dev_dbg(0, 0, 0, "No/Invalid Speaker Allocation Data Block\n", v25);
          }
        }
        else
        {
LABEL_70:
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(0, 0, 0, "CEA extension not found\n", *(double *)&v6);
        }
        goto LABEL_6;
      }
    }
    else
    {
      printk(&unk_27463C, "sde_edid_extract_vendor_id");
      if ( (_drm_debug & 4) != 0 )
        goto LABEL_11;
    }
    v37[0] = 0;
    v7 = *a1;
    if ( !*a1 )
      goto LABEL_35;
    goto LABEL_17;
  }
  v1 = &unk_2324D2;
LABEL_5:
  printk(v1, "sde_parse_edid");
LABEL_6:
  _ReadStatusReg(SP_EL0);
}
