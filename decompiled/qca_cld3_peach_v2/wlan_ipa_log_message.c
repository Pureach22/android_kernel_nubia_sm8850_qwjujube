unsigned __int64 wlan_ipa_log_message(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        ...)
{
  unsigned __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w24
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x20
  __int64 v31; // x20
  unsigned __int64 StatusReg; // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  _QWORD *v41; // x21
  unsigned int v42; // w0
  unsigned int v43; // w22
  unsigned __int64 v44; // x23
  unsigned __int64 v45; // x25
  const char *v46; // x3
  __int64 v47; // x20
  __int64 v48; // x6
  const char *v49; // x7
  unsigned int v50; // w23
  unsigned int v51; // w0
  unsigned int v52; // w19
  unsigned int v53; // w24
  unsigned __int64 v60; // x9
  __int64 v61; // [xsp+8h] [xbp-2F8h]
  __int64 v62; // [xsp+10h] [xbp-2F0h]
  __int64 v63; // [xsp+18h] [xbp-2E8h]
  __int64 v64; // [xsp+20h] [xbp-2E0h]
  __int64 v65; // [xsp+28h] [xbp-2D8h]
  __int64 v66; // [xsp+30h] [xbp-2D0h]
  gcc_va_list va; // [xsp+38h] [xbp-2C8h] BYREF
  _QWORD *v68; // [xsp+58h] [xbp-2A8h] BYREF
  char s[512]; // [xsp+60h] [xbp-2A0h] BYREF
  _QWORD v70[2]; // [xsp+260h] [xbp-A0h] BYREF
  int v71; // [xsp+270h] [xbp-90h]
  gcc_va_list va1; // [xsp+278h] [xbp-88h] BYREF
  __int64 v73; // [xsp+298h] [xbp-68h]
  __int64 v74; // [xsp+2A0h] [xbp-60h]
  __int64 v75; // [xsp+2A8h] [xbp-58h]
  __int64 v76; // [xsp+2B0h] [xbp-50h]
  __int64 v77; // [xsp+2B8h] [xbp-48h]
  __int64 v78; // [xsp+2C0h] [xbp-40h]
  __int64 v79; // [xsp+2C8h] [xbp-38h]
  __int64 v80; // [xsp+2D0h] [xbp-30h]
  int v81; // [xsp+2D8h] [xbp-28h]
  _QWORD v82[2]; // [xsp+2E0h] [xbp-20h] BYREF
  int v83; // [xsp+2F0h] [xbp-10h]
  __int64 v84; // [xsp+2F8h] [xbp-8h]

  va_start(va, a10);
  v61 = va_arg(va, _QWORD);
  v62 = va_arg(va, _QWORD);
  v63 = va_arg(va, _QWORD);
  v64 = va_arg(va, _QWORD);
  v65 = va_arg(va, _QWORD);
  v66 = va_arg(va, _QWORD);
  va_end(va);
  va_start(va1, a10);
  va_start(va, a10);
  v84 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  vscnprintf(s, 512, a2, va1);
  result = strnlen(s, 0x200u);
  if ( result >= 0x201 )
  {
    _fortify_panic(2, 512, result + 1);
LABEL_42:
    _fortify_panic(4, 512, 513);
  }
  if ( result == 512 )
    goto LABEL_42;
  v81 = 0;
  v79 = 0;
  v80 = 0;
  v77 = 0;
  v78 = 0;
  v75 = 0;
  v76 = 0;
  v73 = 0;
  v74 = 0;
  memset(va1, 0, sizeof(va1));
  v68 = nullptr;
  v71 = 0;
  v70[0] = 0;
  v70[1] = 0;
  if ( dword_92E0AC == 1 )
  {
    v21 = result;
    result = qdf_list_empty(&g_ipa_logging_ctx);
    if ( (result & 1) != 0 )
    {
      v30 = jiffies;
      if ( wlan_ipa_send_to_filled_list___last_ticks_21 - jiffies + 125 < 0 )
      {
        result = qdf_trace_msg(
                   0x61u,
                   2u,
                   "%s: no free entries available in list",
                   v22,
                   v23,
                   v24,
                   v25,
                   v26,
                   v27,
                   v28,
                   v29,
                   "wlan_ipa_send_to_filled_list");
        wlan_ipa_send_to_filled_list___last_ticks_21 = v30;
      }
      byte_92E0A8 = 1;
      ++word_92E098;
    }
    else
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(&dword_92D868);
      }
      else
      {
        raw_spin_lock_bh(&dword_92D868);
        qword_92D870 |= 1uLL;
      }
      qdf_list_remove_front(&g_ipa_logging_ctx, &v68);
      if ( (qword_92D870 & 1) != 0 )
      {
        qword_92D870 &= ~1uLL;
        result = raw_spin_unlock_bh(&dword_92D868);
      }
      else
      {
        result = raw_spin_unlock(&dword_92D868);
      }
      v41 = v68 + 2;
      if ( v68 == (_QWORD *)-16LL )
      {
        v47 = jiffies;
        if ( wlan_ipa_send_to_filled_list___last_ticks_23 - jiffies + 125 < 0 )
        {
          result = qdf_trace_msg(
                     0x61u,
                     2u,
                     "%s: error on fetching log buffer",
                     v33,
                     v34,
                     v35,
                     v36,
                     v37,
                     v38,
                     v39,
                     v40,
                     "wlan_ipa_send_to_filled_list");
          wlan_ipa_send_to_filled_list___last_ticks_23 = v47;
        }
      }
      else
      {
        scnprintf(v70, 20, "[%s]", "OPT_DP_HOST");
        v43 = v42;
        __isb(0xFu);
        v44 = _ReadStatusReg(CNTVCT_EL0);
        v83 = 0;
        v82[0] = 0;
        v82[1] = 0;
        qdf_get_time_of_the_day_in_hr_min_sec_usec((__int64)v82, 20);
        v45 = _ReadStatusReg(SP_EL0);
        if ( (*(_DWORD *)(v45 + 16) & 0xF0000) != 0 )
        {
          v46 = "irq";
        }
        else if ( (*(_DWORD *)(v45 + 16) & 0xFF00) != 0 )
        {
          v46 = "soft_irq";
        }
        else
        {
          v46 = (const char *)(v45 + 2320);
        }
        if ( (*(_DWORD *)(v45 + 16) & 0xFFFF00) != 0 )
          v48 = 0;
        else
          v48 = *(unsigned int *)(v45 + 1800);
        if ( byte_92E0A8 )
          v49 = "**";
        else
          v49 = (const char *)&unk_98C763;
        scnprintf(va1, 100, "[%.6s][0x%llx]%s[%d]%s%s: ", v46, v44, v82, v48, v49, a1, v61, v62, v63, v64, v65, v66);
        v50 = v21;
        v52 = v51;
        v53 = v43 + v21 + v51;
        qdf_mem_copy(v41, v70, v43);
        qdf_mem_copy((char *)v41 + (int)v43, va1, v52);
        qdf_mem_copy((char *)v41 + (int)(v52 + v43), s, v50);
        *((_BYTE *)v41 + (int)v53) = 10;
        *((_BYTE *)v41 + (int)(v53 + 1)) = 0;
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v45 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v45 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(&dword_92D868);
        }
        else
        {
          raw_spin_lock_bh(&dword_92D868);
          qword_92D870 |= 1uLL;
        }
        qdf_list_insert_back(&qword_92D850, v68);
        if ( (qword_92D870 & 1) != 0 )
        {
          qword_92D870 &= ~1uLL;
          raw_spin_unlock_bh(&dword_92D868);
        }
        else
        {
          raw_spin_unlock(&dword_92D868);
        }
        _X8 = &qword_92E0A0;
        __asm { PRFM            #0x11, [X8] }
        do
          v60 = __ldxr((unsigned __int64 *)&qword_92E0A0);
        while ( __stxr(v60 | 2, (unsigned __int64 *)&qword_92E0A0) );
        result = _wake_up(&unk_92E078, 1, 1, 0);
      }
    }
  }
  else
  {
    v31 = jiffies;
    if ( wlan_ipa_send_to_filled_list___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x61u,
                 2u,
                 "%s: ipa_logging framework is not active",
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 "wlan_ipa_send_to_filled_list");
      wlan_ipa_send_to_filled_list___last_ticks = v31;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
