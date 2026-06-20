__int64 __fastcall cam_synx_obj_import_dma_fence(
        const char *a1,
        __int64 a2,
        const void *a3,
        _DWORD *a4,
        unsigned int *a5)
{
  unsigned int first_zero_bit; // w0
  __int64 v8; // x21
  __int64 v9; // x23
  unsigned __int64 v16; // x8
  unsigned int v17; // w24
  unsigned int v18; // w0
  unsigned int v19; // w19
  const char *v20; // x5
  __int64 v21; // x4
  __int64 result; // x0
  unsigned __int64 v25; // x9
  __int64 v26; // [xsp+8h] [xbp-38h] BYREF
  _DWORD *v27; // [xsp+10h] [xbp-30h] BYREF
  __int64 v28; // [xsp+18h] [xbp-28h]
  const void *v29; // [xsp+20h] [xbp-20h]
  __int64 v30; // [xsp+28h] [xbp-18h]
  __int64 v31; // [xsp+30h] [xbp-10h]
  __int64 v32; // [xsp+38h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = nullptr;
  v26 = 0;
  v27 = nullptr;
  if ( !a3 )
  {
    v20 = "Importing DMA fence failed - fence pointer is NULL";
    v21 = 502;
LABEL_12:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x1000000000LL,
      1,
      "cam_synx_obj_import_dma_fence",
      v21,
      v20);
    result = 4294967274LL;
    goto LABEL_14;
  }
  v29 = a3;
  v27 = a4;
  LODWORD(v26) = 1;
  LODWORD(v28) = 8;
  if ( !&v27 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x1000000000LL,
      1,
      "__cam_synx_map_generic_flags_to_import",
      441,
      "Import parameters missing");
    v20 = "Importing DMA fence failed - invalid synx import flags";
    v21 = 514;
    goto LABEL_12;
  }
  LODWORD(v28) = 10;
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
      result = 0xFFFFFFFFLL;
      goto LABEL_14;
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
  v18 = synx_import(*(_QWORD *)(g_cam_synx_obj_dev + 23552), &v26);
  if ( v18 )
  {
    v19 = v18;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x1000000000LL,
      1,
      "__cam_synx_obj_import",
      402,
      "Synx import failed for fence : %p",
      v29);
    _X8 = (unsigned __int64 *)(g_cam_synx_obj_dev + 23608 + 8 * v9);
    __asm { PRFM            #0x11, [X8] }
    do
      v25 = __ldxr(_X8);
    while ( __stxr(v25 & ~v8, _X8) );
    result = v19;
  }
  else
  {
    *a5 = v17;
    ((void (*)(void))_cam_synx_obj_init_row)();
    result = 0;
    if ( (debug_mdl & 0x1000000000LL) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x1000000000LL,
        4,
        "__cam_synx_obj_import",
        410,
        "Imported synx obj handle: %d[%s] row_idx: %u",
        *v27,
        a1,
        v17);
      result = 0;
    }
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
