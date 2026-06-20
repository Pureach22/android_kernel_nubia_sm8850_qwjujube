__int64 __fastcall cam_ife_csid_ver2_stop(__int64 a1, __int64 a2, int a3)
{
  __int64 v4; // x20
  __int64 v5; // x9
  __int64 v6; // x22
  __int64 v7; // x21
  __int64 v8; // x28
  bool v9; // w8
  __int64 v10; // x0
  __int64 v11; // x24
  __int64 v12; // x23
  __int64 v13; // x8
  __int64 v14; // x25
  __int64 v15; // x22
  int v16; // w28
  __int64 v17; // x8
  int v18; // w8
  int v19; // w9
  __int64 v20; // x0
  unsigned int v21; // w23
  int v22; // w8
  int v23; // w9
  unsigned int v24; // w28
  unsigned int *v25; // x24
  unsigned int v26; // w0
  char v27; // w8
  const char *v28; // x10
  unsigned int v29; // w7
  unsigned int v30; // w9
  unsigned int v31; // w24
  __int64 result; // x0
  const char *v33; // x5
  __int64 v34; // x6
  __int64 v35; // x2
  __int64 v36; // x4
  __int64 v37; // x0
  __int64 v38; // x1
  unsigned int v39; // w8
  unsigned int v40; // w0
  unsigned int v41; // w21
  __int64 v42; // x0
  __int64 v43; // x1
  __int64 v44; // x0
  __int64 v45; // [xsp+18h] [xbp-38h]
  __int64 v47; // [xsp+28h] [xbp-28h] BYREF
  __int64 v48; // [xsp+30h] [xbp-20h]
  _QWORD v49[3]; // [xsp+38h] [xbp-18h] BYREF

  v49[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v49[0] = 0;
  v49[1] = 0;
  v47 = 0;
  v48 = 0;
  if ( a1 && a2 && a3 == 24 )
  {
    v4 = *(_QWORD *)(a1 + 3680);
    v5 = *(_QWORD *)(v4 + 31128);
    if ( *(_DWORD *)(v5 + 92) )
    {
      if ( *(_DWORD *)(a2 + 16) )
      {
        v6 = *(_QWORD *)(v5 + 384);
        v7 = **(_QWORD **)(v4 + 31136);
        v8 = *(_QWORD *)(v7 + 128);
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_ife_csid_ver2_stop",
            7550,
            "CSID:%u num_res %d",
            *(unsigned int *)(*(_QWORD *)(v4 + 31120) + 4LL));
        *(_BYTE *)(v4 + 2148) = 0;
        v9 = 0;
        if ( *(_BYTE *)(a2 + 20) == 1 )
          v9 = *(_DWORD *)(v4 + 32240) != 2;
        v10 = *(_QWORD *)(v4 + 31128);
        *(_BYTE *)(v4 + 32254) = v9;
        mutex_lock(v10);
        v11 = **(_QWORD **)(v4 + 31136);
        v12 = *(_QWORD *)(*(_QWORD *)(v4 + 31128) + 384LL);
        v13 = *(_QWORD *)(v11 + 120);
        if ( (*(_BYTE *)(v13 + 829) & 2) == 0 )
        {
          v14 = v6;
          v45 = v8;
          if ( (*(_BYTE *)(v4 + 2158) & 1) == 0 )
          {
            if ( *(_DWORD *)(v11 + 660) )
            {
              v15 = *(_QWORD *)(v11 + 128);
              cam_io_w_mb(0, v12 + *(unsigned int *)(v15 + 8));
              if ( *(_DWORD *)(v11 + 660) >= 2u )
              {
                cam_io_w_mb(0, v12 + *(unsigned int *)(v15 + 12));
                if ( *(_DWORD *)(v11 + 660) > 2u )
                  goto LABEL_77;
              }
            }
          }
          if ( *(_DWORD *)(a2 + 16) )
          {
            v16 = 0;
            while ( 1 )
            {
              v17 = *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(a2 + 8) + 8LL * v16) + 4LL);
              if ( (unsigned int)v17 > 0xB )
                break;
              cam_io_w_mb(0, v12 + *(unsigned int *)(*(_QWORD *)(v11 + 136 + 8 * v17) + 4LL));
              if ( (unsigned int)++v16 >= *(_DWORD *)(a2 + 16) )
                goto LABEL_20;
            }
LABEL_77:
            __break(0x5512u);
          }
LABEL_20:
          cam_io_w_mb(0, v12 + *(unsigned int *)(*(_QWORD *)(v11 + 120) + 88LL));
          v13 = *(_QWORD *)(v11 + 120);
          v6 = v14;
          v8 = v45;
          if ( *(_DWORD *)(v11 + 656) >= 2u )
          {
            cam_io_w_mb(0, v12 + *(unsigned int *)(v13 + 56));
            v13 = *(_QWORD *)(v11 + 120);
          }
        }
        cam_io_w_mb(*(unsigned int *)(v13 + 804), v12 + *(unsigned int *)(v13 + 52));
        mutex_unlock(*(_QWORD *)(v4 + 31128));
        cam_ife_csid_ver2_send_cdr_sweep_csi2_rx_vals(v4, v7, 0);
        if ( *(_BYTE *)(*(_QWORD *)(v4 + 31128) + 3296LL) == 1 && (*(_BYTE *)(v4 + 32253) & 1) != 0 )
        {
          v18 = *(_DWORD *)(v4 + 32240);
          BYTE4(v48) = v18 != 2;
          if ( v18 != 2 )
          {
            v19 = *(_DWORD *)(v4 + 2080);
            LODWORD(v47) = *(_DWORD *)(v4 + 2068) - 1;
            HIDWORD(v47) = v19;
            LODWORD(v48) = 1;
            cam_subdev_notify_message(65544, 6u, (__int64)&v47);
          }
        }
        else
        {
          BYTE4(v48) = 0;
        }
        LODWORD(v49[0]) = 1;
        v20 = cam_ife_csid_ver2_reset(a1, (unsigned int *)v49);
        v21 = v20;
        if ( *(_BYTE *)(v4 + 32254) == 1 && !(_DWORD)v20 )
        {
          cam_io_w_mb(v20, v6 + *(unsigned int *)(v8 + 32));
          LODWORD(v49[0]) = 2;
          cam_ife_csid_ver2_reset(a1, (unsigned int *)v49);
          LODWORD(v49[0]) = 3;
          cam_ife_csid_ver2_reset(a1, (unsigned int *)v49);
          if ( (debug_mdl & 8) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_ife_csid_ver2_stop",
              7596,
              "CSID:%u global HW and irq reset issued at stop for standby",
              *(_DWORD *)(*(_QWORD *)(v4 + 31120) + 4LL));
        }
        v22 = *(unsigned __int8 *)(v4 + 32254);
        BYTE4(v48) = 0;
        BYTE5(v48) = v22;
        if ( v22 == 1 )
        {
          v23 = *(_DWORD *)(v4 + 2080);
          LODWORD(v47) = *(_DWORD *)(v4 + 2068) - 1;
          HIDWORD(v47) = v23;
          LODWORD(v48) = 1;
          cam_subdev_notify_message(65544, 6u, (__int64)&v47);
        }
        *(_DWORD *)(v4 + 32248) = 0;
        mutex_lock(*(_QWORD *)(v4 + 31128));
        if ( *(_DWORD *)(a2 + 16) )
        {
          v24 = 0;
          do
          {
            v25 = *(unsigned int **)(*(_QWORD *)(a2 + 8) + 8LL * (int)v24);
            v26 = cam_ife_csid_ver2_disable_path(0, v4, v25, *(_BYTE *)(a2 + 21));
            v27 = debug_mdl;
            v25[2] = 3;
            if ( (v27 & 8) != 0 && !debug_priority )
            {
              v28 = (const char *)(v25 + 32);
              v29 = *v25;
              v30 = v25[1];
              v31 = v26;
              ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                v27 & 8,
                4,
                "cam_ife_csid_ver2_stop",
                7620,
                "CSID:%u res_type %d Resource[id:%d name:%s]",
                *(_DWORD *)(*(_QWORD *)(v4 + 31120) + 4LL),
                v29,
                v30,
                v28);
              v26 = v31;
            }
            ++v24;
          }
          while ( v24 < *(_DWORD *)(a2 + 16) );
          v21 = v26;
        }
        if ( *(_DWORD *)(v4 + 32212) )
        {
          v21 = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq_evt)(*(_QWORD *)(v4 + 30984));
          v37 = *(_QWORD *)(v4 + 30984);
          v38 = *(_QWORD *)(v4 + 31112);
          *(_DWORD *)(v4 + 32212) = 0;
          ((void (__fastcall *)(__int64, __int64))cam_irq_controller_unregister_dependent)(v37, v38);
        }
        v39 = *(_DWORD *)(v7 + 656);
        if ( !v39 )
        {
          v40 = v21;
          goto LABEL_62;
        }
        if ( *(_DWORD *)(v4 + 32216) )
        {
          v40 = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq_evt)(*(_QWORD *)(v4 + 30984));
          *(_DWORD *)(v4 + 32216) = 0;
          v39 = *(_DWORD *)(v7 + 656);
          if ( v39 < 2 )
            goto LABEL_55;
        }
        else
        {
          v40 = v21;
          if ( v39 < 2 )
          {
LABEL_55:
            if ( v39 )
            {
              if ( *(_DWORD *)(v4 + 2184) )
              {
                v40 = ((__int64 (__fastcall *)(_QWORD, _QWORD))cam_irq_controller_unsubscribe_irq_evt)(
                        *(_QWORD *)(v4 + 30984),
                        *(unsigned int *)(v4 + 32224));
                *(_DWORD *)(v4 + 32224) = 0;
                v39 = *(_DWORD *)(v7 + 656);
              }
              if ( v39 >= 2 )
              {
                if ( *(_DWORD *)(v4 + 2188) )
                {
                  v40 = ((__int64 (__fastcall *)(_QWORD, _QWORD))cam_irq_controller_unsubscribe_irq_evt)(
                          *(_QWORD *)(v4 + 30992),
                          *(unsigned int *)(v4 + 32228));
                  *(_DWORD *)(v4 + 32228) = 0;
                  v39 = *(_DWORD *)(v7 + 656);
                }
                if ( v39 > 2 )
                  goto LABEL_77;
              }
            }
LABEL_62:
            if ( *(_DWORD *)(v4 + 32232) )
            {
              v40 = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq_evt)(*(_QWORD *)(v4 + 30984));
              *(_DWORD *)(v4 + 32232) = 0;
              v39 = *(_DWORD *)(v7 + 656);
            }
            v41 = v40;
            if ( v39 >= 2 && *(_DWORD *)(v4 + 32236) )
            {
              v41 = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq_evt)(*(_QWORD *)(v4 + 30984));
              v42 = *(_QWORD *)(v4 + 30984);
              v43 = *(_QWORD *)(v4 + 30992);
              *(_DWORD *)(v4 + 32236) = 0;
              ((void (__fastcall *)(__int64, __int64))cam_irq_controller_unregister_dependent)(v42, v43);
            }
            ((void (__fastcall *)(_QWORD, __int64))cam_ife_csid_ver2_disable_csi2)(0, v4);
            if ( *(_BYTE *)(v4 + 2213) == 1
              && (cam_io_w_mb(
                    0,
                    *(_QWORD *)(*(_QWORD *)(v4 + 31128) + 384LL)
                  + *(unsigned int *)(*(_QWORD *)(**(_QWORD **)(v4 + 31136) + 120LL) + 100LL)),
                  (debug_mdl & 8) != 0)
              && !debug_priority )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 8,
                4,
                "cam_ife_csid_ver2_testbus_config",
                7122,
                "CSID [%u] test_bus_ctrl: 0x%x",
                *(_DWORD *)(*(_QWORD *)(v4 + 31120) + 4LL),
                0);
              if ( (*(_BYTE *)(a2 + 21) & 1) != 0 )
                goto LABEL_72;
            }
            else if ( (*(_BYTE *)(a2 + 21) & 1) != 0 )
            {
LABEL_72:
              v44 = *(_QWORD *)(v4 + 31128);
              *(_BYTE *)(v4 + 2213) = 0;
              *(_BYTE *)(v4 + 2161) = 0;
              *(_BYTE *)(v4 + 2159) = 0;
              *(_BYTE *)(v4 + 2164) = 0;
              mutex_unlock(v44);
              result = v41;
              goto LABEL_73;
            }
            *(_BYTE *)(v4 + 2163) = 0;
            goto LABEL_72;
          }
        }
        if ( *(_DWORD *)(v4 + 32220) )
        {
          v40 = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq_evt)(*(_QWORD *)(v4 + 30992));
          *(_DWORD *)(v4 + 32220) = 0;
          v39 = *(_DWORD *)(v7 + 656);
        }
        if ( v39 > 2 )
          goto LABEL_77;
        goto LABEL_55;
      }
      v33 = "CSID:%u Invalid args";
      v34 = *(unsigned int *)(*(_QWORD *)(v4 + 31120) + 4LL);
      v35 = 1;
      v36 = 7545;
    }
    else
    {
      v33 = "CSID:%u already powered down";
      v34 = *(unsigned int *)(*(_QWORD *)(v4 + 31120) + 4LL);
      v35 = 2;
      v36 = 7538;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      8,
      v35,
      "cam_ife_csid_ver2_stop",
      v36,
      v33,
      v34);
    result = 4294967274LL;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_stop",
      7525,
      "CSID: Invalid args");
    result = 4294967274LL;
  }
LABEL_73:
  _ReadStatusReg(SP_EL0);
  return result;
}
