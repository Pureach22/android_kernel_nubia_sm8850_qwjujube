__int64 __fastcall policy_mgr_dump_current_concurrency(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  _QWORD *v11; // x20
  __int64 result; // x0
  int v13; // w22
  const char *v14; // x19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w21
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  size_t v32; // x0
  __int64 v33; // x21
  size_t v34; // x2
  const char *v35; // x1
  __int64 v36; // x22
  size_t v37; // x2
  const char *v38; // x1
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x20
  size_t v48; // x2
  const char *v49; // x1
  const char *v50; // x2
  char v51; // w22
  __int64 v52; // x21
  size_t v53; // x2
  const char *v54; // x1
  char is_current_hwmode_sbs; // w21
  size_t v56; // x21
  size_t v57; // x0
  size_t v58; // x2
  __int64 v59; // x22
  char is_current_hwmode_dbs; // w8
  __int64 v61; // x0
  size_t v62; // x2
  __int64 v63; // x0
  char string[8]; // [xsp+8h] [xbp-18h] BYREF
  char v65; // [xsp+10h] [xbp-10h]
  __int64 v66; // [xsp+18h] [xbp-8h]

  v66 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
  if ( !comp_private_obj )
  {
    result = qdf_trace_msg(
               0x4Fu,
               2u,
               "%s: Invalid Context",
               v3,
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               "policy_mgr_dump_current_concurrency");
LABEL_193:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v11 = (_QWORD *)comp_private_obj;
  result = policy_mgr_get_connection_count(a1);
  if ( !(_DWORD)result )
    goto LABEL_193;
  v13 = result;
  result = _qdf_mem_malloc(0x12Cu, "policy_mgr_dump_current_concurrency", 1761);
  if ( !result )
    goto LABEL_193;
  v14 = (const char *)result;
  policy_mgr_dump_connection_status_info(a1);
  if ( v13 <= 2 )
  {
    if ( v13 == 1 )
    {
      policy_mgr_dump_current_concurrency_one_connection(v14);
      v50 = "%s: %s Standalone";
LABEL_191:
      qdf_trace_msg(0x4Fu, 8u, v50, v39, v40, v41, v42, v43, v44, v45, v46, "policy_mgr_dump_current_concurrency", v14);
      goto LABEL_192;
    }
    if ( v13 != 2 )
      goto LABEL_46;
    policy_mgr_dump_current_concurrency_two_connection(v14);
    qdf_mutex_acquire((__int64)(v11 + 7));
    if ( HIDWORD(pm_conc_connection_list) == HIDWORD(qword_81C464) )
    {
      v32 = strnlen(v14, 0x12Cu);
      if ( v32 == -1 )
        goto LABEL_204;
      if ( v32 > 0x12B )
        goto LABEL_69;
      if ( v32 >= 0x128 )
        v36 = 299;
      else
        v36 = v32 + 4;
      if ( v32 >= 0x128 )
        v37 = 299 - v32;
      else
        v37 = 4;
      v38 = " SCC";
    }
    else
    {
      if ( (policy_mgr_2_freq_always_on_same_mac(a1, HIDWORD(pm_conc_connection_list), HIDWORD(qword_81C464)) & 1) == 0 )
      {
        if ( (policy_mgr_is_current_hwmode_dbs(a1) & 1) != 0 )
        {
          v32 = strnlen(v14, 0x12Cu);
          if ( v32 == -1 )
            goto LABEL_204;
          if ( v32 <= 0x12B )
          {
            if ( v32 >= 0x128 )
              v52 = 299;
            else
              v52 = v32 + 4;
            if ( v32 >= 0x128 )
              v53 = 299 - v32;
            else
              v53 = 4;
            v54 = " DBS";
            goto LABEL_188;
          }
        }
        else
        {
          is_current_hwmode_sbs = policy_mgr_is_current_hwmode_sbs(a1);
          v32 = strnlen(v14, 0x12Cu);
          if ( (is_current_hwmode_sbs & 1) == 0 )
          {
            if ( v32 != -1 )
            {
LABEL_180:
              if ( v32 > 0x12B )
                goto LABEL_189;
              if ( v32 >= 0x128 )
                v52 = 299;
              else
                v52 = v32 + 4;
              if ( v32 >= 0x128 )
                v53 = 299 - v32;
              else
                v53 = 4;
              v54 = " MCC";
LABEL_188:
              memcpy((void *)&v14[v32], v54, v53);
              v14[v52] = 0;
              goto LABEL_189;
            }
            goto LABEL_204;
          }
          if ( v32 == -1 )
            goto LABEL_204;
          if ( v32 <= 0x12B )
          {
            if ( v32 >= 0x128 )
              v52 = 299;
            else
              v52 = v32 + 4;
            if ( v32 >= 0x128 )
              v53 = 299 - v32;
            else
              v53 = 4;
            v54 = " SBS";
            goto LABEL_188;
          }
        }
LABEL_189:
        qdf_mutex_release((__int64)(v11 + 7));
        goto LABEL_190;
      }
      v32 = strnlen(v14, 0x12Cu);
      if ( v32 == -1 )
        goto LABEL_204;
      if ( v32 > 0x12B )
      {
LABEL_69:
        if ( (policy_mgr_is_current_hwmode_dbs(a1) & 1) != 0 )
        {
          v32 = strnlen(v14, 0x12Cu);
          if ( v32 == -1 )
            goto LABEL_204;
          if ( v32 <= 0x12B )
          {
            if ( v32 >= 0x126 )
              v52 = 299;
            else
              v52 = v32 + 6;
            if ( v32 >= 0x126 )
              v53 = 299 - v32;
            else
              v53 = 6;
            v54 = " (DBS)";
            goto LABEL_188;
          }
        }
        goto LABEL_189;
      }
      if ( v32 >= 0x128 )
        v36 = 299;
      else
        v36 = v32 + 4;
      if ( v32 >= 0x128 )
        v37 = 299 - v32;
      else
        v37 = 4;
      v38 = " MCC";
    }
    memcpy((void *)&v14[v32], v38, v37);
    v14[v36] = 0;
    goto LABEL_69;
  }
  if ( v13 == 3 )
  {
    policy_mgr_dump_current_concurrency_three_connection(v14);
    qdf_mutex_acquire((__int64)(v11 + 7));
    if ( HIDWORD(pm_conc_connection_list) == HIDWORD(qword_81C464)
      && HIDWORD(pm_conc_connection_list) == HIDWORD(qword_81C488) )
    {
      qdf_mutex_release((__int64)(v11 + 7));
      v32 = strnlen(v14, 0x12Cu);
      if ( v32 == -1 )
        goto LABEL_204;
      if ( v32 <= 0x12B )
      {
        if ( v32 >= 0x128 )
          v47 = 299;
        else
          v47 = v32 + 4;
        if ( v32 >= 0x128 )
          v48 = 299 - v32;
        else
          v48 = 4;
        v49 = " SCC";
LABEL_57:
        memcpy((void *)&v14[v32], v49, v48);
        v14[v47] = 0;
      }
    }
    else
    {
      v51 = policy_mgr_are_3_freq_on_same_mac(a1);
      qdf_mutex_release((__int64)(v11 + 7));
      if ( (v51 & 1) == 0 )
      {
        if ( (policy_mgr_is_current_hwmode_dbs(a1) & 1) != 0 )
        {
          policy_mgr_dump_dbs_concurrency(a1, v14);
          goto LABEL_190;
        }
        if ( (policy_mgr_is_current_hwmode_sbs(a1) & 1) != 0 )
        {
          policy_mgr_dump_sbs_concurrency(a1, v14);
          goto LABEL_190;
        }
        v32 = strnlen(v14, 0x12Cu);
        if ( v32 == -1 )
          goto LABEL_204;
        if ( v32 > 0x12B )
          goto LABEL_190;
        if ( v32 >= 0x128 )
          v47 = 299;
        else
          v47 = v32 + 4;
        if ( v32 >= 0x128 )
          v48 = 299 - v32;
        else
          v48 = 4;
        v49 = " MCC";
        goto LABEL_57;
      }
      v32 = strnlen(v14, 0x12Cu);
      if ( v32 == -1 )
        goto LABEL_204;
      if ( v32 <= 0x12B )
      {
        if ( v32 >= 0x11A )
          v47 = 299;
        else
          v47 = v32 + 18;
        if ( v32 >= 0x11A )
          v48 = 299 - v32;
        else
          v48 = 18;
        v49 = " MCC on single MAC";
        goto LABEL_57;
      }
    }
LABEL_190:
    v50 = "%s: %s";
    goto LABEL_191;
  }
  if ( v13 == 4 )
  {
    qdf_mutex_acquire((__int64)(v11 + 7));
    ((void (__fastcall *)(const char *))policy_mgr_dump_current_concurrency_4_connection)(v14);
    goto LABEL_175;
  }
  if ( v13 != 5 )
  {
LABEL_46:
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: unexpected num_connections value %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "policy_mgr_dump_current_concurrency",
      (unsigned int)v13);
LABEL_192:
    result = _qdf_mem_free((__int64)v14);
    goto LABEL_193;
  }
  qdf_mutex_acquire((__int64)(v11 + 7));
  v23 = qword_81C4D0;
  v65 = 0;
  *(_QWORD *)string = 0;
  v24 = scnprintf(string, 9, "(vdev %d)", qword_81C4E8);
  if ( v23 > 2 )
  {
    if ( v23 <= 4 )
    {
      if ( v23 == 3 )
      {
        ((void (__fastcall *)(const char *, double))policy_mgr_dump_current_concurrency_4_connection)(v14, v24);
        v32 = strnlen(v14, 0x12Cu);
        if ( v32 != -1 )
        {
          if ( v32 > 0x12B )
            goto LABEL_164;
          if ( v32 >= 0x125 )
            v33 = 299;
          else
            v33 = v32 + 7;
          if ( v32 >= 0x125 )
            v34 = 299 - v32;
          else
            v34 = 7;
          v35 = "+P2P GO";
          goto LABEL_163;
        }
      }
      else
      {
        ((void (__fastcall *)(const char *, double))policy_mgr_dump_current_concurrency_4_connection)(v14, v24);
        v32 = strnlen(v14, 0x12Cu);
        if ( v32 != -1 )
        {
          if ( v32 > 0x12B )
            goto LABEL_164;
          if ( v32 >= 0x128 )
            v33 = 299;
          else
            v33 = v32 + 4;
          if ( v32 >= 0x128 )
            v34 = 299 - v32;
          else
            v34 = 4;
          v35 = "+NDI";
          goto LABEL_163;
        }
      }
LABEL_204:
      v62 = v32 + 1;
LABEL_206:
      v57 = _fortify_panic(2, -1, v62);
      goto LABEL_207;
    }
    if ( v23 == 5 )
    {
      ((void (__fastcall *)(const char *, double))policy_mgr_dump_current_concurrency_4_connection)(v14, v24);
      v32 = strnlen(v14, 0x12Cu);
      if ( v32 != -1 )
      {
        if ( v32 > 0x12B )
          goto LABEL_164;
        if ( v32 >= 0x123 )
          v33 = 299;
        else
          v33 = v32 + 9;
        if ( v32 >= 0x123 )
          v34 = 299 - v32;
        else
          v34 = 9;
        v35 = "+NAN Disc";
        goto LABEL_163;
      }
      goto LABEL_204;
    }
    if ( v23 == 6 )
    {
      ((void (__fastcall *)(const char *, double))policy_mgr_dump_current_concurrency_4_connection)(v14, v24);
      v32 = strnlen(v14, 0x12Cu);
      if ( v32 != -1 )
      {
        if ( v32 > 0x12B )
          goto LABEL_164;
        if ( v32 >= 0x125 )
          v33 = 299;
        else
          v33 = v32 + 7;
        if ( v32 >= 0x125 )
          v34 = 299 - v32;
        else
          v34 = 7;
        v35 = "+LT_SAP";
        goto LABEL_163;
      }
      goto LABEL_204;
    }
    goto LABEL_125;
  }
  if ( !v23 )
  {
    ((void (__fastcall *)(const char *, double))policy_mgr_dump_current_concurrency_4_connection)(v14, v24);
    v32 = strnlen(v14, 0x12Cu);
    if ( v32 != -1 )
    {
      if ( v32 > 0x12B )
        goto LABEL_164;
      if ( v32 >= 0x128 )
        v33 = 299;
      else
        v33 = v32 + 4;
      if ( v32 >= 0x128 )
        v34 = 299 - v32;
      else
        v34 = 4;
      v35 = "+STA";
      goto LABEL_163;
    }
    goto LABEL_204;
  }
  if ( v23 != 1 )
  {
    if ( v23 == 2 )
    {
      ((void (__fastcall *)(const char *, double))policy_mgr_dump_current_concurrency_4_connection)(v14, v24);
      v32 = strnlen(v14, 0x12Cu);
      if ( v32 != -1 )
      {
        if ( v32 > 0x12B )
          goto LABEL_164;
        if ( v32 >= 0x124 )
          v33 = 299;
        else
          v33 = v32 + 8;
        if ( v32 >= 0x124 )
          v34 = 299 - v32;
        else
          v34 = 8;
        v35 = "+P2P CLI";
        goto LABEL_163;
      }
      goto LABEL_204;
    }
LABEL_125:
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: unexpected mode %d",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "policy_mgr_dump_current_concurrency_5_connection",
      (unsigned int)v23);
    goto LABEL_164;
  }
  ((void (__fastcall *)(const char *, double))policy_mgr_dump_current_concurrency_4_connection)(v14, v24);
  v32 = strnlen(v14, 0x12Cu);
  if ( v32 == -1 )
    goto LABEL_204;
  if ( v32 > 0x12B )
    goto LABEL_164;
  if ( v32 >= 0x128 )
    v33 = 299;
  else
    v33 = v32 + 4;
  if ( v32 >= 0x128 )
    v34 = 299 - v32;
  else
    v34 = 4;
  v35 = "+SAP";
