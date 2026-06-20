__int64 __fastcall prepare_qmi_response(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  __int64 v8; // x8
  __int64 v9; // x0
  _QWORD *v10; // x0
  __int64 v11; // x8
  unsigned __int64 v12; // x25
  int v13; // w27
  __int64 v14; // x20
  int v15; // w22
  unsigned __int8 *v16; // x9
  unsigned __int8 *v17; // x11
  unsigned __int64 v18; // x12
  unsigned __int8 *v19; // x12
  _QWORD *v20; // x28
  __int64 v21; // x12
  unsigned int v22; // w9
  char v23; // w8
  unsigned __int8 *v24; // x11
  unsigned __int8 *v25; // x12
  unsigned __int64 v26; // x13
  unsigned __int8 *v27; // x13
  unsigned __int8 *v28; // x10
  unsigned __int8 *v29; // x12
  unsigned __int64 v30; // x13
  unsigned __int8 *v31; // x13
  unsigned __int8 v32; // w8
  unsigned __int8 v33; // w8
  __int16 v34; // w8
  const char *v35; // x20
  unsigned int v36; // w20
  const char *v37; // x19
  __int64 v38; // x11
  int v39; // w9
  __int64 v40; // x10
  __int64 v41; // x9
  unsigned __int64 v42; // x20
  __int64 *v43; // x22
  char v44; // w9
  __int64 v45; // x10
  __int64 v46; // x1
  __int64 **endpoint_buffer; // x0
  unsigned __int64 v48; // x27
  __int64 v49; // x8
  unsigned __int64 v50; // x23
  __int64 v51; // x9
  __int64 v52; // x10
  __int64 v53; // x8
  __int64 *v54; // x22
  __int64 v55; // x9
  __int64 v56; // x1
  __int64 **v57; // x0
  unsigned __int64 v58; // x8
  __int64 v59; // x10
  __int64 v60; // x23
  unsigned __int8 v61; // w8
  __int16 v62; // w8
  const char *v63; // x20
  const char *v64; // x0
  char v65; // w8
  __int64 v66; // x8
  __int64 v67; // x0
  int id; // w0
  unsigned int v69; // w24
  __int64 v70; // x8
  __int64 event_buffer; // x0
  __int64 v72; // x8
  __int64 v73; // x10
  __int64 v74; // x22
  unsigned int v75; // w26
  __int64 v76; // x0
  __int64 v77; // x8
  __int64 v78; // x9
  int v79; // w22
  unsigned int v80; // w8
  __int64 v81; // x0
  __int64 v82; // x9
  __int64 v83; // x22
  __int64 v84; // x8
  __int64 v85; // x0
  int v86; // w9
  __int64 v87; // x27
  __int64 v88; // x8
  int v89; // w8
  unsigned int v91; // w8
  int v92; // w9
  unsigned int v93; // w23
  __int64 v94; // x24
  __int64 v95; // x0
  __int64 v96; // x2
  __int64 v97; // x0
  __int64 v98; // x8
  __int64 v99; // x9
  __int64 v100; // x26
  __int64 v101; // x8
  __int64 v102; // x23
  unsigned __int64 v103; // x8
  __int64 v104; // x0
  __int64 v105; // x11
  unsigned __int64 v106; // x8
  __int64 v107; // x10
  __int64 v108; // x8
  __int64 v109; // x10
  unsigned __int64 v116; // x10
  __int64 v117; // [xsp+0h] [xbp-50h]
  int v118; // [xsp+8h] [xbp-48h]
  int v119; // [xsp+14h] [xbp-3Ch]
  unsigned __int64 v120; // [xsp+18h] [xbp-38h]
  int v121; // [xsp+20h] [xbp-30h]
  __int64 v122; // [xsp+28h] [xbp-28h]
  __int64 v123; // [xsp+28h] [xbp-28h]
  _QWORD v124[2]; // [xsp+30h] [xbp-20h] BYREF
  _QWORD v125[2]; // [xsp+40h] [xbp-10h] BYREF

  v125[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 32);
  v9 = *(_QWORD *)(a1 + 8);
  v124[1] = 0;
  v125[0] = 0;
  v124[0] = 0;
  v10 = (_QWORD *)usb_ifnum_to_if(v9, *(unsigned __int8 *)(v8 + 40));
  if ( !v10 )
  {
    v63 = "%s%s: interface # %d does not exist\n";
    ipc_log_string(
      *(_QWORD *)(uaudio_svc + 24),
      "%s%s: interface # %d does not exist\n",
      (const char *)&unk_B13E,
      "prepare_qmi_response",
      *(unsigned __int8 *)(*(_QWORD *)(a1 + 32) + 40LL));
LABEL_72:
    v64 = v63;
LABEL_73:
    printk(v64, &unk_B45D);
    v36 = -19;
    goto LABEL_134;
  }
  v11 = *(_QWORD *)(a1 + 32);
  v12 = *(unsigned int *)(a2 + 4);
  v13 = *(_DWORD *)(a2 + 36);
  v14 = *v10 + 40LL * *(unsigned __int8 *)(v11 + 43);
  v15 = *(unsigned __int8 *)(v14 + 7);
  if ( v15 == 48 )
  {
    v16 = nullptr;
LABEL_12:
    if ( (unsigned int)v12 >= 0x200000 )
    {
      __break(0x5512u);
      goto LABEL_136;
    }
    v20 = &uadev[11 * HIWORD(*(_DWORD *)(a2 + 4))];
    v21 = v20[1];
    if ( v21 )
    {
      if ( v15 == 48 )
      {
        if ( *(_BYTE *)(v10[3] + 5LL) == 1 )
        {
          ipc_log_string(
            *(_QWORD *)(uaudio_svc + 24),
            "%s%s: full adc is not supported\n",
            (const char *)&unk_B13E,
            "prepare_qmi_response");
          printk("%s%s: full adc is not supported\n", &unk_B45D);
        }
        v22 = *(unsigned __int16 *)(*(_QWORD *)(v14 + 24) + 4LL);
        v23 = 2;
        if ( v22 > 0xBF )
        {
          if ( *(unsigned __int16 *)(*(_QWORD *)(v14 + 24) + 4LL) <= 0x11Fu )
          {
            if ( v22 != 192 && v22 != 196 )
              goto LABEL_121;
            goto LABEL_54;
          }
          if ( v22 != 294 && v22 != 288 )
            goto LABEL_121;
        }
        else
        {
          if ( *(unsigned __int16 *)(*(_QWORD *)(v14 + 24) + 4LL) <= 0x8Fu )
          {
            if ( v22 != 96 && v22 != 98 )
            {
LABEL_121:
              ipc_log_string(
                *(_QWORD *)(uaudio_svc + 24),
                "%s%s: %d: %u: Invalid wMaxPacketSize\n",
                (const char *)&unk_B13E,
                "prepare_qmi_response",
                *(unsigned __int8 *)(*(_QWORD *)(a1 + 32) + 40LL),
                *(unsigned __int8 *)(*(_QWORD *)(a1 + 32) + 43LL));
              printk("%s%s: %d: %u: Invalid wMaxPacketSize\n", &unk_B45D);
              v36 = -22;
              goto LABEL_134;
            }
            goto LABEL_54;
          }
          if ( v22 != 144 && v22 != 147 )
            goto LABEL_121;
        }
        v23 = 3;
LABEL_54:
        *(_BYTE *)(a3 + 77) = v23;
        *(_BYTE *)(a3 + 76) = 1;
LABEL_55:
        v38 = 1128;
        v39 = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 1488LL);
        *(_BYTE *)(a3 + 20) = 1;
        *(_DWORD *)(a3 + 24) = v39;
        LOBYTE(v39) = *(_BYTE *)(v14 + 8);
        v40 = *(_QWORD *)v14;
        *(_BYTE *)(a3 + 36) = 1;
        *(_BYTE *)(a3 + 45) = v39;
        *(_QWORD *)(a3 + 37) = v40;
        v41 = *(_QWORD *)(a1 + 104);
        v42 = *(unsigned int *)(v41 + 5584);
        if ( (v42 & 0x80) == 0 )
          v38 = 1256;
        v43 = *(__int64 **)(*(_QWORD *)(a1 + 8) + v38 + 8 * ((v42 >> 15) & 0xF));
        if ( v43 )
        {
          v44 = *((_BYTE *)v43 + 8);
          v45 = *v43;
          v46 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + v38 + 8 * ((v42 >> 15) & 0xF));
          *(_BYTE *)(a3 + 46) = 1;
          *(_BYTE *)(a3 + 56) = v44;
          *(_QWORD *)(a3 + 48) = v45;
          if ( (xhci_sideband_add_endpoint(v20[7], v46) & 0x80000000) != 0 )
          {
            dev_err(*(_QWORD *)uaudio_qdev, "failed to get data ep ring address\n");
            v36 = -19;
            goto LABEL_134;
          }
          endpoint_buffer = (__int64 **)xhci_sideband_get_endpoint_buffer(v20[7], v43);
          if ( endpoint_buffer )
          {
            v120 = v12 >> 16;
            v121 = v13;
            v48 = memstart_addr;
            v122 = **endpoint_buffer;
            *(_QWORD *)(a3 + 112) = (*endpoint_buffer)[2];
            ((void (*)(void))sg_free_table)();
            v49 = *(_QWORD *)(a1 + 112);
            if ( v49 )
            {
              v50 = *(unsigned int *)(v49 + 5584);
              v51 = 1128;
              if ( (v50 & 0x80) == 0 )
                v51 = 1256;
              v52 = (v50 >> 15) & 0xF;
              v53 = *(_QWORD *)(a1 + 8) + v51;
              v54 = *(__int64 **)(v53 + 8 * v52);
              if ( v54 )
              {
                v55 = *v54;
                v56 = *(_QWORD *)(v53 + 8 * v52);
                *(_BYTE *)(a3 + 68) = *((_BYTE *)v54 + 8);
                *(_QWORD *)(a3 + 60) = v55;
                *(_BYTE *)(a3 + 58) = 1;
                if ( (xhci_sideband_add_endpoint(v20[7], v56) & 0x80000000) == 0 )
                {
                  v57 = (__int64 **)xhci_sideband_get_endpoint_buffer(v20[7], v54);
                  if ( !v57 )
                  {
                    dev_err(*(_QWORD *)uaudio_qdev, "failed to get sync ep ring address\n");
                    goto LABEL_84;
                  }
                  v58 = memstart_addr;
                  v118 = v50;
                  v59 = **v57;
                  *(_QWORD *)(a3 + 136) = (*v57)[2];
                  v60 = ((v59 & 0x3FFFFFFFFFFFFFCLL) + ((v58 >> 6) & 0x3FFFFFFFFFFFFC0LL) + 0x140000000LL) << 6;
                  ((void (*)(void))sg_free_table)();
LABEL_79:
                  v119 = a4;
                  v65 = *(_DWORD *)(uaudio_qdev + 12);
                  *(_BYTE *)(a3 + 200) = 1;
                  *(_BYTE *)(a3 + 208) = 0;
                  *(_BYTE *)(a3 + 201) = v65;
                  v66 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 80LL) + 8LL);
                  if ( v66 )
                  {
                    v67 = *(_QWORD *)(v66 + 744);
                    if ( v67 )
                    {
                      id = of_alias_get_id(v67, "usb");
                      if ( (id & 0x80000000) == 0 )
                      {
                        *(_BYTE *)(a3 + 209) = id;
                        *(_BYTE *)(a3 + 208) = 1;
                      }
                    }
                  }
                  v69 = *(unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 80LL) + 8LL) + 844LL);
                  if ( (unsigned int)xhci_sideband_create_interrupter(
                                       v20[7],
                                       1,
                                       0,
                                       0,
                                       *(unsigned int *)(uaudio_qdev + 12)) == -12 )
                  {
LABEL_84:
                    v36 = -19;
                    v70 = *(_QWORD *)(a1 + 112);
                    if ( !v70 )
                      goto LABEL_131;
LABEL_128:
                    v106 = *(unsigned int *)(v70 + 5584);
                    v107 = 1128;
                    _ZF = (v106 & 0x80) == 0;
                    v108 = (v106 >> 15) & 0xF;
                    if ( _ZF )
                      v107 = 1256;
                    xhci_sideband_remove_endpoint(v20[7], *(_QWORD *)(*(_QWORD *)(a1 + 8) + v107 + 8 * v108));
                    goto LABEL_131;
                  }
                  event_buffer = xhci_sideband_get_event_buffer(v20[7]);
                  if ( event_buffer )
                  {
                    v72 = (memstart_addr >> 6) & 0x3FFFFFFFFFFFFC0LL;
                    v73 = **(_QWORD **)event_buffer & 0x3FFFFFFFFFFFFFCLL;
                    *(_QWORD *)(a3 + 88) = *(_QWORD *)(*(_QWORD *)event_buffer + 16LL);
                    v74 = (v73 + v72 + 0x140000000LL) << 6;
                    ((void (*)(void))sg_free_table)();
                    if ( v74 )
                    {
                      v75 = (v69 >> 5) & 1;
                      v76 = uaudio_iommu_map(0, v75, v74, 4096, 0);
                      if ( !v76 )
                      {
                        v36 = -12;
                        goto LABEL_127;
                      }
                      v77 = uaudio_qdev;
                      v78 = *(unsigned int *)(uaudio_qdev + 8);
                      *(_DWORD *)(a3 + 96) = 4096;
                      *(_QWORD *)(a3 + 80) = v76 | (v78 << 32);
                      *(_BYTE *)(v77 + 104) = 1;
                      v79 = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 28LL);
                      v80 = v79 - 1;
                      if ( (unsigned int)(v79 - 1) >= 6 || ((0x37u >> v80) & 1) == 0 )
                      {
                        ipc_log_string(
                          *(_QWORD *)(uaudio_svc + 24),
                          "%s%s: udev speed %d\n",
                          (const char *)&unk_B13E,
                          "get_speed_info",
                          v79);
                        printk("%s%s: udev speed %d\n", &unk_B45D);
                        v36 = -19;
                        *(_DWORD *)(a3 + 204) = 0;
LABEL_126:
                        uaudio_iommu_unmap(0, 4096, 4096, 4096);
LABEL_127:
                        xhci_sideband_remove_interrupter(v20[7]);
                        v70 = *(_QWORD *)(a1 + 112);
                        if ( v70 )
                          goto LABEL_128;
LABEL_131:
                        v109 = 1128;
                        if ( (*(_DWORD *)(*(_QWORD *)(a1 + 104) + 5584LL) & 0x80) == 0 )
                          v109 = 1256;
                        xhci_sideband_remove_endpoint(
                          v20[7],
                          *(_QWORD *)(*(_QWORD *)(a1 + 8)
                                    + v109
                                    + 8
                                    * (((unsigned __int64)*(unsigned int *)(*(_QWORD *)(a1 + 104) + 5584LL) >> 15) & 0xF)));
                        goto LABEL_134;
                      }
                      *(_DWORD *)(a3 + 204) = dword_AC14[v80];
                      *(_BYTE *)(a3 + 202) = 1;
                      v81 = uaudio_iommu_map(
                              1,
                              v75,
                              ((v122 & 0x3FFFFFFFFFFFFFCLL) + ((v48 >> 6) & 0x3FFFFFFFFFFFFC0LL) + 0x140000000LL) << 6,
                              4096,
                              0);
                      if ( !v81 )
                      {
LABEL_125:
                        v36 = -12;
                        goto LABEL_126;
                      }
                      v82 = *(_QWORD *)(a3 + 136);
                      v83 = v81;
                      v84 = *(unsigned int *)(uaudio_qdev + 8);
                      *(_DWORD *)(a3 + 120) = 4096;
                      *(_QWORD *)(a3 + 104) = v81 | (v84 << 32);
                      if ( v82 )
                      {
                        v85 = uaudio_iommu_map(1, v75, v60, 4096, 0);
                        v86 = v121;
                        if ( !v85 )
                        {
LABEL_124:
                          uaudio_iommu_unmap(1, v83, 4096, 4096);
                          goto LABEL_125;
                        }
                        v87 = v85;
                        v88 = *(unsigned int *)(uaudio_qdev + 8);
                        *(_DWORD *)(a3 + 144) = 4096;
                        *(_QWORD *)(a3 + 128) = v85 | (v88 << 32);
                      }
                      else
                      {
                        v86 = v121;
                        v87 = 0;
                      }
                      if ( v86 )
                        v89 = v86;
                      else
                        v89 = 4096;
                      _ZF = (v89 & 0xFFF) == 0;
                      v91 = v89 & 0xFFFFF000;
                      v92 = !_ZF;
                      v93 = v91 + (v92 << 12);
                      if ( v93 > 0x18000 )
                      {
                        ipc_log_string(
                          *(_QWORD *)(uaudio_svc + 24),
                          "%s%s: req buf len %d > max buf len %lu, setting %lu\n",
                          (const char *)&unk_B13E,
                          "prepare_qmi_response",
                          v93,
                          98304,
                          98304);
                        printk("%s%s: req buf len %d > max buf len %lu, setting %lu\n", &unk_B45D);
                        v93 = 98304;
                      }
                      v94 = v93;
                      v95 = usb_alloc_coherent(*(_QWORD *)(a1 + 8), v93, 3264, v125);
                      v96 = v95;
                      if ( v95 )
                      {
                        v123 = v95;
                        dma_get_sgtable_attrs(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 80LL) + 8LL), v124);
                        v97 = uaudio_iommu_map(2, v75, v125[0], v93, v124);
                        v96 = v123;
                        if ( v97 )
                        {
                          v98 = v125[0];
                          v99 = uaudio_qdev;
                          *(_DWORD *)(a3 + 168) = v93;
                          v100 = v97;
                          *(_QWORD *)(a3 + 160) = v98;
                          v101 = *(unsigned int *)(v99 + 8);
                          v117 = v93;
                          *(_BYTE *)(a3 + 78) = 1;
                          *(_QWORD *)(a3 + 152) = v97 | (v101 << 32);
                          sg_free_table(v124);
                          v102 = v20[10];
                          if ( *((_DWORD *)v20 + 6) != 1 )
                          {
LABEL_112:
                            v105 = v20[9];
                            *((_DWORD *)v20 + 4) = v120;
                            *((_DWORD *)v20 + 5) = *(unsigned __int8 *)(a3 + 209);
                            *(_QWORD *)(v105 + 80LL * v119) = v83;
                            *(_QWORD *)(v20[9] + 80LL * v119 + 8) = 4096;
                            *(_QWORD *)(v20[9] + 80LL * v119 + 16) = v87;
                            *(_QWORD *)(v20[9] + 80LL * v119 + 24) = 4096;
                            *(_QWORD *)(v20[9] + 80LL * v119 + 32) = v100;
                            *(_QWORD *)(v20[9] + 80LL * v119 + 48) = v125[0];
                            *(_QWORD *)(v20[9] + 80LL * v119 + 40) = v117;
                            *(_DWORD *)(v20[9] + 80LL * v119 + 56) = v42;
                            *(_DWORD *)(v20[9] + 80LL * v119 + 60) = v118;
                            *(_QWORD *)(v20[9] + 80LL * v119 + 64) = v123;
                            *(_BYTE *)(v20[9] + 80LL * v119 + 73) = BYTE2(v12);
                            *(_BYTE *)(v20[9] + 80LL * v119 + 74) = BYTE1(v12);
                            *(_BYTE *)(v20[9] + 80LL * v119 + 75) = *(_DWORD *)(a1 + 24);
                            *(_BYTE *)(v20[9] + 80LL * v119 + 72) = *(_BYTE *)(*(_QWORD *)(a1 + 32) + 40LL);
                            *(_BYTE *)(v20[9] + 80LL * v119 + 76) = 1;
                            v11 = 1LL << SBYTE2(v12);
                            v16 = (unsigned __int8 *)uaudio_qdev;
                            goto LABEL_137;
                          }
                          _init_waitqueue_head(v20 + 4, "&uadev[card_num].disconnect_wq", &prepare_qmi_response___key);
                          *((_DWORD *)v20 + 16) = *(unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 1112LL) + 4LL);
                          v103 = *((int *)v20 + 16);
                          if ( is_mul_ok(v103, 0x50u) )
                          {
                            v104 = _kmalloc_noprof(80 * v103, 3520);
                            v94 = v117;
                            v96 = v123;
                            v20[9] = v104;
                            if ( v104 )
                            {
                              mutex_lock(v102 + 160);
                              v11 = v12 >> 16;
                              if ( (_DWORD)v120 != 32 )
                              {
                                *v20 = *(_QWORD *)(a1 + 8);
                                mutex_unlock(v102 + 160);
                                goto LABEL_112;
                              }
LABEL_136:
                              __break(1u);
LABEL_137:
                              _X9 = (unsigned __int64 *)(v16 + 96);
                              __asm { PRFM            #0x11, [X9] }
                              do
                                v116 = __ldxr(_X9);
                              while ( __stxr(v116 | v11, _X9) );
                              v36 = 0;
                              goto LABEL_134;
                            }
                          }
                          else
                          {
                            v94 = v117;
                            v96 = v123;
                            v20[9] = 0;
                          }
                        }
                      }
                      usb_free_coherent(*(_QWORD *)(a1 + 8), v94, v96, v125[0]);
                      uaudio_iommu_unmap(1, v87, 4096, 4096);
                      goto LABEL_124;
                    }
                    dev_err(*(_QWORD *)uaudio_qdev, "failed to get sec event ring address\n");
                  }
                  else
                  {
                    dev_err(*(_QWORD *)uaudio_qdev, "failed to get event ring address\n");
                  }
                  v36 = -19;
                  goto LABEL_127;
                }
                dev_err(*(_QWORD *)uaudio_qdev, "failed to get sync ep ring address\n");
