__int64 __fastcall simple_amp_hw_params(__int64 a1, _DWORD *a2, __int64 a3)
{
  __int64 v3; // x24
  __int64 v4; // x0
  _QWORD *v5; // x20
  int v6; // w3
  char *v8; // x22
  int v9; // w2
  int v10; // w23
  __int64 v11; // x8
  _DWORD *v12; // x26
  int v14; // w8
  __int64 v15; // x0
  __int64 v16; // x1
  __int64 result; // x0
  unsigned int v18; // w0
  char v19; // w20
  unsigned int v20; // w8
  int v21; // w9
  __int64 v22; // x0
  int v23; // w24
  int v24; // w21
  int v25; // w0
  __int64 v26; // x2
  __int64 v27; // x3
  int v28; // w8
  __int64 v29; // x0
  __int64 v30; // x2
  char v31; // w8
  __int64 v32; // x1
  void *v33; // x0
  unsigned int v34; // w19
  char v35[4]; // [xsp+0h] [xbp-10h] BYREF
  char v36[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v37; // [xsp+8h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a3 + 96);
  v35[0] = 2;
  v4 = *(_QWORD *)(v3 + 24);
  v5 = *(_QWORD **)(v4 + 152);
  if ( !v5 || !v5[2] )
    goto LABEL_18;
  v6 = *(_DWORD *)(a3 + 8);
  if ( (unsigned int)(v6 - 1) >= 3 )
  {
    dev_err(v4, "%s: Invalid Dai ID: %d\n", "simple_amp_hw_params", v6);
    result = 4294967274LL;
    goto LABEL_45;
  }
  v8 = (char *)*(&off_B9B8 + (unsigned int)(v6 - 1)) + (_QWORD)v5;
  *((_QWORD *)v8 + 6) = 0;
  *((_QWORD *)v8 + 7) = 0;
  *((_QWORD *)v8 + 4) = 0;
  *((_QWORD *)v8 + 5) = 0;
  *((_QWORD *)v8 + 2) = 0;
  *((_QWORD *)v8 + 3) = 0;
  *(_QWORD *)v8 = 0;
  *((_QWORD *)v8 + 1) = 0;
  v9 = a2[74];
  v10 = a2[71];
  if ( v9 <= 47999 )
  {
    if ( v9 == 8000 || v9 == 16000 || v9 == 44100 )
      goto LABEL_12;
LABEL_52:
    dev_err(*(_QWORD *)(v3 + 24), "Rate %d is not supported\n", v9);
    result = 4294967274LL;
    goto LABEL_45;
  }
  if ( v9 != 48000 && v9 != 96000 && v9 != 192000 )
    goto LABEL_52;
LABEL_12:
  v11 = *(unsigned int *)(a3 + 8);
  if ( (unsigned int)v11 < 4 )
  {
    v12 = (_DWORD *)v5[v11 + 6];
    if ( v12 )
    {
      regmap_write(*v5, (v12[24] << 15) & 0x200000 | ((_DWORD)v11 << 22) | ((v12[24] & 0x3F) << 7) | 0x40080000u);
      regmap_write(
        *v5,
        (v12[108] << 15) & 0x200000 | ((*(_DWORD *)(a3 + 8) & 7) << 22) | ((v12[108] & 0x3F) << 7) | 0x40080000u);
      regmap_write(
        *v5,
        ((v12[84] << 15) & 0x200000 | ((*(_DWORD *)(a3 + 8) & 7) << 22) | ((v12[84] & 0x3F) << 7) | 0x40000008u) + 24);
      regmap_write(
        *v5,
        (v12[12] << 15) & 0x200000 | ((*(_DWORD *)(a3 + 8) & 7) << 22) | ((v12[12] & 0x3F) << 7) | 0x40080000u);
      v14 = *(_DWORD *)(a3 + 8);
      switch ( v14 )
      {
        case 3:
          regmap_write(*v5, 1086341649);
          v15 = *v5;
          v16 = 1086349841;
          break;
        case 2:
          regmap_write(*v5, 1082147345);
          v15 = *v5;
          v16 = 1082155537;
          break;
        case 1:
          regmap_write(*v5, 1077961233);
          regmap_write(*v5, 1077953041);
          regmap_write(*v5, 1077961234);
          v15 = *v5;
          v16 = 1077953042;
          break;
        default:
          goto LABEL_22;
      }
      regmap_write(v15, v16);
LABEL_22:
      swr_write(v5[2], *(unsigned __int8 *)(v5[2] + 64LL), 76, v35);
      regmap_write(
        *v5,
        (v12[72] << 15) & 0x200000 | ((*(_DWORD *)(a3 + 8) & 7) << 22) | ((v12[72] & 0x3F) << 7) | 0x40000008u);
      v18 = wait_for_pde_state(v5, (unsigned int)v12[72], (unsigned int)v12[24], 0, *(unsigned int *)(a3 + 8));
      if ( v18 )
      {
        v34 = v18;
        dev_err(*(_QWORD *)(v3 + 24), "PS0 request failed\n");
        result = v34;
        goto LABEL_45;
      }
      *((_QWORD *)v8 + 7) = v5[2];
      if ( v10 == 1 )
      {
        if ( *((_DWORD *)v5 + 42) == 1 )
          v19 = 1;
        else
          v19 = 2;
        v20 = a2[9];
        if ( v20 )
          goto LABEL_28;
      }
      else
      {
        v19 = 2;
        v20 = a2[9];
        if ( v20 )
        {
LABEL_28:
          v21 = 0;
          goto LABEL_32;
        }
      }
      v20 = a2[10];
      if ( !v20 )
      {
        v22 = 0;
        goto LABEL_33;
      }
      v21 = 32;
LABEL_32:
      v22 = __clz(__rbit32(v20)) | v21;
LABEL_33:
      v23 = *(_DWORD *)(a3 + 8);
      v24 = a2[74];
      v25 = snd_pcm_format_width(v22);
      if ( v8 )
      {
        v28 = v25;
        v29 = *((_QWORD *)v8 + 7);
        if ( v29 )
        {
          switch ( v23 )
          {
            case 3:
              *((_WORD *)v8 + 2) = 769;
              v30 = 517;
              *((_WORD *)v8 + 6) = 3337;
              *((_WORD *)v8 + 4) = 769;
              v31 = 1;
              v8[16] = v10;
              v8[17] = 2;
              *(_QWORD *)(v8 + 36) = 0xBB800000BB80LL;
              *(_DWORD *)v8 = 2;
              break;
            case 2:
              v8[16] = v10;
              *((_WORD *)v8 + 2) = 512;
              v30 = 261;
              *((_WORD *)v8 + 6) = 3081;
              v8[17] = 2;
              *((_DWORD *)v8 + 9) = v24;
              *((_DWORD *)v8 + 10) = v24;
              *((_WORD *)v8 + 4) = 769;
              *(_DWORD *)v8 = 2;
              v31 = 1;
              break;
            case 1:
              *((_DWORD *)v8 + 5) = v28;
              v8[6] = 2;
              *((_WORD *)v8 + 2) = 512;
              v30 = 261;
              *((_WORD *)v8 + 6) = 3081;
              v8[14] = 13;
              *((_WORD *)v8 + 8) = 514;
              v8[18] = 2;
              *((_WORD *)v8 + 4) = 771;
              *((_QWORD *)v8 + 3) = 0x2000000020LL;
              *((_DWORD *)v8 + 9) = v24;
              *((_DWORD *)v8 + 10) = v24;
              *((_DWORD *)v8 + 11) = v24;
              v8[10] = 12;
              *(_DWORD *)v8 = 3;
              if ( v10 == 2 )
                v31 = 3;
              else
                v31 = v19;
              break;
            default:
              v33 = &unk_CAD1;
LABEL_48:
              printk(v33, "simple_amp_get_port_param", v26, v27);
              goto LABEL_44;
          }
          v32 = *(unsigned __int8 *)(v29 + 64);
          v36[0] = v31;
          swr_write(v29, v32, v30, v36);
          usleep_range_state(2000, 2010, 2);
LABEL_44:
          result = 0;
          *(_QWORD *)(a3 + 48) = v8;
          goto LABEL_45;
        }
      }
      v33 = &unk_D00C;
      goto LABEL_48;
    }
LABEL_18:
    result = 4294967274LL;
LABEL_45:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  return simple_amp_hw_free();
}
