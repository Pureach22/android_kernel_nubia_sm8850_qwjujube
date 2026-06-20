void __fastcall ipa_flt_gen_hw_rule_ipav5_5(unsigned int *a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x8
  int v5; // w8
  unsigned __int64 v6; // x8
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v9; // x9
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x9
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x8
  __int64 v15; // x9
  unsigned __int64 v16; // x9
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x8
  unsigned __int64 v27; // x8
  unsigned __int64 v28; // x8
  _BYTE *v29; // x20
  __int64 v30; // x9
  __int16 v31; // w9
  unsigned int v32; // w21
  __int64 v33; // x22
  __int64 v34; // x8
  __int16 v35; // w9
  __int16 v36; // w8
  _BYTE *v37; // x24
  int v38; // w28
  int v39; // w0
  __int64 v40; // x8
  _BYTE *v41; // x21
  __int64 v42; // x0
  __int64 v43; // x0
  char v44; // w8
  __int64 v45; // x8
  _BYTE *v46; // x9
  __int64 v47; // x8
  _QWORD *v48; // x8
  char v49; // w0
  _BYTE *v50; // x0
  _BYTE *v51; // x0
  _BYTE *v52; // x0
  _BYTE *v53; // x0
  _BYTE *v54; // x0
  _BYTE *v55; // x0
  _BYTE *v56; // x0
  _BYTE *v57; // x0
  _BYTE *v58; // x0
  _BYTE *v59; // x0
  _BYTE *v60; // x0
  _BYTE *v61; // x0
  _BYTE *v62; // x0
  _BYTE *v63; // x0
  _BYTE *v64; // x0
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x0
  __int64 v68; // x0
  __int64 v69; // x0
  __int64 v70; // x0
  __int16 v71; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v72[2]; // [xsp+10h] [xbp-10h] BYREF

  v72[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *((_QWORD *)a1 + 3);
  v71 = 0;
  v5 = *(_DWORD *)(v4 + 4);
  if ( v5 > 1 )
  {
    if ( v5 == 2 )
    {
      v6 = *(_QWORD *)a3 & 0xFE0FFFFFFFFFFFFFLL | 0x20000000000000LL;
    }
    else
    {
      if ( v5 != 3 )
        goto LABEL_8;
      v6 = *(_QWORD *)a3 & 0xFE0FFFFFFFFFFFFFLL | 0x30000000000000LL;
    }
  }
  else
  {
    if ( v5 )
    {
      if ( v5 == 1 )
      {
        v6 = *(_QWORD *)a3 & 0xFE0FFFFFFFFFFFFFLL | 0x10000000000000LL;
        goto LABEL_15;
      }
LABEL_8:
      if ( (unsigned int)__ratelimit(&ipa_flt_gen_hw_rule_ipav5_5__rs, "ipa_flt_gen_hw_rule_ipav5_5") )
      {
        printk(&unk_3EB3EF, "ipa_flt_gen_hw_rule_ipav5_5");
        if ( !ipa3_get_ipc_logbuf() )
        {
LABEL_11:
          if ( ipa3_get_ipc_logbuf_low() )
          {
            ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              ipc_logbuf_low,
              "ipahal %s:%d Invalid Rule Action %d\n",
              "ipa_flt_gen_hw_rule_ipav5_5",
              853,
              *(unsigned int *)(*((_QWORD *)a1 + 3) + 4LL));
          }
          goto LABEL_39;
        }
      }
      else if ( !ipa3_get_ipc_logbuf() )
      {
        goto LABEL_11;
      }
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipahal %s:%d Invalid Rule Action %d\n",
        "ipa_flt_gen_hw_rule_ipav5_5",
        853,
        *(_DWORD *)(*((_QWORD *)a1 + 3) + 4LL));
      goto LABEL_11;
    }
    v6 = *(_QWORD *)a3 & 0xFE0FFFFFFFFFFFFFLL;
  }
