__int64 __fastcall cam_hw_cdm_irq(__int64 a1, __int64 a2)
{
  __int64 v3; // x27
  __int64 v4; // x8
  signed int v5; // w23
  unsigned __int64 v6; // x8
  char v7; // w24
  unsigned __int64 v8; // x20
  unsigned int v9; // w21
  unsigned __int8 v10; // w25
  _QWORD *v11; // x23
  int v12; // w8
  _QWORD *v13; // x26
  __int64 v14; // x0
  unsigned int v21; // w9
  __int64 v22; // x0
  __int64 v23; // x26
  int v24; // w8
  __int64 v25; // x0
  _QWORD *v26; // x26
  __int64 v27; // x26
  int v28; // w8
  int v30; // [xsp+0h] [xbp-60h]
  int v31; // [xsp+8h] [xbp-58h]
  unsigned int v32; // [xsp+20h] [xbp-40h] BYREF
  unsigned int v33; // [xsp+24h] [xbp-3Ch] BYREF
  _QWORD v34[2]; // [xsp+28h] [xbp-38h] BYREF
  _QWORD v35[5]; // [xsp+38h] [xbp-28h] BYREF

  v35[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32 = 15;
  v33 = 0;
  v3 = *(_QWORD *)(a2 + 3680);
  memset(v35, 0, 32);
  v34[0] = 0;
  v34[1] = 0;
  if ( (debug_mdl & 1) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      4,
      "cam_hw_cdm_irq",
      1563,
      "Got irq hw_version 0x%x from %s%u",
      *(_DWORD *)(v3 + 216),
      *(const char **)(a2 + 152),
      *(_DWORD *)(a2 + 116));
  raw_spin_lock(a2 + 48);
  if ( *(_DWORD *)(a2 + 92) )
  {
    if ( *(_DWORD *)(v3 + 216) >= 0x20010000u
      && cam_cdm_read_hw_reg(a2, *(_DWORD *)(**(_QWORD **)(v3 + 232) + 40LL), (int *)&v32) )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        1,
        1,
        "cam_hw_cdm_irq",
        1574,
        "Failed to read CDM HW IRQ status");
    }
    v4 = *(_QWORD *)(v3 + 232);
    if ( *(_DWORD *)(*(_QWORD *)(v4 + 72) + 4LL) )
    {
      v5 = 0;
      do
      {
        if ( (((unsigned __int64)v32 >> v5) & 1) != 0 )
        {
          if ( (unsigned int)v5 >= 4 )
LABEL_70:
            __break(0x5512u);
          if ( cam_cdm_read_hw_reg(a2, *(_DWORD *)(*(_QWORD *)(v4 + 8LL * v5 + 40) + 20LL), (int *)v34 + v5) )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              1,
              1,
              "cam_hw_cdm_irq",
              1586,
              "Failed to read %s%u HW IRQ status",
              *(const char **)(a2 + 152),
              *(_DWORD *)(a2 + 116));
          if ( cam_cdm_write_hw_reg(
                 a2,
                 *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v3 + 232) + 8LL * v5 + 40) + 4LL),
                 *((_DWORD *)v34 + v5)) )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              1,
              1,
              "cam_hw_cdm_irq",
              1593,
              "Failed to Write %s%u HW IRQ Clear",
              *(const char **)(a2 + 152),
              *(_DWORD *)(a2 + 116));
          }
        }
        v4 = *(_QWORD *)(v3 + 232);
        ++v5;
      }
      while ( (unsigned int)v5 < *(_DWORD *)(*(_QWORD *)(v4 + 72) + 4LL) );
    }
    if ( cam_cdm_write_hw_reg(a2, *(_DWORD *)(*(_QWORD *)(v4 + 40) + 8LL), 1u) )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        1,
        "cam_hw_cdm_irq",
        1601,
        "Failed to Write %s%u HW IRQ clr cmd",
        *(const char **)(a2 + 152),
        *(_DWORD *)(a2 + 116));
    if ( cam_cdm_read_hw_reg(a2, *(_DWORD *)(**(_QWORD **)(v3 + 232) + 56LL), (int *)&v33) )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        1,
        "cam_hw_cdm_irq",
        1607,
        "Failed to read %s%u HW IRQ data",
        *(const char **)(a2 + 152),
        *(_DWORD *)(a2 + 116));
    raw_spin_unlock(a2 + 48);
    LODWORD(v6) = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v3 + 232) + 72LL) + 4LL);
    if ( (_DWORD)v6 )
    {
      v7 = 0;
      v8 = 0;
      v9 = 0;
      v10 = 0;
      v11 = (_QWORD *)(v3 + 2328);
      _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        if ( v8 == 4 )
          goto LABEL_70;
        if ( (v8 & 0x3FFFFFFFFFFFFFFFLL) == 4 )
        {
          __break(1u);
          goto LABEL_55;
        }
        v12 = *((_DWORD *)v34 + v8);
        if ( v12 )
        {
          if ( (v12 & 1) != 0 )
          {
            ++v10;
          }
          else
          {
            if ( (v12 & 2) != 0 )
            {
              v9 = (unsigned __int8)(v33 >> v7);
              if ( v9 == 255 )
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                  3,
                  1,
                  3,
                  "cam_hw_cdm_irq",
                  1625,
                  "Debug gen_irq received");
              _X8 = (unsigned int *)v11 + 21;
              __asm { PRFM            #0x11, [X8] }
              do
                v21 = __ldxr(_X8);
              while ( __stxr(v21 + 1, _X8) );
              if ( v9 <= 0x3F )
              {
                raw_spin_lock(v11 + 75);
                v13 = &v11[v9];
                v14 = v13[11];
                if ( v14 )
                {
                  complete_all(v14);
                  v13[11] = 0;
                }
                raw_spin_unlock(v11 + 75);
              }
              else if ( v9 != 255 )
              {
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  1,
                  2,
                  "cam_hw_cdm_irq",
                  1641,
                  "Not expected: exceeding fast complete array, inline_irq_data: %u, array length: %u",
                  v9,
                  64);
              }
            }
            if ( (debug_mdl & 1) != 0 && !debug_priority )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                1,
                4,
                "cam_hw_cdm_irq",
                1646,
                "Rcvd of fifo %d userdata 0x%x tag 0x%x irq_stat 0x%x",
                v8,
                v33,
                v9,
                *((_DWORD *)v34 + v8));
            if ( cam_cdm_write_hw_reg(
                   a2,
                   *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v3 + 232) + 8 * v8 + 40) + 4LL),
                   *((_DWORD *)v34 + v8)) )
            {
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, int, int))cam_print_log)(
                3,
                1,
                1,
                "cam_hw_cdm_irq",
                1654,
                "Failed to Write %s%u HW IRQ Clear",
                *(_QWORD *)(a2 + 152),
                *(unsigned int *)(a2 + 116),
                v30,
                v31);
              goto LABEL_69;
            }
            if ( mem_trace_en == 1 )
              v22 = cam_mem_trace_alloc(64, 0x820u, 0, "cam_hw_cdm_irq", 0x67Au);
            else
              v22 = _kvmalloc_node_noprof(64, 0, 2336, 0xFFFFFFFFLL);
            v23 = v22;
            v35[v8] = v22;
            if ( v22 )
            {
              *(_DWORD *)(v22 + 16) = v8;
              v24 = *((_DWORD *)v34 + v8);
              *(_QWORD *)v22 = a2;
              *(_DWORD *)(v22 + 8) = v24;
              *(_DWORD *)(v22 + 12) = v9;
              v25 = ktime_get_with_offset(1);
              *(_QWORD *)(v23 + 32) = 0xFFFFFFFE00000LL;
              v26 = (_QWORD *)(v23 + 32);
              *(v26 - 1) = v25;
              v26[1] = v26 + 1;
              v26[2] = v26 + 1;
              v26[3] = &cam_hw_cdm_work;
              if ( (queue_work_on(32, *v11, v26) & 1) == 0 )
              {
                v27 = v35[v8];
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  1,
                  1,
                  "cam_hw_cdm_irq",
                  1681,
                  "Failed to queue work for FIFO: %d irq=0x%x",
                  v8,
                  *(_DWORD *)(v27 + 8));
                if ( mem_trace_en == 1 )
                  cam_mem_trace_free((_QWORD *)v27, 0);
                else
                  kvfree(v27);
                v35[v8] = 0;
              }
            }
            else
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                1,
                1,
                "cam_hw_cdm_irq",
                1661,
                "failed to allocate memory for fifo %d payload",
                v8);
            }
          }
        }
        ++v8;
        v7 += 8;
        v11 += 80;
        v6 = *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(v3 + 232) + 72LL) + 4LL);
        if ( v8 >= v6 )
          goto LABEL_60;
      }
    }
    v10 = 0;
LABEL_60:
    if ( (_DWORD)v6 == v10 )
    {
      if ( (debug_mdl & 1) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          1,
          4,
          "cam_hw_cdm_irq",
          1689,
          "%s%u HW reset done IRQ",
          *(const char **)(a2 + 152),
          *(_DWORD *)(a2 + 116));
      complete(v3 + 144);
    }
    if ( v10 )
    {
      v28 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v3 + 232) + 72LL) + 4LL);
      if ( v28 != v10 )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD, int))cam_print_log)(
          3,
          1,
          3,
          "cam_hw_cdm_irq",
          1698,
          "%s%u Reset IRQ received for %d fifos instead of %d",
          *(_QWORD *)(a2 + 152),
          *(unsigned int *)(a2 + 116),
          v10,
          v28);
    }
  }
  else
  {
LABEL_55:
    if ( (debug_mdl & 1) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        1,
        4,
        "cam_hw_cdm_irq",
        1566,
        "CDM is in power down state");
    raw_spin_unlock(a2 + 48);
  }
LABEL_69:
  _ReadStatusReg(SP_EL0);
  return 1;
}
