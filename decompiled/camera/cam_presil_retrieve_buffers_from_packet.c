__int64 __fastcall cam_presil_retrieve_buffers_from_packet(unsigned int *a1, unsigned int a2, int a3)
{
  unsigned int v6; // w8
  int v7; // w24
  __int64 v8; // x25
  unsigned int *v9; // x27
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 result; // x0
  int v14; // w6
  __int64 v15; // [xsp+18h] [xbp-28h] BYREF
  unsigned __int64 v16; // [xsp+20h] [xbp-20h] BYREF
  unsigned __int64 v17; // [xsp+28h] [xbp-18h] BYREF
  _QWORD v18[2]; // [xsp+30h] [xbp-10h] BYREF

  v18[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  if ( !a1 || (a2 & 0x80000000) != 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x8000000,
      1,
      "cam_presil_retrieve_buffers_from_packet",
      790,
      "Invalid params packet %pK iommu_hdl: %d",
      a1,
      a2);
    result = 4294967274LL;
    goto LABEL_29;
  }
  if ( (debug_mdl & 0x8000000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x8000000,
      4,
      "cam_presil_retrieve_buffers_from_packet",
      794,
      "Retrieving output buffer corresponding to res: 0x%x",
      a3);
    v6 = a1[9];
    if ( v6 )
      goto LABEL_6;
LABEL_28:
    result = 0;
    goto LABEL_29;
  }
  v6 = a1[9];
  if ( !v6 )
    goto LABEL_28;
LABEL_6:
  v7 = 0;
  v8 = (__int64)a1 + a1[8] + 56;
  while ( 1 )
  {
    v9 = (unsigned int *)(v8 + ((__int64)v7 << 8));
    if ( v9[56] != 2 || v9[47] != a3 )
      goto LABEL_8;
    v10 = *v9;
    v17 = 0;
    v18[0] = 0;
    v16 = 0;
    if ( (_DWORD)v10 )
    {
      if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, unsigned __int64 *, __int64 *, _QWORD, _QWORD))cam_mem_get_io_buf)(
                           v10,
                           a2,
                           &v16,
                           &v15,
                           0,
                           0) )
      {
        v14 = 0;
        goto LABEL_26;
      }
      if ( HIDWORD(v16) )
        goto LABEL_22;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x8000000,
        3,
        "cam_presil_retrieve_buffers_from_packet",
        826,
        "Retrieving IO CFG buffer:%d addr: 0x%x offset 0x%x res_id: 0x%x",
        *v9,
        v16,
        v9[3],
        v9[47]);
      cam_mem_mgr_retrieve_buffer_from_presil();
      v11 = v9[1];
      if ( (_DWORD)v11 )
      {
        if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, unsigned __int64 *, __int64 *, _QWORD, _QWORD))cam_mem_get_io_buf)(
                             v11,
                             a2,
                             &v17,
                             &v15,
                             0,
                             0) )
        {
          v14 = 1;
          goto LABEL_26;
        }
        if ( HIDWORD(v17) )
          goto LABEL_22;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x8000000,
          3,
          "cam_presil_retrieve_buffers_from_packet",
          826,
          "Retrieving IO CFG buffer:%d addr: 0x%x offset 0x%x res_id: 0x%x",
          v9[1],
          v17,
          v9[4],
          v9[47]);
        cam_mem_mgr_retrieve_buffer_from_presil();
        v12 = v9[2];
        if ( (_DWORD)v12 )
          break;
      }
    }
LABEL_7:
    v6 = a1[9];
LABEL_8:
    if ( ++v7 >= v6 )
      goto LABEL_28;
  }
  if ( !(unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, _QWORD *, __int64 *, _QWORD, _QWORD))cam_mem_get_io_buf)(
                        v12,
                        a2,
                        v18,
                        &v15,
                        0,
                        0) )
  {
    if ( HIDWORD(v18[0]) )
    {
LABEL_22:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x8000000,
        1,
        "cam_presil_retrieve_buffers_from_packet",
        818,
        "Invalid address, presil mapped address should be 32 bit");
      result = 4294967274LL;
      goto LABEL_29;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x8000000,
      3,
      "cam_presil_retrieve_buffers_from_packet",
      826,
      "Retrieving IO CFG buffer:%d addr: 0x%x offset 0x%x res_id: 0x%x",
      v9[2],
      LODWORD(v18[0]),
      v9[5],
      v9[47]);
    cam_mem_mgr_retrieve_buffer_from_presil();
    goto LABEL_7;
  }
  v14 = 2;
LABEL_26:
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x8000000,
    1,
    "cam_presil_retrieve_buffers_from_packet",
    810,
    "no io addr for plane%d",
    v14);
  result = 4294967284LL;
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
