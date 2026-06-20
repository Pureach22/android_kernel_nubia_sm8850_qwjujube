__int64 __fastcall sde_kms_inform_cont_splash_res_disable(__int64 a1, __int64 a2)
{
  __int64 v3; // x20
  __int64 v4; // x21
  __int64 v5; // x0
  bool v6; // zf
  char v7; // w19
  __int64 v8; // x0
  __int64 v9; // x8
  void (__fastcall *v10)(_QWORD); // x9
  __int64 v11; // x0
  __int64 result; // x0
  _QWORD v13[2]; // [xsp+8h] [xbp-B8h] BYREF
  __int64 v14; // [xsp+18h] [xbp-A8h] BYREF
  __int64 v15; // [xsp+20h] [xbp-A0h]
  __int64 v16; // [xsp+28h] [xbp-98h]
  __int64 v17; // [xsp+30h] [xbp-90h]
  __int64 v18; // [xsp+38h] [xbp-88h]
  __int64 v19; // [xsp+40h] [xbp-80h]
  __int64 v20; // [xsp+48h] [xbp-78h]
  __int64 v21; // [xsp+50h] [xbp-70h]
  __int64 v22; // [xsp+58h] [xbp-68h]
  __int64 v23; // [xsp+60h] [xbp-60h]
  __int64 v24; // [xsp+68h] [xbp-58h]
  __int64 v25; // [xsp+70h] [xbp-50h]
  __int64 v26; // [xsp+78h] [xbp-48h]
  __int64 v27; // [xsp+80h] [xbp-40h]
  __int64 v28; // [xsp+88h] [xbp-38h]
  __int64 v29; // [xsp+90h] [xbp-30h]
  __int64 v30; // [xsp+98h] [xbp-28h]
  __int64 v31; // [xsp+A0h] [xbp-20h]
  __int64 v32; // [xsp+A8h] [xbp-18h]
  __int64 v33; // [xsp+B0h] [xbp-10h]
  __int64 v34; // [xsp+B8h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 136);
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
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  v13[0] = 0;
  v13[1] = 0;
  if ( !a2 )
    goto LABEL_7;
  v4 = *(_QWORD *)(*(_QWORD *)(a2 + 1296) + 112LL);
  if ( v4 && (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "encoder name = %s\n", *(const char **)(v4 + 56));
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
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, __int64 *, __int64))dsi_display_get_info)(0, &v14, a2) )
  {
    printk(&unk_22B1BE, "sde_kms_inform_cont_splash_res_disable");
LABEL_7:
    v4 = 0;
  }
  drm_connector_list_iter_begin(v3, v13);
  v5 = drm_connector_list_iter_next(v13);
  if ( v5 )
  {
    if ( a2 )
      v6 = v4 == 0;
    else
      v6 = 1;
    v7 = !v6;
    do
    {
      v9 = *(_QWORD *)v5 + 816LL;
      do
        v9 = *(_QWORD *)v9;
      while ( v9 != *(_QWORD *)v5 + 816LL && ((*(_DWORD *)(v5 + 2264) >> *(_DWORD *)(v9 + 60)) & 1) == 0 );
      if ( v9 == 8 )
      {
        result = printk(&unk_24CD2C, "sde_kms_inform_cont_splash_res_disable");
        goto LABEL_30;
      }
      v10 = *(void (__fastcall **)(_QWORD))(v5 + 3128);
      if ( v10 )
      {
        if ( (v7 & 1) != 0 )
        {
          if ( *(_DWORD *)(v9 + 16) == *(_DWORD *)(v4 + 24) )
          {
            v11 = *(_QWORD *)(v5 + 2760);
            if ( *((_DWORD *)v10 - 1) != -1066802076 )
              __break(0x8229u);
            v10(v11);
            break;
          }
        }
        else
        {
          v8 = *(_QWORD *)(v5 + 2760);
          if ( *((_DWORD *)v10 - 1) != -1066802076 )
            __break(0x8229u);
          v10(v8);
        }
      }
      v5 = drm_connector_list_iter_next(v13);
    }
    while ( v5 );
  }
  result = drm_connector_list_iter_end(v13);
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
