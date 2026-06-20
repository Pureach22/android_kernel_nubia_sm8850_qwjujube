__int64 deinit_tasklet_workers()
{
  cancel_work_sync(&unk_6CE1B8);
  cancel_work_sync(&unk_6CE1F8);
  cancel_work_sync(&unk_6CE238);
  cancel_work_sync(&unk_6CE278);
  cancel_work_sync(&unk_6CE2B8);
  cancel_work_sync(&unk_6CE2F8);
  cancel_work_sync(&unk_6CE338);
  cancel_work_sync(&unk_6CE378);
  cancel_work_sync(&unk_6CE3B8);
  cancel_work_sync(&unk_6CE3F8);
  cancel_work_sync(&unk_6CE438);
  return cancel_work_sync(&unk_6CE478);
}
