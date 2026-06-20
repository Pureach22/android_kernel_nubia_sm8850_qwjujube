__int64 __fastcall cam_sync_util_send_v4l2_event(int a1, unsigned int a2, unsigned int a3, void *src, int a5, int a6)
{
  int v6; // w10
  int v8; // w8
  char *v9; // x8
  unsigned __int64 v10; // x1
  __int64 result; // x0
  __int64 v12; // [xsp+0h] [xbp-90h] BYREF
  unsigned __int64 v13; // [xsp+8h] [xbp-88h]
  _QWORD v14[10]; // [xsp+10h] [xbp-80h] BYREF
  __int64 v15; // [xsp+60h] [xbp-30h]
  __int64 v16; // [xsp+68h] [xbp-28h]
  __int64 v17; // [xsp+70h] [xbp-20h]
  __int64 v18; // [xsp+78h] [xbp-18h]
  __int64 v19; // [xsp+80h] [xbp-10h]
  __int64 v20; // [xsp+88h] [xbp-8h]

  v6 = 134217729;
  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  v8 = *(_DWORD *)(sync_dev + 8680);
  v15 = 0;
  v13 = 0;
  memset(v14, 0, sizeof(v14));
  v12 = 0;
  if ( v8 == 134217729 )
  {
    v9 = (char *)&v14[4] + 4;
    v10 = 84;
    LODWORD(v14[0]) = 134217729;
    HIDWORD(v14[0]) = a6;
  }
  else
  {
    v9 = (char *)v14;
    v6 = 0x8000000;
    v10 = 120;
  }
  LODWORD(v12) = v6;
  v13 = __PAIR64__(a3, a2);
  LODWORD(v15) = a1;
  if ( v10 < a5 )
    _fortify_panic(17, v10, a5);
  memcpy(v9, src, a5);
  result = v4l2_event_queue(*(_QWORD *)sync_dev, &v12);
  if ( (debug_mdl & 0x80) != 0 && !debug_priority )
    result = ((__int64 (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               (unsigned __int8)debug_mdl & 0x80,
               4,
               "cam_sync_util_send_v4l2_event",
               784,
               "send v4l2 event version %d for sync_obj :%d",
               *(_DWORD *)(sync_dev + 8680),
               a2);
  _ReadStatusReg(SP_EL0);
  return result;
}
