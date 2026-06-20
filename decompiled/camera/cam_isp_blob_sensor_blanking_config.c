__int64 __fastcall cam_isp_blob_sensor_blanking_config(_DWORD *a1, __int64 a2)
{
  __int64 v2; // x23
  _QWORD *v3; // x25
  unsigned int v5; // w22
  __int64 v6; // x9
  __int64 v7; // x8
  int v8; // w10
  __int64 (__fastcall *v9)(__int64, __int64, __int64 *, __int64); // x9
  __int64 v10; // x0
  __int64 v11; // x9
  __int64 v12; // x8
  int v13; // w10
  __int64 (__fastcall *v14)(__int64, __int64, __int64 *, __int64); // x9
  __int64 v15; // x0
  __int64 v17; // [xsp+8h] [xbp-18h] BYREF
  __int64 v18; // [xsp+10h] [xbp-10h]
  __int64 v19; // [xsp+18h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a2 + 16);
  v17 = 0;
  v18 = 0;
  v3 = *(_QWORD **)(v2 + 224);
  if ( v3 == (_QWORD *)(v2 + 224) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_blob_sensor_blanking_config",
      11743,
      "Mux List empty, ctx_idx: %u",
      *(_DWORD *)(v2 + 56));
    v5 = -19;
  }
  else
  {
    v5 = 0;
    do
    {
      v6 = v3[4];
      if ( v6 )
      {
        v7 = *(_QWORD *)(v6 + 16);
        v18 = v3[4];
        v8 = a1[1];
        LODWORD(v17) = *a1;
        HIDWORD(v17) = v8;
        if ( v7 )
        {
          v9 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v7 + 88);
          if ( v9 )
          {
            v10 = *(_QWORD *)(v7 + 112);
            if ( *((_DWORD *)v9 - 1) != -1055839300 )
              __break(0x8229u);
            v5 = v9(v10, 39, &v17, 16);
            if ( v5 )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                8,
                1,
                "cam_isp_blob_sensor_blanking_config",
                11767,
                "blanking update failed, ctx_idx: %u",
                *(_DWORD *)(v2 + 56));
          }
        }
      }
      v11 = v3[5];
      if ( v11 )
      {
        v12 = *(_QWORD *)(v11 + 16);
        v18 = v3[5];
        v13 = a1[1];
        LODWORD(v17) = *a1;
        HIDWORD(v17) = v13;
        if ( v12 )
        {
          v14 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v12 + 88);
          if ( v14 )
          {
            v15 = *(_QWORD *)(v12 + 112);
            if ( *((_DWORD *)v14 - 1) != -1055839300 )
              __break(0x8229u);
            v5 = v14(v15, 39, &v17, 16);
            if ( v5 )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                8,
                1,
                "cam_isp_blob_sensor_blanking_config",
                11767,
                "blanking update failed, ctx_idx: %u",
                *(_DWORD *)(v2 + 56));
          }
        }
      }
      v3 = (_QWORD *)*v3;
    }
    while ( v3 != (_QWORD *)(v2 + 224) );
  }
  _ReadStatusReg(SP_EL0);
  return v5;
}
