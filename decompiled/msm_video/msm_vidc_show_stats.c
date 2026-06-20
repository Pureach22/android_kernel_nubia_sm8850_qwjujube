__int64 __fastcall msm_vidc_show_stats(__int64 result)
{
  __int64 v1; // x19
  unsigned __int64 v2; // x8
  __int64 v3; // x21

  v1 = result + 340;
  if ( *(_BYTE *)(result + 4144) )
  {
    if ( result && (v2 = *(unsigned int *)(result + 4228), (_DWORD)v2) )
    {
      if ( (msm_vidc_debug & 8) != 0 )
      {
        v3 = result;
        printk(&unk_84D38, "perf", result + 340, result + 4144, *(_QWORD *)(result + 4136) / v2);
        result = v3;
      }
    }
    else if ( !result )
    {
      return result;
    }
    if ( (msm_vidc_debug & 8) != 0 )
      return printk(&unk_8A645, "perf", v1, result + 4144, *(unsigned int *)(result + 4228));
  }
  return result;
}
