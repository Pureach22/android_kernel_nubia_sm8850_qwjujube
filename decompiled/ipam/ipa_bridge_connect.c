__int64 __fastcall ipa_bridge_connect(unsigned int a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  unsigned int v4; // w21
  __int64 v5; // x9
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x8
  unsigned int v9; // w0
  int v10; // w8
  unsigned int v11; // w0
  int v12; // w9
  unsigned int v13; // w0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x9
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 result; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  unsigned int v28; // w19
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // [xsp+8h] [xbp-208h] BYREF
  __int64 v38; // [xsp+10h] [xbp-200h]
  __int64 v39; // [xsp+18h] [xbp-1F8h]
  __int128 v40; // [xsp+20h] [xbp-1F0h]
  __int64 v41; // [xsp+30h] [xbp-1E0h]
  __int64 v42; // [xsp+38h] [xbp-1D8h]
  __int64 v43; // [xsp+40h] [xbp-1D0h]
  __int64 v44; // [xsp+48h] [xbp-1C8h]
  __int64 v45; // [xsp+50h] [xbp-1C0h]
  __int64 v46; // [xsp+58h] [xbp-1B8h]
  __int64 v47; // [xsp+60h] [xbp-1B0h]
  __int64 v48; // [xsp+68h] [xbp-1A8h]
  __int64 v49; // [xsp+70h] [xbp-1A0h]
  __int64 v50; // [xsp+78h] [xbp-198h]
  __int64 v51; // [xsp+80h] [xbp-190h]
  __int64 v52; // [xsp+88h] [xbp-188h]
  __int64 v53; // [xsp+90h] [xbp-180h]
  __int64 v54; // [xsp+98h] [xbp-178h]
  __int64 v55; // [xsp+A0h] [xbp-170h]
  __int64 v56; // [xsp+A8h] [xbp-168h]
  __int64 v57; // [xsp+B0h] [xbp-160h]
  __int64 v58; // [xsp+B8h] [xbp-158h]
  __int64 v59; // [xsp+C0h] [xbp-150h]
  __int64 v60; // [xsp+C8h] [xbp-148h]
  __int64 v61; // [xsp+D0h] [xbp-140h]
  __int64 (__fastcall *v62)(); // [xsp+D8h] [xbp-138h]
  __int64 v63; // [xsp+E0h] [xbp-130h]
  __int64 v64; // [xsp+E8h] [xbp-128h]
  __int64 v65; // [xsp+F0h] [xbp-120h]
  __int64 v66; // [xsp+F8h] [xbp-118h]
  __int64 v67; // [xsp+100h] [xbp-110h]
  __int64 v68; // [xsp+108h] [xbp-108h] BYREF
  int v69; // [xsp+110h] [xbp-100h]
  __int64 v70; // [xsp+114h] [xbp-FCh]
  int v71; // [xsp+11Ch] [xbp-F4h]
  __int64 v72; // [xsp+120h] [xbp-F0h]
  __int64 v73; // [xsp+128h] [xbp-E8h]
  __int64 v74; // [xsp+130h] [xbp-E0h]
  __int64 v75; // [xsp+138h] [xbp-D8h]
  __int64 v76; // [xsp+140h] [xbp-D0h]
  __int64 v77; // [xsp+148h] [xbp-C8h]
  __int64 v78; // [xsp+150h] [xbp-C0h]
  __int64 v79; // [xsp+158h] [xbp-B8h]
  __int64 v80; // [xsp+160h] [xbp-B0h]
  __int64 v81; // [xsp+168h] [xbp-A8h]
  __int64 v82; // [xsp+170h] [xbp-A0h]
  __int64 v83; // [xsp+178h] [xbp-98h]
  __int64 v84; // [xsp+180h] [xbp-90h]
  __int64 v85; // [xsp+188h] [xbp-88h]
  __int64 v86; // [xsp+190h] [xbp-80h]
  __int64 v87; // [xsp+198h] [xbp-78h]
  __int64 v88; // [xsp+1A0h] [xbp-70h]
  __int64 v89; // [xsp+1A8h] [xbp-68h]
  __int64 v90; // [xsp+1B0h] [xbp-60h]
  __int64 v91; // [xsp+1B8h] [xbp-58h]
  __int64 v92; // [xsp+1C0h] [xbp-50h]
  __int64 v93; // [xsp+1C8h] [xbp-48h]
  __int64 v94; // [xsp+1D0h] [xbp-40h]
  __int64 (__fastcall *v95)(); // [xsp+1D8h] [xbp-38h]
  __int64 v96; // [xsp+1E0h] [xbp-30h]
  __int64 v97; // [xsp+1E8h] [xbp-28h]
  __int64 v98; // [xsp+1F0h] [xbp-20h]
  __int64 v99; // [xsp+1F8h] [xbp-18h]
  __int64 v100; // [xsp+200h] [xbp-10h]
  __int64 v101; // [xsp+208h] [xbp-8h]

  v101 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !ipa_gsb_ctx )
  {
    printk(&unk_3C85BE, "ipa_bridge_connect");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_gsb %s:%d ipa_gsb_ctx was not initialized\n", "ipa_bridge_connect", 856);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipa_gsb %s:%d ipa_gsb_ctx was not initialized\n", "ipa_bridge_connect", 856);
      result = 4294967282LL;
      goto LABEL_32;
    }
    goto LABEL_47;
  }
  if ( a1 < 5 )
  {
    if ( ipa3_get_ipc_logbuf() )
    {
      v2 = ipa3_get_ipc_logbuf();
      ipc_log_string(v2, "ipa_gsb %s:%d client hdl: %d\n", "ipa_bridge_connect", 865, a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v3 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v3, "ipa_gsb %s:%d client hdl: %d\n", "ipa_bridge_connect", 865, a1);
    }
    v4 = a1;
    mutex_lock(ipa_gsb_ctx + 48LL * a1 + 136);
    v5 = *(_QWORD *)(ipa_gsb_ctx + 8LL * a1 + 96);
    if ( v5 )
    {
      if ( *(_BYTE *)(v5 + 104) == 1 )
      {
        if ( ipa3_get_ipc_logbuf() )
        {
          v6 = ipa3_get_ipc_logbuf();
          ipc_log_string(v6, "ipa_gsb %s:%d iface was already connected\n", "ipa_bridge_connect", 875);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v7 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v7, "ipa_gsb %s:%d iface was already connected\n", "ipa_bridge_connect", 875);
        }
LABEL_31:
        mutex_unlock(ipa_gsb_ctx + 48LL * a1 + 136);
        result = 0;
        goto LABEL_32;
      }
      mutex_lock(ipa_gsb_ctx + 16);
      v8 = ipa_gsb_ctx;
      if ( !*(_DWORD *)(ipa_gsb_ctx + 88) )
      {
        v9 = ipa_pm_activate_sync(*(_DWORD *)(ipa_gsb_ctx + 396));
        if ( v9 )
        {
          v28 = v9;
          printk(&unk_3F97C6, "ipa_bridge_connect");
          if ( ipa3_get_ipc_logbuf() )
          {
            v29 = ipa3_get_ipc_logbuf();
            ipc_log_string(v29, "ipa_gsb %s:%d failed to activate ipa pm\n", "ipa_bridge_connect", 884);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v30 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v30, "ipa_gsb %s:%d failed to activate ipa pm\n", "ipa_bridge_connect", 884);
          }
        }
        else
        {
          v94 = 0;
          v93 = 38;
          v77 = 0;
          v78 = 0;
          v79 = 0;
          v80 = 0;
          v81 = 0;
          v82 = 0;
          v83 = 0;
          v84 = 0;
          v85 = 0;
          v86 = 0;
          v87 = 0;
          v88 = 0;
          v89 = 0;
          v90 = 0;
          v91 = 0;
          v92 = 0;
          v95 = nullptr;
          v96 = 0;
          v97 = 0;
          v98 = 0;
          v99 = 0;
          v100 = 0;
          v66 = 0;
          v67 = 0;
          v64 = 0;
          v65 = 0;
          v62 = nullptr;
          v63 = 0;
          v60 = 0;
          v61 = 0;
          v58 = 0;
          v59 = 0;
          v56 = 0;
          v57 = 0;
          v54 = 0;
          v55 = 0;
          v52 = 0;
          v53 = 0;
          v50 = 0;
          v51 = 0;
          v48 = 0;
          v49 = 0;
          v46 = 0;
          v47 = 0;
          v44 = 0;
          v45 = 0;
          v68 = 0;
          v69 = 0;
          v71 = 0;
          v72 = 0;
          v73 = 0;
          v74 = 0;
          v75 = 0;
          v76 = 0;
          v70 = 0x100000012LL;
          v10 = *(_DWORD *)(ipa_gsb_ctx + 72);
          v42 = 0;
          v43 = 0;
          HIDWORD(v93) = v10;
          v41 = 0;
          v39 = 0;
          v40 = 0u;
          v37 = 0;
          v38 = 0;
          LODWORD(v68) = 1;
          v95 = ipa_gsb_tx_dp_notify;
          v11 = ipa_setup_sys_pipe((__int64)&v68, (unsigned int *)(ipa_gsb_ctx + 64));
          if ( v11 )
          {
            v28 = v11;
            printk(&unk_3F643A, "ipa_gsb_connect_sys_pipe");
            if ( ipa3_get_ipc_logbuf() )
            {
              v31 = ipa3_get_ipc_logbuf();
              ipc_log_string(
                v31,
                "ipa_gsb %s:%d fail to setup prod sys pipe %d\n",
                "ipa_gsb_connect_sys_pipe",
                808,
                v28);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v32 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(
                v32,
                "ipa_gsb %s:%d fail to setup prod sys pipe %d\n",
                "ipa_gsb_connect_sys_pipe",
                808,
                v28);
            }
          }
          else
          {
            LODWORD(v60) = 39;
            *(_QWORD *)((char *)&v40 + 4) = 0x200000001LL;
            LODWORD(v42) = 2;
            BYTE1(v44) = 1;
            v48 = 0x400000001LL;
            v49 = 0x3E80000000ELL;
            v12 = *(_DWORD *)(ipa_gsb_ctx + 72);
            HIDWORD(v38) = 60;
            LODWORD(v37) = 0;
            HIDWORD(v60) = v12;
            v61 = 0;
            v62 = ipa_gsb_cons_cb;
            v13 = ipa_setup_sys_pipe((__int64)&v37, (unsigned int *)(ipa_gsb_ctx + 68));
            if ( !v13 )
            {
              if ( ipa3_get_ipc_logbuf() )
              {
                v14 = ipa3_get_ipc_logbuf();
                ipc_log_string(
                  v14,
                  "ipa_gsb %s:%d prod_hdl = %d, cons_hdl = %d\n",
                  "ipa_gsb_connect_sys_pipe",
                  840,
                  *(_DWORD *)(ipa_gsb_ctx + 64),
                  *(_DWORD *)(ipa_gsb_ctx + 68));
              }
              if ( ipa3_get_ipc_logbuf_low() )
              {
                v15 = ipa3_get_ipc_logbuf_low();
                ipc_log_string(
                  v15,
                  "ipa_gsb %s:%d prod_hdl = %d, cons_hdl = %d\n",
                  "ipa_gsb_connect_sys_pipe",
                  840,
                  *(_DWORD *)(ipa_gsb_ctx + 64),
                  *(_DWORD *)(ipa_gsb_ctx + 68));
              }
              v8 = ipa_gsb_ctx;
              goto LABEL_22;
            }
            v28 = v13;
            printk(&unk_3E4D85, "ipa_gsb_connect_sys_pipe");
            if ( ipa3_get_ipc_logbuf() )
            {
              v33 = ipa3_get_ipc_logbuf();
              ipc_log_string(
                v33,
                "ipa_gsb %s:%d fail to setup cons sys pipe %d\n",
                "ipa_gsb_connect_sys_pipe",
                835,
                v28);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v34 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(
                v34,
                "ipa_gsb %s:%d fail to setup cons sys pipe %d\n",
                "ipa_gsb_connect_sys_pipe",
                835,
                v28);
            }
            ipa_teardown_sys_pipe(*(_DWORD *)(ipa_gsb_ctx + 64));
            *(_DWORD *)(ipa_gsb_ctx + 64) = 0;
          }
          printk(&unk_3D9AD2, "ipa_bridge_connect");
          if ( ipa3_get_ipc_logbuf() )
          {
            v35 = ipa3_get_ipc_logbuf();
            ipc_log_string(v35, "ipa_gsb %s:%d fail to connect pipe\n", "ipa_bridge_connect", 891);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v36 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v36, "ipa_gsb %s:%d fail to connect pipe\n", "ipa_bridge_connect", 891);
          }
        }
        mutex_unlock(ipa_gsb_ctx + 16);
        mutex_unlock(ipa_gsb_ctx + 48LL * v4 + 136);
        result = v28;
        goto LABEL_32;
      }
