__int64 __fastcall ipa3_write_rsrc_grp_type_reg(unsigned int a1, __int64 a2, char a3, __int64 a4)
{
  unsigned int v4; // w8
  __int64 result; // x0
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v10; // x8
  __int64 v11; // x0
  unsigned int v12; // w8
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v29; // x8
  __int64 v30; // x0
  __int64 v32; // x8
  __int64 v33; // x0
  __int64 v35; // x8
  __int64 v36; // x0
  unsigned int v37; // w8
  __int64 v39; // x8
  __int64 v40; // x0
  __int64 v42; // x8
  __int64 v43; // x0
  __int64 v45; // x8
  __int64 v46; // x0
  __int64 v48; // x8
  __int64 v49; // x0
  __int64 v51; // x8
  __int64 v52; // x0
  __int64 v54; // x8
  __int64 v55; // x0
  __int64 v57; // x8
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v61; // x8
  __int64 v62; // x0
  __int64 v64; // x8
  __int64 v65; // x0
  __int64 v66; // x8
  __int64 v67; // x0
  __int64 v69; // x8
  __int64 v70; // x0
  __int64 v72; // x8
  __int64 v73; // x0
  __int64 v75; // x8
  __int64 v76; // x0

  v4 = *(unsigned __int8 *)(ipa3_ctx + 32244);
  if ( v4 > 0xD )
  {
    if ( *(unsigned __int8 *)(ipa3_ctx + 32244) <= 0x10u )
    {
      switch ( v4 )
      {
        case 0xEu:
          if ( (a3 & 1) != 0 )
          {
            if ( !a1 )
              goto LABEL_152;
            result = printk(&unk_3DF223, "ipa3_write_rsrc_grp_type_reg");
            v26 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v27 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v27 )
              {
                ipc_log_string(
                  v27,
                  "ipa %s:%d  Invalid source resource group,index #%d\n",
                  "ipa3_write_rsrc_grp_type_reg",
                  11973,
                  a1);
                v26 = ipa3_ctx;
              }
              result = *(_QWORD *)(v26 + 34160);
              if ( result )
                return ipc_log_string(
                         result,
                         "ipa %s:%d  Invalid source resource group,index #%d\n",
                         "ipa3_write_rsrc_grp_type_reg",
                         11973,
                         a1);
            }
          }
          else
          {
            if ( !a1 )
              goto LABEL_167;
            result = printk(&unk_3C7F40, "ipa3_write_rsrc_grp_type_reg");
            v42 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v43 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v43 )
              {
                ipc_log_string(
                  v43,
                  "ipa %s:%d  Invalid destination resource group,index #%d\n",
                  "ipa3_write_rsrc_grp_type_reg",
                  11986,
                  a1);
                v42 = ipa3_ctx;
              }
              result = *(_QWORD *)(v42 + 34160);
              if ( result )
                return ipc_log_string(
                         result,
                         "ipa %s:%d  Invalid destination resource group,index #%d\n",
                         "ipa3_write_rsrc_grp_type_reg",
                         11986,
                         a1);
            }
          }
          return result;
        case 0xFu:
          if ( (a3 & 1) != 0 )
          {
            if ( a1 < 2 )
              goto LABEL_152;
            if ( a1 == 2 )
              goto LABEL_151;
            result = printk(&unk_3DF223, "ipa3_write_rsrc_grp_type_reg");
            v29 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v30 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v30 )
              {
                ipc_log_string(
                  v30,
                  "ipa %s:%d  Invalid source resource group,index #%d\n",
                  "ipa3_write_rsrc_grp_type_reg",
                  12008,
                  a1);
                v29 = ipa3_ctx;
              }
              result = *(_QWORD *)(v29 + 34160);
              if ( result )
                return ipc_log_string(
                         result,
                         "ipa %s:%d  Invalid source resource group,index #%d\n",
                         "ipa3_write_rsrc_grp_type_reg",
                         12008,
                         a1);
            }
          }
          else
          {
            if ( a1 - 2 < 2 )
              goto LABEL_166;
            if ( a1 <= 1 )
              goto LABEL_167;
            result = printk(&unk_3C7F40, "ipa3_write_rsrc_grp_type_reg");
            v48 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v49 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v49 )
              {
                ipc_log_string(
                  v49,
                  "ipa %s:%d  Invalid destination resource group,index #%d\n",
                  "ipa3_write_rsrc_grp_type_reg",
                  12028,
                  a1);
                v48 = ipa3_ctx;
              }
              result = *(_QWORD *)(v48 + 34160);
              if ( result )
                return ipc_log_string(
                         result,
                         "ipa %s:%d  Invalid destination resource group,index #%d\n",
                         "ipa3_write_rsrc_grp_type_reg",
                         12028,
                         a1);
            }
          }
          return result;
        case 0x10u:
          if ( (a3 & 1) != 0 )
          {
            if ( !a1 )
              goto LABEL_152;
            result = printk(&unk_3DF223, "ipa3_write_rsrc_grp_type_reg");
            v10 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v11 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v11 )
              {
                ipc_log_string(
                  v11,
                  "ipa %s:%d  Invalid source resource group,index #%d\n",
                  "ipa3_write_rsrc_grp_type_reg",
                  12044,
                  a1);
                v10 = ipa3_ctx;
              }
              result = *(_QWORD *)(v10 + 34160);
              if ( result )
                return ipc_log_string(
                         result,
                         "ipa %s:%d  Invalid source resource group,index #%d\n",
                         "ipa3_write_rsrc_grp_type_reg",
                         12044,
                         a1);
            }
          }
          else
          {
            if ( a1 == 2 )
              goto LABEL_166;
            if ( !a1 )
              goto LABEL_167;
            result = printk(&unk_3C7F40, "ipa3_write_rsrc_grp_type_reg");
            v45 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v46 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v46 )
              {
                ipc_log_string(
                  v46,
                  "ipa %s:%d  Invalid destination resource group,index #%d\n",
                  "ipa3_write_rsrc_grp_type_reg",
                  12062,
                  a1);
                v45 = ipa3_ctx;
              }
              result = *(_QWORD *)(v45 + 34160);
              if ( result )
                return ipc_log_string(
                         result,
                         "ipa %s:%d  Invalid destination resource group,index #%d\n",
                         "ipa3_write_rsrc_grp_type_reg",
                         12062,
                         a1);
            }
          }
          return result;
      }
      goto LABEL_179;
    }
    if ( v4 - 17 < 4 )
    {
      if ( (a3 & 1) != 0 )
      {
        if ( a1 <= 5 )
          goto LABEL_149;
        result = printk(&unk_3DF223, "ipa3_write_rsrc_grp_type_reg");
        v17 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v18 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v18 )
          {
            ipc_log_string(
              v18,
              "ipa %s:%d  Invalid source resource group,index #%d\n",
              "ipa3_write_rsrc_grp_type_reg",
              12094,
              a1);
            v17 = ipa3_ctx;
          }
          result = *(_QWORD *)(v17 + 34160);
          if ( result )
            return ipc_log_string(
                     result,
                     "ipa %s:%d  Invalid source resource group,index #%d\n",
                     "ipa3_write_rsrc_grp_type_reg",
                     12094,
                     a1);
        }
        return result;
      }
      if ( (int)a1 <= 3 )
      {
        if ( a1 < 2 )
          goto LABEL_167;
        if ( a1 - 2 < 2 )
          goto LABEL_166;
LABEL_185:
        result = printk(&unk_3C7F40, "ipa3_write_rsrc_grp_type_reg");
        v69 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v70 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v70 )
          {
            ipc_log_string(
              v70,
              "ipa %s:%d  Invalid destination resource group,index #%d\n",
              "ipa3_write_rsrc_grp_type_reg",
              12125,
              a1);
            v69 = ipa3_ctx;
          }
          result = *(_QWORD *)(v69 + 34160);
          if ( result )
            return ipc_log_string(
                     result,
                     "ipa %s:%d  Invalid destination resource group,index #%d\n",
                     "ipa3_write_rsrc_grp_type_reg",
                     12125,
                     a1);
        }
        return result;
      }
      if ( a1 - 4 < 2 )
        goto LABEL_162;
      if ( a1 != 6 )
        goto LABEL_185;
