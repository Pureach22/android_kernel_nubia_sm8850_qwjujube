__int64 __fastcall cam_camera_cci_i2c_read_seq(
        __int64 a1,
        int a2,
        __int64 a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6)
{
  _QWORD *v10; // x20
  __int64 v11; // x8
  __int64 (*v12)(void); // x8
  __int64 (*v13)(void); // x9
  unsigned int v14; // w22
  __int64 v15; // x21

  _ReadStatusReg(SP_EL0);
  if ( a4 > 4 || a5 > 4 || a6 > 0x5000 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_camera_cci_i2c_read_seq",
      74,
      "addr_type %d num_byte %d",
      a4,
      a6);
    v14 = -14;
    goto LABEL_32;
  }
  if ( mem_trace_en == 1 )
  {
    v10 = (_QWORD *)cam_mem_trace_alloc(a6, 0xCC0u, 0, "cam_camera_cci_i2c_read_seq", 0x4Eu);
    if ( v10 )
      goto LABEL_6;
LABEL_25:
    v14 = -12;
    goto LABEL_32;
  }
  v10 = (_QWORD *)_kvmalloc_node_noprof(a6, 0, 3520, 0xFFFFFFFFLL);
  if ( !v10 )
    goto LABEL_25;
LABEL_6:
  if ( !*(_QWORD *)a1 )
  {
    v14 = -19;
    goto LABEL_28;
  }
  v11 = **(_QWORD **)(*(_QWORD *)a1 + 160LL);
  if ( !v11 || (v12 = *(__int64 (**)(void))(v11 + 56)) == nullptr )
  {
    v14 = -515;
LABEL_28:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_camera_cci_i2c_read_seq",
      93,
      "CCI config failed rc = %d",
      v14);
    goto LABEL_29;
  }
  if ( !v4l2_subdev_call_wrappers || (v13 = *(__int64 (**)(void))(v4l2_subdev_call_wrappers + 56LL)) == nullptr )
    v13 = v12;
  if ( *((_DWORD *)v13 - 1) != 1356305480 )
    __break(0x8229u);
  v14 = v13();
  if ( (v14 & 0x80000000) != 0 )
    goto LABEL_28;
  v14 = -14;
  if ( (debug_mdl & 0x4000000000LL) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x4000000000LL,
      4,
      "cam_camera_cci_i2c_read_seq",
      97,
      "addr = 0x%x, rc = %d",
      a2,
      -14);
    if ( a6 )
    {
LABEL_18:
      v15 = 0;
      do
      {
        *(_BYTE *)(a3 + v15) = *((_BYTE *)v10 + v15);
        if ( (debug_mdl & 0x4000000000LL) != 0 && !debug_priority )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
            3,
            debug_mdl & 0x4000000000LL,
            4,
            "cam_camera_cci_i2c_read_seq",
            100,
            "Byte %d: Data: 0x%x\n",
            (unsigned int)v15);
        ++v15;
      }
      while ( a6 != v15 );
    }
  }
  else if ( a6 )
  {
    goto LABEL_18;
  }
LABEL_29:
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v10, 0);
  else
    kvfree(v10);
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return v14;
}
