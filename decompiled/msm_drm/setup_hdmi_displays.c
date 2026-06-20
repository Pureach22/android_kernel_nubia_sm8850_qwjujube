__int64 __fastcall setup_hdmi_displays(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v8; // x23
  __int64 v9; // x26
  __int64 v10; // x24
  __int64 v11; // x25
  __int64 v12; // x0
  unsigned __int64 v13; // x0
  __int64 v14; // x28
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x8
  _QWORD v19[4]; // [xsp+0h] [xbp-D0h] BYREF
  __int64 v20; // [xsp+20h] [xbp-B0h] BYREF
  __int64 v21; // [xsp+28h] [xbp-A8h]
  __int64 v22; // [xsp+30h] [xbp-A0h]
  __int64 v23; // [xsp+38h] [xbp-98h]
  __int64 v24; // [xsp+40h] [xbp-90h]
  __int64 v25; // [xsp+48h] [xbp-88h]
  __int64 v26; // [xsp+50h] [xbp-80h]
  __int64 v27; // [xsp+58h] [xbp-78h]
  __int64 v28; // [xsp+60h] [xbp-70h]
  __int64 v29; // [xsp+68h] [xbp-68h]
  __int64 v30; // [xsp+70h] [xbp-60h]
  __int64 v31; // [xsp+78h] [xbp-58h]
  __int64 v32; // [xsp+80h] [xbp-50h]
  __int64 v33; // [xsp+88h] [xbp-48h]
  __int64 v34; // [xsp+90h] [xbp-40h]
  __int64 v35; // [xsp+98h] [xbp-38h]
  __int64 v36; // [xsp+A0h] [xbp-30h]
  __int64 v37; // [xsp+A8h] [xbp-28h]
  __int64 v38; // [xsp+B0h] [xbp-20h]
  __int64 v39; // [xsp+B8h] [xbp-18h]
  __int64 v40; // [xsp+C0h] [xbp-10h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(int *)(a3 + 3648) >= 1 )
  {
    v8 = 0;
    v9 = a2 + 3800;
    v10 = a2 + 4072;
    v38 = 0;
    v39 = 0;
    v36 = 0;
    v37 = 0;
    v34 = 0;
    v35 = 0;
    v32 = 0;
    v33 = 0;
    v30 = 0;
    v31 = 0;
    v28 = 0;
    v29 = 0;
    v26 = 0;
    v27 = 0;
    v24 = 0;
    v25 = 0;
    v22 = 0;
    v23 = 0;
    v20 = 0;
    v21 = 0;
    memset(v19, 0, sizeof(v19));
    do
    {
      if ( *(_DWORD *)(a2 + 3792) >= a4 )
        break;
      v11 = *(_QWORD *)(*(_QWORD *)(a3 + 3640) + 8 * v8);
      v20 = 0;
      v21 = 0;
      v22 = 0;
      v23 = 0;
      v24 = 0;
      v25 = 0;
      v26 = 0;
      v27 = 0;
      v28 = 0;
      v29 = 0;
      v30 = 0;
      v31 = 0;
      v32 = 0;
      v33 = 0;
      v34 = 0;
      v35 = 0;
      v36 = 0;
      v37 = 0;
      v38 = 0;
      v39 = 0;
      snprintf((char *)v19, 0x20u, "hdmi%u", v8);
      v12 = ((__int64 (__fastcall *)(_QWORD, _QWORD *))sde_cesta_create_client)(**(unsigned int **)(a1 + 64), v19);
      v13 = sde_encoder_init(a1, (__int64)&v20, v12);
      if ( !v13 )
        goto LABEL_12;
      v14 = v13;
      if ( v13 < 0xFFFFFFFFFFFFF001LL )
      {
        v15 = sde_connector_init(a1, v13, 0, v11, setup_hdmi_displays_hdmi_ops, 0, 11, 0);
        if ( v15 )
        {
          v16 = *(unsigned int *)(a2 + 3792);
          *(_DWORD *)(a2 + 3792) = v16 + 1;
          if ( (unsigned int)v16 >= 0x10
            || (*(_QWORD *)(v9 + 8 * v16) = v14,
                v17 = *(unsigned int *)(a2 + 4064),
                *(_DWORD *)(a2 + 4064) = v17 + 1,
                (unsigned int)v17 > 0xF) )
          {
            __break(0x5512u);
          }
          *(_QWORD *)(v10 + 8 * v17) = v15;
        }
        else
        {
          printk(&unk_21DB6F, "setup_hdmi_displays");
          sde_encoder_destroy(v14);
        }
      }
      else
      {
LABEL_12:
        printk(&unk_262570, "setup_hdmi_displays");
      }
      ++v8;
    }
    while ( v8 < *(int *)(a3 + 3648) );
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