LABEL_171:
      v59 = 83;
      return ((__int64 (__fastcall *)(__int64, __int64, __int64))ipahal_write_reg_n_fields)(v59, a2, a4);
    }
    if ( v4 - 21 < 2 )
    {
      v37 = a1 - 2;
      if ( (a3 & 1) != 0 )
      {
        if ( v37 < 2 )
          goto LABEL_151;
        if ( a1 <= 1 )
          goto LABEL_152;
        result = printk(&unk_3DF223, "ipa3_write_rsrc_grp_type_reg");
        v39 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v40 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v40 )
          {
            ipc_log_string(
              v40,
              "ipa %s:%d  Invalid source resource group,index #%d\n",
              "ipa3_write_rsrc_grp_type_reg",
              12150,
              a1);
            v39 = ipa3_ctx;
          }
          result = *(_QWORD *)(v39 + 34160);
          if ( result )
            return ipc_log_string(
                     result,
                     "ipa %s:%d  Invalid source resource group,index #%d\n",
                     "ipa3_write_rsrc_grp_type_reg",
                     12150,
                     a1);
        }
      }
      else
      {
        if ( v37 < 2 )
          goto LABEL_166;
        if ( a1 <= 1 )
          goto LABEL_167;
        result = printk(&unk_3C7F40, "ipa3_write_rsrc_grp_type_reg");
        v61 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v62 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v62 )
          {
            ipc_log_string(
              v62,
              "ipa %s:%d  Invalid destination resource group,index #%d\n",
              "ipa3_write_rsrc_grp_type_reg",
              12170,
              a1);
            v61 = ipa3_ctx;
          }
          result = *(_QWORD *)(v61 + 34160);
          if ( result )
            return ipc_log_string(
                     result,
                     "ipa %s:%d  Invalid destination resource group,index #%d\n",
                     "ipa3_write_rsrc_grp_type_reg",
                     12170,
                     a1);
        }
      }
      return result;
    }
    if ( v4 != 23 )
      goto LABEL_179;
    if ( (a3 & 1) != 0 )
    {
      if ( a1 <= 5 )
        goto LABEL_149;
      result = printk(&unk_3DF223, "ipa3_write_rsrc_grp_type_reg");
      v75 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v76 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v76 )
        {
          ipc_log_string(
            v76,
            "ipa %s:%d  Invalid source resource group,index #%d\n",
            "ipa3_write_rsrc_grp_type_reg",
            12200,
            a1);
          v75 = ipa3_ctx;
        }
        result = *(_QWORD *)(v75 + 34160);
        if ( result )
          return ipc_log_string(
                   result,
                   "ipa %s:%d  Invalid source resource group,index #%d\n",
                   "ipa3_write_rsrc_grp_type_reg",
                   12200,
                   a1);
      }
      return result;
    }
    if ( (int)a1 > 3 )
    {
      if ( a1 - 4 < 2 )
        goto LABEL_162;
      if ( a1 == 6 )
        goto LABEL_171;
    }
    else
    {
      if ( a1 < 2 )
        goto LABEL_167;
      if ( a1 - 2 < 2 )
        goto LABEL_166;
    }
    result = printk(&unk_3C7F40, "ipa3_write_rsrc_grp_type_reg");
    v64 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v65 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v65 )
      {
        ipc_log_string(
          v65,
          "ipa %s:%d  Invalid destination resource group,index #%d\n",
          "ipa3_write_rsrc_grp_type_reg",
          12231,
          a1);
        v64 = ipa3_ctx;
      }
      result = *(_QWORD *)(v64 + 34160);
      if ( result )
        return ipc_log_string(
                 result,
                 "ipa %s:%d  Invalid destination resource group,index #%d\n",
                 "ipa3_write_rsrc_grp_type_reg",
                 12231,
                 a1);
    }
    return result;
  }
  if ( *(unsigned __int8 *)(ipa3_ctx + 32244) <= 7u )
  {
    if ( v4 - 1 < 3 )
    {
      if ( (a3 & 1) != 0 )
      {
        if ( a1 - 2 < 2 )
          goto LABEL_151;
        if ( a1 <= 1 )
          goto LABEL_152;
        result = printk(&unk_3DF223, "ipa3_write_rsrc_grp_type_reg");
        v20 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v21 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v21 )
          {
            ipc_log_string(
              v21,
              "ipa %s:%d  Invalid source resource group,index #%d\n",
              "ipa3_write_rsrc_grp_type_reg",
              11805,
              a1);
            v20 = ipa3_ctx;
          }
          result = *(_QWORD *)(v20 + 34160);
          if ( result )
            return ipc_log_string(
                     result,
                     "ipa %s:%d  Invalid source resource group,index #%d\n",
                     "ipa3_write_rsrc_grp_type_reg",
                     11805,
                     a1);
        }
      }
      else
      {
        if ( a1 < 2 )
          goto LABEL_167;
        if ( a1 == 2 )
          goto LABEL_166;
        result = printk(&unk_3C7F40, "ipa3_write_rsrc_grp_type_reg");
        v35 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v36 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v36 )
          {
            ipc_log_string(
              v36,
              "ipa %s:%d  Invalid destination resource group,index #%d\n",
              "ipa3_write_rsrc_grp_type_reg",
              11824,
              a1);
            v35 = ipa3_ctx;
          }
          result = *(_QWORD *)(v35 + 34160);
          if ( result )
            return ipc_log_string(
                     result,
                     "ipa %s:%d  Invalid destination resource group,index #%d\n",
                     "ipa3_write_rsrc_grp_type_reg",
                     11824,
                     a1);
        }
      }
      return result;
    }
    if ( v4 - 4 < 3 )
    {
      if ( (a3 & 1) != 0 )
      {
        if ( a1 - 2 >= 2 )
        {
          if ( a1 > 1 )
          {
            result = printk(&unk_3DF223, "ipa3_write_rsrc_grp_type_reg");
            v7 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v8 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v8 )
              {
                ipc_log_string(
                  v8,
                  "ipa %s:%d  Invalid source resource group,index #%d\n",
                  "ipa3_write_rsrc_grp_type_reg",
                  11851,
                  a1);
                v7 = ipa3_ctx;
              }
              result = *(_QWORD *)(v7 + 34160);
              if ( result )
                return ipc_log_string(
                         result,
                         "ipa %s:%d  Invalid source resource group,index #%d\n",
                         "ipa3_write_rsrc_grp_type_reg",
                         11851,
                         a1);
            }
            return result;
          }
          goto LABEL_152;
        }
