unsigned __int64 __fastcall tx_power_boost_read(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned __int64 a10,
        unsigned __int64 a11)
{
  _QWORD *context; // x21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v22; // w0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x21
  __int64 v41; // x21
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v51; // x9
  __int64 v52; // x0
  unsigned __int64 v53; // x9
  unsigned __int64 v59; // x8
  unsigned __int64 v60; // x8
  unsigned __int64 v62; // x9
  __int64 v63; // [xsp+0h] [xbp-10h] BYREF
  __int64 v64; // [xsp+8h] [xbp-8h]

  v64 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v63 = 0;
  context = _cds_get_context(51, (__int64)"tx_power_boost_read", a1, a2, a3, a4, a5, a6, a7, a8);
  v22 = _wlan_hdd_validate_context(
          (__int64)context,
          (__int64)"tx_power_boost_read",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21);
  if ( !v22 )
  {
    v22 = _osif_psoc_sync_op_start(*(_QWORD *)(context[3] + 488LL), &v63, (__int64)"tx_power_boost_read");
    if ( !v22 )
    {
      if ( wlan_hdd_validate_modules_state((__int64)context, v23, v24, v25, v26, v27, v28, v29, v30) )
      {
        if ( *((unsigned int *)context + 2152) >= a11 )
        {
          if ( a11 >> 31 )
          {
            __break(0x800u);
            a11 = -14;
            goto LABEL_19;
          }
          v41 = context[1072];
          _check_object_size(v41, a11, 1);
          StatusReg = _ReadStatusReg(SP_EL0);
          if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v51 = a10, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
            v51 = a10 & ((__int64)(a10 << 8) >> 8);
          v52 = a11;
          if ( 0x8000000000LL - a11 >= v51 )
          {
            v53 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v59 = *(_QWORD *)(StatusReg + 8);
            _WriteStatusReg(TTBR1_EL1, v59 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
            _WriteStatusReg(TTBR0_EL1, v59);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v53);
            v52 = _arch_copy_to_user(a10 & 0xFF7FFFFFFFFFFFFFLL, v41, a11);
            v60 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v62 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
            _WriteStatusReg(TTBR0_EL1, v62 - 4096);
            _WriteStatusReg(TTBR1_EL1, v62);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v60);
          }
          if ( !v52 )
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: TPB: copy %zu bytes to the app",
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              "__tx_power_boost_read",
              a11,
              v63,
              v64);
            goto LABEL_19;
          }
        }
        else
        {
          v40 = jiffies;
          if ( _tx_power_boost_read___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: TPB: Read overflow! (%zu %u)",
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              "__tx_power_boost_read",
              a11,
              v63,
              v64);
            _tx_power_boost_read___last_ticks = v40;
            a11 = -14;
LABEL_19:
            _osif_psoc_sync_op_stop(v63, (__int64)"tx_power_boost_read");
            goto LABEL_4;
          }
        }
        a11 = -14;
        goto LABEL_19;
      }
      a11 = -22;
      goto LABEL_19;
    }
  }
  a11 = v22;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return a11;
}
