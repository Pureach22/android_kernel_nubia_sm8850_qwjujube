__int64 __fastcall qdf_trace_dump_all(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        __int64 a11,
        unsigned int a12,
        unsigned int a13)
{
  unsigned int v17; // w22
  int v18; // w24
  int v19; // w8
  __int64 result; // x0
  __int64 *v21; // x8
  __int64 v22; // x9
  __int64 v23; // x10
  __int64 v24; // x9
  _DWORD *v25; // x8
  __int64 *v26; // x8
  __int64 v27; // x9
  __int64 v28; // x10
  __int64 v29; // x9
  __int64 v30; // [xsp+0h] [xbp-30h] BYREF
  __int64 v31; // [xsp+8h] [xbp-28h]
  __int64 v32; // [xsp+10h] [xbp-20h]
  __int64 v33; // [xsp+18h] [xbp-18h]
  __int64 v34; // [xsp+20h] [xbp-10h]
  __int64 v35; // [xsp+28h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v30 = 0;
  if ( (g_qdf_trace_data_4 & 1) != 0 )
  {
    qdf_trace_msg(
      0x37u,
      4u,
      "DPT: Total Records: %d, Head: %d, Tail: %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      (unsigned int)g_qdf_trace_data_2,
      (unsigned int)g_qdf_trace_data_0,
      (unsigned int)g_qdf_trace_data_1,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35);
    raw_spin_lock(&ltrace_lock);
    v17 = g_qdf_trace_data_0;
    if ( g_qdf_trace_data_0 == -1 )
    {
      result = raw_spin_unlock(&ltrace_lock);
    }
    else
    {
      v18 = g_qdf_trace_data_1;
      if ( a12 )
      {
        v19 = g_qdf_trace_data_2;
        if ( g_qdf_trace_data_2 >= a12 )
          v19 = a12;
        if ( g_qdf_trace_data_1 >= (unsigned int)(v19 - 1) )
        {
          v17 = g_qdf_trace_data_1 - v19 + 1;
        }
        else if ( v19 != 4000 )
        {
          v17 = g_qdf_trace_data_1 - v19 + 4001;
        }
      }
      if ( v17 >= 0xFA1 )
LABEL_30:
        __break(0x5512u);
      v21 = &g_qdf_trace_tbl[5 * v17];
      v22 = v21[2];
      v23 = v21[3];
      v34 = v21[4];
      v32 = v22;
      v33 = v23;
      v24 = v21[1];
      v30 = *v21;
      v31 = v24;
      g_qdf_trace_data_3 = 0;
      for ( result = raw_spin_unlock(&ltrace_lock); ; result = raw_spin_unlock(&ltrace_lock) )
      {
        if ( !a2 || WORD2(v33) == a2 )
        {
          if ( BYTE2(v33) > 0xA6uLL )
            goto LABEL_30;
          v25 = (_DWORD *)qdf_trace_cb_table[BYTE2(v33)];
          if ( v25 && (!a13 || ((a13 >> SBYTE2(v33)) & 1) != 0) )
          {
            if ( *(v25 - 1) != 1068323170 )
              __break(0x8228u);
            result = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))v25)(a1, &v30, v17);
          }
        }
        if ( v17 == v18 )
          break;
        ++v17;
        raw_spin_lock(&ltrace_lock);
        if ( v17 == 4000 )
        {
          v17 = 0;
          v32 = qword_7175E0;
          v33 = qword_7175E8;
          v34 = qword_7175F0;
          v30 = g_qdf_trace_tbl[0];
          v31 = qword_7175D8;
        }
        else
        {
          if ( v17 > 0xFA0 )
            goto LABEL_30;
          v26 = &g_qdf_trace_tbl[5 * v17];
          v27 = v26[2];
          v28 = v26[3];
          v34 = v26[4];
          v32 = v27;
          v33 = v28;
          v29 = v26[1];
          v30 = *v26;
          v31 = v29;
        }
      }
    }
  }
  else
  {
    result = qdf_trace_msg(0x37u, 2u, "Tracing Disabled", a3, a4, a5, a6, a7, a8, a9, a10, v30, v31, v32, v33, v34, v35);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
