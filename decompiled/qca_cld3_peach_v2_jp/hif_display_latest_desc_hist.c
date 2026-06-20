__int64 __fastcall hif_display_latest_desc_hist(__int64 result)
{
  __int64 v1; // x19

  if ( result )
  {
    v1 = result;
    if ( *(_BYTE *)(result + 2814) == 1 )
    {
      qdf_trace_msg(
        61,
        5,
        "%s: CE_id:%d event_idx:%d cpu_id:%d irq_entry:0x%llx tasklet_entry:0x%llx tasklet_resched:0x%llx tasklet_exit:0x"
        "%llx ce_work:0x%llx hp:%x tp:%x",
        "hif_display_latest_desc_hist",
        2,
        0,
        *(_DWORD *)(result + 3752),
        *(_QWORD *)(result + 3712),
        *(_QWORD *)(result + 3720),
        *(_QWORD *)(result + 3728),
        *(_QWORD *)(result + 3736),
        *(_QWORD *)(result + 3744),
        *(_DWORD *)(result + 3756),
        *(_DWORD *)(result + 3760));
      result = qdf_trace_msg(
                 61,
                 5,
                 "%s: CE_id:%d event_idx:%d cpu_id:%d irq_entry:0x%llx tasklet_entry:0x%llx tasklet_resched:0x%llx taskle"
                 "t_exit:0x%llx ce_work:0x%llx hp:%x tp:%x",
                 "hif_display_latest_desc_hist",
                 2,
                 1,
                 *(_DWORD *)(v1 + 3808),
                 *(_QWORD *)(v1 + 3768),
                 *(_QWORD *)(v1 + 3776),
                 *(_QWORD *)(v1 + 3784),
                 *(_QWORD *)(v1 + 3792),
                 *(_QWORD *)(v1 + 3800),
                 *(_DWORD *)(v1 + 3812),
                 *(_DWORD *)(v1 + 3816));
    }
    if ( *(_BYTE *)(v1 + 2815) == 1 )
    {
      qdf_trace_msg(
        61,
        5,
        "%s: CE_id:%d event_idx:%d cpu_id:%d irq_entry:0x%llx tasklet_entry:0x%llx tasklet_resched:0x%llx tasklet_exit:0x"
        "%llx ce_work:0x%llx hp:%x tp:%x",
        "hif_display_latest_desc_hist",
        3,
        0,
        *(_DWORD *)(v1 + 3864),
        *(_QWORD *)(v1 + 3824),
        *(_QWORD *)(v1 + 3832),
        *(_QWORD *)(v1 + 3840),
        *(_QWORD *)(v1 + 3848),
        *(_QWORD *)(v1 + 3856),
        *(_DWORD *)(v1 + 3868),
        *(_DWORD *)(v1 + 3872));
      return qdf_trace_msg(
               61,
               5,
               "%s: CE_id:%d event_idx:%d cpu_id:%d irq_entry:0x%llx tasklet_entry:0x%llx tasklet_resched:0x%llx tasklet_"
               "exit:0x%llx ce_work:0x%llx hp:%x tp:%x",
               "hif_display_latest_desc_hist",
               3,
               1,
               *(_DWORD *)(v1 + 3920),
               *(_QWORD *)(v1 + 3880),
               *(_QWORD *)(v1 + 3888),
               *(_QWORD *)(v1 + 3896),
               *(_QWORD *)(v1 + 3904),
               *(_QWORD *)(v1 + 3912),
               *(_DWORD *)(v1 + 3924),
               *(_DWORD *)(v1 + 3928));
    }
  }
  return result;
}
