__int64 __fastcall ipa_fltrt_parse_hw_rule_eq(char *a1, int a2, unsigned __int16 *a3, _DWORD *a4)
{
  unsigned __int64 v7; // x23
  __int64 ipc_logbuf_low; // x0
  unsigned int *v10; // x8
  unsigned int v11; // w9
  __int64 v12; // x10
  __int64 v13; // x10
  int v14; // w0
  char *v15; // x23
  char *v16; // x22
  __int64 v17; // x0
  unsigned int v18; // w8
  char v19; // t1
  char v20; // t1
  char v21; // t1
  int v22; // w9
  int v23; // w9
  char v24; // w8
  char v25; // w8
  int v26; // w9
  char v27; // w8
  int v28; // w8
  int v29; // w8
  int v30; // w9
  char v31; // t1
  int v32; // t1
  unsigned __int16 v33; // t1
  int v34; // t1
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 result; // x0
  __int64 v38; // x0
  char v39; // w8
  int v40; // w8
  char v41; // w8
  unsigned __int16 v42; // w8
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 ipc_logbuf; // x0
  __int64 v46; // x0
  char v47; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v48; // [xsp+8h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v47 = 0;
  if ( a1 && a3 && a4 )
  {
    v7 = *a3;
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipahal %s:%d eq_bitmap=0x%x\n", "ipa_fltrt_parse_hw_rule_eq", 3952, v7);
    }
    v10 = (unsigned int *)ipahal_ctx;
    v11 = *(_DWORD *)ipahal_ctx;
    if ( *(_DWORD *)ipahal_ctx >= 0x1Au )
      goto LABEL_128;
    v12 = LOBYTE(ipahal_fltrt_objs[19 * v11 + 18]);
    if ( v12 != 255 && ((v7 >> v12) & 1) != 0 )
    {
      *((_BYTE *)a3 + 2) = 1;
      v10 = (unsigned int *)ipahal_ctx;
      v11 = *(_DWORD *)ipahal_ctx;
      if ( *(_DWORD *)ipahal_ctx > 0x19u )
        goto LABEL_128;
    }
    if ( v11 > 0x19 )
      goto LABEL_127;
    v13 = LOBYTE(ipahal_fltrt_objs[19 * v11 + 16]);
    if ( v13 != 255 && ((v7 >> v13) & 1) != 0 )
    {
      *((_BYTE *)a3 + 2) = 1;
      v10 = (unsigned int *)ipahal_ctx;
      v11 = *(_DWORD *)ipahal_ctx;
      if ( *(_DWORD *)ipahal_ctx > 0x19u )
        goto LABEL_128;
    }
    if ( v11 > 0x19 )
      goto LABEL_127;
    if ( ((v7 >> BYTE1(ipahal_fltrt_objs[19 * v11 + 16])) & 1) != 0 )
    {
      *((_BYTE *)a3 + 4) = 1;
      v10 = (unsigned int *)ipahal_ctx;
      v11 = *(_DWORD *)ipahal_ctx;
      if ( *(_DWORD *)ipahal_ctx > 0x19u )
        goto LABEL_128;
    }
    if ( v11 > 0x19 )
      goto LABEL_127;
    if ( ((v7 >> BYTE2(ipahal_fltrt_objs[19 * v11 + 16])) & 1) != 0 )
    {
      *((_BYTE *)a3 + 48) = 1;
      v11 = *v10;
      if ( *v10 > 0x19 )
        goto LABEL_128;
    }
    if ( v11 > 0x19 )
      goto LABEL_127;
    if ( ((v7 >> BYTE3(ipahal_fltrt_objs[19 * v11 + 16])) & 1) != 0 )
    {
      ++*((_BYTE *)a3 + 100);
      v11 = *v10;
      if ( *v10 > 0x19 )
        goto LABEL_128;
    }
    if ( v11 > 0x19 )
      goto LABEL_127;
    if ( ((v7 >> BYTE4(ipahal_fltrt_objs[19 * v11 + 16])) & 1) != 0 )
    {
      ++*((_BYTE *)a3 + 100);
      v11 = *v10;
      if ( *v10 > 0x19 )
        goto LABEL_128;
    }
    if ( v11 > 0x19 )
      goto LABEL_127;
    if ( ((v7 >> BYTE5(ipahal_fltrt_objs[19 * v11 + 16])) & 1) != 0 )
    {
      ++*((_BYTE *)a3 + 20);
      v11 = *v10;
      if ( *v10 > 0x19 )
        goto LABEL_128;
    }
    if ( v11 > 0x19 )
      goto LABEL_127;
    if ( ((v7 >> BYTE6(ipahal_fltrt_objs[19 * v11 + 16])) & 1) != 0 )
    {
      ++*((_BYTE *)a3 + 20);
      v11 = *v10;
      if ( *v10 > 0x19 )
        goto LABEL_128;
    }
    if ( v11 > 0x19 )
      goto LABEL_127;
    if ( ((v7 >> HIBYTE(ipahal_fltrt_objs[19 * v11 + 16])) & 1) != 0 )
    {
      ++*((_BYTE *)a3 + 72);
      v11 = *v10;
      if ( *v10 > 0x19 )
        goto LABEL_128;
    }
    if ( v11 > 0x19 )
      goto LABEL_127;
    if ( ((v7 >> LOBYTE(ipahal_fltrt_objs[19 * v11 + 17])) & 1) != 0 )
    {
      ++*((_BYTE *)a3 + 72);
      v11 = *v10;
      if ( *v10 > 0x19 )
        goto LABEL_128;
    }
    if ( v11 > 0x19 )
      goto LABEL_127;
    if ( ((v7 >> BYTE1(ipahal_fltrt_objs[19 * v11 + 17])) & 1) != 0 )
    {
      *((_BYTE *)a3 + 167) = 1;
      v11 = *v10;
      if ( *v10 > 0x19 )
        goto LABEL_128;
    }
    if ( v11 > 0x19 )
      goto LABEL_127;
    if ( ((v7 >> BYTE2(ipahal_fltrt_objs[19 * v11 + 17])) & 1) != 0 )
    {
      ++*((_BYTE *)a3 + 6);
      v10 = (unsigned int *)ipahal_ctx;
      v11 = *(_DWORD *)ipahal_ctx;
      if ( *(_DWORD *)ipahal_ctx > 0x19u )
        goto LABEL_128;
    }
    if ( v11 > 0x19 )
      goto LABEL_127;
    if ( ((v7 >> BYTE3(ipahal_fltrt_objs[19 * v11 + 17])) & 1) != 0 )
    {
      ++*((_BYTE *)a3 + 6);
      v10 = (unsigned int *)ipahal_ctx;
      v11 = *(_DWORD *)ipahal_ctx;
      if ( *(_DWORD *)ipahal_ctx > 0x19u )
        goto LABEL_128;
    }
    if ( v11 > 0x19 )
      goto LABEL_127;
    if ( ((v7 >> BYTE4(ipahal_fltrt_objs[19 * v11 + 17])) & 1) != 0 )
    {
      *((_BYTE *)a3 + 62) = 1;
      v11 = *v10;
      if ( *v10 > 0x19 )
        goto LABEL_128;
    }
    if ( v11 > 0x19 )
      goto LABEL_127;
    if ( ((v7 >> BYTE5(ipahal_fltrt_objs[19 * v11 + 17])) & 1) != 0 )
    {
      *((_BYTE *)a3 + 56) = 1;
      v11 = *v10;
      if ( *v10 > 0x19 )
        goto LABEL_128;
    }
    if ( v11 > 0x19 )
      goto LABEL_127;
    if ( ((v7 >> BYTE6(ipahal_fltrt_objs[19 * v11 + 17])) & 1) != 0 )
    {
      *((_BYTE *)a3 + 50) = 1;
      v11 = *v10;
      if ( *v10 > 0x19 )
        goto LABEL_128;
    }
    if ( v11 > 0x19 )
    {
LABEL_127:
      __break(1u);
      goto LABEL_128;
    }
    if ( ((v7 >> HIBYTE(ipahal_fltrt_objs[19 * v11 + 17])) & 1) != 0 )
      *((_BYTE *)a3 + 180) = 1;
    v14 = ipa_fltrt_calc_extra_wrd_bytes(a3);
    if ( v14 < 14 )
    {
      if ( v14 < 9 )
      {
        v15 = &a1[a2];
        if ( v14 < 1 )
        {
          v16 = &a1[a2];
          v15 = &v47;
          v47 = 0;
          if ( !ipa3_get_ipc_logbuf_low() )
            goto LABEL_66;
        }
        else
        {
          v16 = v15 + 8;
          if ( !ipa3_get_ipc_logbuf_low() )
          {
LABEL_66:
            v18 = *(_DWORD *)ipahal_ctx;
            if ( *(_DWORD *)ipahal_ctx <= 0x19u )
            {
              if ( LOBYTE(ipahal_fltrt_objs[19 * v18 + 16]) == 255
                || !*((_BYTE *)a3 + 2)
                || (v19 = *v15,
                    ++v15,
                    *((_BYTE *)a3 + 3) = v19,
                    v18 = *(_DWORD *)ipahal_ctx,
                    *(_DWORD *)ipahal_ctx <= 0x19u) )
              {
                if ( v18 <= 0x19 )
                {
                  if ( LOBYTE(ipahal_fltrt_objs[19 * v18 + 18]) != 255 && *((_BYTE *)a3 + 2) )
                  {
                    ++v15;
                    *((_BYTE *)a3 + 3) = 0;
                  }
                  if ( *((_BYTE *)a3 + 4) )
                  {
                    v20 = *v15++;
                    *((_BYTE *)a3 + 5) = v20;
                  }
                  if ( *((_BYTE *)a3 + 48) )
                  {
                    v21 = *v15++;
                    *((_BYTE *)a3 + 49) = v21;
                  }
                  v22 = *((unsigned __int8 *)a3 + 100);
                  if ( *((_BYTE *)a3 + 100) )
                  {
                    *((_BYTE *)a3 + 101) = *v15;
                    *((_BYTE *)a3 + 102) = *v16;
                    *((_BYTE *)a3 + 103) = v16[1];
                    *((_BYTE *)a3 + 104) = v16[2];
                    *((_BYTE *)a3 + 105) = v16[3];
                    *((_BYTE *)a3 + 106) = v16[4];
                    *((_BYTE *)a3 + 107) = v16[5];
                    *((_BYTE *)a3 + 108) = v16[6];
                    *((_BYTE *)a3 + 109) = v16[7];
                    *((_BYTE *)a3 + 118) = v16[8];
                    *((_BYTE *)a3 + 119) = v16[9];
                    *((_BYTE *)a3 + 120) = v16[10];
                    *((_BYTE *)a3 + 121) = v16[11];
                    *((_BYTE *)a3 + 122) = v16[12];
                    *((_BYTE *)a3 + 123) = v16[13];
                    *((_BYTE *)a3 + 124) = v16[14];
                    *((_BYTE *)a3 + 125) = v16[15];
                    *((_BYTE *)a3 + 110) = v16[16];
                    *((_BYTE *)a3 + 111) = v16[17];
                    *((_BYTE *)a3 + 112) = v16[18];
                    *((_BYTE *)a3 + 113) = v16[19];
                    *((_BYTE *)a3 + 114) = v16[20];
                    *((_BYTE *)a3 + 115) = v16[21];
                    *((_BYTE *)a3 + 116) = v16[22];
                    *((_BYTE *)a3 + 117) = v16[23];
                    *((_BYTE *)a3 + 126) = v16[24];
                    *((_BYTE *)a3 + 127) = v16[25];
                    *((_BYTE *)a3 + 128) = v16[26];
                    *((_BYTE *)a3 + 129) = v16[27];
                    *((_BYTE *)a3 + 130) = v16[28];
                    *((_BYTE *)a3 + 131) = v16[29];
                    *((_BYTE *)a3 + 132) = v16[30];
                    *((_BYTE *)a3 + 133) = v16[31];
                    if ( v22 != 1 )
                    {
                      v24 = v15[1];
                      v15 += 2;
                      *((_BYTE *)a3 + 134) = v24;
                      *((_BYTE *)a3 + 135) = v16[32];
                      *((_BYTE *)a3 + 136) = v16[33];
                      *((_BYTE *)a3 + 137) = v16[34];
                      *((_BYTE *)a3 + 138) = v16[35];
                      *((_BYTE *)a3 + 139) = v16[36];
                      *((_BYTE *)a3 + 140) = v16[37];
                      *((_BYTE *)a3 + 141) = v16[38];
                      *((_BYTE *)a3 + 142) = v16[39];
                      *((_BYTE *)a3 + 151) = v16[40];
                      *((_BYTE *)a3 + 152) = v16[41];
                      *((_BYTE *)a3 + 153) = v16[42];
                      *((_BYTE *)a3 + 154) = v16[43];
                      *((_BYTE *)a3 + 155) = v16[44];
                      *((_BYTE *)a3 + 156) = v16[45];
                      *((_BYTE *)a3 + 157) = v16[46];
                      *((_BYTE *)a3 + 158) = v16[47];
                      *((_BYTE *)a3 + 143) = v16[48];
                      *((_BYTE *)a3 + 144) = v16[49];
                      *((_BYTE *)a3 + 145) = v16[50];
                      *((_BYTE *)a3 + 146) = v16[51];
                      *((_BYTE *)a3 + 147) = v16[52];
                      *((_BYTE *)a3 + 148) = v16[53];
                      *((_BYTE *)a3 + 149) = v16[54];
                      *((_BYTE *)a3 + 150) = v16[55];
                      *((_BYTE *)a3 + 159) = v16[56];
                      *((_BYTE *)a3 + 160) = v16[57];
                      *((_BYTE *)a3 + 161) = v16[58];
                      *((_BYTE *)a3 + 162) = v16[59];
                      *((_BYTE *)a3 + 163) = v16[60];
                      *((_BYTE *)a3 + 164) = v16[61];
                      *((_BYTE *)a3 + 165) = v16[62];
                      v25 = v16[63];
                      v16 += 64;
                      *((_BYTE *)a3 + 166) = v25;
                      v23 = *((unsigned __int8 *)a3 + 20);
                      if ( !*((_BYTE *)a3 + 20) )
                        goto LABEL_86;
LABEL_84:
                      *((_BYTE *)a3 + 24) = *v15;
                      *((_DWORD *)a3 + 7) = *(_DWORD *)v16;
                      *((_DWORD *)a3 + 8) = *((_DWORD *)v16 + 1);
                      if ( v23 != 1 )
                      {
                        v27 = v15[1];
                        v15 += 2;
                        *((_BYTE *)a3 + 36) = v27;
                        *((_DWORD *)a3 + 10) = *((_DWORD *)v16 + 2);
                        v28 = *((_DWORD *)v16 + 3);
                        v16 += 16;
                        *((_DWORD *)a3 + 11) = v28;
                        v26 = *((unsigned __int8 *)a3 + 72);
                        if ( !*((_BYTE *)a3 + 72) )
                          goto LABEL_91;
LABEL_89:
                        *((_BYTE *)a3 + 76) = *v15;
                        *((_DWORD *)a3 + 20) = *(_DWORD *)v16;
                        *((_DWORD *)a3 + 21) = *((_DWORD *)v16 + 1);
                        if ( v26 != 1 )
                        {
                          v39 = v15[1];
                          v15 += 2;
                          *((_BYTE *)a3 + 88) = v39;
                          *((_DWORD *)a3 + 23) = *((_DWORD *)v16 + 2);
                          v40 = *((_DWORD *)v16 + 3);
                          v16 += 16;
                          *((_DWORD *)a3 + 24) = v40;
                          if ( !*((_BYTE *)a3 + 167) )
                          {
LABEL_93:
                            v30 = *((unsigned __int8 *)a3 + 6);
                            if ( *((_BYTE *)a3 + 6) )
                            {
                              *((_BYTE *)a3 + 8) = *v15;
                              a3[6] = *(_WORD *)v16;
                              a3[5] = *((_WORD *)v16 + 1);
                              if ( v30 != 1 )
                              {
                                v41 = v15[1];
                                v15 += 2;
                                *((_BYTE *)a3 + 14) = v41;
                                a3[9] = *((_WORD *)v16 + 2);
                                v42 = *((_WORD *)v16 + 3);
                                v16 += 8;
                                a3[8] = v42;
                                if ( !*((_BYTE *)a3 + 62) )
                                  goto LABEL_98;
                                goto LABEL_97;
                              }
                              v16 += 4;
                              ++v15;
                            }
                            if ( !*((_BYTE *)a3 + 62) )
                            {
LABEL_98:
                              if ( *((_BYTE *)a3 + 56) )
                              {
                                *((_BYTE *)a3 + 58) = *v15;
                                v33 = *(_WORD *)v16;
                                v16 += 4;
                                a3[30] = v33;
                              }
                              if ( *((_BYTE *)a3 + 50) )
                              {
                                v34 = *(_DWORD *)v16;
                                v16 += 4;
                                *((_DWORD *)a3 + 13) = v34 & 0xFFFFF;
                              }
                              if ( ipa3_get_ipc_logbuf_low() )
                              {
                                v35 = ipa3_get_ipc_logbuf_low();
                                ipc_log_string(
                                  v35,
                                  "ipahal %s:%d before rule alignment rest=0x%pK\n",
                                  "ipa_fltrt_parse_hw_rule_eq",
                                  4126,
                                  v16);
                              }
                              if ( ipa3_get_ipc_logbuf_low() )
                              {
                                v36 = ipa3_get_ipc_logbuf_low();
                                ipc_log_string(
                                  v36,
                                  "ipahal %s:%d after rule alignment  rest=0x%pK\n",
                                  "ipa_fltrt_parse_hw_rule_eq",
                                  4129,
                                  (const void *)((unsigned __int64)(v16 + 7) & 0xFFFFFFFFFFFFFFF8LL));
                              }
                              *a4 = (((_DWORD)v16 + 7) & 0xFFFFFFF8) - (_DWORD)a1;
                              result = ipa3_get_ipc_logbuf_low();
                              if ( result )
                              {
                                v38 = ipa3_get_ipc_logbuf_low();
                                ipc_log_string(
                                  v38,
                                  "ipahal %s:%d rule_size=0x%x\n",
                                  "ipa_fltrt_parse_hw_rule_eq",
                                  4132,
                                  *a4);
                                result = 0;
                              }
                              goto LABEL_108;
                            }
LABEL_97:
                            v31 = *v15++;
                            *((_BYTE *)a3 + 64) = v31;
                            v32 = *(_DWORD *)v16;
                            v16 += 4;
                            *((_DWORD *)a3 + 17) = v32;
                            goto LABEL_98;
                          }
LABEL_92:
                          *((_DWORD *)a3 + 43) = *(_DWORD *)v16;
                          v29 = *((_DWORD *)v16 + 1);
                          v16 += 8;
                          *((_DWORD *)a3 + 44) = v29;
                          goto LABEL_93;
                        }
                        v16 += 8;
                        ++v15;
LABEL_91:
                        if ( !*((_BYTE *)a3 + 167) )
                          goto LABEL_93;
                        goto LABEL_92;
                      }
                      v16 += 8;
                      ++v15;
LABEL_86:
                      v26 = *((unsigned __int8 *)a3 + 72);
                      if ( !*((_BYTE *)a3 + 72) )
                        goto LABEL_91;
                      goto LABEL_89;
                    }
                    v16 += 32;
                    ++v15;
                  }
                  v23 = *((unsigned __int8 *)a3 + 20);
                  if ( !*((_BYTE *)a3 + 20) )
                    goto LABEL_86;
                  goto LABEL_84;
                }
                goto LABEL_127;
              }
            }
LABEL_128:
            __break(0x5512u);
          }
        }
      }
      else
      {
        v15 = &a1[a2];
        v16 = v15 + 16;
        if ( !ipa3_get_ipc_logbuf_low() )
          goto LABEL_66;
      }
      v17 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v17,
        "ipahal %s:%d addr=0x%pK extra=0x%pK rest=0x%pK\n",
        "ipa_fltrt_parse_hw_rule_eq",
        4020,
        a1,
        v15,
        v16);
      goto LABEL_66;
    }
    printk(&unk_3C8B8C, "ipa_fltrt_parse_hw_rule_eq");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipahal %s:%d too much extra bytes\n", "ipa_fltrt_parse_hw_rule_eq", 4003);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v46 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v46, "ipahal %s:%d too much extra bytes\n", "ipa_fltrt_parse_hw_rule_eq", 4003);
    }
    result = 0xFFFFFFFFLL;
  }
  else
  {
    printk(&unk_3DD426, "ipa_fltrt_parse_hw_rule_eq");
    if ( ipa3_get_ipc_logbuf() )
    {
      v43 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v43,
        "ipahal %s:%d Input error: addr=%pK atrb=%pK rule_size=%pK\n",
        "ipa_fltrt_parse_hw_rule_eq",
        3946,
        a1,
        a3,
        a4);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v44 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v44,
        "ipahal %s:%d Input error: addr=%pK atrb=%pK rule_size=%pK\n",
        "ipa_fltrt_parse_hw_rule_eq",
        3946,
        a1,
        a3,
        a4);
    }
    result = 4294967274LL;
  }
LABEL_108:
  _ReadStatusReg(SP_EL0);
  return result;
}
