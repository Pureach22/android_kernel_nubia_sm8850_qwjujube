__int64 __fastcall msm_vidc_input_streaming_state(_DWORD *a1, int a2, unsigned int *a3)
{
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x3
  __int64 v9; // x4
  __int64 v10; // x4
  void *v11; // x0
  const char *v12; // x4
  unsigned int cap_id; // w0
  __int64 v14; // x9
  unsigned int v15; // w20
  __int64 result; // x0
  int v17; // w0
  _DWORD *v18; // x2
  const char *v19; // x4
  void *v20; // x0
  _DWORD *v21; // x2
  const char *v22; // x4

  if ( (mutex_is_locked(a1 + 4) & 1) == 0 )
  {
    __break(0x800u);
    if ( a1 && (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_839CB, "err ", a1 + 85, "msm_vidc_input_streaming_state", v9);
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  if ( a2 <= 3 )
  {
    if ( a2 > 1 )
    {
      if ( a2 != 2 )
      {
        cap_id = msm_vidc_get_cap_id((__int64)a1, a3[18]);
        if ( cap_id )
        {
          if ( a1[77] != 2 )
            goto LABEL_66;
          if ( cap_id >= 0xC6 )
          {
            __break(0x5512u);
            return msm_vidc_output_streaming_state(v14 - 1787);
          }
          if ( (a1[42 * cap_id + 1092] & 1) != 0 )
          {
LABEL_66:
            result = msm_vidc_s_ctrl((__int64)a1, (__int64)a3);
            if ( !(_DWORD)result )
              return 0;
            return result;
          }
          if ( a1 && (msm_vidc_debug & 1) != 0 )
          {
            v15 = cap_id;
            cap_name(cap_id);
            printk(&unk_8CF34, "err ", a1 + 85, "msm_vidc_input_streaming_state", v15);
          }
        }
        else if ( a1 && (msm_vidc_debug & 1) != 0 )
        {
          v20 = &unk_86C95;
          v21 = a1 + 85;
          v10 = 0;
LABEL_96:
          printk(v20, "err ", v21, "msm_vidc_input_streaming_state", v10);
          return 4294967274LL;
        }
        return 4294967274LL;
      }
      v17 = a3[1];
      if ( (v17 | 4) != 0xE )
      {
        result = ((__int64 (__fastcall *)(_DWORD *, unsigned int *))msm_vidc_reqbufs)(a1, a3);
        if ( !(_DWORD)result )
          return 0;
        return result;
      }
      if ( !a1 || (msm_vidc_debug & 1) == 0 )
        return 4294967280LL;
      v4l2_type_name(v17);
      v11 = &unk_894A7;
      v12 = "REQBUFS";
    }
    else if ( a2 )
    {
      if ( a2 != 1 )
        goto LABEL_53;
      if ( (*a3 | 4) != 0xE )
      {
        result = msm_vidc_s_fmt((__int64)a1, a3);
        if ( !(_DWORD)result )
          return 0;
        return result;
      }
      if ( !a1 || (msm_vidc_debug & 1) == 0 )
        return 4294967280LL;
      v4l2_type_name(*a3);
      v11 = &unk_894A7;
      v12 = "S_FMT";
    }
    else
    {
      if ( (*a3 | 4) != 0xE )
      {
        result = msm_vidc_try_fmt(a1, a3);
        if ( !(_DWORD)result )
          return 0;
        return result;
      }
      if ( !a1 || (msm_vidc_debug & 1) == 0 )
        return 4294967280LL;
      v4l2_type_name(*a3);
      v11 = &unk_894A7;
      v12 = "TRY_FMT";
    }
    goto LABEL_49;
  }
  if ( a2 <= 5 )
  {
    if ( a2 != 4 )
    {
      v10 = *a3;
      if ( (int)v10 > 12 )
      {
        if ( (_DWORD)v10 == 14 )
        {
          if ( a1 && (msm_vidc_debug & 1) != 0 )
          {
            v22 = v4l2_type_name(14);
            printk(&unk_89EAD, "err ", a1 + 85, "msm_vidc_input_streaming_state", v22);
            return 4294967274LL;
          }
          return 4294967274LL;
        }
        if ( (_DWORD)v10 != 13 )
          goto LABEL_79;
      }
      else if ( (_DWORD)v10 != 9 )
      {
        if ( (_DWORD)v10 == 10 )
        {
          result = msm_vidc_stop_streaming(a1, a3);
          if ( !(_DWORD)result )
            return 0;
          return result;
        }
LABEL_79:
        if ( a1 && (msm_vidc_debug & 1) != 0 )
        {
          v20 = &unk_9531A;
LABEL_95:
          v21 = a1 + 85;
          goto LABEL_96;
        }
        return 4294967274LL;
      }
      if ( a1 && (msm_vidc_debug & 2) != 0 )
      {
        v19 = v4l2_type_name(v10);
        printk(&unk_8AB8F, "high", a1 + 85, "msm_vidc_input_streaming_state", v19);
      }
      return 0;
    }
    if ( (*a3 | 4) != 0xE )
    {
      result = msm_vidc_start_streaming(a1, a3);
      if ( !(_DWORD)result )
        return 0;
      return result;
    }
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      return 4294967280LL;
    v4l2_type_name(*a3);
    v11 = &unk_878E8;
    v12 = "STREAMON";
LABEL_49:
    v18 = a1 + 85;
LABEL_93:
    printk(v11, "err ", v18, "msm_vidc_input_streaming_state", v12);
    return 4294967280LL;
  }
  if ( a2 == 6 )
  {
    if ( (~a1[44] & 0xA) == 0 || (a1[44] & 5) == 5 )
    {
      result = msm_vidc_start_cmd((__int64)a1, v6, v7, v8);
      if ( !(_DWORD)result )
        return 0;
      return result;
    }
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      return 4294967280LL;
    v11 = &unk_94C99;
    v12 = "CMD_START";
LABEL_92:
    v18 = a1 + 85;
    goto LABEL_93;
  }
  if ( a2 == 7 )
  {
    if ( (a1[44] & 1) == 0 )
    {
      result = msm_vidc_stop_cmd((__int64)a1, v6, v7, v8);
      if ( !(_DWORD)result )
        return 0;
      return result;
    }
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      return 4294967280LL;
    v11 = &unk_8CF76;
    v12 = "CMD_STOP";
    goto LABEL_92;
  }
  if ( a2 != 8 )
  {
LABEL_53:
    if ( a1 && (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_84523, "err ", a1 + 85, "msm_vidc_input_streaming_state", "UNKNOWN EVENT");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v10 = a3[6];
  if ( (unsigned int)(v10 - 3) <= 1 )
  {
LABEL_10:
    print_vidc_buffer(4, (__int64)"low ", (__int64)"qbuf deferred", (__int64)a1, (__int64)a3);
    return 0;
  }
  if ( (_DWORD)v10 != 1 )
  {
    if ( (_DWORD)v10 == 2 )
      goto LABEL_10;
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v20 = &unk_9011E;
    goto LABEL_95;
  }
  result = msm_vidc_buf_queue((__int64)a1, (__int64)a3);
  if ( !(_DWORD)result )
    return 0;
  return result;
}
