__int64 __fastcall cam_ife_csid_ver2_irq_inject(__int64 a1, __int64 a2)
{
  unsigned int v3; // w20
  __int64 v4; // x22
  __int64 v5; // x21
  __int64 v6; // x23
  __int64 v7; // x0
  __int64 v8; // x1
  __int64 v9; // x8
  unsigned int *v10; // x8
  unsigned int v11; // w20

  v3 = *(_DWORD *)(a2 + 8);
  v4 = **(_QWORD **)(a1 + 31136);
  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 31128) + 384LL);
  if ( v3 > 0xF )
    goto LABEL_25;
  if ( ((1 << v3) & 0xCFFC) == 0 )
  {
    if ( v3 == 12 )
    {
      v10 = (unsigned int *)(*(_QWORD *)(v4 + 120) + 72LL);
      goto LABEL_18;
    }
    if ( v3 == 13 )
    {
      v10 = (unsigned int *)(*(_QWORD *)(v4 + 128) + 28LL);
      goto LABEL_18;
    }
LABEL_25:
    if ( v3 == 1 )
    {
      v10 = (unsigned int *)(*(_QWORD *)(v4 + 128) + 24LL);
    }
    else
    {
      if ( v3 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          2,
          "cam_ife_csid_ver2_irq_inject",
          8883,
          "Invalid reg_unit %d",
          v3);
        return 4294967274LL;
      }
      v10 = (unsigned int *)(*(_QWORD *)(v4 + 120) + 68LL);
    }
    goto LABEL_18;
  }
  if ( v3 == (unsigned int)cam_ife_csid_convert_res_to_irq_reg(0) )
  {
    v6 = 0;
  }
  else
  {
    v6 = 1;
    if ( v3 != (unsigned int)cam_ife_csid_convert_res_to_irq_reg(1u) )
    {
      v6 = 2;
      if ( v3 != (unsigned int)cam_ife_csid_convert_res_to_irq_reg(2u) )
      {
        v6 = 3;
        if ( v3 != (unsigned int)cam_ife_csid_convert_res_to_irq_reg(3u) )
        {
          v6 = 4;
          if ( v3 != (unsigned int)cam_ife_csid_convert_res_to_irq_reg(4u) )
          {
            v6 = 5;
            if ( v3 != (unsigned int)cam_ife_csid_convert_res_to_irq_reg(5u) )
            {
              v6 = 6;
              if ( v3 != (unsigned int)cam_ife_csid_convert_res_to_irq_reg(6u) )
              {
                v6 = 7;
                if ( v3 != (unsigned int)cam_ife_csid_convert_res_to_irq_reg(7u) )
                {
                  v6 = 8;
                  if ( v3 != (unsigned int)cam_ife_csid_convert_res_to_irq_reg(8u) )
                  {
                    v6 = 9;
                    if ( v3 != (unsigned int)cam_ife_csid_convert_res_to_irq_reg(9u) )
                    {
                      v6 = 10;
                      if ( v3 != (unsigned int)cam_ife_csid_convert_res_to_irq_reg(0xAu) )
                      {
                        v6 = 11;
                        v7 = cam_ife_csid_convert_res_to_irq_reg(0xBu);
                        if ( v3 != (_DWORD)v7 )
                        {
                          __break(0x5512u);
                          return cam_ife_csid_ver2_dump_irq_desc(v7, v8);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  v9 = *(_QWORD *)(v4 + 8 * v6 + 136);
  if ( !v9 )
  {
    v11 = 0;
    goto LABEL_20;
  }
  v10 = (unsigned int *)(v9 + 12);
LABEL_18:
  v11 = *v10;
LABEL_20:
  cam_io_w_mb(*(unsigned int *)(a2 + 12), v5 + v11);
  cam_io_w_mb(16, v5 + *(unsigned int *)(*(_QWORD *)(v4 + 120) + 80LL));
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    3,
    "cam_ife_csid_ver2_irq_inject",
    8890,
    "Injected : irq_mask %#x set_reg_offset %#x",
    *(_DWORD *)(a2 + 12),
    v11);
  return 0;
}
