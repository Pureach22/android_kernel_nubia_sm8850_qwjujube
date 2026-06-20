__int64 __fastcall cvp_synx_ops_v2(__int64 a1, int a2, __int64 a3, unsigned int *a4)
{
  unsigned int v4; // w22
  unsigned int v5; // w23
  __int64 v6; // x24
  unsigned __int64 aon_time; // x25
  unsigned int v8; // w26
  __int64 result; // x0
  __int64 v10; // x20
  int v13; // w23
  unsigned int i; // w22
  unsigned int v15; // w28
  unsigned int v16; // w0
  __int64 v17; // x3
  unsigned int v18; // w27
  unsigned int status; // w0
  __int64 v20; // x3
  __int64 v21; // x8
  int v22; // w9
  unsigned int v23; // w23
  int v24; // w28
  _DWORD *v25; // x8
  unsigned int v26; // w20
  unsigned __int64 v27; // x8
  _DWORD *v28; // x8
  unsigned int v29; // w20
  unsigned __int64 v30; // x25
  int v31; // w21
  __int64 v32; // x26
  unsigned int v33; // w27
  int v34; // w9
  unsigned int v35; // w24
  unsigned int v36; // w23
  unsigned int v37; // w7
  unsigned __int64 v38; // x8
  unsigned __int64 StatusReg; // x27
  __int64 v40; // x0
  __int64 v41; // x8
  unsigned __int64 v42; // [xsp+18h] [xbp-8h]

  if ( *(_DWORD *)(a3 + 28) == -1329939778 )
    return 0;
  v10 = *(_QWORD *)(a1 + 15264);
  if ( a2 == 2 )
  {
    v21 = *(unsigned int *)(a3 + 36);
    if ( (unsigned int)v21 >= 0x41 )
    {
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                       + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
          & 1) != 0 )
      {
        ++*(_DWORD *)(StatusReg + 16);
        v40 = _traceiter_tracing_eva_frame_from_sw(
                0,
                aon_time,
                (__int64)"EVA_KMD_SYNX_SIGNAL_SUCCESS",
                (unsigned int)a4,
                v5,
                v10,
                v6,
                v4,
                a3);
        v41 = *(_QWORD *)(StatusReg + 16) - 1LL;
        *(_DWORD *)(StatusReg + 16) = v41;
        if ( !v41 || !*(_QWORD *)(StatusReg + 16) )
          preempt_schedule_notrace(v40);
      }
LABEL_26:
      result = v8;
      if ( (msm_cvp_debug & 4) != 0 && !msm_cvp_debug_out )
      {
        printk(&unk_85F5D, "info", aon_time, "EVA_KMD_SYNX_SIGNAL_SUCCESS");
        return v8;
      }
      return result;
    }
    v22 = *(_DWORD *)(a3 + 32);
    v23 = *a4;
    v24 = v22 - v21;
    if ( v22 == (_DWORD)v21 )
    {
      result = 0;
LABEL_21:
      if ( v23 != 2 )
        return result;
      if ( (msm_cvp_debug & 0x10000) == 0 )
        return result;
      v25 = *(_DWORD **)(a3 + 312);
      v26 = v25[1];
      if ( v26 <= 0x4021000 || *v25 < 0x44u )
        return result;
      v8 = result;
      get_pkt_name_from_type(v26);
      aon_time = get_aon_time();
      goto LABEL_26;
    }
    v31 = 0;
    result = 0;
    v32 = a3 + 4 * v21 + 44;
    v42 = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v33 = *(_DWORD *)(v32 + 4LL * v31);
      if ( v33 )
      {
        result = synx_signal(v10, v33, v23);
        v34 = msm_cvp_debug_out;
        if ( (_DWORD)result && (v23 = 4, (msm_cvp_debug & 1) != 0) && !msm_cvp_debug_out )
        {
          v36 = result;
          printk(&unk_97581, *(unsigned int *)(v42 + 1800), *(unsigned int *)(v42 + 1804), &unk_8E7CE);
          v34 = msm_cvp_debug_out;
          result = v36;
          v23 = 4;
          if ( (msm_cvp_debug & 0x80) != 0 )
          {
LABEL_46:
            if ( !v34 )
            {
              v35 = result;
              printk(&unk_92ABF, "synx", v33, v23);
              result = v35;
            }
          }
        }
        else if ( (msm_cvp_debug & 0x80) != 0 )
        {
          goto LABEL_46;
        }
      }
      if ( v24 == ++v31 )
        goto LABEL_21;
    }
  }
  if ( a2 == 1 )
  {
    v13 = *(_DWORD *)(a3 + 36);
    if ( v13 )
    {
      for ( i = 0; v13 != i; ++i )
      {
        v15 = *(_DWORD *)(a3 + 44 + 4LL * (int)i);
        if ( v15 )
        {
          v16 = synx_wait(v10, v15, 2000);
          if ( v16 )
          {
            v18 = v16;
            status = synx_get_status(v10, v15);
            *a4 = status;
            if ( status != 2 )
            {
              v37 = status;
              result = v18;
              if ( v37 == 4 )
              {
                if ( (msm_cvp_debug & 0x80) != 0 && !msm_cvp_debug_out )
                {
                  printk(&unk_92A8A, "synx", _ReadStatusReg(SP_EL0) + 2320, i);
                  return v18;
                }
              }
              else
              {
                if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                {
                  v38 = _ReadStatusReg(SP_EL0);
                  printk(&unk_8AF5D, *(unsigned int *)(v38 + 1800), *(unsigned int *)(v38 + 1804), &unk_8E7CE);
                  result = v18;
                }
                *a4 = 4;
              }
              return result;
            }
            if ( (msm_cvp_debug & 0x80) != 0 && !msm_cvp_debug_out )
              printk(&unk_955B3, "synx", "cvp_wait_synx", v20);
          }
          else if ( (msm_cvp_debug & 0x80) != 0 && !msm_cvp_debug_out )
          {
            printk(&unk_89167, "synx", v15, v17);
          }
        }
      }
    }
    if ( *a4 == 2 && (msm_cvp_debug & 0x10000) != 0 )
    {
      v28 = *(_DWORD **)(a3 + 304);
      v29 = v28[1];
      if ( v29 > 0x4011000 && *v28 >= 0x40u )
      {
        get_pkt_name_from_type(v29);
        v30 = get_aon_time();
        result = 0;
        if ( (msm_cvp_debug & 4) == 0 || msm_cvp_debug_out )
          return result;
        printk(&unk_85F5D, "info", v30, "EVA_KMD_SYNX_WAIT_SUCCESS");
      }
    }
    return 0;
  }
  result = 4294967274LL;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v27 = _ReadStatusReg(SP_EL0);
    printk(&unk_888E0, *(unsigned int *)(v27 + 1800), *(unsigned int *)(v27 + 1804), &unk_8E7CE);
    return 4294967274LL;
  }
  return result;
}
