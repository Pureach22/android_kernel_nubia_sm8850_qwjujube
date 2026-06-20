__int64 __fastcall dsi_panel_read_cmd_set(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x22
  __int64 v6; // x0
  unsigned int v7; // w21
  __int64 v8; // x1
  int v9; // w0
  __int64 v10; // x8
  int v11; // w10
  __int64 v12; // x20
  __int64 *v13; // x23
  _QWORD *v14; // x8
  __int16 v15; // w9
  int v16; // w0
  unsigned int v17; // w19
  int v18; // w21

  result = 4294967274LL;
  if ( a1 )
  {
    if ( a2 )
    {
      v4 = *(_QWORD *)(a1 + 1208);
      if ( v4 )
      {
        if ( v4 != 1264 )
        {
          if ( (*(_BYTE *)(a1 + 1973) & 1) != 0 )
          {
            if ( (*(_BYTE *)a2 & 1) != 0 )
            {
              v6 = dsi_display_clk_ctrl(*(_QWORD *)(v4 + 56), 3, 1);
              v7 = *(_DWORD *)(v4 - 424);
              if ( v7 >= 3 )
              {
                __break(0x5512u);
                return dsi_display_cmd_engine_enable(v6);
              }
              else
              {
                if ( (unsigned int)dsi_display_cmd_engine_enable(v4 - 1264) )
                {
                  printk(&unk_26E1EF, v8);
                  v18 = -1;
                }
                else
                {
                  if ( !*(_QWORD *)(v4 - 40) && (v9 = dsi_host_alloc_cmd_tx_buffer(v4 - 1264)) != 0 )
                  {
                    v18 = v9;
                    printk(&unk_251674, v8);
                  }
                  else if ( *(_DWORD *)(a2 + 16) )
                  {
                    v10 = a2;
                    v11 = *(_DWORD *)(a2 + 12);
                    v12 = *(_QWORD *)(a2 + 24);
                    v13 = (__int64 *)(v4 + 48LL * v7 - 1096);
                    if ( !v11 )
                      *(_WORD *)(v12 + 2) |= 2u;
                    *(_QWORD *)(v10 + 56) = 0;
                    v14 = (_QWORD *)(v10 + 56);
                    v14[30] = 0;
                    v14[31] = 0;
                    v14[28] = 0;
                    v14[29] = 0;
                    v14[26] = 0;
                    v14[27] = 0;
                    v14[24] = 0;
                    v14[25] = 0;
                    v14[22] = 0;
                    v14[23] = 0;
                    v14[20] = 0;
                    v14[21] = 0;
                    v14[18] = 0;
                    v14[19] = 0;
                    v14[16] = 0;
                    v14[17] = 0;
                    v14[14] = 0;
                    v14[15] = 0;
                    v14[12] = 0;
                    v14[13] = 0;
                    v14[10] = 0;
                    v14[11] = 0;
                    v14[8] = 0;
                    v14[9] = 0;
                    v14[6] = 0;
                    v14[7] = 0;
                    v14[4] = 0;
                    v14[5] = 0;
                    v14[2] = 0;
                    v14[3] = 0;
                    v14[1] = 0;
                    v15 = *(_WORD *)(v12 + 2);
                    *(_QWORD *)(v12 + 32) = v14;
                    *(_WORD *)(v12 + 2) = v15 | 0x80;
                    *(_QWORD *)(v12 + 24) = *((unsigned int *)v14 - 2);
                    *(_DWORD *)(v12 + 52) = 1;
                    dsi_display_set_cmd_tx_ctrl_flags(v4 - 1264, v12);
                    v16 = dsi_ctrl_transfer_prepare(*v13, *(_DWORD *)(v12 + 52));
                    if ( v16 )
                    {
                      v17 = v16;
                      drm_dev_printk(
                        0,
                        &unk_248D72,
                        "*ERROR* [msm-dsi-error]: prepare for rx cmd transfer failed rc=%d\n",
                        v16);
                      return v17;
                    }
                    v18 = dsi_ctrl_cmd_transfer(*v13, (char *)v12, 0);
                    if ( v18 <= 0 )
                      printk(&unk_213EFB, (unsigned int)v18);
                    else
                      dsi_ctrl_transfer_unprepare(*v13, *(_DWORD *)(v12 + 52));
                  }
                  else
                  {
                    printk(&unk_21B3C2, v8);
                    v18 = 0;
                  }
                  ((void (__fastcall *)(__int64))dsi_display_cmd_engine_disable)(v4 - 1264);
                }
                dsi_display_clk_ctrl(*(_QWORD *)(v4 + 56), 3, 0);
                return (unsigned int)v18;
              }
            }
            else
            {
              printk(&unk_25FFCB, a2);
              return 0xFFFFFFFFLL;
            }
          }
          else
          {
            printk(&unk_27527B, a2);
            return 4294967274LL;
          }
        }
      }
    }
  }
  return result;
}
