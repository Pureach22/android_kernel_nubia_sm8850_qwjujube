__int64 __fastcall cam_hw_cdm_dump_bl_fifo_data(__int64 result)
{
  __int64 v1; // x25
  __int64 v2; // x19
  unsigned __int64 v3; // x20
  __int64 v4; // x28
  unsigned int *v5; // x28
  int v6; // t1
  unsigned int v7; // w24
  int v8; // [xsp+1Ch] [xbp-14h] BYREF
  _QWORD v9[2]; // [xsp+20h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(result + 3680);
  v8 = 0;
  v9[0] = 0;
  if ( **(_DWORD **)(*(_QWORD *)(v1 + 232) + 72LL) )
  {
    v2 = result;
    v3 = 0;
    do
    {
      cam_hw_cdm_bl_fifo_pending_bl_rb_in_fifo(v2, v3, &v8);
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 1,
                 3,
                 "cam_hw_cdm_dump_bl_fifo_data",
                 330,
                 "Fifo:%d content dump. num_pending_BLs: %d",
                 v3,
                 v8);
      if ( v8 )
      {
        if ( v3 > 3 )
          __break(0x5512u);
        v4 = v1 + 2296 + 640 * v3;
        v6 = *(_DWORD *)(v4 + 108);
        v5 = (unsigned int *)(v4 + 108);
        if ( v6 )
        {
          v7 = 0;
          do
          {
            cam_cdm_write_hw_reg(v2, *(_DWORD *)(**(_QWORD **)(v1 + 232) + 44LL), v7);
            cam_cdm_read_hw_reg(v2, *(_DWORD *)(**(_QWORD **)(v1 + 232) + 48LL), (int *)v9);
            cam_cdm_read_hw_reg(v2, *(_DWORD *)(**(_QWORD **)(v1 + 232) + 52LL), (int *)v9 + 1);
            result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                       3,
                       1,
                       3,
                       "cam_hw_cdm_dump_bl_fifo_data",
                       348,
                       "BL_entry:%d base_addr:0x%x, len:%d, ARB:%d, tag:%d",
                       v7++,
                       LODWORD(v9[0]),
                       HIDWORD(v9[0]) & 0xFFFFF,
                       (HIDWORD(v9[0]) >> 20) & 1,
                       HIBYTE(HIDWORD(v9[0])));
          }
          while ( v7 < *v5 );
        }
      }
      ++v3;
    }
    while ( v3 < **(unsigned int **)(*(_QWORD *)(v1 + 232) + 72LL) );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
