__int64 __fastcall msm_vidc_output_streaming_state(_DWORD *a1, int a2, unsigned int *a3)
{
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x3
  __int64 v9; // x4
  __int64 v10; // x4
  __int64 result; // x0
  void *v12; // x0
  const char *v13; // x4
  unsigned int cap_id; // w0
  __int64 v15; // x9
  unsigned int v16; // w20
  void *v17; // x0
  int v18; // w0
  _DWORD *v19; // x2
  const char *v20; // x4
  _DWORD *v21; // x2
  const char *v22; // x4

  if ( (mutex_is_locked(a1 + 4) & 1) == 0 )
  {
    __break(0x800u);
    if ( a1 && (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_839CB, "err ", a1 + 85, "msm_vidc_output_streaming_state", v9);
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
          if ( a1[77] != 1 )
            goto LABEL_66;
          if ( cap_id >= 0xC6 )
          {
            __break(0x5512u);
            return msm_vidc_streaming_state(v15 - 1787);
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
            v16 = cap_id;
            cap_name(cap_id);
            printk(&unk_95A65, "err ", a1 + 85, "msm_vidc_output_streaming_state", v16);
          }
          return 4294967274LL;
        }
        if ( !a1 || (msm_vidc_debug & 1) == 0 )
          return 4294967274LL;
        v17 = &unk_86C95;
        v21 = a1 + 85;
        v10 = 0;
LABEL_93:
        printk(v17, "err ", v21, "msm_vidc_output_streaming_state", v10);
        return 4294967274LL;
      }
      v18 = a3[1];
      if ( (v18 | 4) != 0xD )
      {
        result = ((__int64 (__fastcall *)(_DWORD *, unsigned int *))msm_vidc_reqbufs)(a1, a3);
        if ( !(_DWORD)result )
          return 0;
        return result;
      }
      if ( !a1 || (msm_vidc_debug & 1) == 0 )
        return 4294967280LL;
      v4l2_type_name(v18);
      v12 = &unk_894A7;
      v13 = "REQBUFS";
    }
    else if ( a2 )
    {
      if ( a2 != 1 )
        goto LABEL_55;
      if ( (*a3 | 4) != 0xD )
      {
        result = msm_vidc_s_fmt((__int64)a1, a3);
        if ( !(_DWORD)result )
          return 0;
        return result;
      }
      if ( !a1 || (msm_vidc_debug & 1) == 0 )
        return 4294967280LL;
      v4l2_type_name(*a3);
      v12 = &unk_894A7;
      v13 = "S_FMT";
    }
    else
    {
      if ( (*a3 | 4) != 0xD )
      {
        result = msm_vidc_try_fmt(a1, a3);
        if ( !(_DWORD)result )
          return 0;
        return result;
      }
      if ( !a1 || (msm_vidc_debug & 1) == 0 )
        return 4294967280LL;
      v4l2_type_name(*a3);
      v12 = &unk_894A7;
      v13 = "TRY_FMT";
    }
    goto LABEL_51;
  }
  if ( a2 <= 5 )
  {
    if ( a2 != 4 )
    {
      v10 = *a3;
      if ( (int)v10 > 12 )
      {
        if ( (_DWORD)v10 == 13 )
        {
          if ( a1 && (msm_vidc_debug & 1) != 0 )
          {
            v22 = v4l2_type_name(13);
            printk(&unk_89EAD, "err ", a1 + 85, "msm_vidc_output_streaming_state", v22);
            return 4294967274LL;
          }
          return 4294967274LL;
        }
        if ( (_DWORD)v10 != 14 )
          goto LABEL_31;
      }
      else
      {
        if ( (_DWORD)v10 == 9 )
        {
          result = msm_vidc_stop_streaming(a1, a3);
          if ( (_DWORD)result )
            return result;
          return 0;
        }
        if ( (_DWORD)v10 != 10 )
        {
LABEL_31:
          if ( !a1 || (msm_vidc_debug & 1) == 0 )
            return 4294967274LL;
          v17 = &unk_9531A;
LABEL_92:
          v21 = a1 + 85;
          goto LABEL_93;
        }
      }
      if ( a1 && (msm_vidc_debug & 2) != 0 )
      {
        v20 = v4l2_type_name(v10);
        printk(&unk_8AB8F, "high", a1 + 85, "msm_vidc_output_streaming_state", v20);
      }
      return 0;
    }
    if ( (*a3 | 4) != 0xD )
    {
      result = msm_vidc_start_streaming(a1, a3);
      if ( !(_DWORD)result )
        return 0;
      return result;
    }
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      return 4294967280LL;
    v4l2_type_name(*a3);
    v12 = &unk_878E8;
    v13 = "STREAMON";
LABEL_51:
    v19 = a1 + 85;
LABEL_90:
    printk(v12, "err ", v19, "msm_vidc_output_streaming_state", v13);
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
    if ( a1 && (msm_vidc_debug & 1) != 0 )
    {
      v12 = &unk_94C99;
      v13 = "CMD_START";
LABEL_89:
      v19 = a1 + 85;
      goto LABEL_90;
    }
    return 4294967280LL;
  }
  if ( a2 == 7 )
  {
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      return 4294967280LL;
    v12 = &unk_8E88B;
    v13 = "CMD_STOP";
    goto LABEL_89;
  }
  if ( a2 != 8 )
  {
LABEL_55:
    if ( a1 && (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_84523, "err ", a1 + 85, "msm_vidc_output_streaming_state", "UNKNOWN EVENT");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v10 = a3[6];
  if ( (unsigned int)(v10 - 3) <= 1 || (_DWORD)v10 == 1 )
  {
    print_vidc_buffer(4, (__int64)"low ", (__int64)"qbuf deferred", (__int64)a1, (__int64)a3);
    return 0;
  }
  if ( (_DWORD)v10 != 2 )
  {
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v17 = &unk_9011E;
    goto LABEL_92;
  }
  result = msm_vidc_buf_queue((__int64)a1, (__int64)a3);
  if ( !(_DWORD)result )
    return 0;
  return result;
}
