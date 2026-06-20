__int64 __fastcall sde_edid_update_modes(__int64 a1, _QWORD *a2)
{
  unsigned int v4; // w0
  double v5; // d0
  __int64 v6; // x28
  unsigned int v7; // w19
  __int64 v8; // x8
  __int64 v9; // x21
  int v10; // w24
  int v11; // w8
  __int64 v12; // x25
  __int64 v13; // x23
  unsigned int v14; // w9
  int v15; // w8
  __int64 v16; // x8
  int v17; // w4
  __int64 v18; // x8
  char v19; // w9
  _BYTE *v20; // x9
  int v21; // w4
  char v22; // w8
  unsigned int v23; // w8
  __int64 v24; // x9

  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "%s +", "_sde_edid_update_modes");
  if ( *a2 )
  {
    drm_connector_update_edid_property(a1);
    v4 = drm_add_edid_modes(a1, *a2);
    v6 = *a2;
    v7 = v4;
    if ( v6 )
    {
      v8 = *(unsigned __int8 *)(v6 + 126);
      if ( *(_BYTE *)(v6 + 126) )
      {
        v9 = 0;
        while ( *(_BYTE *)(v6 + v9 + 128) != 2 )
        {
          v9 += 128;
          if ( v8 << 7 == v9 )
            goto LABEL_67;
        }
        if ( v9 != v8 << 7 && v6 + v9 != -128 && *(unsigned __int8 *)(v6 + v9 + 129) >= 3u )
        {
          v10 = *(_BYTE *)(v6 + v9 + 130) ? *(unsigned __int8 *)(v6 + v9 + 130) : 127;
          if ( (char)v10 >= 5 )
          {
            v11 = 4;
            do
            {
              v12 = v11;
              v13 = v6 + v9 + v11;
              v14 = *(unsigned __int8 *)(v13 + 128);
              if ( (int)(v11 + (v14 & 0x1F)) >= v10 )
                break;
              if ( v14 >= 0xE0 )
              {
                if ( (_drm_debug & 4) != 0 )
                  v5 = _drm_dev_dbg(0, 0, 0, "found ext tag block = %d\n", *(unsigned __int8 *)(v6 + v11 + v9 + 129));
                v15 = *(unsigned __int8 *)(v6 + v12 + v9 + 129);
                switch ( v15 )
                {
                  case 6:
                    if ( v13 != -128 )
                    {
                      v20 = (_BYTE *)(v6 + v12 + v9);
                      v21 = v20[130] & 0x3F;
                      v22 = *(_BYTE *)(v13 + 128);
                      *(_DWORD *)(a1 + 4640) = v21;
                      v23 = v22 & 0x1F;
                      *(_BYTE *)(a1 + 4644) = v20[131] & 1;
                      if ( v23 >= 4 )
                      {
                        *(_DWORD *)(a1 + 4648) = (unsigned __int8)v20[132];
                        if ( v23 != 4 )
                        {
                          v24 = v6 + v12 + v9;
                          *(_DWORD *)(a1 + 4652) = *(unsigned __int8 *)(v24 + 133);
                          if ( v23 >= 6 )
                            *(_DWORD *)(a1 + 4656) = *(unsigned __int8 *)(v24 + 134);
                        }
                      }
                      *(_BYTE *)(a1 + 4660) = 1;
                      if ( (_drm_debug & 4) != 0 )
                      {
                        v5 = _drm_dev_dbg(0, 0, 0, "HDR electro-optical %d\n", v21);
                        if ( (_drm_debug & 4) != 0 )
                        {
                          v5 = _drm_dev_dbg(0, 0, 0, "metadata desc 1 %d\n", *(unsigned __int8 *)(a1 + 4644));
                          if ( (_drm_debug & 4) != 0 )
                          {
                            v5 = _drm_dev_dbg(0, 0, 0, "max luminance %d\n", *(_DWORD *)(a1 + 4648));
                            if ( (_drm_debug & 4) != 0 )
                            {
                              v5 = _drm_dev_dbg(0, 0, 0, "avg luminance %d\n", *(_DWORD *)(a1 + 4652));
                              if ( (_drm_debug & 4) != 0 )
                                v5 = _drm_dev_dbg(0, 0, 0, "min luminance %d\n");
                            }
                          }
                        }
                      }
                    }
                    break;
                  case 5:
                    if ( v13 != -128 )
                    {
                      v17 = *(_DWORD *)(a1 + 4664);
                      v18 = v6 + v12 + v9;
                      v19 = *(_BYTE *)(v18 + 130);
                      if ( (v19 & 1) != 0 )
                      {
                        v17 |= 1u;
                        *(_DWORD *)(a1 + 4664) = v17;
                        v19 = *(_BYTE *)(v18 + 130);
                        if ( (v19 & 2) != 0 )
                          goto LABEL_60;
LABEL_39:
                        if ( (v19 & 4) == 0 )
                          goto LABEL_40;
LABEL_61:
                        v17 |= 4u;
                        *(_DWORD *)(a1 + 4664) = v17;
                        v19 = *(_BYTE *)(v18 + 130);
                        if ( (v19 & 8) != 0 )
                          goto LABEL_62;
LABEL_41:
                        if ( (v19 & 0x10) == 0 )
                          goto LABEL_42;
LABEL_63:
                        v17 |= 0x10u;
                        *(_DWORD *)(a1 + 4664) = v17;
                        v19 = *(_BYTE *)(v18 + 130);
                        if ( (v19 & 0x20) != 0 )
                          goto LABEL_64;
LABEL_43:
                        if ( (v19 & 0x40) == 0 )
                          goto LABEL_44;
LABEL_65:
                        v17 |= 0x40u;
                        *(_DWORD *)(a1 + 4664) = v17;
                        if ( (*(_BYTE *)(v18 + 130) & 0x80) == 0 )
                        {
LABEL_45:
                          if ( *(char *)(v6 + v12 + v9 + 131) < 0 )
                            *(_DWORD *)(a1 + 4664) = v17 | 0x8000;
                          v5 = _drm_dev_dbg(0, 0, 2, "colorimetry fmts = 0x%x\n");
                          break;
                        }
                      }
                      else
                      {
                        if ( (*(_BYTE *)(v18 + 130) & 2) == 0 )
                          goto LABEL_39;
LABEL_60:
                        v17 |= 2u;
                        *(_DWORD *)(a1 + 4664) = v17;
                        v19 = *(_BYTE *)(v18 + 130);
                        if ( (v19 & 4) != 0 )
                          goto LABEL_61;
LABEL_40:
                        if ( (v19 & 8) == 0 )
                          goto LABEL_41;
LABEL_62:
                        v17 |= 8u;
                        *(_DWORD *)(a1 + 4664) = v17;
                        v19 = *(_BYTE *)(v18 + 130);
                        if ( (v19 & 0x10) != 0 )
                          goto LABEL_63;
LABEL_42:
                        if ( (v19 & 0x20) == 0 )
                          goto LABEL_43;
LABEL_64:
                        v17 |= 0x20u;
                        *(_DWORD *)(a1 + 4664) = v17;
                        v19 = *(_BYTE *)(v18 + 130);
                        if ( (v19 & 0x40) != 0 )
                          goto LABEL_65;
LABEL_44:
                        if ( (v19 & 0x80) == 0 )
                          goto LABEL_45;
                      }
                      v17 |= 0x80u;
                      *(_DWORD *)(a1 + 4664) = v17;
                      goto LABEL_45;
                    }
                    _drm_err("invalid db\n", v5);
                    break;
                  case 1:
                    if ( (_drm_debug & 4) != 0 )
                      v5 = _drm_dev_dbg(0, 0, 0, "%s +\n", "sde_edid_parse_vsvdb_info");
                    if ( (*(_BYTE *)(v13 + 128) & 0x1Fu) >= 5 )
                    {
                      v16 = v6 + v12 + v9;
                      if ( (*(unsigned __int16 *)(v16 + 130) | (*(unsigned __int8 *)(v16 + 132) << 16)) == 0x90848B )
                        *(_BYTE *)(a1 + 4672) = *(_BYTE *)(v16 + 133) & 3;
                      if ( (_drm_debug & 4) != 0 )
                        v5 = _drm_dev_dbg(0, 0, 0, "%s -\n", "sde_edid_parse_vsvdb_info");
                    }
                    break;
                }
              }
              v11 = (*(_BYTE *)(v13 + 128) & 0x1F) + v12 + 1;
            }
            while ( v11 < v10 );
          }
        }
      }
    }
LABEL_67:
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "%s -", "_sde_edid_update_modes");
  }
  else
  {
    drm_connector_update_edid_property(a1);
    v7 = 0;
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "%s null edid -", "_sde_edid_update_modes");
  }
  return v7;
}
