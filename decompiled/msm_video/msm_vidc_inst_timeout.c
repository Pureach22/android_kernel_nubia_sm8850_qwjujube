__int64 __fastcall msm_vidc_inst_timeout(_QWORD *a1)
{
  __int64 v1; // x19
  __int64 v3; // x4
  _QWORD *v4; // x9
  unsigned int v5; // w20

  v1 = a1[40];
  mutex_lock(v1 + 3856);
  v4 = (_QWORD *)(v1 + 3528);
  while ( 1 )
  {
    v4 = (_QWORD *)*v4;
    if ( v4 == (_QWORD *)(v1 + 3528) )
      break;
    if ( v4 == a1 )
    {
      msm_vidc_change_core_state(v1, 3, "msm_vidc_inst_timeout");
      msm_vidc_change_core_sub_state(v1, 0, 64, "msm_vidc_inst_timeout");
      msm_vidc_core_deinit_locked(v1, 1);
      v5 = 0;
      goto LABEL_9;
    }
  }
  if ( a1 && (msm_vidc_debug & 1) != 0 )
    printk(&unk_8C086, "err ", (char *)a1 + 340, "msm_vidc_inst_timeout", v3);
  v5 = -22;
LABEL_9:
  mutex_unlock(v1 + 3856);
  return v5;
}
