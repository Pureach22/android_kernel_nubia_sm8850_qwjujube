__int64 __fastcall cam_isp_scratch_buf_update_util(unsigned int *a1, __int64 a2)
{
  __int16 v4; // w8
  unsigned int v5; // w8
  int *v6; // x8
  int v7; // w21
  __int64 result; // x0
  unsigned __int64 v9; // x6
  unsigned int v10; // w6
  __int64 v11; // x8
  __int64 v12; // x10
  unsigned int v13; // w7
  unsigned int v14; // w8
  unsigned int v15; // w9
  unsigned int v16; // w12
  char v17; // w11
  __int64 v18; // [xsp+28h] [xbp-18h] BYREF
  _QWORD v19[2]; // [xsp+30h] [xbp-10h] BYREF

  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a1;
  v18 = 0;
  v19[0] = 0;
  v5 = v4 & 0x8000;
  *(_BYTE *)(a2 + 33) = v5 >> 15;
  if ( v5 )
    v6 = &dword_39493C;
  else
    v6 = &dword_394938;
  v7 = *v6;
  if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, _QWORD, __int64 *, _QWORD *, _QWORD, _QWORD))cam_mem_get_io_buf)(
                       *a1,
                       (unsigned int)*v6,
                       &v18,
                       v19,
                       0,
                       0) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_scratch_buf_update_util",
      10054,
      "no scratch buf addr for res: 0x%x",
      a1[6]);
    result = 4294967284LL;
  }
  else
  {
    v9 = a1[1];
    if ( v19[0] <= v9 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_isp_scratch_buf_update_util",
        10063,
        "Invalid scratch buffer offset:%u size:%u mmu_hdl:%u hdl:%d res_type:0x%x",
        v9,
        LODWORD(v19[0]),
        v7,
        *a1,
        a1[6]);
      result = 4294967274LL;
    }
    else
    {
      v10 = a1[6];
      v11 = v18;
      result = 0;
      *(_DWORD *)(a2 + 24) = v10;
      v12 = v11 + a1[1];
      *(_QWORD *)(a2 + 16) = v12;
      v13 = a1[2];
      *(_DWORD *)a2 = v13;
      v14 = a1[3];
      *(_DWORD *)(a2 + 4) = v14;
      v15 = a1[4];
      *(_DWORD *)(a2 + 8) = v15;
      v16 = a1[5];
      *(_BYTE *)(a2 + 32) = 1;
      v17 = debug_mdl;
      *(_DWORD *)(a2 + 28) = 0;
      *(_DWORD *)(a2 + 12) = v16;
      if ( (v17 & 8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v17 & 8,
          4,
          "cam_isp_scratch_buf_update_util",
          10081,
          "res_id: 0x%x w: %d h: %d s: %d sh: %d addr: 0x%x",
          v10,
          v13,
          v14,
          v15,
          v16,
          v12);
        result = 0;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
