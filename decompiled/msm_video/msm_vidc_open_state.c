__int64 __fastcall msm_vidc_open_state(_DWORD *a1, int a2, unsigned int *a3)
{
  __int64 v6; // x4
  const char *v8; // x4
  void *v9; // x0
  _DWORD *v10; // x2

  if ( (mutex_is_locked(a1 + 4) & 1) == 0 )
  {
    __break(0x800u);
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_839CB, "err ", a1 + 85, "msm_vidc_open_state", v6);
    return 4294967274LL;
  }
  if ( a2 <= 3 )
  {
    if ( a2 <= 1 )
    {
      if ( !a2 )
        return msm_vidc_try_fmt(a1, a3);
      if ( a2 == 1 )
        return msm_vidc_s_fmt((__int64)a1, a3);
LABEL_27:
      if ( a1 )
      {
        if ( (msm_vidc_debug & 1) != 0 )
          printk(&unk_84523, "err ", a1 + 85, "msm_vidc_open_state", "UNKNOWN EVENT");
      }
      return 4294967274LL;
    }
    if ( a2 == 2 )
      return ((__int64 (__fastcall *)(_DWORD *, unsigned int *))msm_vidc_reqbufs)(a1, a3);
    else
      return msm_vidc_s_ctrl((__int64)a1, (__int64)a3);
  }
  else
  {
    if ( a2 <= 5 )
    {
      if ( a2 == 4 )
        return msm_vidc_start_streaming(a1, a3);
      if ( !a1 || (msm_vidc_debug & 2) == 0 )
        return 0;
      v8 = v4l2_type_name(*a3);
      v9 = &unk_8AB8F;
      v10 = a1 + 85;
      goto LABEL_33;
    }
    if ( a2 != 6 )
    {
      if ( a2 != 7 )
      {
        if ( a2 == 8 )
        {
          print_vidc_buffer(4, (__int64)"low ", (__int64)"qbuf deferred", (__int64)a1, (__int64)a3);
          return 0;
        }
        goto LABEL_27;
      }
      if ( !a1 || (msm_vidc_debug & 2) == 0 )
        return 0;
      v9 = &unk_8E84A;
      v8 = "CMD_STOP";
      v10 = a1 + 85;
LABEL_33:
      printk(v9, "high", v10, "msm_vidc_open_state", v8);
      return 0;
    }
    if ( a1 && (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_94C99, "err ", a1 + 85, "msm_vidc_open_state", "CMD_START");
      return 4294967280LL;
    }
    else
    {
      return 4294967280LL;
    }
  }
}
