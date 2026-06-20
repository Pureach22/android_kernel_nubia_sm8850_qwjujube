__int64 __fastcall msm_vdec_subscribe_event(__int64 a1, unsigned int *a2)
{
  __int64 v2; // x4
  __int64 result; // x0
  __int64 v6; // x2
  unsigned int v7; // w19

  v2 = *a2;
  switch ( (_DWORD)v2 )
  {
    case 5:
      result = v4l2_src_change_event_subscribe(a1 + 1648, a2);
      if ( !a1 )
        return result;
LABEL_9:
      if ( (_DWORD)result )
      {
        if ( (msm_vidc_debug & 1) != 0 )
        {
          v6 = a1 + 340;
          v7 = result;
          printk(&unk_80288, "err ", v6, "msm_vdec_subscribe_event", *a2);
          return v7;
        }
      }
      return result;
    case 3:
      result = v4l2_ctrl_subscribe_event(a1 + 1648, a2);
      if ( !a1 )
        return result;
      goto LABEL_9;
    case 2:
      result = v4l2_event_subscribe(a1 + 1648, a2, 30, 0);
      if ( !a1 )
        return result;
      goto LABEL_9;
  }
  if ( a1 && (msm_vidc_debug & 1) != 0 )
    printk(&unk_880FE, "err ", a1 + 340, "msm_vdec_subscribe_event", v2);
  return 4294967274LL;
}
