__int64 __fastcall mhi_sat_process_worker(__int64 a1)
{
  __int64 v2; // x20
  bool v3; // zf
  int v4; // w8
  __int64 v5; // x9
  _QWORD *v6; // x10
  _QWORD *v7; // x11
  __int64 result; // x0
  _QWORD *v9; // x20
  __int64 *v10; // x24
  __int64 v11; // x23
  __int16 v12; // w8
  __int64 v13; // x1
  __int16 v14; // w9
  __int16 v15; // w10
  __int16 v16; // w8
  __int64 v17; // x8
  __int16 v18; // w11
  _QWORD *v19; // x8
  _QWORD *v20; // x25
  unsigned int v21; // w8
  int v22; // w21
  __int64 *v23; // x22
  unsigned int v24; // w9
  bool v25; // zf
  int v26; // w8
  int v27; // w8
  unsigned int v28; // w27
  __int64 *v29; // x23
  int v30; // w0
  int v31; // w23
  const char *v32; // x6
  const char **v33; // x28
  __int64 v34; // x0
  _QWORD *v35; // x27
  __int64 v36; // x1
  __int64 v37; // x26
  int v38; // w8
  char v39; // w0
  char v40; // w28
  int v41; // w26
  __int64 v42; // x28
  const char *v43; // x7
  int v44; // w27
  __int64 *v45; // x23
  __int64 v46; // x9
  int v47; // w27
  __int64 v48; // x28
  __int64 v49; // x26
  __int64 v50; // x8
  __int64 *v51; // x23
  const char *v52; // x8
  __int64 v53; // x0
  int v54; // w0
  int v55; // w23
  const char *v56; // x7
  int v57; // w9
  __int64 v58; // x0
  const char *v59; // x0
  const char *v60; // x2
  _QWORD *v61; // x1
  unsigned __int64 v62; // [xsp+10h] [xbp-C0h]
  __int64 v63; // [xsp+18h] [xbp-B8h]
  int v64; // [xsp+24h] [xbp-ACh]
  _QWORD *v65; // [xsp+28h] [xbp-A8h]
  const char **v66; // [xsp+30h] [xbp-A0h]
  __int64 v67; // [xsp+30h] [xbp-A0h]
  __int64 v68; // [xsp+38h] [xbp-98h]
  _QWORD *v69; // [xsp+40h] [xbp-90h]
  __int64 v70; // [xsp+48h] [xbp-88h]
  unsigned int v71; // [xsp+50h] [xbp-80h]
  int v72; // [xsp+54h] [xbp-7Ch]
  __int64 v73; // [xsp+58h] [xbp-78h]
  _QWORD *v74; // [xsp+60h] [xbp-70h] BYREF
  _QWORD **v75; // [xsp+68h] [xbp-68h]
  _QWORD *v76; // [xsp+70h] [xbp-60h] BYREF
  const char *v77; // [xsp+78h] [xbp-58h]
  __int64 v78; // [xsp+80h] [xbp-50h]
  __int64 v79; // [xsp+88h] [xbp-48h]
  _QWORD v80[4]; // [xsp+90h] [xbp-40h] BYREF
  __int64 v81; // [xsp+B0h] [xbp-20h]
  int v82; // [xsp+B8h] [xbp-18h]
  __int64 v83; // [xsp+C0h] [xbp-10h]

  v83 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 - 144);
  v74 = &v74;
  v75 = &v74;
  v68 = a1 - 168;
  v3 = a1 == 168 || v2 == 0;
  v4 = !v3;
  v64 = v4;
  if ( !v3 )
    ipc_log_string(
      *(_QWORD *)(v2 + 88),
      "%s[I][%s][%x] Entered\n",
      (const char *)&unk_8360,
      "mhi_sat_process_worker",
      *(_DWORD *)(a1 + 64));
  v63 = v2;
  raw_spin_lock_irq(a1 - 40);
  v5 = *(_QWORD *)(a1 - 56);
  if ( v5 != a1 - 56 )
  {
    v6 = v75;
    v7 = *(_QWORD **)(a1 - 48);
    *(_QWORD *)(v5 + 8) = v75;
    *v6 = v5;
    *v7 = &v74;
    v75 = (_QWORD **)v7;
    *(_QWORD *)(a1 - 56) = a1 - 56;
    *(_QWORD *)(a1 - 48) = a1 - 56;
  }
  result = raw_spin_unlock_irq(a1 - 40);
  v9 = v74;
  if ( v74 == &v74 )
    goto LABEL_109;
  v10 = (__int64 *)(a1 - 136);
  v73 = a1 - 104;
  v65 = (_QWORD *)(a1 - 120);
  _ReadStatusReg(SP_EL0);
  while ( 2 )
  {
    v20 = (_QWORD *)*v9;
    v19 = (_QWORD *)v9[1];
    v11 = v9[3];
    if ( (_QWORD *)*v19 == v9 && (_QWORD *)v20[1] == v9 )
    {
      v20[1] = v19;
      *v19 = v20;
    }
    else
    {
      _list_del_entry_valid_or_report(v9);
    }
    *v9 = 0xDEAD000000000100LL;
    v9[1] = 0xDEAD000000000122LL;
    if ( *(_DWORD *)(a1 + 92) != 1 )
      goto LABEL_18;
    v21 = *(unsigned __int16 *)(v11 + 10);
    if ( v21 < 0x10 )
      goto LABEL_14;
    v22 = 0;
    v23 = (__int64 *)(v11 + 24);
    v24 = v21 >> 4;
    v69 = *(_QWORD **)(a1 - 144);
    v70 = v11;
    if ( v68 )
      v25 = *(_QWORD *)(a1 - 144) == 0;
    else
      v25 = 1;
    v26 = !v25;
    v71 = v24;
    v72 = v26;
    while ( 1 )
    {
      v27 = *((_DWORD *)v23 + 3);
      if ( BYTE2(v27) <= 0x63u )
      {
        if ( BYTE2(v27) == 16 )
        {
          v44 = HIBYTE(v27);
          mutex_lock(v73);
          v45 = (__int64 *)(a1 - 136);
          do
          {
            v45 = (__int64 *)*v45;
            if ( v45 == v10 )
            {
              mutex_unlock(v73);
              goto LABEL_98;
            }
          }
          while ( *(_DWORD *)(v45[2] + 964) != v44 );
          mutex_unlock(v73);
          if ( v45 )
          {
            if ( (v45[4] & 1) == 0 )
              __break(0x800u);
            mhi_unprepare_from_transfer(v45[2]);
            *((_BYTE *)v45 + 32) = 0;
            if ( v72 )
              ipc_log_string(
                v69[11],
                "%s[I][%s][%x] RESET CHANNEL %d CMD successful\n",
                (const char *)&unk_8360,
                "mhi_sat_process_cmds",
                *(_DWORD *)(a1 + 64),
                v44);
            v11 = v70;
            *v23 = 0;
            v23[1] = 0x21000001000000LL;
            goto LABEL_33;
          }
LABEL_98:
          if ( v72 )
            ipc_log_string(
              v69[11],
              "%s[I][%s][%x] Failed to find the satellite device with id : %d\n",
              (const char *)&unk_8360,
              "mhi_sat_process_cmds",
              *(_DWORD *)(a1 + 64),
              v44);
          goto LABEL_13;
        }
        if ( BYTE2(v27) == 18 )
        {
          v28 = HIBYTE(v27);
          mutex_lock(v73);
          v29 = (__int64 *)(a1 - 136);
          do
          {
            v29 = (__int64 *)*v29;
            if ( v29 == v10 )
            {
              mutex_unlock(v73);
              goto LABEL_105;
            }
          }
          while ( *(_DWORD *)(v29[2] + 964) != v28 );
          mutex_unlock(v73);
          if ( v29 )
          {
            if ( *((_BYTE *)v29 + 32) == 1 )
              __break(0x800u);
            v30 = mhi_prepare_for_transfer(v29[2]);
            if ( v30 )
            {
              v31 = 0;
              if ( v72 )
                goto LABEL_45;
            }
            else
            {
              *((_BYTE *)v29 + 32) = 1;
              v31 = 0x1000000;
              if ( v72 )
              {
LABEL_45:
                if ( v30 )
                  v32 = "failure";
                else
                  v32 = "successful";
                ipc_log_string(
                  v69[11],
                  "%s[I][%s][%x] START CHANNEL %d CMD %s\n",
                  &unk_8360,
                  "mhi_sat_process_cmds",
                  *(unsigned int *)(a1 + 64),
                  v28,
                  v32);
              }
            }
            *v23 = 0;
            *((_DWORD *)v23 + 2) = v31;
            *((_DWORD *)v23 + 3) = 2162688;
            v11 = v70;
            goto LABEL_33;
          }
LABEL_105:
          if ( v72 )
            ipc_log_string(
              v69[11],
              "%s[I][%s][%x] Failed to find the satellite device with id : %d\n",
              (const char *)&unk_8360,
              "mhi_sat_process_cmds",
              *(_DWORD *)(a1 + 64),
              v28);
          goto LABEL_13;
        }
LABEL_31:
        if ( v72 )
        {
          printk(&unk_8780, "mhi_sat_process_cmds", *v69, *(unsigned int *)(a1 + 64));
          v11 = v70;
          ipc_log_string(
            v69[11],
            "%s[E][%s][%x] Unhandled MHI satellite command!",
            (const char *)&unk_8360,
            "mhi_sat_process_cmds",
            *(_DWORD *)(a1 + 64));
        }
        goto LABEL_33;
      }
      if ( BYTE2(v27) == 100 )
        break;
      if ( BYTE2(v27) != 101 )
        goto LABEL_31;
      v33 = *(const char ***)(*(_QWORD *)(*(_QWORD *)(a1 - 152) + 16LL) + 136LL);
      v34 = _kmalloc_cache_noprof(_mhi_driver_register, 2080, 64);
      v35 = (_QWORD *)v34;
      if ( v34 )
      {
        v36 = *v23;
        *(_QWORD *)(v34 + 40) = *v23;
        v37 = *((unsigned int *)v23 + 2);
        *(_QWORD *)(v34 + 48) = v37;
        v38 = *((_DWORD *)v23 + 3);
        *(_BYTE *)(v34 + 56) = v38 & 1;
        if ( (v38 & 1) != 0 )
        {
          v58 = dma_map_resource(v33, v36, v37, 0, 0);
        }
        else
        {
          v66 = v33;
          v62 = v36 - memstart_addr;
          v39 = is_vmalloc_addr((v36 - memstart_addr) | 0xFFFFFF8000000000LL);
          v40 = v39;
          if ( (v39 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
          {
            dma_map_single_attrs___already_done = 1;
            v59 = (const char *)dev_driver_string(v66);
            v60 = v66[14];
            if ( !v60 )
              v60 = *v66;
            _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v59, v60);
            __break(0x800u);
            if ( (v40 & 1) != 0 )
              goto LABEL_57;
          }
          else if ( (v39 & 1) != 0 )
          {
LABEL_57:
            kfree(v35);
            goto LABEL_58;
          }
          v58 = dma_map_page_attrs(v66, ((v62 >> 6) & 0x1FFFFFFC0LL) - 0x140000000LL, v62 & 0xFFF, v37, 0, 32);
        }
        v42 = v58;
        if ( v58 != -1 )
        {
          v35[4] = v58;
          mutex_lock(v73);
          v61 = *(_QWORD **)(a1 - 112);
          if ( v35 == v65 || v61 == v35 || (_QWORD *)*v61 != v65 )
          {
            _list_add_valid_or_report(v35, v61);
          }
          else
          {
            *(_QWORD *)(a1 - 112) = v35;
            *v35 = v65;
            v35[1] = v61;
            *v61 = v35;
          }
          mutex_unlock(v73);
          v41 = 0x1000000;
          v43 = "successful";
          if ( !v72 )
            goto LABEL_60;
LABEL_59:
          ipc_log_string(
            v69[11],
            "%s[I][%s][%x] IOMMU MAP 0x%llx len:%d CMD %s:%llx\n",
            (const char *)&unk_8360,
            "mhi_sat_process_cmds",
            *(_DWORD *)(a1 + 64),
            *v23,
            *((_DWORD *)v23 + 2),
            v43,
            v42);
          goto LABEL_60;
        }
        goto LABEL_57;
      }
LABEL_58:
      v41 = 0;
      v42 = -1;
      v43 = "failed";
      if ( v72 )
        goto LABEL_59;
LABEL_60:
      *v23 = v42;
      *((_DWORD *)v23 + 2) = v41;
      *((_DWORD *)v23 + 3) = 2162688;
LABEL_33:
      ++v22;
      v23 += 2;
      if ( v22 == v71 )
        goto LABEL_14;
    }
    v46 = *v23;
    v47 = HIBYTE(v27);
    v48 = *((unsigned int *)v23 + 2);
    v82 = 0;
    v49 = v27 & 1;
    v67 = v46;
    v81 = 0;
    v79 = 0;
    memset(v80, 0, sizeof(v80));
    v77 = nullptr;
    v78 = 0;
    v76 = nullptr;
    mutex_lock(v73);
    v50 = 968;
    if ( !(_DWORD)v49 )
      v50 = 964;
    v51 = (__int64 *)(a1 - 136);
    do
    {
      v51 = (__int64 *)*v51;
      if ( v51 == v10 )
      {
        mutex_unlock(v73);
        goto LABEL_102;
      }
    }
    while ( *(_DWORD *)(v51[2] + v50) != v47 );
    mutex_unlock(v73);
    if ( v51 )
    {
      v80[0] = 0xA00000000LL;
      LODWORD(v80[1]) = 0;
      HIDWORD(v80[3]) = 0;
      *(_QWORD *)((char *)&v80[1] + 4) = v67;
      v82 = 0;
      v81 = 0;
      *(_QWORD *)((char *)&v80[2] + 4) = v48;
      v78 = 0;
      v79 = 44;
      v52 = sat_ctxt_str[v49];
      v53 = v51[2];
      v76 = v80;
      v77 = v52;
      v54 = mhi_device_configure(v53, 0, &v76, 1);
      v55 = v54 == 0;
      if ( v72 )
      {
        if ( v54 )
          v56 = "failed";
        else
          v56 = "successful";
        ipc_log_string(
          v69[11],
          "%s[I][%s][%x] CTXT UPDATE CMD %s:%d %s\n",
          (const char *)&unk_8360,
          "mhi_sat_process_cmds",
          *(_DWORD *)(a1 + 64),
          v77,
          v47,
          v56);
      }
      v57 = v55 << 24;
      v11 = v70;
      *v23 = 0;
      *((_DWORD *)v23 + 2) = v57;
      *((_DWORD *)v23 + 3) = 2162688;
      goto LABEL_33;
    }
LABEL_102:
    if ( v72 )
      ipc_log_string(
        v69[11],
        "%s[I][%s][%x] Failed to find the satellite device with id : %d\n",
        (const char *)&unk_8360,
        "mhi_sat_process_cmds",
        *(_DWORD *)(a1 + 64),
        v47);
LABEL_13:
    __break(0x800u);
    v11 = v70;
LABEL_14:
    v12 = *(_WORD *)(a1 + 88);
    v13 = v9[3];
    v14 = *(_WORD *)(v11 + 6);
    v15 = *(_WORD *)(v11 + 10);
    if ( v12 == -2 )
      v16 = 0;
    else
      v16 = v12 + 1;
    *(_WORD *)(a1 + 88) = v16;
    v17 = *(_QWORD *)(a1 - 144);
    *(_DWORD *)v13 = 1;
    *(_WORD *)(v13 + 4) = 14;
    v18 = *(_WORD *)(a1 + 88);
    *(_WORD *)(v13 + 8) = v14;
    *(_WORD *)(v13 + 10) = v15 & 0xFFF0;
    *(_WORD *)(v13 + 6) = v18;
    *(_DWORD *)(v13 + 12) = *(_DWORD *)(a1 + 64);
    rpmsg_send(*(_QWORD *)(*(_QWORD *)(v17 + 8) + 968LL), v13, ((v15 & 0xFFF0) + 24) & 0xFFF8);
LABEL_18:
    result = kfree(v9);
    v9 = v20;
    if ( v20 != &v74 )
      continue;
    break;
  }
LABEL_109:
  if ( v64 )
    result = ipc_log_string(
               *(_QWORD *)(v63 + 88),
               "%s[I][%s][%x] Exited\n",
               (const char *)&unk_8360,
               "mhi_sat_process_worker",
               *(_DWORD *)(a1 + 64));
  _ReadStatusReg(SP_EL0);
  return result;
}
