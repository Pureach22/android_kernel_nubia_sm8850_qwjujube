__int64 __fastcall cam_packet_util_dump_patch_info(__int64 a1, int a2, int a3, __int64 a4)
{
  __int64 v8; // x19
  const char *v9; // x5
  __int64 v10; // x4
  int v11; // w24
  __int64 result; // x0
  unsigned int v13; // w23
  int *v14; // x26
  int v15; // w28
  int v16; // w8
  unsigned __int64 v17; // x9
  unsigned __int64 v18; // x8
  unsigned __int64 v19; // x10
  bool v20; // cc
  unsigned __int64 v21; // x8
  _DWORD *v22; // x28
  int v23; // [xsp+40h] [xbp-30h]
  __int64 v24; // [xsp+48h] [xbp-28h] BYREF
  __int64 v25; // [xsp+50h] [xbp-20h]
  __int64 v26; // [xsp+58h] [xbp-18h] BYREF
  __int64 v27; // [xsp+60h] [xbp-10h]
  __int64 v28; // [xsp+68h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  if ( !a1 )
  {
    v9 = "Invalid packet";
    v10 = 227;
LABEL_26:
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               3,
               0x20000,
               1,
               "cam_packet_util_dump_patch_info",
               v10,
               v9);
    goto LABEL_27;
  }
  if ( a4 )
  {
    v8 = a4 + 8;
    v23 = *(_DWORD *)(*(_QWORD *)a4 + 40LL);
  }
  else
  {
    v8 = 0;
    v23 = 0;
  }
  v11 = *(_DWORD *)(a1 + 40);
  result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             0x20000,
             3,
             "cam_packet_util_dump_patch_info",
             241,
             "Total num of patches : %d",
             *(_DWORD *)(a1 + 44));
  if ( *(_DWORD *)(a1 + 44) )
  {
    v13 = 0;
    while ( 1 )
    {
      v14 = (int *)(a1 + (v11 & 0xFFFFFFFC) + 56 + 16LL * (int)v13);
      if ( (v14[2] & 0x8000) != 0 )
        v15 = a3;
      else
        v15 = a2;
      if ( (((__int64 (*)(void))cam_mem_get_io_buf)() & 0x80000000) != 0 )
      {
        result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   0x20000,
                   1,
                   "cam_packet_util_dump_patch_info",
                   251,
                   "unable to get src buf address for hdl 0x%x",
                   v15);
        goto LABEL_27;
      }
      if ( a4 && *((__int16 *)v14 + 5) == v23 && !*(_DWORD *)v8 )
      {
        *(_DWORD *)(v8 + 24) = v13;
        *(_DWORD *)v8 = 2;
        *(_DWORD *)(v8 + 8) = v14[2];
        v16 = v14[3];
        *(_DWORD *)(v8 + 28) = 0;
        v17 = v27;
        *(_DWORD *)(v8 + 12) = v16;
        v18 = *(_QWORD *)(*(_QWORD *)a4 + 16LL);
        v19 = v17 - v18;
        v20 = v18 > v17;
        v21 = v18 - v17;
        if ( !v20 )
          v21 = v19;
        *(_QWORD *)(v8 + 16) = v21;
        *(_QWORD *)(v8 + 32) = *(_QWORD *)(a1 + 8);
        *(_BYTE *)(v8 + 40) = 1;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_packet_util_dump_patch_info",
          270,
          "Found PF at patch: %d src buf hdl: 0x%llx",
          v13,
          (unsigned int)v14[2]);
      }
      if ( (cam_mem_get_cpu_buf(*v14, &v24, &v26) & 0x80000000) != 0 || !v24 || !v26 )
        break;
      v22 = (_DWORD *)(v24 + (unsigned int)v14[1]);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        3,
        "cam_packet_util_dump_patch_info",
        290,
        "i = %d src_buf 0x%llx src_hdl 0x%x src_buf_with_offset 0x%llx src_size 0x%llx src_flags: %x dst %p dst_offset %u"
        " dst_hdl 0x%x value 0x%x",
        v13,
        v27,
        v14[2],
        v27 + (unsigned int)v14[3],
        v25,
        0,
        v22,
        v14[1],
        *v14,
        *v22);
      if ( !*v22 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_packet_util_dump_patch_info",
          293,
          "Null at dst addr %p",
          v22);
      result = cam_mem_put_cpu_buf(*v14);
      if ( ++v13 >= *(_DWORD *)(a1 + 44) )
        goto LABEL_27;
    }
    v9 = "unable to get dst buf address";
    v10 = 276;
    goto LABEL_26;
  }
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
