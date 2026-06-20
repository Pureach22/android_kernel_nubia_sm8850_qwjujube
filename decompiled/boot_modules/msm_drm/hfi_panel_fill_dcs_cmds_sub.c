__int64 __fastcall hfi_panel_fill_dcs_cmds_sub(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        int *a5,
        _BYTE *a6,
        __int64 a7)
{
  unsigned int v13; // w23
  _DWORD *v14; // x26
  __int64 v15; // x8
  __int64 v16; // x9
  int v17; // w0
  int v18; // w8
  int v19; // w9
  int v20; // w10
  __int64 v21; // x8
  __int64 result; // x0
  unsigned int v23; // w19
  int v24; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+8h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a3 + 8) )
  {
    v13 = 0;
    v14 = (_DWORD *)(a7 + 8);
    while ( 1 )
    {
      v15 = *(_QWORD *)(a4 + 16);
      v16 = (__int64)(int)v13 << 6;
      v24 = 0;
      *v14 = *(_DWORD *)(v15 + v16 + 44);
      v14[1] = *(_DWORD *)(*(_QWORD *)(a4 + 16) + v16 + 52);
      v14[2] = *(_DWORD *)(a4 + 4);
      v17 = dsi_hfi_packetize_panel_cmd(*(_QWORD *)(a4 + 16) + v16, &v24, a6);
      if ( v17 )
        break;
      v18 = v24;
      ++v13;
      *(v14 - 1) = v24;
      v19 = *a5;
      v20 = *(_DWORD *)(a1 + 1240);
      v21 = (v18 + 7) & 0xFFFFFFF8;
      a6 += v21;
      v24 = v21;
      *(v14 - 2) = v19 + v20;
      v14 += 7;
      *a5 += v21;
      *(_DWORD *)(a2 + 152) += 28;
      if ( v13 >= *(_DWORD *)(a3 + 8) )
        goto LABEL_5;
    }
    v23 = v17;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to packetize command %d, rc=%d\n", v13, v17);
    result = v23;
  }
  else
  {
LABEL_5:
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
