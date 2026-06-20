__int64 __fastcall cam_jpeg_dma_irq(int a1, __int64 a2)
{
  __int64 v2; // x22
  __int64 v3; // x26
  unsigned int *v6; // x23
  __int64 v7; // x0
  unsigned int v8; // w20
  _DWORD *v9; // x8
  _DWORD *v10; // x8

  if ( a2 )
  {
    v2 = *(_QWORD *)(a2 + 3680);
    v3 = *(_QWORD *)(a2 + 384);
    v6 = *(unsigned int **)(v2 + 8);
    v7 = cam_io_r_mb(v3 + v6[1]);
    v8 = v7;
    cam_io_w_mb(v7, *(_QWORD *)(a2 + 384) + *(unsigned int *)(*(_QWORD *)(v2 + 8) + 8LL));
    if ( (debug_mdl & 0x200) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x200,
        4,
        "cam_jpeg_dma_irq",
        182,
        "irq_num: %d  irq_status: 0x%x , core_state: %d",
        a1,
        v8,
        *(_DWORD *)v2);
    if ( (v6[25] & v8) != 0 )
    {
      raw_spin_lock(a2 + 48);
      if ( *(_DWORD *)v2 == 1 )
      {
        ((void (__fastcall *)(__int64, __int64, _QWORD, const char *, __int64, const char *))cam_print_log)(
          2,
          512,
          0,
          "cam_jpeg_dma_irq",
          186,
          "DMA FrameDone IRQ");
        if ( (debug_mdl & 0x200) != 0 && !debug_priority )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            debug_mdl & 0x200,
            4,
            "cam_jpeg_dma_irq",
            187,
            "frane_done");
        *(_DWORD *)v2 = 4;
        cam_io_w_mb(v6[14], v3 + v6[5]);
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          512,
          2,
          "cam_jpeg_dma_irq",
          192,
          "unexpected frame done ");
        *(_DWORD *)v2 = 0;
      }
      raw_spin_unlock(a2 + 48);
    }
    if ( (v6[26] & v8) != 0 )
    {
      raw_spin_lock(a2 + 48);
      if ( *(_DWORD *)v2 == 4 )
      {
        v9 = *(_DWORD **)(v2 + 24);
        if ( v9 )
        {
          if ( *(v9 - 1) != -1977094699 )
            __break(0x8228u);
          ((void (__fastcall *)(_QWORD, __int64, __int64))v9)(v8, 1, v2 + 32);
        }
        else
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            512,
            2,
            "cam_jpeg_dma_irq",
            210,
            "unexpected frame done");
        }
        *(_DWORD *)v2 = 0;
      }
      else if ( *(_DWORD *)v2 == 2 )
      {
        *(_DWORD *)v2 = 1;
        complete(a2 + 56);
        if ( (debug_mdl & 0x200) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x200,
            4,
            "cam_jpeg_dma_irq",
            204,
            "JPEG DMA %s reset done",
            *(const char **)(a2 + 120));
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          512,
          1,
          "cam_jpeg_dma_irq",
          214,
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
        v10 = *(_DWORD **)(v2 + 24);
        if ( v10 )
        {
          if ( *(v10 - 1) != -1977094699 )
            __break(0x8228u);
          ((void (__fastcall *)(_QWORD, _QWORD, __int64))v10)(v8, 0, v2 + 32);
        }
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          512,
          1,
          "cam_jpeg_dma_irq",
          229,
          "unexpected abort irq");
      }
      raw_spin_unlock(a2 + 48);
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_dma_irq",
      167,
      "Invalid args");
  }
  return 1;
}