LABEL_114:
                v36 = -19;
                goto LABEL_131;
              }
              ipc_log_string(
                *(_QWORD *)(uaudio_svc + 24),
                "%s%s: implicit fb on data ep\n",
                (const char *)&unk_B13E,
                "prepare_qmi_response");
              printk("%s%s: implicit fb on data ep\n", &unk_B8A7);
            }
            v60 = 0;
            v118 = 0;
            goto LABEL_79;
          }
          dev_err(*(_QWORD *)uaudio_qdev, "failed to get data ep ring address\n");
          goto LABEL_114;
        }
        v63 = "%s%s: data ep # %d context is null\n";
        ipc_log_string(
          *(_QWORD *)(uaudio_svc + 24),
          "%s%s: data ep # %d context is null\n",
          (const char *)&unk_B13E,
          "prepare_qmi_response",
          *(_DWORD *)(v41 + 32));
        goto LABEL_72;
      }
      v24 = *(unsigned __int8 **)(v21 + 16);
      v25 = &v24[*(int *)(v21 + 12)];
      if ( v25 > v24 )
      {
        do
        {
          v26 = *v24;
          if ( v26 < 2 )
            break;
          v27 = &v24[v26];
          if ( v27 > v25 )
            break;
          if ( v24[1] == 36 && v24[2] == 1 )
          {
            if ( !v24 )
              break;
            if ( v15 == 32 )
            {
              v61 = v16[4];
              *(_BYTE *)(a3 + 76) = 1;
              *(_BYTE *)(a3 + 77) = v61;
              v62 = *(_WORD *)(v24 + 3);
              *(_BYTE *)(a3 + 70) = 1;
              *(_WORD *)(a3 + 72) = v62;
              goto LABEL_55;
            }
            if ( *(_BYTE *)(v14 + 7) )
            {
              ipc_log_string(
                *(_QWORD *)(uaudio_svc + 24),
                "%s%s: unknown protocol version %x\n",
                (const char *)&unk_B13E,
                "prepare_qmi_response",
                v15);
              v64 = "%s%s: unknown protocol version %x\n";
              goto LABEL_73;
            }
            v28 = *(unsigned __int8 **)(v14 + 16);
            v29 = &v28[*(int *)(v14 + 12)];
            if ( v29 > v28 )
            {
              do
              {
                v30 = *v28;
                if ( v30 < 2 )
                  break;
                v31 = &v28[v30];
                if ( v31 > v29 )
                  break;
                if ( v28[1] == 36 && v28[2] == 1 )
                {
                  if ( !v28 )
                    break;
                  v32 = v28[4];
                  *(_BYTE *)(a3 + 74) = 1;
                  *(_BYTE *)(a3 + 75) = v32;
                  v33 = v16[5];
                  *(_BYTE *)(a3 + 76) = 1;
                  *(_BYTE *)(a3 + 77) = v33;
                  v34 = *(_WORD *)(v24 + 3);
                  *(_BYTE *)(a3 + 70) = 1;
                  *(_WORD *)(a3 + 72) = v34;
                  goto LABEL_55;
                }
                v28 = v31;
              }
              while ( v31 < v29 );
            }
            v35 = "%s%s: %u:%d : no UAC_AS_GENERAL desc\n";
            ipc_log_string(
              *(_QWORD *)(uaudio_svc + 24),
              "%s%s: %u:%d : no UAC_AS_GENERAL desc\n",
              &unk_B13E,
              "prepare_qmi_response",
              *(unsigned __int8 *)(v11 + 40));
            goto LABEL_46;
          }
          v24 = v27;
        }
        while ( v27 < v25 );
      }
      v37 = "%s%s: no UAC_HEADER desc\n";
      ipc_log_string(*(_QWORD *)(uaudio_svc + 24), "%s%s: no UAC_HEADER desc\n", &unk_B13E, "prepare_qmi_response");
    }
    else
    {
      v37 = "%s%s: audio ctrl intf info not cached\n";
      ipc_log_string(
        *(_QWORD *)(uaudio_svc + 24),
        "%s%s: audio ctrl intf info not cached\n",
        &unk_B13E,
        "prepare_qmi_response");
    }
    printk(v37, &unk_B45D);
    v36 = -19;
    goto LABEL_134;
  }
  v16 = *(unsigned __int8 **)(v14 + 16);
  v17 = &v16[*(int *)(v14 + 12)];
  if ( v17 > v16 )
  {
    do
    {
      v18 = *v16;
      if ( v18 < 2 )
        break;
      v19 = &v16[v18];
      if ( v19 > v17 )
        break;
      if ( v16[1] == 36 && v16[2] == 2 )
      {
        if ( !v16 )
          break;
        goto LABEL_12;
      }
      v16 = v19;
    }
    while ( v19 < v17 );
  }
  v35 = "%s%s: %u:%d : no UAC_FORMAT_TYPE desc\n";
  ipc_log_string(
    *(_QWORD *)(uaudio_svc + 24),
    "%s%s: %u:%d : no UAC_FORMAT_TYPE desc\n",
    &unk_B13E,
    "prepare_qmi_response",
    *(unsigned __int8 *)(v11 + 40));
LABEL_46:
  printk(v35, &unk_B45D);
  v36 = -19;
LABEL_134:
  _ReadStatusReg(SP_EL0);
  return v36;
}
