__int64 __fastcall sde_hdcp_1x_verify_r0(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x21
  __int64 v4; // x0
  int v5; // w8
  __int64 v6; // x21
  unsigned int v7; // w20
  void *v8; // x0
  int v9; // w24
  int v10; // w10
  int v11; // w9
  int v12; // w8
  int v13; // w27
  unsigned int v14; // w21
  __int16 *v15; // x22
  int v16; // w28
  __int64 v17; // x0
  __int64 v18; // x21
  __int64 v19; // x0
  __int64 v20; // x21
  __int64 result; // x0
  __int16 v22; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+8h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1 + 40) != 1 )
  {
    printk(&unk_21817B, "sde_hdcp_1x_verify_r0");
    result = 4294967274LL;
    goto LABEL_43;
  }
  v1 = *(_QWORD *)(a1 + 888);
  v3 = ktime_get(a1);
  v4 = readl(*(_QWORD *)(v1 + 8) + *(unsigned int *)(a1 + 1016));
  v5 = *(_DWORD *)(a1 + 1024);
  if ( (((unsigned __int64)(unsigned int)v4 >> v5) & 1) == 0 && *(_DWORD *)(a1 + 40) == 1 )
  {
    v6 = v3 + 2000000000;
    while ( ktime_get(v4) <= v6 )
    {
      usleep_range_state(5001, 20000, 2);
      __yield();
      v4 = readl(*(_QWORD *)(v1 + 8) + *(unsigned int *)(a1 + 1016));
      v5 = *(_DWORD *)(a1 + 1024);
      if ( (((unsigned __int64)(unsigned int)v4 >> v5) & 1) != 0 || *(_DWORD *)(a1 + 40) != 1 )
        goto LABEL_10;
    }
    LODWORD(v4) = readl(*(_QWORD *)(v1 + 8) + *(unsigned int *)(a1 + 1016));
    v5 = *(_DWORD *)(a1 + 1024);
  }
LABEL_10:
  if ( (((unsigned __int64)(unsigned int)v4 >> v5) & 1) != 0 || *(_DWORD *)(a1 + 40) != 1 )
  {
    if ( *(_DWORD *)(a1 + 1000) )
    {
      if ( (*(_BYTE *)(a1 + 32) & 1) == 0 )
      {
        *(_DWORD *)(a1 + 840) = 0;
        wait_for_completion_timeout(a1 + 840, 125);
        if ( (*(_BYTE *)(a1 + 33) & 1) != 0 )
        {
          v7 = -22;
          v8 = &unk_25CE76;
          goto LABEL_39;
        }
      }
    }
    else
    {
      msleep(100);
    }
    v9 = 3;
    while ( 1 )
    {
      v10 = *(_DWORD *)(a1 + 1000);
      v11 = 0;
      v12 = 0;
      v22 = 0;
      if ( v10 == 1 )
        break;
LABEL_26:
      v17 = dss_reg_w(v1, *(unsigned int *)(a1 + 1064), v11 | (unsigned int)(v12 << 8), 1);
      v18 = ktime_get(v17);
      v19 = readl(*(_QWORD *)(v1 + 8) + *(unsigned int *)(a1 + 1016));
      if ( (v19 & 0x1000) == 0 )
      {
        v20 = v18 + 10000;
        if ( *(_DWORD *)(a1 + 40) == 1 )
        {
          while ( ktime_get(v19) <= v20 )
          {
            usleep_range_state(1, 1, 2);
            __yield();
            v19 = readl(*(_QWORD *)(v1 + 8) + *(unsigned int *)(a1 + 1016));
            if ( (v19 & 0x1000) != 0 || *(_DWORD *)(a1 + 40) != 1 )
              goto LABEL_33;
          }
          LOWORD(v19) = readl(*(_QWORD *)(v1 + 8) + *(unsigned int *)(a1 + 1016));
        }
      }
LABEL_33:
      if ( (v19 & 0x1000) != 0 || *(_DWORD *)(a1 + 40) != 1 )
      {
        v7 = 0;
        goto LABEL_40;
      }
      if ( !--v9 )
      {
        v7 = -110;
        goto LABEL_40;
      }
    }
    v13 = *(_DWORD *)(a1 + 1252);
    v14 = *(_DWORD *)(a1 + 1248);
    v15 = &v22;
    while ( 1 )
    {
      v16 = v13 >= 15 ? 15 : v13;
      if ( v16 != (unsigned int)drm_dp_dpcd_read(*(_QWORD *)(a1 + 936), v14, v15, v16) )
        break;
      v13 -= v16;
      v15 = (__int16 *)((char *)v15 + v16);
      v14 += v16;
      if ( v13 <= 0 )
      {
        v12 = HIBYTE(v22);
        v11 = (unsigned __int8)v22;
        goto LABEL_26;
      }
    }
    printk(&unk_26ECF1, "sde_hdcp_1x_read");
    v7 = -5;
    v8 = &unk_26B207;
    goto LABEL_39;
  }
  v7 = -110;
  v8 = &unk_23A6E8;
LABEL_39:
  printk(v8, "sde_hdcp_1x_verify_r0");
LABEL_40:
  if ( *(_DWORD *)(a1 + 40) == 1 )
    result = v7;
  else
    result = 4294967274LL;
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return result;
}
