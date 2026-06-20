__int64 __fastcall qdf_trace(__int64 result, unsigned int a2, __int16 a3, int a4)
{
  unsigned __int64 StatusReg; // x8
  unsigned __int16 v5; // w19
  unsigned __int64 v6; // x21
  __int64 v9; // x20
  int v10; // w11
  int v11; // w10
  __int16 v12; // w9
  int v13; // w8
  _QWORD v14[2]; // [xsp+0h] [xbp-20h] BYREF
  __int16 v15; // [xsp+10h] [xbp-10h]
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( g_qdf_trace_data_4 != 1 )
    goto LABEL_24;
  StatusReg = (unsigned __int8)result;
  v5 = result;
  v15 = 0;
  v14[0] = 0;
  v14[1] = 0;
  if ( (unsigned __int8)result < 0xA7u )
  {
    if ( !qdf_trace_cb_table[(unsigned __int8)result] )
    {
LABEL_24:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    v6 = a2;
    qdf_get_time_of_the_day_in_hr_min_sec_usec((__int64)v14, 18);
    v9 = raw_spin_lock_irqsave(&ltrace_lock);
    if ( (unsigned int)(g_qdf_trace_data_2 + 1) < 0xFA0 )
      v10 = g_qdf_trace_data_2 + 1;
    else
      v10 = 4000;
    g_qdf_trace_data_2 = v10;
    if ( g_qdf_trace_data_0 == -1 )
    {
      g_qdf_trace_data_0 = 0;
      LODWORD(StatusReg) = 0;
      g_qdf_trace_data_1 = 0;
      v12 = v6;
      goto LABEL_18;
    }
    if ( g_qdf_trace_data_1 == 3999 )
      StatusReg = 0;
    else
      StatusReg = (unsigned int)(g_qdf_trace_data_1 + 1);
    if ( g_qdf_trace_data_0 == (_DWORD)StatusReg )
    {
      if ( g_qdf_trace_data_0 == 3999 )
        v11 = 0;
      else
        v11 = g_qdf_trace_data_0 + 1;
      g_qdf_trace_data_0 = v11;
    }
    v12 = v6;
    g_qdf_trace_data_1 = StatusReg;
    if ( (unsigned int)StatusReg <= 0xFA0 )
    {
      if ( (unsigned int)StatusReg > 0xF9F )
      {
        __break(1u);
        goto LABEL_22;
      }
LABEL_18:
      v6 = (unsigned __int64)&g_qdf_trace_tbl[5 * (unsigned int)StatusReg];
      *(_WORD *)(v6 + 28) = v12;
      *(_WORD *)(v6 + 30) = a3;
      *(_DWORD *)(v6 + 32) = a4;
      __isb(0xFu);
      *(_QWORD *)v6 = _ReadStatusReg(CNTVCT_EL0);
      scnprintf(v6 + 8, 18, "%s", (const char *)v14);
      *(_BYTE *)(v6 + 26) = v5;
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) != 0 )
      {
        v13 = 0;
LABEL_23:
        *(_DWORD *)(v6 + 36) = v13;
        ++g_qdf_trace_data_3;
        result = raw_spin_unlock_irqrestore(&ltrace_lock, v9);
        goto LABEL_24;
      }
LABEL_22:
      v13 = *(_DWORD *)(StatusReg + 1800);
      goto LABEL_23;
    }
  }
  __break(0x5512u);
  atomic_store(v5, (unsigned __int16 *)(StatusReg - 206));
  return qdf_mtrace_log();
}
