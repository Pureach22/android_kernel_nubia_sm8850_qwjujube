__int64 __fastcall cam_isp_blob_csid_discard_init_frame_update(__int64 a1, unsigned int *a2, __int64 a3)
{
  __int64 v3; // x23
  unsigned int v4; // w8
  _QWORD *v5; // x25
  unsigned int v7; // w22
  __int64 v8; // x0
  __int64 v9; // x26
  __int64 v10; // x9
  __int64 (__fastcall *v11)(__int64, __int64, __int64 *, __int64); // x8
  __int64 v12; // x9
  __int64 (__fastcall *v13)(__int64, __int64, __int64 *, __int64); // x8
  __int64 v14; // x0
  __int64 v16; // [xsp+8h] [xbp-18h] BYREF
  __int64 v17; // [xsp+10h] [xbp-10h]
  __int64 v18; // [xsp+18h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a3 + 16);
  v4 = *a2;
  v17 = 0;
  v16 = v4;
  v5 = *(_QWORD **)(v3 + 208);
  if ( v5 == (_QWORD *)(v3 + 208) )
  {
    v7 = -22;
  }
  else
  {
    v7 = -22;
    do
    {
      v9 = v5[4];
      if ( v9 )
      {
        v10 = *(_QWORD *)(v9 + 16);
        if ( v10 )
        {
          v11 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v10 + 88);
          if ( v11 )
          {
            if ( *(_DWORD *)(v10 + 4) == **(_DWORD **)(a1 + 8) )
            {
              v8 = *(_QWORD *)(v10 + 112);
              v17 = v5[4];
              if ( *((_DWORD *)v11 - 1) != -1055839300 )
                __break(0x8228u);
              v7 = v11(v8, 55, &v16, 16);
              if ( v7 )
                goto LABEL_6;
            }
          }
        }
      }
      v9 = v5[5];
      if ( v9 )
      {
        v12 = *(_QWORD *)(v9 + 16);
        if ( v12 )
        {
          v13 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v12 + 88);
          if ( v13 )
          {
            if ( *(_DWORD *)(v12 + 4) == **(_DWORD **)(a1 + 8) )
            {
              v14 = *(_QWORD *)(v12 + 112);
              v17 = v5[5];
              if ( *((_DWORD *)v13 - 1) != -1055839300 )
                __break(0x8228u);
              v7 = v13(v14, 55, &v16, 16);
              if ( v7 )
LABEL_6:
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  8,
                  1,
                  "cam_isp_blob_csid_discard_init_frame_update",
                  10751,
                  "Failed to update discard frame cfg for res: %s on CSID[%u] ctx:%u",
                  (const char *)(v9 + 128),
                  **(_DWORD **)(a1 + 8),
                  *(_DWORD *)(v3 + 56));
            }
          }
        }
      }
      v5 = (_QWORD *)*v5;
    }
    while ( v5 != (_QWORD *)(v3 + 208) );
  }
  _ReadStatusReg(SP_EL0);
  return v7;
}
