__int64 __fastcall cam_jpeg_enc_irq(int a1, __int64 a2)
{
  __int64 v2; // x23
  __int64 v4; // x27
  _DWORD *v6; // x24
  __int64 v7; // x0
  unsigned int v8; // w21
  unsigned int v9; // w0
  _DWORD *v10; // x8
  _DWORD *v11; // x8
  __int64 v12; // x0
  _DWORD *v13; // x8

  if ( a2 )
  {
    v2 = *(_QWORD *)(a2 + 3680);
    v4 = *(_QWORD *)(a2 + 384);
    v6 = *(_DWORD **)(v2 + 8);
    raw_spin_lock(a2 + 48);
    if ( !*(_DWORD *)(a2 + 92) )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        512,
        1,
        "cam_jpeg_enc_irq",
        189,
        "JPEG HW is in off state");
LABEL_41:
      raw_spin_unlock(a2 + 48);
      return 1;
    }
    v7 = cam_io_r_mb(v4 + *(unsigned int *)(*(_QWORD *)(v2 + 8) + 4LL));
    v8 = v7;
    cam_io_w_mb(v7, *(_QWORD *)(a2 + 384) + *(unsigned int *)(*(_QWORD *)(v2 + 8) + 8LL));
    raw_spin_unlock(a2 + 48);
    if ( (debug_mdl & 0x200) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x200,
        4,
        "cam_jpeg_enc_irq",
        202,
        "irq_num: %d  irq_status: 0x%x , core_state: %d",
        a1,
        v8,
        *(_DWORD *)v2);
    if ( (v6[25] & v8) != 0 )
    {
      raw_spin_lock(a2 + 48);
      if ( *(_DWORD *)v2 == 1 )
      {
        ((void (*)(__int64, __int64, _QWORD, const char *, __int64, const char *, ...))cam_print_log)(
          2,
          512,
          0,
          "cam_jpeg_enc_irq",
          208,
          "Ctx %lld ENC FrameDone IRQ",
          *(_QWORD *)(v2 + 32));
        v9 = cam_io_r_mb(v4 + *(unsigned int *)(*(_QWORD *)(v2 + 8) + 24LL));
        v10 = *(_DWORD **)(v2 + 24);
        if ( v10 )
        {
          if ( *(v10 - 1) != -1977094699 )
            __break(0x8228u);
          ((void (__fastcall *)(_QWORD, _QWORD, __int64))v10)(v8, v9, v2 + 32);
        }
        else
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            512,
            1,
            "cam_jpeg_enc_irq",
            216,
            "unexpected done, no cb");
        }
        cam_cpas_notify_event((__int64)"JPEG FrameDone", 0);
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          512,
          1,
          "cam_jpeg_enc_irq",
          220,
          "unexpected done irq");
      }
      *(_DWORD *)v2 = 0;
      raw_spin_unlock(a2 + 48);
    }
    if ( (v6[26] & v8) != 0 )
    {
      raw_spin_lock(a2 + 48);
      if ( *(_DWORD *)v2 == 2 )
      {
        *(_DWORD *)v2 = 1;
        complete(a2 + 56);
        if ( (debug_mdl & 0x200) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x200,
            4,
            "cam_jpeg_enc_irq",
            231,
            "JPEG ENC (%s) reset done",
            *(const char **)(a2 + 120));
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          512,
          1,
          "cam_jpeg_enc_irq",
          233,
          "unexpected reset irq");
      }
      raw_spin_unlock(a2 + 48);
    }
    if ( (v6[28] & v8) != 0 )
    {
      raw_spin_lock(a2 + 48);
      if ( *(_DWORD *)v2 == 3 )
      {
        *(_DWORD *)v2 = 0;
        complete(a2 + 56);
        v11 = *(_DWORD **)(v2 + 24);
        if ( v11 )
        {
          if ( *(v11 - 1) != -1977094699 )
            __break(0x8228u);
          ((void (__fastcall *)(_QWORD, __int64, __int64))v11)(v8, 0xFFFFFFFFLL, v2 + 32);
        }
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          512,
          1,
          "cam_jpeg_enc_irq",
          247,
          "unexpected abort irq");
      }
      raw_spin_unlock(a2 + 48);
    }
    if ( (v6[27] & v8) != 0 )
    {
      raw_spin_lock(a2 + 48);
      *(_DWORD *)v2 = 0;
      if ( (unsigned int)__ratelimit(&cam_jpeg_enc_irq__rs, "cam_jpeg_enc_irq") )
        v12 = 3;
      else
        v12 = 2;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        v12,
        512,
        1,
        "cam_jpeg_enc_irq",
        257,
        "error irq_num %d  irq_status = %x , core_state %d",
        a1,
        v8,
        *(_DWORD *)v2);
      v13 = *(_DWORD **)(v2 + 24);
      if ( v13 )
      {
        if ( *(v13 - 1) != -1977094699 )
          __break(0x8228u);
        ((void (__fastcall *)(_QWORD, __int64, __int64))v13)(v8, 0xFFFFFFFFLL, v2 + 32);
      }
      goto LABEL_41;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_enc_irq",
      178,
      "Invalid args");
  }
  return 1;
}
