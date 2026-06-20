__int64 __fastcall msm_vidc_s_ctrl(__int64 a1, __int64 a2)
{
  unsigned int cap_id; // w0
  __int64 v5; // x4
  __int64 v6; // x24
  __int64 v7; // x23
  unsigned int v8; // w21
  char v9; // w8
  int *v10; // x23
  int v11; // t1
  __int64 v12; // x9
  unsigned int v13; // w22
  __int64 v15; // x2
  __int64 v16; // x0
  __int64 v17; // x1
  __int64 v18; // x23
  _QWORD *v19; // x23
  int v20; // w25
  __int64 v21; // t1
  __int64 v22; // x4
  _QWORD *v23; // x20
  __int64 v24; // x8
  unsigned int updated; // w0
  __int64 v26; // x0
  __int64 v27; // x20
  _QWORD *v28; // x8
  __int64 v29; // x4
  __int64 v30; // x10
  __int64 v31; // x0
  __int64 v32; // x1
  __int64 v33; // x0
  _QWORD *v34; // x0
  _QWORD *v35; // x25
  unsigned int v36; // w20
  _QWORD *v37; // x23
  unsigned int *v38; // x8
  _DWORD *v39; // x8
  _QWORD *v40; // x26
  _QWORD *v41; // x8
  _QWORD *v42; // x9
  _QWORD *v43; // x9
  _QWORD *v44; // x21
  _QWORD *v45; // x25
  unsigned int v46; // w23
  unsigned int *v47; // x9
  _DWORD *v48; // x8
  _QWORD *v49; // x27
  __int64 v50; // x28
  unsigned int v51; // w0
  unsigned int v52; // w0
  _QWORD *v53; // x0
  _QWORD *v54; // x26
  _QWORD *v55; // x8
  _QWORD *v56; // x9
  _QWORD *v57; // x9
  _QWORD *v58; // x27
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x0
  __int64 v62; // x0
  __int64 *v63; // x0
  __int64 *v64; // x27
  __int64 **v65; // x8
  __int64 *v66; // x9
  __int64 *v67; // x9
  __int64 *v68; // x28
  __int64 v69; // x0
  _QWORD *v70; // x0
  _QWORD *v71; // x26
  _QWORD *v72; // x8
  _QWORD *v73; // x9
  _QWORD *v74; // x9
  _QWORD *v75; // x27
  __int64 v76; // x0

  if ( a1 && (msm_vidc_debug & 2) != 0 )
  {
    v26 = state_name(*(unsigned int *)(a1 + 160));
    printk(&unk_8826A, "high", a1 + 340, "msm_vidc_s_ctrl", v26);
  }
  cap_id = msm_vidc_get_cap_id(a1, *(_DWORD *)(a2 + 72));
  if ( cap_id - 1 >= 0xC4 )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_8D75D, "err ", a1 + 340, "msm_vidc_s_ctrl", *(_QWORD *)(a2 + 80));
    return (unsigned int)-22;
  }
  v6 = a1 + 4320;
  v7 = a1 + 4320 + 168LL * cap_id;
  v8 = cap_id;
  v11 = *(_DWORD *)(v7 + 48);
  v10 = (int *)(v7 + 48);
  v9 = v11;
  v12 = *(_QWORD *)(a1 + 8LL * (*(_DWORD *)(a1 + 308) == 1) + 1840);
  *v10 = v11 | 0x10;
  if ( (*(_WORD *)(v12 + 320) & 1) != 0 )
  {
    if ( (v9 & 1) != 0 )
    {
      if ( a1 && (msm_vidc_debug & 2) != 0 )
      {
        cap_name(cap_id);
        printk(&unk_977A1, "high", a1 + 340, "msm_vidc_adjust_dynamic_property", v8);
      }
      v18 = v6 + 168LL * v8;
      v21 = *(_QWORD *)(v18 + 32);
      v19 = (_QWORD *)(v18 + 32);
      v20 = v21;
      v13 = msm_vidc_adjust_cap(a1, v8, a2, "msm_vidc_adjust_dynamic_property");
      if ( !v13 )
      {
        if ( v8 == 68 && *v19 == v20 )
        {
LABEL_81:
          if ( a1 && (msm_vidc_debug & 2) != 0 )
            printk(&unk_9602D, "high", a1 + 340, "msm_vidc_set_dynamic_property", v22);
          v34 = *(_QWORD **)(a1 + 4056);
          v35 = (_QWORD *)(a1 + 4056);
          if ( v34 == (_QWORD *)(a1 + 4056) )
            return 0;
          while ( 1 )
          {
            v36 = *((_DWORD *)v34 + 4);
            v37 = (_QWORD *)*v34;
            if ( v36 - 1 <= 0xC3 )
            {
              v38 = (unsigned int *)(v6 + 168LL * v36);
              if ( *v38 - 197 >= 0xFFFFFF3C )
              {
                if ( *(_DWORD *)(v6 + 168LL * *v38) )
                {
                  v39 = *((_DWORD **)v38 + 20);
                  if ( v39 )
                  {
                    v40 = v34;
                    if ( *(v39 - 1) != 1301911631 )
                      __break(0x8228u);
                    v13 = ((__int64 (__fastcall *)(__int64, _QWORD))v39)(a1, v36);
                    v34 = v40;
                    if ( v13 )
                      break;
                  }
                }
              }
            }
            v41 = (_QWORD *)v34[1];
            if ( (_QWORD *)*v41 == v34 && (v42 = (_QWORD *)*v34, *(_QWORD **)(*v34 + 8LL) == v34) )
            {
              v42[1] = v41;
              *v41 = v42;
            }
            else
            {
              _list_del_entry_valid_or_report(v34);
              v34 = v43;
            }
            *v34 = v34;
            v34[1] = v34;
            vfree(v34);
            v34 = v37;
            if ( v37 == v35 )
              return 0;
          }
          if ( a1 && (msm_vidc_debug & 1) != 0 )
          {
            v61 = cap_name(v36);
            printk(&unk_946BA, "err ", a1 + 340, "msm_vidc_set_dynamic_property", v61);
          }
          v53 = (_QWORD *)*v35;
          if ( (_QWORD *)*v35 != v35 )
          {
            do
            {
              v54 = (_QWORD *)*v53;
              if ( a1 && (msm_vidc_debug & 1) != 0 )
              {
                v58 = v53;
                v59 = cap_name(*((unsigned int *)v53 + 4));
                printk(&unk_82ADC, "err ", a1 + 340, "msm_vidc_set_dynamic_property", v59);
                v53 = v58;
              }
              v55 = (_QWORD *)v53[1];
              if ( (_QWORD *)*v55 == v53 && (v56 = (_QWORD *)*v53, *(_QWORD **)(*v53 + 8LL) == v53) )
              {
                v56[1] = v55;
                *v55 = v56;
              }
              else
              {
                _list_del_entry_valid_or_report(v53);
                v53 = v57;
              }
              *v53 = v53;
              v53[1] = v53;
              vfree(v53);
              v53 = v54;
            }
            while ( v54 != v35 );
          }
        }
        else
        {
          v23 = (_QWORD *)(a1 + 4056);
          v24 = a1 + 4056;
          while ( 1 )
          {
            v24 = *(_QWORD *)v24;
            if ( (_QWORD *)v24 == v23 )
              break;
            if ( *(_DWORD *)(v24 + 16) == v8 )
            {
              if ( a1 && (msm_vidc_debug & 4) != 0 )
              {
                cap_name(v8);
                printk(&unk_81060, "low ", a1 + 340, "msm_vidc_add_capid_to_fw_list", v8);
              }
              goto LABEL_79;
            }
          }
          v33 = vzalloc_noprof(24);
          if ( !v33 )
          {
            if ( (msm_vidc_debug & 1) != 0 )
              printk(&unk_8C985, "err ", 0xFFFFFFFFLL, "codec", "add_node_list");
            v13 = -12;
            goto LABEL_148;
          }
          *(_QWORD *)v33 = v33;
          *(_QWORD *)(v33 + 8) = v33;
          *(_DWORD *)(v33 + 16) = v8;
          list_add(v33);
LABEL_79:
          if ( v8 != 55 && *v19 == v20 )
            goto LABEL_81;
          v13 = msm_vidc_add_children(a1, v8);
          if ( !v13 )
          {
            v44 = *(_QWORD **)(a1 + 4040);
            v45 = (_QWORD *)(a1 + 4040);
            if ( v44 == (_QWORD *)(a1 + 4040) )
            {
LABEL_134:
              if ( (_QWORD *)*v45 == v45 )
                goto LABEL_81;
              if ( a1 && (msm_vidc_debug & 1) != 0 )
                printk(&unk_96265, "err ", a1 + 340, "msm_vidc_adjust_dynamic_property", v22);
            }
            else
            {
              while ( 1 )
              {
                v46 = *((_DWORD *)v44 + 4);
                if ( v46 - 1 > 0xC3 )
                  break;
                v47 = (unsigned int *)(v6 + 168LL * v46);
                v48 = *((_DWORD **)v47 + 19);
                if ( !v48 )
                {
                  if ( a1 && (msm_vidc_debug & 1) != 0 )
                  {
                    v62 = cap_name(v46);
                    printk(&unk_953FA, "err ", a1 + 340, "msm_vidc_adjust_dynamic_property", v62);
                  }
                  break;
                }
                v49 = (_QWORD *)*v44;
                v50 = *((_QWORD *)v47 + 4);
                if ( *v47 - 197 >= 0xFFFFFF3C && *(_DWORD *)(v6 + 168LL * *v47) )
                {
                  if ( *(v48 - 1) != -611583898 )
                    __break(0x8228u);
                  v51 = ((__int64 (__fastcall *)(__int64, _QWORD))v48)(a1, 0);
                  if ( v51 )
                  {
                    v13 = v51;
                    if ( a1 && (msm_vidc_debug & 1) != 0 )
                    {
                      v60 = cap_name(v46);
                      printk(&unk_8EFCA, "err ", a1 + 340, "msm_vidc_adjust_dynamic_property", v60);
                    }
                    goto LABEL_148;
                  }
                  v46 = *((_DWORD *)v44 + 4);
                }
                if ( *(_QWORD *)(v6 + 168LL * v46 + 32) != (int)v50 )
                {
                  v52 = msm_vidc_add_capid_to_fw_list(a1, v46);
                  if ( v52 || (v52 = msm_vidc_add_children(a1, *((unsigned int *)v44 + 4))) != 0 )
                  {
                    v13 = v52;
                    goto LABEL_148;
                  }
                }
                list_del_init(v44);
                vfree(v44);
                v44 = v49;
                if ( v49 == v45 )
                  goto LABEL_134;
              }
            }
            v13 = -22;
          }
LABEL_148:
          v63 = *(__int64 **)(a1 + 4040);
          if ( v63 != (__int64 *)(a1 + 4040) )
          {
            do
            {
              v64 = (__int64 *)*v63;
              if ( a1 && (msm_vidc_debug & 1) != 0 )
              {
                v68 = v63;
                v69 = cap_name(*((unsigned int *)v63 + 4));
                printk(&unk_89B3D, "err ", a1 + 340, "msm_vidc_adjust_dynamic_property", v69);
                v63 = v68;
              }
              v65 = (__int64 **)v63[1];
              if ( *v65 == v63 && (v66 = (__int64 *)*v63, *(__int64 **)(*v63 + 8) == v63) )
              {
                v66[1] = (__int64)v65;
                *v65 = v66;
              }
              else
              {
                _list_del_entry_valid_or_report(v63);
                v63 = v67;
              }
              *v63 = (__int64)v63;
              v63[1] = (__int64)v63;
              vfree(v63);
              v63 = v64;
            }
            while ( v64 != (__int64 *)(a1 + 4040) );
          }
          v70 = (_QWORD *)*v23;
          if ( (_QWORD *)*v23 != v23 )
          {
            do
            {
              v71 = (_QWORD *)*v70;
              if ( a1 && (msm_vidc_debug & 1) != 0 )
              {
                v75 = v70;
                v76 = cap_name(*((unsigned int *)v70 + 4));
                printk(&unk_82ADC, "err ", a1 + 340, "msm_vidc_adjust_dynamic_property", v76);
                v70 = v75;
              }
              v72 = (_QWORD *)v70[1];
              if ( (_QWORD *)*v72 == v70 && (v73 = (_QWORD *)*v70, *(_QWORD **)(*v70 + 8LL) == v70) )
              {
                v73[1] = v72;
                *v72 = v73;
              }
              else
              {
                _list_del_entry_valid_or_report(v70);
                v70 = v74;
              }
              *v70 = v70;
              v70[1] = v70;
              vfree(v70);
              v70 = v71;
            }
            while ( v71 != v23 );
          }
        }
      }
    }
    else
    {
      if ( a1 && (msm_vidc_debug & 2) != 0 )
      {
        cap_name(cap_id);
        printk(&unk_820EE, "high", a1 + 340, "msm_vidc_adjust_dynamic_property", v8);
      }
      return (unsigned int)-16;
    }
    return v13;
  }
  if ( cap_id == 31 )
  {
    if ( a1 && (msm_vidc_debug & 2) != 0 )
      printk(&unk_939D0, "high", a1 + 340, "msm_vidc_update_static_property", v5);
    return 0;
  }
  if ( *(_DWORD *)(a2 + 88) == 5 )
  {
    v15 = **(_QWORD **)(a2 + 232);
    if ( (cap_id & 0xFE) == 0x98 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *))msm_vidc_update_cap_value)(
        a1,
        152,
        v15,
        "msm_vidc_update_static_property");
      v16 = a1;
      v17 = 153;
      v15 = **(_QWORD **)(a2 + 232);
      goto LABEL_38;
    }
  }
  else
  {
    v15 = *(int *)(a2 + 196);
  }
  v16 = a1;
  v17 = v8;
