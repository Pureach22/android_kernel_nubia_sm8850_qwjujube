__int64 __fastcall cam_synx_obj_create(const char *a1, __int64 a2, _DWORD *a3, unsigned int *a4)
{
  unsigned int first_zero_bit; // w0
  __int64 v8; // x24
  __int64 v9; // x25
  unsigned __int64 v16; // x8
  unsigned int v17; // w26
  __int64 v18; // x0
  unsigned int v19; // w22
  unsigned __int64 v23; // x9
  _QWORD v24[3]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v25; // [xsp+20h] [xbp-10h]
  __int64 v26; // [xsp+28h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = 0;
  do
  {
    first_zero_bit = find_first_zero_bit(g_cam_synx_obj_dev + 23608, 256);
    if ( first_zero_bit > 0xFF )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        128,
        1,
        "__cam_synx_obj_find_free_idx",
        320,
        "Error: Unable to create synx, no free index");
      v19 = -1;
      goto LABEL_9;
    }
    v8 = 1LL << first_zero_bit;
    v9 = (unsigned __int8)first_zero_bit >> 6;
    _X9 = (unsigned __int64 *)(g_cam_synx_obj_dev + 23608 + 8 * v9);
    __asm { PRFM            #0x11, [X9] }
    do
      v16 = __ldxr(_X9);
    while ( __stlxr(v16 | v8, _X9) );
    __dmb(0xBu);
  }
  while ( (v16 & v8) != 0 );
  v17 = first_zero_bit;
  v24[1] = a3;
  v24[2] = 0;
  v18 = *(_QWORD *)(g_cam_synx_obj_dev + 23552);
  v24[0] = a1;
  LODWORD(v25) = 2;
  v19 = synx_create(v18, v24);
  if ( v19 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x1000000000LL,
      1,
      "cam_synx_obj_create",
      477,
      "Failed to create new synx handle rc: %d",
      v19);
    _X8 = (unsigned __int64 *)(g_cam_synx_obj_dev + 23608 + 8 * v9);
    __asm { PRFM            #0x11, [X8] }
    do
      v23 = __ldxr(_X8);
    while ( __stxr(v23 & ~v8, _X8) );
  }
  else
  {
    *a4 = v17;
    ((void (*)(void))_cam_synx_obj_init_row)();
    if ( (debug_mdl & 0x1000000000LL) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x1000000000LL,
        4,
        "cam_synx_obj_create",
        485,
        "Created synx obj handle: %d[%s] row_idx: %u",
        *a3,
        a1,
        v17);
      v19 = 0;
    }
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return v19;
}
