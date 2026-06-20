__int64 __fastcall dsi_hfi_packetize_panel_cmd(__int64 a1, _DWORD *a2, _BYTE *a3)
{
  unsigned int v5; // w0
  unsigned int v6; // w21
  unsigned __int64 v7; // x9
  __int64 v8; // x8
  char v9; // w10
  char v10; // w9
  int v11; // w11
  int v12; // w9
  __int64 v14; // x11
  __int64 v15; // x10
  char v16; // w14
  unsigned __int64 v17; // [xsp+8h] [xbp-28h] BYREF
  __int64 v18; // [xsp+10h] [xbp-20h]
  __int64 v19; // [xsp+18h] [xbp-18h]
  __int64 v20; // [xsp+20h] [xbp-10h]
  __int64 v21; // [xsp+28h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  v5 = mipi_dsi_create_packet(&v17, a1);
  if ( v5 )
  {
    v6 = v5;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to create message packet, rc=%d\n", v5);
    goto LABEL_22;
  }
  if ( !a3 )
  {
    v6 = -12;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to copy message, rc=%d\n", 4294967284LL);
    goto LABEL_22;
  }
  v7 = v17;
  v8 = ((_DWORD)v17 + 3) & 0xFFFFFFFC;
  if ( (_DWORD)v8 )
  {
    if ( v17 )
    {
      *a3 = v18;
      if ( v7 != 1 )
      {
        a3[1] = BYTE1(v18);
        if ( v7 > 2 )
        {
          a3[2] = BYTE2(v18);
          if ( v7 == 3 )
            v9 = -1;
          else
            v9 = BYTE3(v18);
LABEL_14:
          a3[3] = v9;
          if ( (_DWORD)v8 != 4 )
          {
            v14 = v20;
            v15 = 0;
            do
            {
              if ( v7 > v15 + 4 )
                v16 = *(_BYTE *)(v14 + v15);
              else
                v16 = -1;
              a3[v15++ + 4] = v16;
            }
            while ( v8 - 4 != v15 );
          }
          goto LABEL_15;
        }
LABEL_13:
        v9 = -1;
        a3[2] = -1;
        goto LABEL_14;
      }
    }
    else
    {
      *a3 = -1;
    }
    a3[1] = -1;
    goto LABEL_13;
  }
LABEL_15:
  if ( v19 )
    a3[3] |= 0x40u;
  v10 = v18;
  v11 = v18 & 0x3D;
  *(_WORD *)a3 = *(_WORD *)((char *)&v18 + 1);
  a3[2] = v10;
  if ( v11 == 4 || (v12 = v10 & 0x3F, v12 == 36) || v12 == 20 )
    a3[3] |= 0x20u;
  v6 = 0;
  *a2 = v8;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return v6;
}