LABEL_38:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *))msm_vidc_update_cap_value)(
    v16,
    v17,
    v15,
    "msm_vidc_update_static_property");
  if ( (unsigned __int8)v8 > 0x6Fu )
  {
    if ( (unsigned __int8)v8 <= 0xACu )
    {
      if ( (unsigned __int8)v8 != 112 )
      {
        if ( (unsigned __int8)v8 != 167 )
          goto LABEL_65;
        updated = msm_vidc_update_bitstream_buffer_size(a1);
        goto LABEL_64;
      }
      goto LABEL_61;
    }
    if ( (unsigned __int8)v8 != 173 )
    {
      if ( (unsigned __int8)v8 == 175 )
        ((void (__fastcall *)(__int64, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
          a1,
          173,
          0,
          "msm_vidc_update_static_property");
      goto LABEL_65;
    }
    updated = msm_vidc_adjust_session_priority(a1, a2);
  }
  else
  {
    if ( (unsigned __int8)v8 <= 0x66u )
    {
      if ( (unsigned __int8)v8 != 51 )
      {
        if ( (unsigned __int8)v8 == 65 && *(_DWORD *)(a1 + 312) == 2 )
          ((void (__fastcall *)(__int64, __int64, bool, const char *))msm_vidc_update_cap_value)(
            a1,
            140,
            *(_DWORD *)(a2 + 196) > 0,
            "msm_vidc_update_static_property");
        goto LABEL_65;
      }
LABEL_61:
      updated = msm_venc_s_fmt_output(a1, a1 + 592);
      goto LABEL_64;
    }
    if ( (unsigned __int8)v8 != 103 )
    {
      if ( (unsigned __int8)v8 != 104 || !*(_DWORD *)(a2 + 196) )
        goto LABEL_65;
      v27 = *(_QWORD *)(a1 + 320);
      core_lock(v27, "msm_vidc_allow_secure_session");
      v28 = *(_QWORD **)(v27 + 3528);
      if ( v28 == (_QWORD *)(v27 + 3528) )
      {
        v29 = 0;
      }
      else
      {
        LODWORD(v29) = 0;
        do
        {
          v30 = v28[2728];
          v28 = (_QWORD *)*v28;
          if ( v30 )
            v29 = (unsigned int)(v29 + 1);
          else
            v29 = (unsigned int)v29;
        }
        while ( v28 != (_QWORD *)(v27 + 3528) );
      }
      if ( *(_QWORD *)(v27 + 4080) >= (__int64)(unsigned int)v29 )
      {
        core_unlock(v27, "msm_vidc_allow_secure_session");
        goto LABEL_65;
      }
      if ( a1 && (msm_vidc_debug & 1) != 0 )
        printk(&unk_8D7A8, "err ", a1 + 340, "msm_vidc_allow_secure_session", v29);
      core_unlock(v27, "msm_vidc_allow_secure_session");
      return (unsigned int)-22;
    }
    updated = msm_vidc_update_debug_str(a1);
  }
LABEL_64:
  v13 = updated;
  if ( updated )
    return v13;
LABEL_65:
  if ( (*(_BYTE *)v10 & 0x80) == 0 || (v13 = msm_vidc_update_meta_port_settings(a1)) == 0 )
  {
    if ( (unsigned __int8)v8 > 0xA7u )
    {
      if ( (unsigned __int8)v8 == 168 || (unsigned __int8)v8 == 173 )
      {
        v13 = msm_vidc_update_buffer_count(a1, 0);
        if ( v13 )
          return v13;
        v31 = a1;
        v32 = 1;
LABEL_71:
        v13 = msm_vidc_update_buffer_count(v31, v32);
        if ( v13 )
          return v13;
      }
    }
    else if ( (unsigned int)(unsigned __int8)v8 - 139 < 2 || (unsigned __int8)v8 == 65 )
    {
      v31 = a1;
      v32 = 0;
      goto LABEL_71;
    }
    return 0;
  }
  return v13;
}
