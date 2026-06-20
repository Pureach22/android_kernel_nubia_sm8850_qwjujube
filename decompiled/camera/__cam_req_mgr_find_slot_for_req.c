__int64 __fastcall _cam_req_mgr_find_slot_for_req(int *a1, __int64 a2)
{
  int v2; // w2
  unsigned int v3; // w7
  int v6; // w21
  _DWORD *v7; // x22
  _DWORD *v8; // x9
  unsigned int v10; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+18h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v3 = a1[866];
  v10 = v3;
  if ( v2 < 1 )
    goto LABEL_8;
  if ( v3 > 0x30 )
  {
LABEL_7:
    __break(0x5512u);
LABEL_8:
    v6 = 0;
    goto LABEL_12;
  }
  v6 = 0;
  v7 = a1 + 2;
  while ( 1 )
  {
    v8 = &v7[18 * v3];
    if ( *((_QWORD *)v8 + 2) == a2 )
      break;
    cam_common_dec_idx(&v10, 1);
    v2 = *a1;
    if ( ++v6 >= *a1 )
      goto LABEL_12;
    v3 = v10;
    if ( v10 >= 0x31 )
      goto LABEL_7;
  }
  if ( (debug_mdl & 0x10) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x10,
      4,
      "__cam_req_mgr_find_slot_for_req",
      830,
      "req: %lld found at idx: %d status: %d sync_mode: %d",
      a2,
      v3,
      v8[2],
      v8[6]);
    v2 = *a1;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  if ( v6 >= v2 )
    return 0xFFFFFFFFLL;
  else
    return v10;
}
