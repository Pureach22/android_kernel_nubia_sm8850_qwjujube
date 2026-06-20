__int64 __fastcall ipa_get_clock_stats(unsigned __int64 a1)
{
  __int64 v2; // x21
  _DWORD *v3; // x0
  _DWORD *v4; // x19
  __int64 aggregated_throughput; // x0
  _DWORD *v6; // x22
  unsigned int v7; // w23
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v9; // x9
  __int64 v10; // x0
  unsigned __int64 v11; // x9
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x8
  unsigned __int64 v20; // x9
  __int64 v22; // x0
  __int64 ipc_logbuf; // x0
  __int64 v24; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x0

  if ( (dword_2011F8 & 2) == 0 )
  {
    v22 = printk(&unk_3F88CC, "ipa_get_clock_stats");
    ipc_logbuf = ipa3_get_ipc_logbuf(v22);
    if ( ipc_logbuf )
    {
      v24 = ipa3_get_ipc_logbuf(ipc_logbuf);
      ipc_logbuf = ipc_log_string(v24, "ipa-lnx-stats %s:%d Log type CLOCK mask not set\n", "ipa_get_clock_stats", 306);
    }
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
    if ( ipc_logbuf_low )
    {
      v26 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
      ipc_log_string(v26, "ipa-lnx-stats %s:%d Log type CLOCK mask not set\n", "ipa_get_clock_stats", 306);
    }
    return 4294967282LL;
  }
  v2 = 24 * dword_201204 + 24;
  v3 = (_DWORD *)memdup_user(a1, v2);
  if ( (unsigned __int64)v3 >= 0xFFFFFFFFFFFFF001LL )
  {
    v27 = printk(&unk_3B0209, "ipa_get_clock_stats");
    v28 = ipa3_get_ipc_logbuf(v27);
    if ( v28 )
    {
      v29 = ipa3_get_ipc_logbuf(v28);
      v28 = ipc_log_string(v29, "ipa-lnx-stats %s:%d copy from user failed\n", "ipa_get_clock_stats", 317);
    }
    v30 = ipa3_get_ipc_logbuf_low(v28);
    if ( v30 )
    {
      v31 = ipa3_get_ipc_logbuf_low(v30);
      ipc_log_string(v31, "ipa-lnx-stats %s:%d copy from user failed\n", "ipa_get_clock_stats", 317);
    }
    return 4294967284LL;
  }
  else
  {
    v4 = v3;
    if ( (unsigned int)ipa_pm_get_scaling_bw_levels(v3) )
    {
      v32 = printk(&unk_3D35BA, "ipa_get_clock_stats");
      v33 = ipa3_get_ipc_logbuf(v32);
      if ( v33 )
      {
        v34 = ipa3_get_ipc_logbuf(v33);
        v33 = ipc_log_string(v34, "ipa-lnx-stats %s:%d Couldn't get scaling bw levels\n", "ipa_get_clock_stats", 322);
      }
      v35 = ipa3_get_ipc_logbuf_low(v33);
      if ( v35 )
      {
        v36 = ipa3_get_ipc_logbuf_low(v35);
        ipc_log_string(v36, "ipa-lnx-stats %s:%d Couldn't get scaling bw levels\n", "ipa_get_clock_stats", 322);
      }
    }
    aggregated_throughput = ipa_pm_get_aggregated_throughput();
    if ( (unsigned int)v2 >= 0x11 )
    {
      v4[4] = aggregated_throughput;
      aggregated_throughput = ipa_pm_get_current_clk_vote();
      if ( (unsigned int)v2 >= 0x14 )
      {
        v4[5] = aggregated_throughput;
        *v4 = 0;
        if ( (unsigned int)dword_201204 >= 2 )
        {
          v6 = v4 + 6;
          v7 = 1;
          do
          {
            if ( (((__int64 (__fastcall *)(_DWORD *, _QWORD))ipa_get_pm_client_stats_filled)(v6, v7) & 1) != 0 )
            {
              v6 += 6;
              ++*v4;
            }
            ++v7;
          }
          while ( v7 < dword_201204 );
        }
        if ( (v2 & 0x80000000) != 0 )
        {
          __break(0x800u);
        }
        else
        {
          _check_object_size(v4, v2, 1);
          StatusReg = _ReadStatusReg(SP_EL0);
          if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v9 = a1, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
            v9 = a1 & ((__int64)(a1 << 8) >> 8);
          v10 = 1;
          if ( 0x8000000000LL - v2 >= v9 )
          {
            v11 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v17 = *(_QWORD *)(StatusReg + 8);
            _WriteStatusReg(TTBR1_EL1, v17 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
            _WriteStatusReg(TTBR0_EL1, v17);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v11);
            v10 = _arch_copy_to_user(a1 & 0xFF7FFFFFFFFFFFFFLL, v4, v2);
            v18 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v20 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
            _WriteStatusReg(TTBR0_EL1, v20 - 4096);
            _WriteStatusReg(TTBR1_EL1, v20);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v18);
          }
          if ( !v10 )
          {
            kfree(v4);
            return 0;
          }
        }
        kfree(v4);
        v37 = printk(&unk_3B576A, "ipa_get_clock_stats");
        v38 = ipa3_get_ipc_logbuf(v37);
        if ( v38 )
        {
          v39 = ipa3_get_ipc_logbuf(v38);
          v38 = ipc_log_string(v39, "ipa-lnx-stats %s:%d copy to user failed", "ipa_get_clock_stats", 341);
        }
        v40 = ipa3_get_ipc_logbuf_low(v38);
        if ( v40 )
        {
          v41 = ipa3_get_ipc_logbuf_low(v40);
          ipc_log_string(v41, "ipa-lnx-stats %s:%d copy to user failed", "ipa_get_clock_stats", 341);
        }
        return 4294967282LL;
      }
    }
    __break(1u);
    return ipa_get_wlan_inst_stats(aggregated_throughput);
  }
}
