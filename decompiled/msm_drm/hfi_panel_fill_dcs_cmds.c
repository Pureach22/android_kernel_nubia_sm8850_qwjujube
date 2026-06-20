__int64 __fastcall hfi_panel_fill_dcs_cmds(__int64 a1, __int64 a2, __int64 a3, _BYTE *a4, __int64 a5)
{
  unsigned __int64 v8; // x24
  unsigned __int64 v9; // x27
  int v10; // w25
  __int64 v11; // x22
  _DWORD *v12; // x20
  int v13; // w8
  unsigned int v14; // w28
  _DWORD *v15; // x26
  __int64 v16; // x8
  __int64 v17; // x9
  int v18; // w0
  int v19; // w8
  int v20; // w9
  __int64 v21; // x8
  int v22; // w9
  __int64 v24; // [xsp+0h] [xbp-30h]
  _BYTE *v26; // [xsp+10h] [xbp-20h]
  __int64 v27; // [xsp+18h] [xbp-18h]
  int v28; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v29; // [xsp+28h] [xbp-8h]

  v8 = 0;
  v9 = 0;
  v10 = 0;
  v24 = a3 + 160;
  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  do
  {
    if ( (unsigned int)(v8 - 19) >= 2 )
    {
      v11 = a2 + 40 * v8;
      if ( *(_DWORD *)(v11 + 8) )
      {
        if ( v9 > 3 )
          __break(0x5512u);
        v26 = a4;
        v27 = a5;
        v12 = (_DWORD *)(v24 + 20 * v9);
        v12[3] = *(_DWORD *)(a3 + 152);
        *v12 = v10;
        v12[1] = v8;
        v13 = *(_DWORD *)(v11 + 8);
        v12[2] = v13;
        if ( v13 )
        {
          v14 = 0;
          v15 = (_DWORD *)(a5 + 8);
          while ( 1 )
          {
            v16 = *(_QWORD *)(v11 + 16);
            v17 = (__int64)(int)v14 << 6;
            v28 = 0;
            *v15 = *(_DWORD *)(v16 + v17 + 44);
            v15[1] = *(_DWORD *)(*(_QWORD *)(v11 + 16) + v17 + 52);
            v15[2] = *(_DWORD *)(v11 + 4);
            v18 = dsi_hfi_packetize_panel_cmd(*(_QWORD *)(v11 + 16) + v17, &v28, a4);
            if ( v18 )
              break;
            v19 = v28;
            ++v14;
            *(v15 - 1) = v28;
            v20 = *(_DWORD *)(a1 + 1240);
            v21 = (v19 + 7) & 0xFFFFFFF8;
            v28 = v21;
            a4 += v21;
            v22 = v10 + v20;
            v10 += v21;
            *(v15 - 2) = v22;
            v15 += 7;
            *(_DWORD *)(a3 + 152) += 28;
            if ( v14 >= v12[2] )
              goto LABEL_11;
          }
          drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to packetize command %d, rc=%d\n", v14, v18);
          drm_dev_printk(
            0,
            &unk_248D72,
            "*ERROR* [msm-dsi-error]: Failed to fill panel cmds into memory for cmd type %d",
            v8);
        }
LABEL_11:
        ++v9;
        a5 = v27 + 28LL * *(unsigned int *)(v11 + 8);
        a4 = &v26[v10];
      }
    }
    if ( v8 > 0x39 )
      break;
    ++v8;
  }
  while ( v9 != 4 );
  *(_DWORD *)(a3 + 156) = v9;
  _ReadStatusReg(SP_EL0);
  return 0;
}
