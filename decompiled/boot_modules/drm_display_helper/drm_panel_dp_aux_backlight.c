unsigned __int64 __fastcall drm_panel_dp_aux_backlight(__int64 *a1, const char **a2)
{
  unsigned __int64 result; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x21
  __int64 v8; // x0
  int v9; // w10
  __int64 v10; // x2
  unsigned __int8 v11[4]; // [xsp+4h] [xbp-2Ch] BYREF
  unsigned __int16 v12[2]; // [xsp+8h] [xbp-28h] BYREF
  _DWORD v13[2]; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v14; // [xsp+14h] [xbp-1Ch]
  __int64 v15; // [xsp+1Ch] [xbp-14h]
  __int16 v16; // [xsp+24h] [xbp-Ch] BYREF
  char v17; // [xsp+26h] [xbp-Ah]
  __int64 v18; // [xsp+28h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  v14 = 0;
  if ( a1 )
  {
    result = 4294967274LL;
    if ( a2 )
    {
      if ( *a1 )
      {
        v17 = 0;
        v16 = 0;
        result = drm_dp_dpcd_read(a2, 0x700u, (__int64)&v16, 3);
        if ( (result & 0x80000000) == 0 )
        {
          v5 = *a1;
          if ( (v16 & 0x100) != 0 )
          {
            v6 = devm_kmalloc(v5, 24, 3520);
            if ( v6 )
            {
              v7 = v6;
              *(_QWORD *)(v6 + 8) = a2;
              v12[0] = 0;
              v11[0] = 0;
              result = drm_edp_backlight_init(a2, v6 + 16, 0, (__int64)&v16, v12, v11);
              if ( (result & 0x80000000) == 0 )
              {
                v8 = *a1;
                v9 = *(unsigned __int16 *)(v7 + 18);
                v10 = *a1;
                HIDWORD(v14) = 1;
                v13[0] = v12[0];
                v13[1] = v9;
                result = devm_backlight_device_register(v8, "dp_aux_backlight", v10, v7, &dp_aux_bl_ops, v13);
                *(_QWORD *)v7 = result;
                if ( result < 0xFFFFFFFFFFFFF001LL )
                {
                  backlight_disable();
                  result = 0;
                  a1[1] = *(_QWORD *)v7;
                }
              }
            }
            else
            {
              result = 4294967284LL;
            }
          }
          else
          {
            drm_dev_printk(v5, &unk_1C2B4, "DP AUX backlight is not supported\n");
            result = 0;
          }
        }
      }
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
