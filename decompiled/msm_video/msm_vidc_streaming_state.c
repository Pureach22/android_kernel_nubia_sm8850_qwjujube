__int64 __fastcall msm_vidc_streaming_state(__int64 a1, int a2, unsigned int *a3)
{
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x3
  __int64 v9; // x4
  __int64 v10; // x4
  const char *v11; // x4
  void *v12; // x0
  const char *v13; // x4
  unsigned int cap_id; // w0
  __int64 v15; // x9
  unsigned int v16; // w20
  const char *v17; // x4
  void *v18; // x0
  __int64 v19; // x2
  __int64 result; // x0

  if ( (mutex_is_locked(a1 + 16) & 1) == 0 )
  {
    __break(0x800u);
    if ( a1 && (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_839CB, "err ", a1 + 340, "msm_vidc_streaming_state", v9);
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  if ( a2 > 5 )
  {
    switch ( a2 )
    {
      case 6:
        if ( (~*(_DWORD *)(a1 + 176) & 0xA) == 0 || (*(_DWORD *)(a1 + 176) & 5) == 5 )
        {
          result = msm_vidc_start_cmd(a1, v6, v7, v8);
          if ( !(_DWORD)result )
            return 0;
          return result;
        }
        if ( !a1 || (msm_vidc_debug & 1) == 0 )
          return 4294967280LL;
        v12 = &unk_94C99;
        v13 = "CMD_START";
        break;
      case 7:
        if ( (*(_BYTE *)(a1 + 176) & 1) == 0 )
        {
          result = msm_vidc_stop_cmd(a1, v6, v7, v8);
          if ( !(_DWORD)result )
            return 0;
          return result;
        }
        if ( !a1 || (msm_vidc_debug & 1) == 0 )
          return 4294967280LL;
        v12 = &unk_8CF76;
        v13 = "CMD_STOP";
        break;
      case 8:
        v10 = a3[6];
        if ( (unsigned int)(v10 - 3) <= 1 )
        {
          print_vidc_buffer(4, (__int64)"low ", (__int64)"qbuf deferred", a1, (__int64)a3);
          return 0;
        }
        if ( (unsigned int)(v10 - 1) < 2 )
        {
          result = msm_vidc_buf_queue(a1, (__int64)a3);
          if ( !(_DWORD)result )
            return 0;
          return result;
        }
        if ( a1 && (msm_vidc_debug & 1) != 0 )
        {
          v18 = &unk_9011E;
LABEL_60:
          v19 = a1 + 340;
          goto LABEL_61;
        }
        return 4294967274LL;
      default:
        goto LABEL_29;
    }
    printk(v12, "err ", a1 + 340, "msm_vidc_streaming_state", v13);
    return 4294967280LL;
  }
  if ( a2 != 3 )
  {
    if ( a2 == 5 )
    {
      v10 = *a3;
      if ( (unsigned int)(v10 - 9) < 2 )
      {
        result = msm_vidc_stop_streaming(a1, a3);
        if ( !(_DWORD)result )
          return 0;
        return result;
      }
      if ( (unsigned int)(v10 - 13) > 1 )
      {
        if ( a1 && (msm_vidc_debug & 1) != 0 )
        {
          v18 = &unk_9531A;
          goto LABEL_60;
        }
      }
      else if ( a1 && (msm_vidc_debug & 1) != 0 )
      {
        v11 = v4l2_type_name(v10);
        printk(&unk_89EAD, "err ", a1 + 340, "msm_vidc_streaming_state", v11);
        return 4294967274LL;
      }
      return 4294967274LL;
    }
LABEL_29:
    if ( a1 && (msm_vidc_debug & 1) != 0 )
    {
      if ( (unsigned int)a2 <= 8 )
        v17 = event_name_arr[a2];
      else
        v17 = "UNKNOWN EVENT";
      printk(&unk_84523, "err ", a1 + 340, "msm_vidc_streaming_state", v17);
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  cap_id = msm_vidc_get_cap_id(a1, a3[18]);
  if ( !cap_id )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
    {
      v18 = &unk_86C95;
      v19 = a1 + 340;
      v10 = 0;
LABEL_61:
      printk(v18, "err ", v19, "msm_vidc_streaming_state", v10);
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  if ( cap_id >= 0xC6 )
  {
    __break(0x5512u);
    return msm_vidc_close_state(v15 - 1787);
  }
  if ( (*(_BYTE *)(a1 + 168LL * cap_id + 4368) & 1) == 0 )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
    {
      v16 = cap_id;
      cap_name(cap_id);
      printk(&unk_95A65, "err ", a1 + 340, "msm_vidc_streaming_state", v16);
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  result = msm_vidc_s_ctrl(a1, (__int64)a3);
  if ( !(_DWORD)result )
    return 0;
  return result;
}