LABEL_22:
      v16 = v8 + 8LL * a1;
      *(_BYTE *)(*(_QWORD *)(v16 + 96) + 104LL) = 1;
      *(_BYTE *)(*(_QWORD *)(v16 + 96) + 105LL) = 1;
      ++*(_DWORD *)(v8 + 88);
      if ( ipa3_get_ipc_logbuf() )
      {
        v17 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v17,
          "ipa_gsb %s:%d connected iface: %d\n",
          "ipa_bridge_connect",
          904,
          *(_DWORD *)(ipa_gsb_ctx + 88));
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v18 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v18,
          "ipa_gsb %s:%d connected iface: %d\n",
          "ipa_bridge_connect",
          904,
          *(_DWORD *)(ipa_gsb_ctx + 88));
      }
      ++*(_DWORD *)(ipa_gsb_ctx + 92);
      if ( ipa3_get_ipc_logbuf() )
      {
        v19 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v19,
          "ipa_gsb %s:%d num resumed iface: %d\n",
          "ipa_bridge_connect",
          907,
          *(_DWORD *)(ipa_gsb_ctx + 92));
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v20 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v20,
          "ipa_gsb %s:%d num resumed iface: %d\n",
          "ipa_bridge_connect",
          907,
          *(_DWORD *)(ipa_gsb_ctx + 92));
      }
      mutex_unlock(ipa_gsb_ctx + 16);
      goto LABEL_31;
    }
    printk(&unk_3AB2AC, "ipa_bridge_connect");
    if ( ipa3_get_ipc_logbuf() )
    {
      v26 = ipa3_get_ipc_logbuf();
      ipc_log_string(v26, "ipa_gsb %s:%d fail to find interface, hdl: %d\n", "ipa_bridge_connect", 869, a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v27 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v27, "ipa_gsb %s:%d fail to find interface, hdl: %d\n", "ipa_bridge_connect", 869, a1);
    }
    mutex_unlock(ipa_gsb_ctx + 48LL * a1 + 136);
LABEL_47:
    result = 4294967282LL;
    goto LABEL_32;
  }
  printk(&unk_3E7C9B, "ipa_bridge_connect");
  if ( ipa3_get_ipc_logbuf() )
  {
    v24 = ipa3_get_ipc_logbuf();
    ipc_log_string(v24, "ipa_gsb %s:%d invalid hdl: %d\n", "ipa_bridge_connect", 861, a1);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v25 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v25, "ipa_gsb %s:%d invalid hdl: %d\n", "ipa_bridge_connect", 861, a1);
  }
  result = 4294967274LL;
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
