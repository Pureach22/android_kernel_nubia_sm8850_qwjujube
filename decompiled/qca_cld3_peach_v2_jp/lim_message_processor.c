void __fastcall lim_message_processor(__int64 a1, unsigned __int16 *a2)
{
  int v3; // w8
  __int64 v4; // x0
  unsigned __int16 *v5; // x21
  int type_subtype; // w0
  _BOOL4 v7; // w8
  unsigned __int16 *v9; // x20
  __int64 v10; // x24
  unsigned int v11; // w21
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x22
  int v30; // w8
  const void *deferred_msg_q; // x0
  unsigned __int16 *v32; // x21
  __int64 v33; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x22
  char v51[4]; // [xsp+4h] [xbp-3Ch] BYREF
  _QWORD v52[7]; // [xsp+8h] [xbp-38h] BYREF

  v52[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_DWORD *)(a1 + 4020) )
  {
    pe_free_msg(a1, (__int64)a2);
    goto LABEL_27;
  }
  v3 = *(_DWORD *)(a1 + 4056);
  LOBYTE(v52[0]) = 0;
  v51[0] = 0;
  if ( !v3 )
  {
    v9 = a2;
    if ( !(unsigned __int8)((__int64 (__fastcall *)(__int64))lim_write_deferred_msg_q)(a1) )
    {
      mac_trace_msg_rx(a1, 255, *v9 | 0x40000000u);
      goto LABEL_27;
    }
    v10 = jiffies;
    if ( lim_defer_msg___last_ticks - jiffies + 125 < 0 )
    {
      v11 = *v9;
      v12 = lim_msg_str(*v9);
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Dropped lim message (0x%X) Message %s",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "lim_defer_msg",
        v11,
        v12);
      lim_defer_msg___last_ticks = v10;
    }
    mac_trace_msg_rx(a1, 255, *v9 | 0x80000000);
    v29 = jiffies;
    if ( def_msg_decision___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Unable to Defer Msg in offline state",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "def_msg_decision");
      def_msg_decision___last_ticks = v29;
    }
    goto LABEL_20;
  }
  if ( *(_BYTE *)(a1 + 8885) )
    goto LABEL_26;
  v4 = *a2;
  if ( (_DWORD)v4 == 5044 )
  {
    v5 = a2;
    type_subtype = lim_util_get_type_subtype(*((_QWORD *)a2 + 1), v52, v51);
    v7 = 1;
    if ( !type_subtype && !LOBYTE(v52[0]) )
      v7 = v51[0] != 8 && v51[0] != 5;
    v4 = *v5;
    a2 = v5;
  }
  else
  {
    v7 = 1;
  }
  if ( (int)v4 <= 4195 )
  {
    if ( (unsigned int)(v4 - 4130) <= 0x3A && ((1LL << ((unsigned __int8)v4 - 34)) & 0x6002000000A0045LL) != 0 )
      goto LABEL_26;
    goto LABEL_44;
  }
  if ( (int)v4 > 5043 )
  {
    if ( (_DWORD)v4 == 5084 )
      goto LABEL_26;
    if ( (_DWORD)v4 == 5044 )
    {
      if ( *(_BYTE *)(a1 + 8876) )
        LOBYTE(v7) = 0;
      if ( !v7 )
        goto LABEL_26;
LABEL_45:
      v32 = a2;
      v33 = lim_msg_str(v4);
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Defer the current message %s , gLimProcessDefdMsgs is false and system is not in scan/learn mode",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "def_msg_decision",
        v33);
      v9 = v32;
      if ( !(unsigned int)lim_defer_msg(a1, v32) )
        goto LABEL_27;
      v50 = jiffies;
      if ( def_msg_decision___last_ticks_26 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(0x35u, 2u, "%s: Unable to Defer Msg", v42, v43, v44, v45, v46, v47, v48, v49, "def_msg_decision");
        def_msg_decision___last_ticks_26 = v50;
      }
LABEL_20:
      lim_log_session_states(a1);
      lim_handle_defer_msg_error(a1, v9);
      goto LABEL_27;
    }
LABEL_44:
    if ( !v7 )
      goto LABEL_26;
    goto LABEL_45;
  }
  if ( (_DWORD)v4 != 4196 && (_DWORD)v4 != 4238 )
    goto LABEL_44;
LABEL_26:
  lim_process_messages(a1, (int)a2);
  if ( !*(_BYTE *)(a1 + 8876) )
  {
    if ( *(_BYTE *)(a1 + 8885) )
    {
      v30 = *(unsigned __int16 *)(a1 + 8688);
      memset(v52, 0, 48);
      if ( v30 )
      {
        do
        {
          deferred_msg_q = (const void *)lim_read_deferred_msg_q(a1);
          if ( !deferred_msg_q )
            break;
          qdf_mem_copy(v52, deferred_msg_q, 0x30u);
          lim_process_messages(a1, (int)v52);
          if ( !*(_BYTE *)(a1 + 8885) )
            break;
        }
        while ( !*(_BYTE *)(a1 + 8876) );
      }
    }
  }
LABEL_27:
  _ReadStatusReg(SP_EL0);
}
