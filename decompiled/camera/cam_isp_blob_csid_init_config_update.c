__int64 __fastcall cam_isp_blob_csid_init_config_update(__int64 a1, __int64 a2)
{
  __int64 v2; // x23
  __int64 *v3; // x25
  unsigned int v4; // w22
  __int64 v5; // x9
  __int64 v6; // x28
  _DWORD *v7; // x8
  __int64 v8; // x0
  __int64 v9; // x9
  __int64 v10; // x28
  _DWORD *v11; // x8
  __int64 v12; // x0
  _QWORD v14[3]; // [xsp+8h] [xbp-18h] BYREF

  v14[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 16);
  v14[1] = a2;
  v3 = *(__int64 **)(v2 + 208);
  if ( v3 == (__int64 *)(v2 + 208) )
  {
    v4 = -22;
  }
  else
  {
    v4 = -22;
    v14[0] = 0;
    do
    {
      v5 = v3[4];
      if ( v5 )
      {
        v6 = *(_QWORD *)(v5 + 16);
        if ( v6 )
        {
          v7 = *(_DWORD **)(v6 + 88);
          if ( v7 )
          {
            v14[0] = v3[4];
            if ( (debug_mdl & 8) != 0 && !debug_priority )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 8,
                4,
                "cam_isp_blob_csid_init_config_update",
                12401,
                "Init config update for res_id: %u, ctx_idx: %u",
                *((_DWORD *)v3 + 5),
                *(_DWORD *)(v2 + 56));
              v7 = *(_DWORD **)(v6 + 88);
            }
            v8 = *(_QWORD *)(v6 + 112);
            if ( *(v7 - 1) != -1055839300 )
              __break(0x8228u);
            v4 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v7)(v8, 67, v14, 16);
            if ( v4 )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                8,
                1,
                "cam_isp_blob_csid_init_config_update",
                12412,
                "Init cfg update failed rc: %d, ctx_idx: %u",
                v4,
                *(_DWORD *)(v2 + 56));
          }
        }
      }
      v9 = v3[5];
      if ( v9 )
      {
        v10 = *(_QWORD *)(v9 + 16);
        if ( v10 )
        {
          v11 = *(_DWORD **)(v10 + 88);
          if ( v11 )
          {
            v14[0] = v3[5];
            if ( (debug_mdl & 8) != 0 && !debug_priority )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 8,
                4,
                "cam_isp_blob_csid_init_config_update",
                12401,
                "Init config update for res_id: %u, ctx_idx: %u",
                *((_DWORD *)v3 + 5),
                *(_DWORD *)(v2 + 56));
              v11 = *(_DWORD **)(v10 + 88);
            }
            v12 = *(_QWORD *)(v10 + 112);
            if ( *(v11 - 1) != -1055839300 )
              __break(0x8228u);
            v4 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v11)(v12, 67, v14, 16);
            if ( v4 )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                8,
                1,
                "cam_isp_blob_csid_init_config_update",
                12412,
                "Init cfg update failed rc: %d, ctx_idx: %u",
                v4,
                *(_DWORD *)(v2 + 56));
          }
        }
      }
      v3 = (__int64 *)*v3;
    }
    while ( v3 != (__int64 *)(v2 + 208) );
  }
  _ReadStatusReg(SP_EL0);
  return v4;
}