LABEL_163:
  memcpy((void *)&v14[v32], v35, v34);
  v14[v33] = 0;
LABEL_164:
  v56 = strnlen(v14, 0x12Cu);
  if ( v56 == -1 )
  {
    v62 = 0;
    goto LABEL_206;
  }
  v57 = strnlen(string, 9u);
  if ( v57 >= 0xA )
  {
LABEL_207:
    v57 = _fortify_panic(2, 9, v57 + 1);
    goto LABEL_208;
  }
  if ( v57 != 9 )
  {
    if ( v56 <= 0x12B )
    {
      if ( v57 + v56 >= 0x12C )
        v58 = 299 - v56;
      else
        v58 = v57;
      if ( v57 + v56 >= 0x12C )
        v59 = 299;
      else
        v59 = v57 + v56;
      memcpy((void *)&v14[v56], string, v58);
      v14[v59] = 0;
    }
LABEL_175:
    is_current_hwmode_dbs = policy_mgr_is_current_hwmode_dbs(*v11);
    v61 = *v11;
    if ( (is_current_hwmode_dbs & 1) != 0 )
    {
      policy_mgr_dump_dbs_concurrency(v61, v14);
      goto LABEL_189;
    }
    if ( (policy_mgr_is_current_hwmode_sbs(v61) & 1) != 0 )
    {
      policy_mgr_dump_sbs_concurrency(*v11, v14);
      goto LABEL_189;
    }
    v32 = strnlen(v14, 0x12Cu);
    if ( v32 != -1 )
      goto LABEL_180;
    goto LABEL_204;
  }
LABEL_208:
  v63 = _fortify_panic(4, 9, v57 + 1);
  return policy_mgr_dump_current_concurrency_one_connection(v63);
}
