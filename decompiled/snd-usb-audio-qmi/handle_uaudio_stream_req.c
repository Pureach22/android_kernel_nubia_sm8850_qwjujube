__int64 __fastcall handle_uaudio_stream_req(__int64 a1, unsigned __int16 *a2, __int64 a3, unsigned __int8 *a4)
{
  int data_interval_from_si; // w25
  __int64 v8; // x28
  __int64 v9; // x21
  __int64 v10; // x0
  __int64 v11; // x9
  __int64 v12; // x7
  unsigned int v13; // w26
  __int64 v14; // x23
  __int64 v15; // x24
  __int64 *v16; // x8
  unsigned int v17; // w23
  __int64 v18; // x24
  _DWORD *v19; // x23
  int v20; // w8
  int v21; // w20
  __int64 v22; // x19
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 result; // x0
  int v26; // w8
  __int64 v27; // x9
  _QWORD *v28; // x10
  int v29; // w8
  unsigned int v30; // w25
  unsigned int v31; // w24
  unsigned int v32; // w23
  const char *v33; // x0
  unsigned int v34; // w4
  unsigned int v35; // w14
  __int64 v36; // x25
  _QWORD *v37; // x10
  _QWORD *v38; // x9
  _QWORD *v39; // x8
  _QWORD *v40; // x8
  const void ***v41; // x27
  __int64 v42; // x8
  int v43; // w10
  _QWORD *v44; // x12
  __int64 v45; // x11
  _BYTE *v46; // x12
  const void **v47; // x5
  unsigned int v48; // w26
  __int64 v49; // x27
  unsigned __int64 v50; // x8
  __int64 v51; // x10
  __int64 v52; // x8
  __int64 v53; // x9
  __int64 v54; // x26
  unsigned int v55; // w0
  int v56; // w0
  unsigned __int64 v57; // x8
  __int64 v58; // x10
  __int64 v59; // x8
  __int64 v60; // x9
  __int64 v61; // x26
  unsigned int v68; // w8
  unsigned int v69; // w8
  unsigned int v72; // w9
  unsigned int v75; // w10
  int v76; // [xsp+0h] [xbp-130h]
  int v77; // [xsp+8h] [xbp-128h]
  __int64 **v78; // [xsp+20h] [xbp-110h]
  _QWORD *v79; // [xsp+28h] [xbp-108h]
  unsigned int v80; // [xsp+30h] [xbp-100h]
  __int64 v81; // [xsp+38h] [xbp-F8h]
  __int64 v82; // [xsp+40h] [xbp-F0h]
  __int64 v83; // [xsp+48h] [xbp-E8h] BYREF
  __int64 v84; // [xsp+50h] [xbp-E0h]
  __int64 v85; // [xsp+58h] [xbp-D8h]
  __int64 v86; // [xsp+60h] [xbp-D0h]
  __int64 v87; // [xsp+68h] [xbp-C8h]
  __int64 v88; // [xsp+70h] [xbp-C0h]
  __int64 v89; // [xsp+78h] [xbp-B8h]
  __int64 v90; // [xsp+80h] [xbp-B0h]
  __int64 v91; // [xsp+88h] [xbp-A8h]
  __int64 v92; // [xsp+90h] [xbp-A0h]
  __int64 v93; // [xsp+98h] [xbp-98h]
  __int64 v94; // [xsp+A0h] [xbp-90h]
  __int64 v95; // [xsp+A8h] [xbp-88h]
  __int64 v96; // [xsp+B0h] [xbp-80h]
  __int64 v97; // [xsp+B8h] [xbp-78h]
  __int64 v98; // [xsp+C0h] [xbp-70h]
  __int64 v99; // [xsp+C8h] [xbp-68h]
  __int64 v100; // [xsp+D0h] [xbp-60h]
  __int64 v101; // [xsp+D8h] [xbp-58h]
  __int64 v102; // [xsp+E0h] [xbp-50h]
  __int64 v103; // [xsp+E8h] [xbp-48h]
  __int64 v104; // [xsp+F0h] [xbp-40h]
  __int64 v105; // [xsp+F8h] [xbp-38h]
  __int64 v106; // [xsp+100h] [xbp-30h]
  __int64 v107; // [xsp+108h] [xbp-28h]
  __int64 v108; // [xsp+110h] [xbp-20h]
  __int64 v109; // [xsp+118h] [xbp-18h]
  __int64 v110; // [xsp+120h] [xbp-10h]

  v110 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = uaudio_svc;
  v108 = 0;
  v109 = 0;
  v106 = 0;
  v107 = 0;
  v104 = 0;
  v105 = 0;
  v102 = 0;
  v103 = 0;
  v100 = 0;
  v101 = 0;
  v98 = 0;
  v99 = 0;
  v96 = 0;
  v97 = 0;
  v94 = 0;
  v95 = 0;
  v92 = 0;
  v93 = 0;
  v90 = 0;
  v91 = 0;
  v88 = 0;
  v89 = 0;
  v86 = 0;
  v87 = 0;
  v84 = 0;
  v85 = 0;
  v83 = 0;
  v9 = ((__int64 (*)(void))ktime_get)();
  ipc_log_string(
    *(_QWORD *)(uaudio_svc + 24),
    "%s%s: sq_node:%x sq_port:%x sq_family:%x\n",
    (const char *)&unk_B13E,
    "handle_uaudio_stream_req",
    *((_DWORD *)a2 + 1),
    *((_DWORD *)a2 + 2),
    *a2);
  v10 = printk("%s%s: sq_node:%x sq_port:%x sq_family:%x\n", &unk_B8A7);
  if ( (*(_BYTE *)(v8 + 20) & 1) == 0 )
  {
    v11 = *(_QWORD *)a2;
    *(_DWORD *)(v8 + 16) = *((_DWORD *)a2 + 2);
    *(_QWORD *)(v8 + 8) = v11;
    *(_BYTE *)(v8 + 20) = 1;
  }
  if ( a4[8] && a4[24] && a4[16] && a4[32] )
  {
    v26 = *((_DWORD *)a4 + 1);
    LODWORD(v15) = BYTE2(v26);
    if ( BYTE2(v26) >= 0x20u )
      goto LABEL_80;
    v81 = a3;
    v27 = uadev[11 * BYTE2(v26) + 10];
    if ( v27 && !*(_DWORD *)(v27 + 216) )
    {
      if ( *(_DWORD *)(v27 + 344) <= (unsigned int)BYTE1(v26) )
      {
        printk(&unk_B155, "find_substream");
      }
      else
      {
        if ( (unsigned __int8)*((_DWORD *)a4 + 1) < 2u )
        {
          v37 = (_QWORD *)(v27 + 280);
          v38 = (_QWORD *)(v27 + 280);
          do
          {
            v38 = (_QWORD *)*v38;
            if ( v38 == v37 )
              goto LABEL_27;
          }
          while ( *((_DWORD *)v38 - 106) != BYTE1(v26) );
          v78 = (__int64 **)&v38[26 * (unsigned __int8)*((_DWORD *)a4 + 1) - 52];
LABEL_28:
          v80 = v15;
          v28 = &uadev[11 * (unsigned int)v15];
          v29 = *((_DWORD *)a4 + 1);
          v30 = BYTE2(v29);
          v31 = BYTE1(v29);
          v79 = v28;
          v32 = (unsigned __int8)v29;
          v82 = v28[10];
          ipc_log_string(
            *(_QWORD *)(uaudio_svc + 24),
            "%s%s: card#:%d dev#:%d dir:%d en:%d fmt:%d rate:%d #ch:%d\n",
            (const char *)&unk_B13E,
            "check_valid_request",
            BYTE2(v29),
            BYTE1(v29),
            (unsigned __int8)v29,
            *a4,
            *((_DWORD *)a4 + 3),
            *((_DWORD *)a4 + 7),
            *((_DWORD *)a4 + 5));
          v77 = *((_DWORD *)a4 + 5);
          v76 = *((_DWORD *)a4 + 7);
          printk("%s%s: card#:%d dev#:%d dir:%d en:%d fmt:%d rate:%d #ch:%d\n", &unk_B6EF);
          if ( v30 >= 0x20 )
          {
            ipc_log_string(
              *(_QWORD *)(uaudio_svc + 24),
              "%s%s: invalid card # %u",
              (const char *)&unk_B13E,
              "check_valid_request",
              v30);
            v33 = "%s%s: invalid card # %u";
LABEL_32:
            printk(v33, &unk_B45D);
            LODWORD(v15) = -22;
            data_interval_from_si = -22;
            goto LABEL_45;
          }
          v34 = *((_DWORD *)a4 + 3);
          if ( v34 >= 0x12 )
          {
            ipc_log_string(
              *(_QWORD *)(uaudio_svc + 24),
              "%s%s: unsupported pcm format received %d\n",
              (const char *)&unk_B13E,
              "check_valid_request",
              v34);
            v33 = "%s%s: unsupported pcm format received %d\n";
            goto LABEL_32;
          }
          v35 = v30;
          v36 = uadev[11 * v30 + 10];
          if ( v36 && !*(_DWORD *)(v36 + 216) )
          {
            if ( *(_DWORD *)(v36 + 344) <= v31 )
            {
              printk(&unk_B155, "find_substream");
            }
            else if ( v32 < 2 )
            {
              v39 = (_QWORD *)(v36 + 280);
              do
              {
                v39 = (_QWORD *)*v39;
                if ( v39 == (_QWORD *)(v36 + 280) )
                  goto LABEL_43;
              }
              while ( *((_DWORD *)v39 - 106) != v31 );
              v40 = &v39[26 * v32];
              v41 = (const void ***)(v40 - 52);
              if ( v40 != qword_1A0 )
              {
                if ( !*(_DWORD *)(v36 + 216) )
                {
                  v42 = *(v40 - 48);
                  if ( v42 )
                    v43 = *(unsigned __int8 *)(v42 + 40);
                  else
                    v43 = -1;
                  if ( !*a4 || uadev[11 * v35 + 9] )
                  {
                    v44 = &uadev[11 * v35];
                    v45 = *((unsigned int *)v44 + 16);
                    if ( (int)v45 >= 1 )
                    {
                      v15 = 0;
                      v46 = (_BYTE *)(v44[9] + 76LL);
                      do
                      {
                        if ( *a4 )
                        {
                          if ( (*v46 & 1) == 0 )
                            goto LABEL_66;
                        }
                        else if ( v43 == (unsigned __int8)*(v46 - 4) )
                        {
                          goto LABEL_66;
                        }
                        ++v15;
                        v46 += 80;
                      }
                      while ( v45 != v15 );
                    }
                    LODWORD(v15) = -22;
                  }
                  else
                  {
                    LODWORD(v15) = 0;
                  }
LABEL_66:
                  v47 = *v41;
                  if ( !*(_DWORD *)(v36 + 216) && v47 && v47[1] && *v47 )
                  {
                    if ( *a4 && (v15 & 0x80000000) != 0 )
                    {
                      ipc_log_string(
                        *(_QWORD *)(uaudio_svc + 24),
                        "%s%s: interface# %d already in use card# %d\n",
                        (const char *)&unk_B13E,
                        "check_valid_request",
                        *(unsigned __int8 *)(v42 + 40),
                        v35);
                      printk("%s%s: interface# %d already in use card# %d\n", &unk_B45D);
                      data_interval_from_si = -16;
                    }
                    else
                    {
                      if ( !a4[40] )
                      {
                        data_interval_from_si = 0;
                        goto LABEL_82;
                      }
                      v48 = *((_DWORD *)a4 + 11);
                      data_interval_from_si = get_data_interval_from_si(v78, v48);
                      v10 = *(_QWORD *)(uaudio_svc + 24);
                      if ( data_interval_from_si != -22 )
                        goto LABEL_81;
                      ipc_log_string(
                        v10,
                        "%s%s: invalid service interval %u\n",
                        (const char *)&unk_B13E,
                        "handle_uaudio_stream_req",
                        v48);
                      printk("%s%s: invalid service interval %u\n", &unk_B45D);
                      data_interval_from_si = -22;
                    }
                  }
                  else
                  {
                    ipc_log_string(
                      *(_QWORD *)(uaudio_svc + 24),
                      "%s%s: chip or sub not available: shutdown:%d stream:%p\n",
                      (const char *)&unk_B13E,
                      "check_valid_request",
                      *(_DWORD *)(v36 + 216),
                      v47);
                    printk("%s%s: chip or sub not available: shutdown:%d stream:%p\n", &unk_B45D);
                    if ( *v41 )
                    {
                      ipc_log_string(
                        *(_QWORD *)(uaudio_svc + 24),
                        "%s%s: pcm:%p chip:%p\n",
                        (const char *)&unk_B13E,
                        "check_valid_request",
                        (*v41)[1],
                        **v41);
                      printk("%s%s: pcm:%p chip:%p\n", &unk_B45D);
                    }
                    data_interval_from_si = -19;
                  }
                  goto LABEL_45;
                }
                ipc_log_string(
                  *(_QWORD *)(uaudio_svc + 24),
                  "%s%s: can't find substream for card# %u, dev# %u dir%u\n",
                  (const char *)&unk_B13E,
                  "check_valid_request",
                  v35,
                  v31,
                  v32);
                printk("%s%s: can't find substream for card# %u, dev# %u dir%u\n", &unk_B45D);
                data_interval_from_si = -19;
LABEL_44:
                LODWORD(v15) = -22;
                goto LABEL_45;
              }
            }
            else
            {
              printk(&unk_B311, "find_substream");
            }
          }
LABEL_43:
          ipc_log_string(
            *(_QWORD *)(uaudio_svc + 24),
            "%s%s: invalid substream\n",
            (const char *)&unk_B13E,
            "check_valid_request");
          printk("%s%s: invalid substream\n", &unk_B45D);
          data_interval_from_si = -14;
          goto LABEL_44;
        }
        printk(&unk_B311, "find_substream");
      }
    }
LABEL_27:
    v78 = nullptr;
    goto LABEL_28;
  }
  ipc_log_string(
    *(_QWORD *)(uaudio_svc + 24),
    "%s%s: invalid request msg\n",
    (const char *)&unk_B13E,
    "handle_uaudio_stream_req");
  printk("%s%s: invalid request msg\n", &unk_B45D);
  v13 = 0;
  v14 = 0;
  LODWORD(v15) = -22;
  data_interval_from_si = -22;
  while ( !*a4 && data_interval_from_si != -22 && data_interval_from_si != -19 )
  {
    v82 = v14;
    v10 = mutex_lock(v14 + 160);
    if ( (v15 & 0x80000000) != 0 )
    {
      if ( v13 <= 0x1F )
      {
        v17 = v13;
LABEL_16:
        v19 = &uadev[11 * v17];
        _X9 = v19 + 6;
        __asm { PRFM            #0x11, [X9] }
        do
        {
          v68 = __ldxr(_X9);
          v69 = v68 - 1;
        }
        while ( __stlxr(v69, _X9) );
        __dmb(0xBu);
        if ( !v69 )
        {
          ipc_log_string(
            *(_QWORD *)(uaudio_svc + 24),
            "%s%s: for dev %pK\n",
            (const char *)&unk_B13E,
            "uaudio_dev_release",
            v19);
          printk("%s%s: for dev %pK\n", &unk_B8A7);
          uaudio_event_ring_cleanup_free((__int64)v19);
          v19[6] = 0;
          _wake_up(v19 + 8, 3, 1, 0);
        }
        mutex_unlock(v82 + 160);
        break;
      }
    }
    else if ( v13 <= 0x1F )
    {
      v16 = &uadev[11 * v13];
      v17 = v13;
      v18 = v16[9] + 80LL * (unsigned int)v15;
      uaudio_dev_intf_cleanup(*v16, v18);
      ipc_log_string(
        *(_QWORD *)(uaudio_svc + 24),
        "%s%s: release resources: intf# %d card# %d\n",
        (const char *)&unk_B13E,
        "handle_uaudio_stream_req",
        *(unsigned __int8 *)(v18 + 72),
        v13);
      printk("%s%s: release resources: intf# %d card# %d\n", &unk_B8A7);
      goto LABEL_16;
    }
LABEL_80:
    __break(0x5512u);
LABEL_81:
    ipc_log_string(
      v10,
      "%s%s: data interval %u\n",
      (const char *)&unk_B13E,
      "handle_uaudio_stream_req",
      data_interval_from_si);
    printk("%s%s: data interval %u\n", &unk_B8A7);
LABEL_82:
    v79[1] = *(_QWORD *)(v82 + 408);
    if ( *a4 )
    {
      mutex_lock(v82 + 160);
      _X8 = (unsigned int *)(v79 + 3);
      __asm { PRFM            #0x11, [X8] }
      do
        v72 = __ldxr(_X8);
      while ( __stxr(v72 + 1, _X8) );
      mutex_unlock(v82 + 160);
      v55 = map_pcm_format(*((unsigned int *)a4 + 3));
      v56 = enable_audio_stream(v78, v55, *((unsigned int *)a4 + 5), *((unsigned int *)a4 + 7));
      if ( v56 )
      {
        data_interval_from_si = v56;
        ipc_log_string(
          *(_QWORD *)(uaudio_svc + 24),
          "%s%s: enable_audio_stream failed %d\n",
          (const char *)&unk_B13E,
          "handle_uaudio_stream_req",
          v56);
        printk("%s%s: enable_audio_stream failed %d\n", &unk_B8A7);
      }
      else
      {
        data_interval_from_si = prepare_qmi_response(v78, a4, &v83, (unsigned int)v15);
        if ( !data_interval_from_si )
          goto LABEL_45;
      }
      mutex_lock(v82 + 160);
      ipc_log_string(
        *(_QWORD *)(uaudio_svc + 24),
        "%s%s: enable process failed %d\n",
        (const char *)&unk_B13E,
        "handle_uaudio_stream_req",
        data_interval_from_si);
      printk("%s%s: enable process failed %d\n", &unk_B8A7);
      _X8 = (unsigned int *)(v79 + 3);
      __asm { PRFM            #0x11, [X8] }
      do
        v75 = __ldxr(_X8);
      while ( __stxr(v75 - 1, _X8) );
      v14 = v82;
      mutex_unlock(v82 + 160);
      v13 = v80;
      a3 = v81;
    }
    else
    {
      v49 = v79[9] + 80LL * (int)v15;
      v50 = *(unsigned int *)(v49 + 56);
      if ( (_DWORD)v50 )
      {
        v51 = 1128;
        v52 = (v50 >> 15) & 0xF;
        if ( (*(_DWORD *)(v49 + 56) & 0x80) == 0 )
          v51 = 1256;
        v53 = *v79 + v51;
        v54 = *(_QWORD *)(v53 + 8 * v52);
        if ( v54 )
        {
          xhci_sideband_stop_endpoint(v79[7], *(_QWORD *)(v53 + 8 * v52));
          xhci_sideband_remove_endpoint(v79[7], v54);
        }
        else
        {
          ipc_log_string(
            *(_QWORD *)(uaudio_svc + 24),
            "%s%s: no data ep\n",
            (const char *)&unk_B13E,
            "handle_uaudio_stream_req");
          printk("%s%s: no data ep\n", &unk_B8A7);
        }
        *(_DWORD *)(v49 + 56) = 0;
      }
      v57 = *(unsigned int *)(v49 + 60);
      if ( (_DWORD)v57 )
      {
        v58 = 1128;
        v59 = (v57 >> 15) & 0xF;
        if ( (*(_DWORD *)(v49 + 60) & 0x80) == 0 )
          v58 = 1256;
        v60 = *v79 + v58;
        v61 = *(_QWORD *)(v60 + 8 * v59);
        if ( v61 )
        {
          xhci_sideband_stop_endpoint(v79[7], *(_QWORD *)(v60 + 8 * v59));
          xhci_sideband_remove_endpoint(v79[7], v61);
        }
        else
        {
          ipc_log_string(
            *(_QWORD *)(uaudio_svc + 24),
            "%s%s: no sync ep\n",
            (const char *)&unk_B13E,
            "handle_uaudio_stream_req");
          printk("%s%s: no sync ep\n", &unk_B8A7);
        }
        *(_DWORD *)(v49 + 60) = 0;
      }
      disable_audio_stream(v78);
LABEL_45:
      v13 = v80;
      a3 = v81;
      v14 = v82;
    }
  }
  v20 = *((_DWORD *)a4 + 1);
  LODWORD(v85) = data_interval_from_si;
  LODWORD(v87) = v20;
  BYTE4(v86) = 1;
  BYTE4(v84) = 1;
  LODWORD(v84) = data_interval_from_si != 0;
  BYTE4(v83) = 1;
  v21 = qmi_send_response(*(_QWORD *)v8, a2, a3, 1, 202, &qmi_uaudio_stream_resp_msg_v01_ei, &v83, v12, v76, v77);
  v22 = *(_QWORD *)(uaudio_svc + 24);
  v23 = ((__int64 (*)(void))ktime_get)();
  v24 = ipc_log_string(
          v22,
          "%s%s: ret %d: qmi response latency %lld ms\n",
          (const char *)&unk_B13E,
          "handle_uaudio_stream_req",
          v21,
          (v23 - v9) / 1000000);
  ktime_get(v24);
  result = printk("%s%s: ret %d: qmi response latency %lld ms\n", &unk_B8A7);
  _ReadStatusReg(SP_EL0);
  return result;
}
