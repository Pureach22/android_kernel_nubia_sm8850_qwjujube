__int64 __fastcall msm_vidc_dqevent(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x4
  __int64 v5; // x2
  unsigned int v6; // w19

  result = v4l2_event_dequeue(a1 + 1648, a2, 0);
  if ( a1 && (_DWORD)result && (msm_vidc_debug & 1) != 0 )
  {
    v5 = a1 + 340;
    v6 = result;
    printk(&unk_8EED0, "err ", v5, "msm_vidc_dqevent", v4);
    return v6;
  }
  return result;
}
