__int64 __fastcall ipahal_cp_proc_ctx_to_hw_buff_v3(
        int a1,
        __int64 a2,
        unsigned int a3,
        int a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        _DWORD *a8,
        __int64 a9,
        char a10)
{
  __int64 v10; // x20
  int *v11; // x20
  unsigned __int64 v12; // x19
  __int64 v13; // x0
  __int64 v14; // x0
  unsigned __int64 v15; // x8
  __int64 result; // x0
  __int64 v17; // x19
  __int64 v18; // x22
  __int64 v19; // x0
  __int64 v20; // x0
  int v21; // w8
  unsigned __int8 v22; // w8
  __int64 v23; // x22
  __int64 v25; // x19
  __int64 v26; // x0
  __int64 v27; // x0
  int v28; // w8
  int v29; // w8
  __int64 v30; // x20
  _DWORD *v32; // x22
  unsigned __int64 v33; // x19
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  unsigned __int64 v36; // x8
  int v37; // w8
  int v38; // w9
  unsigned int v39; // w9
  unsigned int v40; // w9
  unsigned int v41; // w9
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x22
  unsigned __int64 v46; // x20
  __int64 v47; // x0
  __int64 v48; // x0
  unsigned __int64 v49; // x8
  __int64 v50; // x0
  __int64 v51; // x0
  unsigned __int64 v53; // x19
  __int64 v54; // x0
  __int64 v55; // x0
  unsigned __int64 v56; // x8
  int v57; // w10
  unsigned int v58; // w10
  unsigned int v59; // w10
  unsigned int v60; // w10
  __int64 v61; // x0
  __int64 v62; // x0
  __int64 v63; // x0
  __int64 v64; // x0
  __int64 v65; // x22
  unsigned __int64 v66; // x19
  __int64 v67; // x0
  __int64 v68; // x0
  unsigned __int64 v69; // x8
  int v70; // w8
  unsigned int v71; // w8
  unsigned int v72; // w8
  unsigned int v73; // w8
  unsigned int v74; // w8
  __int64 v75; // x0
  __int64 v76; // x0
  __int64 v77; // x0
  __int64 v78; // x0
  __int64 v79; // x0
  __int64 v80; // x0
  __int64 v81; // x22
  unsigned __int64 v82; // x19
  __int64 v83; // x0
  __int64 v84; // x0
  unsigned __int64 v85; // x8
  unsigned int v86; // w8
  unsigned int v87; // w8
  unsigned int v88; // w8
  unsigned int v89; // w8
  __int64 v90; // x0
  __int64 v91; // x0
  __int64 v92; // x0
  __int64 v93; // x0
  __int64 v94; // x0
  __int64 v95; // x0
  __int64 v96; // x0
  __int64 v97; // x0

  if ( a1 )
  {
    if ( a1 <= 7 )
    {
      if ( a1 == 5 )
      {
LABEL_36:
        v30 = a2 + a3;
        v32 = (_DWORD *)a7;
        *(_DWORD *)v30 = (a4 << 16) | 0x201;
        v33 = *(unsigned int *)(a6 + 16) + a5;
        if ( ipa3_get_ipc_logbuf() )
        {
          ipc_logbuf = ipa3_get_ipc_logbuf();
          ipc_log_string(
            ipc_logbuf,
            "ipahal %s:%d header address 0x%llx\n",
            "ipahal_cp_proc_ctx_to_hw_buff_v3",
            2093,
            v33);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            ipc_logbuf_low,
            "ipahal %s:%d header address 0x%llx\n",
            "ipahal_cp_proc_ctx_to_hw_buff_v3",
            2093,
            v33);
        }
        v36 = HIDWORD(v33);
        if ( (a10 & 1) == 0 )
          LODWORD(v36) = 0;
        *(_DWORD *)(v30 + 4) = v33;
        *(_DWORD *)(v30 + 8) = v36;
        if ( a1 == 5 )
          v37 = 655619;
        else
          v37 = 786691;
        v38 = *(_DWORD *)(v30 + 16);
        *(_DWORD *)(v30 + 12) = v37;
        v39 = v38 & 0xFFFFFFF7 | (8 * ((*v32 >> 3) & 1));
        *(_DWORD *)(v30 + 16) = v39;
        v40 = v39 & 0xFFFFFFFE | *v32 & 1;
        *(_DWORD *)(v30 + 16) = v40;
        v41 = v40 & 0xFFFFFFFD | (2 * ((*v32 >> 1) & 1));
        *(_DWORD *)(v30 + 16) = v41;
        *(_DWORD *)(v30 + 16) = v41 & 0xFFFFFFFB | (4 * ((*v32 >> 2) & 1));
        if ( ipa3_get_ipc_logbuf() )
        {
          v42 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v42,
            "ipahal %s:%d command id %d\n",
            "ipahal_cp_proc_ctx_to_hw_buff_v3",
            2115,
            *(unsigned __int16 *)(v30 + 14));
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v43 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v43,
            "ipahal %s:%d command id %d\n",
            "ipahal_cp_proc_ctx_to_hw_buff_v3",
            2115,
            *(unsigned __int16 *)(v30 + 14));
        }
        *(_DWORD *)(v30 + 24) = 0;
        return 0;
      }
      if ( a1 == 6 )
      {
        v10 = a2 + a3;
        v65 = a7;
        *(_DWORD *)v10 = (a4 << 16) | 0x201;
        v66 = *(unsigned int *)(a6 + 16) + a5;
        if ( ipa3_get_ipc_logbuf() )
        {
          v67 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v67,
            "ipahal %s:%d header address 0x%llx length %d\n",
            "ipahal_cp_proc_ctx_to_hw_buff_v3",
            2129,
            v66,
            *(unsigned __int16 *)(v10 + 2));
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v68 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v68,
            "ipahal %s:%d header address 0x%llx length %d\n",
            "ipahal_cp_proc_ctx_to_hw_buff_v3",
            2129,
            v66,
            *(unsigned __int16 *)(v10 + 2));
        }
        v69 = HIDWORD(v66);
        if ( (a10 & 1) == 0 )
          LODWORD(v69) = 0;
        *(_DWORD *)(v10 + 4) = v66;
        *(_DWORD *)(v10 + 8) = v69;
        v70 = *(_DWORD *)(v10 + 16);
        *(_DWORD *)(v10 + 12) = 721155;
        v71 = v70 & 0xFFFFFF00 | *(unsigned __int8 *)(v65 + 8);
        *(_DWORD *)(v10 + 16) = v71;
        v72 = v71 & 0xFFFFFEFF | (((*(_DWORD *)(v65 + 8) >> 8) & 1) << 8);
        *(_DWORD *)(v10 + 16) = v72;
        v73 = v72 & 0xFFFFFDFF | (((*(_DWORD *)(v65 + 8) >> 9) & 1) << 9);
        *(_DWORD *)(v10 + 16) = v73;
        v74 = v73 & 0xFFFF03FF | ((unsigned __int8)HIBYTE(*(_WORD *)(v65 + 8)) >> 2 << 10);
        *(_DWORD *)(v10 + 16) = v74;
        *(_DWORD *)(v10 + 16) = v74 & 0xFFFEFFFF | ((HIWORD(*(_DWORD *)(v65 + 8)) & 1) << 16);
        if ( ipa3_get_ipc_logbuf() )
        {
          v75 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v75,
            "ipahal %s:%d hdr ofst valid: %d, hdr ofst pkt size: %d\n",
            "ipahal_cp_proc_ctx_to_hw_buff_v3",
            2150,
            (*(_DWORD *)(v10 + 16) >> 9) & 1,
            (unsigned __int16)*(_DWORD *)(v10 + 16) >> 10);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v76 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v76,
            "ipahal %s:%d hdr ofst valid: %d, hdr ofst pkt size: %d\n",
            "ipahal_cp_proc_ctx_to_hw_buff_v3",
            2150,
            (*(_DWORD *)(v10 + 16) >> 9) & 1,
            (unsigned __int16)*(_DWORD *)(v10 + 16) >> 10);
        }
        if ( ipa3_get_ipc_logbuf() )
        {
          v77 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v77,
            "ipahal %s:%d endianness: %d\n",
            "ipahal_cp_proc_ctx_to_hw_buff_v3",
            2152,
            HIWORD(*(_DWORD *)(v10 + 16)) & 1);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v78 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v78,
            "ipahal %s:%d endianness: %d\n",
            "ipahal_cp_proc_ctx_to_hw_buff_v3",
            2152,
            HIWORD(*(_DWORD *)(v10 + 16)) & 1);
        }
        if ( ipa3_get_ipc_logbuf() )
        {
          v79 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v79,
            "ipahal %s:%d command id %d\n",
            "ipahal_cp_proc_ctx_to_hw_buff_v3",
            2154,
            *(unsigned __int16 *)(v10 + 14));
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v80 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v80,
            "ipahal %s:%d command id %d\n",
            "ipahal_cp_proc_ctx_to_hw_buff_v3",
            2154,
            *(unsigned __int16 *)(v10 + 14));
        }
        goto LABEL_114;
      }
      if ( a1 != 7 )
      {
LABEL_50:
        v44 = a2 + a3;
        *(_DWORD *)v44 = (a4 << 16) | 0x201;
        v46 = *(unsigned int *)(a6 + 16) + a5;
        if ( ipa3_get_ipc_logbuf() )
        {
          v47 = ipa3_get_ipc_logbuf();
          ipc_log_string(v47, "ipahal %s:%d header address 0x%llx\n", "ipahal_cp_proc_ctx_to_hw_buff_v3", 2300, v46);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v48 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v48, "ipahal %s:%d header address 0x%llx\n", "ipahal_cp_proc_ctx_to_hw_buff_v3", 2300, v46);
        }
        v49 = HIDWORD(v46);
        *(_WORD *)(v44 + 12) = 3;
        if ( (a10 & 1) == 0 )
          LODWORD(v49) = 0;
        *(_DWORD *)(v44 + 4) = v46;
        *(_DWORD *)(v44 + 8) = v49;
        if ( (unsigned int)a1 < 0xB && ((0x20Fu >> (a1 - 1)) & 1) != 0 )
        {
          *(_DWORD *)(v44 + 12) = dword_1E5608[a1 - 1];
          if ( ipa3_get_ipc_logbuf() )
          {
            v50 = ipa3_get_ipc_logbuf();
            ipc_log_string(
              v50,
              "ipahal %s:%d command id %d\n",
              "ipahal_cp_proc_ctx_to_hw_buff_v3",
              2328,
              *(unsigned __int16 *)(v44 + 14));
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v51 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v51,
              "ipahal %s:%d command id %d\n",
              "ipahal_cp_proc_ctx_to_hw_buff_v3",
              2328,
              *(unsigned __int16 *)(v44 + 14));
          }
          *(_DWORD *)(v44 + 16) = 0;
          return 0;
        }
        else
        {
          printk(&unk_3BA14D, "ipahal_cp_proc_ctx_to_hw_buff_v3");
          if ( ipa3_get_ipc_logbuf() )
          {
            v96 = ipa3_get_ipc_logbuf();
            ipc_log_string(
              v96,
              "ipahal %s:%d unknown ipa_hdr_proc_type %d",
              "ipahal_cp_proc_ctx_to_hw_buff_v3",
              2324,
              a1);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v97 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v97,
              "ipahal %s:%d unknown ipa_hdr_proc_type %d",
              "ipahal_cp_proc_ctx_to_hw_buff_v3",
              2324,
              a1);
          }
          __break(0x800u);
          return 4294967274LL;
        }
      }
      v17 = a2 + a3;
      *(_DWORD *)v17 = (a4 << 16) | 0x201;
      v18 = *(unsigned int *)(a6 + 16) + a5;
      if ( ipa3_get_ipc_logbuf() )
      {
        v19 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v19,
          "ipahal %s:%d header address 0x%x\n",
          "ipahal_cp_proc_ctx_to_hw_buff_v3",
          2212,
          *(_DWORD *)(v17 + 4));
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v20 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v20,
          "ipahal %s:%d header address 0x%x\n",
          "ipahal_cp_proc_ctx_to_hw_buff_v3",
          2212,
          *(_DWORD *)(v17 + 4));
      }
      *(_DWORD *)(v17 + 4) = v18;
      result = 0;
      if ( (a10 & 1) != 0 )
        v21 = HIDWORD(v18);
      else
        v21 = 0;
      *(_DWORD *)(v17 + 8) = v21;
      *(_DWORD *)(v17 + 12) = 917763;
      v22 = *(_DWORD *)a9;
      *(_BYTE *)(v17 + 16) = v22;
      *(_QWORD *)(v17 + 16) = v22 | (*(unsigned __int8 *)(a9 + 1) << 8);
    }
    else
    {
      if ( a1 <= 10 )
      {
        if ( a1 != 8 )
        {
          if ( a1 == 9 )
          {
            v10 = a2 + a3;
            *(_WORD *)v10 = 513;
            if ( (*(_BYTE *)(a7 + 9) & 1) != 0 )
            {
              v81 = a7;
              *(_DWORD *)v10 = (a4 << 16) | 0x201;
              v82 = *(unsigned int *)(a6 + 16) + a5;
              if ( ipa3_get_ipc_logbuf() )
              {
                v83 = ipa3_get_ipc_logbuf();
                ipc_log_string(
                  v83,
                  "ipahal %s:%d header address 0x%llx length %d\n",
                  "ipahal_cp_proc_ctx_to_hw_buff_v3",
                  2169,
                  v82,
                  *(unsigned __int16 *)(v10 + 2));
              }
              if ( ipa3_get_ipc_logbuf_low() )
              {
                v84 = ipa3_get_ipc_logbuf_low();
                ipc_log_string(
                  v84,
                  "ipahal %s:%d header address 0x%llx length %d\n",
                  "ipahal_cp_proc_ctx_to_hw_buff_v3",
                  2169,
                  v82,
                  *(unsigned __int16 *)(v10 + 2));
              }
              v85 = HIDWORD(v82);
              a7 = v81;
              if ( (a10 & 1) == 0 )
                LODWORD(v85) = 0;
              *(_DWORD *)(v10 + 4) = v82;
              *(_DWORD *)(v10 + 8) = v85;
            }
            else
            {
              *(_DWORD *)v10 = 513;
            }
            *(_DWORD *)(v10 + 12) = 852227;
            v86 = *(_DWORD *)(v10 + 16) & 0xFFFFFF00 | *(unsigned __int8 *)(a7 + 8);
            *(_DWORD *)(v10 + 16) = v86;
            v87 = v86 & 0xFFFFFEFF | (((*(_DWORD *)(a7 + 8) >> 8) & 1) << 8);
            *(_DWORD *)(v10 + 16) = v87;
            v88 = v87 & 0xFFFFFDFF | (((*(_DWORD *)(a7 + 8) >> 9) & 1) << 9);
            *(_DWORD *)(v10 + 16) = v88;
            v89 = v88 & 0xFFFF03FF | ((unsigned __int8)HIBYTE(*(_WORD *)(a7 + 8)) >> 2 << 10);
            *(_DWORD *)(v10 + 16) = v89;
            *(_DWORD *)(v10 + 16) = v89 & 0xFFFEFFFF | ((HIWORD(*(_DWORD *)(a7 + 8)) & 1) << 16);
            if ( ipa3_get_ipc_logbuf() )
            {
              v90 = ipa3_get_ipc_logbuf();
              ipc_log_string(
                v90,
                "ipahal %s:%d hdr ofst valid: %d, hdr ofst pkt size: %d\n",
                "ipahal_cp_proc_ctx_to_hw_buff_v3",
                2193,
                (*(_DWORD *)(v10 + 16) >> 9) & 1,
                (unsigned __int16)*(_DWORD *)(v10 + 16) >> 10);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v91 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(
                v91,
                "ipahal %s:%d hdr ofst valid: %d, hdr ofst pkt size: %d\n",
                "ipahal_cp_proc_ctx_to_hw_buff_v3",
                2193,
                (*(_DWORD *)(v10 + 16) >> 9) & 1,
                (unsigned __int16)*(_DWORD *)(v10 + 16) >> 10);
            }
            if ( ipa3_get_ipc_logbuf() )
            {
              v92 = ipa3_get_ipc_logbuf();
              ipc_log_string(
                v92,
                "ipahal %s:%d endianness: %d\n",
                "ipahal_cp_proc_ctx_to_hw_buff_v3",
                2195,
                HIWORD(*(_DWORD *)(v10 + 16)) & 1);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v93 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(
                v93,
                "ipahal %s:%d endianness: %d\n",
                "ipahal_cp_proc_ctx_to_hw_buff_v3",
                2195,
                HIWORD(*(_DWORD *)(v10 + 16)) & 1);
            }
            if ( ipa3_get_ipc_logbuf() )
            {
              v94 = ipa3_get_ipc_logbuf();
              ipc_log_string(
                v94,
                "ipahal %s:%d command id %d\n",
                "ipahal_cp_proc_ctx_to_hw_buff_v3",
                2197,
                *(unsigned __int16 *)(v10 + 14));
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v95 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(
                v95,
                "ipahal %s:%d command id %d\n",
                "ipahal_cp_proc_ctx_to_hw_buff_v3",
                2197,
                *(unsigned __int16 *)(v10 + 14));
            }
LABEL_114:
            *(_DWORD *)(v10 + 20) = 0;
            return 0;
          }
          goto LABEL_50;
        }
        goto LABEL_36;
      }
      if ( a1 == 11 )
      {
        v10 = a2 + a3;
        *(_DWORD *)v10 = (a4 << 16) | 0x201;
        v53 = *(unsigned int *)(a6 + 16) + a5;
        if ( ipa3_get_ipc_logbuf() )
        {
          v54 = ipa3_get_ipc_logbuf();
          ipc_log_string(v54, "ipahal %s:%d header address 0x%llx\n", "ipahal_cp_proc_ctx_to_hw_buff_v3", 2241, v53);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v55 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v55, "ipahal %s:%d header address 0x%llx\n", "ipahal_cp_proc_ctx_to_hw_buff_v3", 2241, v53);
        }
        v56 = HIDWORD(v53);
        v57 = *(_DWORD *)(v10 + 16);
        if ( (a10 & 1) == 0 )
          LODWORD(v56) = 0;
        *(_DWORD *)(v10 + 4) = v53;
        *(_DWORD *)(v10 + 8) = v56;
        *(_DWORD *)(v10 + 12) = 1114371;
        v58 = v57 & 0xFFFFFFFE | *a8 & 1;
        *(_DWORD *)(v10 + 16) = v58;
        v59 = v58 & 0xFFFFFFFD | (2 * ((*a8 >> 1) & 1));
        *(_DWORD *)(v10 + 16) = v59;
        v60 = v59 & 0xFFFFFFFB | (4 * ((*a8 >> 2) & 1));
        *(_DWORD *)(v10 + 16) = v60;
        *(_DWORD *)(v10 + 16) = v60 & 0xFFFFFFF7 | (8 * ((*a8 >> 3) & 1));
        if ( ipa3_get_ipc_logbuf() )
        {
          v61 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v61,
            "ipahal %s:%d command id %d\n",
            "ipahal_cp_proc_ctx_to_hw_buff_v3",
            2257,
            *(unsigned __int16 *)(v10 + 14));
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v62 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v62,
            "ipahal %s:%d command id %d\n",
            "ipahal_cp_proc_ctx_to_hw_buff_v3",
            2257,
            *(unsigned __int16 *)(v10 + 14));
        }
        if ( ipa3_get_ipc_logbuf() )
        {
          v63 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v63,
            "ipahal %s:%d eth_hdr_retained %d input_ip_version %d output_ip_version %d second_pass %d\n",
            "ipahal_cp_proc_ctx_to_hw_buff_v3",
            2262,
            *a8 & 1,
            (*a8 >> 1) & 1,
            (*a8 >> 2) & 1,
            (*a8 >> 3) & 1);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v64 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v64,
            "ipahal %s:%d eth_hdr_retained %d input_ip_version %d output_ip_version %d second_pass %d\n",
            "ipahal_cp_proc_ctx_to_hw_buff_v3",
            2262,
            *a8 & 1,
            (*a8 >> 1) & 1,
            (*a8 >> 2) & 1,
            (*a8 >> 3) & 1);
        }
        goto LABEL_114;
      }
      if ( a1 != 12 )
        goto LABEL_50;
      v23 = a2 + a3;
      *(_DWORD *)v23 = (a4 << 16) | 0x201;
      v25 = *(unsigned int *)(a6 + 16) + a5;
      if ( ipa3_get_ipc_logbuf() )
      {
        v26 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v26,
          "ipahal %s:%d header address 0x%llx length %d\n",
          "ipahal_cp_proc_ctx_to_hw_buff_v3",
          2276,
          v25,
          *(unsigned __int16 *)(v23 + 2));
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v27 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v27,
          "ipahal %s:%d header address 0x%llx length %d\n",
          "ipahal_cp_proc_ctx_to_hw_buff_v3",
          2276,
          v25,
          *(unsigned __int16 *)(v23 + 2));
      }
      *(_DWORD *)(v23 + 4) = v25;
      result = 0;
      if ( (a10 & 1) != 0 )
        v28 = HIDWORD(v25);
      else
        v28 = 0;
      *(_DWORD *)(v23 + 8) = v28;
      *(_DWORD *)(v23 + 12) = 1179907;
      v29 = a8[1];
      *(_DWORD *)(v23 + 20) = 0;
      *(_BYTE *)(v23 + 16) = v29;
    }
  }
  else
  {
    v11 = (int *)(a2 + a3);
    *v11 = (a4 << 16) | 0x201;
    v12 = *(unsigned int *)(a6 + 16) + a5;
    if ( ipa3_get_ipc_logbuf() )
    {
      v13 = ipa3_get_ipc_logbuf();
      ipc_log_string(v13, "ipahal %s:%d header address 0x%llx\n", "ipahal_cp_proc_ctx_to_hw_buff_v3", 2074, v12);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v14 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v14, "ipahal %s:%d header address 0x%llx\n", "ipahal_cp_proc_ctx_to_hw_buff_v3", 2074, v12);
    }
    v15 = HIDWORD(v12);
    result = 0;
    v11[3] = 0;
    if ( (a10 & 1) == 0 )
      LODWORD(v15) = 0;
    v11[1] = v12;
    v11[2] = v15;
  }
  return result;
}