LABEL_151:
        v59 = 77;
        return ((__int64 (__fastcall *)(__int64, __int64, __int64))ipahal_write_reg_n_fields)(v59, a2, a4);
      }
      if ( a1 >= 2 )
      {
        if ( a1 != 2 )
        {
          result = printk(&unk_3C7F40, "ipa3_write_rsrc_grp_type_reg");
          v32 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v33 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v33 )
            {
              ipc_log_string(
                v33,
                "ipa %s:%d  Invalid destination resource group,index #%d\n",
                "ipa3_write_rsrc_grp_type_reg",
                11871,
                a1);
              v32 = ipa3_ctx;
            }
            result = *(_QWORD *)(v32 + 34160);
            if ( result )
              return ipc_log_string(
                       result,
                       "ipa %s:%d  Invalid destination resource group,index #%d\n",
                       "ipa3_write_rsrc_grp_type_reg",
                       11871,
                       a1);
          }
          return result;
        }
LABEL_166:
        v59 = 81;
        return ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD))ipahal_write_reg_n_fields)(v59, a2, a4);
      }
LABEL_167:
      v59 = 80;
      return ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD))ipahal_write_reg_n_fields)(v59, a2, a4);
    }
    if ( !*(_BYTE *)(ipa3_ctx + 32244) )
    {
      if ( (a3 & 1) != 0 )
      {
        if ( a1 > 5 )
        {
          result = printk(&unk_3DF223, "ipa3_write_rsrc_grp_type_reg");
          v54 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v55 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v55 )
            {
              ipc_log_string(
                v55,
                "ipa %s:%d  Invalid source resource group,index #%d\n",
                "ipa3_write_rsrc_grp_type_reg",
                11754,
                a1);
              v54 = ipa3_ctx;
            }
            result = *(_QWORD *)(v54 + 34160);
            if ( result )
              return ipc_log_string(
                       result,
                       "ipa %s:%d  Invalid source resource group,index #%d\n",
                       "ipa3_write_rsrc_grp_type_reg",
                       11754,
                       a1);
          }
          return result;
        }
