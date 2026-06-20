__int64 __fastcall hw_fence_utils_process_signaled_clients_mask(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  __int64 v6; // x21
  unsigned int v7; // w22
  __int64 v8; // x27
  __int64 v9; // x25
  unsigned int v10; // w8
  unsigned int v11; // w24
  __int64 v12; // x26
  unsigned int v13; // w19
  int v14; // w24
  unsigned __int64 v15; // x28
  unsigned int *v16; // x0
  int v17; // w26
  __int64 v18; // x8
  _BOOL8 v19; // x4
  __int64 v21; // x30
  const char *v22; // x1
  __int64 v23; // x2
  __int64 v24; // x3
  __int64 v25; // x4
  __int64 v26; // x30
  void *v27; // x0
  const char *v28; // x1
  __int64 v29; // x2
  __int64 v30; // x4
  __int64 v31; // x30
  __int64 v32; // [xsp+10h] [xbp-50h]
  __int64 v33; // [xsp+18h] [xbp-48h] BYREF
  __int64 v34; // [xsp+20h] [xbp-40h]
  __int64 v35; // [xsp+28h] [xbp-38h]
  __int64 v36; // [xsp+30h] [xbp-30h]
  __int64 v37; // [xsp+38h] [xbp-28h]
  unsigned __int64 v38; // [xsp+40h] [xbp-20h]
  __int64 v39; // [xsp+48h] [xbp-18h]
  __int64 v40; // [xsp+50h] [xbp-10h]
  __int64 v41; // [xsp+58h] [xbp-8h]

  v6 = result;
  v7 = 0;
  v8 = result + 0x8000;
  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  do
  {
    v9 = 1 << v7;
    if ( (a2 & v9) != 0 )
    {
      if ( (~msm_hw_fence_debug_level & 0x10001) != 0
        || (printk(&unk_29260, "hw_fence_utils_process_signaled_clients_mask", 513, v7, a2),
            (~msm_hw_fence_debug_level & 0x10001) != 0) )
      {
        if ( !v7 )
          goto LABEL_17;
      }
      else
      {
        printk(&unk_26C70, "_process_signaled_client_id", 477, v7, a5);
        if ( !v7 )
        {
LABEL_17:
          v13 = 0;
          v39 = 0;
          v40 = 0;
          v37 = 0;
          v38 = 0;
          v35 = 0;
          v36 = 0;
          v33 = 0;
          v34 = 0;
          while ( 1 )
          {
            result = hw_fence_read_queue_helper(v6, v6 + 264, &v33, a4, a5);
            if ( (result & 0x80000000) != 0 )
            {
              if ( (~msm_hw_fence_debug_level & 0x10010) == 0 )
                result = printk(&unk_25CE0, "_process_ctrl_rx_queue", 448, a4, a5);
              goto LABEL_69;
            }
            v14 = result;
            if ( (unsigned int)WORD2(v33) - 3 < 2 )
              break;
            if ( WORD2(v33) == 33 )
            {
              if ( v6 )
              {
                if ( (*(_BYTE *)(v8 + 752) & 1) != 0 )
                {
                  v19 = *(_DWORD *)(v8 + 908) > 1u;
                  if ( HIDWORD(v35) == v19 && !(_DWORD)v34 )
                  {
                    if ( (~msm_hw_fence_debug_level & 0x10002) == 0 )
                    {
                      printk(&unk_24B11, "_process_power_state_soccp_payload", 432, 33, v19);
                      LOBYTE(v19) = HIDWORD(v35) != 0;
                    }
                    *(_BYTE *)(v8 + 904) = v19;
                    v18 = 33736;
LABEL_45:
                    result = _wake_up(v6 + v18, 3, 0, 0);
                    v17 = 0;
                    goto LABEL_46;
                  }
                  result = printk(
                             &unk_27429,
                             "_process_power_state_soccp_payload",
                             427,
                             v32,
                             *(_DWORD *)(v8 + 908) > 1u);
                  goto LABEL_65;
                }
                v31 = v32;
              }
              else
              {
                v31 = v32;
              }
              v22 = "_process_power_state_soccp_payload";
              v23 = 418;
              v24 = v31;
              v25 = v6;
              goto LABEL_58;
            }
            if ( WORD2(v33) != 2 )
            {
              v26 = v32;
              v27 = &unk_237B7;
              v28 = "_process_ctrl_rx_queue";
              v29 = 464;
              v30 = WORD2(v33);
LABEL_63:
              result = printk(v27, v28, v29, v26, v30);
              goto LABEL_65;
            }
            if ( !v6 )
            {
              result = printk(&unk_232C5, "_process_fence_error_payload", 346, v32, 0);
LABEL_65:
              v17 = -22;
              goto LABEL_46;
            }
            v15 = v38;
            if ( v38 && v38 < *(unsigned int *)(v6 + 60) )
            {
              if ( (~msm_hw_fence_debug_level & 0x10010) == 0 )
                printk(&unk_26CAD, "_process_fence_error_payload", 360, v36, v34);
              mutex_lock(v6 + 680);
              v16 = *(unsigned int **)(*(_QWORD *)(v6 + 728) + 8 * v15);
              if ( v16 )
              {
                v17 = hw_fence_utils_fence_error_cb(v16, v34, v35, v36, v37, v39);
                if ( v17 )
                  printk(&unk_21FD5, "_process_fence_error_payload", 375, v32, (unsigned int)v15);
                result = mutex_unlock(v6 + 680);
                goto LABEL_46;
              }
              printk(&unk_2A47D, "_process_fence_error_payload", 366, v32, (unsigned int)v15);
              result = mutex_unlock(v6 + 680);
            }
            else
            {
              result = printk(&unk_27A99, "_process_fence_error_payload", 354, v32, v38);
            }
            v17 = -22;
LABEL_46:
            if ( v14 )
            {
              if ( v13++ < 0x63 )
                continue;
            }
            if ( !v17 )
              goto LABEL_69;
            v12 = v32;
LABEL_14:
            result = printk(&unk_25FC5, "hw_fence_utils_process_signaled_clients_mask", 517, v12, v7);
            goto LABEL_69;
          }
          if ( v6 )
          {
            if ( (*(_BYTE *)(v8 + 752) & 1) != 0 )
            {
              if ( WORD2(v33) != 4 || *(_DWORD *)(v8 + 992) )
              {
                if ( (~msm_hw_fence_debug_level & 0x10008) == 0 )
                  printk(&unk_22917, "_process_init_soccp_payload", 402, WORD2(v33), a5);
                v18 = 33712;
                *(_BYTE *)(v6 + 736) = 1;
                goto LABEL_45;
              }
              v26 = v32;
              v27 = &unk_288BE;
              v28 = "_process_init_soccp_payload";
              v29 = 398;
              v30 = 4;
              goto LABEL_63;
            }
            v21 = v32;
          }
          else
          {
            v21 = v32;
          }
          v22 = "_process_init_soccp_payload";
          v23 = 391;
          v24 = v21;
          v25 = v6;
LABEL_58:
          result = printk(&unk_23C30, v22, v23, v24, v25);
          goto LABEL_65;
        }
      }
      v10 = *(_DWORD *)(v6 + 740);
      if ( *(_BYTE *)(v8 + 752) )
        v11 = v7 + v10 - 21;
      else
        v11 = v7;
      if ( v10 > v11 || v11 >= v10 + 11 || (result = process_validation_client_loopback(v6, v11), (_DWORD)result) )
      {
        v12 = v32;
        printk(&unk_20D24, "_process_signaled_client_id", 496, v32, v11);
        goto LABEL_14;
      }
LABEL_69:
      a2 &= ~v9;
      if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
      {
        result = printk(&unk_27988, "hw_fence_utils_process_signaled_clients_mask", 522, v7, a2);
        if ( !a2 )
          break;
        goto LABEL_3;
      }
      if ( !a2 )
        break;
    }
LABEL_3:
    ++v7;
  }
  while ( v7 != 33 );
  _ReadStatusReg(SP_EL0);
  return result;
}
