__int64 __fastcall _response_handler(__int64 a1)
{
  __int64 v2; // x8
  unsigned int *v3; // x19
  __int64 v4; // x22
  int v5; // w9
  __int64 v6; // x23
  unsigned int v7; // w21
  int *v8; // x27
  __int64 *v9; // x28
  __int64 v10; // x24
  __int64 v11; // x0
  __int64 v12; // x8
  unsigned int (__fastcall *v13)(_QWORD); // x8
  __int16 v14; // w8
  __int64 pkt_name_from_type; // x0
  __int64 v16; // x2
  __int64 v17; // x3
  int v18; // w8
  __int64 v19; // x8
  __int64 v20; // x10
  __int64 v21; // x11
  __int64 v22; // x5
  _QWORD *v23; // x8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v26; // x8
  __int64 v27; // x23
  __int64 v28; // x0
  unsigned __int64 v29; // x8
  unsigned __int64 v30; // x8
  unsigned __int64 v31; // x8
  unsigned __int64 v32; // x8
  unsigned __int64 v33; // x8
  unsigned __int64 v34; // [xsp+20h] [xbp-30h]
  __int64 v35; // [xsp+28h] [xbp-28h] BYREF
  __int64 v36; // [xsp+30h] [xbp-20h]
  __int64 v37; // [xsp+38h] [xbp-18h]
  __int64 v38; // [xsp+40h] [xbp-10h]
  __int64 v39; // [xsp+48h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || *(_DWORD *)(a1 + 2408) != 2 || (v2 = *(_QWORD *)(cvp_driver + 48)) == 0 )
  {
    v7 = 0;
    goto LABEL_79;
  }
  v3 = *(unsigned int **)(a1 + 2440);
  v4 = *(_QWORD *)(a1 + 2432);
  if ( !v3 || !v4 )
  {
    v7 = 0;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_92D8D, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      v7 = 0;
    }
    goto LABEL_79;
  }
  v5 = *(_DWORD *)(a1 + 20);
  v6 = v2 + 49152;
  if ( (v5 & 0x60) != 0 )
  {
    if ( (v5 & 0x40) != 0 )
    {
      if ( (unsigned int)__ratelimit(&_response_handler__rs, "__response_handler") )
      {
        v30 = _ReadStatusReg(SP_EL0);
        printk(&unk_8FF94, *(unsigned int *)(v30 + 1800), *(unsigned int *)(v30 + 1804), &unk_8E7CE);
      }
      *(_DWORD *)(v6 + 2148) = 1;
      v5 = *(_DWORD *)(a1 + 20);
    }
    if ( (v5 & 0x20) != 0 )
    {
      if ( (unsigned int)__ratelimit(&_response_handler__rs_24, "__response_handler") )
      {
        v31 = _ReadStatusReg(SP_EL0);
        printk(&unk_86A8C, *(unsigned int *)(v31 + 1800), *(unsigned int *)(v31 + 1804), &unk_8E7CE);
      }
      *(_DWORD *)(v6 + 2148) = 2;
    }
  }
  v7 = 0;
  v34 = _ReadStatusReg(SP_EL0);
  while ( 2 )
  {
    v8 = (int *)(v4 + 768LL * (int)v7);
    v9 = (__int64 *)(v8 + 4);
    while ( 1 )
    {
      do
      {
        while ( 1 )
        {
          v10 = *(_QWORD *)(a1 + 2208);
          LODWORD(v35) = 0;
          if ( (mutex_is_locked(a1 + 80) & 1) == 0 && *(_BYTE *)(v10 + 376) )
          {
            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
              printk(&unk_8E7D2, *(unsigned int *)(v34 + 1800), *(unsigned int *)(v34 + 1804), &unk_8E7CE);
            __break(0x800u);
          }
          if ( *(_DWORD *)(a1 + 2408) == 1 )
          {
            if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
            {
              v26 = _ReadStatusReg(SP_EL0);
              printk(&unk_84293, *(unsigned int *)(v26 + 1800), *(unsigned int *)(v26 + 1804), "warn");
            }
            goto LABEL_89;
          }
          if ( !*(_QWORD *)(a1 + 1232) )
          {
            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
            {
              v29 = _ReadStatusReg(SP_EL0);
              printk(&unk_86AF0, *(unsigned int *)(v29 + 1800), *(unsigned int *)(v29 + 1804), &unk_8E7CE);
            }
            goto LABEL_89;
          }
          v11 = _read_queue(a1 + 1208, v3, &v35);
          if ( (_DWORD)v11 )
            goto LABEL_89;
          if ( (_DWORD)v35 )
          {
            v12 = *(_QWORD *)(a1 + 2512);
            if ( v12 )
            {
              v13 = *(unsigned int (__fastcall **)(_QWORD))(v12 + 56);
              if ( v13 )
              {
                if ( *((_DWORD *)v13 - 1) != -1303076162 )
                  __break(0x8228u);
                if ( v13(a1) && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                  printk(&unk_920E3, *(unsigned int *)(v34 + 1800), *(unsigned int *)(v34 + 1804), &unk_8E7CE);
              }
            }
            v11 = _write_register(a1, 0xA0150u, 1u);
          }
          *(_QWORD *)(v6 + 2152) = ktime_get(v11);
          v14 = msm_cvp_debug;
          if ( (msm_cvp_debug & 0x20000) != 0
            && (pkt_name_from_type = get_pkt_name_from_type(v3[1]),
                _ReadStatusReg(CNTVCT_EL0),
                v14 = msm_cvp_debug,
                (msm_cvp_debug & 0x20000) != 0)
            && !msm_cvp_debug_out )
          {
            printk(&unk_8B02B, "perf", "__response_handler", pkt_name_from_type);
            if ( (msm_cvp_debug & 0x4000) == 0 )
              goto LABEL_42;
          }
          else if ( (v14 & 0x4000) == 0 )
          {
            goto LABEL_42;
          }
          if ( !msm_cvp_debug_out )
            printk(&unk_96D33, "hfi", *v3, v3[1]);
LABEL_42:
          if ( !(unsigned int)cvp_hfi_process_msg_packet(0, v3, v8) )
            break;
          if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
            printk(&unk_89BDC, *(unsigned int *)(v34 + 1800), *(unsigned int *)(v34 + 1804), "warn");
        }
      }
      while ( !*v8 );
      v37 = 0;
      v38 = 0;
      v35 = 0;
      v36 = 0;
      v18 = *v8;
      if ( *v8 == 1 )
      {
        if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
          printk(&unk_85792, "core", v16, v17);
        v37 = *(_QWORD *)(a1 + 2504);
        cvp_hfi_process_sys_init_done_prop_read(v3, &v35);
        v19 = v38;
        v21 = v35;
        v20 = v36;
        *((_QWORD *)v8 + 6) = v37;
        *((_QWORD *)v8 + 7) = v19;
        *((_QWORD *)v8 + 4) = v21;
        *((_QWORD *)v8 + 5) = v20;
      }
      else if ( v18 == 3 )
      {
        if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
          printk(&unk_86B29, "core", v16, v17);
      }
      else if ( v18 == 9 )
      {
        _process_sys_error((_QWORD *)a1);
      }
      if ( (unsigned int)*v8 > 0x1D || ((1 << *v8) & 0x3BFDFC00) == 0 || v8 == (int *)-16LL )
        break;
      v22 = *v9;
      if ( HIDWORD(*v9) && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        printk(&unk_908D4, *(unsigned int *)(v34 + 1800), *(unsigned int *)(v34 + 1804), &unk_8E7CE);
        v22 = *v9;
      }
      v23 = (_QWORD *)a1;
      while ( 1 )
      {
        v23 = (_QWORD *)*v23;
        if ( v23 == (_QWORD *)a1 )
          break;
        if ( (HIDWORD(v23) ^ (unsigned int)v23) == (_DWORD)v22 )
        {
          if ( v23 )
          {
            *v9 = v23[2];
            goto LABEL_75;
          }
          break;
        }
      }
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        printk(&unk_8420C, *(unsigned int *)(v34 + 1800), *(unsigned int *)(v34 + 1804), &unk_8E7CE);
    }
LABEL_75:
    if ( (int)++v7 >= 32 )
    {
      if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
      {
        v33 = _ReadStatusReg(SP_EL0);
        printk(&unk_88087, *(unsigned int *)(v33 + 1800), *(unsigned int *)(v33 + 1804), "warn");
      }
    }
    else if ( *v8 != 9 )
    {
      continue;
    }
    break;
  }
LABEL_89:
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 2208) + 329LL) == 1 )
  {
    cancel_delayed_work(&iris_hfi_pm_work);
    v27 = *(_QWORD *)(a1 + 2184);
    v28 = _msecs_to_jiffies(*(unsigned int *)(*(_QWORD *)(a1 + 2208) + 432LL));
    if ( (queue_delayed_work_on(32, v27, &iris_hfi_pm_work, v28) & 1) == 0
      && (msm_cvp_debug & 1) != 0
      && !msm_cvp_debug_out )
    {
      v32 = _ReadStatusReg(SP_EL0);
      printk(&unk_880C3, *(unsigned int *)(v32 + 1800), *(unsigned int *)(v32 + 1804), &unk_8E7CE);
    }
  }
  _flush_debug_queue(a1, v3);
LABEL_79:
  _ReadStatusReg(SP_EL0);
  return v7;
}