LABEL_149:
        if ( ((1 << a1) & 3) == 0 )
        {
          if ( ((1 << a1) & 0xC) != 0 )
            goto LABEL_151;
          goto LABEL_153;
        }
LABEL_152:
        v59 = 76;
        return ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD))ipahal_write_reg_n_fields)(v59, a2, a4);
      }
      if ( a1 <= 5 )
      {
        if ( ((1 << a1) & 3) != 0 )
          goto LABEL_167;
        if ( ((1 << a1) & 0xC) != 0 )
          goto LABEL_166;
        goto LABEL_162;
      }
      result = printk(&unk_3C7F40, "ipa3_write_rsrc_grp_type_reg");
      v72 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v73 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v73 )
        {
          ipc_log_string(
            v73,
            "ipa %s:%d  Invalid destination resource group,index #%d\n",
            "ipa3_write_rsrc_grp_type_reg",
            11780,
            a1);
          v72 = ipa3_ctx;
        }
        result = *(_QWORD *)(v72 + 34160);
        if ( result )
          return ipc_log_string(
                   result,
                   "ipa %s:%d  Invalid destination resource group,index #%d\n",
                   "ipa3_write_rsrc_grp_type_reg",
                   11780,
                   a1);
      }
      return result;
    }
LABEL_179:
    result = printk(&unk_3E4740, "ipa3_write_rsrc_grp_type_reg");
    v66 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v67 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v67 )
      {
        ipc_log_string(v67, "ipa %s:%d invalid hw type\n", "ipa3_write_rsrc_grp_type_reg", 12238);
        v66 = ipa3_ctx;
      }
      result = *(_QWORD *)(v66 + 34160);
      if ( result )
        result = ipc_log_string(result, "ipa %s:%d invalid hw type\n", "ipa3_write_rsrc_grp_type_reg", 12238);
    }
    __break(0x800u);
    return result;
  }
  if ( v4 - 9 >= 5 )
  {
    if ( v4 == 8 )
    {
      if ( (a3 & 1) != 0 )
      {
        if ( !a1 )
          goto LABEL_152;
        result = printk(&unk_3DF223, "ipa3_write_rsrc_grp_type_reg");
        v51 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v52 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v52 )
          {
            ipc_log_string(
              v52,
              "ipa %s:%d  Invalid source resource group,index #%d\n",
              "ipa3_write_rsrc_grp_type_reg",
              11887,
              a1);
            v51 = ipa3_ctx;
          }
          result = *(_QWORD *)(v51 + 34160);
          if ( result )
            return ipc_log_string(
                     result,
                     "ipa %s:%d  Invalid source resource group,index #%d\n",
                     "ipa3_write_rsrc_grp_type_reg",
                     11887,
                     a1);
        }
      }
      else
      {
        if ( !a1 )
          goto LABEL_167;
        result = printk(&unk_3C7F40, "ipa3_write_rsrc_grp_type_reg");
        v57 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v58 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v58 )
          {
            ipc_log_string(
              v58,
              "ipa %s:%d  Invalid destination resource group,index #%d\n",
              "ipa3_write_rsrc_grp_type_reg",
              11900,
              a1);
            v57 = ipa3_ctx;
          }
          result = *(_QWORD *)(v57 + 34160);
          if ( result )
            return ipc_log_string(
                     result,
                     "ipa %s:%d  Invalid destination resource group,index #%d\n",
                     "ipa3_write_rsrc_grp_type_reg",
                     11900,
                     a1);
        }
      }
      return result;
    }
    goto LABEL_179;
  }
  v12 = a1 - 2;
  if ( (a3 & 1) != 0 )
  {
    if ( a1 < 2 )
      goto LABEL_152;
    if ( v12 < 2 )
      goto LABEL_151;
    if ( a1 == 4 )
    {
LABEL_153:
      v59 = 78;
      return ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD))ipahal_write_reg_n_fields)(v59, a2, a4);
    }
    result = printk(&unk_3DF223, "ipa3_write_rsrc_grp_type_reg");
    v14 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v15 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v15 )
      {
        ipc_log_string(
          v15,
          "ipa %s:%d  Invalid source resource group,index #%d\n",
          "ipa3_write_rsrc_grp_type_reg",
          11932,
          a1);
        v14 = ipa3_ctx;
      }
      result = *(_QWORD *)(v14 + 34160);
      if ( result )
        return ipc_log_string(
                 result,
                 "ipa %s:%d  Invalid source resource group,index #%d\n",
                 "ipa3_write_rsrc_grp_type_reg",
                 11932,
                 a1);
    }
  }
  else
  {
    if ( a1 < 2 )
      goto LABEL_167;
    if ( v12 < 2 )
      goto LABEL_166;
    if ( a1 == 4 )
    {
LABEL_162:
      v59 = 82;
      return ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD))ipahal_write_reg_n_fields)(v59, a2, a4);
    }
    result = printk(&unk_3C7F40, "ipa3_write_rsrc_grp_type_reg");
    v23 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v24 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v24 )
      {
        ipc_log_string(
          v24,
          "ipa %s:%d  Invalid destination resource group,index #%d\n",
          "ipa3_write_rsrc_grp_type_reg",
          11957,
          a1);
        v23 = ipa3_ctx;
      }
      result = *(_QWORD *)(v23 + 34160);
      if ( result )
        return ipc_log_string(
                 result,
                 "ipa %s:%d  Invalid destination resource group,index #%d\n",
                 "ipa3_write_rsrc_grp_type_reg",
                 11957,
                 a1);
    }
  }
  return result;
}
