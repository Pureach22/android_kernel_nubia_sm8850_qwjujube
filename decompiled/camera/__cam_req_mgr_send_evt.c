__int64 __fastcall _cam_req_mgr_send_evt(__int64 a1, int a2, int a3, _DWORD *a4)
{
  _DWORD *v8; // x23
  int v9; // w8
  __int64 v10; // x24
  __int64 v11; // x25
  __int64 v12; // x26
  unsigned int v13; // w10
  unsigned int v14; // w9
  int v15; // w9
  __int64 v16; // x9
  __int64 (__fastcall *v17)(_QWORD); // x9
  unsigned int v18; // w0
  unsigned int v19; // w20
  __int64 result; // x0
  __int64 v21; // [xsp+8h] [xbp-48h]
  unsigned __int64 v22; // [xsp+10h] [xbp-40h] BYREF
  __int64 v23; // [xsp+18h] [xbp-38h]
  __int64 v24; // [xsp+20h] [xbp-30h]
  __int64 v25; // [xsp+28h] [xbp-28h]
  __int64 v26; // [xsp+30h] [xbp-20h]
  __int64 v27; // [xsp+38h] [xbp-18h]
  __int64 v28; // [xsp+40h] [xbp-10h]
  __int64 v29; // [xsp+48h] [xbp-8h]

  v8 = a4 + 0x2000;
  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v22 = 0;
  if ( (debug_mdl & 0x10) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x10,
      4,
      "__cam_req_mgr_send_evt",
      535,
      "Notify event type: %d to all connected devices on link: 0x%x",
      a2,
      *a4);
  if ( *((_BYTE *)v8 + 593) == 1 )
    LOBYTE(v24) = 1;
  v9 = a4[1];
  if ( v9 < 1 )
  {
LABEL_18:
    result = 0;
    goto LABEL_19;
  }
  v10 = 0;
  v11 = 0;
  while ( 1 )
  {
    v12 = *((_QWORD *)a4 + 5);
    v13 = *a4;
    v14 = *(_DWORD *)(v12 + v10);
    v23 = a1;
    HIDWORD(v24) = a2;
    v22 = __PAIR64__(v14, v13);
    v15 = a3;
    if ( a2 == 7 )
      v15 = v8[149];
    LODWORD(v25) = v15;
    v16 = *(_QWORD *)(v12 + v10 + 304);
    if ( !v16 )
      goto LABEL_9;
    v17 = *(__int64 (__fastcall **)(_QWORD))(v16 + 40);
    if ( !v17 )
      goto LABEL_9;
    if ( *((_DWORD *)v17 - 1) != -662406558 )
      __break(0x8229u);
    v18 = v17(&v22);
    if ( v18 )
      break;
    v9 = a4[1];
LABEL_9:
    ++v11;
    v10 += 320;
    if ( v11 >= v9 )
      goto LABEL_18;
  }
  v21 = a1;
  v19 = v18;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    16,
    1,
    "__cam_req_mgr_send_evt",
    558,
    "Failed to send evt %d on link 0x%x dev 0x%x req %lld",
    a2,
    *a4,
    *(_DWORD *)(v12 + v10),
    v21);
  result = v19;
LABEL_19:
  *((_BYTE *)v8 + 593) = v24;
  _ReadStatusReg(SP_EL0);
  return result;
}
