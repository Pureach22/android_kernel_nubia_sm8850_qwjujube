__int64 __fastcall dp_mst_sim_down_req_work(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x1
  __int64 *v3; // x24
  __int64 v4; // x2
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 ipc_log_context; // x0
  void *v8; // x0
  _BYTE *v9; // x1
  unsigned int v10; // w8
  unsigned int v11; // w10
  char v12; // w11
  char v13; // w9
  char v14; // w8
  unsigned int v15; // w10
  int v16; // w10
  __int64 v17; // x12
  __int64 v18; // x13
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x9
  int v21; // w12
  __int64 v22; // x11
  int v23; // w13
  _BYTE *v24; // x10
  unsigned __int8 *v25; // x10
  __int64 v26; // x9
  unsigned int v27; // w11
  unsigned int v28; // w9
  int v29; // w10
  __int64 v30; // x11
  __int64 v31; // x12
  __int64 v32; // x8
  __int64 v33; // x10
  int v34; // w9
  __int64 v35; // x9
  unsigned __int64 v36; // x10
  __int64 v37; // x11
  int v38; // w8
  char v39; // w15
  _QWORD *v40; // x15
  __int64 v41; // x16
  int v42; // w14
  __int64 v43; // x14
  char v44; // w15
  char v45; // w16
  unsigned __int64 v46; // x8
  _BYTE *v47; // x9
  __int64 v48; // x10
  char v49; // w8
  int v50; // w9
  __int64 v51; // x8
  __int64 v52; // x9
  int v53; // w8
  __int64 v54; // x0
  char v55; // w8
  __int64 v56; // x8
  __int64 v57; // x11
  size_t v58; // x20
  _BYTE *v59; // x21
  _DWORD *v60; // x8
  __int64 v61; // x0
  __int64 v62; // x2
  int v63; // w8
  int v64; // w9
  int v65; // w8
  size_t v66; // x23
  __int64 v67; // x19
  int v68; // w9
  int v69; // w8
  char v70; // w0
  int v71; // w9
  __int64 v72; // x0
  void (__fastcall *v73)(_QWORD); // x8
  __int64 result; // x0
  __int64 v75; // x0
  __int64 v76; // x11
  __int64 v77; // x13
  __int64 v78; // x0
  __int64 v79; // x10
  __int64 v80; // x11
  __int64 v81; // x0
  __int64 v82; // x11
  __int64 v83; // x13
  __int64 v84; // x0
  void *v85; // x0
  __int64 v86; // x0
  __int64 v87; // x0
  __int64 v88; // [xsp+0h] [xbp-30h]
  char v89; // [xsp+Ch] [xbp-24h]
  __int64 v90; // [xsp+10h] [xbp-20h] BYREF
  __int128 v91; // [xsp+18h] [xbp-18h] BYREF
  __int64 v92; // [xsp+28h] [xbp-8h]

  v1 = a1;
  v2 = a1 + 44;
  v92 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(__int64 **)(a1 + 32);
  v4 = *(unsigned __int8 *)(a1 + 304);
  v91 = 0u;
  v90 = 0;
  v5 = (__int64)v3 + 36;
  if ( (v3[43] & 1) != 0 )
  {
    v6 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))dp_mst_sim_sideband_msg_build)(v5, v2, v4, 0);
    if ( (v6 & 1) == 0 )
    {
      ipc_log_context = get_ipc_log_context(v6);
      ipc_log_string(
        ipc_log_context,
        "[e][%-4d]sideband msg build failed\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
      v8 = &unk_24EFBB;
LABEL_50:
      printk(v8, "dp_get_one_sb_msg");
      goto LABEL_84;
    }
  }
  else
  {
    v6 = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64))dp_mst_sim_sideband_msg_build)(v5, v2, v4, 1);
    if ( (v6 & 1) == 0 )
    {
      v54 = get_ipc_log_context(v6);
      ipc_log_string(v54, "[e][%-4d]sideband hdr build failed\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
      v8 = &unk_24B9BD;
      goto LABEL_50;
    }
  }
  if ( *((_BYTE *)v3 + 345) == 1 )
  {
    v88 = v1;
    v9 = (char *)v3 + 84;
    v10 = *((unsigned __int8 *)v3 + 84);
    v89 = *((_BYTE *)v3 + 361);
    if ( v10 <= 0x13 )
    {
      switch ( v10 )
      {
        case 1u:
          v33 = *(__int64 *)((char *)v3 + 796);
          v32 = *(__int64 *)((char *)v3 + 804);
          *((_BYTE *)v3 + 410) = 1;
          v34 = *((_DWORD *)v3 + 8);
          *(__int64 *)((char *)v3 + 411) = v33;
          *(__int64 *)((char *)v3 + 419) = v32;
          *((_BYTE *)v3 + 427) = v34;
          if ( v34 )
          {
            v35 = 0;
            v36 = 0;
            v37 = (__int64)v3 + 410;
            v38 = 18;
            do
            {
              v43 = v3[3] + v35;
              if ( *(_BYTE *)v43 )
                v44 = 0x80;
              else
                v44 = 0;
              *(_BYTE *)(v37 + v38) = v44 & 0xF0 | v36 & 0xF | (16 * *(_BYTE *)(v43 + 3));
              if ( *(_BYTE *)(v43 + 1) )
                v45 = 0x80;
              else
                v45 = 0;
              v39 = v45 | 0x40;
              if ( !*(_BYTE *)(v43 + 2) )
                v39 = v45;
              v41 = v38 | 1LL;
              if ( *(_BYTE *)v43 == 1 )
              {
                v42 = 2;
              }
              else
              {
                if ( *(_BYTE *)(v43 + 4) )
                  v39 |= 0x20u;
                *(_BYTE *)(v37 + v41) = v39;
                *(_BYTE *)(v37 + v38 + 2) = *(_BYTE *)(v43 + 5);
                v40 = (_QWORD *)(v37 + v38 + 3);
                v41 = *(_QWORD *)(v43 + 14);
                *v40 = *(_QWORD *)(v43 + 6);
                v40[1] = v41;
                LODWORD(v41) = v38 + 19;
                v39 = *(_BYTE *)(v43 + 23) | (16 * *(_BYTE *)(v43 + 22));
                v42 = 20;
              }
              *(_BYTE *)(v37 + (int)v41) = v39;
              ++v36;
              v38 += v42;
              v35 += 48;
            }
            while ( v36 < *((unsigned int *)v3 + 8) );
            HIDWORD(v90) = v38;
          }
          else
          {
            HIDWORD(v90) = 18;
          }
          goto LABEL_63;
        case 0x10u:
          v46 = *((unsigned __int8 *)v3 + 85);
          if ( *((_DWORD *)v3 + 8) <= (unsigned int)(v46 >> 4) )
          {
            v78 = get_ipc_log_context(v6);
            ipc_log_string(v78, "[e][%-4d]invalid port num\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
            printk(&unk_25D8D3, "dp_sideband_build_enum_path_resources_rep");
            v80 = *(__int64 *)((char *)v3 + 796);
            v79 = *(__int64 *)((char *)v3 + 804);
            v9 = (char *)v3 + 84;
            v49 = 0;
            *((_BYTE *)v3 + 410) = *((_BYTE *)v3 + 84) | 0x80;
            *(__int64 *)((char *)v3 + 411) = v80;
            *(__int64 *)((char *)v3 + 419) = v79;
            v48 = 428;
            *((_BYTE *)v3 + 427) = 4;
            v50 = 19;
          }
          else
          {
            v47 = (_BYTE *)(v3[3] + 48LL * (unsigned int)(v46 >> 4));
            *((_BYTE *)v3 + 411) = v46 & 0xF0;
            *((_BYTE *)v3 + 410) = 16;
            v48 = 415;
            *((_BYTE *)v3 + 412) = v47[25];
            *((_BYTE *)v3 + 413) = v47[24];
            *((_BYTE *)v3 + 414) = v47[27];
            v49 = v47[26];
            v50 = 6;
          }
          *((_BYTE *)v3 + v48) = v49;
          HIDWORD(v90) = v50;
          goto LABEL_63;
        case 0x11u:
          v11 = *((unsigned __int8 *)v3 + 85);
          v12 = *((_BYTE *)v3 + 86);
          v13 = *((_BYTE *)v3 + 87);
          v14 = *((_BYTE *)v3 + 88);
          if ( (v11 & 1) != 0 && (v11 & 0xF) - 1 >= 0x10 )
LABEL_92:
            __break(0x5512u);
          v15 = v11 >> 4;
          if ( *((_DWORD *)v3 + 8) <= v15 )
          {
            v81 = get_ipc_log_context(v6);
            ipc_log_string(v81, "[e][%-4d]invalid port num\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
            printk(&unk_25D8D3, "dp_sideband_build_allocate_payload_rep");
            v82 = *(__int64 *)((char *)v3 + 796);
            v83 = *(__int64 *)((char *)v3 + 804);
            v9 = (char *)v3 + 84;
            v14 = 0;
            v16 = 19;
            *((_BYTE *)v3 + 410) = *((_BYTE *)v3 + 84) | 0x80;
            v13 = 4;
            *(__int64 *)((char *)v3 + 411) = v82;
            *(__int64 *)((char *)v3 + 419) = v83;
            v17 = 428;
            v18 = 427;
          }
          else
          {
            *((_BYTE *)v3 + 411) = v15;
            v16 = 5;
            *((_BYTE *)v3 + 410) = 17;
            v17 = 414;
            v18 = 413;
            *((_BYTE *)v3 + 412) = v12;
          }
          *((_BYTE *)v3 + v18) = v13;
          *((_BYTE *)v3 + v17) = v14;
          HIDWORD(v90) = v16;
          goto LABEL_63;
      }
      goto LABEL_46;
    }
    if ( v10 - 36 < 2 )
    {
      v28 = *((unsigned __int8 *)v3 + 85) >> 4;
      if ( *((_DWORD *)v3 + 8) <= v28 )
      {
        v75 = get_ipc_log_context(v6);
        ipc_log_string(v75, "[e][%-4d]invalid port num\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
        printk(&unk_25D8D3, "dp_sideband_build_power_updown_phy_rep");
        v76 = *(__int64 *)((char *)v3 + 796);
        v77 = *(__int64 *)((char *)v3 + 804);
        v9 = (char *)v3 + 84;
        LOBYTE(v28) = 0;
        v29 = 19;
        *((_BYTE *)v3 + 410) = *((_BYTE *)v3 + 84) | 0x80;
        LOBYTE(v10) = 4;
        *(__int64 *)((char *)v3 + 411) = v76;
        *(__int64 *)((char *)v3 + 419) = v77;
        v30 = 428;
        v31 = 427;
      }
      else
      {
        v29 = 2;
        v30 = 411;
        v31 = 410;
      }
      *((_BYTE *)v3 + v31) = v10;
      *((_BYTE *)v3 + v30) = v28;
      HIDWORD(v90) = v29;
      goto LABEL_63;
    }
    if ( v10 == 20 )
    {
      *((_BYTE *)v3 + 410) = 20;
      HIDWORD(v90) = 1;
LABEL_63:
      v60 = (_DWORD *)v3[2];
      if ( v60 )
      {
        v61 = *v3;
        v62 = *((unsigned __int8 *)v3 + 343);
        if ( *(v60 - 1) != 1914195768 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _BYTE *, __int64, char *, char *))v60)(
          v61,
          v9,
          v62,
          (char *)v3 + 410,
          (char *)&v90 + 4);
      }
      memset((char *)v3 + 36, 0, 0x146u);
      *((_BYTE *)v3 + 669) = 0;
      mutex_lock(v3 + 86);
      v63 = *((unsigned __int8 *)v3 + 669);
      v64 = HIDWORD(v90);
      if ( SHIDWORD(v90) > v63 )
      {
        while ( !*((_DWORD *)v3 + 194) )
        {
          v65 = v64 - v63;
          if ( v65 >= 44 )
            v65 = 44;
          v66 = v65;
          if ( (unsigned int)v65 >= 0x3FE && (dp_mst_sim_down_req_internal___already_done & 1) == 0 )
          {
            dp_mst_sim_down_req_internal___already_done = 1;
            _warn_printk(
              "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
              v65,
              "field \"&ctx->dpcd[3]\" at ../vendor/qcom/opensource/display-drivers/msm/dp/dp_mst_sim_helper.c:807",
              0x3FDu);
            __break(0x800u);
          }
          v67 = *((unsigned __int8 *)v3 + 669);
          memcpy((char *)v3 + 815, (char *)v3 + v67 + 410, v66);
          v68 = HIDWORD(v90);
          *((_BYTE *)v3 + 669) = v67 + v66;
          v69 = (unsigned __int8)(v67 + v66);
          BYTE12(v91) = v66 + 1;
          *(_QWORD *)((char *)&v91 + 2) = 0;
          WORD5(v91) = 0;
          LOWORD(v91) = 1;
          HIBYTE(v91) = v89;
          BYTE14(v91) = v68 == v69;
          BYTE13(v91) = (_DWORD)v66 == v69;
          dp_mst_sim_encode_sideband_msg_hdr(&v91, (char *)v3 + 812, &v90);
          v70 = dp_mst_sim_msg_data_crc4((char *)v3 + 815, (unsigned int)v66);
          if ( (unsigned int)(v66 + 3) > 0x3FF )
            goto LABEL_92;
          v71 = *((_DWORD *)v3 + 8);
          *((_BYTE *)v3 + (unsigned int)(v66 + 3) + 812) = v70;
          *(_WORD *)((char *)v3 + 781) = 16;
          *((_BYTE *)v3 + 780) = v71;
          mutex_unlock(v3 + 86);
          v72 = *v3;
          v73 = (void (__fastcall *)(_QWORD))v3[1];
          if ( *((_DWORD *)v73 - 1) != 251140989 )
            __break(0x8228u);
          v73(v72);
          while ( 1 )
          {
            mutex_lock(v3 + 86);
            if ( (*((_BYTE *)v3 + 781) & 0x10) == 0 || *((_DWORD *)v3 + 194) )
              break;
            mutex_unlock(v3 + 86);
            wait_for_completion(v3 + 92);
          }
          v63 = *((unsigned __int8 *)v3 + 669);
          v64 = HIDWORD(v90);
          if ( SHIDWORD(v90) <= v63 )
            break;
        }
      }
      mutex_unlock(v3 + 86);
      v1 = v88;
      goto LABEL_84;
    }
    if ( v10 != 34 )
    {
LABEL_46:
      *((_BYTE *)v3 + 410) = v10 | 0x80;
      v51 = *(__int64 *)((char *)v3 + 796);
      v52 = *(__int64 *)((char *)v3 + 804);
      *(_WORD *)((char *)v3 + 427) = 4;
      *(__int64 *)((char *)v3 + 411) = v51;
      *(__int64 *)((char *)v3 + 419) = v52;
      v53 = 19;
LABEL_62:
      HIDWORD(v90) = v53;
      goto LABEL_63;
    }
    v19 = *((unsigned __int8 *)v3 + 85);
    v20 = v19 >> 4;
    if ( *((_DWORD *)v3 + 8) <= (unsigned int)(v19 >> 4) )
    {
      v55 = -94;
LABEL_53:
      *((_BYTE *)v3 + 410) = v55;
      v57 = *(__int64 *)((char *)v3 + 796);
      v56 = *(__int64 *)((char *)v3 + 804);
      *(_WORD *)((char *)v3 + 427) = 4;
      HIDWORD(v90) = 19;
      *(__int64 *)((char *)v3 + 411) = v57;
      *(__int64 *)((char *)v3 + 419) = v56;
      goto LABEL_63;
    }
    v21 = v19 & 3;
    if ( (v19 & 3) != 0 )
    {
      v22 = *((unsigned __int8 *)v3 + 87);
      v23 = *((_BYTE *)v3 + 86) & 0x7F;
      v24 = &v9[v22];
      if ( v21 == 1 )
      {
        if ( v23 == 80 && (_DWORD)v22 == 1 )
        {
          v25 = v24 + 6;
          v26 = v3[3] + 48LL * (unsigned int)v20;
          v27 = *((unsigned __int8 *)v3 + 88);
LABEL_60:
          v58 = *v25;
          v59 = (char *)v3 + 84;
          if ( v27 + (unsigned int)v58 <= *(_DWORD *)(v26 + 40) )
          {
            *((_BYTE *)v3 + 412) = v58;
            *((_BYTE *)v3 + 410) = 34;
            *((_BYTE *)v3 + 411) = (unsigned int)v19 >> 4;
            memcpy((char *)v3 + 413, (const void *)(*(_QWORD *)(v26 + 32) + v27), v58);
            v53 = v58 + 3;
            v9 = (char *)v3 + 84;
            goto LABEL_62;
          }
          v86 = get_ipc_log_context(v6);
          ipc_log_string(v86, "[e][%-4d]edid data exceeds maximum\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
          v85 = &unk_23AD96;
          goto LABEL_91;
        }
LABEL_90:
        v59 = (char *)v3 + 84;
        v87 = get_ipc_log_context(v6);
        ipc_log_string(v87, "[e][%-4d]unsupported i2c address\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
        v85 = &unk_26F526;
        goto LABEL_91;
      }
      if ( v21 == 2 )
      {
        if ( v23 == 48 && (_DWORD)v22 == 1 && (v24[5] & 0x7F) == 0x50 && v24[6] == 1 )
        {
          v26 = v3[3] + 48LL * (unsigned int)v20;
          v27 = (unsigned __int8)v24[7] | (*((unsigned __int8 *)v3 + 88) << 8);
          v25 = (unsigned __int8 *)v3 + 95;
          goto LABEL_60;
        }
        goto LABEL_90;
      }
    }
    v59 = (char *)v3 + 84;
    v84 = get_ipc_log_context(v6);
    ipc_log_string(v84, "[e][%-4d]unsupported i2c transaction\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v85 = &unk_276238;
LABEL_91:
    printk(v85, "dp_sideband_build_remote_i2c_read_rep");
    v9 = v59;
    v55 = *v59 | 0x80;
    goto LABEL_53;
  }
LABEL_84:
  result = kfree(v1);
  _ReadStatusReg(SP_EL0);
  return result;
}
