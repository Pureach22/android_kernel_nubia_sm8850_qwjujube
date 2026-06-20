__int64 rmnet_shs_rx_wq_exit()
{
  rmnet_shs_inst_rate_switch = 0;
  hrtimer_cancel(&unk_190A0);
  cancel_work_sync(&qword_190E0);
  hrtimer_cancel(&unk_19118);
  cancel_work_sync(&qword_19158);
  hrtimer_cancel(&unk_19190);
  cancel_work_sync(&qword_191D0);
  hrtimer_cancel(&unk_19208);
  cancel_work_sync(&qword_19248);
  hrtimer_cancel(&unk_19280);
  cancel_work_sync(&qword_192C0);
  hrtimer_cancel(&unk_192F8);
  cancel_work_sync(&qword_19338);
  hrtimer_cancel(&unk_19370);
  cancel_work_sync(&qword_193B0);
  hrtimer_cancel(&unk_193E8);
  cancel_work_sync(&qword_19428);
  return cancel_work_sync(&shs_rx_work);
}
