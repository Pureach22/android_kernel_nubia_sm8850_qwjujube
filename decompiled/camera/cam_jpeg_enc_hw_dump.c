__int64 __fastcall cam_jpeg_enc_hw_dump(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x21
  __int64 v5; // x24
  unsigned __int64 v6; // x7
  unsigned __int64 v7; // x8
  unsigned __int64 v8; // x6
  unsigned __int64 v9; // x8
  __int64 result; // x0
  unsigned __int64 v11; // x22
  _DWORD *v12; // x26
  int v13; // w24
  __int64 v14; // t2
  unsigned int v15; // w8
  _DWORD *v16; // x28
  __int64 v17; // x25
  int v18; // w27
  __int64 v19; // x8
  __int64 v20; // x9
  __int16 v21; // w8

  v2 = *(_QWORD *)(a1 + 3680);
  v5 = *(_QWORD *)(v2 + 8);
  mutex_lock(v2 + 64);
  raw_spin_lock(a1 + 48);
  if ( !*(_DWORD *)(a1 + 92) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_enc_hw_dump",
      483,
      "JPEG HW is in off state");
    raw_spin_unlock(a1 + 48);
    mutex_unlock(v2 + 64);
    return 4294967274LL;
  }
  raw_spin_unlock(a1 + 48);
  v6 = a2[2];
  v7 = a2[3];
  v8 = v7 - v6;
  if ( v7 <= v6 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      512,
      2,
      "cam_jpeg_enc_hw_dump",
      493,
      "dump buffer overshoot %zu %zu",
      a2[3]);
    goto LABEL_7;
  }
  v9 = (unsigned int)(*(_DWORD *)(a1 + 400) + 148);
  if ( v8 < v9 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      2,
      "cam_jpeg_enc_hw_dump",
      503,
      "dump buffer exhaust %zu %u",
      v8,
      v9);
LABEL_7:
    mutex_unlock(v2 + 64);
    return 4294967268LL;
  }
  v11 = a2[1] + v6;
  strcpy((char *)v11, "JPEG_REG:");
  v12 = (_DWORD *)(v11 + 148);
  *(_DWORD *)(v11 + 136) = 4;
  *(_DWORD *)(v11 + 144) = *(_DWORD *)(a1 + 116);
  v14 = v5 + 124;
  v13 = *(_DWORD *)(v5 + 124);
  v15 = *(_DWORD *)(v14 + 4) - v13;
  if ( v15 >= 4 )
  {
    v17 = v15 >> 2;
    v18 = 0;
    do
    {
      *v12 = v13 + v18 + **(_DWORD **)(a1 + 320);
      v16 = v12 + 2;
      --v17;
      v12[1] = cam_io_r(*(_QWORD *)(a1 + 384) + v18);
      v18 += 4;
      v12 += 2;
    }
    while ( v17 );
  }
  else
  {
    v16 = (_DWORD *)(v11 + 148);
  }
  mutex_unlock(v2 + 64);
  result = 0;
  v19 = ((__int64)((__int64)v16 - v11 - 144) >> 2) * *(unsigned int *)(v11 + 136);
  *(_QWORD *)(v11 + 128) = v19;
  v20 = v19 + a2[2];
  v21 = debug_mdl;
  a2[2] = v20 + 144;
  if ( (v21 & 0x200) != 0 && !debug_priority )
  {
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v21 & 0x200,
      4,
      "cam_jpeg_enc_hw_dump",
      529,
      "offset %zu",
      v20 + 144);
    return 0;
  }
  return result;
}
