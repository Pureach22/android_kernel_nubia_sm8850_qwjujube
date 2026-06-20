__int64 __fastcall msm_vidc_unsubscribe_event(__int64 a1, unsigned int *a2)
{
  __int64 v2; // x19
  __int64 result; // x0
  __int64 v5; // x2
  unsigned int v6; // w19

  if ( !a1 )
    return v4l2_event_unsubscribe(1648);
  v2 = a1;
  if ( (msm_vidc_debug & 2) != 0 )
  {
    printk(&unk_857D6, "high", a1 + 340, "msm_vidc_unsubscribe_event", *a2);
    a1 = v2;
  }
  result = v4l2_event_unsubscribe(a1 + 1648);
  if ( (_DWORD)result )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v5 = v2 + 340;
      v6 = result;
      printk(&unk_80288, "err ", v5, "msm_vidc_unsubscribe_event", *a2);
      return v6;
    }
  }
  return result;
}
