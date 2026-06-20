__int64 __fastcall cam_cpas_hw_reg_write(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x24
  unsigned int v7; // w19
  unsigned int v8; // w8
  unsigned int v9; // w20
  __int64 v10; // x26
  char v11; // w25
  __int64 v12; // x21
  unsigned int v13; // w22
  unsigned int v14; // w23
  __int64 v15; // x7
  unsigned int v17; // w19

  if ( (unsigned int)a3 >= 0xA )
    goto LABEL_18;
  v6 = *(_QWORD *)(a1 + 3680);
  v7 = *(_DWORD *)(v6 + 4LL * (unsigned int)a3 + 2812);
  v8 = *(_DWORD *)(a1 + 576);
  if ( (v7 & 0x80000000) != 0 || v7 >= v8 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_reg_write",
      624,
      "Invalid reg_base=%d, reg_base_index=%d, num_map=%d",
      a3,
      v7,
      v8);
    return 4294967274LL;
  }
  v9 = a2;
  if ( (unsigned int)a2 > 0x2A )
    return 4294967274LL;
  v10 = a1;
  v11 = a5;
  v12 = v6 + 48LL * (unsigned int)a2;
  v13 = a4;
  v14 = a6;
  a1 = mutex_lock(v12 + 664);
  v15 = *(_QWORD *)(v6 + 8LL * v9 + 320);
  if ( *(_BYTE *)(v15 + 168) == 1 && (*(_BYTE *)(v15 + 169) & 1) != 0 )
  {
    if ( (v11 & 1) != 0 )
    {
      if ( v7 <= 7 )
      {
        cam_io_w_mb(v14, *(_QWORD *)(v10 + 24LL * v7 + 384) + v13);
LABEL_15:
        v17 = 0;
        goto LABEL_16;
      }
    }
    else if ( v7 <= 7 )
    {
      cam_io_w(v14, *(_QWORD *)(v10 + 24LL * v7 + 384) + v13);
      goto LABEL_15;
    }
LABEL_18:
    __break(0x5512u);
    return cam_cpas_hw_reg_read(a1, a2, a3, a4, a5, a6);
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
    3,
    4,
    1,
    "cam_cpas_hw_reg_write",
    637,
    "client=[%d][%s][%d] has not started",
    v9);
  v17 = -1;
LABEL_16:
  mutex_unlock(v12 + 664);
  return v17;
}
