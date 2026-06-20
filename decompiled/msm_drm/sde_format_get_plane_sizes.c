__int64 __fastcall sde_format_get_plane_sizes(__int64 a1, unsigned int a2, unsigned int a3, __int64 a4, _DWORD *a5)
{
  __int64 v5; // x11
  _DWORD *v6; // x10
  int v7; // w9
  int v8; // w8
  __int64 result; // x0
  int v10; // w8
  unsigned int v11; // w10
  int v12; // w9
  int v13; // w10
  char v14; // w9
  unsigned int v15; // w8
  char v16; // w8
  unsigned int v17; // w8
  unsigned int v18; // w12
  int v19; // w8
  const char *v20; // x8
  int v21; // w11
  int v22; // w12
  unsigned int v23; // w10
  unsigned int v24; // w11
  unsigned int v25; // w12
  int v26; // w12
  int v27; // w12
  int v28; // w13
  int v29; // w13
  unsigned int v30; // w14
  int v31; // w8
  int v32; // w10
  unsigned int v33; // w13
  unsigned int v34; // w10
  unsigned __int16 v35; // w10
  int v36; // w10
  unsigned int v37; // w11
  int v38; // w13
  int v39; // w13
  int v40; // w14
  int v41; // w14
  unsigned int v42; // w15
  int v43; // w10
  unsigned int v44; // w11
  int v45; // w11
  unsigned int v46; // w11
  int v47; // w10
  int v48; // w11
  unsigned int v49; // w14
  unsigned int v50; // w14
  unsigned int v51; // w14
  unsigned int v52; // w8

  if ( !a1 || !a4 )
  {
    _drm_err("invalid pointer\n");
    return 4294967274LL;
  }
  if ( (a3 | a2) >= 0x4000 )
  {
    _drm_err("image dimensions outside max range\n");
    return 4294967262LL;
  }
  if ( *(_DWORD *)(a1 + 28) != 2 )
  {
    *(_QWORD *)(a4 + 56) = 0;
    *(_QWORD *)(a4 + 64) = 0;
    *(_QWORD *)(a4 + 40) = 0;
    *(_QWORD *)(a4 + 48) = 0;
    *(_QWORD *)(a4 + 24) = 0;
    *(_QWORD *)(a4 + 32) = 0;
    *(_QWORD *)(a4 + 8) = 0;
    *(_QWORD *)(a4 + 16) = 0;
    *(_QWORD *)a4 = a1;
    *(_DWORD *)(a4 + 12) = a2;
    *(_DWORD *)(a4 + 16) = a3;
    *(_DWORD *)(a4 + 8) = *(unsigned __int8 *)(a1 + 25);
    v10 = *(_DWORD *)(a1 + 4);
    if ( v10 )
    {
      v11 = *(_DWORD *)(a1 + 16) - 1;
      if ( v11 > 2 )
      {
        v12 = 1;
        v13 = 1;
      }
      else
      {
        v12 = dword_28D73C[v11];
        v13 = dword_28D748[v11];
      }
      if ( ((v13 + 0x3FFF) & a2) != 0 || ((v12 + 0x3FFF) & a3) != 0 )
      {
        _drm_err("mismatch in subsample vs dimensions\n");
        return 4294967274LL;
      }
      if ( *(_DWORD *)a1 == 808530512 || *(_DWORD *)a1 == 842094158 && (*(_QWORD *)(a1 + 32) & 2) != 0 )
        v21 = 2;
      else
        v21 = 1;
      v22 = v21 * a2;
      v23 = (unsigned __int16)(v21 * a2) / (unsigned int)(unsigned __int16)v13;
      *(_DWORD *)(a4 + 56) = v21 * a2;
      *(_DWORD *)(a4 + 60) = v23;
      v24 = (unsigned __int16)a3 / (unsigned int)(unsigned __int16)v12 * v23;
      *(_DWORD *)(a4 + 40) = v22 * a3;
      *(_DWORD *)(a4 + 44) = v24;
      if ( *(_DWORD *)(a1 + 4) == 2 )
      {
        *(_DWORD *)(a4 + 8) = 2;
        v14 = 1;
        *(_DWORD *)(a4 + 44) = 2 * v24;
        *(_DWORD *)(a4 + 60) = 2 * v23;
        if ( !a5 )
          goto LABEL_18;
      }
      else
      {
        v14 = 0;
        *(_DWORD *)(a4 + 48) = v24;
        *(_DWORD *)(a4 + 8) = 3;
        *(_DWORD *)(a4 + 64) = v23;
        if ( !a5 )
          goto LABEL_18;
      }
    }
    else
    {
      v14 = 0;
      *(_DWORD *)(a4 + 8) = 1;
      *(_DWORD *)(a4 + 40) = a3 * a2 * *(unsigned __int8 *)(a1 + 23);
      *(_DWORD *)(a4 + 56) = *(unsigned __int8 *)(a1 + 23) * a2;
      if ( !a5 )
      {
LABEL_18:
        if ( v10 )
        {
          if ( a5 )
          {
            v15 = a5[1];
            if ( *(_DWORD *)(a4 + 60) < v15 )
              *(_DWORD *)(a4 + 60) = v15;
          }
          if ( a5 )
            v16 = v14;
          else
            v16 = 1;
          if ( (v16 & 1) == 0 )
          {
            v17 = a5[2];
            if ( *(_DWORD *)(a4 + 64) < v17 )
              *(_DWORD *)(a4 + 64) = v17;
          }
        }
        v18 = *(_DWORD *)(a4 + 20);
        result = 0;
        v19 = *(_DWORD *)(a4 + 48) + *(_DWORD *)(a4 + 52) + *(_DWORD *)(a4 + 44) + *(_DWORD *)(a4 + 40);
        goto LABEL_194;
      }
    }
    if ( *(_DWORD *)(a4 + 56) < *a5 )
      *(_DWORD *)(a4 + 56) = *a5;
    goto LABEL_18;
  }
  v5 = *(_QWORD *)(a1 + 32);
  *(_QWORD *)(a4 + 56) = 0;
  *(_QWORD *)(a4 + 64) = 0;
  *(_QWORD *)(a4 + 8) = 0;
  v6 = (_DWORD *)(a4 + 8);
  *(_QWORD *)(a4 + 40) = 0;
  *(_QWORD *)(a4 + 48) = 0;
  *(_QWORD *)(a4 + 24) = 0;
  *(_QWORD *)(a4 + 32) = 0;
  *(_QWORD *)(a4 + 16) = 0;
  *(_QWORD *)a4 = a1;
  *(_DWORD *)(a4 + 12) = a2;
  *(_DWORD *)(a4 + 16) = a3;
  *(_DWORD *)(a4 + 8) = *(unsigned __int8 *)(a1 + 25);
  v7 = *(_DWORD *)a1;
  if ( *(_DWORD *)a1 == 808530512 )
  {
    v8 = 16;
    if ( (*(_QWORD *)(a1 + 32) & 0x20) != 0 )
      goto LABEL_41;
  }
  else
  {
    if ( v7 == 842094158 )
    {
      if ( (*(_QWORD *)(a1 + 32) & 2) != 0 )
      {
        if ( *(_BYTE *)(a1 + 21) )
          v8 = 3;
        else
          v8 = 8;
      }
      else
      {
        v8 = 2;
      }
      goto LABEL_66;
    }
    v8 = -1;
    if ( (*(_QWORD *)(a1 + 32) & 0x20) != 0 )
    {
LABEL_41:
      v8 = 13;
      goto LABEL_66;
    }
  }
  if ( (*(_QWORD *)(a1 + 32) & 0x40) != 0 )
  {
    v8 = 14;
    goto LABEL_66;
  }
  if ( v7 > 875709015 )
  {
    switch ( v7 )
    {
      case 1211384385:
        v20 = (const char *)&unk_28C678;
        break;
      case 909199170:
        v20 = "BG16\a";
        break;
      case 875709016:
        v20 = (const char *)&unk_28C658;
        break;
      default:
        goto LABEL_65;
    }
  }
  else
  {
    switch ( v7 )
    {
      case 808665665:
        v20 = (const char *)&unk_28C660;
        break;
      case 808665688:
        v20 = (const char *)&unk_28C668;
        break;
      case 875708993:
        v20 = (const char *)&sde_format_get_media_color_ubwc_sde_media_ubwc_map;
        break;
      default:
        goto LABEL_65;
    }
  }
  v8 = *((_DWORD *)v20 + 1);
LABEL_65:
  if ( v8 < 0 )
  {
    _drm_err("UBWC format not supported for fmt: %4.4s\n", (const char *)a1);
    return 4294967274LL;
  }
LABEL_66:
  if ( (*(_QWORD *)(a1 + 32) & 1) == 0 )
  {
    *v6 = 1;
    if ( a2 && (v25 = v8 - 4, (unsigned int)(v8 - 4) <= 0xA) && ((0x70Fu >> v25) & 1) != 0 )
      v26 = (dword_28D6E8[v25] * a2 + 255) & 0x7FF00;
    else
      v26 = 0;
    *(_DWORD *)(a4 + 56) = v26;
    if ( a3 )
    {
      v28 = 0;
      if ( (unsigned int)v8 > 0xE )
        goto LABEL_86;
      if ( ((1 << v8) & 0x30E0) != 0 )
      {
        v29 = 16;
LABEL_82:
        v30 = a3;
LABEL_83:
        v28 = (v30 + v29 - 1) & -v29;
        goto LABEL_86;
      }
      if ( v8 == 4 )
      {
        v29 = 32;
        goto LABEL_82;
      }
      if ( v8 == 14 )
      {
        v30 = a3 >> 1;
        v29 = 16;
        goto LABEL_83;
      }
    }
    else
    {
      v28 = 0;
    }
LABEL_86:
    v18 = (v28 * v26 + 4095) & 0xFFFFF000;
    *(_DWORD *)(a4 + 40) = v18;
    if ( (v5 & 4) != 0 )
    {
      *v6 = 3;
      if ( a2 && (v34 = v8 - 5, (unsigned int)(v8 - 5) <= 9) && ((0x387u >> v34) & 1) != 0 )
      {
        v35 = dword_28D714[v34];
        v36 = ((unsigned __int16)(a2 + v35 - 1) / v35 + 63) & 0xFFC0;
      }
      else
      {
        v36 = 0;
      }
      *(_DWORD *)(a4 + 64) = v36;
      if ( a3 )
      {
        v37 = 0;
        if ( (unsigned int)v8 <= 0xE && ((1 << v8) & 0x70E0) != 0 )
          v37 = (((a3 + 3) >> 2) + 15) & 0x3FF0;
      }
      else
      {
        v37 = 0;
      }
      v31 = 0;
      v33 = 0;
      v32 = (v37 * v36 + 4095) & 0x3FFFF000;
      *(_DWORD *)(a4 + 48) = v32;
    }
    else
    {
      v31 = 0;
      v32 = 0;
      v33 = 0;
    }
    goto LABEL_193;
  }
  *v6 = 2;
  if ( !a2 )
  {
    v27 = 0;
    goto LABEL_111;
  }
  v27 = 0;
  if ( v8 <= 9 )
  {
    if ( (unsigned int)v8 < 3 )
    {
      v27 = ((_WORD)a2 + 127) & 0x7F80;
      goto LABEL_111;
    }
    if ( (unsigned int)(v8 - 8) >= 2 )
    {
      if ( v8 == 3 )
        v27 = (((1431655766 * (unsigned __int64)(4 * (a2 + 191 - (unsigned __int16)(a2 + 191) % 0xC0u))) >> 32) + 255)
            & 0x7FFFFF00;
      goto LABEL_111;
    }
LABEL_110:
    v27 = (2 * (_WORD)a2 + 255) & 0xFF00;
    goto LABEL_111;
  }
  if ( v8 > 15 )
  {
    if ( (unsigned int)(v8 - 16) >= 2 )
      goto LABEL_111;
    goto LABEL_110;
  }
  switch ( v8 )
  {
    case 10:
      v27 = (2 * (_WORD)a2 + 1023) & 0xFC00;
      break;
    case 11:
      v27 = ((_WORD)a2 + 511) & 0x7E00;
      break;
    case 15:
      v27 = ((_WORD)a2 + 255) & 0x7F00;
      break;
  }
LABEL_111:
  v38 = 0;
  *(_DWORD *)(a4 + 56) = v27;
  if ( a3 && (unsigned int)v8 <= 0x11 )
  {
    if ( ((0x38F0Fu >> v8) & 1) != 0 )
      v38 = (a3 + dword_28D6A0[v8] - 1) & -dword_28D6A0[v8];
    else
      v38 = 0;
  }
  v18 = (v38 * v27 + 4095) & 0xFFFFF000;
  *(_DWORD *)(a4 + 40) = v18;
  if ( !a2 )
  {
    v39 = 0;
    goto LABEL_131;
  }
  v39 = 0;
  if ( v8 <= 9 )
  {
    if ( (unsigned int)v8 < 3 )
    {
      v39 = ((_WORD)a2 + 127) & 0x7F80;
      goto LABEL_131;
    }
    if ( (unsigned int)(v8 - 8) >= 2 )
    {
      if ( v8 == 3 )
        v39 = (((1431655766 * (unsigned __int64)(4 * (a2 + 191 - (unsigned __int16)(a2 + 191) % 0xC0u))) >> 32) + 255)
            & 0x7FFFFF00;
      goto LABEL_131;
    }
LABEL_130:
    v39 = (2 * (_WORD)a2 + 255) & 0xFF00;
    goto LABEL_131;
  }
  if ( v8 > 15 )
  {
    if ( (unsigned int)(v8 - 16) >= 2 )
      goto LABEL_131;
    goto LABEL_130;
  }
  switch ( v8 )
  {
    case 10:
      v39 = (2 * (_WORD)a2 + 1023) & 0xFC00;
      break;
    case 11:
      v39 = ((_WORD)a2 + 511) & 0x7E00;
      break;
    case 15:
      v39 = ((_WORD)a2 + 255) & 0x7F00;
      break;
  }
LABEL_131:
  *(_DWORD *)(a4 + 60) = v39;
  if ( !a3 )
  {
    v40 = 0;
    goto LABEL_145;
  }
  v40 = 0;
  if ( (unsigned int)v8 > 0x11 )
    goto LABEL_145;
  if ( ((1 << v8) & 0x3830B) != 0 )
  {
    v41 = 16;
  }
  else
  {
    if ( ((1 << v8) & 0xC00) == 0 )
    {
      if ( v8 != 2 )
        goto LABEL_145;
      v41 = 32;
      goto LABEL_143;
    }
    v41 = 256;
  }
  if ( (v8 & 0x7FFFFFFE) != 0x10 )
  {
LABEL_143:
    v42 = v41 + ((a3 + 1) >> 1);
    goto LABEL_144;
  }
  v42 = a3 + v41;
LABEL_144:
  v40 = (v42 - 1) & -v41;
LABEL_145:
  v33 = (v40 * v39 + 4095) & 0xFFFFF000;
  *(_DWORD *)(a4 + 44) = v33;
  if ( (v5 & 4) != 0 )
  {
    *v6 = 4;
    v43 = 0;
    if ( !a2 )
      goto LABEL_162;
    v44 = 32;
    if ( v8 <= 7 )
    {
      if ( v8 != 2 )
      {
        if ( v8 != 3 )
          goto LABEL_162;
        v44 = 48;
      }
    }
    else if ( v8 != 8 )
    {
      if ( v8 == 15 )
      {
        v44 = 64;
      }
      else if ( v8 != 16 )
      {
LABEL_162:
        *(_DWORD *)(a4 + 64) = v43;
        if ( a3 )
        {
          v45 = 0;
          if ( (unsigned int)v8 > 0x10 )
            goto LABEL_168;
          if ( ((1 << v8) & 0x18108) != 0 )
          {
            v46 = 4;
LABEL_166:
            v45 = ((unsigned __int16)((unsigned __int16)(a3 + v46 - 1) / v46) + 15) & 0xFFF0;
            goto LABEL_168;
          }
          if ( v8 == 2 )
          {
            v46 = 8;
            goto LABEL_166;
          }
        }
        else
        {
          v45 = 0;
        }
LABEL_168:
        v47 = v45 * v43 + 4095;
        v48 = 0;
        v32 = v47 & 0x7FFFF000;
        *(_DWORD *)(a4 + 48) = v32;
        if ( !a2 )
          goto LABEL_181;
        v49 = 16;
        if ( v8 <= 7 )
        {
          if ( v8 != 2 )
          {
            if ( v8 != 3 )
              goto LABEL_181;
            v49 = 24;
          }
        }
        else if ( v8 != 8 )
        {
          if ( v8 == 15 )
          {
            v49 = 32;
          }
          else if ( v8 != 16 )
          {
LABEL_181:
            *(_DWORD *)(a4 + 68) = v48;
            if ( a3 )
            {
              v50 = 0;
              if ( (unsigned int)v8 <= 0x10 )
              {
                if ( ((1 << v8) & 0x18108) != 0 )
                {
                  if ( (v8 & 0x7FFFFFFE) == 0x10 )
                  {
                    LOWORD(v51) = a3 + 3;
                    v52 = 4;
LABEL_191:
                    v50 = ((unsigned __int16)v51 / v52 + 15) & 0xFFF0;
                    goto LABEL_192;
                  }
                  v52 = 4;
LABEL_190:
                  v51 = v52 + ((a3 + 1) >> 1) - 1;
                  goto LABEL_191;
                }
                if ( v8 == 2 )
                {
                  v52 = 8;
                  goto LABEL_190;
                }
              }
            }
            else
            {
              v50 = 0;
            }
LABEL_192:
            v31 = (v50 * v48 + 4095) & 0x7FFFF000;
            *(_DWORD *)(a4 + 52) = v31;
            goto LABEL_193;
          }
        }
        v48 = ((unsigned __int16)((unsigned __int16)(v49 + ((a2 + 1) >> 1) - 1) / v49) + 63) & 0xFFC0;
        goto LABEL_181;
      }
    }
    v43 = ((unsigned __int16)((unsigned __int16)(a2 + v44 - 1) / v44) + 63) & 0xFFC0;
    goto LABEL_162;
  }
  v31 = 0;
  v32 = 0;
LABEL_193:
  result = 0;
  v19 = v32 + v31 + v33;
LABEL_194:
  *(_DWORD *)(a4 + 20) = v19 + v18;
  return result;
}
