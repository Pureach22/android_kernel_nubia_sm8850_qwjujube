__int64 __fastcall cam_hw_mgr_reset_out_of_sync_cnt(__int64 result)
{
  _QWORD *v1; // x19
  _QWORD *v2; // x22
  __int64 v3; // x9
  __int64 v4; // x10
  _DWORD *v5; // x8
  __int64 v6; // x0
  __int64 v7; // x9
  __int64 v8; // x10
  _DWORD *v9; // x8
  __int64 v10; // x0
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = (_QWORD *)(result + 208);
  v2 = *(_QWORD **)(result + 208);
  if ( v2 != (_QWORD *)(result + 208) )
  {
    v11[0] = 0;
    do
    {
      v3 = v2[4];
      if ( v3 )
      {
        v4 = *(_QWORD *)(v3 + 16);
        v5 = *(_DWORD **)(v4 + 88);
        if ( v5 )
        {
          v6 = *(_QWORD *)(v4 + 112);
          v11[0] = v2[4];
          if ( *(v5 - 1) != -1055839300 )
            __break(0x8228u);
          result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v5)(v6, 53, v11, 8);
          if ( (_DWORD)result )
            result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       8,
                       1,
                       "cam_hw_mgr_reset_out_of_sync_cnt",
                       16395,
                       "Failed to reset out of sync cnt");
        }
      }
      v7 = v2[5];
      if ( v7 )
      {
        v8 = *(_QWORD *)(v7 + 16);
        v9 = *(_DWORD **)(v8 + 88);
        if ( v9 )
        {
          v10 = *(_QWORD *)(v8 + 112);
          v11[0] = v2[5];
          if ( *(v9 - 1) != -1055839300 )
            __break(0x8228u);
          result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v9)(v10, 53, v11, 8);
          if ( (_DWORD)result )
            result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       8,
                       1,
                       "cam_hw_mgr_reset_out_of_sync_cnt",
                       16395,
                       "Failed to reset out of sync cnt");
        }
      }
      v2 = (_QWORD *)*v2;
    }
    while ( v2 != v1 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
