__int64 __fastcall cam_cci_transfer_end(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w19
  unsigned int v5; // w20
  __int64 v6; // x26
  __int64 v7; // x23
  __int64 v8; // x22
  __int64 v9; // x1
  unsigned int v10; // w0
  __int64 v11; // x27
  __int64 v12; // x0
  unsigned int v13; // w0
  unsigned int v14; // w8
  __int64 v15; // x6
  unsigned int v16; // w21
  __int64 v17; // x24
  __int64 v18; // x0
  unsigned int v19; // w0
  __int64 v20; // x6
  __int64 v21; // x6

  if ( (unsigned int)a2 < 2 )
  {
    v3 = a3;
    if ( (unsigned int)a3 <= 2 )
    {
      v5 = a2;
      v6 = a1 + 544LL * (unsigned int)a2 + 4040;
      v7 = v6 + 4LL * (unsigned int)a3;
      v8 = a1 + 544LL * (unsigned int)a2 + 4044;
      v9 = raw_spin_lock_irqsave(v7 + 328);
      if ( *(_DWORD *)(v6 + 4 + 4LL * v3) )
      {
        *(_DWORD *)(v6 + 320 + 4LL * v3) = 1;
        raw_spin_unlock_irqrestore(v7 + 328, v9);
        v10 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))cam_cci_wait)(a1, v5, v3);
        if ( (v10 & 0x80000000) != 0 )
        {
          v21 = *(unsigned int *)(a1 + 404);
          v16 = v10;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, unsigned int, unsigned int))cam_print_log)(
            3,
            0x4000,
            1,
            "cam_cci_transfer_end",
            433,
            "CCI%d_I2C_M%d_Q%d Failed with cci_wait for rc: %d",
            v21,
            v5,
            v3,
            v10);
          return v16;
        }
        cam_cci_load_report_cmd(a1, v5, v3);
        cam_cci_lock_queue(a1, v5, v3, 0);
        v11 = *(_QWORD *)(a1 + 672);
        v12 = raw_spin_lock_irqsave(v7 + 328);
        *(_DWORD *)(v8 + 4LL * v3) = 1;
        *(_DWORD *)(v6 + 320 + 4LL * v3) = 1;
        raw_spin_unlock_irqrestore(v7 + 328, v12);
        cam_io_w_mb((unsigned int)(1 << (v3 + 2 * v5)), v11 + 8);
        v13 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))cam_cci_wait)(a1, v5, v3);
        v14 = 0;
        if ( (v13 & 0x80000000) != 0 )
        {
          v15 = *(unsigned int *)(a1 + 404);
          v16 = v13;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, unsigned int, unsigned int))cam_print_log)(
            3,
            0x4000,
            1,
            "cam_cci_transfer_end",
            443,
            "CCI%d_I2C_M%d_Q%d Failed in wait_report_cmd for rc: %d",
            v15,
            v5,
            v3,
            v13);
          return v16;
        }
      }
      else
      {
        raw_spin_unlock_irqrestore(v7 + 328, v9);
        cam_cci_load_report_cmd(a1, v5, v3);
        cam_cci_lock_queue(a1, v5, v3, 0);
        v17 = *(_QWORD *)(a1 + 672);
        v18 = raw_spin_lock_irqsave(v7 + 328);
        *(_DWORD *)(v8 + 4LL * v3) = 1;
        *(_DWORD *)(v7 + 320) = 1;
        raw_spin_unlock_irqrestore(v7 + 328, v18);
        cam_io_w_mb((unsigned int)(1 << (v3 + 2 * v5)), v17 + 8);
        v19 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))cam_cci_wait)(a1, v5, v3);
        v14 = 0;
        if ( (v19 & 0x80000000) != 0 )
        {
          v20 = *(unsigned int *)(a1 + 404);
          v16 = v19;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, unsigned int, unsigned int))cam_print_log)(
            3,
            0x4000,
            1,
            "cam_cci_transfer_end",
            420,
            "CCI%d_I2C_M%d_Q%d Failed for wait_report_cmd for rc: %d",
            v20,
            v5,
            v3,
            v19);
          return v16;
        }
      }
      return v14;
    }
  }
  __break(0x5512u);
  return cam_cci_load_report_cmd(a1, a2, a3);
}