LABEL_15:
  *(_QWORD *)a3 = v6;
  v9 = a1[1];
  if ( (unsigned int)v9 < 0x100 )
  {
    v10 = v6 & 0xFFFFFFFFFF00FFFFLL | (v9 << 16);
    *(_QWORD *)a3 = v10;
    v11 = v10 & 0xBFFFFFFFFFFFFFFFLL | ((unsigned __int64)(**((_BYTE **)a1 + 3) != 0) << 62);
    *(_QWORD *)a3 = v11;
    v12 = *(unsigned __int8 *)(*((_QWORD *)a1 + 3) + 359LL);
    if ( v12 < 0x10 )
    {
      v13 = v11 & 0xE1FFFFFFFFFFFFFFLL | (v12 << 57);
      *(_QWORD *)a3 = v13;
      v14 = v13 & 0x5FFFFFFFFFFFFFFFLL | ((unsigned __int64)(*(_BYTE *)(*((_QWORD *)a1 + 3) + 358LL) != 0) << 61);
      *(_QWORD *)a3 = v14;
      v15 = a1[2];
      if ( (unsigned int)v15 < 0x100 )
      {
        v16 = v14 & 0xFFFFFF00FFFFFFFFLL | (v15 << 32);
        *(_QWORD *)a3 = v16;
        v17 = a1[3];
        if ( (unsigned int)v17 >= 0x3FF )
        {
          if ( (unsigned int)__ratelimit(&ipa_flt_gen_hw_rule_ipav5_5__rs_234, "ipa_flt_gen_hw_rule_ipav5_5") )
          {
            printk(&unk_3D48CC, "ipa_flt_gen_hw_rule_ipav5_5");
            if ( !ipa3_get_ipc_logbuf() )
            {
LABEL_22:
              if ( ipa3_get_ipc_logbuf_low() )
              {
                v19 = ipa3_get_ipc_logbuf_low();
                ipc_log_string(v19, "ipahal %s:%d Invalid id 0x%X\n", "ipa_flt_gen_hw_rule_ipav5_5", 884, a1[3]);
              }
              goto LABEL_39;
            }
          }
          else if ( !ipa3_get_ipc_logbuf() )
          {
            goto LABEL_22;
          }
          v18 = ipa3_get_ipc_logbuf();
          ipc_log_string(v18, "ipahal %s:%d Invalid id 0x%X\n", "ipa_flt_gen_hw_rule_ipav5_5", 884, a1[3]);
          goto LABEL_22;
        }
        v26 = v16 & 0x7FF003FFFFFFFFFFLL | (v17 << 42);
        *(_QWORD *)a3 = v26;
        v27 = v26 & 0xFFFFFFFF00FFFFFFLL | ((unsigned __int64)*((unsigned __int8 *)a1 + 16) << 24);
        *(_QWORD *)a3 = v27;
        v28 = v27 & 0xFFFFFDFFFFFFFFFFLL | ((unsigned __int64)(*(_BYTE *)(*((_QWORD *)a1 + 3) + 362LL) != 0) << 41);
        *(_QWORD *)a3 = v28;
        v29 = (_BYTE *)(a3 + 8);
        v30 = *((_QWORD *)a1 + 3);
        v72[0] = a3 + 8;
        if ( *(_BYTE *)(v30 + 363) || *(_BYTE *)(v30 + 364) )
        {
          v31 = *(_WORD *)(a3 + 8);
          v29 = (_BYTE *)(a3 + 10);
          *(_QWORD *)a3 = v28 | 0x10000000000LL;
          v32 = 1;
          v33 = 8;
          v34 = *((_QWORD *)a1 + 3);
          v35 = v31 & 0xFFFE;
          v72[0] = a3 + 10;
          if ( *(_BYTE *)(v34 + 363) )
            v36 = v35 + 1;
          else
            v36 = v35;
          *(_WORD *)(a3 + 8) = v36;
          *(_WORD *)(a3 + 8) = v36 & 0xFF81 | (2 * (*(_BYTE *)(*((_QWORD *)a1 + 3) + 364LL) & 0x3F));
        }
        else
        {
          v32 = 0;
          v33 = 0;
          *(_QWORD *)a3 = v28 & 0x7FFFFEFFFFFFFFFFLL;
        }
        v37 = *((_BYTE **)a1 + 3);
        if ( v37[352] )
        {
          v38 = (unsigned __int8)v37[264];
          v39 = ipa_fltrt_calc_extra_wrd_bytes(v37 + 164);
          if ( v39 < 14 )
          {
            if ( v39 < 9 )
            {
              if ( v39 < 1 )
              {
                v45 = -2;
                v46 = &v29[v33];
                if ( !v32 )
                {
                  v45 = 0;
                  v29 = nullptr;
                }
                v41 = &v46[v45];
              }
              else
              {
                v44 = v32 ^ 1;
                if ( (unsigned int)v39 < 7 )
                  v44 = 1;
                if ( (v44 & 1) != 0 )
                {
                  v47 = -2;
                  if ( !v32 )
                    v47 = 0;
                  v41 = &v29[v47 + 8];
                }
                else
                {
                  v41 = v29 + 14;
                }
              }
            }
            else
            {
              v40 = -2;
              if ( !v32 )
                v40 = 0;
              v41 = &v29[v40 + 16];
            }
            if ( !v37[166] )
            {
LABEL_84:
              if ( v37[168] )
                v29 = ipa_write_8(v37[169], v29);
              if ( v37[212] )
                v29 = ipa_write_8(v37[213], v29);
              if ( v38 )
              {
                ipa_write_8(v37[265], v29);
                v50 = ipa_write_8(v37[266], v41);
                v51 = ipa_write_8(v37[267], v50);
                v52 = ipa_write_8(v37[268], v51);
                v53 = ipa_write_8(v37[269], v52);
                v54 = ipa_write_8(v37[270], v53);
                v55 = ipa_write_8(v37[271], v54);
                v56 = ipa_write_8(v37[272], v55);
                v57 = ipa_write_8(v37[273], v56);
                v58 = ipa_write_8(v37[282], v57);
                v59 = ipa_write_8(v37[283], v58);
                v60 = ipa_write_8(v37[284], v59);
                v61 = ipa_write_8(v37[285], v60);
                v62 = ipa_write_8(v37[286], v61);
                v63 = ipa_write_8(v37[287], v62);
                v64 = ipa_write_8(v37[288], v63);
                ipa_write_8(v37[289], v64);
                JUMPOUT(0x191E18);
              }
              JUMPOUT(0x192134);
            }
            if ( *(_DWORD *)ipahal_ctx >= 0x1Au )
            {
              __break(0x5512u);
              JUMPOUT(0x192618);
            }
            v48 = &ipahal_fltrt_objs[19 * *(unsigned int *)ipahal_ctx];
            if ( *((unsigned __int8 *)v48 + 144) != 255 )
            {
              v49 = 0;
LABEL_83:
              v29 = ipa_write_8(v49, v29);
              goto LABEL_84;
            }
            if ( *((unsigned __int8 *)v48 + 128) != 255 )
            {
              v49 = v37[167];
              goto LABEL_83;
            }
            printk(&unk_3FA214, "ipa_fltrt_generate_hw_rule_bdy_from_eq_5_5");
            if ( ipa3_get_ipc_logbuf() )
            {
              v69 = ipa3_get_ipc_logbuf();
              ipc_log_string(
                v69,
                "ipahal %s:%d no support for pure_ack and tos eqs\n",
                "ipa_fltrt_generate_hw_rule_bdy_from_eq_5_5",
                2885);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v70 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(
                v70,
                "ipahal %s:%d no support for pure_ack and tos eqs\n",
                "ipa_fltrt_generate_hw_rule_bdy_from_eq_5_5",
                2885);
            }
            goto LABEL_100;
          }
          if ( (unsigned int)__ratelimit(
                               &ipa_fltrt_generate_hw_rule_bdy_from_eq_5_5__rs,
                               "ipa_fltrt_generate_hw_rule_bdy_from_eq_5_5") )
          {
            printk(&unk_3C8B8C, "ipa_fltrt_generate_hw_rule_bdy_from_eq_5_5");
            if ( !ipa3_get_ipc_logbuf() )
            {
LABEL_95:
              if ( !ipa3_get_ipc_logbuf_low() )
                goto LABEL_100;
              goto LABEL_99;
            }
          }
          else if ( !ipa3_get_ipc_logbuf() )
          {
            goto LABEL_95;
          }
          v65 = ipa3_get_ipc_logbuf();
          ipc_log_string(v65, "ipahal %s:%d too much extra bytes\n", "ipa_fltrt_generate_hw_rule_bdy_from_eq_5_5", 2853);
          if ( !ipa3_get_ipc_logbuf_low() )
          {
LABEL_100:
            printk(&unk_3CEB33, "ipa_flt_gen_hw_rule_ipav5_5");
            if ( ipa3_get_ipc_logbuf() )
            {
              v67 = ipa3_get_ipc_logbuf();
              ipc_log_string(v67, "ipahal %s:%d fail to generate hw rule from eq\n", "ipa_flt_gen_hw_rule_ipav5_5", 908);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v68 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(v68, "ipahal %s:%d fail to generate hw rule from eq\n", "ipa_flt_gen_hw_rule_ipav5_5", 908);
            }
            goto LABEL_39;
          }
LABEL_99:
          v66 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v66, "ipahal %s:%d too much extra bytes\n", "ipa_fltrt_generate_hw_rule_bdy_from_eq_5_5", 2853);
          goto LABEL_100;
        }
        if ( !(unsigned int)ipa_fltrt_generate_hw_rule_bdy_5_5(*a1, v37 + 12, v72, &v71, v32) )
          JUMPOUT(0x192358);
        printk(&unk_3C2B3C, "ipa_flt_gen_hw_rule_ipav5_5");
        if ( ipa3_get_ipc_logbuf() )
        {
          v42 = ipa3_get_ipc_logbuf();
          ipc_log_string(v42, "ipahal %s:%d fail to generate hw rule\n", "ipa_flt_gen_hw_rule_ipav5_5", 915);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v43 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v43, "ipahal %s:%d fail to generate hw rule\n", "ipa_flt_gen_hw_rule_ipav5_5", 915);
        }
LABEL_39:
        JUMPOUT(0x1919B4);
      }
      if ( (unsigned int)__ratelimit(&ipa_flt_gen_hw_rule_ipav5_5__rs_233, "ipa_flt_gen_hw_rule_ipav5_5") )
      {
        printk(&unk_3FA248, "ipa_flt_gen_hw_rule_ipav5_5");
        if ( !ipa3_get_ipc_logbuf() )
        {
LABEL_37:
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v25 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v25, "ipahal %s:%d Invalid priority 0x%X\n", "ipa_flt_gen_hw_rule_ipav5_5", 877, a1[2]);
          }
          goto LABEL_39;
        }
      }
      else if ( !ipa3_get_ipc_logbuf() )
      {
        goto LABEL_37;
      }
      v24 = ipa3_get_ipc_logbuf();
      ipc_log_string(v24, "ipahal %s:%d Invalid priority 0x%X\n", "ipa_flt_gen_hw_rule_ipav5_5", 877, a1[2]);
      goto LABEL_37;
    }
    if ( (unsigned int)__ratelimit(&ipa_flt_gen_hw_rule_ipav5_5__rs_232, "ipa_flt_gen_hw_rule_ipav5_5") )
    {
      printk(&unk_3F11B2, "ipa_flt_gen_hw_rule_ipav5_5");
      if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_32:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v23 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v23,
            "ipahal %s:%d Invalid PDN idx 0x%X\n",
            "ipa_flt_gen_hw_rule_ipav5_5",
            868,
            *(unsigned __int8 *)(*((_QWORD *)a1 + 3) + 359LL));
        }
        goto LABEL_39;
      }
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
      goto LABEL_32;
    }
    v22 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v22,
      "ipahal %s:%d Invalid PDN idx 0x%X\n",
      "ipa_flt_gen_hw_rule_ipav5_5",
      868,
      *(unsigned __int8 *)(*((_QWORD *)a1 + 3) + 359LL));
    goto LABEL_32;
  }
  if ( (unsigned int)__ratelimit(&ipa_flt_gen_hw_rule_ipav5_5__rs_231, "ipa_flt_gen_hw_rule_ipav5_5") )
  {
    printk(&unk_3D768C, "ipa_flt_gen_hw_rule_ipav5_5");
    if ( !ipa3_get_ipc_logbuf() )
    {
LABEL_27:
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v21 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v21, "ipahal %s:%d Invalid RT table idx 0x%X\n", "ipa_flt_gen_hw_rule_ipav5_5", 860, a1[1]);
      }
      goto LABEL_39;
    }
  }
  else if ( !ipa3_get_ipc_logbuf() )
  {
    goto LABEL_27;
  }
  v20 = ipa3_get_ipc_logbuf();
  ipc_log_string(v20, "ipahal %s:%d Invalid RT table idx 0x%X\n", "ipa_flt_gen_hw_rule_ipav5_5", 860, a1[1]);
  goto LABEL_27;
}
